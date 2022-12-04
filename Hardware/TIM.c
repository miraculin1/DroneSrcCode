#include "TIM.h"
#include "Delay.h"
/*
 * this is the motor file
 * for now only init one motor, but the reset three
 * are exactly the same
 */

// preload / 10 is real val
void setThro1(uint16_t percent) {
  TIM3_CCR1 = percent + 1000;
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
  TIM3_PSC |= (84 - 1);
  TIM3_ARR = (20000 - 1);

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
  setThro1(0);


  initPins();
  // enable Counter
  TIM3_CR1 |= (0x1 << 0);
}

void initUnlockMotot() {
  initTIM3PWM();
  delay_ms(1000);
  setThro1(1000);
  delay_ms(1000);
  setThro1(0);
  delay_ms(2000);
}
