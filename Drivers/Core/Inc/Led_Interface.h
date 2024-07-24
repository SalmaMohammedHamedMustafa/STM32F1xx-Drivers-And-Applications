/*
 * Led_Interface.h
 *
 *  Created on: Sep 12, 2023
 *      Author: salma
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_
#include "STD_TYPES.h"

void LED_voidInit (u8 Group, u8 pin);
void LED_voidOn (u8 Group, u8 pin);
void LED_voidOff (u8 Group, u8 pin);


#endif /* HAL_LED_LED_INTERFACE_H_ */
