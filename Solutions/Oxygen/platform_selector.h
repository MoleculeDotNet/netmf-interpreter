/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This file is part of the Microsoft .NET Micro Framework Porting Kit Code Samples and is unsupported. 
// Copyright (c) Microsoft Open Technologies, Inc. All rights reserved.
// 
// Licensed under the Apache License, Version 2.0 (the "License"); you may not use these files except in compliance with the License.
// You may obtain a copy of the License at:
// 
// http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing
// permissions and limitations under the License.
// 
// Based on the Implementation for (STM32F4) by Oberon microsystems, Inc.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _PLATFORM_Oxygen_SELECTOR_H_
#define _PLATFORM_Oxygen_SELECTOR_H_ 1

/////////////////////////////////////////////////////////
//
// processor and features
//

#if defined(PLATFORM_ARM_Oxygen)
#define HAL_SYSTEM_NAME "Oxygen"

#define PLATFORM_ARM_STM32F4 1 // STM32F411 cpu

//#define USB_ALLOW_CONFIGURATION_OVERRIDE 1

//
// processor and features
//
/////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////
//
// constants
//

#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2
#define GPIO_PORTD 3
#define GPIO_PORTE 4
#define GPIO_PORTF 5
#define GPIO_PORTG 6
#define GPIO_PORTH 7
#define GPIO_PORTI 8

#define PORT_PIN(port,pin) ( ( (int)port) * 16 + ( pin ) )

#define SYSTEM_CLOCK_HZ                 96000000
#define SYSTEM_CYCLE_CLOCK_HZ           96000000   // 84MHz
#define SYSTEM_APB1_CLOCK_HZ            48000000   // 42MHz
#define SYSTEM_APB2_CLOCK_HZ            96000000   // 84MHz
#define SYSTEM_CRYSTAL_CLOCK_HZ         12000000   // 12MHz external clock
#define SUPPLY_VOLTAGE_MV               3300       // 3.3V supply

#define CLOCK_COMMON_FACTOR             1000000    // GCD(SYSTEM_CLOCK_HZ, 1M)

#define SLOW_CLOCKS_PER_SECOND          1000000
#define SLOW_CLOCKS_TEN_MHZ_GCD         1000000    // GCD(SLOW_CLOCKS_PER_SECOND, 10M)
#define SLOW_CLOCKS_MILLISECOND_GCD     1000       // GCD(SLOW_CLOCKS_PER_SECOND, 1k)

#define FLASH_MEMORY_Base   0x08000000
#define FLASH_MEMORY_Size   0x00080000
#define SRAM1_MEMORY_Base   0x20000000
#define SRAM1_MEMORY_Size   0x00020000

#define PLATFORM_DEPENDENT_RX_USART_BUFFER_SIZE	1024

#define TXPROTECTRESISTOR               RESISTOR_DISABLED
#define RXPROTECTRESISTOR               RESISTOR_DISABLED
#define CTSPROTECTRESISTOR              RESISTOR_DISABLED
#define RTSPROTECTRESISTOR              RESISTOR_DISABLED

#define TOTAL_GPIO_PORT                 3 // PA - PC
#define TOTAL_GPIO_PINS                 (TOTAL_GPIO_PORT*16)

#define INSTRUMENTATION_H_GPIO_PIN      GPIO_PIN_NONE

#define TOTAL_USART_PORT                2
#define USART_DEFAULT_PORT              COM1
#define USART_DEFAULT_BAUDRATE          115200

#define DEBUG_TEXT_PORT    USB1
#define STDIO              USB1
#define DEBUGGER_PORT      USB1
#define MESSAGING_PORT     USB1

#define TOTAL_USB_CONTROLLER            1  // Silicon has 2, but only one supported in this port at this time...
#define USB_MAX_QUEUES                  3  // 3 endpoints (EP0 + 2)

#define TOTAL_SOCK_PORT                 0

// System Timer Configuration
#define STM32F4_32B_TIMER 5
#define STM32F4_16B_TIMER 1

// Pin Configuration
#define STM32F4_ADC 1
#define STM32F4_AD_CHANNELS {0,1,2,3,4,8,9,10,11,12,13} // PA0-PA4,PB0-PB1,PC0-PC3

#define STM32F4_PWM_TIMER {3,3,3,4,4,4,3}
#define STM32F4_PWM_CHNL  {2,3,0,0,2,3,1}
#define STM32F4_PWM_PINS  {16,17,20,22,24,25, 7} //PB0 pb1 PB4 PB6 PB8 PB9 pa7

#define STM32F4_SPI_SCLK_PINS {5, 29} // PA5, PB13
#define STM32F4_SPI_MISO_PINS {6, 30} // PA6, PB14
#define STM32F4_SPI_MOSI_PINS {7, 31} // PA7, PB15

#define STM32F4_I2C_PORT     1
#define STM32F4_I2C_SCL_PIN  PORT_PIN( GPIO_PORTB, 8 ) // PB8
#define STM32F4_I2C_SDA_PIN  PORT_PIN( GPIO_PORTB, 9 ) // PB9

#define STM32F4_UART_RXD_PINS {10,  3} // PA10, PA3
#define STM32F4_UART_TXD_PINS { 9,  2} // PA9,  PA2
#define STM32F4_UART_CTS_PINS {11,  0} // PA11, PA0
#define STM32F4_UART_RTS_PINS {12,  1} // PA12, PA1

// User LEDs
#define LED0 PORT_PIN(GPIO_PORTA, 13) // PA13 user led

// TinyBooter entry using GPIO
//#define TINYBOOTER_ENTRY_GPIO_PIN       PORT_PIN(GPIO_PORTA, 0) // 'User' button
//#define TINYBOOTER_ENTRY_GPIO_STATE     TRUE                    // Active high
//#define TINYBOOTER_ENTRY_GPIO_RESISTOR  RESISTOR_DISABLED       // No internal resistor, there is external pull-down (R39)

//
// constants
/////////////////////////////////////////////////////////

#include <processor_selector.h>

#endif // PLATFORM_ARM_Oxygen
#endif // _PLATFORM_Oxygen_SELECTOR_H_
