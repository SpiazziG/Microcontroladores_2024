/*
 * OLED.c
 *
 *  Created on: May 29, 2024
 *      Author: Gerónimo Spiazzi
 */

#include "OLED.h"
#include "stdio.h"
//static void OLED_UpdateScreen_DMA_Step(OLED_Handle_s *handle);
//static void OLED_Tx_Cplt_Callback(void *context);
static OLED_Status_e OLED_WriteCommand(OLED_Handle_s *handle, uint8_t command);
static OLED_Status_e OLED_WriteCommand_DMA(OLED_Handle_s *handle, uint8_t command);

/*
static uint8_t displayBuffer[DISPLAY_BUFFER_SIZE];

static _sSSD1306Data displayData;	// Screen object
*/

/**
 *	BLOCKING METHOD TO WRITE INTO THE DISPLAY
 */
static OLED_Status_e OLED_WriteCommand(OLED_Handle_s *handle, uint8_t command) {
    if (Port_I2C_Mem_Write(handle->i2cAddr, OLED_CMD, &command, 1, handle->i2cContext) != 0) {
        return OLED_ERROR;
    }
    return OLED_OK;
}

/**
 * NON-BLOCKING METHOD TO WRITE INTO THE DISPLAY
 */


static OLED_Status_e OLED_WriteCommand_DMA(OLED_Handle_s *handle, uint8_t command) {
    // La capa de plataforma necesita un puntero a los datos, no los datos directamente.
    // Como la variable 'command' es local a esta función, si la función termina
    // antes de que el DMA la envíe, el puntero apuntaría a basura.
    // Para un solo byte, esto es un problema.

    // --- Solución Robusta ---
    // Usar una variable estática para asegurar que la memoria persiste.

	static uint8_t dma_Command_Buffer;
	dma_Command_Buffer = command;

	return Port_I2C_Mem_Write_DMA(handle->i2cAddr, 0x00, &dma_Command_Buffer, 1, handle->i2cContext);
}


/**
 * INITIALIZE THE DISPLAY
 */
