/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @author			: Gerónimo Spiazzi
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
#include <string.h>
#include "usbd_cdc_if.h"
#include "stm32f1xx_hal_flash.h"
#include "stm32f1xx_hal_flash_ex.h"
#include "ESP01.h"
#include "UNERBUS.h"
#include "BUTTON.h"
#include "INFRARED.h"
#include "MPU6050.h"
#include "OLED.h"
#include "PID.h"
#include "ENGINE.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef union {
	struct {
		uint8_t	b0:	1;
		uint8_t	b1:	1;
		uint8_t	b2:	1;
		uint8_t	b3:	1;
		uint8_t	b4:	1;
		uint8_t	b5:	1;
		uint8_t	b6:	1;
		uint8_t	b7:	1;
	} bit;
	uint8_t byte;
} _uFlag;

typedef union {
	uint8_t		u8[4];
	int8_t		i8[4];
	uint16_t	u16[2];
	int16_t		i16[2];
	uint32_t	u32;
	int32_t		i32;
} _uWork;

typedef enum {
	// Communication commands
	ACKNOWLEDGE = 0x0D,
	GET_LOCAL_IP = 0xE0,
    ALIVE = 0xF0,
    GET_FIRMWARE_INFO = 0xF1,
	UNKNOWNCMD = 0xFF,

	// 0xA_ : Sensors & Actuators (Read data)
    GET_IR_SENSORS = 0xA0,
	GET_MPU_DATA = 0xA2, //ACCELERATION
	GET_BUTTON_STATE = 0xA4, //BUTTONS
	GET_MOTOR_SPEED = 0xA6,

	// 0xB_ : Sensors (Configuration and calibration)
	SET_IR_CALIBRATION = 0xB0, //CALIBRATION

	// 0xC_ : Actuators and software configuration
	SET_MOTOR_TEST = 0xC0, //TEST_ENGINE
	SET_PWM_CONFIG = 0xC2,

	// 0xD_ : PID Configuration
	// Turn PID
	SET_PID_TURN_GAINS = 0xD0, //SET_PID
	GET_PID_TURN_GAINS = 0xD1,

	// Wall PID
	SET_PID_WALL_GAINS = 0xD2,
	GET_PID_WALL_GAINS = 0xD3,

	// Movement parameters
	SET_TURN_SPEED = 0xD8,
	SET_WALL_SPEED = 0xDA,

	// Maze status
	GET_CURRENT_ACTION		= 0xEA,
	GET_INTERSECTION_TYPE	= 0xEE,
} Command_e;

typedef enum {
	DISPLAY_CLEAR,
	DISPLAY_INITIALIZING,
	DISPLAY_MODE_AND_CONNECTION,
	DISPLAY_MPU_AND_ENGINES,
	DISPLAY_IR_SENSORS,
} DisplayPage_e;

typedef enum {
	MODE_IDLE,
	MODE_FINDING_MARKS,
	MODE_EXPLORING_MAZE,
	MODE_MAZE_RUNNER,
} Robot_Mode_e;

typedef enum {
	ACTION_IDLE,
	ACTION_FOLLOW_WALL,
	ACTION_CENTER_IN_CELL,
	ACTION_PREPARE_TURN,
	ACTION_TURN_PIVOT,
	ACTION_TURN_SMOOTH,
	ACTION_HANDLE_FRONT_WALL,
} Robot_Action_e;

typedef enum {
	INTERSECTION_UNKNOWN,
	INTERSECTION_LEFT_SQUARE,
	INTERSECTION_LEFT_FRONT_OPEN,
	INTERSECTION_RIGHT_SQUARE,
	INTERSECTION_RIGHT_FRONT_OPEN,
	INTERSECTION_T_ROAD,
	INTERSECTION_CROSSROAD,
	INTERSECTION_DEAD_END,
} IntersectionType_e;

typedef struct {
	uint8_t t1ms;
	uint8_t t10ms;
	uint8_t t20ms;
	uint8_t t100ms;
	uint8_t t500ms;
	uint8_t t1s;
	uint8_t tOutAliveUDP;
} Time_s;

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
// Communication buffers size macros
#define SIZEBUFRXPC				128
#define SIZEBUFTXPC				256
#define SIZEBUFRXESP01			128
#define SIZEBUFTXESP01			128

// Heart beat macros
#define	HEARTBEAT_IDLE			0xF4000000
#define	HEARTBEAT_WIFI_READY	0xF5000000
#define	HEARTBEAT_UDP_READY		0xF5400000

// Wi-Fi configuration macros
#define WIFI_SSID				"InternetPlus_86aa10"//"FCAL" "InternetPlus_86aa10" "LabPrototip" "InternetPlus_8e2fbb"
#define WIFI_PASSWORD			"wlan7955ef"//"fcalconcordia.06-2019" "wlan7955ef" "labproto" "Akhantos2340"
#define WIFI_UDP_REMOTE_IP		"192.168.1.31"//"192.168.1.18"	//La IP de la PC 172.23.229.43 "192.168.1.31"
#define WIFI_UDP_REMOTE_PORT	30010				//El puerto UDP en la PC
#define WIFI_UDP_LOCAL_PORT		30000

// Flags macros
#define on1MS					flag1.bit.b0
#define MPU_READ_REQUEST		flag1.bit.b1
#define OLED_UPDATE_REQUEST		flag1.bit.b2
#define I2C_BUS_IS_BUSY			flag1.bit.b3

// Timer counter macros
#define t1MS					timeCounter.t1ms
#define t10MS					timeCounter.t10ms
#define t20MS					timeCounter.t20ms
#define t100MS					timeCounter.t100ms
#define t500MS					timeCounter.t500ms
#define t1S						timeCounter.t1s
#define tOutAliveUDP 			timeCounter.tOutAliveUDP

// Turn control macros

