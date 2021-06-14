#define LCD_DIS_H_
#ifndef LCD_DIS_H_

//LCD COMMANDS

#define cleardisplay     0x01
#define returnHome       0x02
#define shiftCursorRight	0x06
#define cursorBlink			   0x0F
#define cursorFirstLine			0x80
#define cursorSecondLine		0xC0
#define LCD5x7					0x38


void vLCD_NUMSTRING(uint8* str, uint8 amount, uint16 number);
void vLCD_FIRSTLINE(uint8* str, uint8 amount, uint16 number);
void vLCD_SECONDLINE(uint8* str, uint8 amount, uint16 number);
void vLCD_INT (void);  									//LCD INITIALIZATIONS
void vLCD_CMD(uint8 LCD_COMMAND );						//LCD COMMANDS
void vLCD_DATA(uint8 DATA);	                            //LCD DATA
void vLCD_STRING(uint8* str, uint8 amount);					        // LCD STRING OUTPUT
void DELAY_MILLI(int n);                                // DELAY MILLIS
void DELAY_MICRO(int n);                                // DELAY MICROS

#endif
