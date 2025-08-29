/*
 * PORT.c
 *
 *  Created on: July 24, 2025
 *      Author: Gerónimo Spiazzi
 */

#include "PORT.h"

#define I2C_DEFAULT_TIMEOUT_MS 20

/* --- IMPLEMENTACIÓN: GENÉRICA / SISTEMA --- */

void Port_Delay_ms(uint32_t period) {
    HAL_Delay(period);
}


/* --- IMPLEMENTACIÓN: GPIO / BOTONES --- */

/*
 * I2C PORT
 */

static i2c_DMA_Cplt_Callback_t dma_Tx_Callback = 0;
static void* dma_Tx_Callback_Context = 0;

static i2c_DMA_Cplt_Callback_t dma_Rx_Callback = 0;
static void* dma_Rx_Callback_Context = 0;

int8_t Port_I2C_Mem_Write(uint8_t device_addr, uint8_t reg_addr, uint8_t *data, uint16_t len, void *context){
    I2C_HandleTypeDef *hi2c = (I2C_HandleTypeDef *)context;
    HAL_StatusTypeDef status = HAL_I2C_Mem_Write(hi2c, (device_addr << 1), reg_addr, I2C_MEMADD_SIZE_8BIT, data, len, I2C_DEFAULT_TIMEOUT_MS);
    return (status == HAL_OK) ? 0 : -1;
}

int8_t Port_I2C_Mem_Write_DMA(uint8_t device_addr, uint8_t reg_addr, uint8_t *data, uint16_t len, void *context) {
    I2C_HandleTypeDef *hi2c = (I2C_HandleTypeDef *)context;
    HAL_StatusTypeDef status = HAL_I2C_Mem_Write_DMA(hi2c, (device_addr << 1), reg_addr, I2C_MEMADD_SIZE_8BIT, data, len);
    return (status == HAL_OK) ? 0 : -1;
}

int8_t Port_I2C_Mem_Read(uint8_t device_addr, uint8_t reg_addr, uint8_t *data, uint16_t len, void *context) {
    I2C_HandleTypeDef *hi2c = (I2C_HandleTypeDef *)context;
    HAL_StatusTypeDef status = HAL_I2C_Mem_Read(hi2c, (device_addr << 1), reg_addr, I2C_MEMADD_SIZE_8BIT, data, len, I2C_DEFAULT_TIMEOUT_MS);
    return (status == HAL_OK) ? 0 : -1;
}

int8_t Port_I2C_Mem_Read_DMA(uint8_t device_addr, uint8_t reg_addr, uint8_t *data, uint16_t len, void *context) {
    I2C_HandleTypeDef *hi2c = (I2C_HandleTypeDef *)context;
    HAL_StatusTypeDef status = HAL_I2C_Mem_Read_DMA(hi2c, (device_addr << 1), reg_addr, I2C_MEMADD_SIZE_8BIT, data, len);
    return (status == HAL_OK) ? 0 : -1;
}

void Port_I2C_Register_DMA_Tx_Callback(i2c_DMA_Cplt_Callback_t callback, void* callback_Context) {
	dma_Tx_Callback = callback;
	dma_Tx_Callback_Context = callback_Context;
}

void Port_I2C_Register_DMA_Rx_Callback(i2c_DMA_Cplt_Callback_t callback, void* callback_Context) {
	dma_Rx_Callback = callback;
	dma_Rx_Callback_Context = callback_Context;
}

void HAL_I2C_MemTxCpltCallback(I2C_HandleTypeDef *hi2c) {
    if (dma_Tx_Callback != 0) {
        dma_Tx_Callback(dma_Tx_Callback_Context);
    }
}

void HAL_I2C_MemRxCpltCallback(I2C_HandleTypeDef *hi2c) {
    if (dma_Rx_Callback != 0) {
        dma_Rx_Callback(dma_Rx_Callback_Context);
    }
}

