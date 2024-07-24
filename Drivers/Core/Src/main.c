/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Special_Functions.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"
#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "SysTick_interface.h"
#include "Led_Interface.h"
#include "Switch_Interface.h"
#include "STB_interface.h"
#include "STB_config.h"
#include "Lcd_Interface.h"


void main(void)
{

	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,RCC_APP2_IOPA_EN);
	GPIO_voidSetPinDir(STP_SERIAL_DATA, GPIO_OUTPUT_PP_2MHZ);
	GPIO_voidSetPinDir(STP_SHIFT_CLK, GPIO_OUTPUT_PP_2MHZ);
	GPIO_voidSetPinDir(STP_STORAGE_CLK, GPIO_OUTPUT_PP_2MHZ);
	STK_Init();
	STP_voidSendSync(0xAA);

  while (1)
  {

  }

}