OLED_Status_e OLED_Init(OLED_Handle_s *handle, uint8_t i2c_addr, void* i2c_ctx) {
    if (handle == 0 || i2c_ctx == 0)
        return OLED_NULL_PTR;

    handle->i2cAddr = i2c_addr;
    handle->i2cContext = i2c_ctx;

    handle->isUpdating = 0;

    //Port_I2C_Register_DMA_Tx_Callback(OLED_Tx_Cplt_Callback, handle);
    handle->currentPageToUpdate = 8; // Estado inicial: completado
    handle->updatePageState = 0;

    Port_Delay_ms(100); // Wait for the screen to boot

    if (OLED_WriteCommand(handle, OLED_OFF) != OLED_OK) return OLED_ERROR;  	// Display off
    if (OLED_WriteCommand(handle, MEMORY_MODE) != OLED_OK) return OLED_ERROR;   // Set Memory Addressing Mode
    if (OLED_WriteCommand(handle, 0x00) != OLED_OK) return OLED_ERROR;			// 00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
    if (OLED_WriteCommand(handle, 0xB0) != OLED_OK) return OLED_ERROR;			// Set Page Start Address for Page Addressing Mode,0-7
    if (OLED_WriteCommand(handle, 0xC8) != OLED_OK) return OLED_ERROR;			// Set COM Output Scan Direction
    if (OLED_WriteCommand(handle, SET_LOW_COLUMN) != OLED_OK) return OLED_ERROR;// Set low column address
    if (OLED_WriteCommand(handle, SET_HIGH_COLUMN) != OLED_OK) return OLED_ERROR;// Set high column address
    if (OLED_WriteCommand(handle, SET_START_LINE) != OLED_OK) return OLED_ERROR;// Set start line address
    if (OLED_WriteCommand(handle, 0x81) != OLED_OK) return OLED_ERROR;			// Set contrast control register
    if (OLED_WriteCommand(handle, 0xCF) != OLED_OK) return OLED_ERROR;
    if (OLED_WriteCommand(handle, SET_SEGMENT_REMAP) != OLED_OK) return OLED_ERROR;// Set segment re-map 0 to 127
    if (OLED_WriteCommand(handle, NORMAL_DISPLAY) != OLED_OK) return OLED_ERROR;// Set normal display
    if (OLED_WriteCommand(handle, SET_MULTIPLEX) != OLED_OK) return OLED_ERROR;	// Set multiplex ratio(1 to 64)
    if (OLED_WriteCommand(handle, OLED_HEIGHT - 1) != OLED_OK) return OLED_ERROR;
    if (OLED_WriteCommand(handle, DISPLAY_ALL_ON_RESUME) != OLED_OK) return OLED_ERROR;// 0xa4,Output follows RAM content;0xa5,Output ignores RAM content
    if (OLED_WriteCommand(handle, SET_OLED_OFFSET) != OLED_OK) return OLED_ERROR;// Set display offset
    if (OLED_WriteCommand(handle, 0x00) != OLED_OK) return OLED_ERROR; 			// No offset
    if (OLED_WriteCommand(handle, SET_OLED_CLOCK_DIV) != OLED_OK) return OLED_ERROR;// Set display clock divide ratio/oscillator frequency
    if (OLED_WriteCommand(handle, 0x80) != OLED_OK) return OLED_ERROR;			// Set divide ratio
    if (OLED_WriteCommand(handle, SET_PRECHARGE) != OLED_OK) return OLED_ERROR;	// Set pre-charge period
    if (OLED_WriteCommand(handle, 0xF1) != OLED_OK) return OLED_ERROR;
    if (OLED_WriteCommand(handle, SET_COM_PINS) != OLED_OK) return OLED_ERROR;	// Set com pins hardware configuration
    if (OLED_WriteCommand(handle, OLED_COM_LR_REMAP << 5 | OLED_COM_ALTERNATIVE_PIN_CONFIG << 4 | 0x02) != OLED_OK) return OLED_ERROR;
    if (OLED_WriteCommand(handle, SET_VCOM_DETECT) != OLED_OK) return OLED_ERROR;// Set vcomh
    if (OLED_WriteCommand(handle, 0x40) != OLED_OK) return OLED_ERROR;			// 0x20,0.77xVcc
    if (OLED_WriteCommand(handle, CHARGE_PUMP) != OLED_OK) return OLED_ERROR;	// Set DC-DC enable
    if (OLED_WriteCommand(handle, 0x14) != OLED_OK) return OLED_ERROR;
    if (OLED_WriteCommand(handle, OLED_ON) != OLED_OK) return OLED_ERROR;		// Turn on Display panel

    OLED_Fill(handle, Black);		// Clear screen

    /*
    if (OLED_UpdateScreen_Blocking(handle) != OLED_OK) {
        return OLED_ERROR;
    }
     */
    handle->currentX = 0;			// Set default values for screen object
    handle->currentY = 0;
    handle->initialized = 1;		// Checked initialization of the display
    handle->inverted = 0;
    handle->currentPageToUpdate = 0;

    return OLED_OK;
}

/**
 * FILL THE DISPLAY WITH A CERTAIN COLOR
 */
void OLED_Fill(OLED_Handle_s *handle, OLED_Color_e color) {
	if (handle == 0) return;

    uint16_t i;
    uint8_t fill_value = (color == Black) ? 0x00 : 0xFF;

    for (i = 0; i < OLED_BUFFER_SIZE; i++)
        handle->buffer[i] = fill_value;
}

/**
 * UPDATE DATA OF THE DISPLAY
 */

// En OLED.c, reemplaza la función de actualización
//OLED_Status_e OLED_UpdateScreen_DMA(OLED_Handle_s *handle) {
//    if (handle == 0) return OLED_NULL_PTR;
//
//    // 1. Enviar los comandos de configuración de ventana de forma bloqueante
//    //    Esto posiciona el cursor en la esquina superior izquierda (col 0, pag 0)
//    uint8_t cmds[] = {
//        0x21, // Command: Set Column Address
//        0,    // Column Start Address
//        127,  // Column End Address
//        0x22, // Command: Set Page Address
//        0,    // Page Start Address
//        7     // Page End Address
//    };
//
//    for (uint8_t i = 0; i < sizeof(cmds); i++) {
//        if (OLED_WriteCommand(handle, cmds[i]) != OLED_OK) {
//            return OLED_ERROR; // Falló un comando bloqueante
//        }
//    }
//
//    // 2. Ahora, lanzar UNA ÚNICA transferencia DMA para los 1024 bytes del buffer
//    return Port_I2C_Mem_Write_DMA(handle->i2cAddr, OLED_DATA, handle->buffer, OLED_BUFFER_SIZE, handle->i2cContext);
//}


