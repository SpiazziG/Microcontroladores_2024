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
	SET_BATTERY_VOLTAGE = 0xC4,

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
	GET_MAP_INFO			= 0xEF,
} Command_e;

typedef enum {
	DISPLAY_MENU,
	DISPLAY_IR_SENSORS,
	DISPLAY_MPU,
	DISPLAY_WIFI,
	DISPLAY_MOTORS,
	DISPLAY_SOFTWARE,
	DISPLAY_RUN,
	DISPLAY_CLEAR,
} DisplayPage_e;

typedef enum {
	MENU_START = 0,
	MENU_IR_DATA,
	MENU_MPU_DATA,
	MENU_WIFI,
	MENU_DRIVE_MOTOR,
	MENU_SOFTWARE_INFO,
	MENU_MAX_OPTIONS,
} MenuOptions_e;

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
	ACTION_AFTER_TURN,
	ACTION_TURN_PIVOT,
	ACTION_TURN_SMOOTH,
	ACTION_HANDLE_FRONT_WALL,
} Robot_Action_e;

typedef enum {
	NORTH = 0,
	EAST = 1,
	SOUTH = 2,
	WEST = 3,
} Map_Direction_e;

typedef enum {
	// [Left | Front | Right] -> (L << 2) | (F << 1) | R
	INTERSECTION_CROSSROAD			= 0x00,	// 0b000
	INTERSECTION_LEFT_FRONT_OPEN	= 0x01,	// 0b001
	INTERSECTION_T_ROAD				= 0x02, // 0b010
	INTERSECTION_LEFT_SQUARE		= 0x03,	// 0b011
	INTERSECTION_RIGHT_FRONT_OPEN	= 0x04, // 0b100
	INTERSECTION_UNKNOWN			= 0x05,	// 0b101 Hall
	INTERSECTION_RIGHT_SQUARE		= 0x06,	// 0b110
	INTERSECTION_DEAD_END			= 0x07,	// 0b111
} IntersectionType_e;

typedef enum {
	CELL_INSIDE_CELL,		// Robot navigating inside the cell, normal state
	CELL_FRONT_LINE,		// Front-under sensor detected the line
	CELL_REAR_LINE,			// Rear-under sensor detected the line
	CELL_CROSS_FINISHED,	// Rear-under sensor lost the line (robot is inside a new cell)
} CellCrossingState_e;

typedef struct {
	uint8_t t1ms;
	uint8_t t10ms;
	uint8_t t20ms;
	uint8_t t100ms;
	uint8_t t500ms;
	uint8_t t1s;
	uint8_t tOutAliveUDP;
} Time_s;

typedef struct {
	uint8_t walls;
	uint8_t visited;
	uint8_t cost;
} CellData_s;

typedef struct {
	CellData_s maze[16][16];
	uint8_t currentX;
	uint8_t currentY;
} Map_Position_s;

typedef struct {
	uint32_t time_frontLineDetect;
	uint32_t time_rearLineDetect;
	uint32_t currentVelocity_mm_s;
	uint32_t time_dt_ms;
} VELOCITY_Handle_s;
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

// Display design macros
#define MENU_ITEM_HEIGHT		12 // 10px fuente + 2px espacio
#define MENU_START_Y			14 // Debajo de la línea del header
#define MAX_VISIBLE_ITEMS		4 // Cuántas opciones caben en pantalla a la vez

// Flags macros
#define on1MS					flag1.bit.b0
#define MPU_READ_REQUEST		flag1.bit.b1
#define OLED_UPDATE_REQUEST		flag1.bit.b2
#define I2C_BUS_IS_BUSY			flag1.bit.b3
#define LINE_DETECTED_TURNING	flag1.bit.b4

// Timer counter macros
#define t1MS					timeCounter.t1ms
#define t10MS					timeCounter.t10ms
#define t20MS					timeCounter.t20ms
#define t100MS					timeCounter.t100ms
#define t500MS					timeCounter.t500ms
#define t1S						timeCounter.t1s
#define tOutAliveUDP 			timeCounter.tOutAliveUDP

// Voltage of the batteries (used for PID control of the engines)
#define PID_VOLTAGE					800
#define CURRENT_VOLTAGE				820

// Turn control macros
#define SMOOTH_TURN_OUTER_SPEED		-65
#define SMOOTH_TURN_INNER_SPEED		-35
#define TURN_THRESHOLD				7*YAW_SCALE

#define SMOOTH_TURN_BASE_SPEED		-50
#define SMOOTH_EXIT_OFFSET 			(7 * YAW_SCALE)
#define TURN_MIN_PWM				30

// Wall follow control macros
#define WALL_FRONT_THRESHOLD		1050 	// Para no chocar la pared de enfrente 			// Casa: 1050 	// Facu: 1200
#define OPEN_CORNER_THRESHOLD		320 	// Para detectar la apertura de una esquina 	// Casa: 320 	// Facu: 170
#define ONE_WALL_TARGET_DISTANCE 	1400 	// Para seguir la pared 						// Casa: 1400 	// Facu: 1100
#define OBJECT_DETECTION_THRESHOLD	130 	// Para detectar pared al otro lado del cruce 	// Casa: 150 	// Facu: 190
#define LINE_DETECTION_THRESHOLD	1400 	// Para detectar la línea de la celda 			// Casa: 1400 	// Facu: 1500
#define LATERAL_WALL_THRESHOLD		800 	// Detectar si hay pared al lado (mapeo) 		// Casa: 500 	// Facu: 800

#define DIAG_COLLISION_THRESHOLD 	1600  // Ajustar según calibración (valor alto = muy cerca)
#define ANTI_CRASH_TURN_SPEED    	30    // Potencia para corregir el choque

#define WALL_ERROR_DEADZONE			50
#define GYRO_COMPENSATION_GAIN		30 		// Ponderación del giroscopio para mantenerse recto en un cruce con una sola pared

// IR MACROS
#define FILTERED_RIGHT_IR			myInfraredValues.filteredSamples[0]
#define FILTERED_DIAG_RIGHT_IR		myInfraredValues.filteredSamples[1]
#define FILTERED_FRONT_RIGHT_IR		myInfraredValues.filteredSamples[2]
#define FILTERED_FRONT_UNDER_IR		myInfraredValues.filteredSamples[3]
#define FILTERED_FRONT_LEFT_IR		myInfraredValues.filteredSamples[4]
#define FILTERED_DIAG_LEFT_IR		myInfraredValues.filteredSamples[5]
#define FILTERED_LEFT_IR			myInfraredValues.filteredSamples[6]
#define FILTERED_REAR_UNDER_IR		myInfraredValues.filteredSamples[7]

#define DISTANCE_FRONT_TO_REAR_IR	 85 // Millimeter
#define IR_CENTER_DISTANCE_THRESHOLD 1400

#define PERCEPTION_RIGHT			flagsIR.bit.b0
#define PERCEPTION_DIAG_RIGHT		flagsIR.bit.b1
#define	PERCEPTION_FRONT_RIGHT		flagsIR.bit.b2
#define PERCEPTION_FRONT_LEFT		flagsIR.bit.b4
#define PERCEPTION_DIAG_LEFT		flagsIR.bit.b5
#define PERCEPTION_LEFT				flagsIR.bit.b6

