#include "TM4C123.h"

void port_A(void){
	GPIOA ->DATA = 0x02 ;
	GPIOA ->DEN = 0x02 ;
}

void port_B(void){
	
}