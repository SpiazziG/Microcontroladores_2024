/*
 * MPU6050.c
 *
 *  Created on: May 21, 2024
 *      Author: Gerónimo Spiazzi
 */

#include "mpu6050.h"

MPU_Status_e MPU6050_Init(MPU_Handle_s *handle, uint8_t i2c_addr, void* i2c_ctx) {
	if (handle == 0 || i2c_ctx == 0)
		return MPU6050_NULL_PTR;

	handle->i2c_addr = i2c_addr;
	handle->i2c_context = i2c_ctx;

	//Port_I2C_Register_DMA_Rx_Callback(MPU_DMA_RxCpltCallback, handle);

	uint8_t data = 0;

	if (Port_I2C_Mem_Read(handle->i2c_addr, WHO_AM_I_REG, &data, 1, handle->i2c_context) != 0)
		return MPU6050_ERROR;

	uint8_t config = 0;

	if (data == WHO_AM_I_DEFAULT_VALUE) {
		config = 0;
		Port_I2C_Mem_Write(handle->i2c_addr, POWER_MANAGEMENT_REG, &config, 1, handle->i2c_context);

		config = 0;
		Port_I2C_Mem_Write(handle->i2c_addr, ACCEL_CONFIG_REG, &config, 1, handle->i2c_context);

		config = 0x08;
		Port_I2C_Mem_Write(handle->i2c_addr, GYRO_CONFIG_REG, &config, 1, handle->i2c_context);

		config = 3;
		Port_I2C_Mem_Write(handle->i2c_addr, DLPF_CONFIG_REG, &config, 1, handle->i2c_context);

		return MPU6050_OK;
	}

	return MPU6050_ERROR;
}

MPU_Status_e MPU6050_Read_Data(MPU_Handle_s *handle) {
	if (handle == 0)
		return MPU6050_NULL_PTR;

	return Port_I2C_Mem_Read_DMA(handle->i2c_addr, ACCEL_XOUT_REG, handle->bufData, MPU_DATA_BUFFER_SIZE, handle->i2c_context);
}

void MPU6050_ProcessRawData(MPU_Handle_s *handle) {
	if (handle == 0) return;

	uint8_t *buf = handle->bufData;

	handle->data.accelX = (int16_t)(buf[0] << 8 | buf[1]);
	handle->data.accelY = (int16_t)(buf[2] << 8 | buf[3]);
	handle->data.accelZ = (int16_t)(buf[4] << 8 | buf[5]);

	handle->data.gyroX = (int16_t)(buf[8] << 8 | buf[9]);
	handle->data.gyroY = (int16_t)(buf[10] << 8 | buf[11]);
	handle->data.gyroZ = (int16_t)(buf[12] << 8 | buf[13]);

	handle->data.accelX -= handle->data.offsetAccelX;
	handle->data.accelY -= handle->data.offsetAccelY;
	handle->data.accelZ -= handle->data.offsetAccelZ;
	handle->data.gyroX -= handle->data.offsetGyroX;
	handle->data.gyroY -= handle->data.offsetGyroY;
	handle->data.gyroZ -= handle->data.offsetGyroZ;
}

MPU_Status_e MPU6050_Calibrate(MPU_Handle_s *handle) {
	if (handle == 0) return MPU6050_NULL_PTR;

	int32_t auxOffset_AX, auxOffset_AY, auxOffset_AZ;
	int32_t auxOffset_GX, auxOffset_GY, auxOffset_GZ;

	auxOffset_AX = 0;
	auxOffset_AY = 0;
	auxOffset_AZ = 0;

	auxOffset_GX = 0;
	auxOffset_GY = 0;
	auxOffset_GZ = 0;

	uint8_t localBuffer[MPU_DATA_BUFFER_SIZE];

	for (uint16_t i = 0; i < SAMPLES_SIZE; i++) {
		int8_t status = Port_I2C_Mem_Read(handle->i2c_addr, ACCEL_XOUT_REG, localBuffer, MPU_DATA_BUFFER_SIZE, handle->i2c_context);

		if (status != 0) return MPU6050_ERROR;

		if(i > (DISCARDED_SAMPLES - 1)) {
			auxOffset_AX += (int16_t)(localBuffer[0] << 8) | localBuffer[1];
			auxOffset_AY += (int16_t)(localBuffer[2] << 8) | localBuffer[3];
			auxOffset_AZ += (int16_t)(localBuffer[4] << 8) | localBuffer[5];

			auxOffset_GX += (int16_t)((localBuffer[8] << 8) | localBuffer[9]);
			auxOffset_GY += (int16_t)((localBuffer[10] << 8) | localBuffer[11]);
			auxOffset_GZ += (int16_t)((localBuffer[12] << 8) | localBuffer[13]);
		}

		Port_Delay_ms(10);
	}

	handle->data.offsetAccelX = (auxOffset_AX / (SAMPLES_SIZE - DISCARDED_SAMPLES));
	handle->data.offsetAccelY = (auxOffset_AY / (SAMPLES_SIZE - DISCARDED_SAMPLES));
	handle->data.offsetAccelZ = (auxOffset_AZ / (SAMPLES_SIZE - DISCARDED_SAMPLES));

	handle->data.offsetGyroX = (auxOffset_GX / (SAMPLES_SIZE - DISCARDED_SAMPLES));
	handle->data.offsetGyroY = (auxOffset_GY / (SAMPLES_SIZE - DISCARDED_SAMPLES));
	handle->data.offsetGyroZ = (auxOffset_GZ / (SAMPLES_SIZE - DISCARDED_SAMPLES));

	return MPU6050_OK;
}

