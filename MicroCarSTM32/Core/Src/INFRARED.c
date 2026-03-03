/*
 * INFRARED.c
 *
 *  Created on: May 10, 2025
 *      Author: Gerónimo Spiazzi
 */

#include "INFRARED.h"

const uint8_t mm_reference[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100};

// Initialize the sensors
void Infrared_Init(InfraredHandle_s *infraredData){
	//uint16_t aux[LOOKUP_SIZE] = {3943, 3929, 3839, 2820, 2047, 1547, 1136, 1026, 758, 683, 554, 542, 476, 403, 363, 325, 260, 230, 205};

	for(uint8_t c=0; c<ADC_CHANNELS; c++) {
		for(uint8_t i=0; i<LOOKUP_SIZE; i++) {
			infraredData->lookUp[c][i] = 0;
		}
	}

	// BOTH FRONT
	uint16_t auxF[LOOKUP_SIZE] = {
			3980, 3950, 3920, 3820, 2940,
			2290, 1865, 1450, 1310, 1100,
			970,  895,  792,  740,  675,
			620,  570,  532,  495,  455
	};

	// RIGHT
	uint16_t auxCH0[LOOKUP_SIZE] = {
			3980, 3950, 3920, 3200, 2400,
			1890, 1410, 1140, 940,  835,
			685,  585,  500,  440,  400,
			335,  305,  280,  250,  230
	};

	// RIGHT DIAGONAL
	uint16_t auxCH1[LOOKUP_SIZE] = {
			3970, 3930, 3267, 2345, 1785, // 5mm a 25mm
			1420, 1122,  945,  797,  712, // 30mm a 50mm
			610,  550,  485,  430,  360, // 55mm a 75mm
			335,  325,  300,  280,  257  // 80mm a 100mm
	};

	// LEFT DIAGONAL
	uint16_t auxCH5[LOOKUP_SIZE] = {
			3920, 3100, 2000, 1580, 1230, // 5mm a 25mm
			985,  827,  700,  571,  487, // 30mm a 50mm
			420,  376,  345,  310,  272, // 55mm a 75mm
			243,  215,  190,  180,  169  // 80mm a 100mm
	};

	// LEFT
	uint16_t auxCH6[LOOKUP_SIZE] = {
			3980, 3950, 3920, 3590, 2800,
			2150, 1550, 1230, 1040, 865,
			757,  640,  540,  477,  430,
			385,  340,  300,  275,  250
	};

	for(uint8_t i=0; i<LOOKUP_SIZE; i++) {
		infraredData->lookUp[0][i] = auxCH0[i];
		infraredData->lookUp[1][i] = auxCH1[i];
		infraredData->lookUp[2][i] = auxF[i];
		infraredData->lookUp[4][i] = auxF[i];
		infraredData->lookUp[5][i] = auxCH5[i];
		infraredData->lookUp[6][i] = auxCH6[i];
	}
}

// Moving Average filter
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

// Convert 16 bits values to 2 values of 8 bits (for communication)
void Infrared_To8Bits(InfraredHandle_s *infraredData){
	uint8_t index = 0;
	for(uint8_t channel = 0; channel < ADC_CHANNELS; channel++){
		infraredData->auxSamples[index++] = (uint8_t)(infraredData->filteredSamples[channel] & 0xFF);
		infraredData->auxSamples[index++] = (uint8_t)((infraredData->filteredSamples[channel] >> 8) & 0xFF);
	}
}

// Convert raw values to millimeter values using LUT and interpolation
void Infrared_Convert(InfraredHandle_s *infraredData, uint16_t threshold){
    for (uint8_t channel = 0; channel < ADC_CHANNELS; channel++) {
    	// OPTIMIZACIÓN: Saltamos los sensores que miran al piso (Canales 3 y 7)
		// A estos los seguiremos leyendo con valores RAW del ADC en el resto del código
		if (channel == 3 || channel == 7) {
			infraredData->millimeterSamples[channel] = 0;
			continue;
		}

    	uint16_t currentADC = infraredData->filteredSamples[channel];

    	// 2. Detección de celda vacía / Pared muy lejana
		if (currentADC <= (threshold)) {
			// No hay nada a la vista
			infraredData->millimeterSamples[channel] = 255;
			continue;
		}

    	if (currentADC >= infraredData->lookUp[channel][0]) {
    		infraredData->millimeterSamples[channel] = 5;
    		continue;
    	}

    	for(uint8_t j = 1; j < LOOKUP_SIZE; j++){
    		if (currentADC >= infraredData->lookUp[channel][j]) {
    			uint16_t adc0 = infraredData->lookUp[channel][j-1];
    			uint16_t adc1 = infraredData->lookUp[channel][j];

    			uint8_t dist0 = j * 5;
    			uint8_t dist1 = (j + 1) * 5;

    			uint32_t deltaDist = dist1 - dist0;
    			uint32_t deltaAdcTotal = adc0 - adc1;
    			uint32_t deltaAdcParcial = adc0 - currentADC;

    			infraredData->millimeterSamples[channel] = dist0 + ((deltaDist * deltaAdcParcial) / deltaAdcTotal);

    			break;
    		}

//    		if(infraredData->filteredSamples[channel] >= infraredData->lookUp[j]){
//    			infraredData->millimeterSamples[channel] = (j + 1) * 5;
//    			break;
//    		}
    	}
    }
}

// Transform the values to 1 or 0 based on a threshold
void Infrared_DigitalPerception(InfraredHandle_s *infraredData, uint8_t *byte, uint16_t threshold) {
	*byte = 0;

	// Right Sensors
	*byte |= (infraredData->millimeterSamples[RIGHT_SENSOR] < 200) << RIGHT_SENSOR;
	*byte |= (infraredData->millimeterSamples[RIGHT_DIAGONAL_SENSOR] < 200) << RIGHT_DIAGONAL_SENSOR;
	*byte |= (infraredData->millimeterSamples[FRONT_RIGHT_SENSOR] < 110) << FRONT_RIGHT_SENSOR;

	// Left Sensors
	*byte |= (infraredData->millimeterSamples[FRONT_LEFT_SENSOR] < 110) << FRONT_LEFT_SENSOR;
	*byte |= (infraredData->millimeterSamples[LEFT_DIAGONAL_SENSOR] < 140) << LEFT_DIAGONAL_SENSOR;
	*byte |= (infraredData->millimeterSamples[LEFT_SENSOR] < 200) << LEFT_SENSOR;

//		*byte |= (infraredData->filteredSamples[i] > threshold) << i;
}

