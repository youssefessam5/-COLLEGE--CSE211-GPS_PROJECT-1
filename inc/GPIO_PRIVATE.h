/*************************************************
*
* FILE: GPIO_PRIVATE.h
*
* AUTHOR: EMBEDDED SYSTEMS TEAM 44
*
* DATE: 30/5/2021
*
* DESCRIPTION: Registers of GPIO TM4C123
*
**************************************************/

#include "STD_TYPES.h"

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

/* 		BASE ADDRESSES 			*/

#define GPIOA_BASE  		0x40058000
#define GPIOB_BASE			0x40059000
#define GPIOC_BASE  		0x4005A000
#define GPIOD_BASE 			0x4005B000
#define GPIOE_BASE			0x4005C000
#define GPIOF_BASE  		0x4005D000

/* 		GPIOA REGISTERS 		*/

#define GPIOA_DATA 			*((volatile uint32*)(GPIOA_BASE + 0x000))
#define GPIOA_DIR 			*((volatile uint32*)(GPIOA_BASE + 0x400))
#define GPIOA_AFSEL			*((volatile uint32*)(GPIOA_BASE + 0x420))
#define GPIOA_PUR			*((volatile uint32*)(GPIOA_BASE + 0x510))
#define GPIOA_PDR			*((volatile uint32*)(GPIOA_BASE + 0x514))
#define GPIOA_DEN			*((volatile uint32*)(GPIOA_BASE + 0x51C))
#define GPIOA_LOCK			*((volatile uint32*)(GPIOA_BASE + 0x520))
#define GPIOA_CR			*((volatile uint32*)(GPIOA_BASE + 0x524))
#define GPIOA_AMSEL			*((volatile uint32*)(GPIOA_BASE + 0x528))
#define GPIOA_PCTL			*((volatile uint32*)(GPIOA_BASE + 0x52C))

/* 		GPIOB REGISTERS 		*/

#define GPIOB_DATA 			*((volatile uint32*)(GPIOB_BASE + 0x000))
#define GPIOB_DIR 			*((volatile uint32*)(GPIOB_BASE + 0x400))
#define GPIOB_AFSEL			*((volatile uint32*)(GPIOB_BASE + 0x420))
#define GPIOB_PUR			*((volatile uint32*)(GPIOB_BASE + 0x510))
#define GPIOB_PDR			*((volatile uint32*)(GPIOB_BASE + 0x514))
#define GPIOB_DEN			*((volatile uint32*)(GPIOB_BASE + 0x51C))
#define GPIOB_LOCK			*((volatile uint32*)(GPIOB_BASE + 0x520))
#define GPIOB_CR			*((volatile uint32*)(GPIOB_BASE + 0x524))
#define GPIOB_AMSEL			*((volatile uint32*)(GPIOB_BASE + 0x528))
#define GPIOB_PCTL			*((volatile uint32*)(GPIOB_BASE + 0x52C))

/* 		GPIOC REGISTERS 		*/

#define GPIOC_DATA  		*((volatile uint32*)(GPIOC_BASE + 0x000))
#define GPIOC_DIR   		*((volatile uint32*)(GPIOC_BASE + 0x400))
#define GPIOC_AFSEL 		*((volatile uint32*)(GPIOC_BASE + 0x420))
#define GPIOC_PUR   		*((volatile uint32*)(GPIOC_BASE + 0x510))
#define GPIOC_PDR   		*((volatile uint32*)(GPIOC_BASE + 0x514))
#define GPIOC_DEN   		*((volatile uint32*)(GPIOC_BASE + 0x51C))
#define GPIOC_AMSEL 		*((volatile uint32*)(GPIOC_BASE + 0x528))
#define GPIOC_LOCK  		*((volatile uint32*)(GPIOC_BASE + 0x520))
#define GPIOC_CR    		*((volatile uint32*)(GPIOC_BASE + 0x524))
#define GPIOC_PCTL  		*((volatile uint32*)(GPIOC_BASE + 0x52C))

/* 		GPIOD REGISTERS 		*/

#define GPIOD_DATA 			*((volatile uint32*)(GPIOD_BASE + 0x000))
#define GPIOD_DIR 			*((volatile uint32*)(GPIOD_BASE + 0x400))
#define GPIOD_AFSEL			*((volatile uint32*)(GPIOD_BASE + 0x420))
#define GPIOD_PUR			*((volatile uint32*)(GPIOD_BASE + 0x510))
#define GPIOD_PDR			*((volatile uint32*)(GPIOD_BASE + 0x514))
#define GPIOD_DEN			*((volatile uint32*)(GPIOD_BASE + 0x51C))
#define GPIOD_LOCK			*((volatile uint32*)(GPIOD_BASE + 0x520))
#define GPIOD_CR			*((volatile uint32*)(GPIOD_BASE + 0x524))
#define GPIOD_AMSEL			*((volatile uint32*)(GPIOD_BASE + 0x528))
#define GPIOD_PCTL			*((volatile uint32*)(GPIOD_BASE + 0x52C))

/* 		GPIOE REGISTERS 		*/

#define GPIOE_DATA 			*((volatile uint32*)(GPIOE_BASE + 0x000))
#define GPIOE_DIR 			*((volatile uint32*)(GPIOE_BASE + 0x400))
#define GPIOE_AFSEL 		*((volatile uint32*)(GPIOE_BASE + 0x420))
#define GPIOE_PUR 			*((volatile uint32*)(GPIOE_BASE + 0x510))
#define GPIOE_PDR 			*((volatile uint32*)(GPIOE_BASE + 0x514))
#define GPIOE_DEN 			*((volatile uint32*)(GPIOE_BASE + 0x51C))
#define GPIOE_LOCK 			*((volatile uint32*)(GPIOE_BASE + 0x520))
#define GPIOE_CR 			*((volatile uint32*)(GPIOE_BASE + 0x524))
#define GPIOE_AMSEL 		*((volatile uint32*)(GPIOE_BASE + 0x528))
#define GPIOE_PCTL 			*((volatile uint32*)(GPIOE_BASE + 0x52C))


/* 		GPIOF REGISTERS 		*/

#define GPIOF_DATA 			*((volatile uint32*)(GPIOF_BASE + 0x000))
#define GPIOF_DIR 			*((volatile uint32*)(GPIOF_BASE + 0x400))
#define GPIOF_AFSEL 		*((volatile uint32*)(GPIOF_BASE + 0x420))
#define GPIOF_PUR 			*((volatile uint32*)(GPIOF_BASE + 0x510))
#define GPIOF_PDR 			*((volatile uint32*)(GPIOF_BASE + 0x514))
#define GPIOF_DEN 			*((volatile uint32*)(GPIOF_BASE + 0x51C))
#define GPIOF_LOCK 			*((volatile uint32*)(GPIOF_BASE + 0x520))
#define GPIOF_CR 			*((volatile uint32*)(GPIOF_BASE + 0x524))
#define GPIOF_AMSEL 		*((volatile uint32*)(GPIOF_BASE + 0x528))
#define GPIOF_PCTL 			*((volatile uint32*)(GPIOF_BASE + 0x52C))

#endif
