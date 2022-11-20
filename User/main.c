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
  initTIM3PWM();

  LED_ON();
  unlock();

  for (int i = 0; i < 100; i += 10) {
  setThro(i);
  delay_ms(1000);
  }
  setThro(0);

  /* uint16_t x, y, z; */
  while (1) {
    /* HMCReadData(&x, &y, &z); */
    /* USendInt(x); */
    /* USendByte(','); */
    /* USendInt(y); */
    /* USendByte(','); */
    /* USendInt(z); */
    /* USendByte('|'); */
  }
}