#define SMOOTH_TURN_OUTER_SPEED		-65
#define SMOOTH_TURN_INNER_SPEED		-35
#define TURN_THRESHOLD				2*YAW_SCALE
#define TARGET_ANGULAR_VELOCITY     250

// Wall follow control macros
#define WALL_FRONT_THRESHOLD		800
#define OPEN_CORNER_THRESHOLD		300
#define ONE_WALL_TARGET_DISTANCE 	1000
#define OBJECT_DETECTION_THRESHOLD	210
#define LINE_DETECTION_THRESHOLD	1800

#define WALL_FADE_TICKS				3
#define PREPARE_TURN_TICKS			100
#define SMOOTH_TURN_BASE_SPEED		-50
#define SMOOTH_TURN_EXIT_THRESHOLD	(TURN_THRESHOLD * 2)
#define TURN_MIN_PWM				50

// WALL STATES
#define WALL_STATE_NONE				0
#define WALL_STATE_RIGHT			1
#define WALL_STATE_LEFT				2
#define WALL_STATE_BOTH				3

// IR MACROS
#define FILTERED_RIGHT_IR			myInfraredValues.filteredSamples[0]
#define FILTERED_DIAG_RIGHT_IR		myInfraredValues.filteredSamples[1]
#define FILTERED_FRONT_RIGHT_IR		myInfraredValues.filteredSamples[2]
#define FILTERED_FRONT_UNDER_IR		myInfraredValues.filteredSamples[3]
#define FILTERED_FRONT_LEFT_IR		myInfraredValues.filteredSamples[4]
#define FILTERED_DIAG_LEFT_IR		myInfraredValues.filteredSamples[5]
#define FILTERED_LEFT_IR			myInfraredValues.filteredSamples[6]
#define FILTERED_REAR_UNDER_IR		myInfraredValues.filteredSamples[7]

#define PERCEPTION_RIGHT			flagsIR.bit.b0
#define PERCEPTION_DIAG_RIGHT		flagsIR.bit.b1
#define	PERCEPTION_FRONT_RIGHT		flagsIR.bit.b2
#define PERCEPTION_FRONT_LEFT		flagsIR.bit.b4
#define PERCEPTION_DIAG_LEFT		flagsIR.bit.b5
#define PERCEPTION_LEFT				flagsIR.bit.b6
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
volatile _uFlag flag1;
_uWork w;
Command_e cmds;
Time_s timeCounter;

static _uFlag flagsIR;
static InfraredHandle_s myInfraredValues;
static MPU_Handle_s myMpuValues;
static OLED_Handle_s myOled;
static PIDHandle_s myTurnValues, myWallValues, mySmoothTurnValues;
static ENGINE_Handle_s myEngines;
static BUTTON_Handle_s myButton1;
/////////////////////////// COMMUNICATION VARIABLES ////////////////////////////
_sESP01Handle esp01;
_sUNERBUSHandle unerbusPC;
_sUNERBUSHandle unerbusESP01;

char localIP[16];

uint8_t bufRXPC[SIZEBUFRXPC], bufTXPC[SIZEBUFTXPC];
uint8_t bufRXESP01[SIZEBUFRXESP01], bufTXESP01[SIZEBUFTXESP01], dataRXESP01;

uint8_t rxUSBData, newData;
////////////////////////////// HEARTBEAT VARIABLES /////////////////////////////
uint16_t mask, moveMask;

//////////////////////////////// OTHER VARIABLES ///////////////////////////////
// Robot maneuver variables
Robot_Mode_e currentMode;
Robot_Action_e currentAction;

IntersectionType_e detectedIntersection;
const IntersectionType_e intersectionLUT[8] = {
	// Index -> [Left | Front | Right]
	// 0b000 -> [ No | No | No ]
	INTERSECTION_CROSSROAD,
	// 0b001 -> [ No | No | Yes ]
	INTERSECTION_LEFT_FRONT_OPEN,
	// 0b010 -> [ No | Yes | No ]
	INTERSECTION_T_ROAD,
	// 0b011 -> [ No | Yes | Yes ]
	INTERSECTION_LEFT_SQUARE,
	// 0b100 -> [ Yes | No | No ]
	INTERSECTION_RIGHT_FRONT_OPEN,
	// 0b101 -> [ Yes | No | Yes ] -> Hall
	INTERSECTION_UNKNOWN,
	// 0b110 -> [ Yes | Yes | No ]
	INTERSECTION_RIGHT_SQUARE,
	// 0b111 -> [ Yes | Yes | Yes ] -> Could be a dead end, or a premature detection of a turn
	INTERSECTION_UNKNOWN
};

uint8_t turnInnerSpeed, turnOuterSpeed;

uint8_t prevWallState;
uint8_t intersectionType;
uint8_t wallFadeCounter;
uint8_t ticksOpenSpace;
int16_t pivotDegreesTarget;

int32_t targetYaw;

int8_t test_turn_sequence = 0; // 0=idle, 1=girar +90, 2=girar -90, 3=girar 180

char strAux[20];

