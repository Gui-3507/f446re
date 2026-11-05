#include <stdint.h>
#include "../core/clock/clock.h"

#define GPIOA			0x40020000
#define GPIOA_MODDER	*(volatile uint32_t *)(GPIOA)
#define GPIOA_ODR		*(volatile uint32_t *)(GPIOA + 0x14)    

int main(void){

	// inicio dos clock
	init_clock();
	init_ms();

	// configurando o pino do LED 
	GPIOA_MODDER |= 1<<10;

	int ant = 0;
	int now = 0;
	int ms_led_interval = 200;

	// variaveis usadas para o led 1
	while(1){
		
		// piscar o led com ms()
		now = ms();
		if ((now - ant) > ms_led_interval) {
			GPIOA_ODR ^= 1<<5;
			ant = now;
		}

	}

}
