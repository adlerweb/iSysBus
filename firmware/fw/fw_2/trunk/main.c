/**
 * @file		fw/fw_2/trunk/main.c
 *
 * @brief		Firmware.
 *
 * This file includes the Firmware.
 *
 * @author		© Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
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



#define USE_AVRLIB_ISB



#include <trunk/core/isb_fw_dummy.h>



const uint8_t Isb_Firmware_Code[4] = { 0x02, 0x00, 0x00, 0x00 };



#define ISB_IF_CAN__0 1
#if ISB_IF_CAN__0 == TRUE
	#define ISB_IF_CAN__0_CLOCK 8000000
	#define ISB_IF_CAN__0_SPEED 50000
	#define ISB_IF_CAN__0_SS PORTB_PIN4
	#define ISB_IF_CAN__0_RS NONE
	#define ISB_IF_CAN__0_INT INTERRUPT2
	#define ISB_IF_CAN__0_MODE LIB_MCP2515__MODE_NORMAL
#endif /* ISB_IF_CAN__0 == TRUE */



#include <trunk/core/isb_fw_dummy.c>