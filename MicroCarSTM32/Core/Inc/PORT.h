/*
 * PORT.h
 *
 *  Created on: July 24, 2025
 *      Author: Gerónimo Spiazzi
 */

#ifndef INC_PORT_H_
#define INC_PORT_H_

#include <stdint.h>
#include "stm32f1xx_hal.h"

// --- SECCIÓN: GENÉRICA / SISTEMA ---

/**
 * @brief Proporciona un retardo bloqueante en milisegundos.
 */
void Port_Delay_ms(uint32_t period);


// --- SECCIÓN: GPIO / BOTONES ---


// --- SECCIÓN: I2C ---
typedef enum {
	I2C_BUS_IDLE,
	I2C_BUS_BUSY,
} I2C_State_e;

typedef void (*i2c_DMA_Cplt_Callback_t)(void *context);

/**
 * @brief Escribe en un registro de un dispositivo I2C de forma bloqueante.
 * @param device_addr Dirección I2C de 7 bits del dispositivo.
 * @param reg_addr Dirección del registro a escribir.
 * @param data Puntero a los datos a enviar.
 * @param len Longitud de los datos.
 * @param context Puntero al contexto de la plataforma (ej: I2C_HandleTypeDef*).
 * @return 0 en éxito, <0 en error.
 */
int8_t Port_I2C_Mem_Write(uint8_t device_addr, uint8_t reg_addr, uint8_t *data, uint16_t len, void *context);

/**
 * @brief Inicia una escritura a un registro I2C usando DMA (no bloqueante).
 * @return 0 en éxito, <0 en error.
 */
int8_t Port_I2C_Mem_Write_DMA(uint8_t device_addr, uint8_t reg_addr, uint8_t *data, uint16_t len, void *context);

/**
 * @brief Lee de un registro de un dispositivo I2C de forma bloqueante.
 * @param ... (parámetros similares)
 * @return 0 en éxito, <0 en error.
 */
int8_t Port_I2C_Mem_Read(uint8_t device_addr, uint8_t reg_addr, uint8_t *data, uint16_t len, void *context);

/**
 * @brief Inicia una lectura de un registro I2C usando DMA.
 * @param ... (parámetros similares)
 * @return 0 en éxito, <0 en error.
 */
int8_t Port_I2C_Mem_Read_DMA(uint8_t device_addr, uint8_t reg_addr, uint8_t *data, uint16_t len, void *context);

/**
 * @brief Proporciona un retardo en milisegundos.
 */
void Port_Delay_ms(uint32_t period);

/**
 * @brief Registra una función de callback para ser llamada al finalizar la DMA.
 */
void Port_I2C_Register_DMA_Tx_Callback(i2c_DMA_Cplt_Callback_t callback, void *callback_Context);
void Port_I2C_Register_DMA_Rx_Callback(i2c_DMA_Cplt_Callback_t callback, void *callback_Context);
#endif /* INC_PORT_H_ */
