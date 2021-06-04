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