void OLED_UpdateSingleStep_DMA(OLED_Handle_s *handle) {
    // El switch se encarga de enviar un paso de la actualización.
    // La callback de DMA se encargará de llamar a esta función de nuevo para el siguiente paso.

    switch (handle->updatePageState) {
        case 0: // Enviar comando para posicionar la página (0xB0 a 0xB7)
            OLED_WriteCommand_DMA(handle, 0xB0 + handle->currentPageToUpdate);
            break;

        case 1: // Enviar comando para posicionar columna baja (0x00)
            OLED_WriteCommand_DMA(handle, SET_LOW_COLUMN);
            break;

        case 2: // Enviar comando para posicionar columna alta (0x10)
            OLED_WriteCommand_DMA(handle, SET_HIGH_COLUMN);
            break;

        case 3: // Enviar una fila (128 bytes) del framebuffer por DMA
                // Calcula el puntero al inicio de la página actual en el buffer
                uint8_t* pageStart = &handle->buffer[OLED_WIDTH * handle->currentPageToUpdate];
                Port_I2C_Mem_Write_DMA(handle->i2cAddr, OLED_DATA, pageStart, OLED_WIDTH, handle->i2cContext);
            break;
    }

    // Avanzar la máquina de estados para la próxima llamada de la callback
//    handle->updatePageState++;
}


uint8_t OLED_IsBusy(OLED_Handle_s *handle) {
    if (handle == 0) return 0;
    return handle->isUpdating;
}

/*
OLED_Status_e OLED_UpdateScreen_Blocking(OLED_Handle_s *handle) {
    if (handle == NULL) {
        return OLED_NULL_PTR;
    }

    uint8_t cmds[] = {0x21, 0, 127, 0x22, 0, 7};
    for (uint8_t i = 0; i < sizeof(cmds); i++) {
        if (OLED_WriteCommand(handle, cmds[i]) != OLED_OK) return OLED_ERROR;
    }

	// 3. Enviar los 128 bytes de datos de la página de forma bloqueante.
	//    Usamos la función Port_I2C_Mem_Write, que es la versión bloqueante.
	if (Port_I2C_Mem_Write(handle->i2cAddr, OLED_DATA, handle->buffer, OLED_BUFFER_SIZE, handle->i2cContext) != 0) {
		return OLED_ERROR;
	}

    return OLED_OK; // Si todas las páginas se enviaron correctamente
}
*/
//static void OLED_UpdateScreen_DMA_Step(OLED_Handle_s *handle) {
//    // Si la repetición ha llegado a 8, significa que hemos enviado las 8 páginas.
//    // El proceso ha terminado.
//    if (handle->update_repetition > 7) {
//        // Reiniciar para la próxima vez
//        handle->update_repetition = 0;
//        *(handle->i2cBusStatePtr) = I2C_BUS_IDLE;
//        // Opcional: aquí podrías llamar a una callback de "actualización completa".
//        return;
//    }
//
//    switch (handle->update_state) {
//        case 0:
//            // Enviar comando para posicionar la página (0xB0 a 0xB7)
//            OLED_WriteCommand_DMA(handle, 0xB0 + handle->update_repetition);
//            break;
//        case 1:
//            // Enviar comando para posicionar columna baja (0x00)
//            OLED_WriteCommand_DMA(handle, 0x00);
//            break;
//        case 2:
//            // Enviar comando para posicionar columna alta (0x10)
//            OLED_WriteCommand_DMA(handle, 0x10);
//            break;
//        case 3:
//            { // Enviar una fila (128 bytes) del framebuffer por DMA
//                uint8_t* start_of_row = &handle->buffer[OLED_WIDTH * handle->update_repetition];
//                Port_I2C_Mem_Write_DMA(handle->i2c_addr, 0x40, start_of_row, OLED_WIDTH, handle->i2c_context);
//            }
//            break;
//    }
//
//    // Avanzar la máquina de estados para la próxima llamada de la callback
//    handle->update_state++;
//    if (handle->update_state > 3) {
//        handle->update_state = 0;
//        handle->update_repetition++;
//    }
//}

