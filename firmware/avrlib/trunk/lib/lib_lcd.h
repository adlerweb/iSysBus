/**
 * @file		avrlib/trunk/lib/lib_lcd.h
 *
 * @brief		Library Lcd.
 *
 * This file includes Library Lcd.
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





#ifndef LIB_LCD_H_
	#define LIB_LCD_H_



	void Lib_Lcd_Init(void);
	void Lib_Lcd_Clear(void);
	void Lib_Lcd_Home(void);
	void Lib_Lcd_SetCursor(uint8_t spalte, uint8_t zeile);
	void Lib_Lcd_Data(uint8_t data);
	void Lib_Lcd_String(const char *data);
	void Lib_Lcd_GenerateChar(uint8_t code, const uint8_t *data);
	void Lib_Lcd_Cmd(uint8_t data);



#endif /* LIB_LCD_H_ */
