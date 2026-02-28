/*
 * ENGINE.h
 *
 *  Created on: Jul 24, 2025
 *      Author: Gerónimo Spiazzi
 */

#ifndef INC_ENGINE_H_
#define INC_ENGINE_H_

#include "stm32f1xx_hal.h"
#include <stdint.h>

#define PWM_TIMER				htim4

#define LEFT_ENGINE_FORWARD		TIM_CHANNEL_1
#define LEFT_ENGINE_BACKWARD	TIM_CHANNEL_2
#define RIGHT_ENGINE_FORWARD	TIM_CHANNEL_3
#define RIGHT_ENGINE_BACKWARD	TIM_CHANNEL_4

#define PWM_MAX_VALUE			9999

#define ENGINE_MAX_STEP 		15
#define ENGINE_DEADBAND			25

typedef enum {
	LEFT_MOTOR,
	RIGHT_MOTOR
} ENGINE_Side_e;

typedef struct {
	uint32_t leftForwardChannel;
	uint32_t leftBackwardChannel;

	uint32_t rightForwardChannel;
	uint32_t rightBackwardChannel;

	int8_t targetLeftSpeed;
	int8_t targetRightSpeed;
	int8_t currentLeftSpeed;
	int8_t currentRightSpeed;


	int16_t pwmMaxPeriod;

	uint16_t nominalVoltage;
	uint16_t currentVoltage;
} ENGINE_Handle_s;

void ENGINE_Init(ENGINE_Handle_s *handle);
//static void ENGINE_CalculateRamp(int8_t *currentSpeed, int8_t targetSpeed);
void ENGINE_Task(ENGINE_Handle_s *handle);
void ENGINE_SetLeftSpeed(ENGINE_Handle_s *handle, int8_t speed);
void ENGINE_SetRightSpeed(ENGINE_Handle_s *handle, int8_t speed);
void ENGINE_SetBatteryVoltage(ENGINE_Handle_s *handle, uint16_t voltage);

#endif /* INC_ENGINE_H_ */
