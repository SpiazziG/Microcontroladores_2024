/*
 * ENGINE.c
 *
 *  Created on: Jul 24, 2025
 *      Author: Gerónimo Spiazzi
 */
#include "ENGINE.h"



extern TIM_HandleTypeDef htim4;

static void ENGINE_UpdateMotor (ENGINE_Handle_s *handle, ENGINE_Side_e engineSide) {
	int8_t speedPercentage;
	uint32_t forwardChannel, backwardChannel;

    if (engineSide == LEFT_MOTOR) {
        speedPercentage = handle->leftSpeed;
        forwardChannel = handle->leftForwardChannel;
        backwardChannel = handle->leftBackwardChannel;
    } else { // RIGHT_MOTOR
        speedPercentage = handle->rightSpeed;
        forwardChannel = handle->rightForwardChannel;
        backwardChannel = handle->rightBackwardChannel;
    }

    if (speedPercentage > 100) speedPercentage = 100;
    if (speedPercentage < -100) speedPercentage = -100;

    uint8_t speedAbs = (speedPercentage < 0) ? -speedPercentage : speedPercentage;
    uint32_t compareValue = ((uint32_t)speedAbs * handle->pwmMaxPeriod) / 100;

    if (speedPercentage > 0){
    	__HAL_TIM_SET_COMPARE(&PWM_TIMER, forwardChannel, compareValue);
    	__HAL_TIM_SET_COMPARE(&PWM_TIMER, backwardChannel, 0);
    } else if (speedPercentage < 0) {
    	__HAL_TIM_SET_COMPARE(&PWM_TIMER, forwardChannel, 0);
    	__HAL_TIM_SET_COMPARE(&PWM_TIMER, backwardChannel, compareValue);
    } else {
    	__HAL_TIM_SET_COMPARE(&PWM_TIMER, forwardChannel, 0);
    	__HAL_TIM_SET_COMPARE(&PWM_TIMER, backwardChannel, 0);
    }
}

void ENGINE_Init(ENGINE_Handle_s *handle) {
	handle->leftForwardChannel = LEFT_ENGINE_FORWARD;
	handle->leftBackwardChannel = LEFT_ENGINE_BACKWARD;
	handle->rightForwardChannel = RIGHT_ENGINE_FORWARD;
	handle->rightBackwardChannel = RIGHT_ENGINE_BACKWARD;
	handle->pwmMaxPeriod = PWM_MAX_VALUE;
	handle->leftSpeed = 0;
	handle->rightSpeed = 0;
}

void ENGINE_SetLeftSpeed(ENGINE_Handle_s *handle, int8_t speed) {
	handle->leftSpeed = speed;

	ENGINE_UpdateMotor(handle, LEFT_MOTOR);
}

void ENGINE_SetRightSpeed(ENGINE_Handle_s *handle, int8_t speed) {
	handle->rightSpeed = speed;

	ENGINE_UpdateMotor(handle, RIGHT_MOTOR);
}
