#include <stdint.h>

// Lista de registradores para configuração do clock
//  + variaveis e constantes
#define HSI_clk     16000000
#define PLLP_clk    160000000
// tempo de estabilização do PLL
extern uint32_t ctn_pll;
extern uint32_t SysClk;
//  + Geral 
#define RCC	    	0x40023800
#define RCC_CR 		*(volatile uint32_t *)(RCC)
#define RCC_CFGR	*(volatile uint32_t *)(RCC + 0x08)
#define RCC_AHB1ENR	*(volatile uint32_t *)(RCC + 0x30)
#define RCC_PLLCFGR *(volatile uint32_t *)(RCC + 0x04)
#define RCC_APB1ENR *(volatile uint32_t *)(RCC + 0x40)

//  + Systick 
#define STK		    0xE000E010
#define STK_CTRL	*(volatile uint32_t *)(STK)
#define STK_LOAD	*(volatile uint32_t *)(STK + 0x04)
#define STK_VAL		*(volatile uint32_t *)(STK + 0x08)

//  + FLASH
#define FLASH       0x40023C00
#define FLASH_ACR   *(volatile uint32_t *)(FLASH)

//  + Power
#define PWR         0x40007000
#define PWR_CR      *(volatile uint32_t *)(PWR)
#define PWR_CSR     *(volatile uint32_t *)(PWR + 0x04)

// Lista de funções
void init_clock();
void delay_ms(uint16_t x);
