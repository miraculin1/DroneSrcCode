#include "TIM.h"
#include "Delay.h"

// preload / 10 is real val
void setThro(uint16_t percent) {
  TIM3_CCR1 = percent * 5 + 500;
}
static void initPins() {
  RCC_AHB1 |= (0x1 << 2);
  // AF
  GPIOC_MODER |= (0x2 << (2 * 6));
  // very speed
  GPIOC_OSPEEDR |= (0x3 << (2 * 6));
  GPIOC_AF_L |= (0x2 << (4 * 6));
}

void initTIM3PWM() {

  // enable clock
  RCC_APB1 |= (0x1) << 1;

  // TIM running on 84MHz
  TIM3_PSC |= (168 - 1);
  TIM3_ARR = (10000 - 1);

  // ARR preload
  TIM3_CR1 |= (0x1 << 7);
  TIM3_CR1 &= ~(0x1 << 4);

  // config capture/compare mode
  // ch1 ch2 output
  // enable preload
  TIM3_CCMR1 |= (0x1 << 3);
  // set mode pwm1
  TIM3_CCMR1 |= (0x6 << 4);

  // enable capture/compare
  TIM3_CCER |= (0x1 << 0);
  setThro(0);


  initPins();
  // enable Counter
  TIM3_CR1 |= (0x1 << 0);
}

void unlock() {
  initTIM3PWM();
  setThro(0);
  delay_ms(3000);
  setThro(100);
  delay_ms(2000);
}
