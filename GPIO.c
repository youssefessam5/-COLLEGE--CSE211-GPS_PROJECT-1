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
void vGPIOLOCK_SET(uint8 PORT){
	switch(PORT){
		case GPIOA:
			GPIO_PORTA_LOCK_R =  0x4C4F434B;
			break;

		case GPIOB:
			GPIO_PORTB_LOCK_R =  0x4C4F434B;
			break;

		case GPIOC:
			GPIO_PORTC_LOCK_R =  0x4C4F434B;
			break;

		case GPIOD:
			GPIO_PORTD_LOCK_R =  0x4C4F434B;
			break;

		case GPIOE:
			GPIO_PORTE_LOCK_R =  0x4C4F434B;
			break;

		case GPIOF:
			GPIO_PORTF_LOCK_R =  0x4C4F434B;
			break;
	}
}

void vGPIOLOCK_RESET(uint8 PORT){
	switch(PORT){
		case GPIOA:
			GPIO_PORTA_LOCK_R =  0x01;
			break;

		case GPIOB:
			GPIO_PORTB_LOCK_R =  0x01;
			break;

		case GPIOC:
			GPIO_PORTC_LOCK_R =  0x01;
			break;

		case GPIOD:
			GPIO_PORTD_LOCK_R =  0x01;
			break;

		case GPIOE:
			GPIO_PORTE_LOCK_R =  0x01;
			break;

		case GPIOF:
			GPIO_PORTF_LOCK_R =  0x01;
			break;
	}
}

void vGPIOAMSEL_SET(uint8 PORT, uint8 VALUE){
    switch(PORT){
        case GPIOA:
            GPIO_PORTA_AMSEL_R |= VALUE;
            break;
        case GPIOB:
            GPIO_PORTB_AMSEL_R |= VALUE;
            break;
        case GPIOC:
            GPIO_PORTC_AMSEL_R |= VALUE;
            break;
        case GPIOD:
            GPIO_PORTD_AMSEL_R |= VALUE;
            break;
        case GPIOE:
            GPIO_PORTE_AMSEL_R |= VALUE;
            break;
        case GPIOF:
            GPIO_PORTF_AMSEL_R |= VALUE;
            break;
    }
}

void vGPIOAMSEL_RESET(uint8 PORT, uint8 VALUE){
    switch(PORT){
        case GPIOA:
            CLEAR_BITS(GPIO_PORTA_AMSEL_R, VALUE, 0);
            break;
        case GPIOB:
            CLEAR_BITS(GPIO_PORTB_AMSEL_R, VALUE, 0);
            break;
        case GPIOC:
            CLEAR_BITS(GPIO_PORTC_AMSEL_R, VALUE, 0);
            break;
        case GPIOD:
            CLEAR_BITS(GPIO_PORTD_AMSEL_R, VALUE, 0);
            break;
        case GPIOE:
            CLEAR_BITS(GPIO_PORTE_AMSEL_R, VALUE, 0);
            break;
        case GPIOF:
            CLEAR_BITS(GPIO_PORTF_AMSEL_R, VALUE, 0);
            break;
    }
}

void vGPIODEN_RESET(uint8 PORT, uint8 VALUE){
    switch(PORT){
        case GPIOA:
            CLEAR_BITS(GPIO_PORTA_DEN_R, VALUE, 0);
            break;
        case GPIOB:
            CLEAR_BITS(GPIO_PORTB_DEN_R, VALUE, 0);
            break;
        case GPIOC:
            CLEAR_BITS(GPIO_PORTC_DEN_R, VALUE, 0);
            break;
        case GPIOD:
            CLEAR_BITS(GPIO_PORTD_DEN_R, VALUE, 0);
            break;
        case GPIOE:
            CLEAR_BITS(GPIO_PORTE_DEN_R, VALUE, 0);
            break;
        case GPIOF:
            CLEAR_BITS(GPIO_PORTF_DEN_R, VALUE, 0);
            break;
    }
}

