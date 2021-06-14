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
uint8* u8GPS_GETDATA(void){
	int i;
	uint8* line;
	do{
		line = u8GPS_GETLINE();
	}while(strncmp(line, "$GPGLL", 6) != 0);
	for(i = 0; i < 82; i++){
		if(line[i] == '$' && i != 0)
			line[i] = '\0';
	}
	return line;
}
