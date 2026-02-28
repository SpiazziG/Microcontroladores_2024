/*
 * PID.h
 *
 *  Created on: May 11, 2025
 *      Author: Gerónimo Spiazzi
 */

#ifndef INC_PID_H_
#define INC_PID_H_

#include <stdint.h>

typedef struct {
    uint16_t Kp;
    uint16_t Ki;
    uint16_t Kd;

    int32_t prevError;
    int32_t integral;
    int32_t output;

    int32_t outputMin;
    int32_t outputMax;
    int8_t base;
} PIDHandle_s;

void PID_Init(PIDHandle_s *pid, int32_t Kp, int32_t Ki, int32_t Kd, int32_t min, int32_t max);
void PID_Compute(PIDHandle_s *pid, int32_t error, int32_t dt_ms);
void PID_Compute_Gyro(PIDHandle_s *pid, int32_t error, int32_t gyro_rate);
void PID_Reset(PIDHandle_s *pid);

#endif /* INC_PID_H_ */
