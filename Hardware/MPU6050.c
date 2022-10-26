#include "MPU6050.h"
#include "IIC.h"
#include <stdint.h>

// rough delay
static void delay(uint32_t ms) {
  int i = 0;
  while (ms--) {
  i = 12000;
    while (i--)
      ;
  }
}

void ref() {
  IIC_WriteData(SELF_ADD, 0x6b, 0x00);
  IIC_WriteData(SELF_ADD, 0x19, 0x00);
  IIC_WriteData(SELF_ADD, 0x1a, 0x06);
  IIC_WriteData(SELF_ADD, 0x1b, 0x18);
  IIC_WriteData(SELF_ADD, 0x1c, 0x00);

}
void initMPU6050() {
  uint8_t data = 0;
  // reset device
  IIC_WriteData(SELF_ADD, 0x6b, 0x80);
  delay(1000);
  // select 8MHz internal clock
  IIC_WriteData(SELF_ADD, 0x6b, 0x00);
  // all axis no standby
  IIC_WriteData(SELF_ADD, 0x6c, 0x00);
  // disable interupts
  IIC_ReadData(SELF_ADD, 0x6b, &data);
  IIC_WriteData(SELF_ADD, 0x38, 0x00);
  // DLPF as 20Hz
  IIC_WriteData(SELF_ADD, 0x1a, 0x04);
  IIC_WriteData(SELF_ADD, 0x19, 0x00);
  // Gyro set to 2000degs/sec
  IIC_WriteData(SELF_ADD, 0x1b, 0x18);
  // acce set to +- 2g
  IIC_WriteData(SELF_ADD, 0x1c, 0x00);
  // set direct link to all senser in GY86
  // TODO 0x37 would change 0x6d to 65d
  IIC_WriteData(SELF_ADD, 0x37, 0x02);
  IIC_ReadData(SELF_ADD, 0x6b, &data);
}

void ReadMPU6050(uint16_t *x, uint16_t *y, uint16_t *z) {
  uint8_t tmp_h;
  uint8_t tmp_l;
  // read x
  IIC_ReadData(SELF_ADD, 0x3b, &tmp_h);
  IIC_ReadData(SELF_ADD, 0x3c, &tmp_l);
  *x = 0;
  *x |= (tmp_h << 8);
  *x |= (tmp_l);

  // read y
  IIC_ReadData(SELF_ADD, 0x3d, &tmp_h);
  IIC_ReadData(SELF_ADD, 0x3e, &tmp_l);
  *y = 0;
  *y |= (tmp_h << 8);
  *y |= (tmp_l);

  // read z
  IIC_ReadData(SELF_ADD, 0x3f, &tmp_h);
  IIC_ReadData(SELF_ADD, 0x40, &tmp_l);
  *z = 0;
  *z |= (tmp_h << 8);
  *z |= (tmp_l);
}
