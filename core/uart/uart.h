#include <stdint.h>

// registers
#define USART2          0x4000 4400
#define USART2_ST       *(volatile uint32_t *)(USART2)
#define USART2_DR       *(volatile uint32_t *)(USART2 + 0x04)
#define USART2_BRR      *(volatile uint32_t *)(USART2 + 0x08)
#define USART2_CR1      *(volatile uint32_t *)(USART2 + 0x0C)
#define USART2_CR2      *(volatile uint32_t *)(USART2 + 0x10)
#define USART2_CR3      *(volatile uint32_t *)(USART2 + 0x14)
