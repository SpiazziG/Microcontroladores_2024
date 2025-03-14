/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usb_device.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usbd_cdc_if.h"
#include <string.h>
#include "ESP01.h"
#include "UNERBUS.h"
#include "stm32f1xx_hal_flash.h"
#include "stm32f1xx_hal_flash_ex.h"
#include "MPU6050.h"
#include "OLED.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef union{
	struct{
		uint8_t	ON1MS:			1;
		uint8_t	UPDATESCREEN:	1;
		uint8_t	UPDATEPOSITION:	1;
		uint8_t	NEWMPUDATA:		1;
		uint8_t	b4:	1;
		uint8_t	b5:	1;
		uint8_t	b6:	1;
		uint8_t	b7:	1;
	} bit;
	uint8_t byte;
} _uFlag;

typedef union{
	uint8_t		u8[4];
	int8_t		i8[4];
	uint16_t	u16[2];
	int16_t		i16[2];
	uint32_t	u32;
	int32_t		i32;
} _uWork;

typedef enum{
	ACKNOWLEDGE = 0x0D,
    ALIVE = 0xF0,
    BUTTONS = 0x12,
    FIRMWARE = 0xF1,
    IRSENSORS = 0xA0,
    TEST_ENGINE = 0xA1,
	ACCELERATION = 0xA2,
    SPEED = 0xA4,
	UNKNOWNCMD = 0xFF,
} _eCommand;

typedef enum{
	INTERP_IDLE,
	INTERP_FIND_INTERVAL,
	INTERP_INTERPOLATE,
} _eInterpolationState;

typedef enum{
	INITIALIZING,
	MODE_AND_CONNECTION,
	MPU_AND_ENGINES,
	IR_SENSORS,
} _eDisplayPage;

typedef struct{
	uint8_t t1ms;
	uint8_t t10ms;
	uint8_t t100ms;
	uint8_t t500ms;
	uint8_t t1s;
	uint8_t tOutAliveUDP;
} _sTime;

/*
 * HAL_FLASH_Unlock();
 * CONFIGURAR ESTRUCTURA ERASE
 * EJECUTAR HAL_FLASHEx_Erase
 * Pasar toda la información a la Flash con HAL_FLASH_Program
 * HAL_FLASH_Lock();
 */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define SIZEBUFADC				64
#define SIZEBUFRXPC				128
#define SIZEBUFTXPC				256
#define SIZEBUFRXESP01			128
#define SIZEBUFTXESP01			128

#define	HEARTBEAT_IDLE			0xF4000000
#define	HEARTBEAT_WIFI_READY	0xF5000000
#define	HEARTBEAT_UDP_READY		0xF5400000

#define WIFI_SSID				"InternetPlus_86aa10"//"FCAL"
#define WIFI_PASSWORD			"wlan7955ef"//"fcalconcordia.06-2019"
#define WIFI_UDP_REMOTE_IP		"192.168.1.4"//"192.168.1.18"		//La IP de la PC 172.23.229.43
#define WIFI_UDP_REMOTE_PORT	30010				//El puerto UDP en la PC
#define WIFI_UDP_LOCAL_PORT		30000

#define on1MS					flag1.bit.ON1MS
#define UPDATESCREEN			flag1.bit.UPDATESCREEN
#define UPDATEPOSITION			flag1.bit.UPDATEPOSITION
#define NEWMPUDATA				flag1.bit.NEWMPUDATA

#define t1MS					timeCounter.t1ms
#define t10MS					timeCounter.t10ms
#define t100MS					timeCounter.t100ms
#define t500MS					timeCounter.t500ms
#define t1S						timeCounter.t1s
#define tOutAliveUDP 			timeCounter.tOutAliveUDP

#define REFERENCE_SAMPLES_SIZE	19
#define FILTER_SIZE				16
#define TOTAL_ADC_CHANNELS		8
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;

I2C_HandleTypeDef hi2c2;
DMA_HandleTypeDef hdma_i2c2_rx;
DMA_HandleTypeDef hdma_i2c2_tx;

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim4;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
////////////////////////////// TYPEDEF VARIABLES ///////////////////////////////
_uFlag flag1;
_uWork w;
_eCommand cmds;
_sTime timeCounter;

