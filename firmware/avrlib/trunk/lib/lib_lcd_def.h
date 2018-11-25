/**
 * @file		avrlib/trunk/lib/lib_lcd_def.h
 *
 * @brief		Library Lcd Defines.
 *
 * This file includes Library Lcd Defines.
 *
 * @author		© Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
 *
 * @date		$Date: 2011-09-04 15:19:34 +0200 (So, 04 Sep 2011) $
 *
 * @version		$Rev: 4782 $
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





#ifndef LIB_LCD_DEF_H_
	#define LIB_LCD_DEF_H_



	#define LIB_LCD_BOOTUP_MS					15
	#define LIB_LCD_ENABLE_US					1
	#define LIB_LCD_WRITEDATA_US				46
	#define LIB_LCD_COMMAND_US					42
	#define LIB_LCD_SOFT_RESET_MS1				5
	#define LIB_LCD_SOFT_RESET_MS2				1
	#define LIB_LCD_SOFT_RESET_MS3				1
	#define LIB_LCD_SET_4BITMODE_MS				5
	#define LIB_LCD_CLEAR_DISPLAY_MS			2
	#define LIB_LCD_CURSOR_HOME_MS				2



	#define LIB_LCD_DDADR_LINE1					0x00
	#define LIB_LCD_DDADR_LINE2					0x40
	#define LIB_LCD_DDADR_LINE3					0x10
	#define LIB_LCD_DDADR_LINE4					0x50



	// Clear Display -------------- 0b00000001
	#define LIB_LCD_CLEAR_DISPLAY				0x01



	// Cursor Home ---------------- 0b0000001x
	#define LIB_LCD_CURSOR_HOME					0x02



	// Set Entry Mode ------------- 0b000001xx
	#define LIB_LCD_SET_ENTRY					0x04
		#define LIB_LCD_ENTRY_DECREASE				0x00
		#define LIB_LCD_ENTRY_INCREASE				0x02
		#define LIB_LCD_ENTRY_NOSHIFT				0x00
		#define LIB_LCD_ENTRY_SHIFT					0x01



	// Set Display ---------------- 0b00001xxx
	#define LIB_LCD_SET_DISPLAY					0x08
		#define LIB_LCD_DISPLAY_OFF					0x00
		#define LIB_LCD_DISPLAY_ON					0x04
		#define LIB_LCD_CURSOR_OFF					0x00
		#define LIB_LCD_CURSOR_ON					0x02
		#define LIB_LCD_BLINKING_OFF				0x00
		#define LIB_LCD_BLINKING_ON					0x01



	// Set Shift ------------------ 0b0001xxxx
	#define LIB_LCD_SET_SHIFT					0x10
		#define LIB_LCD_CURSOR_MOVE					0x00
		#define LIB_LCD_DISPLAY_SHIFT				0x08
		#define LIB_LCD_SHIFT_LEFT					0x00
		#define LIB_LCD_SHIFT_RIGHT					0x04



	// Set Function --------------- 0b001xxxxx
	#define LIB_LCD_SET_FUNCTION				0x20
		#define LIB_LCD_FUNCTION_4BIT				0x00
		#define LIB_LCD_FUNCTION_8BIT				0x10
		#define LIB_LCD_FUNCTION_1LINE				0x00
		#define LIB_LCD_FUNCTION_2LINE				0x08
		#define LIB_LCD_FUNCTION_5X7				0x00
		#define LIB_LCD_FUNCTION_5X10				0x04



	#define LIB_LCD_SOFT_RESET					0x30



	// Set CG RAM Address --------- 0b01xxxxxx  (Character Generator RAM)
	#define LIB_LCD_SET_CGADR					0x40
	#define LIB_LCD_GC_CHAR0						0
	#define LIB_LCD_GC_CHAR1						1
	#define LIB_LCD_GC_CHAR2						2
	#define LIB_LCD_GC_CHAR3						3
	#define LIB_LCD_GC_CHAR4						4
	#define LIB_LCD_GC_CHAR5						5
	#define LIB_LCD_GC_CHAR6						6
	#define LIB_LCD_GC_CHAR7						7



	// Set DD RAM Address --------- 0b1xxxxxxx  (Display Data RAM)
	#define LIB_LCD_SET_DDADR					0x80



#endif /* LIB_LCD_DEF_H_ */
