/*
 * MPU6050.h
 *
 *  Created on: May 21, 2024
 *      Author: Gerónimo Spiazzi
 */

#ifndef INC_MPU6050_H_
#define INC_MPU6050_H_

#include <stdlib.h>
#include "PORT.h"

// MPU6050 address
#define MPU6050_ADDR 0x68 // 0x68 << 1 = 0xD0

// MPU6050 registers
#define WHO_AM_I_REG			0x75
#define DLPF_CONFIG_REG			0x1A
#define POWER_MANAGEMENT_REG 	0x6B
#define GYRO_CONFIG_REG 		0x1B
#define GYRO_XOUT_REG 			0x43
#define ACCEL_CONFIG_REG 		0x1C
#define ACCEL_XOUT_REG 			0x3B

// Default Values
#define WHO_AM_I_DEFAULT_VALUE 	0x68

// Library macros
#define MPU_DATA_BUFFER_SIZE	14
#define SAMPLES_SIZE			250
#define DISCARDED_SAMPLES		15
#define GYRO_THRESHOLD			50
#define GYRO_SENSITIVITY_SCALE	65500 //131 * 1000; 65.5, ETC
#define YAW_SCALE				10

typedef enum {
    MPU6050_OK = 0,
    MPU6050_ERROR = -1,
    MPU6050_NULL_PTR = -2
} MPU_Status_e;

typedef struct {
	// Sensor readings
	int16_t accelX, accelY, accelZ;
	//uint16_t temperature;
	int16_t gyroX, gyroY, gyroZ;

	// Offset values for calibration
	int16_t offsetAccelX, offsetAccelY, offsetAccelZ;
	int16_t offsetGyroX, offsetGyroY, offsetGyroZ;

	// Calculated values
	int64_t relativeRawYaw;
	int16_t relativeYaw;
	int32_t relativeYawScaled;

	int64_t absoluteRawYaw;
	int16_t absoluteYaw;
	//int32_t absoluteYawScaled;
} MPU_Data_s;

typedef struct {
	// Configuration
	uint8_t i2c_addr;					// Device I2C Address
	void *i2c_context;					// I2C_HandleTypeDef*

	// Data and state
	MPU_Data_s data;					// Sensor data
	uint8_t bufData[MPU_DATA_BUFFER_SIZE];	// Readings buffer
} MPU_Handle_s;


MPU_Status_e MPU6050_Init(MPU_Handle_s *handle, uint8_t i2c_addr, void* i2c_ctx);
MPU_Status_e MPU6050_Read_Data(MPU_Handle_s *handle);
MPU_Status_e MPU6050_Calibrate(MPU_Handle_s *handle);
void MPU6050_Compose_Number(MPU_Handle_s *handle, uint8_t *buf);
void MPU6050_Get_Yaw(MPU_Handle_s *handle, uint8_t deltaT);
void MPU6050_Reset_Yaw(MPU_Handle_s *handle);
void MPU6050_ProcessRawData(MPU_Handle_s *handle);
//void MPU_DMA_RxCpltCallback(void *context);

// Prototypes
/*
void MPU6050_Init(I2C_HandleTypeDef *hi2c);
void MPU6050_Read_Data_DMA(I2C_HandleTypeDef *hi2c);
void MPU6050_Compose_Number(_sMPUData mpuValues, uint8_t *buf);
void MPU6050_Calibrate(I2C_HandleTypeDef *hi2c);
void MPU6050_Get_Yaw(_sMPUData *mpuData, uint8_t deltaT);
*/
#endif /* INC_MPU6050_H_ */
