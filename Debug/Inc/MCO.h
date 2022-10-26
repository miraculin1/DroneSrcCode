#ifndef __MCO_H
#define __MCO_H

//  register definition begin
#define RCC_BASE        (uint32_t)0x40023800
#define RCC_CR          *(uint32_t*) (RCC_BASE+0x00)
#define RCC_PLLCFGR     *(uint32_t*) (RCC_BASE+0x04)
#define RCC_CFGR        *(uint32_t*) (RCC_BASE+0x08)
#define RCC_CIR         *(uint32_t*) (RCC_BASE+0x0C)
#define RCC_AHB1RSTR    *(uint32_t*) (RCC_BASE+0x10)
#define RCC_AHB2RSTR    *(uint32_t*) (RCC_BASE+0x14)
#define RCC_APB1RSTR    *(uint32_t*) (RCC_BASE+0x20)
#define RCC_APB2RSTR    *(uint32_t*) (RCC_BASE+0x24)
#define RCC_AHB1ENR     *(uint32_t*) (RCC_BASE+0x30)
#define RCC_AHB2ENR     *(uint32_t*) (RCC_BASE+0x34)
#define RCC_APB1ENR     *(uint32_t*) (RCC_BASE+0x40)
#define RCC_APB2ENR     *(uint32_t*) (RCC_BASE+0x44)
#define RCC_AHB1LPENR   *(uint32_t*) (RCC_BASE+0x50)
#define RCC_AHB2LPENR   *(uint32_t*) (RCC_BASE+0x54)
#define RCC_APB1LPENR   *(uint32_t*) (RCC_BASE+0x60)
#define RCC_APB2LPENR   *(uint32_t*) (RCC_BASE+0x64)
#define RCC_BDCR        *(uint32_t*) (RCC_BASE+0x70)
#define RCC_CSR         *(uint32_t*) (RCC_BASE+0x74)
#define RCC_SSCGR       *(uint32_t*) (RCC_BASE+0x80)
#define RCC_PLLI2SCFGR  *(uint32_t*) (RCC_BASE+0x84)
#define RCC_DCKCFGR     *(uint32_t*) (RCC_BASE+0x8C)
//GPIO C
#define GPIOC_BASE      (uint32_t)0x40020800
#define GPIOC_MODER     *(uint32_t*) (GPIOC_BASE+0x00)
#define GPIOC_OTYPER    *(uint32_t*) (GPIOC_BASE+0x04)
#define GPIOC_OSPEEDR   *(uint32_t*) (GPIOC_BASE+0x08)
#define GPIOC_PUPDR     *(uint32_t*) (GPIOC_BASE+0x0C)
#define GPIOC_IDR       *(uint32_t*) (GPIOC_BASE+0x10)
#define GPIOC_ODR       *(uint32_t*) (GPIOC_BASE+0x14)
#define GPIOC_BSRR      *(uint32_t*) (GPIOC_BASE+0x18)
#define GPIOC_LCKR      *(uint32_t*) (GPIOC_BASE+0x1C)
#define GPIOC_AFRL      *(uint32_t*) (GPIOC_BASE+0x20)
#define GPIOC_AFRH      *(uint32_t*) (GPIOC_BASE+0x24)
//GPIO RCC ENABLE
#define RCC_GPIOA_ENR   (uint32_t) (0x001)
#define RCC_GPIOB_ENR   (uint32_t) (0x002)
#define RCC_GPIOC_ENR   (uint32_t) (0x004)
#define RCC_GPIOD_ENR   (uint32_t) (0x008)
#define RCC_GPIOE_ENR   (uint32_t) (0x010)
#define RCC_GPIOF_ENR   (uint32_t) (0x012)
#define RCC_GPIOG_ENR   (uint32_t) (0x014)
#define RCC_GPIOH_ENR   (uint32_t) (0x018)
#define RCC_GPIOI_ENR   (uint32_t) (0x100)

void DEBUG_MCO();

#endif
