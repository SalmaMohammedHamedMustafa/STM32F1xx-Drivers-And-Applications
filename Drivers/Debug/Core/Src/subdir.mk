################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/AFIO_program.c \
../Core/Src/EXTI_program.c \
../Core/Src/Functions.c \
../Core/Src/GPIO_program.c \
../Core/Src/Lcd_Program.c \
../Core/Src/Led_Programe.c \
../Core/Src/NVIC_program.c \
../Core/Src/OS_program.c \
../Core/Src/RCC_program.c \
../Core/Src/STP_program.c \
../Core/Src/Switch_Program.c \
../Core/Src/SysTick_program.c \
../Core/Src/main.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c 

OBJS += \
./Core/Src/AFIO_program.o \
./Core/Src/EXTI_program.o \
./Core/Src/Functions.o \
./Core/Src/GPIO_program.o \
./Core/Src/Lcd_Program.o \
./Core/Src/Led_Programe.o \
./Core/Src/NVIC_program.o \
./Core/Src/OS_program.o \
./Core/Src/RCC_program.o \
./Core/Src/STP_program.o \
./Core/Src/Switch_Program.o \
./Core/Src/SysTick_program.o \
./Core/Src/main.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o 

C_DEPS += \
./Core/Src/AFIO_program.d \
./Core/Src/EXTI_program.d \
./Core/Src/Functions.d \
./Core/Src/GPIO_program.d \
./Core/Src/Lcd_Program.d \
./Core/Src/Led_Programe.d \
./Core/Src/NVIC_program.d \
./Core/Src/OS_program.d \
./Core/Src/RCC_program.d \
./Core/Src/STP_program.d \
./Core/Src/Switch_Program.d \
./Core/Src/SysTick_program.d \
./Core/Src/main.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103x6 -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/AFIO_program.cyclo ./Core/Src/AFIO_program.d ./Core/Src/AFIO_program.o ./Core/Src/AFIO_program.su ./Core/Src/EXTI_program.cyclo ./Core/Src/EXTI_program.d ./Core/Src/EXTI_program.o ./Core/Src/EXTI_program.su ./Core/Src/Functions.cyclo ./Core/Src/Functions.d ./Core/Src/Functions.o ./Core/Src/Functions.su ./Core/Src/GPIO_program.cyclo ./Core/Src/GPIO_program.d ./Core/Src/GPIO_program.o ./Core/Src/GPIO_program.su ./Core/Src/Lcd_Program.cyclo ./Core/Src/Lcd_Program.d ./Core/Src/Lcd_Program.o ./Core/Src/Lcd_Program.su ./Core/Src/Led_Programe.cyclo ./Core/Src/Led_Programe.d ./Core/Src/Led_Programe.o ./Core/Src/Led_Programe.su ./Core/Src/NVIC_program.cyclo ./Core/Src/NVIC_program.d ./Core/Src/NVIC_program.o ./Core/Src/NVIC_program.su ./Core/Src/OS_program.cyclo ./Core/Src/OS_program.d ./Core/Src/OS_program.o ./Core/Src/OS_program.su ./Core/Src/RCC_program.cyclo ./Core/Src/RCC_program.d ./Core/Src/RCC_program.o ./Core/Src/RCC_program.su ./Core/Src/STP_program.cyclo ./Core/Src/STP_program.d ./Core/Src/STP_program.o ./Core/Src/STP_program.su ./Core/Src/Switch_Program.cyclo ./Core/Src/Switch_Program.d ./Core/Src/Switch_Program.o ./Core/Src/Switch_Program.su ./Core/Src/SysTick_program.cyclo ./Core/Src/SysTick_program.d ./Core/Src/SysTick_program.o ./Core/Src/SysTick_program.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32f1xx_hal_msp.cyclo ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_it.cyclo ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.cyclo ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su

.PHONY: clean-Core-2f-Src

