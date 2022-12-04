#include "Delay.h"
#include "HMC5883.h"
#include "IIC.h"
#include "LED.h"
#include "MPU6050.h"
#include "REC.h"
#include "TIM.h"
#include "USART.h"
#include "stm32f4xx.h"
#include <stdint.h>

int main() {
  initLED();
  initUSART();
  initRec();
  initIIC();
  initMPU6050();
  initHMC();
  initUnlockMotot();

  USendStr("OK");
  uint16_t x, y, z;
  while (1) {
    MPUReadData(&x, &y, &z);
    USendInt(x);
    USendByte(';');
    USendInt(y);
    USendByte(';');
    USendInt(z);
    USendByte(';');

    if (recData.linedUp) {
      setThro1(recData.chs[2] - 1000);
    }
  }
}
