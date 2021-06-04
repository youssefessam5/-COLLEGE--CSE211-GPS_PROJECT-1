#include "inc/tm4c123gh6pm.h"
#include "inc/STD_TYPES.h"
#include "inc/GPIO_CNFG.h"
#include "inc/GPIO.h"

//DG1=12 PIN C5
//DG2=9  PIN C6
//DG3=8  PIN C7

void vDISPLAY_ENABLE(uint8 DISNUM){
	switch(DISNUM){
		case DG1:
			vGPIODATA_RESET(GPIOC, DG1);
			break;
		case DG2:
			vGPIODATA_RESET(GPIOC, DG2);
			break;
		case DG3:
			vGPIODATA_RESET(GPIOC, DG3);
			break;
	}
}

void vDISPLAY_DISABLE(uint8 DISNUM){
	switch(DISNUM){
		case DG1:
			vGPIODATA_SET(GPIOC, DG1);
			break;
		case DG2:
			vGPIODATA_SET(GPIOC, DG2);
			break;
		case DG3:
			vGPIODATA_SET(GPIOC, DG3);
			break;
	}
}
void vLED_WRITE(uint16 NUM){
	int count = 0;
	int Number = 0;
	int remainder = 0;
	while(1){
		count = 10000;
		Number = NUM;
		remainder = Number % 100;
		Number = Number - remainder;
		if(Number >= 100){
			vDISPLAY_ENABLE(DG1);
			vDISPLAY_DISABLE(DG2);
			vDISPLAY_DISABLE(DG3);
			vDIGIT_NUMBER((int)(Number / 100));
		}
