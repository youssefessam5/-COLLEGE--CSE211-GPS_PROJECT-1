#include "STD_TYPES.h"
#include "GPIO.h"
#include "GPIO_CNFG.h"
#include "Clock.h"
#include "tm4c123gh6pm.h"
#include "LCD.h"

int initial = 0;
void vLCD_INT (void){
     
	//FOR LCD CONTROL
		vGPIOCLOCK_SET(GPIOA); // ENABLE CLOCK FOR A
		vGPIODIR_SET(GPIOA, 0x1C); // ENABLE A2, A3, A4 as OUTPUT
		vGPIODEN_SET(GPIOA, 0x1C); // SET IT TO DIGITAL
	
		// FOR LCD DATA
		vGPIOCLOCK_SET(GPIOB); 													// CLOCK ENABLES PORTB
		vGPIODIR_SET(GPIOB, 0xFF);										 // SETS ALL TO OUTPUT
		vGPIODEN_SET(GPIOB, 0xFF);										 // SETS ALL TO DIGITAL
		
		DELAY_MILLI(20);
		vLCD_CMD(0x30);
		DELAY_MILLI(5);
		vLCD_CMD(0x30);
		DELAY_MICRO(100);
		vLCD_CMD(0x030);
	
		vLCD_CMD(LCD5x7);
		vLCD_CMD(shiftCursorRight);
		vLCD_CMD(cleardisplay);
		vLCD_CMD(cursorBlink);
 
}
void vLCD_STRING(uint8* str, uint8 amount)
{
	uint8* input=str;
	uint8 i;
	for ( i=0; i<amount;i++)
	{
			if(*(input+i) == '\0'){
				return;
			}
			if(*(input+i) == '\n')
				return;
			if(i == 0)
				vLCD_CMD(0x80);
			else if(i == 16)
				vLCD_CMD(0xC0);
      vLCD_DATA(*(input+i)); 
	}

}
void vLCD_FIRSTLINE(uint8* str, uint8 amount, uint16 number){
	int remainder;
	int hundreds;
	int tenth;
	int units;
	uint8 i;
	uint8* input;
	remainder = number % 100;
	hundreds = number - remainder;
	hundreds = hundreds / 100; 
	tenth = remainder;
	remainder = remainder % 10;
	tenth = tenth - remainder;
	tenth = tenth / 10;
	units = remainder;
	input = str;
	for ( i=0; i<amount;i++)
	{
			if(i == 0)
				vLCD_CMD(0x80);
			if(*(input+i) == '\0'){
				break;
			}
			if(*(input+i) == '\n')
				break;
      vLCD_DATA(*(input+i)); 
	}
	if(number != 0){
		vLCD_DATA(hundreds + '0');
		vLCD_DATA(tenth + '0');
		vLCD_DATA(units + '0');
	}
}

void vLCD_SECONDLINE(uint8* str, uint8 amount, uint16 number){
	int remainder;
	int hundreds;
	int tenth;
	int units;
	uint8 i;
	uint8* input;
	remainder = number % 100;
	hundreds = number - remainder;
	hundreds = hundreds / 100; 
	tenth = remainder;
	remainder = remainder % 10;
	tenth = tenth - remainder;
	tenth = tenth / 10;
	units = remainder;
	input = str;
	for ( i=0; i<amount;i++)
	{
			if(i == 0)
				vLCD_CMD(0xC0);
			if(*(input+i) == '\0'){
				break;
			}
			if(*(input+i) == '\n')
				break;
      vLCD_DATA(*(input+i)); 
	}
	if(number != 0){
		vLCD_DATA(hundreds + '0');
		vLCD_DATA(tenth + '0');
		vLCD_DATA(units + '0');
	}
}

void DELAY_MILLI(int n)
{
 int i,j;
 for(i=0;i<n;i++)
 for(j=0;j<3180;j++)
 {}
 
}
 void DELAY_MICRO(int n)
{
 int i,j;
 for(i=0;i<n;i++)
 for(j=0;j<3;j++)
 {}
 
}
void vLCD_CMD(uint8 COMMAND)
{
	// CONTROL PINS
	vGPIODATA_RESET(GPIOA, 3); // RESET RS
	vGPIODATA_RESET(GPIOA, 4); // RESET RW
	vGPIODATA_RESET(GPIOA, 2); //RESET ENABLE
	vGPIODATA_WRITE(GPIOB, COMMAND); // COMMAND
	vGPIODATA_SET(GPIOA, 2); // SET ENABLE
	DELAY_MICRO (0);	 
	vGPIODATA_RESET(GPIOA, 2); // RESET ENABLE
	if(COMMAND < 4)
		DELAY_MILLI(2);
	else
		DELAY_MICRO(40);
}

 

void vLCD_DATA(uint8 DATA)
{
	//SHOULD PLACE
	vGPIODATA_RESET(GPIOA, 4); //RESET RW
	vGPIODATA_RESET(GPIOA, 2); // RESET E
	vGPIODATA_SET(GPIOA, 3); // SET RS
	vGPIODATA_WRITE(GPIOB, DATA);
	vGPIODATA_SET(GPIOA, 2);
	DELAY_MICRO(0);
	vGPIODATA_RESET(GPIOA, 2);
	vGPIODATA_RESET(GPIOA, 3);
	vGPIODATA_RESET(GPIOA, 4);
	DELAY_MICRO(40);
}

