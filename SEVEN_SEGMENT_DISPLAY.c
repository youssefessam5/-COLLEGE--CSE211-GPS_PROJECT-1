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
	if(NUM > 999)
		return;
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
		else{
			vDISPLAY_ENABLE(DG1);
			vDISPLAY_DISABLE(DG2);
			vDISPLAY_DISABLE(DG3);
			vDIGIT_NUMBER((int)(Number / 100));
		}
		while(count--);
		count = 10000;
		Number = remainder;
		remainder = Number % 10;
		Number = Number - remainder;
		if(Number >= 10){
			vDISPLAY_ENABLE(DG2);
			vDISPLAY_DISABLE(DG1);
			vDISPLAY_DISABLE(DG3);
			vDIGIT_NUMBER((int)(Number / 10));
		}
		else{
			vDISPLAY_ENABLE(DG2);
			vDISPLAY_DISABLE(DG1);
			vDISPLAY_DISABLE(DG3);
			vDIGIT_NUMBER((int)(Number / 10));
		}
		while(count--);
		count = 10000;
		Number = remainder;
		vDISPLAY_ENABLE(DG3);
		vDISPLAY_DISABLE(DG1);
		vDISPLAY_DISABLE(DG2);
		vDIGIT_NUMBER((int)Number);
		while(count--);
	}
}

void vDIGIT_NUMBER(uint8 NUMBER){
	switch(NUMBER){
		case 0:
			vGPIODATA_WRITE(GPIOB, 0X3F);
			break;
		case 1:
			vGPIODATA_WRITE(GPIOB, 0X06);
			break;
		case 2:
			vGPIODATA_WRITE(GPIOB, 0XDB);
			break;
		case 3:
			vGPIODATA_WRITE(GPIOB, 0X4F);
			break;
		case 4:
			vGPIODATA_WRITE(GPIOB, 0X66);
			break;
		case 5:
			vGPIODATA_WRITE(GPIOB, 0X6D);	
			break;
		case 6:
			vGPIODATA_WRITE(GPIOB, 0XFD);
			break;
		case 7:
			vGPIODATA_WRITE(GPIOB, 0X07);
			break;
		case 8:
			vGPIODATA_WRITE(GPIOB, 0XFF);
			break;
		case 9:
			vGPIODATA_WRITE(GPIOB, 0XEF);
			break;
	}
}
