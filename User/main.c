#include "Delay.h"
#include "HMC5883.h"
#include "IIC.h"
#include "LED.h"
#include "MPU6050.h"
#include "TIM.h"
#include "USART.h"
#include "stm32f4xx.h"
#include <stdint.h>

int main() {
  initLED();
  initIIC();
  initUSART();
  initMPU6050();
  initHMC();
  /* initTIM3PWM(); */
  /* unlock(); */
/*  */
  /* for (int i = 0; i < 100; i += 10) { */
    /* setThro(i); */
    /* delay_ms(1000); */
  /* } */
  /* setThro(0); */
/*  */
  LED_ON();
  while (1) {
  }
}
