#include "MCO.h"
#include <stdint.h>

// using standard lib
void DEBUG_MCO() {
  RCC_CFGR &= ~(uint32_t)(0x3 << 30); // MCO2 choose PLL
  RCC_CFGR |= (uint32_t)(0x3 << 30);
  RCC_CFGR |= (uint32_t)(1 << 29);
  RCC_AHB1ENR &= ~(uint32_t)(1 << 2); // GPIOC enable
  RCC_AHB1ENR |= (uint32_t)(1 << 2);
  GPIOC_MODER &= ~(uint32_t)(0x3 << 18); // GPIOC_9
  GPIOC_MODER |= (uint32_t)(1 << 19);
  GPIOC_OSPEEDR &= ~(uint32_t)(0x3 << 18); // GPIOC_9 50MHz speed
  GPIOC_OSPEEDR |= (uint32_t)(1 << 19);
}