_sMPUData myMpuValues;

/////////////////////////// COMMUNICATION VARIABLES ////////////////////////////
_sESP01Handle esp01;
_sUNERBUSHandle unerbusPC;
_sUNERBUSHandle unerbusESP01;

char localIP[16];

uint8_t bufRXPC[SIZEBUFRXPC], bufTXPC[SIZEBUFTXPC];
uint8_t bufRXESP01[SIZEBUFRXESP01], bufTXESP01[SIZEBUFTXESP01], dataRXESP01;

uint8_t rxUSBData, newData;

/////////////////////////// INFRARRED ADC VARIABLES ////////////////////////////
const uint16_t adcReferences[REFERENCE_SAMPLES_SIZE] = {3943, 3929, 3839, 2820, 2047, 1547, 1136, 1026, 758, 683, 554, 542, 476, 403, 363, 325, 260, 230, 205};
const uint8_t distanceReferences[REFERENCE_SAMPLES_SIZE] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 100}; // en mm

uint16_t bufADC[SIZEBUFADC][TOTAL_ADC_CHANNELS];
uint8_t iwBufADC, irBufADC;
uint8_t aux8, auxSample;

uint16_t movingAverageADC[TOTAL_ADC_CHANNELS];

uint8_t bufInterpolated[8];
uint8_t sensorToInterpolate;
volatile _eInterpolationState interpState = INTERP_IDLE;
volatile uint16_t valueToInterpolate;
volatile uint16_t distanceInterpolated;
volatile uint8_t referenceIndex;
////////////////////////////// HEARTBEAT VARIABLES /////////////////////////////
uint16_t mask, moveMask;

//////////////////////////////// OTHER VARIABLES ///////////////////////////////
uint16_t currentI2CDeviceAddress;
char strAux[20];

const uint32_t varEeprom __attribute__ ((__section__ (".configeeprom")));
//__attribute__ ((__section__ (".configeeprom"), used)) uint32_t varEeprom;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_ADC1_Init(void);
static void MX_I2C2_Init(void);
static void MX_TIM1_Init(void);
static void MX_TIM4_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */
////////////////////// COMMUNICATION FUNCTIONS PROTOTYPES //////////////////////
void ESP01DoCHPD(uint8_t value);
int ESP01WriteUSARTByte(uint8_t value);
void ESP01WriteByteToBufRX(uint8_t value);
void ESP01ChangeState(_eESP01STATUS esp01State);

void DecodeCMD(struct UNERBUSHandle *aBus, uint8_t iStartData);

void USBReceive(uint8_t *buf, uint16_t len);

///////////////////////// PROGRAM FUNCTIONS PROTOTYPES /////////////////////////
void Do1ms();
void Do10ms();
void Do100ms();
void Do1s();

void ChangeDisplayPage(_eDisplayPage page);

void Heartbeat();

void Interpolate();
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
////////////////////////////// CALLBACKS FUNCTIONS //////////////////////////////
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance == TIM1){
		t1MS--;
		if(!t1MS){
			on1MS = 1;
			t1MS = 4;
		}

		HAL_ADC_Start_DMA(&hadc1, (uint32_t *)&bufADC[iwBufADC], 8);
	}
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc){
	for(uint8_t i= 0; i < TOTAL_ADC_CHANNELS; i++){
		uint32_t sum = 0;
		for (uint8_t j = 0; j < FILTER_SIZE; j++) {
			auxSample = (aux8 - j);
			auxSample &= (SIZEBUFADC -1 );
			sum += bufADC[auxSample][i];
		}
		movingAverageADC[i] = sum / FILTER_SIZE;
	}

	iwBufADC++;
	iwBufADC &= (SIZEBUFADC-1);

	aux8 = iwBufADC - 1;
	aux8 &= (SIZEBUFADC - 1);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if(huart->Instance == USART1){
		ESP01_WriteRX(dataRXESP01);
		HAL_UART_Receive_IT(&huart1, &dataRXESP01, 1);
	}
}

