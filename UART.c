#include "inc/STD_TYPES.h"
#include "inc/tm4c123gh6pm.h"
#include "inc/GPIO_CNFG.h"
#include "inc/UART_CNFG.h"

uint8 UART_TxAvailable(uint8 PORT){
	
	switch(PORT){
		case UART0:
			return((UART0_FR_R & 0x0020) != 0);
		case UART1:
			return((UART1_FR_R & 0x0020) != 0);;
		case UART2:
			return((UART2_FR_R & 0x0020) != 0);
		case UART3:
			return((UART3_FR_R & 0x0020) != 0);
		case UART4:
			return((UART4_FR_R & 0x0020) != 0);
		case UART5:
			return((UART5_FR_R & 0x0020) != 0);
		case UART6:
			return((UART6_FR_R & 0x0020) != 0);	
	  case UART7:
			return((UART7_FR_R & 0x0020) != 0);
		default:
			return 0;
		}	
}
void vUARTIBRD_WRITE(uint8 PORT, uint16 VALUE){

	switch(PORT){
		case UART0:
			UART0_IBRD_R = VALUE;
			break;
		case UART1:
			UART1_IBRD_R = VALUE;
			break;
		case UART2:
			UART2_IBRD_R = VALUE;
			break;
		case UART3:
			UART3_IBRD_R = VALUE;
			break;
		case UART4:
			UART4_IBRD_R = VALUE;
			break;
		case UART5:
			UART5_IBRD_R = VALUE;
			break;
		case UART6:
			UART6_IBRD_R = VALUE;
			break;	
	    case UART7:
			UART7_IBRD_R = VALUE;
			break;	
	}
}
void vUARTCTL_SET(uint8 PORT, uint16 VALUE){
	
	switch(PORT){
		case UART0:
			SET_BITS(UART0_CTL_R, VALUE, 0);
			break;
		case UART1:
			SET_BITS(UART1_CTL_R, VALUE, 0);
			break;
		case UART2:
			SET_BITS(UART2_CTL_R, VALUE, 0);
			break;
		case UART3:
			SET_BITS(UART3_CTL_R, VALUE, 0);
			break;
		case UART4:
			SET_BITS(UART4_CTL_R, VALUE, 0);
			break;
		case UART5:
			SET_BITS(UART5_CTL_R, VALUE, 0);
			break;
		case UART6:
			SET_BITS(UART6_CTL_R, VALUE, 0);
			break;	
	  case UART7:
			SET_BITS(UART7_CTL_R, VALUE, 0);
			break;
			
	}	
}
