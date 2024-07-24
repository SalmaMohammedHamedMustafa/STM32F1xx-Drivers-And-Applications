/*
 * Switch_Interface.h
 *
 *  Created on: Sep 12, 2023
 *      Author: salma
 */

#ifndef HAL_SWITCH_SWITCH_INTERFACE_H_
#define HAL_SWITCH_SWITCH_INTERFACE_H_

#ifndef HAL_SWITCH_SWITDH_INTERFACE_H_
#define HAL_SWITCH_SWITDH_INTERFACE_H_
#include "STD_TYPES.h"
#include "Switch_Config.h"

void SWITCH_voidInit (u8 Group, u8 pin);
u8 SWITCH_u8GetValue (u8 Group, u8 pin);
#endif /* HAL_SWITCH_SWITDH_INTERFACE_H_ */


#endif /* HAL_SWITCH_SWITCH_INTERFACE_H_ */
