#include "stm32f4xx.h"                  // Device header

int main(){
	
	//A and G port's clocks enabled
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN | RCC_AHB1ENR_GPIOAEN;
	
	//PG13 setted as OUTPUT
	GPIOG->MODER |= GPIO_MODER_MODE13_0;	//PG13 setted as OUTPUT
	
	while(1){
	
		if(GPIOA->IDR & GPIO_IDR_ID0)
			//Turn the led on
			GPIOG->BSRR |= GPIO_BSRR_BS13;
		
		else
			//Turn the led off
			GPIOG->BSRR |= GPIO_BSRR_BR13;
	}
}