#define WALL_NORTH 0x01
#define WALL_EAST 0x02
#define WALL_SOUTH 0x04
#define WALL_WEST 0x08
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
DisplayPage_e currentPage;
MenuOptions_e currentMenu;
Command_e cmds;
Time_s timeCounter;

static _uFlag flagsIR;
static InfraredHandle_s myInfraredValues;
static MPU_Handle_s myMpuValues;
static OLED_Handle_s myOled;
static PIDHandle_s myTurnValues, myWallValues, mySmoothTurnValues, myStopValues;
static ENGINE_Handle_s myEngines;
static BUTTON_Handle_s myButton1;
static VELOCITY_Handle_s myVelocity;
/////////////////////////// COMMUNICATION VARIABLES ////////////////////////////
_sESP01Handle esp01;
_sUNERBUSHandle unerbusPC;
_sUNERBUSHandle unerbusESP01;

char localIP[16];

uint8_t bufRXPC[SIZEBUFRXPC], bufTXPC[SIZEBUFTXPC];
uint8_t bufRXESP01[SIZEBUFRXESP01], bufTXESP01[SIZEBUFTXESP01], dataRXESP01;

uint8_t rxUSBData, newData;

static uint8_t i2c_start_timeout = 0;
////////////////////////////// HEARTBEAT VARIABLES /////////////////////////////
uint16_t mask, moveMask;

//////////////////////////// DISPLAY & MENU VARIABLES //////////////////////////
const char* menuItems[] = {
	"Run", 		// "Run           ",
    "Infrared", // "Infrared      ",
    "Motion",
    "Wi-Fi",
    "Motors", 	// "Motors        ",
    "Software"
};

const int8_t totalMenuItems = 6;
int8_t currentSelection;
int8_t scrollOffset;
//////////////////////////////// OTHER VARIABLES ///////////////////////////////
// Robot maneuver variables
Robot_Mode_e currentMode;
Robot_Action_e currentAction;

static uint16_t snapDiagLeft = 0, snapFront = 0, snapDiagRight = 0;

CellCrossingState_e cellState;

Map_Position_s currentPosition;
Map_Direction_e currentDirection = NORTH;

IntersectionType_e detectedIntersection;
//const IntersectionType_e intersectionLUT[8] = {
//	// Index -> [Left | Front | Right]
//	// 0b000 -> [ No | No | No ]
//	INTERSECTION_CROSSROAD,
//	// 0b001 -> [ No | No | Yes ]
//	INTERSECTION_LEFT_FRONT_OPEN,
//	// 0b010 -> [ No | Yes | No ]
//	INTERSECTION_T_ROAD,
//	// 0b011 -> [ No | Yes | Yes ]
//	INTERSECTION_LEFT_SQUARE,
//	// 0b100 -> [ Yes | No | No ]
//	INTERSECTION_RIGHT_FRONT_OPEN,
//	// 0b101 -> [ Yes | No | Yes ] -> Hall
//	INTERSECTION_UNKNOWN,
//	// 0b110 -> [ Yes | Yes | No ]
//	INTERSECTION_RIGHT_SQUARE,
//	// 0b111 -> [ Yes | Yes | Yes ] -> Could be a dead end, or a premature detection of a turn
//	//INTERSECTION_UNKNOWN
//	INTERSECTION_DEAD_END,
//};

uint8_t intersectionType;
int16_t pivotDegreesTarget;

int32_t wallFollowTargetYaw = 0;
uint16_t referenceLeftWall = 0, referenceRightWall = 0;
uint8_t exitTurn;
uint32_t timeToCenter, centeringStartTime;

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
void I2C_Bus_Recovery(void);
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
void Robot_GoBlind(void);
void Robot_Turn_Control(int16_t degreesToTurn);
void Robot_CheckCellCrossing(void);
IntersectionType_e Robot_IdentifyIntersection(void);
void Robot_UpdateWall(void);
void Robot_UpdateDirection(int8_t turnDir);
void Robot_UpdateCoordinates(void);

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
	if (I2C_BUS_IS_BUSY) {

//		if ((HAL_GetTick() - i2c_start_timeout) > 15) {
//			I2C_Bus_Recovery();
//		}
		return;
	}

	if (MPU_READ_REQUEST) {
		MPU_READ_REQUEST = 0;
		I2C_BUS_IS_BUSY = 1;
		i2c_start_timeout = HAL_GetTick();
		MPU6050_Read_Data(&myMpuValues);
		return;
	} else if (myOled.currentPageToUpdate < 8) {
		I2C_BUS_IS_BUSY = 1;
		i2c_start_timeout = HAL_GetTick();
		OLED_UpdateSingleStep_DMA(&myOled);
	}
}

//void I2C_Bus_Recovery(void) {
//	// 1. Detener cualquier transferencia DMA que haya quedado a medias
//	    if (hi2c2.hdmatx != NULL) HAL_DMA_Abort(hi2c2.hdmatx);
//	    if (hi2c2.hdmarx != NULL) HAL_DMA_Abort(hi2c2.hdmarx);
//
//	    // 2. Reseteo violento por hardware del periférico I2C2
//	    __HAL_RCC_I2C2_FORCE_RESET();
//	    __NOP();
//		__NOP();
//		__NOP();
//		__NOP();
//	    __HAL_RCC_I2C2_RELEASE_RESET();
//
//	    // 3. Reinicializar el periférico con tu configuración original
//	    MX_I2C2_Init();
//
//	    // 4. Liberar el bus
//	    I2C_BUS_IS_BUSY = 0;
//	    MPU_READ_REQUEST = 0;
//
//	    // 5. Resetear la máquina de estados del OLED.
//	    // Lo mandamos a 8 para que aborte el cuadro actual y espere a que
//	    // Do100ms() pida un cuadro nuevo. Esto evita glitches gráficos.
//	    myOled.updatePageState = 0;
//	    myOled.currentPageToUpdate = 8;
//}

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
	case SET_BATTERY_VOLTAGE:
		ENGINE_SetBatteryVoltage(&myEngines, UNERBUS_GetUInt16(aBus));
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
		}
		break;
	case GET_MAP_INFO:

		break;
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

	if (currentPage == DISPLAY_RUN) {
		if (currentAction == ACTION_TURN_PIVOT) {
			if (FILTERED_FRONT_UNDER_IR < LINE_DETECTION_THRESHOLD)
				LINE_DETECTED_TURNING = 1;
		} else if (currentAction != ACTION_CENTER_IN_CELL){
			Robot_CheckCellCrossing();
		}
//		if (currentAction != ACTION_TURN_PIVOT && currentAction != ACTION_CENTER_IN_CELL)
//			Robot_CheckCellCrossing();
	}

	ESP01_Timeout10ms();
	UNERBUS_Timeout(&unerbusESP01);
	UNERBUS_Timeout(&unerbusPC);

	ENGINE_Task(&myEngines);
}

void Do20ms(){
	t20MS = 2;
}

