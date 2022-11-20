#include "Delay.h"
#include <stdint.h>

// trying to use SysTick to delay
//
// you can choose clock in the CLKSOURCE reg
// running on "processor clock" (84MHz in this condition)

void delay_us(uint32_t delay_us) {
  // clear
  STK_LOAD &= ~(0xffffff);
  STK_LOAD |= (delay_us * (CLK / 8000000));
  STK_VAL &= ~(0xffffff);
  STK_CTRL |= (0x1);
  volatile uint32_t tmp = STK_CTRL;
  while (((tmp & 0x1) && !(tmp & (0x1 << 16)))) {
    // wait
    tmp = STK_CTRL;
  }
  STK_CTRL &= ~(0x1);
  STK_CTRL &= ~(0x1 << 16);
}

void delay_ms(uint32_t delay_ms) {
  // clear
  STK_LOAD &= ~(0xffffff);
  STK_LOAD |= (delay_ms * (CLK / 8000));
  STK_VAL &= ~(0xffffff);
  STK_CTRL |= (0x1);
  volatile uint32_t tmp = STK_CTRL;
  while (((tmp & 0x1) && !(tmp & (0x1 << 16)))) {
    // wait
    tmp = STK_CTRL;
  }
  STK_CTRL &= ~(0x1);
  STK_CTRL &= ~(0x1 << 16);
}

/* // too rough abandon */
/* // */
/* //微秒级的延时 */
/* void delay_us(uint32_t delay_us) { */
/* volatile unsigned int num; */
/* volatile unsigned int t; */
/*  */
/* for (num = 0; num < delay_us; num++) { */
/* t = 11; */
/* while (t != 0) { */
/* t--; */
/* } */
/* } */
/* } */
/* //毫秒级的延时 */
/* void delay_ms(uint32_t delay_ms) { */
/* volatile unsigned int num; */
/* for (num = 0; num < delay_ms; num++) { */
/* delay_us(1000); */
/* } */
/* } */
