/*
 * Switch_Config.h
 *
 *  Created on: Sep 12, 2023
 *      Author: salma
 */

#ifndef HAL_SWITCH_SWITCH_CONFIG_H_
#define HAL_SWITCH_SWITCH_CONFIG_H_
#include "Switch_Private.h"
#define SwitchConnection PullUp
#if SwitchConnection==PullUp
	#define pressed 0
	#define unpressed 1
#elif SwitchConnection==PullDown
	#define pressed 1
	#define unpressed 0
#endif

#endif /* HAL_SWITCH_SWITCH_CONFIG_H_ */
