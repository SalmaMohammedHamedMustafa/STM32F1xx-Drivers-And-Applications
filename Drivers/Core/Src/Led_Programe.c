/*
 * Led_Programe.c
 *
 *  Created on: Sep 12, 2023
 *      Author: salma
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "definition.h"
#include "GPIO_interface.h"
#include "Led_Interface.h"
void LED_voidInit (u8 Group, u8 pin)
{
	GPIO_voidSetPinDir(Group, pin, GPIO_OUTPUT_PP_10MHZ);
}

void LED_voidOn (u8 Group, u8 pin)
{
	GPIO_voidSetPinValue(Group, pin, High);
}

void LED_voidOff (u8 Group, u8 pin)
{
	GPIO_voidSetPinValue(Group, pin, Low);
}


