/*
 * OLED.h
 *
 *  Created on: May 29, 2024
 *      Author: Gerónimo Spiazzi
 */

#ifndef INC_OLED_H_
#define INC_OLED_H_

#include "stm32f1xx_hal.h"
#include "fonts.h"

#define OLED_I2C_ADDR        	0x78  // Dirección I2C del SSD1306 (ajustar si es necesario)
#define OLED_WIDTH           	128
#define OLED_HEIGHT          	64
#define OLED_CMD             	0x00
#define OLED_DATA            	0x40
#define DISPLAY_BUFFER_SIZE		(OLED_WIDTH * OLED_HEIGHT / 8)

#define OLED_OFF				0xAE
#define OLED_ON					0xAF
#define SET_OLED_CLOCK_DIV		0xD5
#define CHARGE_PUMP 			0x8D
#define SET_MULTIPLEX 			0xA8
#define SET_VCOM_DETECT			0xDB
#define SET_COM_PINS 			0xDA
#define NORMAL_DISPLAY 			0xA6
#define SET_SEGMENT_REMAP 		0xA1
#define COM_SCAN_DIR 			0xC8
#define SET_PRECHARGE 			0xD9
#define SET_LOW_COLUMN 			0x00
#define SET_HIGH_COLUMN 		0x10
#define SET_START_LINE			0x40
#define SET_CONTRAST 			0x81
#define SET_OLED_OFFSET			0xD3
#define MEMORY_MODE 			0x20
#define DISPLAY_ALL_ON_RESUME 	0xA4

#define OLED_COM_LR_REMAP    0
#define OLED_COM_ALTERNATIVE_PIN_CONFIG    1

/**
 * SCREEN COLORS
 */
typedef enum {
    Black = 0x00,   // Black color, no pixel
    White = 0x01,   // Pixel is set. Color depends on LCD
	Inverse = 0x02,
} Display_COLOR;

/**
 * DISPLAY VARIABLES
 */
typedef struct {
    uint16_t currentX;
    uint16_t currentY;
    uint8_t inverted;
    uint8_t initialized;
} _sSSD1306Data;

/**
 * FUNCTION DEFINITIONS
 */
uint8_t OLED_Init(I2C_HandleTypeDef *hi2c);

uint8_t OLED_UpdateScreen(I2C_HandleTypeDef *hi2c);

void OLED_Fill(Display_COLOR color);

void OLED_DrawPixel(uint8_t x, uint8_t y, Display_COLOR color);

char OLED_WriteChar(char ch, FontDef Font, Display_COLOR color);

char OLED_WriteString(const char* str, FontDef Font, Display_COLOR color);

void OLED_SetCursor(uint8_t x, uint8_t y);

void OLED_InvertColors(void);

void OLED_DrawBitmap(uint8_t W, uint8_t H, const uint8_t* pBMP);

void OLED_DrawHorizontalLine(int16_t x, int16_t y, int16_t length, Display_COLOR color);

void OLED_DrawVerticalLine(int16_t x, int16_t y, int16_t length, Display_COLOR color);

void OLED_DrawRect(int16_t x, int16_t y, int16_t width, int16_t height, Display_COLOR color);
/*

#define SWAP_INT16_T(a, b) { int16_t t = a; a = b; b = t; }

typedef struct {
	uint16_t currentX;
	uint16_t currentY;
	uint8_t initialized;
} _sSSD1306Data;

void OLED_Init(I2C_HandleTypeDef *hi2c, _sSSD1306Data displayData);
void OLED_WriteCommand(I2C_HandleTypeDef *hi2c, uint8_t command);
void DisplayFill(uint8_t color);
void OLED_WriteData(I2C_HandleTypeDef *hi2c, uint8_t* data, uint8_t size);
void DisplayUpdateScreen();
void DisplayDrawPixel(uint8_t x, uint8_t y);
void DisplayDrawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1);
char DisplayWriteChar(char ch, FontDef Font, _sSSD1306Data displayData);
char DisplayWriteString(char* str, FontDef Font, _sSSD1306Data displayData);
*/
#endif /* INC_OLED_H_ */
