/*
 * INFRARED.h
 *
 *  Created on: May 10, 2025
 *      Author: Gustavo
 */

#ifndef INC_INFRARED_H_
#define INC_INFRARED_H_

#include <stdint.h>

#define ADC_CHANNELS			8
#define SIZE_BUF_ADC			32 // Must be a power of 2
#define LOOKUP_SIZE				20

#define RIGHT_SENSOR			0
#define RIGHT_DIAGONAL_SENSOR	1
#define FRONT_RIGHT_SENSOR		2
#define FRONT_UNDER_SENSOR		3
#define FRONT_LEFT_SENSOR		4
#define LEFT_DIAGONAL_SENSOR	5
#define LEFT_SENSOR				6
#define REAR_UNDER_SENSOR		7

#define RIGHT_THR_RAW			230
#define RIGHT_DIAG_THR_RAW		200
#define FRONT_RIGHT_THR_RAW		300 //400 -> no hay pared cerca. 250 -> pared de la otra celda aprox
#define FRONT_UNDER_THR_RAW		1800
#define FRONT_LEFT_THR_RAW		400
#define LEFT_DIAG_THR_RAW		150
#define LEFT_THR_RAW			260
#define REAR_UNDER_THR_RAW		1800

#define RIGHT_THR_MM			80
#define RIGHT_DIAG_THR_MM		100
#define FRONT_RIGHT_THR_MM		100
#define FRONT_LEFT_THR_MM		100
#define LEFT_DIAG_THR_MM		100
#define LEFT_THR_MM				80

typedef struct{
	//uint8_t iwBufADC, irBufADC;
	uint8_t index[ADC_CHANNELS]; // o SIZE_BUF_ADC?
	uint16_t bufADC[ADC_CHANNELS][SIZE_BUF_ADC];
	uint16_t rawSamples[ADC_CHANNELS];
	uint16_t filteredSamples[ADC_CHANNELS];
	uint8_t auxSamples[ADC_CHANNELS*2];
	uint32_t acumulated[ADC_CHANNELS];
	uint8_t millimeterSamples[ADC_CHANNELS];
	uint16_t lookUp[ADC_CHANNELS][LOOKUP_SIZE];
	uint16_t threshold[ADC_CHANNELS];
} InfraredHandle_s;


//const uint16_t adcReferences[REFERENCE_SAMPLES] = {3943, 3929, 3839, 2820, 2047, 1547, 1136, 1026, 758, 683, 554, 542, 476, 403, 363, 325, 260, 230, 205};

void Infrared_Init(InfraredHandle_s *infraredData);

void Infrared_Filter(InfraredHandle_s *infraredData);

void Infrared_Convert(InfraredHandle_s *infraredData);

void Infrared_To8Bits(InfraredHandle_s *infraredData);

void Infrared_DigitalPerception(InfraredHandle_s *infraredData, uint8_t *byte);

#endif /* INC_INFRARED_H_ */
