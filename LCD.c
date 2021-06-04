//test
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
void vLCD_INT (void){
     
	  vGPIOCLOCK_SET(GPIOD);
	  vGPIOCLOCK_SET(GPIOE);
	  vGPIODIR_SET(GPIOD,0xFF );
	  vGPIODIR_SET(GPIOE,0x03 );
	  vGPIODEN_SET(GPIOD,0XFF);
	  vGPIODEN_SET(GPIOE, 0X03);
	  vLCD_CMD(Set5x7FontSize);  
    vLCD_CMD(Function_set_8bit); 
    vLCD_CMD(moveCursorRight); 
    vLCD_CMD(clear_display); 
    vLCD_CMD(cursorBlink); 
 
}


void vLCD_CMD(uint8 COMMAND)
{
	vGPIODATA_WRITE(GPIOE, 0x00);
	vGPIODATA_WRITE(GPIOD, COMMAND);
	vGPIODATA_WRITE(GPIOE, 0x01);
	DELAY_MILLI (0);	 
	vGPIODATA_WRITE(GPIOE, 0x00); 
	  
	
}

void vLCD_DATA(uint8 DATA)
{
	vGPIODATA_WRITE(GPIOE, 0x002);
	vGPIODATA_WRITE(GPIOD, DATA);
	vGPIODATA_WRITE(GPIOE, 0x001);
	DELAY_MICRO(0);	 
	vGPIODATA_WRITE(GPIOE, 0x00); 
	  
	
}

void vLCD_STRING(char* str)
{
	char* input=str;
	uint8 i;
	for ( i=0; i<sizeof(input);i++)
	{
      vLCD_DATA(*(input+i))	;
	    DELAY_MICRO(0);	 
	}

}

// PIN D0   D0
// PIN D1   D1
// PIN D2   D2
// PIN D3   D3
// PIN D4   D4
// PIN D5   D5
// PIN D6   D6
// PIN D7   D7
// PIN E0   E
// PIN E1   RS
// PIN E2   RW

