/**
 *Reset and Clock Control (RCC) peripheral.
 *
 * @author Salma Mohammed Hamed
 * @date 1 Feb 2024
 * @version V01
 *
*/
#ifndef __RCC_PRIVATE_H__
#define __RCC_PRIVATE_H__
#include "STD_TYPES.h"
/*registers definition*/
/*choose processor clk*/
#define RCC_CR     			*((volatile u32 *)0x40021000)
#define RCC_CFGR     		*((volatile u32 *)0x40021004)
/***************************/
#define RCC_CIR				*((volatile u32 *)0X40021008)
#define RCC_APB2RSTR	    *((volatile u32 *)0X4002100C)
#define RCC_APB1RSTR		*((volatile u32 *)0X40021010)
/*priphrals clk*/
#define RCC_AHBENR			*((volatile u32 *)0X40021014) //for clock, enable and disable the clock on the different peripherals
#define RCC_APB1ENR			*((volatile u32 *)0X4002101C) //for clock, enable and disable the clock on the different peripherals
#define RCC_APB2ENR			*((volatile u32 *)0X40021018) //for clock, enable and disable the clock on the different peripherals
/********************************/
#define RCC_BDCR			*((volatile u32 *)0X40021020)
#define RCC_CSR				*((volatile u32 *)0X40021024) 
/*****************Clk types*****************/
#define 	RCC_HSE_CRYSTAL 0
#define	    RCC_HSE_RC      1
#define 	RCC_HSI         2
#define 	RCC_PLL         3

/*****************PLL options***************/
#define RCC_PLL_IN_HSI_DIV_2    0
#define	RCC_PLL_IN_HSE_DIV_2    1 
#define RCC_PLL_IN_HSE          2

/*Important bits*/
#define RCC_HSIRDY_BIT			1
#define RCC_HSERDY_BIT			17
#define RCC_PLLRDY_BIT			25


#endif /**< __RCC_PRIVATE_H__ */