void vGPIOAFSEL_RESET(uint8 PORT, uint8 VALUE){
    switch(PORT){
        case GPIOA:
            GPIO_PORTA_AFSEL_R &=~ VALUE;
            break;
        case GPIOB:
            GPIO_PORTB_AFSEL_R &=~ VALUE;
            break;
        case GPIOC:
            GPIO_PORTC_AFSEL_R &=~ VALUE;
            break;
        case GPIOD:
            GPIO_PORTD_AFSEL_R &=~ VALUE;
            break;
        case GPIOE:
            GPIO_PORTE_AFSEL_R &=~ VALUE;
            break;
        case GPIOF:
            GPIO_PORTF_AFSEL_R &=~ VALUE;
            break;
    }
}
void vGPIOAFSEL_SET(uint8 PORT, uint8 VALUE){
    switch(PORT){
        case GPIOA:
            GPIO_PORTA_AFSEL_R |= VALUE;
            break;
        case GPIOB:
            GPIO_PORTB_AFSEL_R |= VALUE;
            break;
        case GPIOC:
            GPIO_PORTC_AFSEL_R |= VALUE;
            break;
        case GPIOD:
            GPIO_PORTD_AFSEL_R |= VALUE;
            break;
        case GPIOE:
            GPIO_PORTE_AFSEL_R |= VALUE;
            break;
        case GPIOF:
            GPIO_PORTF_AFSEL_R |= VALUE;
            break;
    }
}
void vGPIODIR_SET(uint8 PORT, uint8 VALUE){
	switch(PORT){
		case GPIOA:
			SET_BITS(GPIO_PORTA_DIR_R, VALUE, 0);
			break;
		case GPIOB:
			SET_BITS(GPIO_PORTB_DIR_R, VALUE, 0);
			break;
		case GPIOC:
			SET_BITS(GPIO_PORTC_DIR_R, VALUE, 0);
			break;
		case GPIOD:
			SET_BITS(GPIO_PORTD_DIR_R, VALUE, 0);
			break;
		case GPIOE:
			SET_BITS(GPIO_PORTE_DIR_R, VALUE, 0);
			break;
		case GPIOF:
			SET_BITS(GPIO_PORTF_DIR_R, VALUE, 0);
			break;
	}
}

void vGPIODIR_RESET(uint8 PORT, uint8 VALUE){
	switch(PORT){
		case GPIOA:
			CLEAR_BITS(GPIO_PORTA_DIR_R, VALUE, 0);
			break;
		case GPIOB:
			CLEAR_BITS(GPIO_PORTB_DIR_R, VALUE, 0);
			break;
		case GPIOC:
			CLEAR_BITS(GPIO_PORTC_DIR_R, VALUE, 0);
			break;
		case GPIOD:
			CLEAR_BITS(GPIO_PORTD_DIR_R, VALUE, 0);
			break;
		case GPIOE:
			CLEAR_BITS(GPIO_PORTE_DIR_R, VALUE, 0);
			break;
		case GPIOF:
			CLEAR_BITS(GPIO_PORTF_DIR_R, VALUE, 0);
			break;
	}
}

void vGPIODEN_SET(uint8 PORT, uint8 VALUE){
    switch(PORT){
        case GPIOA:
            GPIO_PORTA_DEN_R |= VALUE;
            break;
        case GPIOB:
            GPIO_PORTB_DEN_R |= VALUE;
            break;
        case GPIOC:
            GPIO_PORTC_DEN_R |= VALUE;
            break;
        case GPIOD:
            GPIO_PORTD_DEN_R |= VALUE;
            break;
        case GPIOE:
            GPIO_PORTE_DEN_R |= VALUE;
            break;
        case GPIOF:
            GPIO_PORTF_DEN_R |= VALUE;
            break;
    }
}

void vGPIOCR_RESET(uint8 PORT, uint8 VALUE){
    switch(PORT){
        case GPIOA:
           GPIO_PORTA_CR_R &= ~VALUE;
            break;
        case GPIOB:
           GPIO_PORTB_CR_R &= ~VALUE;
            break;
        case GPIOC:
            GPIO_PORTC_CR_R &= ~VALUE;
            break;
        case GPIOD:
            GPIO_PORTD_CR_R &= ~VALUE;
            break;
        case GPIOE:
           GPIO_PORTE_CR_R &= ~VALUE;
            break;
        case GPIOF:
           GPIO_PORTF_CR_R &= ~VALUE;
            break;
    }
}


