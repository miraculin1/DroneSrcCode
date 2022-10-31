#include "Print.h"
#include <stdint.h>

void PrintOutMPU(uint8_t add) {
  initUSART();
  initIIC();
  uint8_t data;
  IIC_ReadData(0xd0, add, &data);
  USendByte(data);
}
