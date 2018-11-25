/**
 * @file		fw/fw_9/1.0/main.c
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



#include <1.1.0/core/isb_fw_dummy.h>



const uint8_t Isb_Firmware_Code[4] = { 0x09, 0x00, 0x01, 0x00 };



#include <1.1.0/core/isb_fw_dummy.c>
