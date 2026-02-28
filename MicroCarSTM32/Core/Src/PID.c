/*
 * PID.c
 *
 *  Created on: May 11, 2025
 *      Author: Gerónimo Spiazzi
 */

#include "PID.h"

void PID_Init(PIDHandle_s *pid, int32_t Kp, int32_t Ki, int32_t Kd, int32_t min, int32_t max) {
    pid->Kp = Kp;
    pid->Ki = Ki;
    pid->Kd = Kd;
    pid->prevError = 0;
    pid->integral = 0;
    pid->output = 0;
    pid->outputMin = min;
    pid->outputMax = max;
}

void PID_Compute(PIDHandle_s *pid, int32_t error, int32_t dt_ms){
    int32_t p_term = pid->Kp * error;
    int32_t i_term = pid->Ki * pid->integral;
    int32_t d_term = (pid->Kd * (error - pid->prevError)) / dt_ms;

    // Suma PID con escala para no usar flotantes
    // Escala base: 100
    pid->output = (p_term + i_term + d_term) / 100;

    if ((pid->output >= pid->outputMax) || (pid->output <= pid->outputMin)) {
        // No hacer nada con el integral.
    } else {
        pid->integral += error;
    }

    const int32_t INTEGRAL_LIMIT = 32000;
    if (pid->integral > INTEGRAL_LIMIT) {
        pid->integral = INTEGRAL_LIMIT;
    } else if (pid->integral < -INTEGRAL_LIMIT) {
        pid->integral = -INTEGRAL_LIMIT;
    }

    // Ajuste de salida / overflow
    if (pid->output > pid->outputMax)
        pid->output = pid->outputMax;
    else if (pid->output < pid->outputMin)
        pid->output = pid->outputMin;

    // Guardar error
    pid->prevError = error;
}

void PID_Compute_Gyro(PIDHandle_s *pid, int32_t error, int32_t gyro_rate) {
    int32_t p_term = pid->Kp * error;
    int32_t i_term = pid->Ki * pid->integral;

    // Como tu error es (Actual - Setpoint), la derivada del error es
    // directamente la lectura del giroscopio (velocidad angular).
    int32_t d_term = - (pid->Kd * gyro_rate * 10) / 655;

    // Suma PID con escala para no usar flotantes
    pid->output = (p_term + i_term + d_term) / 100;

    // --- El resto queda exactamente igual a tu función original ---
    if ((pid->output >= pid->outputMax) || (pid->output <= pid->outputMin)) {
        // No hacer nada con el integral.
    } else {
        pid->integral += error;
    }

    const int32_t INTEGRAL_LIMIT = 32000;
    if (pid->integral > INTEGRAL_LIMIT) {
        pid->integral = INTEGRAL_LIMIT;
    } else if (pid->integral < -INTEGRAL_LIMIT) {
        pid->integral = -INTEGRAL_LIMIT;
    }

    if (pid->output > pid->outputMax)
        pid->output = pid->outputMax;
    else if (pid->output < pid->outputMin)
        pid->output = pid->outputMin;

    pid->prevError = error;
}

void PID_Reset(PIDHandle_s *pid) {
    pid->integral = 0;
    pid->prevError = 0;
}