/**
 * DRAW A PIXEL IN THE DISPLAY
 */
void OLED_DrawPixel(OLED_Handle_s *handle, uint8_t x, uint8_t y, OLED_Color_e color) {
    if (x >= OLED_WIDTH || y >= OLED_HEIGHT || handle == 0) {
        return; // No escribir fuera del buffer
    }

    if (handle->inverted)				// Check if pixel should be inverted
    	color = (OLED_Color_e)!color;

    // Operamos sobre el buffer DENTRO del handle
    if (color == White) {
        handle->buffer[x + (y / 8) * OLED_WIDTH] |= 1 << (y % 8);
    } else {
        handle->buffer[x + (y / 8) * OLED_WIDTH] &= ~(1 << (y % 8));
    }
}

/**
 * WRITE A CHAR INTO THE DISPLAY BUFFER
 */
char OLED_WriteChar(OLED_Handle_s *handle, char ch, FontDef Font, OLED_Color_e color) {
    if (handle == 0) return 0;

    uint32_t i, b, j;

    // Comprobar espacio restante
    if (OLED_WIDTH <= (handle->currentX + Font.FontWidth) ||
        OLED_HEIGHT <= (handle->currentY + Font.FontHeight)) {
        return 0;
    }

    // Traducir la fuente al framebuffer
    for (i = 0; i < Font.FontHeight; i++) {
        b = Font.data[(ch - 32) * Font.FontHeight + i];
        for (j = 0; j < Font.FontWidth; j++) {
            if ((b << j) & 0x8000) {
                OLED_DrawPixel(handle, handle->currentX + j, (handle->currentY + i), color);
            } else {
                OLED_DrawPixel(handle, handle->currentX + j, (handle->currentY + i), (OLED_Color_e)!color);
            }
        }
    }

    // Avanzar el cursor
    handle->currentX += Font.FontWidth;

    return ch;
}

/**
 * WRITE STRING INTO THE DISPLAY BUFFER
 */
char OLED_WriteString(OLED_Handle_s *handle, const char* str, FontDef Font, OLED_Color_e color) {
    if (handle == 0) return 0;

    while (*str) {
        if (OLED_WriteChar(handle, *str, Font, color) != *str) {
            return *str; // No se pudo escribir el carácter
        }
        str++;
    }
    return *str; // Everything OK
}

/**
 * INVERT DISPLAY COLORS
 */
void OLED_InvertColors(OLED_Handle_s *handle){
	handle->inverted = !handle->inverted;
}

/**
 * SET CURSOR POSITION
 */
void OLED_SetCursor(OLED_Handle_s *handle, uint8_t x, uint8_t y) {
    if (handle == 0) return;
    handle->currentX = x;
    handle->currentY = y;
}

/**
 * DRAW BITMAP
 */
void OLED_DrawBitmap(OLED_Handle_s *handle, uint8_t W, uint8_t H, const uint8_t* pBMP) {
	if (handle == 0) return;

	uint16_t byteWidth = (W + 7) / 8; // Calculate the width in bytes
	for (uint16_t y = 0; y < H; y++){
		for (uint16_t x = 0; x < W; x++){
			if (pBMP[y * byteWidth + x / 8] & (128 >> (x & 7)))
				OLED_DrawPixel(handle, x, y, White);
		}
	}
}

void OLED_DrawHorizontalLine(OLED_Handle_s *handle, int16_t x, int16_t y, int16_t length, OLED_Color_e color){
  if (y < 0 || y >= OLED_HEIGHT)
	  return;

  if (x < 0){
	  length += x;
	  x = 0;
  }

  if((x + length) > OLED_WIDTH)
	  length = (OLED_WIDTH - x);


  if(length <= 0)
	  return;

  uint8_t * bufferPtr = handle->buffer;
  bufferPtr += (y >> 3) * OLED_WIDTH;
  bufferPtr += x;

  uint8_t drawBit = 1 << (y & 7);

  switch (color){
    case White:
    	while (length--)
    		*bufferPtr++ |= drawBit;
    	break;
    case Black:
    	drawBit = ~drawBit;
    	while (length--)
    		*bufferPtr++ &= drawBit;
    	break;
    case Inverse:
    	while (length--)
    		*bufferPtr++ ^= drawBit;
    	 break;
  }
}