void MPU6050_Compose_Number(MPU_Handle_s *handle, uint8_t *buf) {
	//buf[0] = Less Significant Bits
	buf[0] = handle->data.accelX & 0xFF;
	buf[1] = (handle->data.accelX >> 8) & 0xFF;
	buf[2] = handle->data.accelY & 0xFF;
	buf[3] = (handle->data.accelY >> 8) & 0xFF;
	buf[4] = handle->data.accelZ & 0xFF;
	buf[5] = (handle->data.accelZ >> 8) & 0xFF;

	buf[6] = handle->data.gyroX & 0xFF;
	buf[7] = (handle->data.gyroX >> 8) & 0xFF;
	buf[8] = handle->data.gyroY & 0xFF;
	buf[9] = (handle->data.gyroY >> 8) & 0xFF;
	buf[10] = handle->data.gyroZ & 0xFF;
	buf[11] = (handle->data.gyroZ >> 8) & 0xFF;

	buf[12] = handle->data.absoluteYaw & 0xFF;
	buf[13] = (handle->data.absoluteYaw >> 8) & 0xFF;
}

void MPU6050_Get_Yaw(MPU_Handle_s *handle, uint8_t deltaT) {
	if (handle == 0) return;

	int32_t deltaYaw = 0;
	if(handle->data.gyroZ > GYRO_THRESHOLD || handle->data.gyroZ < -GYRO_THRESHOLD){
		deltaYaw += (int32_t)(handle->data.gyroZ * deltaT);
	}

	handle->data.relativeRawYaw += deltaYaw;
	handle->data.absoluteRawYaw += deltaYaw;

	handle->data.relativeYaw = handle->data.relativeRawYaw / (GYRO_SENSITIVITY_SCALE);
	handle->data.relativeYawScaled = handle->data.relativeYaw * YAW_SCALE;

	handle->data.absoluteYaw = handle->data.absoluteRawYaw / GYRO_SENSITIVITY_SCALE;

    //handle->data.absoluteYawScaled = handle->data.absoluteYaw * YAW_SCALE;
}

void MPU6050_Reset_Yaw(MPU_Handle_s *handle) {
	if (handle == 0) return;

	handle->data.relativeRawYaw = 0;
	handle->data.relativeYaw = 0;
	handle->data.relativeYawScaled = 0;
}
/*
void MPU_DMA_RxCpltCallback(void *context) {
	MPU_Handle_s *handle = (MPU_Handle_s *) context;
	if (handle == 0) return;

	uint8_t *buf = handle->bufData;

	handle->data.accelX = (int16_t)(buf[0] << 8 | buf[1]);
	handle->data.accelY = (int16_t)(buf[2] << 8 | buf[3]);
	handle->data.accelZ = (int16_t)(buf[4] << 8 | buf[5]);

	handle->data.gyroX = (int16_t)(buf[8] << 8 | buf[9]);
	handle->data.gyroY = (int16_t)(buf[10] << 8 | buf[11]);
	handle->data.gyroZ = (int16_t)(buf[12] << 8 | buf[13]);

	handle->data.accelX -= handle->data.offsetAccelX;
	handle->data.accelY -= handle->data.offsetAccelY;
	handle->data.accelZ -= handle->data.offsetAccelZ;
	handle->data.gyroX -= handle->data.offsetGyroX;
	handle->data.gyroY -= handle->data.offsetGyroY;
	handle->data.gyroZ -= handle->data.offsetGyroZ;
}
*/

/*
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
*/

/*
void MPU6050_Read_Data_DMA(I2C_HandleTypeDef *hi2c){
	HAL_I2C_Mem_Read_DMA(hi2c, MPU6050_ADDR, ACCEL_XOUT_REG, 1, bufData, 14);
}
*/

/*
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

	libraryValues.rawYaw	= myMpuValues.rawYaw;
	libraryValues.yaw		= myMpuValues.yaw;

	myMpuValues 			= libraryValues;
}
*/

/*
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
*/

/*
void MPU6050_Compose_Number(_sMPUData mpuValues, uint8_t *buf){
	//buf[0] = Less Significant Bits
	buf[0] = mpuValues.accelX & 0xFF;
	buf[1] = (mpuValues.accelX >> 8) & 0xFF;
	buf[2] = mpuValues.accelY & 0xFF;
	buf[3] = (mpuValues.accelY >> 8) & 0xFF;
	buf[4] = mpuValues.accelZ & 0xFF;
	buf[5] = (mpuValues.accelZ >> 8) & 0xFF;

	buf[6] = mpuValues.gyroX & 0xFF;
	buf[7] = (mpuValues.gyroX >> 8) & 0xFF;
	buf[8] = mpuValues.gyroY & 0xFF;
	buf[9] = (mpuValues.gyroY >> 8) & 0xFF;
	buf[10] = mpuValues.gyroZ & 0xFF;
	buf[11] = (mpuValues.gyroZ >> 8) & 0xFF;

	buf[12] = mpuValues.yaw & 0xFF;
	buf[13] = (mpuValues.yaw >> 8) & 0xFF;
}
*/

/*
void MPU6050_Get_Yaw(_sMPUData *mpuData, uint8_t deltaT){
	if(mpuData->gyroZ > 19 || mpuData->gyroZ < -19){
		mpuData->rawYaw += (mpuData->gyroZ * deltaT);
	}
	mpuData->yaw = mpuData->rawYaw / (131*1000);
}
*/