//////////////////////////// COMMUNICATION FUNCTIONS ////////////////////////////
void ESP01DoCHPD(uint8_t value){
	HAL_GPIO_WritePin(CH_EN_GPIO_Port, CH_EN_Pin, value);
}

int ESP01WriteUSARTByte(uint8_t value){
	if(__HAL_UART_GET_FLAG(&huart1, USART_SR_TXE)){
		USART1->DR = value;
		return 1;
	}
	return 0;
}

void ESP01WriteByteToBufRX(uint8_t value){
	UNERBUS_ReceiveByte(&unerbusESP01, value);
}

void ESP01ChangeState(_eESP01STATUS esp01State){
	/*
	switch((uint32_t)esp01State){
	case ESP01_WIFI_CONNECTED:
		heartbeat = HEARTBEAT_WIFI_READY;
		break;
	case ESP01_UDPTCP_CONNECTED:
		heartbeat = HEARTBEAT_UDP_READY;
		break;
	case ESP01_UDPTCP_DISCONNECTED:
		heartbeat = HEARTBEAT_WIFI_READY;
		break;
	case ESP01_WIFI_DISCONNECTED:
		heartbeat = HEARTBEAT_IDLE;
		break;
	}
	*/
}

void DecodeCMD(struct UNERBUSHandle *aBus, uint8_t iStartData){
	uint8_t id;
	uint8_t length = 0;

	id = UNERBUS_GetUInt8(aBus);
	switch(id){
	case 0xE0://GET LOCAL IP
		UNERBUS_Write(aBus, (uint8_t *)ESP01_GetLocalIP(), 16);
		length = 17;
		break;
	case ALIVE://ALIVE
		UNERBUS_WriteByte(aBus, 0x0D);
		length = 2;
		break;
	case IRSENSORS:
		aux8 = iwBufADC - 1;
		aux8 &= (SIZEBUFADC - 1);
		UNERBUS_Write(aBus, (uint8_t*)&bufADC[aux8], 16);
		length = 17;
		break;
	case ACCELERATION:
		uint8_t buf[12];
		MPU6050_Compose_Number(myMpuValues, buf);
		UNERBUS_Write(aBus, buf, 12);
		length = 13;
		break;
	}

	if(length){
		UNERBUS_Send(aBus, id, length);
	}
}

void USBReceive(uint8_t *buf, uint16_t len){
	UNERBUS_ReceiveBuf(&unerbusPC, buf, len);
}

/////////////////////////////// PROGRAM FUNCTIONS ///////////////////////////////
void Do1ms(){
	on1MS = 0;

	if(t10MS)
		t10MS--;
}

void Do10ms(){
	MPU6050_Read_Data_DMA(&hi2c2);

	t10MS = 10;

	if(t100MS)
		t100MS--;

	ESP01_Timeout10ms();
	UNERBUS_Timeout(&unerbusESP01);
	UNERBUS_Timeout(&unerbusPC);
}

void Do100ms(){
	UPDATEPOSITION = 1;

	t100MS = 10;

	if(t1S)
		t1S--;

	Heartbeat();


	//UNERBUS_Write(&unerbusPC, (uint8_t*)&bufADC[aux8], 16);
	//UNERBUS_Send(&unerbusPC, 0xA0, 17);

	UNERBUS_Write(&unerbusESP01, bufInterpolated, 8);
	UNERBUS_Send(&unerbusESP01, 0xA0, 9);

	UNERBUS_Write(&unerbusPC, bufInterpolated, 8);
	UNERBUS_Send(&unerbusPC, 0xA0, 9);

	//UNERBUS_Write(&unerbusESP01, (uint8_t*)&bufADC[aux8], 16);
	//UNERBUS_Send(&unerbusESP01, 0xA0, 17);

	/*
	if(heartbeatmask & heartbeat)
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
	else
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);

	heartbeatmask >>= 1;
	if(!heartbeatmask)
		heartbeatmask = 0x80000000;
	*/
	if(tOutAliveUDP)
		tOutAliveUDP--;
}

