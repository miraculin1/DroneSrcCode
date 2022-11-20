#ifndef __MPU6050_H
#define __MPU6050_H

#define SELF_ADD 0xd0
#include "IIC.h"
void initMPU6050();
void MPUReadData(uint16_t *x, uint16_t *y, uint16_t *z);
#endif
