#include "inc/STD_TYPES.h"
#include "inc/tm4c123gh6pm.h"
#include "inc/GPIO_CNFG.h"

void vGPIODATA_WRITE(uint8 PORT, uint8 VALUE){
	switch(PORT){
		case GPIOA:
			GPIO_PORTA_DATA_R = VALUE;
			break;
		case GPIOB:
			GPIO_PORTB_DATA_R = VALUE;
			break;
		case GPIOC:
			GPIO_PORTC_DATA_R = VALUE;
			break;
		case GPIOD:
			GPIO_PORTD_DATA_R = VALUE;
			break;
		case GPIOE:
			GPIO_PORTE_DATA_R = VALUE;
			break;
		case GPIOF:
			GPIO_PORTF_DATA_R = VALUE;
			break;
	}
}

void vGPIODATA_SET(uint8 PORT, uint8 bit){
	switch(PORT){
		case GPIOA:
			SET_BIT(GPIO_PORTA_DATA_R, bit);
			break;
		case GPIOB:
			SET_BIT(GPIO_PORTB_DATA_R, bit);
			break;
		case GPIOC:
			SET_BIT(GPIO_PORTC_DATA_R, bit);
			break;
		case GPIOD:
			SET_BIT(GPIO_PORTD_DATA_R, bit);
			break;
		case GPIOE:
			SET_BIT(GPIO_PORTE_DATA_R, bit);
			break;
		case GPIOF:
			SET_BIT(GPIO_PORTF_DATA_R, bit);
			break;
	}
}

void vGPIODATA_RESET(uint8 PORT, uint8 bit){
	switch(PORT){
		case GPIOA:
			CLEAR_BIT(GPIO_PORTA_DATA_R, bit);
			break;
		case GPIOB:
			CLEAR_BIT(GPIO_PORTB_DATA_R, bit);
			break;
		case GPIOC:
			CLEAR_BIT(GPIO_PORTC_DATA_R, bit);
			break;
		case GPIOD:
			CLEAR_BIT(GPIO_PORTD_DATA_R, bit);
			break;
		case GPIOE:
			CLEAR_BIT(GPIO_PORTE_DATA_R, bit);
			break;
		case GPIOF:
			CLEAR_BIT(GPIO_PORTF_DATA_R, bit);
			break;
	}
	
}
