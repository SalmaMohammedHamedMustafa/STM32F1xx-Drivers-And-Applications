/*
 * Switch_Program.c
 *
 *  Created on: Sep 12, 2023
 *      Author: salma
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "definition.h"
#include "GPIO_interface.h"
#include "Switch_Interface.h"
#include "Switch_Config.h"
#include "Switch_Private.h"
void SWITCH_voidInit (u8 Group, u8 pin)
{
	GPIO_voidSetPinDir(Group, pin, GPIO_INPUT_PU);
#if SwitchConnection==PullUp
	GPIO_voidSetPinValue(Group,pin,HIGH);
#elif SwitchConnection==PullDown
	GPIO_voidSetPinValue(Group,pin,LOW);
#endif
}

u8 SWITCH_u8GetValue (u8 Group, u8 pin)
{
	return GPIO_u8GetPinValue(Group,pin);
}
