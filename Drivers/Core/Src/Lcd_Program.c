/*
 * Lcd_Program.c
 *
 *  Created on: Sep 15, 2023
 *      Author: salma
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "definition.h"
#include "Special_Functions.h"
#include "GPIO_interface.h"
#include "SysTick_interface.h"
#include "Lcd_Interface.h"
#include "Lcd_Private.h"
#include "Lcd_config.h"
void LCD_voidSendCommand(u8 command)
{

	//set the RS value as Low (command =>RS =  0 )
		GPIO_voidSetPinValue(Lcd_ControlGroup,Lcd_RsPin,Low);
	//set the RW value as Low (Write  => RW = 0 )
		GPIO_voidSetPinValue(Lcd_ControlGroup,Lcd_RwPin,Low);
	//set the E Value as High (High CLK)
		GPIO_voidSetPinValue(Lcd_ControlGroup,Lcd_EPin,High);
	//Send Command
		GPIO_voidSetPortValue(Lcd_DCGroup,command);
	//Set the E value as Low (Low CLK)
		GPIO_voidSetPinValue(Lcd_ControlGroup,Lcd_EPin,Low);


}

void LCD_voidSendData(u8 data)
{

	//set the RS value as Low (Data =>RS =  1 )
	GPIO_voidSetPinValue(Lcd_ControlGroup,Lcd_RsPin,High);
	//set the RW vlaue as Low (Write  => RW = 0 )
	GPIO_voidSetPinValue(Lcd_ControlGroup,Lcd_RwPin,Low);
	//set the E Value as High (High CLK)
	GPIO_voidSetPinValue(Lcd_ControlGroup,Lcd_EPin,High);
	//Send Data
	GPIO_voidSetPortValue(Lcd_DCGroup,data);
	//Set the E value as Low (Low CLK)
	GPIO_voidSetPinValue(Lcd_ControlGroup,Lcd_EPin,Low);


}


void LCD_voidInit()
{
	//set Direction
	//all portA output
	GPIO_voidSetPinDir(Lcd_ControlGroup, Lcd_RsPin, GPIO_OUTPUT_PP_10MHZ);
	GPIO_voidSetPinDir(Lcd_ControlGroup, Lcd_RwPin, GPIO_OUTPUT_PP_10MHZ);
	GPIO_voidSetPinDir(Lcd_ControlGroup, Lcd_EPin, GPIO_OUTPUT_PP_10MHZ);
	GPIO_voidSetPinDir(Lcd_DCGroup, 0, GPIO_OUTPUT_PP_10MHZ);
	GPIO_voidSetPinDir(Lcd_DCGroup, 1, GPIO_OUTPUT_PP_10MHZ);
	GPIO_voidSetPinDir(Lcd_DCGroup, 2, GPIO_OUTPUT_PP_10MHZ);
	GPIO_voidSetPinDir(Lcd_DCGroup, 3, GPIO_OUTPUT_PP_10MHZ);
	GPIO_voidSetPinDir(Lcd_DCGroup, 4, GPIO_OUTPUT_PP_10MHZ);
	GPIO_voidSetPinDir(Lcd_DCGroup, 5, GPIO_OUTPUT_PP_10MHZ);
	GPIO_voidSetPinDir(Lcd_DCGroup, 6, GPIO_OUTPUT_PP_10MHZ);
	GPIO_voidSetPinDir(Lcd_DCGroup, 7, GPIO_OUTPUT_PP_10MHZ);
	//wait for 30ms
	STK_SetBusyWait(16000000);
	STK_SetBusyWait(16000000);
	STK_SetBusyWait(16000000);
	STK_SetBusyWait(16000000);
	STK_SetBusyWait(16000000);
	STK_SetBusyWait(16000000);
	//sent the Function set
	LCD_voidSendCommand(LCD_Set8Bit2Line5x8);
	//wait for 39us
	STK_SetBusyWait(16000000);
	STK_SetBusyWait(16000000);
	//sent the display
	LCD_voidSendCommand(LCD_8BitCursorBlinkON);
	//wait for 39us
	STK_SetBusyWait(16000000);
	STK_SetBusyWait(16000000);
	//sent the Clear
	LCD_voidSendCommand(LCD_8BitClearDisplay);
	//wait for 1.53ms
	STK_SetBusyWait(16000000);
	STK_SetBusyWait(16000000);
	STK_SetBusyWait(16000000);
	//sent the EntryMode
	LCD_voidSendCommand(LCD_8BitEntryMode1);


}


void LCD_voidSendString(u8 String[])
{
	u8 i = 0 ;
	while(String[i]!='\0')
	{
		LCD_voidSendData(String[i]);
		i++;
	}
}


void LCD_voidSetPos(u8 x, u8 y)
{
	u8 adress;
	if (x==first_line_pos)
	{
		adress=y+first_line_add;
	}
	else if (x==sec_line_pos)
	{
		adress=y+sec_line_add;
	}
	LCD_voidSendCommand(adress|LCD_SetAddressDDRAM);
}

void LCD_voidSpecialCharacter (u8 block_no , u8 *special, u8 x, u8 y)
{
	u8 adress;
	u8 counter;
	adress = block_no*8;
	LCD_voidSendCommand(adress|LCD_SetAddressCGRAM);
	for (counter=0; counter<8;counter++)
	{
		LCD_voidSendData(special[counter]);
	}
	//go back to DDRAM
	LCD_voidSetPos(x,y);
	LCD_voidSendData(block_no);
}

void LCD_voidClear()
{
	LCD_voidSendCommand(LCD_8BitClearDisplay);
	//wait for 1.53ms
	delay(2);
}
void LCD_voidSendNumber(s32 num) {
    s8 counter;
    u8 length = 0;
    u8 StringStart = 0;
    u8 IsNegative = 0;
    u8 str[20];

    if (num < 0) {
        num = -num;
        IsNegative = 1;
        StringStart = 1;
        str[0] = '-';
        length++;
    }

    u32 temp_num = num;
    do {
        temp_num /= 10;
        length++;
    } while (temp_num > 0);

    for (counter = length - 1; counter >= StringStart; counter--) {
        str[counter] = num % 10 + '0';
        num /= 10;
    }
    str[length] = '\0';
    LCD_voidSendString(str);
}




