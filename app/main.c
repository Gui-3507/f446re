#include <stdint.h>
#include "../core/clock/clock.h"

#define GPIOA			0x40020000
#define GPIOA_MODDER	*(volatile uint32_t *)(GPIOA)
#define GPIOA_ODR		*(volatile uint32_t *)(GPIOA + 0x14)    

int main(void){

	// inicio dos clock
	init_clock();

	// configurando o pino do LED 
	GPIOA_MODDER |= 1<<10;

	while(1){
		
		GPIOA_ODR ^= 1<<5;
		delay_ms(200);

	}

}
