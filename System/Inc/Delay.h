#ifndef __DELAY_H
#define __DELAY_H
#include "stm32f4xx.h"

#define STK_CTRL *(uint32_t *)(0xE000E010)
#define STK_LOAD *(uint32_t *)(0xE000E014)
#define STK_VAL *(uint32_t *)(0xE000E018)
#define STK_CALIB *(uint32_t *)(0xE000E01c)
#define CLK 84000000
void delay_us(uint32_t delay_us);
void delay_ms(uint32_t delay_ms);

#endif
