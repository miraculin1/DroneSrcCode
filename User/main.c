#include "LED.h"
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include <stdint.h>

int main() {
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

  GPIO_InitTypeDef GPIO_InitStruct;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;
  GPIO_InitStruct.GPIO_Speed = GPIO_High_Speed;
  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;

  GPIO_Init(GPIOA, &GPIO_InitStruct);
  GPIO_SetBits(GPIOA, GPIO_Pin_5);
  while (1) {
  }
}
