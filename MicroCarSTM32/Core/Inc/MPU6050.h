/*
 * MPU6050.h
 *
 *  Created on: May 21, 2024
 *      Author: Gerónimo Spiazzi
 */

#ifndef INC_MPU6050_H_
#define INC_MPU6050_H_

#include "stm32f1xx_hal.h"

#include <stdlib.h>
// MPU6050 address
#define MPU6050_ADDR 0xD0 // 0x68 << 1

// MPU6050 registers
#define WHO_AM_I 				0x75
#define DLPF_CONFIG_REG			0x1A
#define POWER_MANAGEMENT_REG 	0x6B
#define GYRO_CONFIG_REG 		0x1B
#define GYRO_XOUT_REG 			0x43
#define ACCEL_CONFIG_REG 		0x1C
#define ACCEL_XOUT_REG 			0x3B

// Default Values
#define WHO_AM_I_DEFAULT_VALUE 	0x68

#define SAMPLES_SIZE			250
#define DISCARDED_SAMPLES		15


typedef struct {
	int16_t accelX;
	int16_t accelY;
	int16_t accelZ;

	//uint16_t temperature;

	int16_t gyroX;
	int16_t gyroY;
	int16_t gyroZ;

	int16_t offsetAccelX;
	int16_t offsetAccelY;
	int16_t offsetAccelZ;

	int16_t offsetGyroX;
	int16_t offsetGyroY;
	int16_t offsetGyroZ;
}_sMPUData;

// Prototypes
void MPU6050_Init(I2C_HandleTypeDef *hi2c);
void MPU6050_Read_Data_DMA(I2C_HandleTypeDef *hi2c);
void MPU6050_Compose_Number(_sMPUData mpuValues, uint8_t buf[12]);
void MPU6050_Calibrate(I2C_HandleTypeDef *hi2c);

#endif /* INC_MPU6050_H_ */