void Do100ms(){
	t100MS = 10;

	if(t1S)
		t1S--;

	Heartbeat();

//	if (currentPage != DISPLAY_RUN) {
			ChangeDisplayPage(currentPage);
//	}
//	ChangeDisplayPage(currentPage);
//    if (currentPage == DISPLAY_IR_SENSORS) {
//        if (myOled.currentPageToUpdate == 0) {
//             ChangeDisplayPage(currentPage);
//        }
//    }

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

void Do1s(void) {
	t1S = 10;

	if(currentMode != MODE_IDLE) {
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
		//uint8_t frontWallClose = (FILTERED_FRONT_LEFT_IR > WALL_FRONT_THRESHOLD) || (FILTERED_FRONT_RIGHT_IR > WALL_FRONT_THRESHOLD);

		Robot_FollowWall_Control();

//		if ((FILTERED_FRONT_LEFT_IR > WALL_FRONT_THRESHOLD) ||
//		        (FILTERED_FRONT_RIGHT_IR > WALL_FRONT_THRESHOLD))
//		{
//			ENGINE_SetLeftSpeed(&myEngines, 0);
//			ENGINE_SetRightSpeed(&myEngines, 0);
//			currentAction = ACTION_IDLE;
//			currentMode = MODE_IDLE;
//			uint8_t wallLeft  = (FILTERED_LEFT_IR > OPEN_CORNER_THRESHOLD);
//			uint8_t wallRight = (FILTERED_RIGHT_IR > OPEN_CORNER_THRESHOLD);
//
//			if (wallLeft && wallRight) {
				// Pared Izq + Der + Frente = Callejón sin salida (Dead End)
//				pivotDegreesTarget = 180;
//
//				currentAction = ACTION_TURN_PIVOT;
//
//				MPU6050_Reset_Yaw(&myMpuValues);
//				PID_Reset(&myTurnValues); // Reseteamos PID de giro
//				PID_Reset(&myWallValues); // Reseteamos PID de pared
//			}
//			else if (wallLeft) {
//				// Pared Izq + Frente = Girar Derecha
//				pivotDegreesTarget = 90;
//			}
//			else if (wallRight) {
//				// Pared Der + Frente = Girar Izquierda
//				pivotDegreesTarget = -90;
//			}
//			else {
//				// Solo pared enfrente (es una "T" o Cruz donde chocamos la pared de fondo)
//				// Por defecto giramos a la izquierda (o tu preferencia)
//				pivotDegreesTarget = -90;
//			}
//
//			// 4. Configurar el giro PIVOT (Porque estamos parados frente a la pared)
//			MPU6050_Reset_Yaw(&myMpuValues);
//			PID_Reset(&myTurnValues); // Reseteamos PID de giro
//			PID_Reset(&myWallValues); // Reseteamos PID de pared
//
//			currentAction = ACTION_TURN_PIVOT;
//		}

		break;
	case ACTION_TURN_PIVOT:
		Robot_Turn_Control(pivotDegreesTarget);
		break;
	case ACTION_CENTER_IN_CELL:
		Robot_FollowWall_Control();

		if (!(detectedIntersection & 0b010)) { // Si no hay pared al frente
			if (HAL_GetTick() - centeringStartTime >= timeToCenter) {
				ENGINE_SetLeftSpeed(&myEngines, 0);
				ENGINE_SetRightSpeed(&myEngines, 0);

				if (pivotDegreesTarget == 180 || pivotDegreesTarget == -180) {
					// Menor valor IR = Más espacio libre
					if (FILTERED_LEFT_IR < FILTERED_RIGHT_IR) {
						// Hay más lugar a la izquierda -> giramos por la izquierda
						pivotDegreesTarget = 180;  // Asumiendo que + es izquierda
					} else {
						// Hay más lugar a la derecha -> giramos por la derecha
						pivotDegreesTarget = -180; // Asumiendo que - es derecha
					}
				}

				currentAction = ACTION_TURN_PIVOT;

				PID_Reset(&myTurnValues);
				MPU6050_Reset_Yaw(&myMpuValues);
			}
		}
	    break;
	case ACTION_AFTER_TURN:
		Robot_FollowWall_Control();
		break;
	case ACTION_TURN_SMOOTH:
//		{
//            // 1. Calcular el error de ángulo (Distancia al objetivo)
//            // (Asumimos que target es 90, -90, etc)
//            int32_t current_yaw = myMpuValues.data.relativeYawScaled;
//            int32_t target_yaw  = pivotDegreesTarget * YAW_SCALE;
//            int32_t error_yaw   = target_yaw - current_yaw;
//            int32_t error_abs   = (error_yaw < 0) ? -error_yaw : error_yaw;
//
//            // 2. Definir velocidades fijas para el arco (Ajustar empíricamente)
//            // Recuerda: Tus velocidades son NEGATIVAS para ir adelante.
//            // Una rueda va rápido (Externa) y la otra lento (Interna).
//            int8_t speed_fast = -90; // Rueda externa (recorre más distancia)
//            int8_t speed_slow = -20; // Rueda interna (pivote del arco)
//
//            // 3. Verificar si terminamos
//            if (error_abs <= SMOOTH_EXIT_OFFSET) {
//                // ¡LLEGAMOS!
//                // Opción A: Frenar un poco si la siguiente recta es corta
//                // Opción B: Pasar directo a seguir pared (más fluido)
//
//                currentAction = ACTION_FOLLOW_WALL;
//                PID_Reset(&myWallValues); // Resetear PID de pared para evitar saltos
//            }
//            else {
//                // 4. MANTENER EL ARCO
//                // No usamos PID aquí. Confiamos en la geometría de las ruedas.
//
//                if (pivotDegreesTarget < 0) {
//                    // --- GIRO A DERECHA (Right Turn) ---
//                    // Rueda IZQUIERDA es la externa (Rápida)
//                    // Rueda DERECHA es la interna (Lenta)
//                    ENGINE_SetLeftSpeed(&myEngines, speed_fast);
//                    ENGINE_SetRightSpeed(&myEngines, speed_slow);
//                }
//                else {
//                    // --- GIRO A IZQUIERDA (Left Turn) ---
//                    // Rueda DERECHA es la externa (Rápida)
//                    // Rueda IZQUIERDA es la interna (Lenta)
//                    ENGINE_SetLeftSpeed(&myEngines, speed_slow);
//                    ENGINE_SetRightSpeed(&myEngines, speed_fast);
//                }
//            }
//        }
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
	uint8_t hasLeftWall;
	uint8_t hasRightWall;

	int32_t errorWall;
	int32_t errorGyro;
	int32_t errorTotal;
	int8_t correction;

	int32_t currentYaw = myMpuValues.data.relativeYawScaled;

//	if (currentAction == ACTION_AFTER_TURN) {
//		if (pivotDegreesTarget == 90) {
//			hasLeftWall = 0;
//			hasRightWall = (detectedIntersection >> 1) & 0x01;
//		}
//		else if (pivotDegreesTarget == -90) {
//			hasLeftWall = (detectedIntersection >> 1) & 0x01;
//			hasRightWall = 0;
//		}
//		else if (pivotDegreesTarget == 180 || pivotDegreesTarget == -180) {
//			hasLeftWall == detectedIntersection & 0x01;
//			hasRightWall == (detectedIntersection >> 2) & 0x01;
//		}
////		hasLeftWall = (FILTERED_LEFT_IR > LATERAL_WALL_THRESHOLD);
////		hasRightWall = (FILTERED_RIGHT_IR > LATERAL_WALL_THRESHOLD);
//	} else {
//			hasLeftWall = (detectedIntersection & 0x04) >> 2;
//			hasRightWall = detectedIntersection & 0x01;
		hasLeftWall = (FILTERED_LEFT_IR > LATERAL_WALL_THRESHOLD) ? 1 : 0;
		hasRightWall = (FILTERED_RIGHT_IR > LATERAL_WALL_THRESHOLD) ? 1 : 0;
//	}

	if (hasLeftWall && hasRightWall) {
		// Caso 1: Dos paredes. El error es la diferencia entre ellas.
		errorWall = FILTERED_LEFT_IR - FILTERED_RIGHT_IR;
		errorGyro = 0;
		errorTotal = errorWall;
	} else if (hasRightWall) {
		// Caso 2: Solo pared derecha. El error es la diferencia con la distancia objetivo.
		// El signo negativo se aplicará a la corrección, no al error.
		errorWall = referenceRightWall - FILTERED_RIGHT_IR;

		errorGyro = (wallFollowTargetYaw - currentYaw) / YAW_SCALE;

		errorTotal = errorWall + (errorGyro * GYRO_COMPENSATION_GAIN);

		errorTotal = -errorTotal;
	} else if (hasLeftWall) {
		// Caso 3: Solo pared izquierda. El error es la diferencia con la distancia objetivo.
		errorWall = FILTERED_LEFT_IR - referenceLeftWall;

		errorGyro = (currentYaw - wallFollowTargetYaw) / YAW_SCALE;

		errorTotal = errorWall + (errorGyro * GYRO_COMPENSATION_GAIN);
	} else {
		// Caso 4: sin paredes, navegar de forma ciega
		errorWall = 0;
		errorGyro = (currentYaw - wallFollowTargetYaw) / YAW_SCALE;
		errorTotal = errorGyro * GYRO_COMPENSATION_GAIN;
	}

	if (abs(errorTotal) > WALL_ERROR_DEADZONE) {
		PID_Compute(&myWallValues, errorTotal, 10);
		correction = (int8_t)myWallValues.output;

		// El PID para una sola pared derecha debe actuar en dirección opuesta.
		// Si solo hay pared derecha, la corrección debe ser negativa.
		if (!hasLeftWall && hasRightWall)
			correction = -correction;
	} else {
		// Si estamos en la zona muerta o no hay paredes, no hay corrección.
		// Además, reseteamos el PID para evitar que el término integral acumulado
		// cause un salto brusco cuando volvamos a necesitarlo.
		PID_Reset(&myWallValues);
		correction = 0;
	}

	// --- INICIO PID FRENO ---
	int8_t currentBaseSpeed = myWallValues.base; // Guardamos la velocidad base original temporalmente

	// Tomamos el valor más alto de los dos sensores frontales por seguridad
	uint16_t maxFrontIR = (FILTERED_FRONT_LEFT_IR > FILTERED_FRONT_RIGHT_IR) ? FILTERED_FRONT_LEFT_IR : FILTERED_FRONT_RIGHT_IR;

	uint16_t brakeStartIR = 500; // Distancia a la que empezamos a soltar el acelerador
	uint16_t stopTolerance = 50; // Distancia a la que cortamos (850 +/- 50)

	if ((detectedIntersection & 0b010) && (currentAction == ACTION_CENTER_IN_CELL)) {
		if (maxFrontIR >= brakeStartIR) {
			// Calculamos el error.
			// Si maxFrontIR es 300 (lejos) -> errorDistance es +550
			// Si maxFrontIR es 900 (se pasó por inercia) -> errorDistance es -50
			int16_t errorDistance = WALL_FRONT_THRESHOLD - maxFrontIR;

			PID_Compute(&myStopValues, errorDistance, 10);

			currentBaseSpeed = (int8_t)myStopValues.output;

			// Si estamos dentro del rango objetivo, cortamos todo y salimos
			if (abs(errorDistance) <= stopTolerance) {
				ENGINE_SetLeftSpeed(&myEngines, 0);
				ENGINE_SetRightSpeed(&myEngines, 0);

				PID_Reset(&myStopValues);
				PID_Reset(&myWallValues);
				MPU6050_Reset_Yaw(&myMpuValues);

				// Cambia el estado aquí según la lógica de tu laberinto
				currentAction = ACTION_TURN_PIVOT;
				return; // Abortamos para no sobrescribir el 0
			}
		} else {
			PID_Reset(&myStopValues);
		}

		int8_t brake_min_pwm = 30;

		// Si el PID calculó una fuerza muy chica, la subimos al mínimo necesario para moverse
		if (currentBaseSpeed > 0 && currentBaseSpeed < brake_min_pwm) {
		    currentBaseSpeed = brake_min_pwm;
		} else if (currentBaseSpeed < 0 && currentBaseSpeed > -brake_min_pwm) {
		    currentBaseSpeed = -brake_min_pwm;
		}
	}
	ENGINE_SetLeftSpeed(&myEngines, (-currentBaseSpeed - correction));
	ENGINE_SetRightSpeed(&myEngines, (-currentBaseSpeed + correction));
//	ENGINE_SetLeftSpeed(&myEngines, (-myWallValues.base - correction));
//	ENGINE_SetRightSpeed(&myEngines, (-myWallValues.base + correction));
}

void Robot_Turn_Control(int16_t degreesToTurn) {
	int32_t error = myMpuValues.data.relativeYawScaled - (degreesToTurn * YAW_SCALE);
	int32_t errorAbs = (error < 0) ? -error : error;

	if (errorAbs <= TURN_THRESHOLD) {
		ENGINE_SetLeftSpeed(&myEngines, 0);
		ENGINE_SetRightSpeed(&myEngines, 0);
		currentAction = ACTION_AFTER_TURN;
//		currentAction = ACTION_IDLE;
		PID_Reset(&myWallValues);
		PID_Reset(&myTurnValues);
		MPU6050_Reset_Yaw(&myMpuValues);

		wallFollowTargetYaw = 0;

		if (LINE_DETECTED_TURNING) {
			LINE_DETECTED_TURNING = 0;

			snapDiagLeft = FILTERED_DIAG_LEFT_IR;
			snapDiagRight = FILTERED_DIAG_RIGHT_IR;
			// Para el frente, tomamos el mayor de los dos frontales por seguridad
			snapFront = (FILTERED_FRONT_LEFT_IR > FILTERED_FRONT_RIGHT_IR) ? FILTERED_FRONT_LEFT_IR : FILTERED_FRONT_RIGHT_IR;

			detectedIntersection = Robot_IdentifyIntersection();

			cellState = CELL_FRONT_LINE;

			myVelocity.time_frontLineDetect = HAL_GetTick();
		} else {
			cellState = CELL_INSIDE_CELL;
		}

//		cellState = CELL_INSIDE_CELL;
		return;
	}

	PID_Compute_Gyro(&myTurnValues, error, myMpuValues.data.gyroZ);
//	PID_Compute(&myTurnValues, error, 10);

	int8_t power = (int8_t)myTurnValues.output;
	if (errorAbs > (15 * YAW_SCALE)) {
		if (power > 0 && power < TURN_MIN_PWM) power = TURN_MIN_PWM;
		else if (power < 0 && power > -TURN_MIN_PWM) power = -TURN_MIN_PWM;
	}

	ENGINE_SetLeftSpeed(&myEngines, -power);
	ENGINE_SetRightSpeed(&myEngines, power);
}

//void Robot_GoBlind(void) {
//	int32_t errorGyro = 0;
//	int8_t correction = 0;
//
//	errorGyro = ((currentYaw - wallFollowTargetYaw) / YAW_SCALE) * GYRO_COMPENSATION_GAIN;
//
//	int32_t currentYaw = myMpuValues.data.relativeYawScaled;
//    if (abs(errorTotal) > WALL_ERROR_DEADZONE) {
//        PID_Compute(&myWallValues, errorGyro, 10);
//        correction = (int8_t)myWallValues.output;
//
//        // El PID para una sola pared derecha debe actuar en dirección opuesta.
//        // Si solo hay pared derecha, la corrección debe ser negativa.
//        if (!hasLeftWall && hasRightWall)
//            correction = -correction;
//    } else {
//        // Si estamos en la zona muerta o no hay paredes, no hay corrección.
//        // Además, reseteamos el PID para evitar que el término integral acumulado
//        // cause un salto brusco cuando volvamos a necesitarlo.
//        PID_Reset(&myWallValues);
//        correction = 0;
//    }
//
//	ENGINE_SetLeftSpeed(&myEngines, (-myWallValues.base - correction));
//	ENGINE_SetRightSpeed(&myEngines, (-myWallValues.base + correction));
//}

IntersectionType_e Robot_IdentifyIntersection(void) {
    // 1. Determinar el estado de las paredes
    uint8_t frontWall = (PERCEPTION_FRONT_LEFT | PERCEPTION_FRONT_RIGHT);
    uint8_t leftWall  = PERCEPTION_DIAG_LEFT;
    uint8_t rightWall = PERCEPTION_DIAG_RIGHT;

    // 2. Combinar los estados en un índice de 3 bits
    uint8_t intersectionIndex = (leftWall << 2) | (frontWall << 1) | (rightWall);

    // 3. Devolver el resultado directamente desde la tabla
    return (IntersectionType_e)intersectionIndex;
//    return intersectionLUT[intersectionIndex];
}

void Robot_CheckCellCrossing(void) {
    uint8_t frontLine = (FILTERED_FRONT_UNDER_IR < LINE_DETECTION_THRESHOLD);
    uint8_t rearLine  = (FILTERED_REAR_UNDER_IR < LINE_DETECTION_THRESHOLD);

    switch (cellState) {
        case CELL_INSIDE_CELL:
            if (frontLine) { 		// Wait until the front sensor see the line
//            	ChangeDisplayPage(currentPage);

            	myVelocity.time_frontLineDetect = HAL_GetTick();

                cellState = CELL_FRONT_LINE;

                snapDiagLeft = FILTERED_DIAG_LEFT_IR;
				snapDiagRight = FILTERED_DIAG_RIGHT_IR;
				// Para el frente, tomamos el mayor de los dos frontales por seguridad
				snapFront = (FILTERED_FRONT_LEFT_IR > FILTERED_FRONT_RIGHT_IR) ? FILTERED_FRONT_LEFT_IR : FILTERED_FRONT_RIGHT_IR;

            	detectedIntersection = Robot_IdentifyIntersection();

            	if (currentAction != ACTION_AFTER_TURN) {
//					referenceLeftWall = ONE_WALL_TARGET_DISTANCE;
//					referenceRightWall = ONE_WALL_TARGET_DISTANCE;
            	}
				switch(detectedIntersection) {
					// GIROS A LA IZQUIERDA
					case INTERSECTION_LEFT_FRONT_OPEN:
					case INTERSECTION_LEFT_SQUARE:
					case INTERSECTION_CROSSROAD:
						pivotDegreesTarget = 90;
						Robot_UpdateDirection(-1);
						break;
					// GIROS A LA DERECHA
					case INTERSECTION_T_ROAD: // Forzado a izquierda para pruebas
						pivotDegreesTarget = 90;
						Robot_UpdateDirection(-1);
						break;
					case INTERSECTION_RIGHT_FRONT_OPEN:
						pivotDegreesTarget = -90;
						break;
					case INTERSECTION_RIGHT_SQUARE:
						pivotDegreesTarget = -90;
						Robot_UpdateDirection(1);
						break;
					// CALLEJÓN SIN SALIDA (CASO ESPECIAL)
					// Aquí quizás quieras frenar ANTES, no esperar a perder la línea
					// Pero si lo usas, funcionará igual.
					case INTERSECTION_DEAD_END:
						 pivotDegreesTarget = 180;
//						 Robot_UpdateDirection(2);
//						 currentAction = ACTION_TURN_PIVOT;
//						 MPU6050_Reset_Yaw(&myMpuValues);
//						 cellState = CELL_INSIDE_CELL;
						 break;
					case INTERSECTION_UNKNOWN:
						pivotDegreesTarget = 0;
						break;
					default:
						break;
				}
            }
            break;
        case CELL_FRONT_LINE:
            if (!frontLine) {

            }

            if (rearLine) {
            	myVelocity.time_rearLineDetect = HAL_GetTick();

            	myVelocity.time_dt_ms = myVelocity.time_rearLineDetect - myVelocity.time_frontLineDetect;

            	myVelocity.currentVelocity_mm_s = (DISTANCE_FRONT_TO_REAR_IR * 1000) / myVelocity.time_dt_ms;

                cellState = CELL_REAR_LINE;

                if (detectedIntersection != INTERSECTION_UNKNOWN) {
					timeToCenter = (45 * 1000) / myVelocity.currentVelocity_mm_s; //30 * 1000

					currentAction = ACTION_CENTER_IN_CELL;

					centeringStartTime = HAL_GetTick();
                } else {
                	if (currentAction == ACTION_AFTER_TURN){
//                		referenceLeftWall = ONE_WALL_TARGET_DISTANCE;
//                		referenceRightWall = ONE_WALL_TARGET_DISTANCE;
                		currentAction = ACTION_FOLLOW_WALL;
                	}
                }
                // 1. Actualizamos coordenadas basándonos en la dirección con la que LLEGAMOS
				Robot_UpdateCoordinates();

				// 2. Mapear paredes de la nueva celda (opcional aquí o al estabilizarse)
				Robot_UpdateWall();
            }
            break;
        case CELL_REAR_LINE:
            if (!rearLine)
                cellState = CELL_CROSS_FINISHED;


            break;
        case CELL_CROSS_FINISHED:
            // NEW CELL CONFIRMED
            // 1. Update coordinates
            // 2. Reset relatives variables

            // Return to initial state
            cellState = CELL_INSIDE_CELL;
            break;
    }
}

void Robot_UpdateWall(void) {
	uint8_t dir;
	uint8_t buf[5];

	if (FILTERED_RIGHT_IR > LATERAL_WALL_THRESHOLD) {
		dir = (currentDirection + 1) % 4;
		currentPosition.maze[currentPosition.currentX][currentPosition.currentY].walls |= (1 << dir);
	}

	if (FILTERED_LEFT_IR > LATERAL_WALL_THRESHOLD) {
		dir = (currentDirection + 3) % 4;
		currentPosition.maze[currentPosition.currentX][currentPosition.currentY].walls |= (1 << dir);
	}

	if ((FILTERED_FRONT_LEFT_IR > LATERAL_WALL_THRESHOLD) || (FILTERED_FRONT_RIGHT_IR > LATERAL_WALL_THRESHOLD)) {
		dir = (currentDirection + 0) % 4;
		currentPosition.maze[currentPosition.currentX][currentPosition.currentY].walls |= (1 << dir);
	}

	currentPosition.maze[currentPosition.currentX][currentPosition.currentY].visited = 1;

	buf[0] = currentPosition.currentX;
	buf[1] = currentPosition.currentY;
	buf[2] = currentPosition.maze[currentPosition.currentX][currentPosition.currentY].walls;
	buf[3] = currentDirection;

    UNERBUS_WriteByte(&unerbusESP01, buf[0]);
    UNERBUS_WriteByte(&unerbusESP01, buf[1]);
    UNERBUS_WriteByte(&unerbusESP01, buf[2]);
    UNERBUS_WriteByte(&unerbusESP01, buf[3]);
    UNERBUS_Send(&unerbusESP01, GET_MAP_INFO, 4);
}

void Robot_UpdateDirection(int8_t turnDir) {
	// La aritmética de punteros con el enum Map_Direction_e:
	// NORTH=0, EAST=1, SOUTH=2, WEST=3

	// turn: 0 (Recto), 1 (Derecha +90), -1 (Izquierda -90), 2 (Media vuelta 180)

	int8_t newDir = currentDirection + turnDir;

	// Normalizar para mantenerlo entre 0 y 3
	if (newDir > 3) newDir -= 4;
	else if (newDir < 0) newDir += 4;

	currentDirection = (Map_Direction_e)newDir;
}

void Robot_UpdateCoordinates(void) {
	switch(currentDirection){
		case NORTH:
			if(currentPosition.currentY > 0) currentPosition.currentY++; //y--;
			// Asumiendo (0,0) arriba-izquierda. Si (0,0) es abajo, sería Y++.
			break;
		case EAST:
			if(currentPosition.currentX < 15) currentPosition.currentX++;
			break;
		case SOUTH:
			if(currentPosition.currentY < 15) currentPosition.currentY++;
			break;
		case WEST:
			if(currentPosition.currentX > 0) currentPosition.currentX--;
			break;
	}
}

void ChangeDisplayPage(DisplayPage_e page){
	const char* currentTitle = "";
	uint8_t y = GUI_HEADER_HEIGHT + GUI_WIDGET_ROW_GAP;
	char str[32];

	switch(page){
		case DISPLAY_CLEAR:
			OLED_Fill(&myOled, Black);
			break;
//		case DISPLAY_INITIALIZING:
//			break;
		case DISPLAY_MENU:
			currentTitle = "Menu";
			OLED_Fill(&myOled, Black);

			if (currentSelection >= scrollOffset + MAX_VISIBLE_ITEMS) {
			        scrollOffset = currentSelection - MAX_VISIBLE_ITEMS + 1;
			    }
			    // Si la selección subió por encima del scroll, subimos el scroll
			    if (currentSelection < scrollOffset) {
			        scrollOffset = currentSelection;
			    }

			    // 4. DIBUJAR LISTA DE OPCIONES
			    for (int i = 0; i < MAX_VISIBLE_ITEMS; i++) {
			        int8_t itemIndex = scrollOffset + i;

			        if (itemIndex >= totalMenuItems) break; // No hay más items

			        int y_pos = MENU_START_Y + (i * MENU_ITEM_HEIGHT);

			        // ¿Es esta la opción seleccionada? -> DIBUJO INVERTIDO
			        if (itemIndex == currentSelection) {
			            // Dibuja un rectángulo blanco de fondo para la selección
			            OLED_DrawFilledRect(&myOled, 15, y_pos - 1, 98, MENU_ITEM_HEIGHT-1, White);

			            // Escribe el texto en NEGRO
			            OLED_SetCursor(&myOled, 15, y_pos);
			            sprintf(strAux, "%s", menuItems[itemIndex]); // Sin ">", la barra basta
			            OLED_WriteString(&myOled, strAux, Font_7x10, Black);
			        }
			        else {
			            // Opción normal (Fondo negro, texto blanco)
			        	//OLED_DrawRect(&myOled, 15, y_pos - 1, 98, MENU_ITEM_HEIGHT-1, Black);
			            OLED_SetCursor(&myOled, 15, y_pos);
			            sprintf(strAux, "%s", menuItems[itemIndex]);
			            OLED_WriteString(&myOled, strAux, Font_7x10, White);
			        }
			    }
			break;
		case DISPLAY_RUN:
			OLED_Fill(&myOled, Black);
			int y_pos = MENU_START_Y + (MENU_ITEM_HEIGHT);
			OLED_SetCursor(&myOled, 1, y_pos-26);
			switch(currentAction) {
			case ACTION_IDLE:
				sprintf(str, "IDLE");
				break;
			case ACTION_FOLLOW_WALL:
				sprintf(str, "FOLLOW WALL");
				break;
			case ACTION_CENTER_IN_CELL:
				sprintf(str, "CENTER CELL");
				break;
			case ACTION_AFTER_TURN:
				sprintf(str, "AFTER TURN");
				break;
			case ACTION_TURN_PIVOT:
				sprintf(str, "PIVOT");
				break;
			case ACTION_TURN_SMOOTH:
				sprintf(str, "SMOOTH");
				break;
			case ACTION_HANDLE_FRONT_WALL:
				sprintf(str, "HAND. F. WALL");
				break;
			}
			OLED_WriteString(&myOled, str, Font_7x10, White);

			OLED_SetCursor(&myOled, 1, y_pos-12);
			int32_t currentYaw = myMpuValues.data.relativeYawScaled / YAW_SCALE;
			sprintf(str, "Tgt:%d Now:%ld", pivotDegreesTarget, currentYaw);

			OLED_WriteString(&myOled, str, Font_7x10, White);


			OLED_SetCursor(&myOled, 1, y_pos);

	        switch(detectedIntersection) {
	            case INTERSECTION_RIGHT_FRONT_OPEN:
	            	sprintf(str, "<- |");
	            	break;
	            case INTERSECTION_RIGHT_SQUARE:
	            	sprintf(str, "<-");
	            	break;
	            case INTERSECTION_CROSSROAD:
	            	sprintf(str, "CROSS");
	                break;
	            case INTERSECTION_LEFT_FRONT_OPEN:
	            	sprintf(str, "| ->");
	            	break;
	            case INTERSECTION_LEFT_SQUARE:
	            	sprintf(str, "->");
	                break;
	            case INTERSECTION_T_ROAD:
	            	sprintf(str, "T");
	                break;
	            case INTERSECTION_UNKNOWN:
	            	sprintf(str, "HALL");
	            	break;
	            case INTERSECTION_DEAD_END:
	            	sprintf(str, "DEAD");
	        }
			OLED_WriteString(&myOled, str, Font_7x10, White);

			OLED_SetCursor(&myOled, 1, y_pos+12);

			sprintf(str, "%d %d %d", snapDiagLeft, snapFront, snapDiagRight);
//			sprintf(str, "L:%3d R:%3d", myEngines.currentLeftSpeed, myEngines.currentRightSpeed);
//	        switch(cellState) {
//	            case CELL_INSIDE_CELL:
//	            	sprintf(str, "C: INSIDE");
//	            	break;
//	            case CELL_FRONT_LINE:
//	            	sprintf(str, "C: FRONT");
//	            	break;
//	            case CELL_REAR_LINE:
//	            	sprintf(str, "C: REAR");
//	                break;
//	            case CELL_CROSS_FINISHED:
//	            	sprintf(str, "C: END");
//	            	break;
//	        }
			OLED_WriteString(&myOled, str, Font_7x10, White);
			//OJOS
//		    uint8_t baseW = 23;
//		    uint8_t baseH = 34;
//		    uint8_t baseX_L = 34;
//		    uint8_t baseX_R = 71;
//		    uint8_t baseY = 15;
//
//		    // Variables dinámicas
//		    uint8_t w_L = baseW, h_L = baseH;
//		    uint8_t w_R = baseW, h_R = baseH;
//		    uint8_t x_L = baseX_L, y_L = baseY;
//		    uint8_t x_R = baseX_R, y_R = baseY;
//
//		    uint8_t showEyebrow = 0;
//
//		    switch(detectedIntersection){
//		    case INTERSECTION_DEAD_END:
//		    	w_L = 13; h_L = 15; y_L = baseY + 10;
//		    	// Ojo izquierdo
////		    	x_L = 25;
////		    	y_L = 43;
////		    	w_L = 34;
////		    	h_L = 21;
////
////		    	// Ojo derecho
////		    	x_R = 69;
////		    	y_R = 43;
////		    	w_R = 34;
////		    	h_R = 21;
//		    	break;
//		    case INTERSECTION_RIGHT_SQUARE:
//		    case INTERSECTION_RIGHT_FRONT_OPEN:
//		        // --- MIRAR A IZQUIERDA ---
//		        // Se desplazan a la izquierda
//		        x_L = 1;
//		        x_R = 41;
//
//		        y_L = 10;
//		        // Perspectiva: Se hacen más angostos
//		        // El ojo izquierdo (el que "lidera" el giro) se hace más fino
//		        w_L = 26; // Muy fino
//		        h_L = 42; // Medio fino
//		    	break;
//		    case INTERSECTION_LEFT_SQUARE:
//		    case INTERSECTION_LEFT_FRONT_OPEN:
//				// --- MIRAR A DERECHA ---
//				// Se desplazan a la derecha
//				x_L = 64;
//				x_R = 101;
//
//				y_R = 10;
//
//				// Perspectiva
//				h_R = 42; // Medio fino
//				w_R = 26; // Muy fino
//		    	break;
//		    case INTERSECTION_CROSSROAD:
//		    case INTERSECTION_T_ROAD:
//		    	showEyebrow = 1;
//		    	y_L = baseY + 10;
//		    	y_R = baseY + 10;
//		    	break;
//		    case INTERSECTION_UNKNOWN:
//		        static uint32_t blinkTimer = 0;
//		        if (HAL_GetTick() - blinkTimer > 4000) { // Cada 4s
//		            h_L = 4; // Ojo casi cerrado
//		            h_R = 4;
//		            y_L = baseY + 15; // Centrado
//		            y_R = baseY + 15;
//
//		            if (HAL_GetTick() - blinkTimer > 4150) {
//		                blinkTimer = HAL_GetTick(); // Abrir
//		            }
//		        }
//		    	break;
//		    }
//
//		    OLED_DrawDigitalEye(&myOled, x_L, y_L, w_L, h_L);
//		    OLED_DrawDigitalEye(&myOled, x_R, y_R, w_R, h_R);
//
//		    if (showEyebrow) {
//		    	for(uint8_t i = 0; i < w_R - 5; i++) {
//		    		uint8_t pixelsToErase = 9 - (i / 2);
//
//		    		//if (pixelsToErase == 0) break;
//
//		    		OLED_DrawVerticalLine(&myOled, x_R + i, y_R, pixelsToErase, Black);
//		    	}
//		    }
			break;
		case DISPLAY_IR_SENSORS:
			currentTitle = menuItems[MENU_IR_DATA];
			OLED_Fill(&myOled, Black);

			// Left Column
			OLED_DrawSensorWidget(&myOled, "1", FILTERED_RIGHT_IR, 0, 0);
			OLED_DrawSensorWidget(&myOled, "2", FILTERED_DIAG_RIGHT_IR, 0, 1);
			OLED_DrawSensorWidget(&myOled, "3", FILTERED_FRONT_RIGHT_IR, 0, 2);

			// Center Column
			OLED_DrawSensorWidget(&myOled, "8", FILTERED_REAR_UNDER_IR, 1, 0);
			OLED_DrawSensorWidget(&myOled, "4", FILTERED_FRONT_UNDER_IR, 1, 2);

			// Right Column
			OLED_DrawSensorWidget(&myOled, "7", FILTERED_LEFT_IR, 2, 0);
			OLED_DrawSensorWidget(&myOled, "6", FILTERED_DIAG_LEFT_IR, 2, 1);
			OLED_DrawSensorWidget(&myOled, "5", FILTERED_FRONT_LEFT_IR, 2, 2);

			break;
		case DISPLAY_MPU:
			currentTitle = menuItems[MENU_MPU_DATA];
			OLED_Fill(&myOled, Black);
			int32_t yawDeg = myMpuValues.data.relativeYawScaled / YAW_SCALE;

			int32_t displayYaw = yawDeg % 360;
			if (displayYaw > 180) displayYaw -= 360;
			if (displayYaw < -180) displayYaw += 360;

			snprintf(str, sizeof(str), "Yaw: %ld °", yawDeg);
			OLED_SetCursor(&myOled, 0, y);
			OLED_WriteString(&myOled, str, Font_7x10, White);

			y += 12;
			OLED_DrawBidirectionalBar(&myOled, 0, y, 128, 8, displayYaw, 180);

			y += 12;
			snprintf(str, sizeof(str), "Gz: %d", myMpuValues.data.gyroZ);
			OLED_SetCursor(&myOled, 0, y);
			OLED_WriteString(&myOled, str, Font_7x10, White);

			y += 12;
		    snprintf(str, sizeof(str), "Ax:%d  Ay:%d", myMpuValues.data.accelX, myMpuValues.data.accelY);
		    OLED_SetCursor(&myOled, 0, y);
		    OLED_WriteString(&myOled, str, Font_7x10, White);
			break;
		case DISPLAY_WIFI:
			currentTitle = menuItems[MENU_WIFI];
			OLED_Fill(&myOled, Black);

			snprintf(str, sizeof(str), "Net: %.13s", WIFI_SSID);
			OLED_SetCursor(&myOled, 0, y);
			OLED_WriteString(&myOled, str, Font_7x10, White);

			y += 12;
			snprintf(str, sizeof(str), "PC: %.14s", WIFI_UDP_REMOTE_IP);
			OLED_SetCursor(&myOled, 0, y);
			OLED_WriteString(&myOled, str, Font_7x10, White);

			y += 12;
			sprintf(str, "L. Port: %d", WIFI_UDP_LOCAL_PORT);
			OLED_SetCursor(&myOled, 0, y);
			OLED_WriteString(&myOled, str, Font_7x10, White);

			y += 12;
			sprintf(str, "Status: ");
			OLED_SetCursor(&myOled, 0, y);
			OLED_WriteString(&myOled, str, Font_7x10, White);
			break;
		case DISPLAY_MOTORS:
			currentTitle = menuItems[MENU_DRIVE_MOTOR];
			OLED_Fill(&myOled, Black);

			y += 12;
			OLED_DrawBidirectionalBar(&myOled, 15, y, 75, 10, myEngines.currentLeftSpeed, 100);

			y += 12;
			OLED_DrawBidirectionalBar(&myOled, 15, y, 75, 10, myEngines.currentRightSpeed, 100);

			y += 12;

			snprintf(str, sizeof(str), "PWM Max: %d", myEngines.pwmMaxPeriod);
			OLED_SetCursor(&myOled, 0, y);
			OLED_WriteString(&myOled, str, Font_7x10, White);

//			y += 12;
//			if (myEngines.leftSpeed == 0 && myEngines.rightSpeed == 0) {
//				 OLED_WriteString(&myOled, "State: STOPPED", Font_7x10, White);
//			} else {
//				 OLED_WriteString(&myOled, "State: RUNNING", Font_7x10, White);
//			}

			break;
		case DISPLAY_SOFTWARE:
			currentTitle = menuItems[MENU_SOFTWARE_INFO];
			OLED_Fill(&myOled, Black);

			OLED_SetCursor(&myOled, 0, y);
			OLED_WriteString(&myOled, "Pathfinder v1.0", Font_7x10, White);

			y += 12;
			OLED_SetCursor(&myOled, 0, y);
			OLED_WriteString(&myOled, "Dev: G. Spiazzi", Font_7x10, White);

			y += 12;
		    OLED_SetCursor(&myOled, 0, y);
		    OLED_WriteString(&myOled, "Build: " __DATE__, Font_7x10, White);

		    y += 12;
		    OLED_SetCursor(&myOled, 0, y);
		    OLED_WriteString(&myOled, "Time:  " __TIME__, Font_7x10, White);
			break;
	}

	if (page != DISPLAY_RUN)
		OLED_DrawHeader(&myOled, currentTitle, HAL_GetTick());

    if (myOled.currentPageToUpdate >= 8) {
        myOled.currentPageToUpdate = 0; // Start from page 0
        myOled.updatePageState = 0;   // Start from page state 0
    }
}

void Heartbeat() {
	if (I2C_BUS_IS_BUSY && ((HAL_GetTick() - i2c_start_timeout) > 500)) {
		mask = 0x5555; // ERROR: Parpadeo rápido y constante (100ms ON, 100ms OFF)
	} else {
		mask = 0x0AAF; // NORMAL: 4 pulsos rápidos y pausa
	}

	uint8_t write;
	write = ~(mask>>moveMask) & 1;
	moveMask++;
	moveMask ^= (moveMask & 16);
	HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, write);
}

static void ButtonNormalPress(void) {
//	if (currentAction == ACTION_IDLE) {
//		// --- INICIAR TEST DE GIRO ---
//
//		// A. Reseteamos todo para tener condiciones iniciales limpias
//		MPU6050_Reset_Yaw(&myMpuValues);
//		PID_Reset(&myTurnValues);
//
//		// B. Definimos el objetivo (90 grados)
//		// Puedes cambiar esto a -90 si quieres probar hacia el otro lado
//		pivotDegreesTarget = 90;
//
//		// C. Disparamos la acción
//		currentAction = ACTION_TURN_PIVOT;
//
//	} else {
//		// --- PARADA DE EMERGENCIA ---
//		// Si apretas el botón mientras gira, se detiene.
//		ENGINE_SetLeftSpeed(&myEngines, 0);
//		ENGINE_SetRightSpeed(&myEngines, 0);
//		currentAction = ACTION_IDLE;
//	}

	if(currentMode == MODE_IDLE && currentPage == DISPLAY_MENU){
		currentSelection++;
		if (currentSelection >= totalMenuItems){
			currentSelection = 0;
			scrollOffset = 0;
		}
		detectedIntersection = Robot_IdentifyIntersection();
		//ChangeDisplayPage(DISPLAY_MENU);
	}

// Si estamos parados, iniciamos la secuencia de giros.
//	if (currentAction != ACTION_FOLLOW_WALL)
//		currentAction = ACTION_FOLLOW_WALL;
//	else
//		currentAction = ACTION_IDLE;

//	OLED_SetCursor(&myOled, 82, 21);
//	sprintf(strAux, "L:%3hd%c", myEngines.leftSpeed, '%');
//	OLED_WriteString(&myOled, strAux, Font_7x10, White);
	return;
}

static void ButtonLongPress(void) {
	if (currentMode != MODE_IDLE) {
		currentMode = MODE_IDLE;
		return;
	}

	switch (currentPage) {
		case DISPLAY_MENU:
			switch(currentSelection) {
			case MENU_START:
				currentPage = DISPLAY_RUN;
				ChangeDisplayPage(DISPLAY_RUN);
				Robot_UpdateWall();
				detectedIntersection = INTERSECTION_UNKNOWN;
//				referenceLeftWall = FILTERED_LEFT_IR;
//				referenceRightWall = FILTERED_RIGHT_IR;
								referenceLeftWall = ONE_WALL_TARGET_DISTANCE;
								referenceRightWall = ONE_WALL_TARGET_DISTANCE;
				currentAction = ACTION_FOLLOW_WALL;
				break;
			case MENU_IR_DATA:
				currentPage = DISPLAY_IR_SENSORS;
				ChangeDisplayPage(DISPLAY_IR_SENSORS);
				break;
			case MENU_MPU_DATA:
				currentPage = DISPLAY_MPU;
				ChangeDisplayPage(DISPLAY_MPU);
				break;
			case MENU_WIFI:
				currentPage = DISPLAY_WIFI;
				ChangeDisplayPage(DISPLAY_WIFI);
				break;
			case MENU_DRIVE_MOTOR:
				currentPage = DISPLAY_MOTORS;
				ChangeDisplayPage(DISPLAY_MOTORS);
				break;
			case MENU_SOFTWARE_INFO:
				currentPage = DISPLAY_SOFTWARE;
				ChangeDisplayPage(DISPLAY_SOFTWARE);
				break;
			}
			break;
		default:
			currentPage = DISPLAY_MENU;
			ChangeDisplayPage(DISPLAY_MENU);
			break;
	}

//	OLED_SetCursor(&myOled, 82, 33);
//	sprintf(strAux, "R:%3hd%c", myEngines.rightSpeed, '%');
//	OLED_WriteString(&myOled, strAux, Font_7x10, White);
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

  currentPage = DISPLAY_MENU;
  ChangeDisplayPage(DISPLAY_MENU);

  currentSelection = 0;
  scrollOffset = 0;

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

  // Voltage used to calibrate the PIDs
  myEngines.nominalVoltage = PID_VOLTAGE;

  // Voltage measured with the multi-meter before use
  ENGINE_SetBatteryVoltage(&myEngines, CURRENT_VOLTAGE);

  HAL_Delay(500);

  // Buttons Initialization
  BUTTON_Init(&myButton1, SW1_GPIO_Port, SW1_Pin);

  BUTTON_Register_PressReleasedCallback(&myButton1, ButtonNormalPress);
  BUTTON_Register_LongPressCallback(&myButton1, ButtonLongPress);

  // PID Initialization
  PID_Init(&mySmoothTurnValues, 10, 0, 10, -90, 90);
  mySmoothTurnValues.base = SMOOTH_TURN_BASE_SPEED;
  PID_Init(&myTurnValues, 45, 0, 500, -65, 65);
//  PID_Init(&myTurnValues, 45, 0, 2500, -65, 65);
  PID_Init(&myWallValues, 10, 0, 1500, -55, 55); // P = 1 // 45
  myTurnValues.base = TURN_MIN_PWM;
  myWallValues.base = 50;

  PID_Init(&myStopValues, 10, 10, 1500, -55, 55);
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

  detectedIntersection = INTERSECTION_UNKNOWN;
  pivotDegreesTarget = 0;

  cellState = CELL_INSIDE_CELL;
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