void vGPIOCR_SET(uint8 PORT, uint8 VALUE){
    switch(PORT){
        case GPIOA:
          GPIO_PORTA_CR_R |= VALUE;
            break;
        case GPIOB:
           GPIO_PORTB_CR_R |= VALUE;
            break;
        case GPIOC:
           GPIO_PORTC_CR_R |= VALUE;
            break;
        case GPIOD:
           GPIO_PORTD_CR_R |= VALUE;
            break;
        case GPIOE:
           GPIO_PORTE_CR_R |= VALUE;
            break;
        case GPIOF:
           GPIO_PORTF_CR_R |= VALUE;
            break;
    }
}

void vGPIOPCTL_SET(uint8 PORT, uint8 PIN, uint8 VALUE){
	switch(PORT){
		case GPIOA:
			SET_BITS(GPIO_PORTA_PCTL_R, VALUE, 4*PIN);
			break;
		case GPIOB:
			SET_BITS(GPIO_PORTB_PCTL_R, VALUE, 4*PIN);
			break;
		case GPIOC:
			SET_BITS(GPIO_PORTC_PCTL_R, VALUE, 4*PIN);
			break;
		case GPIOD:
			SET_BITS(GPIO_PORTD_PCTL_R, VALUE, 4*PIN);
			break;
		case GPIOE:
			SET_BITS(GPIO_PORTE_PCTL_R, VALUE, 4*PIN);
			break;
		case GPIOF:
			SET_BITS(GPIO_PORTF_PCTL_R, VALUE, 4*PIN);
			break;
	}
}void vGPIOPCTL_RESET(uint8 PORT, uint8 PIN, uint8 VALUE){
	switch(PORT){
		case GPIOA:
			CLEAR_BITS(GPIO_PORTA_PCTL_R, VALUE, 4*PIN);
			break;
		case GPIOB:
			CLEAR_BITS(GPIO_PORTB_PCTL_R, VALUE, 4*PIN);
			break;
		case GPIOC:
			CLEAR_BITS(GPIO_PORTC_PCTL_R, VALUE, 4*PIN);
			break;
		case GPIOD:
			CLEAR_BITS(GPIO_PORTD_PCTL_R, VALUE, 4*PIN);
			break;
		case GPIOE:
			CLEAR_BITS(GPIO_PORTE_PCTL_R, VALUE, 4*PIN);
			break;
		case GPIOF:
			CLEAR_BITS(GPIO_PORTF_PCTL_R, VALUE, 4*PIN);
			break;
	}
}

void vGPIOPUR_SET (uint8 PORT,uint8 VALUE){

	switch(PORT){
    case GPIOA:
		GPIO_PORTA_PUR_R |= VALUE;
		break;

    case GPIOB:
		GPIO_PORTB_PUR_R |= VALUE;
		break;

    case GPIOC:
		GPIO_PORTC_PUR_R |= VALUE;
		break;

    case GPIOD:
		GPIO_PORTE_PUR_R |= VALUE;
		break;

    case GPIOE:
		GPIO_PORTD_PUR_R |= VALUE;
		break;

    case GPIOF:
		GPIO_PORTF_PUR_R |= VALUE;
		break;
    }
}



void vGPIOPUR_RESET (uint8 PORT,uint8 VALUE){
	switch(PORT){
		case GPIOA:
			CLEAR_BITS(GPIO_PORTA_PUR_R,VALUE,0);
			break;
		case GPIOB:
			CLEAR_BITS(GPIO_PORTB_PUR_R,VALUE,0);
			break;
		case GPIOC:
			CLEAR_BITS(GPIO_PORTC_PUR_R,VALUE,0);
			break;
		case GPIOD:
			CLEAR_BITS(GPIO_PORTD_PUR_R,VALUE,0);
			break;
		case GPIOE:
			CLEAR_BITS(GPIO_PORTE_PUR_R,VALUE,0);
			break;
		case GPIOF:
			CLEAR_BITS(GPIO_PORTF_PUR_R,VALUE,0);
			break;
	}
}


