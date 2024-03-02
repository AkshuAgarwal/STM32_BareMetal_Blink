#include <stdint.h>

#define RCC_APB2ENR *((uint32_t *)0x40021018)
#define GPIOC_CRH   *((uint32_t *)0x40011004)
#define GPIOC_ODR   *((uint32_t *)0x4001100C)

#define RCC_APB2ENR_IOPCEN  1 << 4
#define GPIOC_CRH_MODE13    1 << 20
#define GPIOC_ODR_13        1 << 13

void delay(uint32_t time) {
  for (int i = 0; i < time; i++) {
    for (int j = 0; j < time; j++) {
      __asm__("nop");
    }
  }
}

int main(void) {
  RCC_APB2ENR |= RCC_APB2ENR_IOPCEN;
  GPIOC_CRH &= ~(GPIOC_CRH_MODE13);
  GPIOC_CRH |= (GPIOC_CRH_MODE13 << 1);

  for (;;) {
    GPIOC_ODR |= GPIOC_ODR_13;
    delay(1000);
    GPIOC_ODR &= ~(GPIOC_ODR_13);
    delay(1000);
  }

  return 0;
}

