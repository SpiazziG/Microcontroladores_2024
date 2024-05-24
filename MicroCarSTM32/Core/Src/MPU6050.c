/*
 * MPU6050.c
 *
 *  Created on: May 21, 2024
 *      Author: Gerónimo Spiazzi
 */

#include "mpu6050.h"

uint8_t bufData[14];

void MPU6050_Init(I2C_HandleTypeDef *hi2c) {
    uint8_t data = 0;

    // Verifies connection with MPU6050
    HAL_I2C_Mem_Read(hi2c, MPU6050_ADDR, WHO_AM_I, 1, &data, 1, 1);

    if (data == WHO_AM_I_DEFAULT_VALUE){
        // Wake up MPU6050
        data = 0;
        HAL_I2C_Mem_Write(hi2c, MPU6050_ADDR, POWER_MANAGEMENT_REG, 1, &data, 1, 1);

        // Set accelerometer range (+/- 2g, 4g, 8g, 16g)
        data = 0; // 2g (default)
        HAL_I2C_Mem_Write(hi2c, MPU6050_ADDR, ACCEL_CONFIG_REG, 1, &data, 1, 1);

        // Set gyroscope range (+/- 250, 500, 1000, 2000 degree/s)
        data = 0; // 250 degree/s (default)
        HAL_I2C_Mem_Write(hi2c, MPU6050_ADDR, GYRO_CONFIG_REG, 1, &data, 1, 1);
    }
}


void MPU6050_Read_Data_DMA(I2C_HandleTypeDef *hi2c){
	HAL_I2C_Mem_Read_DMA(hi2c, MPU6050_ADDR, ACCEL_XOUT_REG, 1, bufData, 14);
}


void HAL_I2C_MemRxCpltCallback(I2C_HandleTypeDef *hi2c){
	extern _sMPUData mpuValues;
	_sMPUData callbackData = mpuValues;

	callbackData.accelX[0] = bufData[1];
	callbackData.accelX[1] = bufData[0];

	callbackData.accelY[0] = bufData[3];
	callbackData.accelY[1] = bufData[2];

	callbackData.accelZ[0] = bufData[5];
	callbackData.accelZ[1] = bufData[4];

	//callbackData.temperature[0] = bufData[7];
	//callbackData.temperature[1] = bufData[6];

	callbackData.gyroX[0] = bufData[9];
	callbackData.gyroX[1] = bufData[8];

	callbackData.gyroY[0] = bufData[11];
	callbackData.gyroY[1] = bufData[10];

	callbackData.gyroZ[0] = bufData[13];
	callbackData.gyroZ[1] = bufData[12];

	mpuValues = callbackData;
}
/*
void MPU6050_Read_Data(I2C_HandleTypeDef *hi2c, _sMPUData *accelData) {
    // Read 14 bytes from acceleration registers
    HAL_I2C_Mem_Read(hi2c, MPU6050_ADDR, ACCEL_XOUT_REG, 1, bufData, 14, 1);

    // Load low part first
    accelData->accelX[0] = bufData[1];
    accelData->accelX[1] = bufData[0];

    accelData->accelY[0] = bufData[3];
    accelData->accelY[1] = bufData[2];

    accelData->accelZ[0] = bufData[5];
    accelData->accelZ[1] = bufData[4];

    //accelData->temperature[0] = recData[7];
    //accelData->temperature[1] = recData[6];

    accelData->gyroX[0] = bufData[9];
    accelData->gyroX[1] = bufData[8];

    accelData->gyroY[0] = bufData[11];
    accelData->gyroY[1] = bufData[10];

    accelData->gyroZ[0] = bufData[13];
    accelData->gyroZ[1] = bufData[12];
}
*/