void OLED_DrawVerticalLine(OLED_Handle_s *handle, int16_t x, int16_t y, int16_t length, OLED_Color_e color){
  if(x < 0 || x >= OLED_WIDTH)
	  return;

  if(y < 0){
	  length += y;
	  y = 0;
  }

  if ( (y + length) > OLED_HEIGHT)
	  length = (OLED_HEIGHT - y);

  if (length <= 0)
	  return;

  uint8_t yOffset = y & 7;
  uint8_t drawBit;
  uint8_t *bufferPtr = handle->buffer;

  bufferPtr += (y >> 3) * OLED_WIDTH;
  bufferPtr += x;

  if (yOffset){
    yOffset = 8 - yOffset;
    drawBit = ~(0xFF >> (yOffset));

    if (length < yOffset)
    	drawBit &= (0xFF >> (yOffset - length));

    switch (color){
      case White:   *bufferPtr |=  drawBit; break;
      case Black:   *bufferPtr &= ~drawBit; break;
      case Inverse: *bufferPtr ^=  drawBit; break;
    }

    if (length < yOffset) return;

    length -= yOffset;
    bufferPtr += OLED_WIDTH;
  }

  if (length >= 8) {
    switch (color){
      case White:
      case Black:
        drawBit = (color == White) ? 0xFF : 0x00;
        do {
          *bufferPtr = drawBit;
          bufferPtr += OLED_WIDTH;
          length -= 8;
        } while (length >= 8);
        break;
      case Inverse:
        do {
          *bufferPtr = ~(*bufferPtr);
          bufferPtr += OLED_WIDTH;
          length -= 8;
        } while (length >= 8);
        break;
    }
  }

  if(length > 0){
    drawBit = (1 << (length & 7)) - 1;
    switch (color){
      case White:   *bufferPtr |=  drawBit; break;
      case Black:   *bufferPtr &= ~drawBit; break;
      case Inverse: *bufferPtr ^=  drawBit; break;
    }
  }
}

void OLED_DrawRect(OLED_Handle_s *handle, int16_t x, int16_t y, int16_t width, int16_t height, OLED_Color_e color){
	OLED_DrawHorizontalLine(handle, x, y, width, color);
	OLED_DrawVerticalLine(handle, x, y, height, color);
	OLED_DrawVerticalLine(handle, x + width - 1, y, height, color);
	OLED_DrawHorizontalLine(handle, x, y + height - 1, width, color);
}

void OLED_DrawFilledRect(OLED_Handle_s *handle, int16_t x, int16_t y, int16_t w, int16_t h, OLED_Color_e color){
	for (int i = 0; i < w; i++) {
		OLED_DrawVerticalLine(handle, x + i, y, h, color);
	}
}

void OLED_DrawHeader(OLED_Handle_s *handle, const char* title, uint32_t ticks) {
	// Background
	OLED_DrawFilledRect(handle, 0, 0, OLED_WIDTH, GUI_HEADER_HEIGHT, White);

	OLED_SetCursor(handle, 2, 1);
	OLED_WriteString(handle, (char*)title, Font_7x10, Black);

	uint32_t totalSeconds = ticks / 1000;
	uint8_t minutes = (totalSeconds / 60) % 100;
	uint8_t seconds = totalSeconds % 60;

	char timeStr[6];
	sprintf(timeStr, "%02d:%02d", minutes, seconds);

	OLED_SetCursor(handle, 88, 1);
	OLED_WriteString(handle, timeStr, Font_7x10, Black);
}

/**
 * @brief Dibuja un widget de sensor individual
 * @param id: Número o letra para identificar el sensor
 * @param val: Valor actual del sensor
 * @param x, y: Coordenadas de la esquina superior izquierda del widget
 */
