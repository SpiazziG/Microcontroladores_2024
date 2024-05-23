/*
 * MPU6050.c
 *
 *  Created on: May 21, 2024
 *      Author: Gerónimo Spiazzi
 */

#include "mpu6050.h"

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

        // Set gyroscope range (+/- 250, 500, 1000, 2000 degree/seg)
        data = 0; // 250 degree/seg (default)
        HAL_I2C_Mem_Write(hi2c, MPU6050_ADDR, GYRO_CONFIG_REG, 1, &data, 1, 1);
    }
}

void MPU6050_Read_Data(I2C_HandleTypeDef *hi2c, _sMPUData *accelData) {
    uint8_t recData[6];

    // Read 6 bytes from acceleration registers
    HAL_I2C_Mem_Read(hi2c, MPU6050_ADDR, ACCEL_XOUT_REG, 1, recData, 6, 1);

    // Load low part first
    accelData->accelX[0] = recData[1];
    accelData->accelX[1] = recData[0];

    accelData->accelY[0] = recData[3];
    accelData->accelY[1] = recData[2];

    accelData->accelZ[0] = recData[5];
    accelData->accelZ[1] = recData[4];

    // Read 6 bytes from gyroscope registers
    uint8_t gyroData[6];
    HAL_I2C_Mem_Read(hi2c, MPU6050_ADDR, GYRO_XOUT_REG, 1, gyroData, 6, 1);

    // Load low part first
    accelData->gyroX[0] = gyroData[1];
    accelData->gyroX[1] = gyroData[0];

    accelData->gyroY[0] = gyroData[3];
    accelData->gyroY[1] = gyroData[2];

    accelData->gyroZ[0] = gyroData[5];
    accelData->gyroZ[1] = gyroData[4];
}
