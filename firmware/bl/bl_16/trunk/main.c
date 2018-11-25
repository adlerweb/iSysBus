/**
 * @file		bl/bl_16/trunk/main.c
 *
 * @brief		Bootloader.
 *
 * This file includes the Bootloader.
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



#include <trunk/core/isb_bl.h>



const uint8_t Isb_Bootloader_Code[4] = { 0x10, 0x00, 0x00, 0x00 };



#define ISB_NODE_IDENTIFY PORTC_PIN0



#define ISB_INF CAN0



#if ISB_INF == USART0
	#define ISB_INF_USART0 0
	#define ISB_INF_USART0_BAUDRATE NONE
	#define ISB_INF_USART0_STARTBITS NONE
	#define ISB_INF_USART0_DATABITS NONE
	#define ISB_INF_USART0_PARITY NONE
	#define ISB_INF_USART0_STOPBITS NONE
#endif /* ISB_INF == USART0 */



#if ISB_INF == CAN0
	#define ISB_INF_CAN0 1
	#define ISB_INF_CAN0_CLOCK 4000000
	#define ISB_INF_CAN0_SPEED 50000
	#define ISB_INF_CAN0_SS PORTB_PIN0
	#define ISB_INF_CAN0_RS MCP2515_RX1BF
	#define ISB_INF_CAN0_INT INTERRUPT0
#endif /* ISB_INF == CAN0 */



#include <trunk/core/isb_bl.c>
