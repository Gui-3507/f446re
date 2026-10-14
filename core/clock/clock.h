#include <stdint.h>

// Lista de registradores para configuração do clock
//  + RCC clock control register : RCC_CR
#define RCC	    	0x40023800
#define RCC_RC 		*(volatile uint32_t *)(RCC)
#define RCC_CFGR	*(volatile uint32_t *)(RCC + 0x08)
#define RCC_AHB1ENR	*(volatile uint32_t *)(RCC + 0x30)

//  + Systick 
#define STK		    0xE000E010
#define STK_CTRL	*(volatile uint32_t *)(STK)
#define STK_LOAD	*(volatile uint32_t *)(STK + 0x04)
#define STK_VAL		*(volatile uint32_t *)(STK + 0x08)

// Lista de funções
void init_clock();
void delay_ms(uint16_t x);
