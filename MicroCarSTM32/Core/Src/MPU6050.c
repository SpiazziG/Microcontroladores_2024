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

	uint16_t aux;
	aux = (uint16_t)((callbackData.gyroX[1] << 8) | callbackData.gyroX[0]) + (uint16_t)((callbackData.gyroXoffset[1] << 8) | callbackData.gyroXoffset[0]);
	callbackData.gyroX[1] = (uint8_t)(aux >> 8);
	callbackData.gyroX[0] = (uint8_t)(aux & 0xFF);

	mpuValues = callbackData;
}

/*
void MPU6050_Calibrate(I2C_HandleTypeDef *hi2c, _sMPUData *accelData){
	const int numSamples = 100;
	//int16_t accelX = 0, accelY = 0, accelZ = 0;
	uint8_t auxBuf[6];
	int16_t GYRO_X = 0, GYRO_Y = 0, GYRO_Z = 0;

	for (int i = 0; i < numSamples; i++){
		HAL_I2C_Mem_Read(hi2c, MPU6050_ADDR, GYRO_XOUT_REG, 6, bufData, 6, 10);
		HAL_Delay(10);

		GYRO_X += (int16_t)((bufData[0] << 8) | bufData[1]);
		GYRO_Y += (int16_t)((bufData[2] << 8) | bufData[3]);
		GYRO_Z += (int16_t)((bufData[4] << 8) | bufData[5]);
	}

	//accelOffset.Accel_X = accelX / numSamples;
	//accelOffset.Accel_Y = accelY / numSamples;
	//accelOffset.Accel_Z = (accelZ / numSamples) - 16384; // Ajustar para que el valor Z del acelerómetro sea aproximadamente 1g

	GYRO_X = GYRO_X / numSamples;
	GYRO_Y = GYRO_Y / numSamples;
	GYRO_Z = GYRO_Z / numSamples;

    auxBuf[1] = (uint8_t)(GYRO_X >> 8);  // Obtener los 8 bits más significativos
    auxBuf[0] = (uint8_t)(GYRO_X & 0xFF); // Obtener los 8 bits menos significativos

    auxBuf[3] = (uint8_t)(GYRO_Y >> 8);  // Obtener los 8 bits más significativos
    auxBuf[2] = (uint8_t)(GYRO_Y & 0xFF); // Obtener los 8 bits menos significativos

    auxBuf[5] = (uint8_t)(GYRO_Z >> 8);  // Obtener los 8 bits más significativos
    auxBuf[4] = (uint8_t)(GYRO_Z & 0xFF); // Obtener los 8 bits menos significativos

	accelData->gyroXoffset[0] = auxBuf[0];
	accelData->gyroXoffset[1] = auxBuf[1];

	accelData->gyroYoffset[0] = auxBuf[2];
	accelData->gyroXoffset[1] = auxBuf[3];

	accelData->gyroZoffset[0] = auxBuf[4];
	accelData->gyroXoffset[1] = auxBuf[5];
}
*/
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