void OLED_DrawSensorWidget(OLED_Handle_s *handle, char *label, uint16_t val, uint8_t col, uint8_t row) {
	// Calculate Coordinates
	// Start X = Margin + Column * (Bar Width + Gap)
	// Column 0: 4
	// Column 1: 4 + 34 + 9 = 47
	// Column 2: 47 + 34 + 9 = 90

	int16_t x_base = GUI_MARGIN_LEFT + (col * (GUI_BAR_WIDTH + GUI_WIDGET_COL_GAP));

	// Widget's total height = box + gapBoxBar + Bar + GapRow
	// Height = 10 + 2 + 3 + 2 = 17
	// Initial Offset = Header(11) + GapHeader(2) = 13
	int16_t y_base = (GUI_HEADER_HEIGHT + 2) + (row * (GUI_BOX_HEIGHT + GUI_BOX_TO_BAR_GAP + GUI_BAR_HEIGHT + GUI_WIDGET_ROW_GAP));

	// Components specifics coordinates
	int16_t box_x = x_base + ((GUI_BAR_WIDTH - GUI_BOX_WIDTH) / 2); // Centered Box ID

	int16_t bar_y = y_base + GUI_BOX_HEIGHT + GUI_BOX_TO_BAR_GAP;

// Draw Value
	char textBuf[6];
	sprintf(textBuf, "%4d", val);
	OLED_SetCursor(handle, x_base + 3, y_base);
	OLED_WriteString(handle, textBuf, Font_7x10, White);
	// Draw ID
//	OLED_SetCursor(handle, box_x + 3, y_base);
//	OLED_WriteString(handle, label, Font_7x10, White);

	// Calculate bar width
	if (val > GUI_BAR_MAX_VAL) val = GUI_BAR_MAX_VAL;

	uint16_t fillWidth = (uint32_t)(val * GUI_BAR_WIDTH) / GUI_BAR_MAX_VAL;

	// Draw filled Bar
	//int16_t barX = x + (WIDGET_W - BAR_WIDTH) / 2;
	//int16_t barY = y + BOX_HEIGHT + 2;

	if (fillWidth > 0) {
		OLED_DrawFilledRect(handle, x_base, bar_y, fillWidth, GUI_BAR_HEIGHT, White);
	}
}

void OLED_DrawDigitalEye(OLED_Handle_s *handle, uint8_t x, uint8_t y, uint8_t w, uint8_t h) {
	uint8_t r;
	r = 3;

	OLED_DrawFilledRect(handle, x + r, y, w - (2 * r), h, White);
	OLED_DrawFilledRect(handle, x, y + r, w, h - (2 * r), White);

	OLED_DrawPixel(handle, x + 1, y + 1, White);
	OLED_DrawPixel(handle, x + w - 2, y + 1, White);
	OLED_DrawPixel(handle, x + 1, y + h - 2, White);
	OLED_DrawPixel(handle, x + w - 2, y + h - 2, White);
}

void OLED_DrawBidirectionalBar(OLED_Handle_s *handle, uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint16_t val, int32_t maxScale) {
	// Dibujar contorno
	OLED_DrawRect(handle, x, y, w, h, White);

	// Dibujar línea central
	int8_t midX = x + (w / 2);
	OLED_DrawVerticalLine(handle, midX, y, h, White);

	// Calcular relleno
	int16_t absVal = (val < 0) ? -val : val;

	int8_t halfW = (w - 4) / 2;

	if (maxScale == 0) maxScale = 1;

	// Regla de 3
	int8_t barLen = (absVal * halfW) / maxScale;

	if (barLen > halfW) barLen = halfW; // Saturación

	if (barLen > 0) {
		if (val > 0) {
			// Positivo, del centro hacia la derecha
			// X start: midX + 1
			OLED_DrawFilledRect(handle, midX + 1, y + 2, barLen, h - 4, White);
		} else {
			OLED_DrawFilledRect(handle, midX - barLen, y + 2, barLen, h - 4, White);
		}
	}

	char str[6];

	sprintf(str, "%4d", val);
	OLED_SetCursor(handle, 94, y);
	OLED_WriteString(handle, str, Font_7x10, White);

}
/*
static void OLED_Tx_Cplt_Callback(void *context) {
    // 1. Convertir el puntero de contexto genérico de vuelta a nuestro tipo de handle.
    OLED_Handle_s *handle = (OLED_Handle_s*)context;

    // 2. Comprobación de seguridad.
    if (handle == 0)
        return;

    // 3. La transmisión de un trozo terminó, ahora le decimos a la máquina de estados
    //    que envíe el siguiente trozo.
    //OLED_UpdateScreen_DMA_Step(handle);
}
*/
/*
void HAL_I2C_MemTxCpltCallback(I2C_HandleTypeDef *hi2c){
	//if(hi2c->Instance == SSD1306_I2C_PORT.Instance){
		//TODO:
	//}
}
*/

