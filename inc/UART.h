#ifndef UART_H_
#define UART_H_

// Tx and Rx available
uint8 UART_TxAvailable(uint8 PORT);
uint8 UART_RxAvailable(uint8 PORT);
//CTL
void vUARTCTL_SET(uint8 PORT, uint16 VALUE);
void vUARTCTL_RESET(uint8 PORT,uint16 VALUE);
//IBRD
void vUARTIBRD_WRITE(uint8 PORT, uint16 VALUE);
//FBRD
void vUARTFBRD_WRITE(uint8 PORT, uint8 VALUE);
//LCRH
void vUARTLCRH_WRITE(uint8 PORT,uint8 VALUE);
uint8 u8UART_Receive(void);

#endif

