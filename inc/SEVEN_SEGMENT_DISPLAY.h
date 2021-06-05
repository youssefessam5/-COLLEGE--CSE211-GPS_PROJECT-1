#ifndef seven_segment_display_H_
#define seven_segment_display_H_

#include "STD_TYPES.h"

//To choose which display of the three will work
void vDISPLAY_ENABLE(uint8 DISNUM);
void vDISPLAY_DISABLE(uint8 DISNUM);
//To choose which digit to appear from 0-9
void vDIGIT_NUMBER(uint8 NUMBER);
//INSERT A NUMBER TO DISPLAY ON LED
void vLED_WRITE(uint16 NUM);


#endif
