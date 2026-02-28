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
        speedPercentage = handle->currentLeftSpeed;
        forwardChannel = handle->leftForwardChannel;
        backwardChannel = handle->leftBackwardChannel;
    } else { // RIGHT_MOTOR
        speedPercentage = handle->currentRightSpeed;
        forwardChannel = handle->rightForwardChannel;
        backwardChannel = handle->rightBackwardChannel;
    }

    // Limitation from -100 to 100
    if (speedPercentage > 100) speedPercentage = 100;
    if (speedPercentage < -100) speedPercentage = -100;


    // Voltage compensation
    uint8_t speedAbs = (speedPercentage < 0) ? -speedPercentage : speedPercentage;
    uint32_t compareValue = 0;

    // Avoid division by zero if voltage is not set.
    if (handle->currentVoltage > 0 && handle->nominalVoltage > 0) {
    	compareValue = (speedAbs * handle->pwmMaxPeriod * handle->nominalVoltage);
    	compareValue /= (100 * handle->currentVoltage);
    } else {
    	// Do a normal calculus if a voltage is not set
    	compareValue = ((uint32_t)speedAbs * handle->pwmMaxPeriod) / 100;
    }

    // If compensation is more than 100% of the PWM
    if (compareValue > handle->pwmMaxPeriod) compareValue = handle->pwmMaxPeriod;

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
	handle->targetLeftSpeed = 0;
	handle->targetRightSpeed = 0;
	handle->currentLeftSpeed = 0;
	handle->currentRightSpeed = 0;

	// Default values (without compensation)
	handle->nominalVoltage = 820; // 8.2 Volts
	handle->currentVoltage = 820;
}

static void ENGINE_CalculateRamp(int8_t *currentSpeed, int8_t targetSpeed) {
    if (targetSpeed == 0 ||
       (targetSpeed > 0 && targetSpeed < *currentSpeed) ||
       (targetSpeed < 0 && targetSpeed > *currentSpeed)) {

        *currentSpeed = targetSpeed; // Freno inmediato
    }
    else if ((targetSpeed > 0 && *currentSpeed < 0) ||
             (targetSpeed < 0 && *currentSpeed > 0)) {

        *currentSpeed = 0; // Inversión de giro (pasar por 0)
    }
    else {
        // Aceleración progresiva (Rampa con salto de zona muerta)
        if (targetSpeed > *currentSpeed) {
            if (*currentSpeed == 0 && targetSpeed >= 25) *currentSpeed = 25; // Salto Deadband
            else *currentSpeed += 10; // Incremento normal

            if (*currentSpeed > targetSpeed) *currentSpeed = targetSpeed; // Tope

        } else if (targetSpeed < *currentSpeed) {
            if (*currentSpeed == 0 && targetSpeed <= -25) *currentSpeed = -25; // Salto Deadband
            else *currentSpeed -= 10;

            if (*currentSpeed < targetSpeed) *currentSpeed = targetSpeed; // Tope
        }
    }
}

void ENGINE_Task(ENGINE_Handle_s *handle) {
	ENGINE_CalculateRamp(&handle->currentLeftSpeed, handle->targetLeftSpeed);
	ENGINE_CalculateRamp(&handle->currentRightSpeed, handle->targetRightSpeed);

	ENGINE_UpdateMotor(handle, LEFT_MOTOR);
	ENGINE_UpdateMotor(handle, RIGHT_MOTOR);
}

void ENGINE_SetLeftSpeed(ENGINE_Handle_s *handle, int8_t targetSpeed) {
	handle->targetLeftSpeed = targetSpeed;
}

void ENGINE_SetRightSpeed(ENGINE_Handle_s *handle, int8_t targetSpeed) {
	handle->targetRightSpeed = targetSpeed;
}

//void ENGINE_SetLeftSpeed(ENGINE_Handle_s *handle, int8_t speed) {
//	handle->leftSpeed = speed;
//	ENGINE_UpdateMotor(handle, LEFT_MOTOR);
//}
//
//void ENGINE_SetRightSpeed(ENGINE_Handle_s *handle, int8_t speed) {
//	handle->rightSpeed = speed;
//	ENGINE_UpdateMotor(handle, RIGHT_MOTOR);
//}

void ENGINE_SetBatteryVoltage(ENGINE_Handle_s *handle, uint16_t voltage) {
	// Basic protection
	if (voltage < 300) return; // Ignore ultra-low voltages

	handle->currentVoltage = voltage;

}
