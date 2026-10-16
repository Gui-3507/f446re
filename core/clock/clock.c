#include <stdint.h>
#include "clock.h"

// numero de ciclos no systick a cada 1ms
#define Systick_1ms	SysClk/8/1000	

// variaveis globais
uint32_t ctn_pll = 0;
uint32_t SysClk  = 0;

// criar a função init_clock 
void init_clock(){

	// verifica HSI
	if (!(RCC_CR & 1)) RCC_CR |= 1;
	while(!(RCC_CR & 1<<1));
	SysClk = HSI_clk;

	// ajustando a latencia da memoria para subir o clock
	FLASH_ACR |= 5;
	if((FLASH_ACR & 15)==5){
		// configurando o PLL para 160 MHz (N=160; M=8; P=2)
		if(RCC_PLLCFGR & 1<<22) RCC_PLLCFGR &= ~(1<<22);
		RCC_PLLCFGR &= ~(7<<28 | 3<<16 | 511<<6 | 63);
		RCC_PLLCFGR |= (2<<28) | (160<<6) | (8);
		RCC_PLLCFGR &= ~(3<<16);
		// liga o PLL
		RCC_CR |= (1<<24);
		// ligando overdrive enquant o PLL trava
		RCC_APB1ENR |= 1<<28;
		PWR_CR |= 1<<16;
		while(!(PWR_CSR & 1<<16)){}
		PWR_CR |= 1<<17;
		while(!(PWR_CSR & 1<<17)){}
		// ajustar os divisores para respeitar limite APB preAOB1=4 e preAPB2=2
		RCC_CFGR |= 5<<10 |  4<<13;
		// espera o PLL estabilizar 
		while(!(RCC_CR & 1<<25)){}
		// while(!(RCC_CR & 1<<25)){}
		// {
		// 	STK_CTRL |= 1;
		// 	while(!(STK_CTRL & 1<<16));
		// 	ctn_pll++;
		// 	STK_CTRL &= ~1;	
		// }
		// seleciona o PLL como clock do sistema e atualiza a variavel SysClk
		RCC_CFGR |= 2;
		SysClk = PLLP_clk;
		
	}
	
	// ativar o clock no GPIOA
	RCC_AHB1ENR |= 1; 

	// configurações do systick
	STK_CTRL &= ~(1<<2);
	STK_LOAD = Systick_1ms - 1;
	STK_VAL = 1;

}

// criar a função delay() usando o Systick
void delay_ms(uint16_t x){

	STK_CTRL |= 1;
	for(int i=0; i<x; i++){
		while(!(STK_CTRL & 1<<16));
	}
	STK_CTRL &= ~1;
}