void Do1s(){
	static uint8_t power = 0;

	t1S = 10;

	w.i16[0] = myMpuValues.accelX;
	//w.i16[0] /= 131;// 16384;
	OLED_SetCursor(19, 16);
	sprintf(strAux, "%hd   ", w.i16[0]);
	OLED_WriteString(strAux, Font_7x10, White);

	w.i16[0] = myMpuValues.accelY;
	//w.i16[0] /= 131;//w.i32 /= 16384;
	OLED_SetCursor(19, 27);
	sprintf(strAux, "%hd   ", w.i16[0]);
	OLED_WriteString(strAux, Font_7x10, White);

	w.i16[0] = myMpuValues.accelZ;
	//w.i16[0] /= 16384;
	OLED_SetCursor(19, 38);
	sprintf(strAux, "%hd   ", w.i16[0]);
	OLED_WriteString(strAux, Font_7x10, White);

	//sprintf(strAux, "%hd", aux++);
	//OLED_SetCursor(3, 3);
	//OLED_WriteString(strAux, Font_7x10, White);

	OLED_SetCursor(82, 21);
	sprintf(strAux, "L:%3hd%c", power, '%');
	OLED_WriteString(strAux, Font_7x10, White);

	OLED_SetCursor(82, 33);
	sprintf(strAux, "R:%3hd%c", power, '%');
	OLED_WriteString(strAux, Font_7x10, White);

	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, power*100);
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, 0);


	OLED_SetCursor(3, 52);
	sprintf(strAux, "%hd    ", movingAverageADC[0]);
	OLED_WriteString(strAux, Font_7x10, White);

	UPDATESCREEN = 1;

	if(power < 99){
		power++;
	} else {
		power = 0;
	}
}

void ChangeDisplayPage(_eDisplayPage page){
	switch(page){
		case INITIALIZING:
			  OLED_DrawRect(1, 1, 126, 62, White);
			  OLED_DrawHorizontalLine(2, 13, 125, White);
			  //OLED_DrawHorizontalLine(2, 14, 125, White);
			  OLED_DrawHorizontalLine(2, 49, 125, White);
			  //OLED_DrawHorizontalLine(2, 50, 125, White);

			  OLED_SetCursor(3, 3);
			  sprintf(strAux, "   Spiazzi 2024");
			  OLED_WriteString(strAux, Font_7x10, White);

			  OLED_SetCursor(3, 16);
			  sprintf(strAux, "X:");
			  OLED_WriteString(strAux, Font_7x10, White);

			  OLED_SetCursor(3, 27);
			  sprintf(strAux, "Y:");
			  OLED_WriteString(strAux, Font_7x10, White);

			  OLED_SetCursor(3, 38);
			  sprintf(strAux, "Z:");
			  OLED_WriteString(strAux, Font_7x10, White);

			  /*
			  OLED_SetCursor(3, 52);
			  sprintf(strAux, "MODE: IDLE");
			  OLED_WriteString(strAux, Font_7x10, White);
			  */
			break;
		case MODE_AND_CONNECTION:
			break;
		case MPU_AND_ENGINES:
			break;
		case IR_SENSORS:
			break;
	}
	UPDATESCREEN = 1;
}

void Heartbeat(){
	uint8_t write;
	write = ~(mask>>moveMask) & 1;
	moveMask++;
	moveMask ^= (moveMask & 16);
	HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, write);
}

