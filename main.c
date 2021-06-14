#include "inc/STD_TYPES.h"
#include "inc/GPIO.h"
#include "inc/GPIO_CNFG.h"
#include "inc/Clock.h"
#include "inc/tm4c123gh6pm.h"
#include "inc/seven_segment_display.h"
#include "inc/UART.h"
#include "inc/UARTINIT.h"
#include "inc/DISTANCE.h"
#include <math.h>



void SystemInit(){
	  vGPIOCLOCK_SET(GPIOF); 														// CLOCK ENABLES PORTF FOR LEDS
		vGPIODIR_SET(GPIOF, 0x0E);										 		// SETS LEDS TO OUTPUT
		vGPIODEN_SET(GPIOF, 0x0E);											 // SETS LEDS TO DIGITAL
		vGPIOCLOCK_SET(GPIOB); 													// CLOCK ENABLES PORTB
		vGPIODIR_SET(GPIOB, 0xFF);										 // SETS ALL TO OUTPUT
		vGPIODEN_SET(GPIOB, 0xFF);										 // SETS ALL TO DIGITAL
		vGPIOCLOCK_SET(GPIOC); 												// CLOCK ENABLES PORTD
		vGPIODIR_SET(GPIOC, 0xE0);									 // SET PIN 5 and6 and 7 to OUTPUT
		vGPIODEN_SET(GPIOC, 0xE0);									 // SET PIN 5 and 6 and 7 to DIGITAL
		//vGPIOCLOCK_SET(GPIOD); 										// CLOCK ENABLES PORTD
		//vGPIODIR_SET(GPIOD, 0xFF);
		//vGPIODEN_SET(GPIOD, 0xFF);
		vGPIODATA_SET(GPIOC, 5); 										// INITIALIZES C5 to 1
		vGPIODATA_SET(GPIOC, 6); 										// INITIALIZES C6 to 1
		vGPIODATA_SET(GPIOC, 7); 										// INITIALIZES C7 to 1

}

int main(){
		int distance = 96; 																							// DISTANCE TO BE CALCULATED
		vGPIODATA_WRITE(GPIOF, 0x08); 														// LIGHTS UP GREEN MEANS PROGRAM IS RUNNING
		//distance = calc_Distance(20.002,150.000,20.005,150.002); // EXAMPLE DISTANCE SHOULD BE 393 METRES
	
	
	
		while(1){ // LOOP TO CHECK GPS
		gpsLine = u8GPS_GETDATA(); //keep reading from GPS
		endLong[trajCount] = fGET_LONGITUDE(gpsLine);
		endLat[trajCount] = fGET_LATITUDE(gpsLine);
		distance = calc_Distance(beginLat, beginLong, endLat[trajCount], endLong[trajCount]);
		vLCD_CMD(cleardisplay);
		vLCD_FIRSTLINE("LAT: ", 32, (int)endLat[trajCount]);
		vLCD_SECONDLINE("LONG: ", 32, (int)endLong[trajCount]);
		vLED_WRITE(distance);
		trajCount++;
		if(distance >= 100){
			vGPIODATA_WRITE(GPIOF, 0x02);
			vLCD_CMD(cleardisplay);
			vLCD_FIRSTLINE("DISTANCE: ", 32, distance);
			break;
		}
	}
	while(1){ // LOOP TO WRITE LED
		vLED_WRITE(distance);
	}
}

}