/**
 *	BLOCKING METHOD TO WRITE INTO THE DISPLAY
 */
/*
static uint8_t OLED_WriteCommand(I2C_HandleTypeDef *hi2c, uint8_t command){
    return HAL_I2C_Mem_Write(hi2c, OLED_I2C_ADDR, 0x00, 1, &command, 1, 10);
}

 * NON-BLOCKING METHOD TO WRITE INTO THE DISPLAY
 */
/*
static uint8_t OLED_WriteCommand_DMA(I2C_HandleTypeDef *hi2c, uint8_t command){
    return HAL_I2C_Mem_Write_DMA(hi2c, OLED_I2C_ADDR, 0x00, 1, &command, 1);
}

 * INITIALIZE THE DISPLAY
 */
/*
uint8_t OLED_Init(I2C_HandleTypeDef *hi2c){
    HAL_Delay(100);	// Wait for the screen to boot
    int status = 0;

    status += OLED_WriteCommand(hi2c, OLED_OFF);   // Display off
    status += OLED_WriteCommand(hi2c, MEMORY_MODE);   // Set Memory Addressing Mode
    status += OLED_WriteCommand(hi2c, 0x10);   // 00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
    status += OLED_WriteCommand(hi2c, 0xB0);   // Set Page Start Address for Page Addressing Mode,0-7
    status += OLED_WriteCommand(hi2c, 0xC8);   // Set COM Output Scan Direction
    status += OLED_WriteCommand(hi2c, SET_LOW_COLUMN);   // Set low column address
    status += OLED_WriteCommand(hi2c, SET_HIGH_COLUMN);   // Set high column address
    status += OLED_WriteCommand(hi2c, SET_START_LINE);   // Set start line address
    status += OLED_WriteCommand(hi2c, 0x81);   // set contrast control register
    status += OLED_WriteCommand(hi2c, 0xFF);
    status += OLED_WriteCommand(hi2c, SET_SEGMENT_REMAP);   // Set segment re-map 0 to 127
    status += OLED_WriteCommand(hi2c, NORMAL_DISPLAY);   // Set normal display

    status += OLED_WriteCommand(hi2c, SET_MULTIPLEX);   // Set multiplex ratio(1 to 64)
    status += OLED_WriteCommand(hi2c, OLED_HEIGHT - 1);

    status += OLED_WriteCommand(hi2c, DISPLAY_ALL_ON_RESUME);   // 0xa4,Output follows RAM content;0xa5,Output ignores RAM content
    status += OLED_WriteCommand(hi2c, SET_OLED_OFFSET);   // Set display offset
    status += OLED_WriteCommand(hi2c, 0x00);   // No offset
    status += OLED_WriteCommand(hi2c, SET_OLED_CLOCK_DIV);   // Set display clock divide ratio/oscillator frequency
    status += OLED_WriteCommand(hi2c, 0xF0);   // Set divide ratio
    status += OLED_WriteCommand(hi2c, SET_PRECHARGE);   // Set pre-charge period
    status += OLED_WriteCommand(hi2c, 0x22);

    status += OLED_WriteCommand(hi2c, SET_COM_PINS);   // Set com pins hardware configuration
    status += OLED_WriteCommand(hi2c, OLED_COM_LR_REMAP << 5 | OLED_COM_ALTERNATIVE_PIN_CONFIG << 4 | 0x02);

    status += OLED_WriteCommand(hi2c, SET_VCOM_DETECT);   // Set vcomh
    status += OLED_WriteCommand(hi2c, 0x20);   // 0x20,0.77xVcc
    status += OLED_WriteCommand(hi2c, CHARGE_PUMP);   // Set DC-DC enable
    status += OLED_WriteCommand(hi2c, 0x14);   //
    status += OLED_WriteCommand(hi2c, OLED_ON);   // Turn on Display panel

    if (status != 0)
        return 1;

    OLED_Fill(Black);		// Clear screen
    displayData.currentX = 0;		// Set default values for screen object
    displayData.currentY = 0;
    displayData.initialized = 1;	// Checked initialization of the display

    return 0;
}

 * FILL THE DISPLAY WITH A CERTAIN COLOR
 */