void Interpolate(){
	switch (interpState) {
		case INTERP_IDLE:
			if(sensorToInterpolate == 0)
				sensorToInterpolate = 7;
			else
				sensorToInterpolate--;

			valueToInterpolate = movingAverageADC[sensorToInterpolate];
			referenceIndex = 0;
			interpState = INTERP_FIND_INTERVAL;
			break;
		case INTERP_FIND_INTERVAL:
			if(valueToInterpolate <= adcReferences[referenceIndex]){
				referenceIndex++;
				if (referenceIndex >= REFERENCE_SAMPLES_SIZE)
					bufInterpolated[sensorToInterpolate] = adcReferences[REFERENCE_SAMPLES_SIZE-1];
					//interpState = INTERP_IDLE;  // Error
			} else {
				if(referenceIndex != 0)
					interpState = INTERP_INTERPOLATE;
				else
					bufInterpolated[sensorToInterpolate] = adcReferences[0];
			}
			break;
		case INTERP_INTERPOLATE:
			uint16_t adc_high	= adcReferences[referenceIndex -1];
			uint16_t adc_low	= adcReferences[referenceIndex];
			uint16_t dist_high	= distanceReferences[referenceIndex -1];
			uint16_t dist_low	= distanceReferences[referenceIndex];

			distanceInterpolated = dist_low + ((valueToInterpolate - adc_low) * (dist_high - dist_low)) / (adc_high - adc_low);
			bufInterpolated[sensorToInterpolate] = distanceInterpolated;
			interpState = INTERP_IDLE;
			break;
	}
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */
	mask = 0xAAF;
	moveMask = 0;
	//heartbeat = HEARTBEAT_IDLE;
	//heartbeatmask = 0x80000000;

	t1MS = 4;
	t10MS = 10;
	t100MS = 10;
	t1S = 10;
	tOutAliveUDP = 50;

	UPDATEPOSITION = 0;
	UPDATESCREEN = 0;

	iwBufADC = 0;
	irBufADC = 0;

	esp01.DoCHPD = ESP01DoCHPD;
	esp01.WriteByteToBufRX = ESP01WriteByteToBufRX;
	esp01.WriteUSARTByte = ESP01WriteUSARTByte;

	unerbusESP01.MyDataReady = DecodeCMD;
	unerbusESP01.WriteUSARTByte = NULL;
	unerbusESP01.rx.buf = bufRXESP01;
	unerbusESP01.rx.maxIndexRingBuf = (SIZEBUFRXESP01 - 1);
	unerbusESP01.tx.buf = bufTXESP01;
	unerbusESP01.tx.maxIndexRingBuf = (SIZEBUFTXESP01 - 1);

	unerbusPC.MyDataReady = DecodeCMD;
	unerbusPC.WriteUSARTByte = NULL;
	unerbusPC.rx.buf = bufRXPC;
	unerbusPC.rx.maxIndexRingBuf = (SIZEBUFRXPC - 1);
	unerbusPC.tx.buf = bufTXPC;
	unerbusPC.tx.maxIndexRingBuf = (SIZEBUFTXPC - 1);
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USB_DEVICE_Init();
  MX_ADC1_Init();
  MX_I2C2_Init();
  MX_TIM1_Init();
  MX_TIM4_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_Delay(1000);

  MPU6050_Init(&hi2c2);
  MPU6050_Calibrate(&hi2c2);

  CDC_AttachRxData(USBReceive);

  HAL_TIM_Base_Start_IT(&htim1);


  HAL_TIM_Base_Start(&htim4);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4);
  __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 0);
  __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, 0);
  __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 0);
  __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 0);

  ESP01_Init(&esp01);
  UNERBUS_Init(&unerbusESP01);
  UNERBUS_Init(&unerbusPC);

  ESP01_AttachChangeState(ESP01ChangeState);
  ESP01_SetWIFI(WIFI_SSID, WIFI_PASSWORD);
  ESP01_StartUDP(WIFI_UDP_REMOTE_IP, WIFI_UDP_REMOTE_PORT, WIFI_UDP_LOCAL_PORT);

  HAL_UART_Receive_IT(&huart1, &dataRXESP01, 1);

  OLED_Init(&hi2c2);
  ChangeDisplayPage(INITIALIZING);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  if(!tOutAliveUDP){
		  tOutAliveUDP = 50;
		  UNERBUS_WriteByte(&unerbusESP01, 0x0D);
		  UNERBUS_Send(&unerbusESP01, 0xF0, 2);

		  //UNERBUS_WriteConstString(&unerbusPC, "UNER\x03:\xF0\x0D\xC8", 0);
		  //UNERBUS_WriteConstString(&unerbusPC, " El ALIVE", 1);
	  }

	  if(on1MS)
		  Do1ms();

	  if(!t10MS)
		  Do10ms();

	  if(!t100MS)
		  Do100ms();

	  if(!t1S)
		  Do1s();

	  if(unerbusESP01.tx.iRead != unerbusESP01.tx.iWrite){
		  w.u8[0] = unerbusESP01.tx.iWrite - unerbusESP01.tx.iRead;
		  w.u8[0] &= unerbusESP01.tx.maxIndexRingBuf;
		  if(ESP01_Send(unerbusESP01.tx.buf, unerbusESP01.tx.iRead, w.u8[0], unerbusESP01.tx.maxIndexRingBuf+1) == ESP01_SEND_READY)
			  unerbusESP01.tx.iRead = unerbusESP01.tx.iWrite;
	  }

	  if(unerbusPC.tx.iRead != unerbusPC.tx.iWrite){
		  if(unerbusPC.tx.iRead < unerbusPC.tx.iWrite)
			  w.u8[0] = unerbusPC.tx.iWrite - unerbusPC.tx.iRead;
		  else
			  w.u8[0] = unerbusPC.tx.maxIndexRingBuf+1 - unerbusPC.tx.iRead;

		  if(CDC_Transmit_FS(&unerbusPC.tx.buf[unerbusPC.tx.iRead], w.u8[0]) == USBD_OK){
			  unerbusPC.tx.iRead += w.u8[0];
			  unerbusPC.tx.iRead &= unerbusPC.tx.maxIndexRingBuf;
		  }
	  }

	  if ((HAL_I2C_GetState(&hi2c2) == HAL_I2C_STATE_READY) && UPDATESCREEN) {
		  currentI2CDeviceAddress = OLED_I2C_ADDR;
		  UPDATESCREEN = OLED_UpdateScreen(&hi2c2);
	  }

	  if ((HAL_I2C_GetState(&hi2c2) == HAL_I2C_STATE_READY) && UPDATEPOSITION) {
		  //currentI2CDeviceAddress = I2C_MPU6050_ADDR;
		  //MPU6050_Read_All(&hi2c2, &MPU6050[iwMPU]);
		  UPDATEPOSITION = 0;
	  }

	  Interpolate();

	  ESP01_Task();

	  UNERBUS_Task(&unerbusESP01);

	  UNERBUS_Task(&unerbusPC);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC|RCC_PERIPHCLK_USB;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLL_DIV1_5;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ScanConvMode = ADC_SCAN_ENABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 8;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = ADC_REGULAR_RANK_2;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_2;
  sConfig.Rank = ADC_REGULAR_RANK_3;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_3;
  sConfig.Rank = ADC_REGULAR_RANK_4;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_4;
  sConfig.Rank = ADC_REGULAR_RANK_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_5;
  sConfig.Rank = ADC_REGULAR_RANK_6;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_6;
  sConfig.Rank = ADC_REGULAR_RANK_7;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_7;
  sConfig.Rank = ADC_REGULAR_RANK_8;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief I2C2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C2_Init(void)
{

  /* USER CODE BEGIN I2C2_Init 0 */

  /* USER CODE END I2C2_Init 0 */

  /* USER CODE BEGIN I2C2_Init 1 */

  /* USER CODE END I2C2_Init 1 */
  hi2c2.Instance = I2C2;
  hi2c2.Init.ClockSpeed = 100000;
  hi2c2.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C2_Init 2 */

  /* USER CODE END I2C2_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 71;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 249;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

}

/**
  * @brief TIM4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM4_Init(void)
{

  /* USER CODE BEGIN TIM4_Init 0 */

  /* USER CODE END TIM4_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM4_Init 1 */

  /* USER CODE END TIM4_Init 1 */
  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 71;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 10000;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim4, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM4_Init 2 */

  /* USER CODE END TIM4_Init 2 */
  HAL_TIM_MspPostInit(&htim4);

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);
  /* DMA1_Channel4_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel4_IRQn);
  /* DMA1_Channel5_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel5_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(CH_EN_GPIO_Port, CH_EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : LED_Pin */
  GPIO_InitStruct.Pin = LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : SW0_Pin */
  GPIO_InitStruct.Pin = SW0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(SW0_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : CH_EN_Pin */
  GPIO_InitStruct.Pin = CH_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(CH_EN_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
	  mask = 0x5555;
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
