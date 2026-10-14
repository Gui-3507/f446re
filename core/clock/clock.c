#include <stdint.h>
#include "clock.h"

// numero de ciclos no systick a cada 1ms
#define Systick_1ms	16000000/8/1000	

// criar a função init_clock 
void init_clock(){

	// começar por verificar o HSI
	if (!(RCC_RC & 1)) RCC_RC |= 1;
	while(!(RCC_RC & 1<<1));
	
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
