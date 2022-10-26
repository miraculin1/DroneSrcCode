#include "IIC.h"
#include "LED.h"
#include "MPU6050.h"
#include "stm32f4xx.h"
#include <stdint.h>

int main() {
  initLED();

  uint16_t x;
  uint16_t y;
  uint16_t z;
  uint8_t reg = 0;
  initIIC();
  // TODO bug in 0x1a 0x1b 0x1c
  /* initMPU6050(); */
  ref();
  IIC_ReadData(0xd0, 0x6b, &reg);
  LED_ON();
  while (1) {
    ReadMPU6050(&x, &y, &z);
  }
}
