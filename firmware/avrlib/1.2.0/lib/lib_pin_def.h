/**
 * @file		avrlib/trunk/lib/lib_pin_def.h
 *
 * @brief		Library Pin Defines.
 *
 * This file includes Library Pin Defines.
 *
 * @author		© Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
 *
 * @date		$Date: 2011-07-10 14:38:43 +0200 (So, 10 Jul 2011) $
 *
 * @version		$Rev: 4495 $
 *
 * @note
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version. \n
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details. \n
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see http:*www.gnu.org/licenses. \n
 */





#ifndef LIB_PIN_DEF_H_
	#define LIB_PIN_DEF_H_



	#define A									0b00001000
	#define B									0b00010000
	#define C									0b00011000
	#define D									0b00100000
	#define E									0b00101000
	#define F									0b00110000
	#define G									0b00111000

	#define PULLUP								0b01000000



	#define LIB_PIN_OUTPUT_TRISTATE				0x00
	#define LIB_PIN_OUTPUT_LOW					0x01
	#define LIB_PIN_OUTPUT_HIGH					0x03

	#define LIB_PIN_INPUT						0x00
	#define LIB_PIN_INPUT_PULLUP				0x02



#endif /* LIB_PIN_DEF_H_ */
