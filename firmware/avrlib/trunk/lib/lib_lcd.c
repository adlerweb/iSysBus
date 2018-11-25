/**
 * @file		avrlib/trunk/lib/lib_lcd.c
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





#ifndef LIB_LCD_C_
	#define LIB_LCD_C_



	void Lib_Lcd_Enable() {

		LIB_LCD_PORT |= (1 << LIB_LCD_EN);
		_delay_us(LIB_LCD_ENABLE_US);
		LIB_LCD_PORT &= ~(1 << LIB_LCD_EN);

	}



	void Lib_Lcd_Out(uint8_t data) {

		data &= 0xF0;
		LIB_LCD_PORT &= ~(0xF0 >> (4 - LIB_LCD_DB));
		LIB_LCD_PORT |= (data >> (4 - LIB_LCD_DB));
		Lib_Lcd_Enable();

	}



	void Lib_Lcd_Init(void) {

		uint8_t pins = (0x0F << LIB_LCD_DB) | (1 << LIB_LCD_RS) | (1 << LIB_LCD_EN);
		LIB_LCD_DDR |= pins;
		LIB_LCD_PORT &= ~pins;
		_delay_ms(LIB_LCD_BOOTUP_MS);

		Lib_Lcd_Out(LIB_LCD_SOFT_RESET);
		_delay_ms(LIB_LCD_SOFT_RESET_MS1);
		Lib_Lcd_Enable();
		_delay_ms(LIB_LCD_SOFT_RESET_MS2);
		Lib_Lcd_Enable();
		_delay_ms(LIB_LCD_SOFT_RESET_MS3);

		Lib_Lcd_Out(LIB_LCD_SET_FUNCTION | LIB_LCD_FUNCTION_4BIT);
		_delay_ms(LIB_LCD_SET_4BITMODE_MS);

		Lib_Lcd_Cmd(LIB_LCD_SET_FUNCTION | LIB_LCD_FUNCTION_4BIT | LIB_LCD_FUNCTION_2LINE | LIB_LCD_FUNCTION_5X7);

		Lib_Lcd_Cmd(LIB_LCD_SET_DISPLAY | LIB_LCD_DISPLAY_ON | LIB_LCD_CURSOR_OFF | LIB_LCD_BLINKING_OFF);

		Lib_Lcd_Cmd(LIB_LCD_SET_ENTRY | LIB_LCD_ENTRY_INCREASE | LIB_LCD_ENTRY_NOSHIFT);

		Lib_Lcd_Clear();

	}



	void Lib_Lcd_Clear(void) {

		Lib_Lcd_Cmd(LIB_LCD_CLEAR_DISPLAY);
		_delay_ms(LIB_LCD_CLEAR_DISPLAY_MS);

	}



	void Lib_Lcd_Home(void) {

		Lib_Lcd_Cmd(LIB_LCD_CURSOR_HOME);
		_delay_ms(LIB_LCD_CURSOR_HOME_MS);

	}



	void Lib_Lcd_SetCursor(uint8_t spalte, uint8_t zeile) {

		uint8_t data;
		switch (zeile) {
			case 1:
				data = LIB_LCD_SET_DDADR + LIB_LCD_DDADR_LINE1 + spalte;
				break;
			case 2:
				data = LIB_LCD_SET_DDADR + LIB_LCD_DDADR_LINE2 + spalte;
				break;
			case 3:
				data = LIB_LCD_SET_DDADR + LIB_LCD_DDADR_LINE3 + spalte;
				break;
			case 4:
				data = LIB_LCD_SET_DDADR + LIB_LCD_DDADR_LINE4 + spalte;
				break;
			default:
				return;
		}
		Lib_Lcd_Cmd(data);

	}



	void Lib_Lcd_Data(uint8_t data) {

		LIB_LCD_PORT |= (1 << LIB_LCD_RS);
		Lib_Lcd_Out(data);
		Lib_Lcd_Out(data << 4);
		_delay_us(LIB_LCD_WRITEDATA_US);

	}



	void Lib_Lcd_String(const char *data) {

		while (*data != '\0') {
			Lib_Lcd_Data(*data++);
		}

	}



	void Lib_Lcd_GenerateChar(uint8_t code, const uint8_t *data) {

		Lib_Lcd_Cmd(LIB_LCD_SET_CGADR | (code << 3));
		for (uint8_t i = 0; i < 8; i++) {
			Lib_Lcd_Data( data[i] );
		}

	}



	void Lib_Lcd_Cmd(uint8_t data) {

		LIB_LCD_PORT &= ~(1 << LIB_LCD_RS);
		Lib_Lcd_Out(data);
		Lib_Lcd_Out(data << 4);
		_delay_us(LIB_LCD_COMMAND_US);

	}



#endif /* LIB_LCD_C_ */
