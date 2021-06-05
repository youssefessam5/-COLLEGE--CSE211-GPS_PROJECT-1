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
																														//AT END OF THE CODE TO PRINT THE DISTANCE WE HAVE CALCULATED
		while(1){ // WHILE LOOP TO UPDATE DISTANCE AND CHECKS IT
			//UPDATE ENDING POINT
			// UPDATE DISTANCE
			vLED_WRITE(distance); // TAKES 5 SECONDS TO FINISH
			distance++;
			if(distance >= 100){
				vGPIODATA_WRITE(GPIOF, 0X02); 										// LIGHT UP THE RED LED
				break;
			}
		}
		while(1){ // KEEP WRITING 100
			vLED_WRITE(distance); 																	// SHOULD LIGHT UP 393
		}
}
