/**
 *GPIO
 *
 * @author Salma Mohammed Hamed
 * @date  6 Feb 2024
 * @version V01
 *
*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void GPIO_voidSetPinDir(u8 Copy_PORT, u8 Copy_PIN, u8 Copy_Mode)
{
	switch(Copy_PORT)
	{
		case GPIO_PORTA:
			if(Copy_PIN < 8)
			{
				GPIOA_CRL_R &= ~((0b1111) << (Copy_PIN * 4));
				GPIOA_CRL_R |= ((Copy_Mode) << (Copy_PIN * 4));
			}
			else if(Copy_PIN < 16)
			{
				Copy_PIN-=8;
				GPIOA_CRH_R &= ~((0b1111) << (Copy_PIN * 4));
			    GPIOA_CRH_R |= ((Copy_Mode) << (Copy_PIN * 4));
			}
			else
			{
				/**< RETURN ERROR STATUS */
			}
		break;
		case GPIO_PORTB:
			if(Copy_PIN < 8)
			{
				GPIOB_CRL_R &= ~((0b1111) << (Copy_PIN * 4));
				GPIOB_CRL_R |= ((Copy_Mode) << (Copy_PIN * 4));
			}
			else if(Copy_PIN < 16)
			{
				Copy_PIN-=8;
				GPIOB_CRH_R &=~ ((0b1111) << (Copy_PIN * 4));
				GPIOB_CRH_R |= ((Copy_Mode) << (Copy_PIN * 4));
			}
			else
			{
				/**< RETURN ERROR STATUS */
			}
		break;
		case GPIO_PORTC:
			if(Copy_PIN < 8)
			{
				GPIOC_CRL_R &=~ ((0b1111) << (Copy_PIN * 4));
				GPIOC_CRL_R |= ((Copy_Mode) << (Copy_PIN * 4));
			}
			else if(Copy_PIN < 16)
			{
				Copy_PIN-=8;
				GPIOC_CRH_R &=~ ((0b1111) << (Copy_PIN * 4));
				GPIOC_CRH_R |= ((Copy_Mode) << (Copy_PIN * 4));
			}
			else
			{
				/**< RETURN ERROR STATUS */
			}
		break;
		default:
			/**< RETURN ERROR STATUS */
		break;
	}
	/**< RETURN ERRORSTATUS */
}

void GPIO_voidSetPinValue(u8 Copy_PORT,u8 Copy_PIN, u8 Copy_Value)
{
	if(Copy_PIN < 16)
	{
		switch(Copy_PORT)
		{
			case GPIO_PORTA:
				if(Copy_Value == HIGH)
				{
					SET_BIT(GPIOA_ODR_R, Copy_PIN);
				}
				else if(Copy_Value == LOW)
				{
					CLR_BIT(GPIOA_ODR_R, Copy_PIN);
				}
				else
				{
					/**< RETURN ERROR STATUS */
				}
			break;
			case GPIO_PORTB:
				if(Copy_Value == HIGH)
				{
					SET_BIT(GPIOB_ODR_R, Copy_PIN);
				}
				else if(Copy_Value == LOW)
				{
					CLR_BIT(GPIOB_ODR_R, Copy_PIN);
				}
				else
				{
					/**< RETURN ERROR STATUS */
				}
			break;
			case GPIO_PORTC:
				if(Copy_Value == HIGH)
				{
					SET_BIT(GPIOC_ODR_R, Copy_PIN);
				}
				else if(Copy_Value == LOW)
				{
					CLR_BIT(GPIOC_ODR_R, Copy_PIN);
				}
				else
				{
					/**< RETURN ERROR STATUS */
				}
			break;
			default:
				/**< RETURN ERROR STATUS */
			break;
		}
	}
	else
	{
		/**< RETURN ERROR STATUS */
	}
	/**< RETURN ERROR STATUS */
}

u8  GPIO_u8GetPinValue(u8 Copy_PORT, u8 Copy_PIN)
{
	u8 Local_u8ReturnPinValue = 0;
	if(Copy_PIN < 16)
	{
		switch(Copy_PORT)
		{
			case GPIO_PORTA: Local_u8ReturnPinValue = GET_BIT(GPIOA_IDR_R, Copy_PIN); break;
			case GPIO_PORTB: Local_u8ReturnPinValue = GET_BIT(GPIOB_IDR_R, Copy_PIN); break;
			case GPIO_PORTC: Local_u8ReturnPinValue = GET_BIT(GPIOC_IDR_R, Copy_PIN); break;
		}
	}
	else
	{
		/**< RETURN ERROR STATUS */
	}
	return Local_u8ReturnPinValue;
}


void GPIO_voidSetPortValue(u8 Copy_PORT ,u32 Copy_Value)
{
	switch(Copy_PORT)
	{
		case GPIO_PORTA: GPIOA_ODR_R=Copy_Value; break;
		case GPIO_PORTB: GPIOB_ODR_R=Copy_Value; break;
		case GPIO_PORTC: GPIOC_ODR_R=Copy_Value; break;
	}
}

void GPIO_voidSetPortDir(u8 Copy_PORT,u32 Copy_DirL,u32 Copy_DirH)
{
	switch(Copy_PORT)
	{
		case GPIO_PORTA: GPIOA_CRL_R=Copy_DirL; GPIOA_CRH_R=Copy_DirH; break;
		case GPIO_PORTB: GPIOB_CRL_R=Copy_DirL; GPIOB_CRH_R=Copy_DirH; break;
		case GPIO_PORTC: GPIOC_CRL_R=Copy_DirL; GPIOC_CRH_R=Copy_DirH; break;
	}
}


