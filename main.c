#include "inc/STD_TYPES.h"
#include "inc/GPIO.h"
#include "inc/GPIO_CNFG.h"
#include "inc/Clock.h"
#include "inc/tm4c123gh6pm.h"
#include "inc/seven_segment_display.h"
#include "inc/UART.h"
#include "inc/UARTINIT.h"
#include "inc/DISTANCE.h"
#include "inc/LCD.h"
#include "inc/GPS.h"
#include <math.h>
#include "inc/PARSING.h"
#include <string.h>

/*******************
*	FOR LCD CONTROL IS A2 A3 A4

*	FOR DATA OF LCD B IS USED

*

*

*********************/

void SystemInit(){
		vUART7_INIT();
	
		vLCD_INT();
	// FOR SEVEN SEGMENT
		vGPIOCLOCK_SET(GPIOE); // ENABLE PORT E
		vGPIODIR_SET(GPIOE, 0x3C); // ENABLE E2, E3, E4, E5 as OUTPUT
		vGPIODEN_SET(GPIOE, 0x3C); // ENABLE E2, E3, E4, E5 as DIGITAL

		// FOR LED IN TIVAC
	  vGPIOCLOCK_SET(GPIOF); 														// CLOCK ENABLES PORTF FOR LEDS
		vGPIODIR_SET(GPIOF, 0x0E);										 		// SETS LEDS TO OUTPUT
		vGPIODEN_SET(GPIOF, 0x0E);											 // SETS LEDS TO DIGITAL
	
		// FOR SEVEN SEGMENT
		vGPIOCLOCK_SET(GPIOC); 												// CLOCK ENABLES PORTD
		vGPIODIR_SET(GPIOC, 0xF0);									 // SET PIN 5 and6 and 7 to OUTPUT
		vGPIODEN_SET(GPIOC, 0xF0);									 // SET PIN 5 and 6 and 7 to DIGITAL
		// FOR 7 SEGMENT
		vGPIOCLOCK_SET(GPIOD); 										// CLOCK ENABLES PORTD
		vGPIODIR_SET(GPIOD, 0x0C); // SET D2 and D3 to OUTPUT
		vGPIODEN_SET(GPIOD, 0x0C); // SET D2 and D3 to DIGITAL
	
		vGPIODATA_SET(GPIOC, 5); 										// INITIALIZES C5 to 1
		vGPIODATA_SET(GPIOC, 6); 										// INITIALIZES C6 to 1
		vGPIODATA_SET(GPIOC, 7); 										// INITIALIZES C7 to 1
}

int main(){
	int trajCount = 0;
	float endLat[20];
	float endLong[20];
	float beginLat;
	float beginLong;
	int distance = 5; 																							// DISTANCE TO BE CALCULATED
	volatile uint8* gpsLine;	
	vGPIODATA_WRITE(GPIOF, 0x08);	// LIGHTS UP GREEN MEANS PROGRAM IS RUNNING
	//vLCD_CMD(cleardisplay); // MUST BE USED BEFORE WRITING AN ACTUAL LINE TO CLEAR PREVIOS TEXT
	//vLCD_FIRSTLINE("LONG: ", 32, 1);
	//vLCD_SECONDLINE("LAT:  ", 32, 1);
//	vLED_WRITE(321);
	gpsLine = u8GPS_GETDATA(); //REDA HYDEHALY
	vLCD_CMD(cleardisplay);
	vLCD_STRING("Starting..", 32);
//	vLCD_CMD(cleardisplay);
//	vLCD_STRING(gpsLine, 32);
	vLCD_CMD(cleardisplay);
	beginLong = fGET_LONGITUDE(gpsLine);
	beginLat = fGET_LATITUDE(gpsLine);
	vLCD_FIRSTLINE("LAT: ", 32, (int)beginLat);
	vLCD_SECONDLINE("LONG: ", 32, (int)beginLong);
//	vLED_WRITE(123);
		//vLED_WRITE0);
	
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
	while(1){ // LOOP TO WRITE LED
		vLED_WRITE(distance);
	}
}