/*
void OLED_Fill(Display_COLOR color){
    uint16_t i;

    for(i = 0; i < sizeof(displayBuffer); i++)	// Fill screenbuffer with a constant value (color)
        displayBuffer[i] = (color == Black) ? 0x00 : 0xFF;
}

 * UPDATE DATA OF THE DISPLAY
 */
/*
uint8_t OLED_UpdateScreen(I2C_HandleTypeDef *hi2c){
	static uint8_t updateScreenState = 0;
	static uint8_t repetition = 0;
	uint8_t IsUpdateScreenTime = 1;

	switch (updateScreenState) {
		case 0:
			OLED_WriteCommand_DMA(hi2c, 0xB0 + repetition);
			break;
		case 1:
			OLED_WriteCommand_DMA(hi2c, 0x00);
			break;
		case 2:
			OLED_WriteCommand_DMA(hi2c, 0x10);
			break;
		case 3:
			HAL_I2C_Mem_Write_DMA(hi2c, OLED_I2C_ADDR, 0x40, 1, &displayBuffer[OLED_WIDTH * repetition], OLED_WIDTH);
			break;
	}

	updateScreenState++;

	if (updateScreenState > 3) {
		updateScreenState = 0;
		repetition++;

		if (repetition > 7) {
			updateScreenState = 0;
			repetition = 0;
			IsUpdateScreenTime = 0;
		}
	}
	return(IsUpdateScreenTime);
}

 * DRAW A PIXEL IN THE DISPLAY
 */
/*
void OLED_DrawPixel(uint8_t x, uint8_t y, Display_COLOR color){
    if (x >= OLED_WIDTH || y >= OLED_HEIGHT)	// Don't write outside the buffer
        return;

    if (displayData.inverted)				// Check if pixel should be inverted
    	color = (Display_COLOR)!color;

    if (color == White)		// Draw in the correct color
        displayBuffer[x + (y / 8) * OLED_WIDTH] |= 1 << (y % 8);
    else
    	displayBuffer[x + (y / 8) * OLED_WIDTH] &= ~(1 << (y % 8));
}

 * WRITE A CHAR INTO THE DISPLAY BUFFER
 */
/*
char OLED_WriteChar(char ch, FontDef Font, Display_COLOR color){
    uint32_t i, b, j;

    // Check remaining space on current line
    if (OLED_WIDTH <= (displayData.currentX + Font.FontWidth) ||
        OLED_HEIGHT <= (displayData.currentY + Font.FontHeight))
    {
        return 0;	// Not enough space on current line
    }

    for (i = 0; i < Font.FontHeight; i++){	// Translate font to screenbuffer
        b = Font.data[(ch - 32) * Font.FontHeight + i];
        for (j = 0; j < Font.FontWidth; j++){
            if ((b << j) & 0x8000)
                OLED_DrawPixel(displayData.currentX + j, (displayData.currentY + i), (Display_COLOR) color);
            else
                OLED_DrawPixel(displayData.currentX + j, (displayData.currentY + i), (Display_COLOR)!color);
        }
    }
    displayData.currentX += Font.FontWidth;	// The current space is now taken

    return ch;	// Return written char for validation
}

 * WRITE STRING INTO THE DISPLAY BUFFER
 */
/*
char OLED_WriteString(const char* str, FontDef Font, Display_COLOR color){
    while (*str){
        if (OLED_WriteChar(*str, Font, color) != *str)	// Write until null-byte
        	return *str;	// Char could not be written

        str++;	// Next char
    }
    return *str;	// Everything ok
}

 * SET CURSOR POSITION
 */
/*
void OLED_SetCursor(uint8_t x, uint8_t y){
    displayData.currentX = x;
    displayData.currentY = y;
}

 * DRAW BITMAP
 */
/*
void OLED_DrawBitmap(uint8_t W, uint8_t H, const uint8_t* pBMP){
	uint16_t byteWidth = (W + 7) / 8; // Calculate the width in bytes
	for (uint16_t y = 0; y < H; y++){
		for (uint16_t x = 0; x < W; x++){
			if (pBMP[y * byteWidth + x / 8] & (128 >> (x & 7)))
				OLED_DrawPixel(x, y, White);
		}
	}
}
*/
