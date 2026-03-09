/*
 * INFRARED.c
 *
 *  Created on: May 10, 2025
 *      Author: Gerónimo Spiazzi
 */

#include "INFRARED.h"

const uint8_t mm_reference[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100};

void Infrared_Init(InfraredHandle_s *infraredData){
	// CASA

	// BOTH FRONT
//	uint16_t auxF[LOOKUP_SIZE] = {
//			3980, 3950, 3920, 3820, 2940,
//			2290, 1865, 1450, 1310, 1100,
//			970,  895,  792,  740,  675,
//			620,  570,  532,  495,  455
//	};

//	// RIGHT
//	uint16_t auxCH0[LOOKUP_SIZE] = {
//			3980, 3950, 3920, 3200, 2400,
//			1890, 1410, 1140, 940,  835,
//			685,  585,  500,  440,  400,
//			335,  305,  280,  250,  230
//	};

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

//	// LEFT
//	uint16_t auxCH6[LOOKUP_SIZE] = {
//			3980, 3950, 3920, 3590, 2800,
//			2150, 1550, 1230, 1040, 865,
//			757,  640,  540,  477,  430,
//			385,  340,  300,  275,  250
//	};


	/////////////////////////////////////// FACULTAD
	// RIGHT
	uint16_t auxCH0[LOOKUP_SIZE] = { // Menos de 300 no hay pared
			3990, 3950, 3930, 3760, 2685,
			2080, 1700, 1400, 1210,  1030,
			900,  805,  750,  695,  623,
			578,  540,  490,  460,  427
	};

	uint16_t auxCH2[LOOKUP_SIZE] = { // FRONTAL DERECHO - 300 RAW = 200mm
			4000, 3980, 3940, 3920, 3740,
			2980, 2380, 2000, 1700, 1520,
			1360, 1238, 1140, 1040, 970,
			905, 840, 787, 740, 695,
	};

	uint16_t auxCH4[LOOKUP_SIZE] = { // FRONTAL IZQUIERDO - 273 RAW = 200mm
			3985, 3970, 3935, 3850, 3160,
			2540, 2090, 1740, 1500, 1327,
			1200, 1100, 1010, 930, 870,
			815, 755, 712, 672, 635,
	};

	// LEFT
	uint16_t auxCH6[LOOKUP_SIZE] = { // Menos de 300 no hay pared
			3980, 3950, 3900, 3415, 2700,
			2080, 1690, 1400, 1210, 1060,
			920,  840,  775,  700,  630,
			590,  540,  495,  460,  420
	};
//	uint16_t aux[LOOKUP_SIZE] = {3943, 3929, 3839, 2820, 2047, 1547, 1136, 1026, 758, 683, 554, 542, 476, 403, 363, 325, 260, 230, 205};

	for(uint8_t i=0; i<LOOKUP_SIZE; i++){
		infraredData->lookUp[RIGHT_SENSOR][i] = auxCH0[i];
		infraredData->lookUp[RIGHT_DIAGONAL_SENSOR][i] = auxCH1[i];
		infraredData->lookUp[FRONT_RIGHT_SENSOR][i] = auxCH2[i];
		infraredData->lookUp[FRONT_LEFT_SENSOR][i] = auxCH4[i];
		infraredData->lookUp[LEFT_DIAGONAL_SENSOR][i] = auxCH5[i];
		infraredData->lookUp[LEFT_SENSOR][i] = auxCH6[i];
	}

	infraredData->threshold[RIGHT_SENSOR] = RIGHT_THR_RAW;
	infraredData->threshold[FRONT_RIGHT_SENSOR] = FRONT_RIGHT_THR_RAW;
	infraredData->threshold[FRONT_LEFT_SENSOR] = FRONT_LEFT_THR_RAW;
	infraredData->threshold[LEFT_SENSOR] = LEFT_THR_RAW;
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
		if (channel == 3 || channel == 7) {
			infraredData->millimeterSamples[channel] = 0;
			continue;
		}

		if (infraredData->filteredSamples[channel] >= infraredData->lookUp[channel][0]) {
			infraredData->millimeterSamples[channel] = 5;
			continue;
		}

		if (infraredData->filteredSamples[channel] <= infraredData->threshold[channel]){
			infraredData->millimeterSamples[channel] = 255;
			continue;
		}

    	for(uint8_t j = 1; j < LOOKUP_SIZE; j++){
    		if(infraredData->filteredSamples[channel] >= infraredData->lookUp[channel][j]){
    			uint16_t adc0 = infraredData->lookUp[channel][j-1];
    			uint16_t adc1 = infraredData->lookUp[channel][j];

				uint8_t dist0 = j * 5;
				uint8_t dist1 = (j + 1) * 5;

				uint32_t deltaDist = dist1 - dist0;
				uint32_t deltaAdcTotal = adc0 - adc1;
				uint32_t deltaAdcParcial = adc0 - infraredData->filteredSamples[channel];

				infraredData->millimeterSamples[channel] = dist0 + ((deltaDist * deltaAdcParcial) / deltaAdcTotal);

//    			infraredData->millimeterSamples[channel] = (j + 1) * 5;
    			break;
    		}
    	}
    }
}

void Infrared_DigitalPerception(InfraredHandle_s *infraredData, uint8_t *byte) {
	*byte = 0;

	for (uint8_t i = 0; i < ADC_CHANNELS; i++)
		*byte |= (infraredData->filteredSamples[i] > infraredData->threshold[i]) << i;
}

//void Infrared_DigitalPerception(InfraredHandle_s *infraredData, uint8_t *byte, uint16_t threshold) {
//	*byte = 0;
//
//	for (uint8_t i = 0; i < ADC_CHANNELS; i++)
//		*byte |= (infraredData->filteredSamples[i] > threshold) << i;
//}

