////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//  Implementation for the Oxygen board (STM32F4): Copyright (c) Oberon microsystems, Inc.
//
//  *** Oxygen Board Specific IO Port Initialization ***
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define ARRAY_LENGTH(x)    (sizeof(x)/sizeof(0[x]))

#include <tinyhal.h>
#include "..\..\..\..\DeviceCode\Targets\Native\STM32F4\DeviceCode\stm32f4xx.h"

extern void STM32F4_GPIO_Pin_Config( GPIO_PIN pin, UINT32 mode, GPIO_RESISTOR resistor, UINT32 alternate );    // Workaround, since CPU_GPIO_DisablePin() does not correctly initialize pin speeds

void __section("SectionForBootstrapOperations") BootstrapCode_GPIO()
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN | RCC_AHB1ENR_GPIOCEN;
	CPU_GPIO_SetPinState(0, FALSE); // PC0
	STM32F4_GPIO_Pin_Config(0, 1, RESISTOR_DISABLED, 0);
	CPU_GPIO_SetPinState(0 * 16 + 13, FALSE); // PE11
	STM32F4_GPIO_Pin_Config(0 * 16 + 13, 1, RESISTOR_DISABLED, 0); // general purpose output
	
    CPU_GPIO_EnableOutputPin(LED0, FALSE);
}
