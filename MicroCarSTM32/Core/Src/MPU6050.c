/*
 * MPU6050.c
 *
 *  Created on: May 21, 2024
 *      Author: Gerónimo Spiazzi
 */

#include "mpu6050.h"

static _sMPUData libraryValues;
uint8_t bufData[14];

void MPU6050_Init(I2C_HandleTypeDef *hi2c) {
    uint8_t data = 0;

    // Verifies connection with MPU6050
    HAL_I2C_Mem_Read(hi2c, MPU6050_ADDR, WHO_AM_I, 1, &data, 1, 10);

    if (data == WHO_AM_I_DEFAULT_VALUE){
        // Wake up MPU6050
        data = 0;
        HAL_I2C_Mem_Write(hi2c, MPU6050_ADDR, POWER_MANAGEMENT_REG, 1, &data, 1, 10);

        // Set accelerometer range (+/- 2g, 4g, 8g, 16g)
        data = 0; // 2g (default)
        HAL_I2C_Mem_Write(hi2c, MPU6050_ADDR, ACCEL_CONFIG_REG, 1, &data, 1, 10);

        // Set gyroscope range (+/- 250, 500, 1000, 2000 degree/s)
        data = 0; // 250 degree/s (default)
        HAL_I2C_Mem_Write(hi2c, MPU6050_ADDR, GYRO_CONFIG_REG, 1, &data, 1, 10);

        // Set Digital Low Pass Filter
		data = 4;
		HAL_I2C_Mem_Write(hi2c, MPU6050_ADDR, DLPF_CONFIG_REG, 1, &data, 1, 10);
    }
}

void MPU6050_Read_Data_DMA(I2C_HandleTypeDef *hi2c){
	HAL_I2C_Mem_Read_DMA(hi2c, MPU6050_ADDR, ACCEL_XOUT_REG, 1, bufData, 14);
}

void HAL_I2C_MemRxCpltCallback(I2C_HandleTypeDef *hi2c){
	extern _sMPUData myMpuValues;

	libraryValues.accelX	= (bufData[0] << 8) | bufData[1];
	libraryValues.accelY	= (bufData[2] << 8) | bufData[3];
	libraryValues.accelZ	= (bufData[4] << 8) | bufData[5];

	//libraryValues.temperature = (bufData[6] << 8) | bufData[7];

	libraryValues.gyroX		= (bufData[8] << 8) | bufData[9];
	libraryValues.gyroY 	= (bufData[10] << 8) | bufData[11];
	libraryValues.gyroZ		= (bufData[12] << 8) | bufData[13];

	libraryValues.accelX	= libraryValues.accelX - (int16_t)libraryValues.offsetAccelX;
	libraryValues.accelY	= libraryValues.accelY - (int16_t)libraryValues.offsetAccelY;
	libraryValues.accelZ	= libraryValues.accelZ - (int16_t)libraryValues.offsetAccelZ;

	libraryValues.gyroX 	= libraryValues.gyroX - (int16_t)libraryValues.offsetGyroX;
	libraryValues.gyroY		= libraryValues.gyroY - (int16_t)libraryValues.offsetGyroY;
	libraryValues.gyroZ		= libraryValues.gyroZ - (int16_t)libraryValues.offsetGyroZ;

	myMpuValues = libraryValues;
}

void MPU6050_Calibrate(I2C_HandleTypeDef *hi2c){
	int32_t auxOffset_AX, auxOffset_AY, auxOffset_AZ;
	int32_t auxOffset_GX, auxOffset_GY, auxOffset_GZ;

	auxOffset_AX = 0;
	auxOffset_AY = 0;
	auxOffset_AZ = 0;

	auxOffset_GX = 0;
	auxOffset_GY = 0;
	auxOffset_GZ = 0;

	for (uint16_t i = 0; i < SAMPLES_SIZE; i++){
		HAL_I2C_Mem_Read(hi2c, MPU6050_ADDR, ACCEL_XOUT_REG, 1, bufData, 14, 100);
		if(i > (DISCARDED_SAMPLES-1)){
			auxOffset_AX += (int16_t)(bufData[0] << 8) | bufData[1];
			auxOffset_AY += (int16_t)(bufData[2] << 8) | bufData[3];
			auxOffset_AZ += (int16_t)(bufData[4] << 8) | bufData[5];

			auxOffset_GX += (int16_t)((bufData[8] << 8) | bufData[9]);
			auxOffset_GY += (int16_t)((bufData[10] << 8) | bufData[11]);
			auxOffset_GZ += (int16_t)((bufData[12] << 8) | bufData[13]);
		}
		HAL_Delay(10);
	}

	libraryValues.offsetAccelX = (auxOffset_AX/(SAMPLES_SIZE-DISCARDED_SAMPLES));
	libraryValues.offsetAccelY = (auxOffset_AY/(SAMPLES_SIZE-DISCARDED_SAMPLES));
	libraryValues.offsetAccelZ = (auxOffset_AZ/(SAMPLES_SIZE-DISCARDED_SAMPLES));

	libraryValues.offsetGyroX = (auxOffset_GX/(SAMPLES_SIZE-DISCARDED_SAMPLES));
	libraryValues.offsetGyroY = (auxOffset_GY/(SAMPLES_SIZE-DISCARDED_SAMPLES));
	libraryValues.offsetGyroZ = (auxOffset_GZ/(SAMPLES_SIZE-DISCARDED_SAMPLES));
}

void MPU6050_Compose_Number(_sMPUData mpuValues, uint8_t buf[12]){
	//buf[0] = Less Significant Bits
	buf[0] = libraryValues.accelX & 0xFF;
	buf[1] = (libraryValues.accelX >> 8) & 0xFF;
	buf[2] = libraryValues.accelY & 0xFF;
	buf[3] = (libraryValues.accelY >> 8) & 0xFF;
	buf[4] = libraryValues.accelZ & 0xFF;
	buf[5] = (libraryValues.accelZ >> 8) & 0xFF;

	buf[6] = libraryValues.gyroX & 0xFF;
	buf[7] = (libraryValues.gyroX >> 8) & 0xFF;
	buf[8] = libraryValues.gyroY & 0xFF;
	buf[9] = (libraryValues.gyroY >> 8) & 0xFF;
	buf[10] = libraryValues.gyroZ & 0xFF;
	buf[11] = (libraryValues.gyroZ >> 8) & 0xFF;
}