const uint8_t varEeprom[] __attribute__ ((__section__ (".configeeprom"))) =
		{0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x07, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x07, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,
		0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x0f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff,
		0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff,
		0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff,
		0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff,
		0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff,
		0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff,
		0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x01, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff,
		0xff, 0xff, 0x80, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xc0, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0x80, 0x03, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0x00, 0x1f, 0xfc, 0x00, 0x00, 0x07, 0xc0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0x00, 0x1f, 0xf8, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff,
		0xff, 0xfe, 0x00, 0x3f, 0xf0, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff,
		0xff, 0xfe, 0x00, 0x3f, 0xe0, 0x00, 0x00, 0x07, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff,
		0xff, 0xfe, 0x00, 0x3f, 0xc0, 0x00, 0x00, 0x07, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,
		0xff, 0xfe, 0x00, 0x3f, 0x80, 0x00, 0x00, 0x07, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,
		0xff, 0xff, 0x00, 0x3f, 0x00, 0x00, 0x00, 0x07, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff,
		0xff, 0xff, 0x00, 0x3f, 0x00, 0x00, 0x00, 0x07, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff,
		0xff, 0xff, 0x00, 0x1f, 0xff, 0xff, 0xc0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x3f, 0xff,
		0xff, 0xff, 0x00, 0x0f, 0xff, 0xff, 0xc0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x3f, 0xff,
		0xff, 0xff, 0x80, 0x07, 0xff, 0xff, 0xc0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x3f, 0xff,
		0xff, 0xff, 0x80, 0x03, 0xff, 0xff, 0xc0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x3f, 0xff,
		0xff, 0xff, 0xc0, 0x00, 0xff, 0xff, 0xc0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x3f, 0xff,
		0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff,
		0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x07, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff,
		0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x07, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff,
		0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,
		0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,
		0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x07, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
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

void USBReceive(uint8_t *buf, uint16_t len);
void ESP01DoCHPD(uint8_t value);
int ESP01WriteUSARTByte(uint8_t value);
void ESP01WriteByteToBufRX(uint8_t value);
void ESP01ChangeState(_eESP01STATUS esp01State);

void DecodeCMD(struct UNERBUSHandle *aBus, uint8_t iStartData);

const char* GetFirmwareVersion_String(void);

void I2C_State_Control(void);
void MPU_Read_Completed_Callback(void *context);
void OLED_Write_Completed_Callback(void *context);
///////////////////////// TIMING FUNCTIONS PROTOTYPES //////////////////////////

void Do1ms();
void Do10ms();
void Do20ms();
void Do100ms();
void Do1s();

///////////////////////// PROGRAM FUNCTIONS PROTOTYPES /////////////////////////
void Robot_StateMachine(void);
void Robot_ExploreMaze(void);
void Robot_FollowWall_Control(void);
void Robot_SmoothTurn(void);
void Robot_PrepareTurn(void);
void Robot_Turn_Control(int16_t degreesToTurn);

IntersectionType_e Robot_IdentifyIntersection(void);

void ChangeDisplayPage(DisplayPage_e page);

void Heartbeat();

void SetMotorSpeed(uint8_t leftPower, uint8_t rightPower);

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

		HAL_ADC_Start_DMA(&hadc1, (uint32_t *)&myInfraredValues.rawSamples, ADC_CHANNELS);
	}
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc){
	Infrared_Filter(&myInfraredValues);
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

const char* GetFirmwareVersion_String(void){
    static char firmwareVersionStr[32];

    // Macro __DATE__ returns "mm dd yyyy" (example: "May 31 2024")
    // Macro __TIME__ returns "hh:mm:ss" (example. "15:45:00")
    sprintf(firmwareVersionStr, "%s - %s", __DATE__, __TIME__);

    return firmwareVersionStr;
}

void MPU_Read_Completed_Callback(void *context) {
	// MPU Reading completed
    // 'context' is &myMpuValues.
    MPU_Handle_s *mpuHandle = (MPU_Handle_s *)context;

    // 1. Process the new data
    MPU6050_ProcessRawData(mpuHandle);

    // 2. Freed I2C bus
    I2C_BUS_IS_BUSY = 0;
}

//================================================================================
// CALLBACK when I2C Writing via DMA ends (Tx)
//================================================================================
void OLED_Write_Completed_Callback(void *context) {
    myOled.updatePageState++;
    if (myOled.updatePageState > 3) {
        myOled.updatePageState = 0;   // Reset for the next page
        myOled.currentPageToUpdate++; // Go to next page
    }

    I2C_BUS_IS_BUSY = 0;
}

void I2C_State_Control(void){
	if (I2C_BUS_IS_BUSY)
		return;

	if (MPU_READ_REQUEST) {
		MPU_READ_REQUEST = 0;
		I2C_BUS_IS_BUSY = 1;
		MPU6050_Read_Data(&myMpuValues);
		return;
	} else if (myOled.currentPageToUpdate < 8) {
		I2C_BUS_IS_BUSY = 1;
		OLED_UpdateSingleStep_DMA(&myOled);
	}
}


void DecodeCMD(struct UNERBUSHandle *aBus, uint8_t iStartData){
	uint8_t id;
	uint8_t length = 0;

	uint8_t buf[24];
	id = UNERBUS_GetUInt8(aBus);
	switch(id){
	case GET_LOCAL_IP:
		UNERBUS_Write(aBus, (uint8_t *)ESP01_GetLocalIP(), 16);
		length = 17;
		break;
	case ALIVE: //ALIVE
		UNERBUS_WriteByte(aBus, ACKNOWLEDGE);
		length = 2;
		break;
	case GET_FIRMWARE_INFO:
		const char* versionStr = GetFirmwareVersion_String();
		UNERBUS_Write(aBus, (uint8_t*)versionStr, strlen(versionStr));
		length = strlen(versionStr) + 1;
		break;
	case GET_IR_SENSORS:
		for(uint8_t i = 0; i < ADC_CHANNELS; i++) {
			UNERBUS_WriteByte(aBus, myInfraredValues.filteredSamples[i] & 0xFF);
			UNERBUS_WriteByte(aBus, (myInfraredValues.filteredSamples[i] >> 8) & 0xFF);
		}
		length = (ADC_CHANNELS * 2) + 1;
		//UNERBUS_Write(aBus, myInfraredValues.millimeterSamples, ADC_CHANNELS);
		//length = ADC_CHANNELS + 1;
		break;
	case SET_IR_CALIBRATION:
		for(uint8_t i = 0; i < 20; i++)
			myInfraredValues.lookUp[i] = UNERBUS_GetInt16(aBus);
		break;
	case GET_MPU_DATA:
		MPU6050_Compose_Number(&myMpuValues, buf);
		UNERBUS_Write(aBus, buf, MPU_DATA_BUFFER_SIZE);
		length = MPU_DATA_BUFFER_SIZE + 1;
		break;
	case SET_MOTOR_TEST:
		ENGINE_SetLeftSpeed(&myEngines, UNERBUS_GetUInt8(aBus));
		ENGINE_SetRightSpeed(&myEngines, UNERBUS_GetUInt8(aBus));
		break;
	case SET_PWM_CONFIG:
		myEngines.pwmMaxPeriod = UNERBUS_GetUInt8(aBus);
		__HAL_TIM_SET_PRESCALER(&htim4, myEngines.pwmMaxPeriod);
		__HAL_TIM_SET_AUTORELOAD(&htim4, UNERBUS_GetUInt8(aBus));
		break;
	case SET_PID_TURN_GAINS:
		myTurnValues.Kp = UNERBUS_GetUInt16(aBus);
		myTurnValues.Ki = UNERBUS_GetUInt16(aBus);
		myTurnValues.Kd = UNERBUS_GetUInt16(aBus);
		myTurnValues.outputMin = UNERBUS_GetInt8(aBus);
		myTurnValues.outputMax = UNERBUS_GetInt8(aBus);
		myTurnValues.base = UNERBUS_GetInt8(aBus);
		break;
	case GET_PID_TURN_GAINS:
		buf[0] = myTurnValues.Kp & 0xFF;
		buf[1] = (myTurnValues.Kp >> 8) & 0xFF;

		buf[2] = myTurnValues.Ki & 0xFF;
		buf[3] = (myTurnValues.Ki >> 8) & 0xFF;

		buf[4] = myTurnValues.Kd & 0xFF;
		buf[5] = (myTurnValues.Kd >> 8) & 0xFF;

		buf[6] = myTurnValues.outputMin;
		buf[7] = myTurnValues.outputMax;
		buf[8] = myTurnValues.base;

		UNERBUS_Write(aBus, buf, 9);
		length = 10;
		break;
	case SET_PID_WALL_GAINS:
		myWallValues.Kp = UNERBUS_GetUInt16(aBus);
		myWallValues.Ki = UNERBUS_GetUInt16(aBus);
		myWallValues.Kd = UNERBUS_GetUInt16(aBus);
		myWallValues.outputMin = UNERBUS_GetInt8(aBus);
		myWallValues.outputMax = UNERBUS_GetInt8(aBus);
		myWallValues.base = UNERBUS_GetInt8(aBus);
		break;
	case GET_PID_WALL_GAINS:
		buf[0] = myWallValues.Kp & 0xFF;
		buf[1] = (myWallValues.Kp >> 8) & 0xFF;

		buf[2] = myWallValues.Ki & 0xFF;
		buf[3] = (myWallValues.Ki >> 8) & 0xFF;

		buf[4] = myWallValues.Kd & 0xFF;
		buf[5] = (myWallValues.Kd >> 8) & 0xFF;

		buf[6] = myWallValues.outputMin;
		buf[7] = myWallValues.outputMax;
		buf[8] = myWallValues.base;

		UNERBUS_Write(aBus, buf, 9);
		length = 10;
		break;
	case GET_CURRENT_ACTION:

		break;
	case GET_INTERSECTION_TYPE:
		{
	    uint8_t frontWall = (PERCEPTION_FRONT_LEFT | PERCEPTION_FRONT_RIGHT);
	    uint8_t leftWall  = PERCEPTION_DIAG_LEFT;
	    uint8_t rightWall = PERCEPTION_DIAG_RIGHT;

	    uint8_t intersectionIndex = (leftWall << 2) | (frontWall << 1) | (rightWall);

	    UNERBUS_WriteByte(aBus, intersectionIndex);
	    length = 2;
		break;
		}
	}

	if(length)
		UNERBUS_Send(aBus, id, length);

}

void USBReceive(uint8_t *buf, uint16_t len){
	UNERBUS_ReceiveBuf(&unerbusPC, buf, len);
}

/////////////////////////////// PROGRAM FUNCTIONS ///////////////////////////////
void Do1ms(){
	on1MS = 0;

	if(t10MS)
		t10MS--;

	Infrared_DigitalPerception(&myInfraredValues, &flagsIR.byte, OBJECT_DETECTION_THRESHOLD);
}

void Do10ms(){
	t10MS = 10;

	if(t20MS)
		t20MS--;

	if(t100MS)
		t100MS--;

	Robot_StateMachine();

	MPU6050_Get_Yaw(&myMpuValues, 10);
	MPU_READ_REQUEST = 1;

	Infrared_Convert(&myInfraredValues);

	ESP01_Timeout10ms();
	UNERBUS_Timeout(&unerbusESP01);
	UNERBUS_Timeout(&unerbusPC);
}

void Do20ms(){
	t20MS = 2;
}

void Do100ms(){
	t100MS = 10;

	if(t1S)
		t1S--;

	Heartbeat();

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

//void Do1s(){
//	t1S = 10;
//
//	OLED_SetCursor(&myOled, 3, 3);
//	sprintf(strAux, "%d", currentAction);
//	OLED_WriteString(&myOled, strAux, Font_7x10, White);
//
//	OLED_SetCursor(&myOled, 30, 16);
//	sprintf(strAux, "%ld   ", myMpuValues.data.relativeYawScaled);
//	OLED_WriteString(&myOled, strAux, Font_7x10, White);
//
//	w.i32 = myTurnValues.Kp;//w.i32 /= 16384;
//	OLED_SetCursor(&myOled, 19, 27);
////	if(currentAction != ACTION_IN_THE_MIDDLE)
////		sprintf(strAux, "F");
////	else
////		sprintf(strAux, "G");
//	sprintf(strAux, "%3ld   ", myWallValues.outputMin);
//	OLED_WriteString(&myOled, strAux, Font_7x10, White);
//
//	w.i32 = myTurnValues.Ki;
//	OLED_SetCursor(&myOled, 19, 38);
//	sprintf(strAux, "%3ld", targetYaw);
//	//sprintf(strAux, "%3hd R:%3hd", myInfraredValues.filteredSamples[LEFT_SENSOR], myInfraredValues.filteredSamples[RIGHT_SENSOR]);
//	//sprintf(strAux, "%hd   ", w.i16[0]);
//	OLED_WriteString(&myOled, strAux, Font_7x10, White);
//
//
//	OLED_SetCursor(&myOled, 82, 21);
//	sprintf(strAux, "P:%3hd", myWallValues.Kp);
////	sprintf(strAux, "L:%3hd%c", myEngines.leftSpeed, '%');
//	OLED_WriteString(&myOled, strAux, Font_7x10, White);
//
//	OLED_SetCursor(&myOled, 82, 33);
//	sprintf(strAux, "I:%3hd", myWallValues.Ki);
////	sprintf(strAux, "R:%3hd%c", myEngines.rightSpeed, '%');
//	OLED_WriteString(&myOled, strAux, Font_7x10, White);
//
//	OLED_SetCursor(&myOled, 82, 52);
//	sprintf(strAux, "D:%3hd", myWallValues.Kd);
//	OLED_WriteString(&myOled, strAux, Font_7x10, White);
//
//	OLED_SetCursor(&myOled, 3, 52);
////	if(currentMode != MODE_EXPLORING_MAZE)
////		sprintf(strAux, "M. F");
////	else
////		sprintf(strAux, "M. G");
//	//sprintf(strAux, "D: %ld    ", myTurnValues.Kd);
//	sprintf(strAux, "%3ld", myWallValues.outputMax);
//	OLED_WriteString(&myOled, strAux, Font_7x10, White);
//
//    if (myOled.currentPageToUpdate >= 8) {
//        myOled.currentPageToUpdate = 0; // Start from page 0
//        myOled.updatePageState = 0;   // Start from page state 0
//    }
//
//    /*
//	if(do10s == 5 && state == 1){
//		do10s = 0;
//		state++;
//	}
//
//	if (do10s < 5)
//		do10s++;
//	else
//		do10s = 0;
//     */
//}

void Do1s(void) {
	t1S = 10;

	OLED_SetCursor(&myOled, 3, 3);
	sprintf(strAux, "%d", currentAction);
	OLED_WriteString(&myOled, strAux, Font_7x10, White);

	OLED_SetCursor(&myOled, 3, 16);
	switch (detectedIntersection) {
		case INTERSECTION_RIGHT_SQUARE:
			sprintf(strAux, "%c%c", '_', '|');
			break;
		case INTERSECTION_RIGHT_FRONT_OPEN:
			sprintf(strAux, "%c%c", '_','|');
			break;
		case INTERSECTION_LEFT_SQUARE:
			sprintf(strAux, "%c%c", '|', '_');
			break;
		case INTERSECTION_LEFT_FRONT_OPEN:
			sprintf(strAux, "%c%c", '|', '-');
			break;
		case INTERSECTION_CROSSROAD:
			sprintf(strAux, " %c ", '+');
			break;
		case INTERSECTION_T_ROAD:
			sprintf(strAux, " %c ", 'T');
			break;
		case INTERSECTION_DEAD_END:
			sprintf(strAux, " %c ", 'X');
			break;
		case INTERSECTION_UNKNOWN:
			sprintf(strAux, " %c ", '|');
			break;
	}

	OLED_WriteString(&myOled, strAux, Font_7x10, White);

//	OLED_SetCursor(&myOled, 3, 16);
//	// Muestra el ángulo RELATIVO, que es el que se usa para el giro.
//	sprintf(strAux, "YawRel: %d", myMpuValues.data.relativeYaw);
//	OLED_WriteString(&myOled, strAux, Font_7x10, White);
//
//	OLED_SetCursor(&myOled, 3, 28);
//	// Muestra el ángulo ABSOLUTO, para ver si se acumula correctamente.
//	sprintf(strAux, "YawAbs: %d", myMpuValues.data.absoluteYaw);
//	OLED_WriteString(&myOled, strAux, Font_7x10, White);
//
//	OLED_SetCursor(&myOled, 3, 40);
//	// Muestra el paso actual de la secuencia de prueba.
//	sprintf(strAux, "Test: %d", test_turn_sequence);
//	OLED_WriteString(&myOled, strAux, Font_7x10, White);

	if (myOled.currentPageToUpdate >= 8) {
		myOled.currentPageToUpdate = 0; // Start from page 0
		myOled.updatePageState = 0;   // Start from page state 0
	}
}

void Robot_StateMachine() {
	switch(currentMode){
	case MODE_IDLE:
		//currentAction = ACTION_IDLE;
		break;
	case MODE_EXPLORING_MAZE:
		Robot_ExploreMaze();
		break;
	case MODE_MAZE_RUNNER:
		break;
	case MODE_FINDING_MARKS:
		break;
	}

	switch(currentAction) {
	case ACTION_IDLE:
		ENGINE_SetLeftSpeed(&myEngines, 0);
		ENGINE_SetRightSpeed(&myEngines, 0);
		break;
	case ACTION_FOLLOW_WALL:
		{
			uint8_t frontWallClose = (FILTERED_FRONT_LEFT_IR > WALL_FRONT_THRESHOLD) || (FILTERED_FRONT_RIGHT_IR > WALL_FRONT_THRESHOLD);

			if (frontWallClose) {
				ENGINE_SetLeftSpeed(&myEngines, 0);
				ENGINE_SetRightSpeed(&myEngines, 0);

				pivotDegreesTarget = 180;
				currentAction = ACTION_TURN_PIVOT;
				MPU6050_Reset_Yaw(&myMpuValues);
				break;
			}

			if (FILTERED_FRONT_UNDER_IR < LINE_DETECTION_THRESHOLD) {
				detectedIntersection = Robot_IdentifyIntersection();
				MPU6050_Reset_Yaw(&myMpuValues);
				currentAction = ACTION_CENTER_IN_CELL;
			} else {
				Robot_FollowWall_Control();
			}

		}
		break;
	case ACTION_TURN_PIVOT:
		Robot_Turn_Control(pivotDegreesTarget);
		break;
	case ACTION_CENTER_IN_CELL:

		if (FILTERED_REAR_UNDER_IR < LINE_DETECTION_THRESHOLD) {
	        ENGINE_SetLeftSpeed(&myEngines, 0);
	        ENGINE_SetRightSpeed(&myEngines, 0);

	        switch(detectedIntersection) {
	            case INTERSECTION_RIGHT_FRONT_OPEN:
	            case INTERSECTION_RIGHT_SQUARE:
	            case INTERSECTION_CROSSROAD:
	                pivotDegreesTarget = -90;
	                break;
	            case INTERSECTION_LEFT_FRONT_OPEN:
	            case INTERSECTION_LEFT_SQUARE:
	                pivotDegreesTarget = 90;
	                break;
	            case INTERSECTION_T_ROAD:
	                pivotDegreesTarget = 90;
	                break;
	            default:
	                pivotDegreesTarget = 0;
	                break;
	        }

	        if (pivotDegreesTarget != 0) {
	            currentAction = ACTION_TURN_SMOOTH;
	            MPU6050_Reset_Yaw(&myMpuValues);
	        } else {
	            currentAction = ACTION_FOLLOW_WALL;
	        }

		} else {
	        int32_t error = myMpuValues.data.relativeYawScaled - 0;
	        PID_Compute(&myTurnValues, error, 10);
	        int8_t correction = (int8_t)myTurnValues.output;
	        ENGINE_SetLeftSpeed(&myEngines, (-myWallValues.base - correction));
	        ENGINE_SetRightSpeed(&myEngines, (-myWallValues.base + correction));
		}

	    break;
	case ACTION_TURN_SMOOTH:
		{
			int32_t error_yaw = myMpuValues.data.relativeYawScaled - (pivotDegreesTarget * YAW_SCALE);

			if ((error_yaw >= -SMOOTH_TURN_EXIT_THRESHOLD) && (error_yaw <= SMOOTH_TURN_EXIT_THRESHOLD)) {
				currentAction = ACTION_FOLLOW_WALL;
				PID_Reset(&myWallValues);
			} else {

		        int32_t target_ang_vel = (pivotDegreesTarget > 0) ? TARGET_ANGULAR_VELOCITY : -TARGET_ANGULAR_VELOCITY;
		        int32_t current_ang_vel = myMpuValues.data.gyroZ; // Asegúrate de que Gz esté escalado correctamente.
		        int32_t error_ang_vel = target_ang_vel - current_ang_vel;

		        // 2. Calcular la salida del PID.
		        PID_Compute(&mySmoothTurnValues, error_ang_vel, 10);
		        int8_t correction = (int8_t)mySmoothTurnValues.output;

		        // 3. Aplicar la velocidad base y la corrección a las ruedas.
		        // La corrección se suma a la rueda exterior y se resta a la interior.
		        int8_t outer_speed = SMOOTH_TURN_BASE_SPEED + correction;
		        int8_t inner_speed = SMOOTH_TURN_BASE_SPEED - correction;

		        // 4. Asignar velocidades a las ruedas (usando la lógica invertida que descubriste).
		        if (pivotDegreesTarget > 0) { // Giro a la derecha
		            ENGINE_SetRightSpeed(&myEngines, outer_speed);
		            ENGINE_SetLeftSpeed(&myEngines, inner_speed);
		        } else { // Giro a la izquierda
		            ENGINE_SetLeftSpeed(&myEngines, outer_speed);
		            ENGINE_SetRightSpeed(&myEngines, inner_speed);
		        }

//	            if (pivotDegreesTarget > 0) {
//	                ENGINE_SetRightSpeed(&myEngines, SMOOTH_TURN_OUTER_SPEED);
//	                ENGINE_SetLeftSpeed(&myEngines, SMOOTH_TURN_INNER_SPEED);
//	            } else {
//	                ENGINE_SetLeftSpeed(&myEngines, SMOOTH_TURN_OUTER_SPEED);
//	                ENGINE_SetRightSpeed(&myEngines, SMOOTH_TURN_INNER_SPEED);
//	            }
			}
		}
		break;
	default:
		currentAction = ACTION_IDLE;
		break;
	}
}

void Robot_ExploreMaze() {

	return;
}

void Robot_FollowWall_Control(void) {
	uint8_t has_LeftWall = (FILTERED_LEFT_IR > OPEN_CORNER_THRESHOLD);
	uint8_t has_RightWall = (FILTERED_RIGHT_IR > OPEN_CORNER_THRESHOLD);
	int32_t error_Wall = 0;
	int8_t correction = 0;

	const int8_t WALL_ERROR_DEADZONE = 100;

	if (has_LeftWall && has_RightWall) {
        // Caso 1: Dos paredes. El error es la diferencia entre ellas.
		error_Wall = FILTERED_LEFT_IR - FILTERED_RIGHT_IR;
	} else if (has_RightWall) {
        // Caso 2: Solo pared derecha. El error es la diferencia con la distancia objetivo.
        // El signo negativo se aplicará a la corrección, no al error.
		error_Wall = ONE_WALL_TARGET_DISTANCE - FILTERED_RIGHT_IR;
	} else if (has_LeftWall) {
        // Caso 3: Solo pared izquierda. El error es la diferencia con la distancia objetivo.
		error_Wall = ONE_WALL_TARGET_DISTANCE - FILTERED_LEFT_IR;
	}

    if (abs(error_Wall) > WALL_ERROR_DEADZONE) {
        PID_Compute(&myWallValues, error_Wall, 10);
        correction = (int8_t)myWallValues.output;

        // El PID para una sola pared derecha debe actuar en dirección opuesta.
        // Si solo hay pared derecha, la corrección debe ser negativa.
        if (!has_LeftWall && has_RightWall) {
            correction = -correction;
        }
    } else {
        // Si estamos en la zona muerta o no hay paredes, no hay corrección.
        // Además, reseteamos el PID para evitar que el término integral acumulado
        // cause un salto brusco cuando volvamos a necesitarlo.
        PID_Reset(&myWallValues);
        correction = 0;
    }
//	if (has_LeftWall && has_RightWall) { // CASE WHEN THERE ARE 2 WALLS
//		error_Wall = FILTERED_LEFT_IR - FILTERED_RIGHT_IR;
//		PID_Compute(&myWallValues, error_Wall, 10);
//		correction = (int8_t) myWallValues.output;
//	} else if (has_RightWall) {
//		error_Wall = ONE_WALL_TARGET_DISTANCE - FILTERED_RIGHT_IR;
//		PID_Compute(&myWallValues, error_Wall, 10);
//		correction = -(int8_t) myWallValues.output;
//	} else if (has_LeftWall) {
//		error_Wall = ONE_WALL_TARGET_DISTANCE - FILTERED_LEFT_IR;
//		PID_Compute(&myWallValues, error_Wall, 10);
//		correction = (int8_t) myWallValues.output;
//	} else {
//		correction = 0;
//	}

	ENGINE_SetLeftSpeed(&myEngines, (-myWallValues.base - correction));
	ENGINE_SetRightSpeed(&myEngines, (-myWallValues.base + correction));
}

void Robot_Turn_Control(int16_t degreesToTurn) {
	int32_t error = myMpuValues.data.relativeYawScaled - (degreesToTurn * YAW_SCALE);
	int32_t errorAbs = (error < 0) ? -error : error;

	if (errorAbs <= TURN_THRESHOLD) {
		ENGINE_SetLeftSpeed(&myEngines, 0);
		ENGINE_SetRightSpeed(&myEngines, 0);
		test_turn_sequence++;
		currentAction = ACTION_FOLLOW_WALL;
		return;
	}

	PID_Compute(&myTurnValues, error, 10);

	int8_t power = (int8_t)myTurnValues.output;

	if (power > 0 && power < TURN_MIN_PWM) power = TURN_MIN_PWM;
	else if (power < 0 && power > -TURN_MIN_PWM) power = -TURN_MIN_PWM;

	ENGINE_SetLeftSpeed(&myEngines, -power);
	ENGINE_SetRightSpeed(&myEngines, power);

//	if (errorAbs <= TURN_THRESHOLD) {
//		ENGINE_SetLeftSpeed(&myEngines, 0);
//		ENGINE_SetRightSpeed(&myEngines, 0);
//		currentAction = ACTION_FOLLOW_WALL;
//		PID_Reset(&myWallValues); PID_Reset(&myTurnValues);
//		MPU6050_Reset_Yaw(&myMpuValues);
//		return;
//	}
//
//	PID_Compute(&myTurnValues, error, 10);
//
//	int8_t power = (int8_t)myTurnValues.output;
//
//    if (power > 0 && power < TURN_MIN_PWM) power = TURN_MIN_PWM;
//    else if (power < 0 && power > -TURN_MIN_PWM) power = -TURN_MIN_PWM;
//
//	ENGINE_SetLeftSpeed(&myEngines, -power);
//	ENGINE_SetRightSpeed(&myEngines, power);
}

IntersectionType_e Robot_IdentifyIntersection(void) {
    // 1. Determinar el estado de las paredes
    uint8_t frontWall = (PERCEPTION_FRONT_LEFT | PERCEPTION_FRONT_RIGHT);
    uint8_t leftWall  = PERCEPTION_DIAG_LEFT;
    uint8_t rightWall = PERCEPTION_DIAG_RIGHT;

    // 2. Combinar los estados en un índice de 3 bits
    uint8_t intersectionIndex = (leftWall << 2) | (frontWall << 1) | (rightWall);

    // 3. Devolver el resultado directamente desde la tabla
    return intersectionLUT[intersectionIndex];
}

void ChangeDisplayPage(DisplayPage_e page){
	switch(page){
		case DISPLAY_CLEAR:
			break;
		case DISPLAY_INITIALIZING:
			OLED_Fill(&myOled, Black);
			OLED_DrawRect(&myOled, 1, 1, 126, 62, White);
			OLED_DrawHorizontalLine(&myOled, 2, 13, 125, White);
			  //OLED_DrawHorizontalLine(2, 14, 125, White);
			OLED_DrawHorizontalLine(&myOled, 2, 49, 125, White);
			  //OLED_DrawHorizontalLine(2, 50, 125, White);

//			OLED_SetCursor(&myOled, 3, 3);
//			sprintf(strAux, "   Spiazzi 2024");
//			OLED_WriteString(&myOled, strAux, Font_7x10, White);

			OLED_SetCursor(&myOled, 3, 16);
			sprintf(strAux, "Yaw:");
			OLED_WriteString(&myOled, strAux, Font_7x10, White);

			OLED_SetCursor(&myOled, 3, 27);
			sprintf(strAux, "m:");
			OLED_WriteString(&myOled, strAux, Font_7x10, White);

			OLED_SetCursor(&myOled, 3, 38);
			sprintf(strAux, "B:");
			OLED_WriteString(&myOled, strAux, Font_7x10, White);

			  /*
			  OLED_SetCursor(3, 52);
			  sprintf(strAux, "MODE: IDLE");
			  OLED_WriteString(strAux, Font_7x10, White);
			  */
			break;
		case DISPLAY_MODE_AND_CONNECTION:
			break;
		case DISPLAY_MPU_AND_ENGINES:
			break;
		case DISPLAY_IR_SENSORS:
			break;
	}
    if (myOled.currentPageToUpdate >= 8) {
        myOled.currentPageToUpdate = 0; // Start from page 0
        myOled.updatePageState = 0;   // Start from page state 0
    }
}

void Heartbeat() {
	uint8_t write;
	write = ~(mask>>moveMask) & 1;
	moveMask++;
	moveMask ^= (moveMask & 16);
	HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, write);
}

static void ButtonNormalPress(void) {
	// Si estamos parados, iniciamos la secuencia de giros.
	if (currentAction != ACTION_FOLLOW_WALL)
		currentAction = ACTION_FOLLOW_WALL;
	else
		currentAction = ACTION_IDLE;

//	OLED_SetCursor(&myOled, 82, 21);
//	sprintf(strAux, "L:%3hd%c", myEngines.leftSpeed, '%');
//	OLED_WriteString(&myOled, strAux, Font_7x10, White);
	return;
}

static void ButtonLongPress(void) {
//	OLED_SetCursor(&myOled, 82, 33);
//	sprintf(strAux, "R:%3hd%c", myEngines.rightSpeed, '%');
//	OLED_WriteString(&myOled, strAux, Font_7x10, White);
	return;
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
  HAL_Delay(100);

  // Register callbacks for I2C Operations
  Port_I2C_Register_DMA_Rx_Callback(MPU_Read_Completed_Callback, &myMpuValues);
  Port_I2C_Register_DMA_Tx_Callback(OLED_Write_Completed_Callback, &myOled);

  // OLED Initialization
  if (OLED_Init(&myOled, OLED_I2C_ADDR, &hi2c2) != OLED_OK){
      while (1) {
          HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
          HAL_Delay(500);
      }
  }

  // OLED Start Image
  OLED_DrawBitmap(&myOled, OLED_WIDTH, OLED_HEIGHT, varEeprom);
  myOled.currentPageToUpdate = 0;
  myOled.updatePageState = 0;

  while (myOled.currentPageToUpdate < 8) {
      I2C_State_Control();
  }

  ChangeDisplayPage(DISPLAY_INITIALIZING);

  HAL_Delay(1200) ;

  // MPU6050 Initialization
  if (MPU6050_Init(&myMpuValues, MPU6050_ADDR, &hi2c2) != MPU6050_OK) {
      while (1) {
          HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
          HAL_Delay(100);
      }
  }

  // MPU6050 Calibration
  if (MPU6050_Calibrate(&myMpuValues) != MPU6050_OK) {
      while (1) {
          HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
          HAL_Delay(3000);
      }
  }

  I2C_BUS_IS_BUSY = 0;

  HAL_Delay(1500);

  // Engines Initialization
  ENGINE_Init(&myEngines);

  HAL_Delay(500);

  // Buttons Initialization
  BUTTON_Init(&myButton1, SW1_GPIO_Port, SW1_Pin);

  BUTTON_Register_PressReleasedCallback(&myButton1, ButtonNormalPress);
  BUTTON_Register_LongPressCallback(&myButton1, ButtonLongPress);

  // PID Initialization
  PID_Init(&mySmoothTurnValues, 10, 0, 10, -90, 90);
  mySmoothTurnValues.base = SMOOTH_TURN_BASE_SPEED;
  PID_Init(&myTurnValues, 100, 0, 300, -80, 80);
  PID_Init(&myWallValues, 1, 0, 100, -80, 80);
  myTurnValues.base = TURN_MIN_PWM;
  myWallValues.base = 45;

  turnInnerSpeed = SMOOTH_TURN_INNER_SPEED;
  turnOuterSpeed = SMOOTH_TURN_OUTER_SPEED;

  // IR Sensors Initialization
  Infrared_Init(&myInfraredValues);

  // Communication Initialization
  CDC_AttachRxData(USBReceive);

  ESP01_Init(&esp01);
  UNERBUS_Init(&unerbusESP01);
  UNERBUS_Init(&unerbusPC);

  ESP01_AttachChangeState(ESP01ChangeState);
  ESP01_SetWIFI(WIFI_SSID, WIFI_PASSWORD);
  ESP01_StartUDP(WIFI_UDP_REMOTE_IP, WIFI_UDP_REMOTE_PORT, WIFI_UDP_LOCAL_PORT);

  HAL_UART_Receive_IT(&huart1, &dataRXESP01, 1);

  // Timers Initialization
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

  // ROBOT NAVIGATION INICIALIZATION
  currentAction = ACTION_IDLE;

  prevWallState = WALL_STATE_NONE;
  detectedIntersection = INTERSECTION_UNKNOWN;
  wallFadeCounter = 0;
  ticksOpenSpace = 0;
  pivotDegreesTarget = 0;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  if(on1MS)
		  Do1ms();

	  if(!t10MS)
		  Do10ms();

	  if(!t20MS)
		  Do20ms();

	  if(!t100MS)
		  Do100ms();

	  if(!t1S)
		  Do1s();

	  I2C_State_Control();

	  ESP01_Task();

	  UNERBUS_Task(&unerbusESP01);

	  UNERBUS_Task(&unerbusPC);

	  BUTTON_Update(&myButton1);

	  if(!tOutAliveUDP){
		  tOutAliveUDP = 50;
		  UNERBUS_WriteByte(&unerbusESP01, ACKNOWLEDGE);
		  UNERBUS_Send(&unerbusESP01, ALIVE, 2);

		  //UNERBUS_WriteConstString(&unerbusPC, "UNER\x03:\xF0\x0D\xC8", 0);
		  //UNERBUS_WriteConstString(&unerbusPC, " El ALIVE", 1);
	  }

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
  sConfig.SamplingTime = ADC_SAMPLETIME_55CYCLES_5;
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
  hi2c2.Init.ClockSpeed = 400000;
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
  htim4.Init.Period = 9999;
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

  /*Configure GPIO pin : SW1_Pin */
  GPIO_InitStruct.Pin = SW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(SW1_GPIO_Port, &GPIO_InitStruct);

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
