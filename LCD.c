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


