#ifndef GPIO_H_
#define GPIO_H_

//DATA
void vGPIODATA_WRITE(uint8 PORT, uint8 DATA);
void vGPIODATA_SET(uint8 PORT, uint8 bit);
void vGPIODATA_RESET(uint8 PORT, uint8 bit);
//DIR
void vGPIODIR_SET(uint8 PORT, uint8 VALUE);
void vGPIODIR_RESET(uint8 PORT, uint8 VALUE);
//DEN
void vGPIODEN_SET(uint8 PORT, uint8 VALUE);
void vGPIODEN_RESET(uint8 PORT, uint8 VALUE);
//AFSEL
void vGPIOAFSEL_RESET(uint8 PORT, uint8 VALUE);
void vGPIOAFSEL_SET(uint8 PORT, uint8 VALUE);
//PUR
void vGPIOPUR_SET (uint8 PORT,uint8 VALUE);
void vGPIOPUR_RESET (uint8 PORT,uint8 VALUE);
//CR
void vGPIOCR_RESET(uint8 PORT, uint8 VALUE);
void vGPIOCR_SET(uint8 PORT, uint8 VALUE);
//PCTL
void vGPIOPCTL_SET(uint8 PORT, uint8 PIN, uint8 VALUE);
void vGPIOPCTL_RESET(uint8 PORT, uint8 PIN, uint8 VALUE);
//LOCK
void vGPIOLOCK_RESET(uint8 PORT);
void vGPIOLOCK_SET(uint8 PORT);
//AMSEL
void vGPIOAMSEL_SET(uint8 PORT, uint8 VALUE);
void vGPIOAMSEL_RESET(uint8 PORT, uint8 VALUE);

#endif
