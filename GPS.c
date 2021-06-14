#include "inc/STD_TYPES.h"
#include "inc/UART.h"
#include <string.h>

uint8* u8GPS_GETLINE(void){
	int i ;
	uint8 line[82];
	for( i = 0; i < 82; i++){
			line[i] = u8UART_Receive();
	}
	return line;
}

