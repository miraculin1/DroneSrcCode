#include "Delay.h"
#include "HMC5883.h"
#include "IIC.h"
#include "LED.h"
#include "MPU6050.h"
#include "USART.h"
#include "stm32f4xx.h"
#include <stdint.h>

int main() {
  initLED();
  initIIC();
  initMPU6050();
  initHMC();
  initUSART();

  uint16_t x;
  uint16_t y;
  uint16_t z;
  uint8_t status;
  /* ReadMPU6050(&x, &y, &z); */
  /* USendInt(x); */
  /* USendByte('|'); */
  while (1) {
    HMCReadData(&x, &y, &z);
    HMCReadByte(0x09, &status);
    USendByte(0);
    USendByte(status);
    delay_ms(1000);
  }
}
