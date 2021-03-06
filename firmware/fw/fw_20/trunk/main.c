/**
 * @file		fw/fw_20/trunk/main.c
 *
 * @brief		Firmware.
 *
 * This file includes the Firmware.
 *
 * @author		� Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
 *
 * @date		$Date$
 *
 * @version		$Rev$
 *
 * @note
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see http:*www.gnu.org/licenses.
 */





#include <stdio.h>



#include <trunk/core/isb_fw_dummy.h>



const uint8_t Isb_Firmware_Code[4] = { 0x14, 0x00, 0x00, 0x00 };



#define ISB_INF_USART0 1
#if ISB_INF_USART0 == 1
	#define ISB_INF_USART0_BAUDRATE 115200
	#define ISB_INF_USART0_STARTBITS 1
	#define ISB_INF_USART0_DATABITS 8
	#define ISB_INF_USART0_PARITY NONE
	#define ISB_INF_USART0_STOPBITS 1
#endif /* ISB_INF_USART0 == 1 */



#define ISB_INF_CAN0 1
#if ISB_INF_CAN0 == 1
	#define ISB_INF_CAN0_CLOCK 4000000
	#define ISB_INF_CAN0_SPEED 50000
	#define ISB_INF_CAN0_SS PORTB_PIN4
	#define ISB_INF_CAN0_RS NONE
	#define ISB_INF_CAN0_INT INTERRUPT2
	#define ISB_INF_CAN0_MODE LIB_MCP2515_MODE_NORMAL
#endif /* ISB_INF_CAN0 == 1 */



#include <trunk/core/isb_fw_dummy.c>
