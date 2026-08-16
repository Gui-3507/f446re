#include <stdint.h>

// funções usadas
int main(void);
void Reset_Handler(void);
void Default_Handler(void);

// variaveis criadas no linker script, endereços de memorias de seções do codigo compilado
extern uint32_t _estack;
extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

// atribuição das funções do vetor de interruções (NVIC)
__attribute__((section(".isr_vector")))
void(*const isr_vector[])(void) = 
{
    (void (*)(void))&_estack,
    Reset_Handler,
    Default_Handler,
    Default_Handler,
};

// função de reset
void Reset_Handler(void)
{
    uint32_t *src;
    uint32_t *dst;

    // iniciando os valores de .data
    src = &_sidata; 
    dst = &_sdata;
    while(dst < &_edata) // lembrar que _edata aponta para o primeiro endereço APOS .data
    {
        *dst++ = *src++;
    }

    // zerando os valores de .bss
    dst = &_sbss;
    while(src < &_ebss)
    {
        *dst++ = 0;
    }

    // chamar a 'main'
    main();

    // no caso da main acabar, chama default handler
    Default_Handler();
    
}


// função defualt
void Default_Handler(void)
{
    while(1);
}
