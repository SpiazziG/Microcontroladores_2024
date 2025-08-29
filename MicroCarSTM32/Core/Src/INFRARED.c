/*
 * INFRARED.c
 *
 *  Created on: May 10, 2025
 *      Author: Gerónimo Spiazzi
 */

#include "INFRARED.h"

const uint8_t mm_reference[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100};

void Infrared_Init(InfraredHandle_s *infraredData){
	uint16_t aux[LOOKUP_SIZE] = {3943, 3929, 3839, 2820, 2047, 1547, 1136, 1026, 758, 683, 554, 542, 476, 403, 363, 325, 260, 230, 205};

	for(uint8_t i=0; i<LOOKUP_SIZE; i++)
		infraredData->lookUp[i] = aux[i];
}

void Infrared_Filter(InfraredHandle_s *infraredData){
	for(uint8_t channel = 0; channel < ADC_CHANNELS; channel++){
		// Delete oldest value
		infraredData->acumulated[channel] -= infraredData->bufADC[channel][infraredData->index[channel]];

		// Load newest value
		infraredData->acumulated[channel] += infraredData->rawSamples[channel];

		// Update buffer with the newest sample
		infraredData->bufADC[channel][infraredData->index[channel]] = infraredData->rawSamples[channel];

		// Calculate average
		infraredData->filteredSamples[channel] = infraredData->acumulated[channel] / SIZE_BUF_ADC;

		// Increase index value
		infraredData->index[channel]++;

		// Overflow control
		infraredData->index[channel] &= (SIZE_BUF_ADC - 1);
	}
}

void Infrared_To8Bits(InfraredHandle_s *infraredData){
	uint8_t index = 0;
	for(uint8_t channel = 0; channel < ADC_CHANNELS; channel++){
		infraredData->auxSamples[index++] = (uint8_t)(infraredData->filteredSamples[channel] & 0xFF);
		infraredData->auxSamples[index++] = (uint8_t)((infraredData->filteredSamples[channel] >> 8) & 0xFF);
	}
}

void Infrared_Convert(InfraredHandle_s *infraredData){
    for (uint8_t channel = 0; channel < ADC_CHANNELS; channel++) {
    	for(uint8_t j = 0; j < LOOKUP_SIZE; j++){
    		if(infraredData->filteredSamples[channel] >= infraredData->lookUp[j]){
    			infraredData->millimeterSamples[channel] = (j + 1) * 5;
    			break;
    		}
    	}
    }
}

void Infrared_DigitalPerception(InfraredHandle_s *infraredData, uint8_t *byte, uint8_t threshold) {
	*byte = 0;

	for (uint8_t i = 0; i < ADC_CHANNELS; i++)
		*byte |= (infraredData->filteredSamples[i] > threshold) << i;
}

