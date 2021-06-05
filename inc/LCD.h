#define LCD_DIS_H_
#ifndef LCD_DIS_H_

//LCD COMMANDS

#define clear_display     0x01
#define returnHome        0x02
#define moveCursorRight   0x06
#define moveCursorLeft    0x08
#define shiftDisplayRight 0x1C
#define shiftDisplayLeft  0x18
#define cursorBlink       0x0F
#define cursorOff         0x0C
#define cursorOn          0x0E
#define Function_set_4bit 0x28
#define Function_set_8bit 0x38
#define Entry_mode        0x06
#define Function_8_bit    0x32
#define Set5x7FontSize    0x20
#define FirstRow          0x80



void vLCD_INT (void);               //LCD INITIALIZATIONS
void vLCD_CMD(uint8 LCD_COMMAND );	//LCD COMMANDS
void vLCD_DATA(uint8 DATA);	        //LCD DATA
void vLCD_STRING(char* str);			  // LCD STRING OUTPUT
void DELAY_MILLI(int n);            // DELAY MILLIS
void DELAY_MICRO(int n);            // DELAY MICROS

#endif
