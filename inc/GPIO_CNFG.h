#ifndef GPIO_CNFGH
#define GPIO_CNFGH

/* USER DEFINED MACROS /

/ MACROS FOR PORT /

#define GPIOA 0
#define GPIOB 1
#define GPIOC 2
#define GPIOD 3
#define GPIOE 4
#define GPIOF 5

/ MACROS FOR PCTL /

#define GPIO 0x0
#define UART 0x1
#define SSI0 0x2
#define JTAG 0x1
/* MACROS FOR 7 segemnt display */

#define DG1 5 // PORT B7
//#define DG2 1
//#define DG3 2
#define DG2 6 //PORT C5
#define DG3 7 // PORT C6
/* MACROS FOR MARGIN */

#define MAX_DISTANCE 100
#define MAX_MARGIN 2
#define MARGIN_ERROR MAX_DISTANCE - MAX_MARGIN

#endif

