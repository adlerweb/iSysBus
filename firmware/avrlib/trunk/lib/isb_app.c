/**
 * @file		avrlib/trunk/lib/isb_app.c
 *
 * @brief		iSysBus Application.
 *
 * This file includes iSysBus Application.
 *
 * @author		© Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
 *
 * @date		$Date: 2012-05-07 00:20:12 +0200 (Mo, 07. Mai 2012) $
 *
 * @version		$Rev: 7793 $
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





#ifndef ISB_APP_C_
	#define ISB_APP_C_



	void Isb_App_Init(void)
	{

		#if defined(ISB_APP_LCD_MAX)
// TODO: ->
// TODO: Alles
//char Buffer[20];
Lib_Lcd_Init();
Lib_Lcd_Clear();
Lib_Lcd_String("  ... Init ...  ");
////itoa(AppIndex, Buffer, 10);
////Lcd_String(Buffer);
//			for (uint8_t AppIndex = 0; AppIndex < ISB_APP_LCD_MAX; AppIndex++) {
//				switch (AppIndex) {
//					#if defined(ISB_APP_FLOAT_SENSOR_0)
//						case 0:
//							Isb_App_Float_Sensor[AppIndex].Ch = ISB_APP_FLOAT_SENSOR_0_CH;
//							Isb_App_Float_Sensor[AppIndex].Obj_Sensor = ISB_APP_FLOAT_SENSOR_0_OBJ_SENSOR;
//							break;
//					#endif /* ISB_APP_FLOAT_SENSOR_15 */
//					default:
//						Isb_App_Float_Sensor[AppIndex].Ch = 0xFF;
//						Isb_App_Float_Sensor[AppIndex].Obj_Sensor = 0;
//						break;
//				}
//			}
// TODO: Alles
// TODO: <-
		#endif /* ISB_APP_LCD_MAX */

	}



	void Isb_App_Convert_None(uint16_t Value, void *Destination)
	{

		*(uint16_t *)Destination = Value;

	}



	void Isb_App_Convert_PT100(uint16_t Value, void *Destination)
	{

		Value = Value << 1;
		*(uint16_t *)Destination = Value;

	}



	int32_t Lib_FloatToInteger(uint16_t Float)
	{

		uint32_t Integer = 0;
		uint16_t Exponent = (Float & 0x7C00)>>11;
		uint16_t Mantisse = Float & 0x03FF;

		if (bit_is_set(Float, 15))
		{
			// Positiv
			Integer += Mantisse * (1<<Exponent);
		}
		else
		{
			// Negativ
			Integer -= Mantisse * (1<<Exponent);
		}

		return Integer;

	}



	uint16_t Lib_IntegerToFloat(int32_t Integer)
	{

		uint16_t Float = 0;

		// Vorzeichen
		if (Integer >= 0)
		{
			Float |= 0x8000;
		}

		uint16_t Exponent = 0;
		while (Integer > 2047)
		{
			Exponent++;
			Integer = Integer >> 1;
		}
		Exponent = Exponent << 11;

		Float |= Exponent;
		Float |= (uint16_t)Integer;

		return Float;

	}



	void Isb_App_Exec(void)
	{

		uint8_t Isb_Ch_Ctrl_Get(uint8_t Ch)
		{
			uint8_t Ctrl = 0;
			uint16_t eepAddrCtrl = 0;
			uint16_t eepAddrCrc = 0;
			switch (Ch)
			{
				#if defined(ISB_CH_0)
					case 0:
						eepAddrCtrl = ISB_CH_0_EEADDR_CTRL;
						eepAddrCrc = ISB_CH_0_EEADDR_CRC;
						break;
				#endif /* ISB_CH_0 */
				#if defined(ISB_CH_1)
					case 1:
						eepAddrCtrl = ISB_CH_1_EEADDR_CTRL;
						eepAddrCrc = ISB_CH_1_EEADDR_CRC;
						break;
				#endif /* ISB_CH_1 */
				#if defined(ISB_CH_2)
					case 2:
						eepAddrCtrl = ISB_CH_2_EEADDR_CTRL;
						eepAddrCrc = ISB_CH_2_EEADDR_CRC;
						break;
				#endif /* ISB_CH_2 */
				#if defined(ISB_CH_3)
					case 3:
						eepAddrCtrl = ISB_CH_3_EEADDR_CTRL;
						eepAddrCrc = ISB_CH_3_EEADDR_CRC;
						break;
				#endif /* ISB_CH_3 */
				#if defined(ISB_CH_4)
					case 4:
						eepAddrCtrl = ISB_CH_4_EEADDR_CTRL;
						eepAddrCrc = ISB_CH_4_EEADDR_CRC;
						break;
				#endif /* ISB_CH_4 */
				#if defined(ISB_CH_5)
					case 5:
						eepAddrCtrl = ISB_CH_5_EEADDR_CTRL;
						eepAddrCrc = ISB_CH_5_EEADDR_CRC;
						break;
				#endif /* ISB_CH_5 */
				#if defined(ISB_CH_6)
					case 6:
						eepAddrCtrl = ISB_CH_6_EEADDR_CTRL;
						eepAddrCrc = ISB_CH_6_EEADDR_CRC;
						break;
				#endif /* ISB_CH_6 */
				#if defined(ISB_CH_7)
					case 7:
						eepAddrCtrl = ISB_CH_7_EEADDR_CTRL;
						eepAddrCrc = ISB_CH_7_EEADDR_CRC;
						break;
				#endif /* ISB_CH_7 */
				#if defined(ISB_CH_8)
					case 8:
						eepAddrCtrl = ISB_CH_8_EEADDR_CTRL;
						eepAddrCrc = ISB_CH_8_EEADDR_CRC;
						break;
				#endif /* ISB_CH_8 */
				#if defined(ISB_CH_9)
					case 9:
						eepAddrCtrl = ISB_CH_9_EEADDR_CTRL;
						eepAddrCrc = ISB_CH_9_EEADDR_CRC;
						break;
				#endif /* ISB_CH_9 */
				#if defined(ISB_CH_10)
					case 10:
						eepAddrCtrl = ISB_CH_10_EEADDR_CTRL;
						eepAddrCrc = ISB_CH_10_EEADDR_CRC;
						break;
				#endif /* ISB_CH_10 */
				#if defined(ISB_CH_11)
					case 11:
						eepAddrCtrl = ISB_CH_11_EEADDR_CTRL;
						eepAddrCrc = ISB_CH_11_EEADDR_CRC;
						break;
				#endif /* ISB_CH_11 */
				#if defined(ISB_CH_12)
					case 12:
						eepAddrCtrl = ISB_CH_12_EEADDR_CTRL;
						eepAddrCrc = ISB_CH_12_EEADDR_CRC;
						break;
				#endif /* ISB_CH_12 */
				#if defined(ISB_CH_13)
					case 13:
						eepAddrCtrl = ISB_CH_13_EEADDR_CTRL;
						eepAddrCrc = ISB_CH_13_EEADDR_CRC;
						break;
				#endif /* ISB_CH_13 */
				#if defined(ISB_CH_14)
					case 14:
						eepAddrCtrl = ISB_CH_14_EEADDR_CTRL;
						eepAddrCrc = ISB_CH_14_EEADDR_CRC;
						break;
				#endif /* ISB_CH_14 */
				#if defined(ISB_CH_15)
					case 15:
						eepAddrCtrl = ISB_CH_15_EEADDR_CTRL;
						eepAddrCrc = ISB_CH_15_EEADDR_CRC;
						break;
				#endif /* ISB_CH_15 */
//-				default:
//-					eepAddrCtrl = 0;
//-					eepAddrCrc = 0;
//-					break;
			}
			if ((eepAddrCrc != 0) & (eepAddrCtrl < eepAddrCrc))
			{
				uint8_t Crc = 0;
				for (uint16_t eepAddr = eepAddrCtrl; eepAddr <= eepAddrCrc; eepAddr++)
				{
// TODO: Aktivieren wenn die Visu die CRC korrekt schreibt.
//					Crc += lib_eep_fw_read_byte((uint8_t *)eepAddr);
				}
				if (Crc == 0)
				{
					Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddrCtrl);
					Ctrl &= ~(1<<ISB_CH_CTRL_ERROR_CRC);
				}
				else
				{
					Ctrl = (1<<ISB_CH_CTRL_ERROR_CRC);
				}
				Ctrl &= ~(1<<ISB_CH_CTRL_INITIALIZED);
			}
			return Ctrl;
		}

		#if defined(ISB_APP_ANAIN_MAX)
			if (bit_is_set(Isb_App_AnaIn_Ctrl, ISB_CTRL_SOFTIRQ_EXEC))
			{
				for (uint8_t AppIndex = 0; AppIndex < ISB_APP_ANAIN_MAX; AppIndex++)
				{
					uint8_t Ch = pgm_read_byte(&pgmIsb_App_AnaIn_Ch_Array[AppIndex]);
					uint8_t Obj_0 = pgm_read_byte(&pgmIsb_App_AnaIn_Obj_0_Array[AppIndex]);
					uint8_t Obj_1 = pgm_read_byte(&pgmIsb_App_AnaIn_Obj_1_Array[AppIndex]);
					uint8_t Obj_2 = pgm_read_byte(&pgmIsb_App_AnaIn_Obj_2_Array[AppIndex]);
					// Initialize
					if (bit_is_clear(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_INITIALIZED))
					{
						uint16_t eepAddr_Cfg0 = 0;
						uint16_t eepAddr_Cfg1 = 0;
						uint16_t eepAddr_Cfg2 = 0;
						uint16_t eepAddr_Cfg_Switch1On = 0;
						uint16_t eepAddr_Cfg_Switch1Off = 0;
						uint16_t eepAddr_Cfg_Switch2On = 0;
						uint16_t eepAddr_Cfg_Switch2Off = 0;
						uint16_t eepAddr_Obj_0_Ctrl = 0;
						uint16_t eepAddr_Obj_0_Tov = 0;
						uint16_t eepAddr_Obj_0_InitValue = 0;
						uint16_t eepAddr_Obj_1_Ctrl = 0;
						uint16_t eepAddr_Obj_1_Tov = 0;
						uint16_t eepAddr_Obj_1_InitValue = 0;
						uint16_t eepAddr_Obj_2_Ctrl = 0;
						uint16_t eepAddr_Obj_2_Tov = 0;
						uint16_t eepAddr_Obj_2_InitValue = 0;
						switch (AppIndex)
						{
							#if defined(ISB_APP_ANAIN_0)
								case ISB_APP_ANAIN_0:
									eepAddr_Cfg0 = ISB_APP_ANAIN_0_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_ANAIN_0_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_ANAIN_0_EEADDR_CFG2;
									eepAddr_Cfg_Switch1On = ISB_APP_ANAIN_0_EEADDR_CFG_SWITCH1ON;
									eepAddr_Cfg_Switch1Off = ISB_APP_ANAIN_0_EEADDR_CFG_SWITCH1OFF;
									eepAddr_Cfg_Switch2On = ISB_APP_ANAIN_0_EEADDR_CFG_SWITCH2ON;
									eepAddr_Cfg_Switch2Off = ISB_APP_ANAIN_0_EEADDR_CFG_SWITCH2OFF;
									eepAddr_Obj_0_Ctrl = ISB_APP_ANAIN_0_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_ANAIN_0_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_ANAIN_0_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_ANAIN_0_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_ANAIN_0_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_ANAIN_0_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_ANAIN_0_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_ANAIN_0_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_ANAIN_0_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_ANAIN_0 */
							#if defined(ISB_APP_ANAIN_1)
								case ISB_APP_ANAIN_1:
									eepAddr_Cfg0 = ISB_APP_ANAIN_1_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_ANAIN_1_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_ANAIN_1_EEADDR_CFG2;
									eepAddr_Cfg_Switch1On = ISB_APP_ANAIN_1_EEADDR_CFG_SWITCH1ON;
									eepAddr_Cfg_Switch1Off = ISB_APP_ANAIN_1_EEADDR_CFG_SWITCH1OFF;
									eepAddr_Cfg_Switch2On = ISB_APP_ANAIN_1_EEADDR_CFG_SWITCH2ON;
									eepAddr_Cfg_Switch2Off = ISB_APP_ANAIN_1_EEADDR_CFG_SWITCH2OFF;
									eepAddr_Obj_0_Ctrl = ISB_APP_ANAIN_1_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_ANAIN_1_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_ANAIN_1_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_ANAIN_1_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_ANAIN_1_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_ANAIN_1_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_ANAIN_1_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_ANAIN_1_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_ANAIN_1_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_ANAIN_1 */
							#if defined(ISB_APP_ANAIN_2)
								case ISB_APP_ANAIN_2:
									eepAddr_Cfg0 = ISB_APP_ANAIN_2_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_ANAIN_2_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_ANAIN_2_EEADDR_CFG2;
									eepAddr_Cfg_Switch1On = ISB_APP_ANAIN_2_EEADDR_CFG_SWITCH1ON;
									eepAddr_Cfg_Switch1Off = ISB_APP_ANAIN_2_EEADDR_CFG_SWITCH1OFF;
									eepAddr_Cfg_Switch2On = ISB_APP_ANAIN_2_EEADDR_CFG_SWITCH2ON;
									eepAddr_Cfg_Switch2Off = ISB_APP_ANAIN_2_EEADDR_CFG_SWITCH2OFF;
									eepAddr_Obj_0_Ctrl = ISB_APP_ANAIN_2_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_ANAIN_2_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_ANAIN_2_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_ANAIN_2_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_ANAIN_2_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_ANAIN_2_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_ANAIN_2_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_ANAIN_2_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_ANAIN_2_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_ANAIN_2 */
							#if defined(ISB_APP_ANAIN_3)
								case ISB_APP_ANAIN_3:
									eepAddr_Cfg0 = ISB_APP_ANAIN_3_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_ANAIN_3_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_ANAIN_3_EEADDR_CFG2;
									eepAddr_Cfg_Switch1On = ISB_APP_ANAIN_3_EEADDR_CFG_SWITCH1ON;
									eepAddr_Cfg_Switch1Off = ISB_APP_ANAIN_3_EEADDR_CFG_SWITCH1OFF;
									eepAddr_Cfg_Switch2On = ISB_APP_ANAIN_3_EEADDR_CFG_SWITCH2ON;
									eepAddr_Cfg_Switch2Off = ISB_APP_ANAIN_3_EEADDR_CFG_SWITCH2OFF;
									eepAddr_Obj_0_Ctrl = ISB_APP_ANAIN_3_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_ANAIN_3_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_ANAIN_3_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_ANAIN_3_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_ANAIN_3_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_ANAIN_3_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_ANAIN_3_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_ANAIN_3_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_ANAIN_3_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_ANAIN_3 */
							#if defined(ISB_APP_ANAIN_4)
								case ISB_APP_ANAIN_4:
									eepAddr_Cfg0 = ISB_APP_ANAIN_4_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_ANAIN_4_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_ANAIN_4_EEADDR_CFG2;
									eepAddr_Cfg_Switch1On = ISB_APP_ANAIN_4_EEADDR_CFG_SWITCH1ON;
									eepAddr_Cfg_Switch1Off = ISB_APP_ANAIN_4_EEADDR_CFG_SWITCH1OFF;
									eepAddr_Cfg_Switch2On = ISB_APP_ANAIN_4_EEADDR_CFG_SWITCH2ON;
									eepAddr_Cfg_Switch2Off = ISB_APP_ANAIN_4_EEADDR_CFG_SWITCH2OFF;
									eepAddr_Obj_0_Ctrl = ISB_APP_ANAIN_4_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_ANAIN_4_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_ANAIN_4_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_ANAIN_4_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_ANAIN_4_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_ANAIN_4_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_ANAIN_4_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_ANAIN_4_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_ANAIN_4_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_ANAIN_4 */
							#if defined(ISB_APP_ANAIN_5)
								case ISB_APP_ANAIN_5:
									eepAddr_Cfg0 = ISB_APP_ANAIN_5_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_ANAIN_5_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_ANAIN_5_EEADDR_CFG2;
									eepAddr_Cfg_Switch1On = ISB_APP_ANAIN_5_EEADDR_CFG_SWITCH1ON;
									eepAddr_Cfg_Switch1Off = ISB_APP_ANAIN_5_EEADDR_CFG_SWITCH1OFF;
									eepAddr_Cfg_Switch2On = ISB_APP_ANAIN_5_EEADDR_CFG_SWITCH2ON;
									eepAddr_Cfg_Switch2Off = ISB_APP_ANAIN_5_EEADDR_CFG_SWITCH2OFF;
									eepAddr_Obj_0_Ctrl = ISB_APP_ANAIN_5_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_ANAIN_5_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_ANAIN_5_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_ANAIN_5_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_ANAIN_5_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_ANAIN_5_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_ANAIN_5_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_ANAIN_5_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_ANAIN_5_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_ANAIN_5 */
							#if defined(ISB_APP_ANAIN_6)
								case ISB_APP_ANAIN_6:
									eepAddr_Cfg0 = ISB_APP_ANAIN_6_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_ANAIN_6_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_ANAIN_6_EEADDR_CFG2;
									eepAddr_Cfg_Switch1On = ISB_APP_ANAIN_6_EEADDR_CFG_SWITCH1ON;
									eepAddr_Cfg_Switch1Off = ISB_APP_ANAIN_6_EEADDR_CFG_SWITCH1OFF;
									eepAddr_Cfg_Switch2On = ISB_APP_ANAIN_6_EEADDR_CFG_SWITCH2ON;
									eepAddr_Cfg_Switch2Off = ISB_APP_ANAIN_6_EEADDR_CFG_SWITCH2OFF;
									eepAddr_Obj_0_Ctrl = ISB_APP_ANAIN_6_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_ANAIN_6_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_ANAIN_6_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_ANAIN_6_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_ANAIN_6_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_ANAIN_6_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_ANAIN_6_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_ANAIN_6_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_ANAIN_6_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_ANAIN_6 */
							#if defined(ISB_APP_ANAIN_7)
								case ISB_APP_ANAIN_7:
									eepAddr_Cfg0 = ISB_APP_ANAIN_7_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_ANAIN_7_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_ANAIN_7_EEADDR_CFG2;
									eepAddr_Cfg_Switch1On = ISB_APP_ANAIN_7_EEADDR_CFG_SWITCH1ON;
									eepAddr_Cfg_Switch1Off = ISB_APP_ANAIN_7_EEADDR_CFG_SWITCH1OFF;
									eepAddr_Cfg_Switch2On = ISB_APP_ANAIN_7_EEADDR_CFG_SWITCH2ON;
									eepAddr_Cfg_Switch2Off = ISB_APP_ANAIN_7_EEADDR_CFG_SWITCH2OFF;
									eepAddr_Obj_0_Ctrl = ISB_APP_ANAIN_7_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_ANAIN_7_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_ANAIN_7_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_ANAIN_7_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_ANAIN_7_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_ANAIN_7_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_ANAIN_7_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_ANAIN_7_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_ANAIN_7_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_ANAIN_7 */
							#if defined(ISB_APP_ANAIN_8)
								case ISB_APP_ANAIN_8:
									eepAddr_Cfg0 = ISB_APP_ANAIN_8_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_ANAIN_8_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_ANAIN_8_EEADDR_CFG2;
									eepAddr_Cfg_Switch1On = ISB_APP_ANAIN_8_EEADDR_CFG_SWITCH1ON;
									eepAddr_Cfg_Switch1Off = ISB_APP_ANAIN_8_EEADDR_CFG_SWITCH1OFF;
									eepAddr_Cfg_Switch2On = ISB_APP_ANAIN_8_EEADDR_CFG_SWITCH2ON;
									eepAddr_Cfg_Switch2Off = ISB_APP_ANAIN_8_EEADDR_CFG_SWITCH2OFF;
									eepAddr_Obj_0_Ctrl = ISB_APP_ANAIN_8_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_ANAIN_8_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_ANAIN_8_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_ANAIN_8_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_ANAIN_8_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_ANAIN_8_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_ANAIN_8_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_ANAIN_8_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_ANAIN_8_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_ANAIN_8 */
							#if defined(ISB_APP_ANAIN_9)
								case ISB_APP_ANAIN_9:
									eepAddr_Cfg0 = ISB_APP_ANAIN_9_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_ANAIN_9_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_ANAIN_9_EEADDR_CFG2;
									eepAddr_Cfg_Switch1On = ISB_APP_ANAIN_9_EEADDR_CFG_SWITCH1ON;
									eepAddr_Cfg_Switch1Off = ISB_APP_ANAIN_9_EEADDR_CFG_SWITCH1OFF;
									eepAddr_Cfg_Switch2On = ISB_APP_ANAIN_9_EEADDR_CFG_SWITCH2ON;
									eepAddr_Cfg_Switch2Off = ISB_APP_ANAIN_9_EEADDR_CFG_SWITCH2OFF;
									eepAddr_Obj_0_Ctrl = ISB_APP_ANAIN_9_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_ANAIN_9_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_ANAIN_9_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_ANAIN_9_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_ANAIN_9_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_ANAIN_9_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_ANAIN_9_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_ANAIN_9_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_ANAIN_9_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_ANAIN_9 */
							#if defined(ISB_APP_ANAIN_10)
								case ISB_APP_ANAIN_10:
									eepAddr_Cfg0 = ISB_APP_ANAIN_10_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_ANAIN_10_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_ANAIN_10_EEADDR_CFG2;
									eepAddr_Cfg_Switch1On = ISB_APP_ANAIN_10_EEADDR_CFG_SWITCH1ON;
									eepAddr_Cfg_Switch1Off = ISB_APP_ANAIN_10_EEADDR_CFG_SWITCH1OFF;
									eepAddr_Cfg_Switch2On = ISB_APP_ANAIN_10_EEADDR_CFG_SWITCH2ON;
									eepAddr_Cfg_Switch2Off = ISB_APP_ANAIN_10_EEADDR_CFG_SWITCH2OFF;
									eepAddr_Obj_0_Ctrl = ISB_APP_ANAIN_10_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_ANAIN_10_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_ANAIN_10_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_ANAIN_10_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_ANAIN_10_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_ANAIN_10_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_ANAIN_10_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_ANAIN_10_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_ANAIN_10_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_ANAIN_10 */
							#if defined(ISB_APP_ANAIN_11)
								case ISB_APP_ANAIN_11:
									eepAddr_Cfg0 = ISB_APP_ANAIN_11_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_ANAIN_11_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_ANAIN_11_EEADDR_CFG2;
									eepAddr_Cfg_Switch1On = ISB_APP_ANAIN_11_EEADDR_CFG_SWITCH1ON;
									eepAddr_Cfg_Switch1Off = ISB_APP_ANAIN_11_EEADDR_CFG_SWITCH1OFF;
									eepAddr_Cfg_Switch2On = ISB_APP_ANAIN_11_EEADDR_CFG_SWITCH2ON;
									eepAddr_Cfg_Switch2Off = ISB_APP_ANAIN_11_EEADDR_CFG_SWITCH2OFF;
									eepAddr_Obj_0_Ctrl = ISB_APP_ANAIN_11_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_ANAIN_11_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_ANAIN_11_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_ANAIN_11_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_ANAIN_11_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_ANAIN_11_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_ANAIN_11_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_ANAIN_11_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_ANAIN_11_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_ANAIN_11 */
							#if defined(ISB_APP_ANAIN_12)
								case ISB_APP_ANAIN_12:
									eepAddr_Cfg0 = ISB_APP_ANAIN_12_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_ANAIN_12_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_ANAIN_12_EEADDR_CFG2;
									eepAddr_Cfg_Switch1On = ISB_APP_ANAIN_12_EEADDR_CFG_SWITCH1ON;
									eepAddr_Cfg_Switch1Off = ISB_APP_ANAIN_12_EEADDR_CFG_SWITCH1OFF;
									eepAddr_Cfg_Switch2On = ISB_APP_ANAIN_12_EEADDR_CFG_SWITCH2ON;
									eepAddr_Cfg_Switch2Off = ISB_APP_ANAIN_12_EEADDR_CFG_SWITCH2OFF;
									eepAddr_Obj_0_Ctrl = ISB_APP_ANAIN_12_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_ANAIN_12_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_ANAIN_12_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_ANAIN_12_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_ANAIN_12_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_ANAIN_12_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_ANAIN_12_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_ANAIN_12_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_ANAIN_12_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_ANAIN_12 */
							#if defined(ISB_APP_ANAIN_13)
								case ISB_APP_ANAIN_13:
									eepAddr_Cfg0 = ISB_APP_ANAIN_13_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_ANAIN_13_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_ANAIN_13_EEADDR_CFG2;
									eepAddr_Cfg_Switch1On = ISB_APP_ANAIN_13_EEADDR_CFG_SWITCH1ON;
									eepAddr_Cfg_Switch1Off = ISB_APP_ANAIN_13_EEADDR_CFG_SWITCH1OFF;
									eepAddr_Cfg_Switch2On = ISB_APP_ANAIN_13_EEADDR_CFG_SWITCH2ON;
									eepAddr_Cfg_Switch2Off = ISB_APP_ANAIN_13_EEADDR_CFG_SWITCH2OFF;
									eepAddr_Obj_0_Ctrl = ISB_APP_ANAIN_13_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_ANAIN_13_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_ANAIN_13_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_ANAIN_13_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_ANAIN_13_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_ANAIN_13_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_ANAIN_13_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_ANAIN_13_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_ANAIN_13_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_ANAIN_13 */
							#if defined(ISB_APP_ANAIN_14)
								case ISB_APP_ANAIN_14:
									eepAddr_Cfg0 = ISB_APP_ANAIN_14_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_ANAIN_14_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_ANAIN_14_EEADDR_CFG2;
									eepAddr_Cfg_Switch1On = ISB_APP_ANAIN_14_EEADDR_CFG_SWITCH1ON;
									eepAddr_Cfg_Switch1Off = ISB_APP_ANAIN_14_EEADDR_CFG_SWITCH1OFF;
									eepAddr_Cfg_Switch2On = ISB_APP_ANAIN_14_EEADDR_CFG_SWITCH2ON;
									eepAddr_Cfg_Switch2Off = ISB_APP_ANAIN_14_EEADDR_CFG_SWITCH2OFF;
									eepAddr_Obj_0_Ctrl = ISB_APP_ANAIN_14_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_ANAIN_14_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_ANAIN_14_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_ANAIN_14_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_ANAIN_14_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_ANAIN_14_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_ANAIN_14_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_ANAIN_14_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_ANAIN_14_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_ANAIN_14 */
							#if defined(ISB_APP_ANAIN_15)
								case ISB_APP_ANAIN_15:
									eepAddr_Cfg0 = ISB_APP_ANAIN_15_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_ANAIN_15_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_ANAIN_15_EEADDR_CFG2;
									eepAddr_Cfg_Switch1On = ISB_APP_ANAIN_15_EEADDR_CFG_SWITCH1ON;
									eepAddr_Cfg_Switch1Off = ISB_APP_ANAIN_15_EEADDR_CFG_SWITCH1OFF;
									eepAddr_Cfg_Switch2On = ISB_APP_ANAIN_15_EEADDR_CFG_SWITCH2ON;
									eepAddr_Cfg_Switch2Off = ISB_APP_ANAIN_15_EEADDR_CFG_SWITCH2OFF;
									eepAddr_Obj_0_Ctrl = ISB_APP_ANAIN_15_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_ANAIN_15_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_ANAIN_15_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_ANAIN_15_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_ANAIN_15_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_ANAIN_15_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_ANAIN_15_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_ANAIN_15_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_ANAIN_15_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_ANAIN_15 */
						}
						Isb_Ch[Ch].Ctrl = Isb_Ch_Ctrl_Get(Ch);
						if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_ENABLED))
						{
							Isb_App_AnaIn[AppIndex].Cfg0 = lib_eep_fw_read_byte((uint8_t *)eepAddr_Cfg0);
							Isb_App_AnaIn[AppIndex].Cfg1 = lib_eep_fw_read_byte((uint8_t *)eepAddr_Cfg1);
							Isb_App_AnaIn[AppIndex].Cfg2 = lib_eep_fw_read_byte((uint8_t *)eepAddr_Cfg2);
							Isb_App_AnaIn[AppIndex].Cfg_Switch1On = lib_eep_fw_read_word((uint16_t *)eepAddr_Cfg_Switch1On);
							Isb_App_AnaIn[AppIndex].Cfg_Switch1Off = lib_eep_fw_read_word((uint16_t *)eepAddr_Cfg_Switch1Off);
							Isb_App_AnaIn[AppIndex].Cfg_Switch2On = lib_eep_fw_read_word((uint16_t *)eepAddr_Cfg_Switch2On);
							Isb_App_AnaIn[AppIndex].Cfg_Switch2Off = lib_eep_fw_read_word((uint16_t *)eepAddr_Cfg_Switch2Off);
							Isb_Obj[Obj_0].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_0_Ctrl);
							Isb_Obj[Obj_0].Top = ISB_MSG_TOP_FLOAT;
							Isb_Obj[Obj_0].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_0_Tov);
							for (uint8_t i = 0; i < 5; i++)
							{
								Isb_Obj[Obj_0].Data[i] = lib_eep_fw_read_byte((uint8_t *)(eepAddr_Obj_0_InitValue + i));
							}
							Isb_Obj[Obj_0].IsChanged = FALSE;
							Isb_Obj[Obj_1].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_1_Ctrl);
							Isb_Obj[Obj_1].Top = ISB_MSG_TOP_1BIT;
							Isb_Obj[Obj_1].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_1_Tov);
							for (uint8_t i = 0; i < 5; i++)
							{
								Isb_Obj[Obj_1].Data[i] = lib_eep_fw_read_byte((uint8_t *)(eepAddr_Obj_1_InitValue + i));
							}
							Isb_Obj[Obj_1].IsChanged = FALSE;
							Isb_Obj[Obj_2].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_2_Ctrl);
							Isb_Obj[Obj_2].Top = ISB_MSG_TOP_1BIT;
							Isb_Obj[Obj_2].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_2_Tov);
							for (uint8_t i = 0; i < 5; i++)
							{
								Isb_Obj[Obj_2].Data[i] = lib_eep_fw_read_byte((uint8_t *)(eepAddr_Obj_2_InitValue + i));
							}
							Isb_Obj[Obj_2].IsChanged = FALSE;
						}
						Isb_Ch[Ch].Ctrl |= (1<<ISB_CH_CTRL_INITIALIZED);
					}
					// Exec
					if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_ENABLED))
					{
						// Sensor einlesen
						switch (Isb_App_AnaIn[AppIndex].Cfg0 & ISB_APP_ANAIN_CFG0_MODE_MASK)
						{
							#if ISB_APP_ANAIN_SOURCE_FEATURE_DS1621 == TRUE
								case ISB_APP_ANAIN_CFG0_MODE_DS1621:
									if (Isb_App_AnaIn[AppIndex].TimeCount == 1000)
									{
										uint16_t Result = 0;
										Lib_Ds1621_ReadTemperature(Isb_App_AnaIn[AppIndex].Cfg1, &Result);
//										int32_t Convert = Result>>8;
//										if (bit_is_set(Result, 7))
//										{
//											Convert += 50;
//										}
//										Isb_App_AnaIn[AppIndex].Value = Lib_IntegerToFloat(Convert);

										uint16_t Vorzeichen = 0x8000;
										if (Result < 0)
										{
											Vorzeichen = 0x0000;
										}
										uint16_t Mantisse = (Result >> 8) * 100;
										if (bit_is_set(Result, 7))
										{
											Mantisse += 50;
										}
										uint16_t Exponent = 0;
										while (Mantisse > 2047)
										{
											Exponent++;
											Mantisse = Mantisse >> 1;
										}
										Exponent = Exponent << 11;
										Isb_App_AnaIn[AppIndex].Value = Vorzeichen + Exponent + Mantisse;

										Isb_App_AnaIn[AppIndex].TimeCount = 0;
									}
									if (Isb_App_AnaIn[AppIndex].TimeCount == 0)
									{
										Lib_Ds1621_StartConvertT(Isb_App_AnaIn[AppIndex].Cfg1);
									}
									Isb_App_AnaIn[AppIndex].TimeCount++;
									break;
							#endif /* ISB_APP_ANAIN_SOURCE_FEATURE_DS1621 == TRUE */
							#if ISB_APP_ANAIN_SOURCE_FEATURE_ADC == TRUE
								case ISB_APP_ANAIN_CFG0_MODE_ADC:
//									if (Isb_App_AnaIn[AppIndex].TimeCount == 1000)
//									{
//										Isb_App_AnaIn[AppIndex].TimeCount = 0;
//									}
//									if (Isb_App_AnaIn[AppIndex].TimeCount == 0)
//									{
//										Lib_Adc_Init(Isb_App_AnaIn[AppIndex].Cfg1, Isb_App_AnaIn[AppIndex].Cfg2, &Isb_App_AnaIn[AppIndex].Value, &Isb_App_Convert_None);
//									}
//									Isb_App_AnaIn[AppIndex].TimeCount++;
									break;
							#endif /* ISB_APP_ANAIN_SOURCE_FEATURE_ADC == TRUE */
							#if ISB_APP_ANAIN_SOURCE_FEATURE_ADC_PT100 == TRUE
								case ISB_APP_ANAIN_CFG0_MODE_ADC_PT100:
//									if (Isb_App_AnaIn[AppIndex].TimeCount == 1000)
//									{
//										Isb_App_AnaIn[AppIndex].TimeCount = 0;
//									}
//									if (Isb_App_AnaIn[AppIndex].TimeCount == 0)
//									{
//										Lib_Adc_Init(Isb_App_AnaIn[AppIndex].Cfg1, Isb_App_AnaIn[AppIndex].Cfg2, &Isb_App_AnaIn[AppIndex].Value, &Isb_App_Convert_PT100);
//									}
//									Isb_App_AnaIn[AppIndex].TimeCount++;
									break;
							#endif /* ISB_APP_ANAIN_SOURCE_FEATURE_ADC_PT100 == TRUE */
							#if ISB_APP_ANAIN_SOURCE_FEATURE_DS1820 == TRUE
								case ISB_APP_ANAIN_CFG0_MODE_DS1820:
									if (Isb_App_AnaIn[AppIndex].TimeCount == 1000)
									{
//										uint16_t Result;
//										Lib_Ds1820_ReadScratchpad(Isb_App_AnaIn[AppIndex].Cfg1, &Result);
//										int32_t Convert = Result>>8;
//										if (bit_is_set(Result, 7))
//										{
//											Convert += 50;
//										}
//										Isb_App_AnaIn[AppIndex].Value = Lib_IntegerToFloat(Convert);
										Isb_App_AnaIn[AppIndex].TimeCount = 0;
									}
									if (Isb_App_AnaIn[AppIndex].TimeCount == 0)
									{
//										Lib_Ds1820_ConvertT(Isb_App_AnaIn[AppIndex].Cfg1);
									}
									Isb_App_AnaIn[AppIndex].TimeCount++;
									break;
							#endif /* ISB_APP_ANAIN_SOURCE_FEATURE_DS1820 == TRUE */
							default:
								Isb_App_AnaIn[AppIndex].Value = 0x7FFF;
								break;
						}
						// Sensor auswerten
						// Sensor
						CONVERT_W Value;
						Value.w = Isb_App_AnaIn[AppIndex].Value;
						if ((Isb_Obj[Obj_0].Data[0] != Value.b[0]) | (Isb_Obj[Obj_0].Data[1] != Value.b[1]))
						{
							Isb_Obj[Obj_0].Data[0] = Value.b[0];
							Isb_Obj[Obj_0].Data[1] = Value.b[1];
							Isb_Obj[Obj_0].IsChanged = TRUE;
						}
						// Schalter 1
						if (bit_is_set(Isb_App_AnaIn[AppIndex].Cfg0, 4))
						{
							if (Lib_FloatToInteger(Isb_App_AnaIn[AppIndex].Value) >= Lib_FloatToInteger(Isb_App_AnaIn[AppIndex].Cfg_Switch1On))
							{
								if (Isb_Obj[Obj_1].Data[0] != TRUE)
								{
									Isb_Obj[Obj_1].Data[0] = TRUE;
									Isb_Obj[Obj_1].IsChanged = TRUE;
								}
							}
							if (Lib_FloatToInteger(Isb_App_AnaIn[AppIndex].Value) <= Lib_FloatToInteger(Isb_App_AnaIn[AppIndex].Cfg_Switch1Off))
							{
								if (Isb_Obj[Obj_1].Data[0] != FALSE)
								{
									Isb_Obj[Obj_1].Data[0] = FALSE;
									Isb_Obj[Obj_1].IsChanged = TRUE;
								}
							}
						}
						// Schalter 2
						if (bit_is_set(Isb_App_AnaIn[AppIndex].Cfg0, 5))
						{
							if (Lib_FloatToInteger(Isb_App_AnaIn[AppIndex].Value) >= Lib_FloatToInteger(Isb_App_AnaIn[AppIndex].Cfg_Switch2On))
							{
								if (Isb_Obj[Obj_2].Data[0] != TRUE)
								{
									Isb_Obj[Obj_2].Data[0] = TRUE;
									Isb_Obj[Obj_2].IsChanged = TRUE;
								}
							}
							if (Lib_FloatToInteger(Isb_App_AnaIn[AppIndex].Value) <= Lib_FloatToInteger(Isb_App_AnaIn[AppIndex].Cfg_Switch2Off))
							{
								if (Isb_Obj[Obj_2].Data[0] != FALSE)
								{
									Isb_Obj[Obj_2].Data[0] = FALSE;
									Isb_Obj[Obj_2].IsChanged = TRUE;
								}
							}
						}
					}
				}
				Isb_App_AnaIn_Ctrl &= ~(1 << ISB_CTRL_SOFTIRQ_EXEC);
			}
		#endif /* ISB_APP_ANAIN_MAX */

		#ifdef ISB_APP_CLOCK_MAX
			if (bit_is_set(Isb_App_Clock_Ctrl, ISB_CTRL_SOFTIRQ_EXEC))
			{
				for (uint8_t AppIndex = 0; AppIndex < ISB_APP_CLOCK_MAX; AppIndex++)
				{
					uint8_t Ch = pgm_read_byte(&pgmIsb_App_Clock_Ch_Array[AppIndex]);
					uint8_t Obj_0 = pgm_read_byte(&pgmIsb_App_Clock_Obj_0_Array[AppIndex]);
					uint8_t Obj_1 = pgm_read_byte(&pgmIsb_App_Clock_Obj_1_Array[AppIndex]);
					// Initialize
					if (bit_is_clear(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_INITIALIZED))
					{
						uint16_t eepAddr_Obj_0_Ctrl = 0;
						uint16_t eepAddr_Obj_0_Tov = 0;
						uint16_t eepAddr_Obj_0_InitValue = 0;
						uint16_t eepAddr_Obj_1_Ctrl = 0;
						uint16_t eepAddr_Obj_1_Tov = 0;
						uint16_t eepAddr_Obj_1_InitValue = 0;
						switch (AppIndex)
						{
							#if defined(ISB_APP_CLOCK_0)
								case ISB_APP_CLOCK_0:
									eepAddr_Obj_0_Ctrl = ISB_APP_CLOCK_0_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_CLOCK_0_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_CLOCK_0_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_CLOCK_0_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_CLOCK_0_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_CLOCK_0_OBJ_1_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_CLOCK_0 */
						}
						Isb_Ch[Ch].Ctrl = Isb_Ch_Ctrl_Get(Ch);
						if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_ENABLED))
						{
							Isb_Obj[Obj_0].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_0_Ctrl);
							Isb_Obj[Obj_0].Top = ISB_MSG_TOP_TIME;
							Isb_Obj[Obj_0].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_0_Tov);
							for (uint8_t i = 0; i < 5; i++)
							{
								Isb_Obj[Obj_0].Data[i] = lib_eep_fw_read_byte((uint8_t *)(eepAddr_Obj_0_InitValue + i));
							}
							Isb_Obj[Obj_0].IsChanged = FALSE;
							Isb_Obj[Obj_1].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_1_Ctrl);
							Isb_Obj[Obj_1].Top = ISB_MSG_TOP_DATE;
							Isb_Obj[Obj_1].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_1_Tov);
							for (uint8_t i = 0; i < 5; i++)
							{
								Isb_Obj[Obj_1].Data[i] = lib_eep_fw_read_byte((uint8_t *)(eepAddr_Obj_1_InitValue + i));
							}
							Isb_Obj[Obj_1].IsChanged = FALSE;
						}
						Isb_Ch[Ch].Ctrl |= (1<<ISB_CH_CTRL_INITIALIZED);
					}
					// Exec
					if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_ENABLED))
					{
						// Uhrzeit stellen
						if (Isb_Obj[Obj_0].IsChanged == TRUE)
						{
							Isb_Systick_Clock.Seconds = Isb_Obj[Obj_0].Data[0];
							Isb_Systick_Clock.Minutes = Isb_Obj[Obj_0].Data[1];
							Isb_Systick_Clock.Hour = Isb_Obj[Obj_0].Data[2];
							Isb_Obj[Obj_0].IsChanged = FALSE;
						}
						// Datum stellen
						if (Isb_Obj[Obj_1].IsChanged == TRUE)
						{
							Isb_Systick_Clock.Day = Isb_Obj[Obj_1].Data[0];
							Isb_Systick_Clock.Month = Isb_Obj[Obj_1].Data[1];
							Isb_Systick_Clock.Year = (uint16_t)Isb_Obj[Obj_1].Data[2];
							Isb_Systick_Clock.Year |= (uint16_t)(Isb_Obj[Obj_1].Data[3]<<8);
							Isb_Systick_Clock.Dow = Isb_Obj[Obj_1].Data[4];
							Isb_Obj[Obj_1].IsChanged = FALSE;
						}
						// Sekunden
						if (Isb_Obj[Obj_0].Data[0] != Isb_Systick_Clock.Seconds)
						{
							Isb_Obj[Obj_0].Data[0] = Isb_Systick_Clock.Seconds;
							if (bit_is_set(Isb_Obj[Obj_0].Ctrl, ISB_OBJ_CTRL_SEND))
							{
								Isb_Obj[Obj_0].IsChanged = TRUE;
							}
						}
						// Minuten
						if (Isb_Obj[Obj_0].Data[1] != Isb_Systick_Clock.Minutes)
						{
							Isb_Obj[Obj_0].Data[1] = Isb_Systick_Clock.Minutes;
							if (bit_is_set(Isb_Obj[Obj_0].Ctrl, ISB_OBJ_CTRL_SEND))
							{
								Isb_Obj[Obj_0].IsChanged = TRUE;
							}
						}
						// Stunden
						if (Isb_Obj[Obj_0].Data[2] != Isb_Systick_Clock.Hour)
						{
							Isb_Obj[Obj_0].Data[2] = Isb_Systick_Clock.Hour;
							if (bit_is_set(Isb_Obj[Obj_0].Ctrl, ISB_OBJ_CTRL_SEND))
							{
								Isb_Obj[Obj_0].IsChanged = TRUE;
							}
						}
						// Tag
						if (Isb_Obj[Obj_1].Data[0] != Isb_Systick_Clock.Day)
						{
							Isb_Obj[Obj_1].Data[0] = Isb_Systick_Clock.Day;
							if (bit_is_set(Isb_Obj[Obj_0].Ctrl, ISB_OBJ_CTRL_SEND))
							{
								Isb_Obj[Obj_0].IsChanged = TRUE;
							}
						}
						// Monat
						if (Isb_Obj[Obj_1].Data[1] != Isb_Systick_Clock.Month)
						{
							Isb_Obj[Obj_1].Data[1] = Isb_Systick_Clock.Month;
							if (bit_is_set(Isb_Obj[Obj_0].Ctrl, ISB_OBJ_CTRL_SEND))
							{
								Isb_Obj[Obj_0].IsChanged = TRUE;
							}
						}
						// Jahr
						if ((uint16_t)(Isb_Obj[Obj_1].Data[2] + (uint16_t)(Isb_Obj[Obj_1].Data[3]<<8)) != Isb_Systick_Clock.Year)
						{
							Isb_Obj[Obj_1].Data[2] = Isb_Systick_Clock.Year;
							Isb_Obj[Obj_1].Data[3] = (Isb_Systick_Clock.Year>>8);
							if (bit_is_set(Isb_Obj[Obj_0].Ctrl, ISB_OBJ_CTRL_SEND))
							{
								Isb_Obj[Obj_0].IsChanged = TRUE;
							}
						}
						// Wochentag
						if (Isb_Obj[Obj_1].Data[4] != Isb_Systick_Clock.Dow)
						{
							Isb_Obj[Obj_1].Data[4] = Isb_Systick_Clock.Dow;
							if (bit_is_set(Isb_Obj[Obj_0].Ctrl, ISB_OBJ_CTRL_SEND))
							{
								Isb_Obj[Obj_0].IsChanged = TRUE;
							}
						}
					}
				}
				Isb_App_Clock_Ctrl &= ~(1 << ISB_CTRL_SOFTIRQ_EXEC);
			}
		#endif /* ISB_APP_CLOCK_MAX */

		#if defined(ISB_APP_DIGIN_MAX)
			if (bit_is_set(Isb_App_DigIn_Ctrl, ISB_CTRL_SOFTIRQ_EXEC))
			{
				for (uint8_t AppIndex = 0; AppIndex < ISB_APP_DIGIN_MAX; AppIndex++)
				{
					uint8_t Ch = pgm_read_byte(&pgmIsb_App_DigIn_Ch_Array[AppIndex]);
					uint8_t Pin0 = pgm_read_byte(&pgmIsb_App_DigIn_Pin0_Array[AppIndex]);
					uint8_t Obj_0 = pgm_read_byte(&pgmIsb_App_DigIn_Obj_0_Array[AppIndex]);
					uint8_t Obj_1 = pgm_read_byte(&pgmIsb_App_DigIn_Obj_1_Array[AppIndex]);
					uint8_t Obj_2 = pgm_read_byte(&pgmIsb_App_DigIn_Obj_2_Array[AppIndex]);
					// Initialize
					if (bit_is_clear(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_INITIALIZED))
					{
						uint16_t eepAddr_Cfg0 = 0;
						uint16_t eepAddr_Cfg1 = 0;
						uint16_t eepAddr_Cfg2 = 0;
						uint16_t eepAddr_Cfg3 = 0;
						uint16_t eepAddr_Obj_0_Ctrl = 0;
						uint16_t eepAddr_Obj_0_Tov = 0;
						uint16_t eepAddr_Obj_0_InitValue = 0;
						uint16_t eepAddr_Obj_1_Ctrl = 0;
						uint16_t eepAddr_Obj_1_Tov = 0;
						uint16_t eepAddr_Obj_1_InitValue = 0;
						uint16_t eepAddr_Obj_2_Ctrl = 0;
						uint16_t eepAddr_Obj_2_Tov = 0;
						uint16_t eepAddr_Obj_2_InitValue = 0;
						switch (AppIndex)
						{
							#if defined(ISB_APP_DIGIN_0)
								case ISB_APP_DIGIN_0:
									eepAddr_Cfg0 = ISB_APP_DIGIN_0_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_DIGIN_0_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_DIGIN_0_EEADDR_CFG2;
									eepAddr_Cfg3 = ISB_APP_DIGIN_0_EEADDR_CFG3;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGIN_0_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGIN_0_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGIN_0_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_DIGIN_0_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_DIGIN_0_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_DIGIN_0_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_DIGIN_0_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_DIGIN_0_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_DIGIN_0_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_DIGIN_0 */
							#if defined(ISB_APP_DIGIN_1)
								case ISB_APP_DIGIN_1:
									eepAddr_Cfg0 = ISB_APP_DIGIN_1_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_DIGIN_1_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_DIGIN_1_EEADDR_CFG2;
									eepAddr_Cfg3 = ISB_APP_DIGIN_1_EEADDR_CFG3;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGIN_1_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGIN_1_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGIN_1_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_DIGIN_1_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_DIGIN_1_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_DIGIN_1_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_DIGIN_1_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_DIGIN_1_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_DIGIN_1_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_DIGIN_1 */
							#if defined(ISB_APP_DIGIN_2)
								case ISB_APP_DIGIN_2:
									eepAddr_Cfg0 = ISB_APP_DIGIN_2_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_DIGIN_2_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_DIGIN_2_EEADDR_CFG2;
									eepAddr_Cfg3 = ISB_APP_DIGIN_2_EEADDR_CFG3;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGIN_2_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGIN_2_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGIN_2_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_DIGIN_2_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_DIGIN_2_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_DIGIN_2_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_DIGIN_2_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_DIGIN_2_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_DIGIN_2_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_DIGIN_2 */
							#if defined(ISB_APP_DIGIN_3)
								case ISB_APP_DIGIN_3:
									eepAddr_Cfg0 = ISB_APP_DIGIN_3_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_DIGIN_3_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_DIGIN_3_EEADDR_CFG2;
									eepAddr_Cfg3 = ISB_APP_DIGIN_3_EEADDR_CFG3;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGIN_3_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGIN_3_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGIN_3_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_DIGIN_3_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_DIGIN_3_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_DIGIN_3_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_DIGIN_3_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_DIGIN_3_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_DIGIN_3_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_DIGIN_3 */
							#if defined(ISB_APP_DIGIN_4)
								case ISB_APP_DIGIN_4:
									eepAddr_Cfg0 = ISB_APP_DIGIN_4_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_DIGIN_4_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_DIGIN_4_EEADDR_CFG2;
									eepAddr_Cfg3 = ISB_APP_DIGIN_4_EEADDR_CFG3;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGIN_4_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGIN_4_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGIN_4_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_DIGIN_4_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_DIGIN_4_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_DIGIN_4_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_DIGIN_4_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_DIGIN_4_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_DIGIN_4_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_DIGIN_4 */
							#if defined(ISB_APP_DIGIN_5)
								case ISB_APP_DIGIN_5:
									eepAddr_Cfg0 = ISB_APP_DIGIN_5_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_DIGIN_5_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_DIGIN_5_EEADDR_CFG2;
									eepAddr_Cfg3 = ISB_APP_DIGIN_5_EEADDR_CFG3;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGIN_5_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGIN_5_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGIN_5_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_DIGIN_5_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_DIGIN_5_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_DIGIN_5_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_DIGIN_5_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_DIGIN_5_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_DIGIN_5_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_DIGIN_5 */
							#if defined(ISB_APP_DIGIN_6)
								case ISB_APP_DIGIN_6:
									eepAddr_Cfg0 = ISB_APP_DIGIN_6_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_DIGIN_6_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_DIGIN_6_EEADDR_CFG2;
									eepAddr_Cfg3 = ISB_APP_DIGIN_6_EEADDR_CFG3;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGIN_6_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGIN_6_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGIN_6_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_DIGIN_6_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_DIGIN_6_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_DIGIN_6_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_DIGIN_6_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_DIGIN_6_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_DIGIN_6_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_DIGIN_6 */
							#if defined(ISB_APP_DIGIN_7)
								case ISB_APP_DIGIN_7:
									eepAddr_Cfg0 = ISB_APP_DIGIN_7_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_DIGIN_7_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_DIGIN_7_EEADDR_CFG2;
									eepAddr_Cfg3 = ISB_APP_DIGIN_7_EEADDR_CFG3;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGIN_7_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGIN_7_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGIN_7_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_DIGIN_7_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_DIGIN_7_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_DIGIN_7_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_DIGIN_7_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_DIGIN_7_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_DIGIN_7_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_DIGIN_7 */
							#if defined(ISB_APP_DIGIN_8)
								case ISB_APP_DIGIN_8:
									eepAddr_Cfg0 = ISB_APP_DIGIN_8_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_DIGIN_8_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_DIGIN_8_EEADDR_CFG2;
									eepAddr_Cfg3 = ISB_APP_DIGIN_8_EEADDR_CFG3;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGIN_8_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGIN_8_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGIN_8_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_DIGIN_8_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_DIGIN_8_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_DIGIN_8_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_DIGIN_8_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_DIGIN_8_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_DIGIN_8_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_DIGIN_8 */
							#if defined(ISB_APP_DIGIN_9)
								case ISB_APP_DIGIN_9:
									eepAddr_Cfg0 = ISB_APP_DIGIN_9_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_DIGIN_9_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_DIGIN_9_EEADDR_CFG2;
									eepAddr_Cfg3 = ISB_APP_DIGIN_9_EEADDR_CFG3;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGIN_9_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGIN_9_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGIN_9_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_DIGIN_9_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_DIGIN_9_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_DIGIN_9_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_DIGIN_9_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_DIGIN_9_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_DIGIN_9_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_DIGIN_9 */
							#if defined(ISB_APP_DIGIN_10)
								case ISB_APP_DIGIN_10:
									eepAddr_Cfg0 = ISB_APP_DIGIN_10_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_DIGIN_10_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_DIGIN_10_EEADDR_CFG2;
									eepAddr_Cfg3 = ISB_APP_DIGIN_10_EEADDR_CFG3;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGIN_10_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGIN_10_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGIN_10_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_DIGIN_10_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_DIGIN_10_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_DIGIN_10_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_DIGIN_10_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_DIGIN_10_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_DIGIN_10_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_DIGIN_10 */
							#if defined(ISB_APP_DIGIN_11)
								case ISB_APP_DIGIN_11:
									eepAddr_Cfg0 = ISB_APP_DIGIN_11_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_DIGIN_11_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_DIGIN_11_EEADDR_CFG2;
									eepAddr_Cfg3 = ISB_APP_DIGIN_11_EEADDR_CFG3;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGIN_11_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGIN_11_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGIN_11_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_DIGIN_11_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_DIGIN_11_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_DIGIN_11_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_DIGIN_11_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_DIGIN_11_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_DIGIN_11_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_DIGIN_11 */
							#if defined(ISB_APP_DIGIN_12)
								case ISB_APP_DIGIN_12:
									eepAddr_Cfg0 = ISB_APP_DIGIN_12_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_DIGIN_12_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_DIGIN_12_EEADDR_CFG2;
									eepAddr_Cfg3 = ISB_APP_DIGIN_12_EEADDR_CFG3;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGIN_12_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGIN_12_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGIN_12_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_DIGIN_12_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_DIGIN_12_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_DIGIN_12_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_DIGIN_12_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_DIGIN_12_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_DIGIN_12_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_DIGIN_12 */
							#if defined(ISB_APP_DIGIN_13)
								case ISB_APP_DIGIN_13:
									eepAddr_Cfg0 = ISB_APP_DIGIN_13_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_DIGIN_13_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_DIGIN_13_EEADDR_CFG2;
									eepAddr_Cfg3 = ISB_APP_DIGIN_13_EEADDR_CFG3;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGIN_13_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGIN_13_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGIN_13_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_DIGIN_13_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_DIGIN_13_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_DIGIN_13_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_DIGIN_13_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_DIGIN_13_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_DIGIN_13_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_DIGIN_13 */
							#if defined(ISB_APP_DIGIN_14)
								case ISB_APP_DIGIN_14:
									eepAddr_Cfg0 = ISB_APP_DIGIN_14_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_DIGIN_14_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_DIGIN_14_EEADDR_CFG2;
									eepAddr_Cfg3 = ISB_APP_DIGIN_14_EEADDR_CFG3;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGIN_14_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGIN_14_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGIN_14_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_DIGIN_14_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_DIGIN_14_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_DIGIN_14_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_DIGIN_14_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_DIGIN_14_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_DIGIN_14_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_DIGIN_14 */
							#if defined(ISB_APP_DIGIN_15)
								case ISB_APP_DIGIN_15:
									eepAddr_Cfg0 = ISB_APP_DIGIN_15_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_DIGIN_15_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_DIGIN_15_EEADDR_CFG2;
									eepAddr_Cfg3 = ISB_APP_DIGIN_15_EEADDR_CFG3;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGIN_15_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGIN_15_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGIN_15_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_DIGIN_15_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_DIGIN_15_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_DIGIN_15_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_DIGIN_15_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_DIGIN_15_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_DIGIN_15_OBJ_2_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_DIGIN_15 */
						}
						Isb_Ch[Ch].Ctrl = Isb_Ch_Ctrl_Get(Ch);
						if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_ENABLED))
						{
							Isb_App_DigIn[AppIndex].Cfg0 = lib_eep_fw_read_byte((uint8_t *)eepAddr_Cfg0);
							Isb_App_DigIn[AppIndex].Cfg1 = lib_eep_fw_read_byte((uint8_t *)eepAddr_Cfg1);
							Isb_App_DigIn[AppIndex].Cfg2 = lib_eep_fw_read_byte((uint8_t *)eepAddr_Cfg2);
							Isb_App_DigIn[AppIndex].Cfg3 = lib_eep_fw_read_byte((uint8_t *)eepAddr_Cfg3);
							uint8_t Port = (Pin0 & ISB_APP_DIGIN_PIN0_MASKPORT) >> 3;
							uint8_t Pin = Pin0 & ISB_APP_DIGIN_PIN0_MASKPIN;
							if (Port != 0)
							{
								if ((Pin0 & PULLUP) == 0)
								{
									Lib_Pin_Set(Port, Pin, LIB_PIN_INPUT);
								}
								else
								{
									Lib_Pin_Set(Port, Pin, LIB_PIN_INPUT_PULLUP);
								}
							}
							Isb_Obj[Obj_0].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_0_Ctrl);
							Isb_Obj[Obj_0].Top = ISB_MSG_TOP_1BIT;
							Isb_Obj[Obj_0].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_0_Tov);
							for (uint8_t i = 0; i < 5; i++)
							{
								Isb_Obj[Obj_0].Data[i] = lib_eep_fw_read_byte((uint8_t *)(eepAddr_Obj_0_InitValue + i));
							}
							Isb_Obj[Obj_0].IsChanged = FALSE;
							Isb_Obj[Obj_1].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_1_Ctrl);
							Isb_Obj[Obj_1].Top = ISB_MSG_TOP_1BIT;
							Isb_Obj[Obj_1].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_1_Tov);
							for (uint8_t i = 0; i < 5; i++)
							{
								Isb_Obj[Obj_1].Data[i] = lib_eep_fw_read_byte((uint8_t *)(eepAddr_Obj_1_InitValue + i));
							}
							Isb_Obj[Obj_1].IsChanged = FALSE;
							Isb_Obj[Obj_2].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_2_Ctrl);
							Isb_Obj[Obj_2].Top = ISB_MSG_TOP_1BIT;
							Isb_Obj[Obj_2].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_2_Tov);
							for (uint8_t i = 0; i < 5; i++)
							{
								Isb_Obj[Obj_2].Data[i] = lib_eep_fw_read_byte((uint8_t *)(eepAddr_Obj_2_InitValue + i));
							}
							Isb_Obj[Obj_2].IsChanged = FALSE;
						}
						Isb_Ch[Ch].Ctrl |= (1<<ISB_CH_CTRL_INITIALIZED);
					}
					// Exec
					if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_ENABLED))
					{
// -> TODO:
//						if (Isb_Obj[Obj_0].Data[0] == 0)
//						{
							// Pin einlesen
							switch (Isb_App_DigIn[AppIndex].Cfg0 & ISB_APP_DIGIN_CFG0_SOURCE_MASK)
							{
								#if ISB_APP_DIGIN_SOURCE_FEATURE_PIN == TRUE
									case ISB_APP_DIGIN_CFG0_SOURCE_STD:
										;
										uint8_t Port = (Pin0 & ISB_APP_DIGIN_PIN0_MASKPORT) >> 3;
										uint8_t Pin = Pin0 & ISB_APP_DIGIN_PIN0_MASKPIN;
										if (Port != 0)
										{
											if (bit_is_clear(Isb_App_DigIn[AppIndex].Cfg0, ISB_APP_DIGIN_CFG0_PIN0_INVERTED))
											{
												if (Lib_Pin_Get(Port, Pin) != 0)
												{
													Isb_App_DigIn[AppIndex].Value = 1;
												}
												else
												{
													Isb_App_DigIn[AppIndex].Value = 0;
												}
											}
											else
											{
												if (Lib_Pin_Get(Port, Pin) != 0)
												{
													Isb_App_DigIn[AppIndex].Value = 0;
												}
												else
												{
													Isb_App_DigIn[AppIndex].Value = 1;
												}
											}
										}
										break;
								#endif /* ISB_APP_DIGIN_SOURCE_FEATURE_PIN == TRUE */
								#if ISB_APP_DIGIN_SOURCE_FEATURE_SLAVE_USART0 == TRUE
									case ISB_APP_DIGIN_CFG0_SOURCE_SLAVEUSART0:
// TODO: ISB_APP_DIGIN_SOURCE_FEATURE_SLAVE_USART0
										Isb_App_DigIn[AppIndex].Value = 0;
										break;
								#endif /* ISB_APP_DIGIN_SOURCE_FEATURE_SLAVE_USART0 == TRUE */
								#if ISB_APP_DIGIN_SOURCE_FEATURE_SLAVE_USART1 == TRUE
									case ISB_APP_DIGIN_CFG0_SOURCE_SLAVEUSART1:
// TODO: ISB_APP_DIGIN_SOURCE_FEATURE_SLAVE_USART1
										Isb_App_DigIn[AppIndex].Value = 0;
										break;
								#endif /* ISB_APP_DIGIN_SOURCE_FEATURE_SLAVE_USART1 == TRUE */
							}
							// Pin auswerten
							if (Isb_App_DigIn[AppIndex].Value != 0)
							{
								// Global
								Isb_App_DigIn[AppIndex].CountHigh++;
								// Event "High" > 40ms
								if (Isb_App_DigIn[AppIndex].CountHigh == 4)
								{
									Isb_App_DigIn[AppIndex].Event |= (1 << ISB_APP_DIGIN_EVENT_HIGH);
								}
								// Event "High Long" > 400ms
								if (Isb_App_DigIn[AppIndex].CountHigh == 40)
								{
									Isb_App_DigIn[AppIndex].Event |= (1 << ISB_APP_DIGIN_EVENT_HIGHLONG);
								}
								// Event "High Repeat"
								if (Isb_App_DigIn[AppIndex].CountHigh == 100)
								{
									Isb_App_DigIn[AppIndex].CountHigh = 90;
									Isb_App_DigIn[AppIndex].Event |= (1 << ISB_APP_DIGIN_EVENT_HIGHREPEAT);
								}
								// Event "Low Short" = 40-400ms
// TODO: DELETE
//-								if (Isb_App_DigIn[AppIndex].CountLow != 0)
//-								{
//-									if (Isb_App_DigIn[AppIndex].CountLow < 40)
//-									{
//-										Isb_App_DigIn[AppIndex].Event |= (1 << ISB_APP_DIGIN_EVENT_LOWSHORT);
//-									}
//-								}
								// Global
								Isb_App_DigIn[AppIndex].CountLow = 0;
							}
							else
							{
								// Global
								Isb_App_DigIn[AppIndex].CountLow++;
								// Event "Low" > 40ms
								if (Isb_App_DigIn[AppIndex].CountLow == 4)
								{
									Isb_App_DigIn[AppIndex].Event |= (1 << ISB_APP_DIGIN_EVENT_LOW);
								}
// TODO: DELETE
//-								// Event "Low Long" > 400ms
//-								if (Isb_App_DigIn[AppIndex].CountLow == 40)
//-								{
//-									Isb_App_DigIn[AppIndex].Event |= (1 << ISB_APP_DIGIN_EVENT_LOWLONG);
//-								}
//-								// Event "Low Repeat"
//-								if (Isb_App_DigIn[AppIndex].CountLow == 100)
//-								{
//-									Isb_App_DigIn[AppIndex].CountLow = 90;
//-									Isb_App_DigIn[AppIndex].Event |= (1 << ISB_APP_DIGIN_EVENT_LOWREPEAT);
//-								}
								// Event "High Short" = 40-400ms
								if (Isb_App_DigIn[AppIndex].CountHigh != 0)
								{
									if (Isb_App_DigIn[AppIndex].CountHigh < 40)
									{
										Isb_App_DigIn[AppIndex].Event |= (1 << ISB_APP_DIGIN_EVENT_HIGHSHORT);
									}
								}
								// Global
								Isb_App_DigIn[AppIndex].CountHigh = 0;
							}
							// Event auswerten
							switch (Isb_App_DigIn[AppIndex].Cfg1 & ISB_APP_DIGIN_CFG1_MODE_MASK)
							{
								#if ISB_APP_DIGIN_MODE_FEATURE_SWITCH == TRUE
									case ISB_APP_DIGIN_CFG1_MODE_SWITCH:
										// Betriebsart = Schaltsensor/Störmeldeeingang
										switch (Isb_App_DigIn[AppIndex].Cfg1 & ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_MASK)
										{
											#if ISB_APP_DIGIN_MODE_FEATURE_SWITCH_FUNCTION_1SOUKLOR == TRUE
												case ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_0:
													// 1 Schaltobjekt - Ohne Unterscheidung Kurz/Lang - Ohne Repeat
													if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGH))
													{
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_1)
														{
															// Aus
															Isb_Obj[Obj_1].Data[0] = 0;
															Isb_Obj[Obj_1].IsChanged = TRUE;
														}
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_2)
														{
															// Ein
															Isb_Obj[Obj_1].Data[0] = 1;
															Isb_Obj[Obj_1].IsChanged = TRUE;
														}
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_3)
														{
															// Um
															if (Isb_Obj[Obj_1].Data[0] == 0)
															{
																Isb_Obj[Obj_1].Data[0] = 1;
															}
															else
															{
																Isb_Obj[Obj_1].Data[0] = 0;
															}
															Isb_Obj[Obj_1].IsChanged = TRUE;
														}
														Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGH);
													}
													if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_LOW))
													{
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_1)
														{
															// Aus
															Isb_Obj[Obj_1].Data[0] = 0;
															Isb_Obj[Obj_1].IsChanged = TRUE;
														}
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_2)
														{
															// Ein
															Isb_Obj[Obj_1].Data[0] = 1;
															Isb_Obj[Obj_1].IsChanged = TRUE;
														}
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_3)
														{
															// Um
															if (Isb_Obj[Obj_1].Data[0] == 0)
															{
																Isb_Obj[Obj_1].Data[0] = 1;
															}
															else
															{
																Isb_Obj[Obj_1].Data[0] = 0;
															}
															Isb_Obj[Obj_1].IsChanged = TRUE;
														}
														Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_LOW);
													}
													break;
											#endif /* ISB_APP_DIGIN_MODE_FEATURE_SWITCH_FUNCTION_1SOUKLOR == TRUE */
											#if ISB_APP_DIGIN_MODE_FEATURE_SWITCH_FUNCTION_1SOUKLMR == TRUE
												case ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_1:
													// 1 Schaltobjekt - Ohne Unterscheidung Kurz/Lang - Mit Repeat
													if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGH))
													{
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_1)
														{
															// Aus
															Isb_Obj[Obj_1].Data[0] = 0;
															Isb_Obj[Obj_1].IsChanged = TRUE;
														}
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_2)
														{
															// Ein
															Isb_Obj[Obj_1].Data[0] = 1;
															Isb_Obj[Obj_1].IsChanged = TRUE;
														}
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_3)
														{
															// Um
															if (Isb_Obj[Obj_1].Data[0] == 0)
															{
																Isb_Obj[Obj_1].Data[0] = 1;
															}
															else
															{
																Isb_Obj[Obj_1].Data[0] = 0;
															}
															Isb_Obj[Obj_1].IsChanged = TRUE;
														}
														Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGH);
													}
													if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_LOW))
													{
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_1)
														{
															// Aus
															Isb_Obj[Obj_1].Data[0] = 0;
															Isb_Obj[Obj_1].IsChanged = TRUE;
														}
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_2)
														{
															// Ein
															Isb_Obj[Obj_1].Data[0] = 1;
															Isb_Obj[Obj_1].IsChanged = TRUE;
														}
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_3)
														{
															// Um
															if (Isb_Obj[Obj_1].Data[0] == 0)
															{
																Isb_Obj[Obj_1].Data[0] = 1;
															}
															else
															{
																Isb_Obj[Obj_1].Data[0] = 0;
															}
															Isb_Obj[Obj_1].IsChanged = TRUE;
														}
														Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_LOW);
													}
													if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHREPEAT))
													{
// TODO: REPEAT
														Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHREPEAT);
													}
													break;
											#endif /* ISB_APP_DIGIN_MODE_FEATURE_SWITCH_FUNCTION_1SOUKLMR == TRUE */
											#if ISB_APP_DIGIN_MODE_FEATURE_SWITCH_FUNCTION_2SMUKLOR == TRUE
												case ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_2:
													// 2 Schaltobjekte - Mit Unterscheidung Kurz/Lang - Ohne Repeat
													if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHSHORT))
													{
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_1)
														{
															// Aus
															Isb_Obj[Obj_1].Data[0] = 0;
															Isb_Obj[Obj_1].IsChanged = TRUE;
														}
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_2)
														{
															// Ein
															Isb_Obj[Obj_1].Data[0] = 1;
															Isb_Obj[Obj_1].IsChanged = TRUE;
														}
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_3)
														{
															// Um
															if (Isb_Obj[Obj_1].Data[0] == 0)
															{
																Isb_Obj[Obj_1].Data[0] = 1;
															}
															else
															{
																Isb_Obj[Obj_1].Data[0] = 0;
															}
															Isb_Obj[Obj_1].IsChanged = TRUE;
														}
														Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHSHORT);
													}
													if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHLONG))
													{
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_1)
														{
															// Aus
															Isb_Obj[Obj_2].Data[0] = 0;
															Isb_Obj[Obj_2].IsChanged = TRUE;
														}
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_2)
														{
															// Ein
															Isb_Obj[Obj_2].Data[0] = 1;
															Isb_Obj[Obj_2].IsChanged = TRUE;
														}
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_3)
														{
															// Um
															if (Isb_Obj[Obj_2].Data[0] == 0)
															{
																Isb_Obj[Obj_2].Data[0] = 1;
															}
															else
															{
																Isb_Obj[Obj_2].Data[0] = 0;
															}
															Isb_Obj[Obj_2].IsChanged = TRUE;
														}
														Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHLONG);
													}
													break;
											#endif /* ISB_APP_DIGIN_MODE_FEATURE_SWITCH_FUNCTION_2SMUKLOR == TRUE */
											#if ISB_APP_DIGIN_MODE_FEATURE_SWITCH_FUNCTION_2SMUKLMR == TRUE
												case ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_3:
													// 2 Schaltobjekte - Mit Unterscheidung Kurz/Lang - Mit Repeat
													if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHSHORT))
													{
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_1)
														{
															// Aus
															Isb_Obj[Obj_1].Data[0] = 0;
															Isb_Obj[Obj_1].IsChanged = TRUE;
														}
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_2)
														{
															// Ein
															Isb_Obj[Obj_1].Data[0] = 1;
															Isb_Obj[Obj_1].IsChanged = TRUE;
														}
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_3)
														{
															// Um
															if (Isb_Obj[Obj_1].Data[0] == 0)
															{
																Isb_Obj[Obj_1].Data[0] = 1;
															}
															else
															{
																Isb_Obj[Obj_1].Data[0] = 0;
															}
															Isb_Obj[Obj_1].IsChanged = TRUE;
														}
														Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHSHORT);
													}
													if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHLONG))
													{
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_1)
														{
															// Aus
															Isb_Obj[Obj_2].Data[0] = 0;
															Isb_Obj[Obj_2].IsChanged = TRUE;
														}
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_2)
														{
															// Ein
															Isb_Obj[Obj_2].Data[0] = 1;
															Isb_Obj[Obj_2].IsChanged = TRUE;
														}
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_3)
														{
															// Um
															if (Isb_Obj[Obj_2].Data[0] == 0)
															{
																Isb_Obj[Obj_2].Data[0] = 1;
															}
															else
															{
																Isb_Obj[Obj_2].Data[0] = 0;
															}
															Isb_Obj[Obj_2].IsChanged = TRUE;
														}
														Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHLONG);
													}
													if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHREPEAT))
													{
// TODO: REPEAT
														Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHREPEAT);
													}
													break;
											#endif /* ISB_APP_DIGIN_MODE_FEATURE_SWITCH_FUNCTION_2SMUKLMR == TRUE */
										}
										break;
								#endif /* ISB_APP_DIGIN_MODE_FEATURE_SWITCH == TRUE */
								#if ISB_APP_DIGIN_MODE_FEATURE_DIMMER == TRUE
									case ISB_APP_DIGIN_CFG1_MODE_DIMMER:
										// Betriebsart = Schalt-/Dimmsensor
										switch (Isb_App_DigIn[AppIndex].Cfg1 & ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_MASK)
										{
											#if ISB_APP_DIGIN_MODE_FEATURE_DIMMER_FUNCTION_DUS == TRUE
												case ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_0:
													// Dimmen und Schalten
													if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHSHORT))
													{
														// Schalten
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_1)
														{
															// Ein
															Isb_Obj[Obj_1].Data[0] = 1;
															Isb_Obj[Obj_1].IsChanged = TRUE;
														}
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_2)
														{
															// Aus
															Isb_Obj[Obj_1].Data[0] = 0;
															Isb_Obj[Obj_1].IsChanged = TRUE;
														}
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_3)
														{
															// Um
															if (Isb_Obj[Obj_1].Data[0] == 0)
															{
																Isb_Obj[Obj_1].Data[0] = 1;
															}
															else
															{
																Isb_Obj[Obj_1].Data[0] = 0;
															}
															Isb_Obj[Obj_1].IsChanged = TRUE;
														}
														Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHSHORT);
													}
													if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHLONG))
													{
														// Dimmen
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_0)
														{
															// Heller
															Isb_Obj[Obj_2].Data[0] = (1 << ISB_APP_DIGIN_CFG3_DIMMER_DIRECTION) | (Isb_App_DigIn[AppIndex].Cfg3 & ISB_APP_DIGIN_CFG3_DIMMER_STEP_MASK);
															Isb_Obj[Obj_2].IsChanged = TRUE;
														}
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_0)
														{
															// Dunkler
															Isb_Obj[Obj_2].Data[0] = (Isb_App_DigIn[AppIndex].Cfg3 & ISB_APP_DIGIN_CFG3_DIMMER_STEP_MASK);
															Isb_Obj[Obj_2].IsChanged = TRUE;
														}
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_0)
														{
															// Heller/Dunkler
															if (bit_is_clear(Isb_App_DigIn[AppIndex].Cfg3, ISB_APP_DIGIN_CFG3_DIMMER_DIRECTION))
															{
																Isb_Obj[Obj_2].Data[0] = (1 << ISB_APP_DIGIN_CFG3_DIMMER_DIRECTION);
															}
															Isb_Obj[Obj_2].Data[0] &= ~ISB_APP_DIGIN_CFG3_DIMMER_STEP_MASK;
															Isb_Obj[Obj_2].Data[0] |= (Isb_App_DigIn[AppIndex].Cfg3 & ISB_APP_DIGIN_CFG3_DIMMER_STEP_MASK);
															Isb_Obj[Obj_2].IsChanged = TRUE;
														}
														Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHLONG);
													}
													if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHREPEAT))
													{
														// Dimmen
														Isb_Obj[Obj_2].IsChanged = TRUE;
														Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHREPEAT);
													}
													break;
											#endif /* ISB_APP_DIGIN_MODE_FEATURE_DIMMER_FUNCTION_DUS == TRUE */
											#if ISB_APP_DIGIN_MODE_FEATURE_DIMMER_FUNCTION_ND == TRUE
												case ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_1:
													// Nur Dimmen
													if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGH))
													{
														// Dimmen
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_0)
														{
															// Heller
															Isb_Obj[Obj_2].Data[0] = (1 << ISB_APP_DIGIN_CFG3_DIMMER_DIRECTION) | (Isb_App_DigIn[AppIndex].Cfg3 & ISB_APP_DIGIN_CFG3_DIMMER_STEP_MASK);
															Isb_Obj[Obj_2].IsChanged = TRUE;
														}
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_0)
														{
															// Dunkler
															Isb_Obj[Obj_2].Data[0] = (Isb_App_DigIn[AppIndex].Cfg3 & ISB_APP_DIGIN_CFG3_DIMMER_STEP_MASK);
															Isb_Obj[Obj_2].IsChanged = TRUE;
														}
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_0)
														{
															// Heller/Dunkler
															if (bit_is_clear(Isb_App_DigIn[AppIndex].Cfg3, ISB_APP_DIGIN_CFG3_DIMMER_DIRECTION))
															{
																Isb_Obj[Obj_2].Data[0] = (1 << ISB_APP_DIGIN_CFG3_DIMMER_DIRECTION);
															}
															Isb_Obj[Obj_2].Data[0] &= ~ISB_APP_DIGIN_CFG3_DIMMER_STEP_MASK;
															Isb_Obj[Obj_2].Data[0] |= (Isb_App_DigIn[AppIndex].Cfg3 & ISB_APP_DIGIN_CFG3_DIMMER_STEP_MASK);
															Isb_Obj[Obj_2].IsChanged = TRUE;
														}
														Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGH);
													}
													if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHREPEAT))
													{
														// Dimmen
														Isb_Obj[Obj_2].IsChanged = TRUE;
														Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHREPEAT);
													}
													break;
											#endif /* ISB_APP_DIGIN_MODE_FEATURE_DIMMER_FUNCTION_ND == TRUE */
										}
										break;
								#endif /* ISB_APP_DIGIN_MODE_FEATURE_DIMMER == TRUE */
								#if ISB_APP_DIGIN_MODE_FEATURE_JALOUSIE == TRUE
									case ISB_APP_DIGIN_CFG1_MODE_JALOUSIE:
										// Betriebsart = Jalousiesensor
										switch (Isb_App_DigIn[AppIndex].Cfg1 & ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_MASK)
										{
											#if ISB_APP_DIGIN_MODE_FEATURE_JALOUSIE_FUNCTION_1TBKLLF == TRUE
												case ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_0:
													// Option 1-Taster-Betrieb (Kurz=Lamelle, Lang=Fahren)
													if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHSHORT))
													{
														// Stop / Lamelle Auf/Zu
														if (Isb_Obj[Obj_2].Data[0] == 0)
														{
															Isb_Obj[Obj_2].Data[0] = 1;
														}
														else
														{
															Isb_Obj[Obj_2].Data[0] = 0;
														}
														Isb_Obj[Obj_2].IsChanged = TRUE;
														Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHSHORT);
													}
													if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHLONG))
													{
														// Fahren Auf / Zu
														if (Isb_Obj[Obj_1].Data[0] == 0)
														{
															Isb_Obj[Obj_1].Data[0] = 1;
														}
														else
														{
															Isb_Obj[Obj_1].Data[0] = 0;
														}
														Isb_Obj[Obj_1].IsChanged = TRUE;
														Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHLONG);
													}
													break;
											#endif /* ISB_APP_DIGIN_MODE_FEATURE_JALOUSIE_FUNCTION_1TBKLLF == TRUE */
											#if ISB_APP_DIGIN_MODE_FEATURE_JALOUSIE_FUNCTION_1TBKFLL == TRUE
												case ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_1:
													// Option 1-Taster-Betrieb (Kurz=Fahren, Lang=Lamelle)
													if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHSHORT))
													{
														// Fahren Auf / Zu
														if (Isb_Obj[Obj_1].Data[0] == 0)
														{
															Isb_Obj[Obj_1].Data[0] = 1;
														}
														else
														{
															Isb_Obj[Obj_1].Data[0] = 0;
														}
														Isb_Obj[Obj_1].IsChanged = TRUE;
														Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHSHORT);
													}
													if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHLONG))
													{
														// Stop / Lamelle Auf/Zu
														if (Isb_Obj[Obj_2].Data[0] == 0)
														{
															Isb_Obj[Obj_2].Data[0] = 1;
														}
														else
														{
															Isb_Obj[Obj_2].Data[0] = 0;
														}
														Isb_Obj[Obj_2].IsChanged = TRUE;
														Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHLONG);
													}
													if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHREPEAT))
													{
														Isb_Obj[Obj_2].IsChanged = TRUE;
														Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHREPEAT);
													}
													break;
											#endif /* ISB_APP_DIGIN_MODE_FEATURE_JALOUSIE_FUNCTION_1TBKFLL == TRUE */
											#if ISB_APP_DIGIN_MODE_FEATURE_JALOUSIE_FUNCTION_1TBNFS == TRUE
												case ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_2:
													// Option 1-Taster-Betrieb (nur Fahren - Stop)
													if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGH))
													{
														// Fahren Auf
														if ((Isb_Obj[Obj_2].Data[0] == 0) & (Isb_Obj[Obj_1].Data[0] == 0))
														{
															Isb_Obj[Obj_1].Data[0] = 1;
															Isb_Obj[Obj_1].IsChanged = TRUE;
														}
														// Stop
														if ((Isb_Obj[Obj_2].Data[0] == 0) & (Isb_Obj[Obj_1].Data[0] == 1))
														{
															Isb_Obj[Obj_2].Data[0] = 1;
															Isb_Obj[Obj_2].IsChanged = TRUE;
														}
														// Fahren Ab
														if ((Isb_Obj[Obj_2].Data[0] == 1) & (Isb_Obj[Obj_1].Data[0] == 1))
														{
															Isb_Obj[Obj_1].Data[0] = 0;
															Isb_Obj[Obj_1].IsChanged = TRUE;
														}
														// Stop
														if ((Isb_Obj[Obj_2].Data[0] == 1) & (Isb_Obj[Obj_1].Data[0] == 0))
														{
															Isb_Obj[Obj_2].Data[0] = 0;
															Isb_Obj[Obj_2].IsChanged = TRUE;
														}
														Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGH);
													}
													break;
											#endif /* ISB_APP_DIGIN_MODE_FEATURE_JALOUSIE_FUNCTION_1TBNFS == TRUE */
											#if ISB_APP_DIGIN_MODE_FEATURE_JALOUSIE_FUNCTION_1SBNF == TRUE
												case ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_3:
													// Option 1-Schalter-Betrieb (nur Fahren)
													if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGH))
													{
														// Fahren Ab
														Isb_Obj[Obj_1].Data[0] = 1;
														Isb_Obj[Obj_1].IsChanged = TRUE;
														Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHSHORT);
													}
													if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_LOW))
													{
														// Fahren Auf
														Isb_Obj[Obj_1].Data[0] = 0;
														Isb_Obj[Obj_1].IsChanged = TRUE;
														Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHSHORT);
													}
													break;
											#endif /* ISB_APP_DIGIN_MODE_FEATURE_JALOUSIE_FUNCTION_1SBNF == TRUE */
											#if ISB_APP_DIGIN_MODE_FEATURE_JALOUSIE_FUNCTION_2TBKLLF == TRUE
												case ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_4:
													// Option 2-Taster-Betrieb (Kurz=Lamelle, Lang=Fahren)
													if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHSHORT))
													{
														// Stop / Lamelle Auf/Zu
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_0)
														{
															Isb_Obj[Obj_2].Data[0] = 0;
														}
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_1)
														{
															Isb_Obj[Obj_2].Data[0] = 1;
														}
														Isb_Obj[Obj_2].IsChanged = TRUE;
														Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHSHORT);
													}
													if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHLONG))
													{
														// Fahren Auf / Zu
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_0)
														{
															Isb_Obj[Obj_1].Data[0] = 0;
														}
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_1)
														{
															Isb_Obj[Obj_1].Data[0] = 1;
														}
														Isb_Obj[Obj_1].IsChanged = TRUE;
														Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHLONG);
													}
													break;
											#endif /* ISB_APP_DIGIN_MODE_FEATURE_JALOUSIE_FUNCTION_2TBKLLF == TRUE */
											#if ISB_APP_DIGIN_MODE_FEATURE_JALOUSIE_FUNCTION_2TBNF == TRUE
												case ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_5:
													// Option 2-Schalter/Taster-Betrieb (nur Fahren)
													if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGH))
													{
														// Fahren Auf / Zu
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_0)
														{
															Isb_Obj[Obj_1].Data[0] = 0;
														}
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_1)
														{
															Isb_Obj[Obj_1].Data[0] = 1;
														}
														Isb_Obj[Obj_1].IsChanged = TRUE;
														Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHSHORT);
													}
													break;
											#endif /* ISB_APP_DIGIN_MODE_FEATURE_JALOUSIE_FUNCTION_2TBNF == TRUE */
											#if ISB_APP_DIGIN_MODE_FEATURE_JALOUSIE_FUNCTION_2TBNFS == TRUE
												case ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_6:
													// Option 2-Taster-Betrieb (nur Fahren - Stop)
													if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGH))
													{
														// Fahren Auf / Zu
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_0)
														{
															// Fahren Auf
															if ((Isb_Obj[Obj_2].Data[0] == 0) & (Isb_Obj[Obj_1].Data[0] == 0))
															{
																Isb_Obj[Obj_1].Data[0] = 1;
																Isb_Obj[Obj_1].IsChanged = TRUE;
															}
															// Stop
															if ((Isb_Obj[Obj_2].Data[0] == 0) & (Isb_Obj[Obj_1].Data[0] == 1))
															{
																Isb_Obj[Obj_2].Data[0] = 1;
																Isb_Obj[Obj_2].IsChanged = TRUE;
															}
														}
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_1)
														{
															// Fahren Ab
															if ((Isb_Obj[Obj_2].Data[0] == 1) & (Isb_Obj[Obj_1].Data[0] == 1))
															{
																Isb_Obj[Obj_1].Data[0] = 0;
																Isb_Obj[Obj_1].IsChanged = TRUE;
															}
															// Stop
															if ((Isb_Obj[Obj_2].Data[0] == 1) & (Isb_Obj[Obj_1].Data[0] == 0))
															{
																Isb_Obj[Obj_2].Data[0] = 0;
																Isb_Obj[Obj_2].IsChanged = TRUE;
															}
														}
													}
													break;
											#endif /* ISB_APP_DIGIN_MODE_FEATURE_JALOUSIE_FUNCTION_2TBNFS == TRUE */
											#if ISB_APP_DIGIN_MODE_FEATURE_JALOUSIE_FUNCTION_2TBNL == TRUE
												case ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_7:
													// Option 2-Taster-Betrieb (nur Lamelle)
													if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGH))
													{
														// Stop / Lamellen Auf / Zu
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_0)
														{
															Isb_Obj[Obj_2].Data[0] = 0;
														}
														if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_1)
														{
															Isb_Obj[Obj_2].Data[0] = 1;
														}
														Isb_Obj[Obj_2].IsChanged = TRUE;
														Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGH);
													}
													if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHREPEAT))
													{
														Isb_Obj[Obj_2].IsChanged = TRUE;
														Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHREPEAT);
													}
													break;
											#endif /* ISB_APP_DIGIN_MODE_FEATURE_JALOUSIE_FUNCTION_2TBNL == TRUE */
										}
										break;
								#endif /* ISB_APP_DIGIN_MODE_FEATURE_JALOUSIE == TRUE */
								#if ISB_APP_DIGIN_MODE_FEATURE_xx == TRUE
// TODO: ISB_APP_DIGIN_MODE_FEATURE_xx
									case ISB_APP_DIGIN_CFG1_MODE_xx:
										// Betriebsart = Wert/Zwangsführung
										break;
								#endif /* ISB_APP_DIGIN_MODE_FEATURE_xx == TRUE */
								#if ISB_APP_DIGIN_MODE_FEATURE_xx == TRUE
// TODO: ISB_APP_DIGIN_MODE_FEATURE_xx
									case ISB_APP_DIGIN_CFG1_MODE_xx:
										// Betriebsart = Szene steuern
										break;
								#endif /* ISB_APP_DIGIN_MODE_FEATURE_xx == TRUE */
								#if ISB_APP_DIGIN_MODE_FEATURE_xx == TRUE
// TODO: ISB_APP_DIGIN_MODE_FEATURE_xx
									case ISB_APP_DIGIN_CFG1_MODE_xx:
										// Betriebsart = Schaltfolgen
										break;
								#endif /* ISB_APP_DIGIN_MODE_FEATURE_xx == TRUE */
								#if ISB_APP_DIGIN_MODE_FEATURE_xx == TRUE
// TODO: ISB_APP_DIGIN_MODE_FEATURE_xx
									case ISB_APP_DIGIN_CFG1_MODE_xx:
										// Betriebsart = Mehrfachbetätigung
										break;
								#endif /* ISB_APP_DIGIN_MODE_FEATURE_xx == TRUE */
								#if ISB_APP_DIGIN_MODE_FEATURE_COUNTER == TRUE
// TODO: ISB_APP_DIGIN_MODE_FEATURE_COUNTER
// Von Antimon erklären lassen was hier passieren soll
									case ISB_APP_DIGIN_CFG1_MODE_COUNTER:
										// Betriebsart = Impulszähler
										break;
								#endif /* ISB_APP_DIGIN_MODE_FEATURE_COUNTER == TRUE */
							}
//						}
					}
				}
				Isb_App_DigIn_Ctrl &= ~(1 << ISB_CTRL_SOFTIRQ_EXEC);
			}
		#endif /* ISB_APP_DIGIN_MAX */

		#if defined(ISB_APP_DIGOUT_MAX)
			if (bit_is_set(Isb_App_DigOut_Ctrl, ISB_CTRL_SOFTIRQ_EXEC))
			{
				for (uint8_t AppIndex = 0; AppIndex < ISB_APP_DIGOUT_MAX; AppIndex++)
				{
					uint8_t Ch = pgm_read_byte(&pgmIsb_App_DigOut_Ch_Array[AppIndex]);
					uint8_t Obj_0 = pgm_read_byte(&pgmIsb_App_DigOut_Obj_0_Array[AppIndex]);
					#if ISB_APP_DIGOUT_FEATURE_RESULT == TRUE
						uint8_t Obj_1 = pgm_read_byte(&pgmIsb_App_DigOut_Obj_1_Array[AppIndex]);
					#endif /* ISB_APP_DIGOUT_FEATURE_RESULT == TRUE */
					#if ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE
						uint8_t Obj_2 = pgm_read_byte(&pgmIsb_App_DigOut_Obj_2_Array[AppIndex]);
					#endif /* ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE */
					#if ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE
						uint8_t Obj_3 = pgm_read_byte(&pgmIsb_App_DigOut_Obj_3_Array[AppIndex]);
					#endif /* ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE */
					// Initialize
					if (bit_is_clear(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_INITIALIZED))
					{
						uint16_t eepAddr_Cfg0 = 0;
						uint16_t eepAddr_Obj_0_Ctrl = 0;
						uint16_t eepAddr_Obj_0_Tov = 0;
						uint16_t eepAddr_Obj_0_InitValue = 0;
						#if ISB_APP_DIGOUT_FEATURE_RESULT == TRUE
							uint16_t eepAddr_Cfg1 = 0;
							uint16_t eepAddr_Obj_1_Ctrl = 0;
							uint16_t eepAddr_Obj_1_Tov = 0;
							uint16_t eepAddr_Obj_1_InitValue = 0;
						#endif /* ISB_APP_DIGOUT_FEATURE_RESULT == TRUE */
						#if ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE
							uint16_t eepAddr_Cfg2 = 0;
							uint16_t eepAddr_Obj_2_Ctrl = 0;
							uint16_t eepAddr_Obj_2_Tov = 0;
							uint16_t eepAddr_Obj_2_InitValue = 0;
						#endif /* ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE */
						#if ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE
							uint16_t eepAddr_Cfg3 = 0;
							uint16_t eepAddr_Cfg4 = 0;
							uint16_t eepAddr_Cfg5 = 0;
							uint16_t eepAddr_Cfg6 = 0;
							uint16_t eepAddr_Cfg7 = 0;
							uint16_t eepAddr_Cfg8 = 0;
							uint16_t eepAddr_Cfg9 = 0;
						#endif /* ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE */
						#if ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE
							uint16_t eepAddr_Cfg10 = 0;
							uint16_t eepAddr_Obj_3_Ctrl = 0;
							uint16_t eepAddr_Obj_3_Tov = 0;
							uint16_t eepAddr_Obj_3_InitValue = 0;
						#endif /* ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE */
						switch (AppIndex)
						{
							#if defined(ISB_APP_DIGOUT_0)
								case 0:
									eepAddr_Cfg0 = ISB_APP_DIGOUT_0_EEADDR_CFG0;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_INITVALUE;
									#if ISB_APP_DIGOUT_FEATURE_RESULT == TRUE
										eepAddr_Cfg1 = ISB_APP_DIGOUT_0_EEADDR_CFG1;
										eepAddr_Obj_1_Ctrl = ISB_APP_DIGOUT_0_OBJ_1_EEADDR_CTRL;
										eepAddr_Obj_1_Tov = ISB_APP_DIGOUT_0_OBJ_1_EEADDR_TOV;
										eepAddr_Obj_1_InitValue = ISB_APP_DIGOUT_0_OBJ_1_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_RESULT == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE
										eepAddr_Cfg2 = ISB_APP_DIGOUT_0_EEADDR_CFG2;
										eepAddr_Obj_2_Ctrl = ISB_APP_DIGOUT_0_OBJ_2_EEADDR_CTRL;
										eepAddr_Obj_2_Tov = ISB_APP_DIGOUT_0_OBJ_2_EEADDR_TOV;
										eepAddr_Obj_2_InitValue = ISB_APP_DIGOUT_0_OBJ_2_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE
										eepAddr_Cfg3 = ISB_APP_DIGOUT_0_EEADDR_CFG3;
										eepAddr_Cfg4 = ISB_APP_DIGOUT_0_EEADDR_CFG4;
										eepAddr_Cfg5 = ISB_APP_DIGOUT_0_EEADDR_CFG5;
										eepAddr_Cfg6 = ISB_APP_DIGOUT_0_EEADDR_CFG6;
										eepAddr_Cfg7 = ISB_APP_DIGOUT_0_EEADDR_CFG7;
										eepAddr_Cfg8 = ISB_APP_DIGOUT_0_EEADDR_CFG8;
										eepAddr_Cfg9 = ISB_APP_DIGOUT_0_EEADDR_CFG9;
									#endif /* ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE
										eepAddr_Cfg10 = ISB_APP_DIGOUT_0_EEADDR_CFG10;
										eepAddr_Obj_3_Ctrl = ISB_APP_DIGOUT_0_OBJ_3_EEADDR_CTRL;
										eepAddr_Obj_3_Tov = ISB_APP_DIGOUT_0_OBJ_3_EEADDR_TOV;
										eepAddr_Obj_3_InitValue = ISB_APP_DIGOUT_0_OBJ_3_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE */
									break;
							#endif /* ISB_APP_DIGOUT_0 */
							#if defined(ISB_APP_DIGOUT_1)
								case 1:
									eepAddr_Cfg0 = ISB_APP_DIGOUT_1_EEADDR_CFG0;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGOUT_1_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGOUT_1_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGOUT_1_OBJ_0_EEADDR_INITVALUE;
									#if ISB_APP_DIGOUT_FEATURE_RESULT == TRUE
										eepAddr_Cfg1 = ISB_APP_DIGOUT_1_EEADDR_CFG1;
										eepAddr_Obj_1_Ctrl = ISB_APP_DIGOUT_1_OBJ_1_EEADDR_CTRL;
										eepAddr_Obj_1_Tov = ISB_APP_DIGOUT_1_OBJ_1_EEADDR_TOV;
										eepAddr_Obj_1_InitValue = ISB_APP_DIGOUT_1_OBJ_1_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_RESULT == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE
										eepAddr_Cfg2 = ISB_APP_DIGOUT_1_EEADDR_CFG2;
										eepAddr_Obj_2_Ctrl = ISB_APP_DIGOUT_1_OBJ_2_EEADDR_CTRL;
										eepAddr_Obj_2_Tov = ISB_APP_DIGOUT_1_OBJ_2_EEADDR_TOV;
										eepAddr_Obj_2_InitValue = ISB_APP_DIGOUT_1_OBJ_2_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE
										eepAddr_Cfg3 = ISB_APP_DIGOUT_1_EEADDR_CFG3;
										eepAddr_Cfg4 = ISB_APP_DIGOUT_1_EEADDR_CFG4;
										eepAddr_Cfg5 = ISB_APP_DIGOUT_1_EEADDR_CFG5;
										eepAddr_Cfg6 = ISB_APP_DIGOUT_1_EEADDR_CFG6;
										eepAddr_Cfg7 = ISB_APP_DIGOUT_1_EEADDR_CFG7;
										eepAddr_Cfg8 = ISB_APP_DIGOUT_1_EEADDR_CFG8;
										eepAddr_Cfg9 = ISB_APP_DIGOUT_1_EEADDR_CFG9;
									#endif /* ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE
										eepAddr_Cfg10 = ISB_APP_DIGOUT_1_EEADDR_CFG10;
										eepAddr_Obj_3_Ctrl = ISB_APP_DIGOUT_1_OBJ_3_EEADDR_CTRL;
										eepAddr_Obj_3_Tov = ISB_APP_DIGOUT_1_OBJ_3_EEADDR_TOV;
										eepAddr_Obj_3_InitValue = ISB_APP_DIGOUT_1_OBJ_3_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE */
									break;
							#endif /* ISB_APP_DIGOUT_1 */
							#if defined(ISB_APP_DIGOUT_2)
								case 2:
									eepAddr_Cfg0 = ISB_APP_DIGOUT_2_EEADDR_CFG0;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGOUT_2_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGOUT_2_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGOUT_2_OBJ_0_EEADDR_INITVALUE;
									#if ISB_APP_DIGOUT_FEATURE_RESULT == TRUE
										eepAddr_Cfg1 = ISB_APP_DIGOUT_2_EEADDR_CFG1;
										eepAddr_Obj_1_Ctrl = ISB_APP_DIGOUT_2_OBJ_1_EEADDR_CTRL;
										eepAddr_Obj_1_Tov = ISB_APP_DIGOUT_2_OBJ_1_EEADDR_TOV;
										eepAddr_Obj_1_InitValue = ISB_APP_DIGOUT_2_OBJ_1_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_RESULT == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE
										eepAddr_Cfg2 = ISB_APP_DIGOUT_2_EEADDR_CFG2;
										eepAddr_Obj_2_Ctrl = ISB_APP_DIGOUT_2_OBJ_2_EEADDR_CTRL;
										eepAddr_Obj_2_Tov = ISB_APP_DIGOUT_2_OBJ_2_EEADDR_TOV;
										eepAddr_Obj_2_InitValue = ISB_APP_DIGOUT_2_OBJ_2_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE
										eepAddr_Cfg3 = ISB_APP_DIGOUT_2_EEADDR_CFG3;
										eepAddr_Cfg4 = ISB_APP_DIGOUT_2_EEADDR_CFG4;
										eepAddr_Cfg5 = ISB_APP_DIGOUT_2_EEADDR_CFG5;
										eepAddr_Cfg6 = ISB_APP_DIGOUT_2_EEADDR_CFG6;
										eepAddr_Cfg7 = ISB_APP_DIGOUT_2_EEADDR_CFG7;
										eepAddr_Cfg8 = ISB_APP_DIGOUT_2_EEADDR_CFG8;
										eepAddr_Cfg9 = ISB_APP_DIGOUT_2_EEADDR_CFG9;
									#endif /* ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE
										eepAddr_Cfg10 = ISB_APP_DIGOUT_2_EEADDR_CFG10;
										eepAddr_Obj_3_Ctrl = ISB_APP_DIGOUT_2_OBJ_3_EEADDR_CTRL;
										eepAddr_Obj_3_Tov = ISB_APP_DIGOUT_2_OBJ_3_EEADDR_TOV;
										eepAddr_Obj_3_InitValue = ISB_APP_DIGOUT_2_OBJ_3_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE */
									break;
							#endif /* ISB_APP_DIGOUT_2 */
							#if defined(ISB_APP_DIGOUT_3)
								case 3:
									eepAddr_Cfg0 = ISB_APP_DIGOUT_3_EEADDR_CFG0;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGOUT_3_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGOUT_3_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGOUT_3_OBJ_0_EEADDR_INITVALUE;
									#if ISB_APP_DIGOUT_FEATURE_RESULT == TRUE
										eepAddr_Cfg1 = ISB_APP_DIGOUT_3_EEADDR_CFG1;
										eepAddr_Obj_1_Ctrl = ISB_APP_DIGOUT_3_OBJ_1_EEADDR_CTRL;
										eepAddr_Obj_1_Tov = ISB_APP_DIGOUT_3_OBJ_1_EEADDR_TOV;
										eepAddr_Obj_1_InitValue = ISB_APP_DIGOUT_3_OBJ_1_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_RESULT == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE
										eepAddr_Cfg2 = ISB_APP_DIGOUT_3_EEADDR_CFG2;
										eepAddr_Obj_2_Ctrl = ISB_APP_DIGOUT_3_OBJ_2_EEADDR_CTRL;
										eepAddr_Obj_2_Tov = ISB_APP_DIGOUT_3_OBJ_2_EEADDR_TOV;
										eepAddr_Obj_2_InitValue = ISB_APP_DIGOUT_3_OBJ_2_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE
										eepAddr_Cfg3 = ISB_APP_DIGOUT_3_EEADDR_CFG3;
										eepAddr_Cfg4 = ISB_APP_DIGOUT_3_EEADDR_CFG4;
										eepAddr_Cfg5 = ISB_APP_DIGOUT_3_EEADDR_CFG5;
										eepAddr_Cfg6 = ISB_APP_DIGOUT_3_EEADDR_CFG6;
										eepAddr_Cfg7 = ISB_APP_DIGOUT_3_EEADDR_CFG7;
										eepAddr_Cfg8 = ISB_APP_DIGOUT_3_EEADDR_CFG8;
										eepAddr_Cfg9 = ISB_APP_DIGOUT_3_EEADDR_CFG9;
									#endif /* ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE
										eepAddr_Cfg10 = ISB_APP_DIGOUT_3_EEADDR_CFG10;
										eepAddr_Obj_3_Ctrl = ISB_APP_DIGOUT_3_OBJ_3_EEADDR_CTRL;
										eepAddr_Obj_3_Tov = ISB_APP_DIGOUT_3_OBJ_3_EEADDR_TOV;
										eepAddr_Obj_3_InitValue = ISB_APP_DIGOUT_3_OBJ_3_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE */
									break;
							#endif /* ISB_APP_DIGOUT_3 */
							#if defined(ISB_APP_DIGOUT_4)
								case 4:
									eepAddr_Cfg0 = ISB_APP_DIGOUT_4_EEADDR_CFG0;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGOUT_4_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGOUT_4_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGOUT_4_OBJ_0_EEADDR_INITVALUE;
									#if ISB_APP_DIGOUT_FEATURE_RESULT == TRUE
										eepAddr_Cfg1 = ISB_APP_DIGOUT_4_EEADDR_CFG1;
										eepAddr_Obj_1_Ctrl = ISB_APP_DIGOUT_4_OBJ_1_EEADDR_CTRL;
										eepAddr_Obj_1_Tov = ISB_APP_DIGOUT_4_OBJ_1_EEADDR_TOV;
										eepAddr_Obj_1_InitValue = ISB_APP_DIGOUT_4_OBJ_1_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_RESULT == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE
										eepAddr_Cfg2 = ISB_APP_DIGOUT_4_EEADDR_CFG2;
										eepAddr_Obj_2_Ctrl = ISB_APP_DIGOUT_4_OBJ_2_EEADDR_CTRL;
										eepAddr_Obj_2_Tov = ISB_APP_DIGOUT_4_OBJ_2_EEADDR_TOV;
										eepAddr_Obj_2_InitValue = ISB_APP_DIGOUT_4_OBJ_2_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE
										eepAddr_Cfg3 = ISB_APP_DIGOUT_4_EEADDR_CFG3;
										eepAddr_Cfg4 = ISB_APP_DIGOUT_4_EEADDR_CFG4;
										eepAddr_Cfg5 = ISB_APP_DIGOUT_4_EEADDR_CFG5;
										eepAddr_Cfg6 = ISB_APP_DIGOUT_4_EEADDR_CFG6;
										eepAddr_Cfg7 = ISB_APP_DIGOUT_4_EEADDR_CFG7;
										eepAddr_Cfg8 = ISB_APP_DIGOUT_4_EEADDR_CFG8;
										eepAddr_Cfg9 = ISB_APP_DIGOUT_4_EEADDR_CFG9;
									#endif /* ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE
										eepAddr_Cfg10 = ISB_APP_DIGOUT_4_EEADDR_CFG10;
										eepAddr_Obj_3_Ctrl = ISB_APP_DIGOUT_4_OBJ_3_EEADDR_CTRL;
										eepAddr_Obj_3_Tov = ISB_APP_DIGOUT_4_OBJ_3_EEADDR_TOV;
										eepAddr_Obj_3_InitValue = ISB_APP_DIGOUT_4_OBJ_3_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE */
									break;
							#endif /* ISB_APP_DIGOUT_4 */
							#if defined(ISB_APP_DIGOUT_5)
								case 5:
									eepAddr_Cfg0 = ISB_APP_DIGOUT_5_EEADDR_CFG0;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGOUT_5_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGOUT_5_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGOUT_5_OBJ_0_EEADDR_INITVALUE;
									#if ISB_APP_DIGOUT_FEATURE_RESULT == TRUE
										eepAddr_Cfg1 = ISB_APP_DIGOUT_5_EEADDR_CFG1;
										eepAddr_Obj_1_Ctrl = ISB_APP_DIGOUT_5_OBJ_1_EEADDR_CTRL;
										eepAddr_Obj_1_Tov = ISB_APP_DIGOUT_5_OBJ_1_EEADDR_TOV;
										eepAddr_Obj_1_InitValue = ISB_APP_DIGOUT_5_OBJ_1_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_RESULT == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE
										eepAddr_Cfg2 = ISB_APP_DIGOUT_5_EEADDR_CFG2;
										eepAddr_Obj_2_Ctrl = ISB_APP_DIGOUT_5_OBJ_2_EEADDR_CTRL;
										eepAddr_Obj_2_Tov = ISB_APP_DIGOUT_5_OBJ_2_EEADDR_TOV;
										eepAddr_Obj_2_InitValue = ISB_APP_DIGOUT_5_OBJ_2_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE
										eepAddr_Cfg3 = ISB_APP_DIGOUT_5_EEADDR_CFG3;
										eepAddr_Cfg4 = ISB_APP_DIGOUT_5_EEADDR_CFG4;
										eepAddr_Cfg5 = ISB_APP_DIGOUT_5_EEADDR_CFG5;
										eepAddr_Cfg6 = ISB_APP_DIGOUT_5_EEADDR_CFG6;
										eepAddr_Cfg7 = ISB_APP_DIGOUT_5_EEADDR_CFG7;
										eepAddr_Cfg8 = ISB_APP_DIGOUT_5_EEADDR_CFG8;
										eepAddr_Cfg9 = ISB_APP_DIGOUT_5_EEADDR_CFG9;
									#endif /* ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE
										eepAddr_Cfg10 = ISB_APP_DIGOUT_5_EEADDR_CFG10;
										eepAddr_Obj_3_Ctrl = ISB_APP_DIGOUT_5_OBJ_3_EEADDR_CTRL;
										eepAddr_Obj_3_Tov = ISB_APP_DIGOUT_5_OBJ_3_EEADDR_TOV;
										eepAddr_Obj_3_InitValue = ISB_APP_DIGOUT_5_OBJ_3_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE */
									break;
							#endif /* ISB_APP_DIGOUT_5 */
							#if defined(ISB_APP_DIGOUT_6)
								case 6:
									eepAddr_Cfg0 = ISB_APP_DIGOUT_6_EEADDR_CFG0;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGOUT_6_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGOUT_6_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGOUT_6_OBJ_0_EEADDR_INITVALUE;
									#if ISB_APP_DIGOUT_FEATURE_RESULT == TRUE
										eepAddr_Cfg1 = ISB_APP_DIGOUT_6_EEADDR_CFG1;
										eepAddr_Obj_1_Ctrl = ISB_APP_DIGOUT_6_OBJ_1_EEADDR_CTRL;
										eepAddr_Obj_1_Tov = ISB_APP_DIGOUT_6_OBJ_1_EEADDR_TOV;
										eepAddr_Obj_1_InitValue = ISB_APP_DIGOUT_6_OBJ_1_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_RESULT == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE
										eepAddr_Cfg2 = ISB_APP_DIGOUT_6_EEADDR_CFG2;
										eepAddr_Obj_2_Ctrl = ISB_APP_DIGOUT_6_OBJ_2_EEADDR_CTRL;
										eepAddr_Obj_2_Tov = ISB_APP_DIGOUT_6_OBJ_2_EEADDR_TOV;
										eepAddr_Obj_2_InitValue = ISB_APP_DIGOUT_6_OBJ_2_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE
										eepAddr_Cfg3 = ISB_APP_DIGOUT_6_EEADDR_CFG3;
										eepAddr_Cfg4 = ISB_APP_DIGOUT_6_EEADDR_CFG4;
										eepAddr_Cfg5 = ISB_APP_DIGOUT_6_EEADDR_CFG5;
										eepAddr_Cfg6 = ISB_APP_DIGOUT_6_EEADDR_CFG6;
										eepAddr_Cfg7 = ISB_APP_DIGOUT_6_EEADDR_CFG7;
										eepAddr_Cfg8 = ISB_APP_DIGOUT_6_EEADDR_CFG8;
										eepAddr_Cfg9 = ISB_APP_DIGOUT_6_EEADDR_CFG9;
									#endif /* ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE
										eepAddr_Cfg10 = ISB_APP_DIGOUT_6_EEADDR_CFG10;
										eepAddr_Obj_3_Ctrl = ISB_APP_DIGOUT_6_OBJ_3_EEADDR_CTRL;
										eepAddr_Obj_3_Tov = ISB_APP_DIGOUT_6_OBJ_3_EEADDR_TOV;
										eepAddr_Obj_3_InitValue = ISB_APP_DIGOUT_6_OBJ_3_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE */
									break;
							#endif /* ISB_APP_DIGOUT_6 */
							#if defined(ISB_APP_DIGOUT_7)
								case 7:
									eepAddr_Cfg0 = ISB_APP_DIGOUT_7_EEADDR_CFG0;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGOUT_7_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGOUT_7_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGOUT_7_OBJ_0_EEADDR_INITVALUE;
									#if ISB_APP_DIGOUT_FEATURE_RESULT == TRUE
										eepAddr_Cfg1 = ISB_APP_DIGOUT_7_EEADDR_CFG1;
										eepAddr_Obj_1_Ctrl = ISB_APP_DIGOUT_7_OBJ_1_EEADDR_CTRL;
										eepAddr_Obj_1_Tov = ISB_APP_DIGOUT_7_OBJ_1_EEADDR_TOV;
										eepAddr_Obj_1_InitValue = ISB_APP_DIGOUT_7_OBJ_1_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_RESULT == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE
										eepAddr_Cfg2 = ISB_APP_DIGOUT_7_EEADDR_CFG2;
										eepAddr_Obj_2_Ctrl = ISB_APP_DIGOUT_7_OBJ_2_EEADDR_CTRL;
										eepAddr_Obj_2_Tov = ISB_APP_DIGOUT_7_OBJ_2_EEADDR_TOV;
										eepAddr_Obj_2_InitValue = ISB_APP_DIGOUT_7_OBJ_2_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE
										eepAddr_Cfg3 = ISB_APP_DIGOUT_7_EEADDR_CFG3;
										eepAddr_Cfg4 = ISB_APP_DIGOUT_7_EEADDR_CFG4;
										eepAddr_Cfg5 = ISB_APP_DIGOUT_7_EEADDR_CFG5;
										eepAddr_Cfg6 = ISB_APP_DIGOUT_7_EEADDR_CFG6;
										eepAddr_Cfg7 = ISB_APP_DIGOUT_7_EEADDR_CFG7;
										eepAddr_Cfg8 = ISB_APP_DIGOUT_7_EEADDR_CFG8;
										eepAddr_Cfg9 = ISB_APP_DIGOUT_7_EEADDR_CFG9;
									#endif /* ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE
										eepAddr_Cfg10 = ISB_APP_DIGOUT_7_EEADDR_CFG10;
										eepAddr_Obj_3_Ctrl = ISB_APP_DIGOUT_7_OBJ_3_EEADDR_CTRL;
										eepAddr_Obj_3_Tov = ISB_APP_DIGOUT_7_OBJ_3_EEADDR_TOV;
										eepAddr_Obj_3_InitValue = ISB_APP_DIGOUT_7_OBJ_3_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE */
									break;
							#endif /* ISB_APP_DIGOUT_7 */
							#if defined(ISB_APP_DIGOUT_8)
								case 8:
									eepAddr_Cfg0 = ISB_APP_DIGOUT_8_EEADDR_CFG0;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGOUT_8_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGOUT_8_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGOUT_8_OBJ_0_EEADDR_INITVALUE;
									#if ISB_APP_DIGOUT_FEATURE_RESULT == TRUE
										eepAddr_Cfg1 = ISB_APP_DIGOUT_8_EEADDR_CFG1;
										eepAddr_Obj_1_Ctrl = ISB_APP_DIGOUT_8_OBJ_1_EEADDR_CTRL;
										eepAddr_Obj_1_Tov = ISB_APP_DIGOUT_8_OBJ_1_EEADDR_TOV;
										eepAddr_Obj_1_InitValue = ISB_APP_DIGOUT_8_OBJ_1_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_RESULT == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE
										eepAddr_Cfg2 = ISB_APP_DIGOUT_8_EEADDR_CFG2;
										eepAddr_Obj_2_Ctrl = ISB_APP_DIGOUT_8_OBJ_2_EEADDR_CTRL;
										eepAddr_Obj_2_Tov = ISB_APP_DIGOUT_8_OBJ_2_EEADDR_TOV;
										eepAddr_Obj_2_InitValue = ISB_APP_DIGOUT_8_OBJ_2_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE
										eepAddr_Cfg3 = ISB_APP_DIGOUT_8_EEADDR_CFG3;
										eepAddr_Cfg4 = ISB_APP_DIGOUT_8_EEADDR_CFG4;
										eepAddr_Cfg5 = ISB_APP_DIGOUT_8_EEADDR_CFG5;
										eepAddr_Cfg6 = ISB_APP_DIGOUT_8_EEADDR_CFG6;
										eepAddr_Cfg7 = ISB_APP_DIGOUT_8_EEADDR_CFG7;
										eepAddr_Cfg8 = ISB_APP_DIGOUT_8_EEADDR_CFG8;
										eepAddr_Cfg9 = ISB_APP_DIGOUT_8_EEADDR_CFG9;
									#endif /* ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE
										eepAddr_Cfg10 = ISB_APP_DIGOUT_8_EEADDR_CFG10;
										eepAddr_Obj_3_Ctrl = ISB_APP_DIGOUT_8_OBJ_3_EEADDR_CTRL;
										eepAddr_Obj_3_Tov = ISB_APP_DIGOUT_8_OBJ_3_EEADDR_TOV;
										eepAddr_Obj_3_InitValue = ISB_APP_DIGOUT_8_OBJ_3_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE */
									break;
							#endif /* ISB_APP_DIGOUT_8 */
							#if defined(ISB_APP_DIGOUT_9)
								case 9:
									eepAddr_Cfg0 = ISB_APP_DIGOUT_9_EEADDR_CFG0;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGOUT_9_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGOUT_9_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGOUT_9_OBJ_0_EEADDR_INITVALUE;
									#if ISB_APP_DIGOUT_FEATURE_RESULT == TRUE
										eepAddr_Cfg1 = ISB_APP_DIGOUT_9_EEADDR_CFG1;
										eepAddr_Obj_1_Ctrl = ISB_APP_DIGOUT_9_OBJ_1_EEADDR_CTRL;
										eepAddr_Obj_1_Tov = ISB_APP_DIGOUT_9_OBJ_1_EEADDR_TOV;
										eepAddr_Obj_1_InitValue = ISB_APP_DIGOUT_9_OBJ_1_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_RESULT == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE
										eepAddr_Cfg2 = ISB_APP_DIGOUT_9_EEADDR_CFG2;
										eepAddr_Obj_2_Ctrl = ISB_APP_DIGOUT_9_OBJ_2_EEADDR_CTRL;
										eepAddr_Obj_2_Tov = ISB_APP_DIGOUT_9_OBJ_2_EEADDR_TOV;
										eepAddr_Obj_2_InitValue = ISB_APP_DIGOUT_9_OBJ_2_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE
										eepAddr_Cfg3 = ISB_APP_DIGOUT_9_EEADDR_CFG3;
										eepAddr_Cfg4 = ISB_APP_DIGOUT_9_EEADDR_CFG4;
										eepAddr_Cfg5 = ISB_APP_DIGOUT_9_EEADDR_CFG5;
										eepAddr_Cfg6 = ISB_APP_DIGOUT_9_EEADDR_CFG6;
										eepAddr_Cfg7 = ISB_APP_DIGOUT_9_EEADDR_CFG7;
										eepAddr_Cfg8 = ISB_APP_DIGOUT_9_EEADDR_CFG8;
										eepAddr_Cfg9 = ISB_APP_DIGOUT_9_EEADDR_CFG9;
									#endif /* ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE
										eepAddr_Cfg10 = ISB_APP_DIGOUT_9_EEADDR_CFG10;
										eepAddr_Obj_3_Ctrl = ISB_APP_DIGOUT_9_OBJ_3_EEADDR_CTRL;
										eepAddr_Obj_3_Tov = ISB_APP_DIGOUT_9_OBJ_3_EEADDR_TOV;
										eepAddr_Obj_3_InitValue = ISB_APP_DIGOUT_9_OBJ_3_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE */
									break;
							#endif /* ISB_APP_DIGOUT_9 */
							#if defined(ISB_APP_DIGOUT_10)
								case 10:
									eepAddr_Cfg0 = ISB_APP_DIGOUT_10_EEADDR_CFG0;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGOUT_10_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGOUT_10_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGOUT_10_OBJ_0_EEADDR_INITVALUE;
									#if ISB_APP_DIGOUT_FEATURE_RESULT == TRUE
										eepAddr_Cfg1 = ISB_APP_DIGOUT_10_EEADDR_CFG1;
										eepAddr_Obj_1_Ctrl = ISB_APP_DIGOUT_10_OBJ_1_EEADDR_CTRL;
										eepAddr_Obj_1_Tov = ISB_APP_DIGOUT_10_OBJ_1_EEADDR_TOV;
										eepAddr_Obj_1_InitValue = ISB_APP_DIGOUT_10_OBJ_1_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_RESULT == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE
										eepAddr_Cfg2 = ISB_APP_DIGOUT_10_EEADDR_CFG2;
										eepAddr_Obj_2_Ctrl = ISB_APP_DIGOUT_10_OBJ_2_EEADDR_CTRL;
										eepAddr_Obj_2_Tov = ISB_APP_DIGOUT_10_OBJ_2_EEADDR_TOV;
										eepAddr_Obj_2_InitValue = ISB_APP_DIGOUT_10_OBJ_2_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE
										eepAddr_Cfg3 = ISB_APP_DIGOUT_10_EEADDR_CFG3;
										eepAddr_Cfg4 = ISB_APP_DIGOUT_10_EEADDR_CFG4;
										eepAddr_Cfg5 = ISB_APP_DIGOUT_10_EEADDR_CFG5;
										eepAddr_Cfg6 = ISB_APP_DIGOUT_10_EEADDR_CFG6;
										eepAddr_Cfg7 = ISB_APP_DIGOUT_10_EEADDR_CFG7;
										eepAddr_Cfg8 = ISB_APP_DIGOUT_10_EEADDR_CFG8;
										eepAddr_Cfg9 = ISB_APP_DIGOUT_10_EEADDR_CFG9;
									#endif /* ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE
										eepAddr_Cfg10 = ISB_APP_DIGOUT_10_EEADDR_CFG10;
										eepAddr_Obj_3_Ctrl = ISB_APP_DIGOUT_10_OBJ_3_EEADDR_CTRL;
										eepAddr_Obj_3_Tov = ISB_APP_DIGOUT_10_OBJ_3_EEADDR_TOV;
										eepAddr_Obj_3_InitValue = ISB_APP_DIGOUT_10_OBJ_3_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE */
									break;
							#endif /* ISB_APP_DIGOUT_10 */
							#if defined(ISB_APP_DIGOUT_11)
								case 11:
									eepAddr_Cfg0 = ISB_APP_DIGOUT_11_EEADDR_CFG0;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGOUT_11_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGOUT_11_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGOUT_11_OBJ_0_EEADDR_INITVALUE;
									#if ISB_APP_DIGOUT_FEATURE_RESULT == TRUE
										eepAddr_Cfg1 = ISB_APP_DIGOUT_11_EEADDR_CFG1;
										eepAddr_Obj_1_Ctrl = ISB_APP_DIGOUT_11_OBJ_1_EEADDR_CTRL;
										eepAddr_Obj_1_Tov = ISB_APP_DIGOUT_11_OBJ_1_EEADDR_TOV;
										eepAddr_Obj_1_InitValue = ISB_APP_DIGOUT_11_OBJ_1_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_RESULT == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE
										eepAddr_Cfg2 = ISB_APP_DIGOUT_11_EEADDR_CFG2;
										eepAddr_Obj_2_Ctrl = ISB_APP_DIGOUT_11_OBJ_2_EEADDR_CTRL;
										eepAddr_Obj_2_Tov = ISB_APP_DIGOUT_11_OBJ_2_EEADDR_TOV;
										eepAddr_Obj_2_InitValue = ISB_APP_DIGOUT_11_OBJ_2_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE
										eepAddr_Cfg3 = ISB_APP_DIGOUT_11_EEADDR_CFG3;
										eepAddr_Cfg4 = ISB_APP_DIGOUT_11_EEADDR_CFG4;
										eepAddr_Cfg5 = ISB_APP_DIGOUT_11_EEADDR_CFG5;
										eepAddr_Cfg6 = ISB_APP_DIGOUT_11_EEADDR_CFG6;
										eepAddr_Cfg7 = ISB_APP_DIGOUT_11_EEADDR_CFG7;
										eepAddr_Cfg8 = ISB_APP_DIGOUT_11_EEADDR_CFG8;
										eepAddr_Cfg9 = ISB_APP_DIGOUT_11_EEADDR_CFG9;
									#endif /* ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE
										eepAddr_Cfg10 = ISB_APP_DIGOUT_11_EEADDR_CFG10;
										eepAddr_Obj_3_Ctrl = ISB_APP_DIGOUT_11_OBJ_3_EEADDR_CTRL;
										eepAddr_Obj_3_Tov = ISB_APP_DIGOUT_11_OBJ_3_EEADDR_TOV;
										eepAddr_Obj_3_InitValue = ISB_APP_DIGOUT_11_OBJ_3_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE */
									break;
							#endif /* ISB_APP_DIGOUT_11 */
							#if defined(ISB_APP_DIGOUT_12)
								case 12:
									eepAddr_Cfg0 = ISB_APP_DIGOUT_12_EEADDR_CFG0;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGOUT_12_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGOUT_12_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGOUT_12_OBJ_0_EEADDR_INITVALUE;
									#if ISB_APP_DIGOUT_FEATURE_RESULT == TRUE
										eepAddr_Cfg1 = ISB_APP_DIGOUT_12_EEADDR_CFG1;
										eepAddr_Obj_1_Ctrl = ISB_APP_DIGOUT_12_OBJ_1_EEADDR_CTRL;
										eepAddr_Obj_1_Tov = ISB_APP_DIGOUT_12_OBJ_1_EEADDR_TOV;
										eepAddr_Obj_1_InitValue = ISB_APP_DIGOUT_12_OBJ_1_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_RESULT == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE
										eepAddr_Cfg2 = ISB_APP_DIGOUT_12_EEADDR_CFG2;
										eepAddr_Obj_2_Ctrl = ISB_APP_DIGOUT_12_OBJ_2_EEADDR_CTRL;
										eepAddr_Obj_2_Tov = ISB_APP_DIGOUT_12_OBJ_2_EEADDR_TOV;
										eepAddr_Obj_2_InitValue = ISB_APP_DIGOUT_12_OBJ_2_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE
										eepAddr_Cfg3 = ISB_APP_DIGOUT_12_EEADDR_CFG3;
										eepAddr_Cfg4 = ISB_APP_DIGOUT_12_EEADDR_CFG4;
										eepAddr_Cfg5 = ISB_APP_DIGOUT_12_EEADDR_CFG5;
										eepAddr_Cfg6 = ISB_APP_DIGOUT_12_EEADDR_CFG6;
										eepAddr_Cfg7 = ISB_APP_DIGOUT_12_EEADDR_CFG7;
										eepAddr_Cfg8 = ISB_APP_DIGOUT_12_EEADDR_CFG8;
										eepAddr_Cfg9 = ISB_APP_DIGOUT_12_EEADDR_CFG9;
									#endif /* ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE
										eepAddr_Cfg10 = ISB_APP_DIGOUT_12_EEADDR_CFG10;
										eepAddr_Obj_3_Ctrl = ISB_APP_DIGOUT_12_OBJ_3_EEADDR_CTRL;
										eepAddr_Obj_3_Tov = ISB_APP_DIGOUT_12_OBJ_3_EEADDR_TOV;
										eepAddr_Obj_3_InitValue = ISB_APP_DIGOUT_12_OBJ_3_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE */
									break;
							#endif /* ISB_APP_DIGOUT_12 */
							#if defined(ISB_APP_DIGOUT_13)
								case 13:
									eepAddr_Cfg0 = ISB_APP_DIGOUT_13_EEADDR_CFG0;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGOUT_13_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGOUT_13_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGOUT_13_OBJ_0_EEADDR_INITVALUE;
									#if ISB_APP_DIGOUT_FEATURE_RESULT == TRUE
										eepAddr_Cfg1 = ISB_APP_DIGOUT_13_EEADDR_CFG1;
										eepAddr_Obj_1_Ctrl = ISB_APP_DIGOUT_13_OBJ_1_EEADDR_CTRL;
										eepAddr_Obj_1_Tov = ISB_APP_DIGOUT_13_OBJ_1_EEADDR_TOV;
										eepAddr_Obj_1_InitValue = ISB_APP_DIGOUT_13_OBJ_1_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_RESULT == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE
										eepAddr_Cfg2 = ISB_APP_DIGOUT_13_EEADDR_CFG2;
										eepAddr_Obj_2_Ctrl = ISB_APP_DIGOUT_13_OBJ_2_EEADDR_CTRL;
										eepAddr_Obj_2_Tov = ISB_APP_DIGOUT_13_OBJ_2_EEADDR_TOV;
										eepAddr_Obj_2_InitValue = ISB_APP_DIGOUT_13_OBJ_2_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE
										eepAddr_Cfg3 = ISB_APP_DIGOUT_13_EEADDR_CFG3;
										eepAddr_Cfg4 = ISB_APP_DIGOUT_13_EEADDR_CFG4;
										eepAddr_Cfg5 = ISB_APP_DIGOUT_13_EEADDR_CFG5;
										eepAddr_Cfg6 = ISB_APP_DIGOUT_13_EEADDR_CFG6;
										eepAddr_Cfg7 = ISB_APP_DIGOUT_13_EEADDR_CFG7;
										eepAddr_Cfg8 = ISB_APP_DIGOUT_13_EEADDR_CFG8;
										eepAddr_Cfg9 = ISB_APP_DIGOUT_13_EEADDR_CFG9;
									#endif /* ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE
										eepAddr_Cfg10 = ISB_APP_DIGOUT_13_EEADDR_CFG10;
										eepAddr_Obj_3_Ctrl = ISB_APP_DIGOUT_13_OBJ_3_EEADDR_CTRL;
										eepAddr_Obj_3_Tov = ISB_APP_DIGOUT_13_OBJ_3_EEADDR_TOV;
										eepAddr_Obj_3_InitValue = ISB_APP_DIGOUT_13_OBJ_3_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE */
									break;
							#endif /* ISB_APP_DIGOUT_13 */
							#if defined(ISB_APP_DIGOUT_14)
								case 14:
									eepAddr_Cfg0 = ISB_APP_DIGOUT_14_EEADDR_CFG0;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGOUT_14_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGOUT_14_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGOUT_14_OBJ_0_EEADDR_INITVALUE;
									#if ISB_APP_DIGOUT_FEATURE_RESULT == TRUE
										eepAddr_Cfg1 = ISB_APP_DIGOUT_14_EEADDR_CFG1;
										eepAddr_Obj_1_Ctrl = ISB_APP_DIGOUT_14_OBJ_1_EEADDR_CTRL;
										eepAddr_Obj_1_Tov = ISB_APP_DIGOUT_14_OBJ_1_EEADDR_TOV;
										eepAddr_Obj_1_InitValue = ISB_APP_DIGOUT_14_OBJ_1_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_RESULT == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE
										eepAddr_Cfg2 = ISB_APP_DIGOUT_14_EEADDR_CFG2;
										eepAddr_Obj_2_Ctrl = ISB_APP_DIGOUT_14_OBJ_2_EEADDR_CTRL;
										eepAddr_Obj_2_Tov = ISB_APP_DIGOUT_14_OBJ_2_EEADDR_TOV;
										eepAddr_Obj_2_InitValue = ISB_APP_DIGOUT_14_OBJ_2_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE
										eepAddr_Cfg3 = ISB_APP_DIGOUT_14_EEADDR_CFG3;
										eepAddr_Cfg4 = ISB_APP_DIGOUT_14_EEADDR_CFG4;
										eepAddr_Cfg5 = ISB_APP_DIGOUT_14_EEADDR_CFG5;
										eepAddr_Cfg6 = ISB_APP_DIGOUT_14_EEADDR_CFG6;
										eepAddr_Cfg7 = ISB_APP_DIGOUT_14_EEADDR_CFG7;
										eepAddr_Cfg8 = ISB_APP_DIGOUT_14_EEADDR_CFG8;
										eepAddr_Cfg9 = ISB_APP_DIGOUT_14_EEADDR_CFG9;
									#endif /* ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE
										eepAddr_Cfg10 = ISB_APP_DIGOUT_14_EEADDR_CFG10;
										eepAddr_Obj_3_Ctrl = ISB_APP_DIGOUT_14_OBJ_3_EEADDR_CTRL;
										eepAddr_Obj_3_Tov = ISB_APP_DIGOUT_14_OBJ_3_EEADDR_TOV;
										eepAddr_Obj_3_InitValue = ISB_APP_DIGOUT_14_OBJ_3_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE */
									break;
							#endif /* ISB_APP_DIGOUT_14 */
							#if defined(ISB_APP_DIGOUT_15)
								case 15:
									eepAddr_Cfg0 = ISB_APP_DIGOUT_15_EEADDR_CFG0;
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGOUT_15_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGOUT_15_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGOUT_15_OBJ_0_EEADDR_INITVALUE;
									#if ISB_APP_DIGOUT_FEATURE_RESULT == TRUE
										eepAddr_Cfg1 = ISB_APP_DIGOUT_15_EEADDR_CFG1;
										eepAddr_Obj_1_Ctrl = ISB_APP_DIGOUT_15_OBJ_1_EEADDR_CTRL;
										eepAddr_Obj_1_Tov = ISB_APP_DIGOUT_15_OBJ_1_EEADDR_TOV;
										eepAddr_Obj_1_InitValue = ISB_APP_DIGOUT_15_OBJ_1_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_RESULT == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE
										eepAddr_Cfg2 = ISB_APP_DIGOUT_15_EEADDR_CFG2;
										eepAddr_Obj_2_Ctrl = ISB_APP_DIGOUT_15_OBJ_2_EEADDR_CTRL;
										eepAddr_Obj_2_Tov = ISB_APP_DIGOUT_15_OBJ_2_EEADDR_TOV;
										eepAddr_Obj_2_InitValue = ISB_APP_DIGOUT_15_OBJ_2_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE
										eepAddr_Cfg3 = ISB_APP_DIGOUT_15_EEADDR_CFG3;
										eepAddr_Cfg4 = ISB_APP_DIGOUT_15_EEADDR_CFG4;
										eepAddr_Cfg5 = ISB_APP_DIGOUT_15_EEADDR_CFG5;
										eepAddr_Cfg6 = ISB_APP_DIGOUT_15_EEADDR_CFG6;
										eepAddr_Cfg7 = ISB_APP_DIGOUT_15_EEADDR_CFG7;
										eepAddr_Cfg8 = ISB_APP_DIGOUT_15_EEADDR_CFG8;
										eepAddr_Cfg9 = ISB_APP_DIGOUT_15_EEADDR_CFG9;
									#endif /* ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE
										eepAddr_Cfg10 = ISB_APP_DIGOUT_15_EEADDR_CFG10;
										eepAddr_Obj_3_Ctrl = ISB_APP_DIGOUT_15_OBJ_3_EEADDR_CTRL;
										eepAddr_Obj_3_Tov = ISB_APP_DIGOUT_15_OBJ_3_EEADDR_TOV;
										eepAddr_Obj_3_InitValue = ISB_APP_DIGOUT_15_OBJ_3_EEADDR_INITVALUE;
									#endif /* ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE */
									break;
							#endif /* ISB_APP_DIGOUT_15 */
						}
						Isb_Ch[Ch].Ctrl = Isb_Ch_Ctrl_Get(Ch);
						if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_ENABLED))
						{
							Isb_App_DigOut[AppIndex].Cfg0 = lib_eep_fw_read_byte((uint8_t *)eepAddr_Cfg0);
							Isb_Obj[Obj_0].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_0_Ctrl);
							Isb_Obj[Obj_0].Top = ISB_MSG_TOP_1BIT;
							Isb_Obj[Obj_0].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_0_Tov);
							for (uint8_t i = 0; i < 5; i++)
							{
								Isb_Obj[Obj_0].Data[i] = lib_eep_fw_read_byte((uint8_t *)(eepAddr_Obj_0_InitValue + i));
							}
							Isb_Obj[Obj_0].IsChanged = FALSE;
							#if ISB_APP_DIGOUT_FEATURE_RESULT == TRUE
								Isb_App_DigOut[AppIndex].Cfg1 = lib_eep_fw_read_byte((uint8_t *)eepAddr_Cfg1);
								Isb_Obj[Obj_1].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_1_Ctrl);
								Isb_Obj[Obj_1].Top = ISB_MSG_TOP_1BIT;
								Isb_Obj[Obj_1].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_1_Tov);
								for (uint8_t i = 0; i < 5; i++)
								{
									Isb_Obj[Obj_1].Data[i] = lib_eep_fw_read_byte((uint8_t *)(eepAddr_Obj_1_InitValue + i));
								}
								Isb_Obj[Obj_1].IsChanged = FALSE;
							#endif /* ISB_APP_DIGOUT_FEATURE_RESULT == TRUE */
							#if ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE
								Isb_App_DigOut[AppIndex].Cfg2 = lib_eep_fw_read_byte((uint8_t *)eepAddr_Cfg2);
								Isb_Obj[Obj_2].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_2_Ctrl);
								Isb_Obj[Obj_2].Top = ISB_MSG_TOP_1BIT;
								Isb_Obj[Obj_2].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_2_Tov);
								for (uint8_t i = 0; i < 5; i++)
								{
									Isb_Obj[Obj_2].Data[i] = lib_eep_fw_read_byte((uint8_t *)(eepAddr_Obj_2_InitValue + i));
								}
								Isb_Obj[Obj_2].IsChanged = FALSE;
							#endif /* ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE */
							#if ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE
								Isb_App_DigOut[AppIndex].Cfg3 = lib_eep_fw_read_byte((uint8_t *)eepAddr_Cfg3);
								Isb_App_DigOut[AppIndex].Cfg4 = lib_eep_fw_read_byte((uint8_t *)eepAddr_Cfg4);
								Isb_App_DigOut[AppIndex].Cfg5 = lib_eep_fw_read_byte((uint8_t *)eepAddr_Cfg5);
								Isb_App_DigOut[AppIndex].Cfg6 = lib_eep_fw_read_byte((uint8_t *)eepAddr_Cfg6);
								Isb_App_DigOut[AppIndex].Cfg7 = lib_eep_fw_read_byte((uint8_t *)eepAddr_Cfg7);
								Isb_App_DigOut[AppIndex].Cfg8 = lib_eep_fw_read_byte((uint8_t *)eepAddr_Cfg8);
								Isb_App_DigOut[AppIndex].Cfg9 = lib_eep_fw_read_byte((uint8_t *)eepAddr_Cfg9);
							#endif /* ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE */
							#if ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE
								Isb_App_DigOut[AppIndex].Cfg10 = lib_eep_fw_read_byte((uint8_t *)eepAddr_Cfg10);
								Isb_Obj[Obj_3].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_3_Ctrl);
								Isb_Obj[Obj_3].Top = ISB_MSG_TOP_1BIT;
								Isb_Obj[Obj_3].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_3_Tov);
								for (uint8_t i = 0; i < 5; i++)
								{
									Isb_Obj[Obj_3].Data[i] = lib_eep_fw_read_byte((uint8_t *)(eepAddr_Obj_3_InitValue + i));
								}
								Isb_Obj[Obj_3].IsChanged = FALSE;
							#endif /* ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE */
						}
						Isb_Ch[Ch].Ctrl |= (1<<ISB_CH_CTRL_INITIALIZED);
					}
					// Exec
					if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_ENABLED))
					{
						uint8_t Value = Isb_App_DigOut[AppIndex].Value;
						uint8_t IsChanged = Isb_App_DigOut[AppIndex].IsChanged;
						// Logikfunktion
						#if ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE
							switch (Isb_App_DigOut[AppIndex].Cfg2 & ISB_APP_DIGOUT_CFG2_LOGIC_MODE_MASK)
							{
								#if ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION_AND == TRUE
									case ISB_APP_DIGOUT_CFG2_LOGIC_MODE_AND:
										if ((Isb_Obj[Obj_0].Data[0] != FALSE) & (Isb_Obj[Obj_2].Data[0] != FALSE))
										{
											if (Isb_App_DigOut[AppIndex].LogicValue != TRUE)
											{
												Isb_App_DigOut[AppIndex].LogicValue = TRUE;
												Isb_App_DigOut[AppIndex].LogicIsChanged = TRUE;
											}
										}
										else
										{
											if (Isb_App_DigOut[AppIndex].LogicValue != FALSE)
											{
												Isb_App_DigOut[AppIndex].LogicValue = FALSE;
												Isb_App_DigOut[AppIndex].LogicIsChanged = TRUE;
											}
										}
										Isb_Obj[Obj_0].IsChanged = FALSE;
										Isb_Obj[Obj_2].IsChanged = FALSE;
										break;
								#endif /* ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION_AND == TRUE */
								#if ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION_OR == TRUE
									case ISB_APP_DIGOUT_CFG2_LOGIC_MODE_OR:
										if ((Isb_Obj[Obj_0].Data[0] != FALSE) | (Isb_Obj[Obj_2].Data[0] != FALSE))
										{
											if (Isb_App_DigOut[AppIndex].LogicValue != TRUE)
											{
												Isb_App_DigOut[AppIndex].LogicValue = TRUE;
												Isb_App_DigOut[AppIndex].LogicIsChanged = TRUE;
											}
										}
										else
										{
											if (Isb_App_DigOut[AppIndex].LogicValue != FALSE)
											{
												Isb_App_DigOut[AppIndex].LogicValue = FALSE;
												Isb_App_DigOut[AppIndex].LogicIsChanged = TRUE;
											}
										}
										Isb_Obj[Obj_0].IsChanged = FALSE;
										Isb_Obj[Obj_2].IsChanged = FALSE;
										break;
								#endif /* ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION_OR == TRUE */
								default:
									if (Isb_App_DigOut[AppIndex].LogicValue != Isb_Obj[Obj_0].Data[0])
									{
										Isb_App_DigOut[AppIndex].LogicValue = Isb_Obj[Obj_0].Data[0];
										Isb_App_DigOut[AppIndex].LogicIsChanged = TRUE;
									}
									Isb_Obj[Obj_0].IsChanged = FALSE;
									break;
							}
							Value = Isb_App_DigOut[AppIndex].LogicValue;
							IsChanged = Isb_App_DigOut[AppIndex].LogicIsChanged;
						#else /* ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE */
							if (Value != Isb_Obj[Obj_0].Data[0])
							{
								Value = Isb_Obj[Obj_0].Data[0];
								IsChanged = TRUE;
							}
							Isb_Obj[Obj_0].IsChanged = FALSE;
						#endif /* ISB_APP_DIGOUT_FEATURE_LOGICFUNCTION == TRUE */
						// Zeitfunktion
						#if ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE
							switch (Isb_App_DigOut[AppIndex].Cfg3 & ISB_APP_DIGOUT_CFG3_TIME_MODE_MASK)
							{
								#if ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION_POWERUPDELAY == TRUE | ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION_POWERDOWNDELAY == TRUE
									case ISB_APP_DIGOUT_CFG3_TIME_MODE_DELAY:
										#if ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION_POWERUPDELAY == TRUE
											if (bit_is_set(Isb_App_DigOut[AppIndex].Cfg3, ISB_APP_DIGOUT_CFG3_TIME_POWERUPDELAY_ENABLED))
											{
												if (Value == TRUE)
												{
													if (Isb_App_DigOut[AppIndex].TimeOnCount != 0)
													{
														Isb_App_DigOut[AppIndex].TimeOnCount--;
														Value = FALSE;
													}
												}
												else
												{
													Isb_App_DigOut[AppIndex].TimeOnCount = (Isb_App_DigOut[AppIndex].Cfg4 + Isb_App_DigOut[AppIndex].Cfg5 * 60 + Isb_App_DigOut[AppIndex].Cfg6 * 60 * 60) * 1000 / ISB_APP_DIGOUT_EXECTIME;
												}
											}
										#endif /* ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION_POWERUPDELAY == TRUE */
										#if ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION_POWERDOWNDELAY == TRUE
											if (bit_is_set(Isb_App_DigOut[AppIndex].Cfg3, ISB_APP_DIGOUT_CFG3_TIME_POWERDOWNDELAY_ENABLED))
											{
												if (Value == FALSE)
												{
													if (Isb_App_DigOut[AppIndex].TimeOffCount != 0)
													{
														Isb_App_DigOut[AppIndex].TimeOffCount--;
														Value = TRUE;
													}
												}
												else
												{
													Isb_App_DigOut[AppIndex].TimeOffCount = (Isb_App_DigOut[AppIndex].Cfg7 + Isb_App_DigOut[AppIndex].Cfg8 * 60 + Isb_App_DigOut[AppIndex].Cfg9 * 60 * 60) * 1000 / ISB_APP_DIGOUT_EXECTIME;
												}
											}
										#endif /* ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION_POWERDOWNDELAY == TRUE */
									break;
								#endif /* ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION_POWERUPDELAY == TRUE | ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION_POWERDOWNDELAY == TRUE */
								#if ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION_STAIRCASEFUNCTION == TRUE
									case ISB_APP_DIGOUT_CFG3_TIME_MODE_STAIRCASEFUNCTION:
										if (Value == FALSE)
										{
											if (Isb_App_DigOut[AppIndex].TimeOffCount != 0)
											{
												Isb_App_DigOut[AppIndex].TimeOffCount--;
												Value = TRUE;
											}
											if ((bit_is_set(Isb_App_DigOut[AppIndex].Cfg3, ISB_APP_DIGOUT_CFG3_TIME_RETRIGGER_ENABLED)) | (Isb_App_DigOut[AppIndex].TimeOnCount == 0))
											{
												if (bit_is_set(Isb_App_DigOut[AppIndex].Cfg3, ISB_APP_DIGOUT_CFG3_TIME_PUMP_ENABLED))
												{
													Isb_App_DigOut[AppIndex].TimeOnCount += (Isb_App_DigOut[AppIndex].Cfg4 + Isb_App_DigOut[AppIndex].Cfg5 * 60 + Isb_App_DigOut[AppIndex].Cfg6 * 60 * 60) * 1000 / ISB_APP_DIGOUT_EXECTIME;
												}
												else
												{
													Isb_App_DigOut[AppIndex].TimeOnCount = (Isb_App_DigOut[AppIndex].Cfg4 + Isb_App_DigOut[AppIndex].Cfg5 * 60 + Isb_App_DigOut[AppIndex].Cfg6 * 60 * 60) * 1000 / ISB_APP_DIGOUT_EXECTIME;
												}
											}
										}
										else
										{
											Isb_App_DigOut[AppIndex].TimeOffCount = (Isb_App_DigOut[AppIndex].Cfg7 + Isb_App_DigOut[AppIndex].Cfg8 * 60 + Isb_App_DigOut[AppIndex].Cfg9 * 60 * 60) * 1000 / ISB_APP_DIGOUT_EXECTIME;
										}
										break;
								#endif /* ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION_STAIRCASEFUNCTION == TRUE */
								default:
									break;
							}
							if (Isb_App_DigOut[AppIndex].TimeValue != Value)
							{
								Isb_App_DigOut[AppIndex].TimeValue = Value;
								Isb_App_DigOut[AppIndex].TimeIsChanged = TRUE;
							}
						#endif /* ISB_APP_DIGOUT_FEATURE_TIMEFUNCTION == TRUE */
						// Spezialfunktion
						#if ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE
							if (Isb_Obj[Obj_3].IsChanged == TRUE)
							{
								switch (Isb_App_DigOut[AppIndex].Cfg10 & ISB_APP_DIGOUT_CFG10_SPECIAL_MODE_MASK)
								{
									#if ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION_BLOCKING == TRUE
										// Sperrfunktion
										case ISB_APP_DIGOUT_CFG10_SPECIAL_MODE_BLOCKINGFUNCTION:
											if (((Isb_Obj[Obj_3].Data[0] == 1) & (bit_is_clear(Isb_App_DigOut[AppIndex].Cfg10, ISB_APP_DIGOUT_CFG10_SPECIAL_BLOCKINGFUNCTION_INVERTED))) | ((Isb_Obj[Obj_3].Data[0] == 0) & (bit_is_set(Isb_App_DigOut[AppIndex].Cfg10, ISB_APP_DIGOUT_CFG10_SPECIAL_BLOCKINGFUNCTION_INVERTED))))
											{
												// Activiert
												// Verhalten zu Beginn der Sperrfunktion
												if ((Isb_App_DigOut[AppIndex].Cfg10 & ISB_APP_DIGOUT_CFG10_SPECIAL_BLOCKINGFUNCTION_ACTION_ON_MASK) == ISB_APP_DIGOUT_CFG10_SPECIAL_BLOCKINGFUNCTION_ACTION_ON_NONE)
												{
													// -> keine Änderung des Schaltzustandes
													Isb_App_DigOut[AppIndex].Special_Action = 11;
												}
												if ((Isb_App_DigOut[AppIndex].Cfg10 & ISB_APP_DIGOUT_CFG10_SPECIAL_BLOCKINGFUNCTION_ACTION_ON_MASK) == ISB_APP_DIGOUT_CFG10_SPECIAL_BLOCKINGFUNCTION_ACTION_ON_OFF)
												{
													// -> ausschalten
													Isb_App_DigOut[AppIndex].Special_Action = 12;
												}
												if ((Isb_App_DigOut[AppIndex].Cfg10 & ISB_APP_DIGOUT_CFG10_SPECIAL_BLOCKINGFUNCTION_ACTION_ON_MASK) == ISB_APP_DIGOUT_CFG10_SPECIAL_BLOCKINGFUNCTION_ACTION_ON_ON)
												{
													// -> einschalten
													Isb_App_DigOut[AppIndex].Special_Action = 13;
												}
												if ((Isb_App_DigOut[AppIndex].Cfg10 & ISB_APP_DIGOUT_CFG10_SPECIAL_BLOCKINGFUNCTION_ACTION_ON_MASK) == ISB_APP_DIGOUT_CFG10_SPECIAL_BLOCKINGFUNCTION_ACTION_ON_BLINK)
												{
													// -> blinken
													Isb_App_DigOut[AppIndex].Special_Action = 14;
												}
											}
											else
											{
												// Deaktiviert
												// Verhalten am Ende der Sperrfunktion
												if ((Isb_App_DigOut[AppIndex].Cfg10 & ISB_APP_DIGOUT_CFG10_SPECIAL_BLOCKINGFUNCTION_ACTION_OFF_MASK) == ISB_APP_DIGOUT_CFG10_SPECIAL_BLOCKINGFUNCTION_ACTION_OFF_NONE)
												{
													// -> keine Änderung des Schaltzustandes
													Isb_App_DigOut[AppIndex].Special_Action = 01;
												}
												if ((Isb_App_DigOut[AppIndex].Cfg10 & ISB_APP_DIGOUT_CFG10_SPECIAL_BLOCKINGFUNCTION_ACTION_OFF_MASK) == ISB_APP_DIGOUT_CFG10_SPECIAL_BLOCKINGFUNCTION_ACTION_OFF_OFF)
												{
													// -> ausschalten
													Isb_App_DigOut[AppIndex].Special_Action = 02;
												}
												if ((Isb_App_DigOut[AppIndex].Cfg10 & ISB_APP_DIGOUT_CFG10_SPECIAL_BLOCKINGFUNCTION_ACTION_OFF_MASK) == ISB_APP_DIGOUT_CFG10_SPECIAL_BLOCKINGFUNCTION_ACTION_OFF_ON)
												{
													// -> einschalten
													Isb_App_DigOut[AppIndex].Special_Action = 03;
												}
												if ((Isb_App_DigOut[AppIndex].Cfg10 & ISB_APP_DIGOUT_CFG10_SPECIAL_BLOCKINGFUNCTION_ACTION_OFF_MASK) == ISB_APP_DIGOUT_CFG10_SPECIAL_BLOCKINGFUNCTION_ACTION_OFFF_REAL)
												{
													// -> nachgeführten Zustand einstellen
													Isb_App_DigOut[AppIndex].Special_Action = 00;
												}
												if ((Isb_App_DigOut[AppIndex].Cfg10 & ISB_APP_DIGOUT_CFG10_SPECIAL_BLOCKINGFUNCTION_ACTION_OFF_MASK) == ISB_APP_DIGOUT_CFG10_SPECIAL_BLOCKINGFUNCTION_ACTION_OFF_BLINK)
												{
													// -> blinken
													Isb_App_DigOut[AppIndex].Special_Action = 04;
												}
											}
											break;
									#endif /* ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION_BLOCKING == TRUE */
									#if ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION_BONDAGE == TRUE
										// Zwangsstellungsfunktion
										case ISB_APP_DIGOUT_CFG10_SPECIAL_MODE_BONDAGEFUNCTION:
											if (((Isb_Obj[Obj_3].Data[0] == 1) & (bit_is_clear(Isb_App_DigOut[AppIndex].Cfg10, ISB_APP_DIGOUT_CFG10_SPECIAL_BONDAGEFUNCTION_INVERTED))) | ((Isb_Obj[Obj_3].Data[0] == 0) & (bit_is_set(Isb_App_DigOut[AppIndex].Cfg10, ISB_APP_DIGOUT_CFG10_SPECIAL_BONDAGEFUNCTION_INVERTED))))
											{
												// Aktiviert
												// Verhalten am Anfang der Zwangsstellung
												// -> keine Änderung des Schaltzustandes
												Isb_App_DigOut[AppIndex].Special_Action = 01;
											}
											else
											{
												// Deaktiviert
												// Verhalten am Ende der Zwangsstellung
												if ((Isb_App_DigOut[AppIndex].Cfg10 & ISB_APP_DIGOUT_CFG10_SPECIAL_BONDAGEFUNCTION_ACTION_OFF_MASK) == ISB_APP_DIGOUT_CFG10_SPECIAL_BONDAGEFUNCTION_ACTION_OFF_NONE)
												{
													// -> keine Änderung des Schaltzustandes
													Isb_App_DigOut[AppIndex].Special_Action = 01;
												}
												if ((Isb_App_DigOut[AppIndex].Cfg10 & ISB_APP_DIGOUT_CFG10_SPECIAL_BONDAGEFUNCTION_ACTION_OFF_MASK) == ISB_APP_DIGOUT_CFG10_SPECIAL_BONDAGEFUNCTION_ACTION_OFF_OFF)
												{
													// -> ausschalten
													Isb_App_DigOut[AppIndex].Special_Action = 02;
												}
												if ((Isb_App_DigOut[AppIndex].Cfg10 & ISB_APP_DIGOUT_CFG10_SPECIAL_BONDAGEFUNCTION_ACTION_OFF_MASK) == ISB_APP_DIGOUT_CFG10_SPECIAL_BONDAGEFUNCTION_ACTION_OFF_ON)
												{
													// -> einschalten
													Isb_App_DigOut[AppIndex].Special_Action = 03;
												}
												if ((Isb_App_DigOut[AppIndex].Cfg10 & ISB_APP_DIGOUT_CFG10_SPECIAL_BONDAGEFUNCTION_ACTION_OFF_MASK) == ISB_APP_DIGOUT_CFG10_SPECIAL_BONDAGEFUNCTION_ACTION_OFF_REAL)
												{
													// -> nachgeführten Zustand einstellen
													Isb_App_DigOut[AppIndex].Special_Action = 00;
												}
											}
											break;
									#endif /* ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION_BONDAGE == TRUE */
									default:
										Isb_App_DigOut[AppIndex].Special_Action = 00;
										break;
								}
								Isb_Obj[Obj_3].IsChanged = FALSE;
							}
							switch (Isb_App_DigOut[AppIndex].Special_Action)
							{
								case 01:
									//  Ende - keine Änderung des Schaltzustandes
									Value = Isb_App_DigOut[AppIndex].Value;
									IsChanged = Isb_App_DigOut[AppIndex].IsChanged;
									break;
								case 02:
									// Ende - ausschalten
									if (Value != FALSE)
									{
										Value = FALSE;
										IsChanged = TRUE;
									}
									Isb_App_DigOut[AppIndex].Special_Action = 01;
									break;
								case 03:
									// Ende - einschalten
									if (Value != TRUE)
									{
										Value = TRUE;
										IsChanged = TRUE;
									}
									Isb_App_DigOut[AppIndex].Special_Action = 01;
									break;
								case 04:
									// Ende - blinken
// TODO: Blinker mit systick realisieren
//									if (Value != Blinker_Value)
//									{
//										Value = Blinker_Value;
										IsChanged = TRUE;
//									}
									Isb_App_DigOut[AppIndex].Special_Action = 01;
									break;
								case 11:
									//  Beginn - keine Änderung des Schaltzustandes
									Value = Isb_App_DigOut[AppIndex].Value;
									IsChanged = Isb_App_DigOut[AppIndex].IsChanged;
									break;
								case 12:
									// Beginn - ausschalten
									if (Value != FALSE)
									{
										Value = FALSE;
										IsChanged = TRUE;
									}
									Isb_App_DigOut[AppIndex].Special_Action = 11;
									break;
								case 13:
									// Beginn - einschalten
									if (Value != TRUE)
									{
										Value = TRUE;
										IsChanged = TRUE;
									}
									Isb_App_DigOut[AppIndex].Special_Action = 11;
									break;
								case 14:
									// Beginn - blinken
// TODO: Blinker mit systick realisieren
//									if (Value != Blinker_Value)
//									{
//										Value = Blinker_Value;
										IsChanged = TRUE;
//									}
									Isb_App_DigOut[AppIndex].Special_Action = 11;
									break;
								default:
									// nachgeführten Zustand einstellen
									break;
							}
						#endif /* ISB_APP_DIGOUT_FEATURE_SPECIALFUNCTION == TRUE */
						// Ausgang
						Isb_App_DigOut[AppIndex].Value = Value;
						Isb_App_DigOut[AppIndex].IsChanged = IsChanged;
						uint8_t Pin0 = pgm_read_byte(&pgmIsb_App_DigOut_Pin0_Array[AppIndex]);
						#if (ISB_APP_DIGOUT_DESTINATION_FEATURE_SSR == TRUE) | (ISB_APP_DIGOUT_FEATURE_RESULT == TRUE)
							uint8_t Pin1 = pgm_read_byte(&pgmIsb_App_DigOut_Pin1_Array[AppIndex]);
						#endif /* (ISB_APP_DIGOUT_DESTINATION_FEATURE_SSR == TRUE) | (ISB_APP_DIGOUT_FEATURE_RESULT == TRUE) */
						switch (Isb_App_DigOut[AppIndex].Cfg0 & ISB_APP_DIGOUT_CFG0_OPERATION_MASK)
						{
							#if ISB_APP_DIGOUT_DESTINATION_FEATURE_RELAIS == TRUE
								case ISB_APP_DIGOUT_CFG0_OPERATION_STD:
									if (Isb_App_DigOut[AppIndex].IsChanged == TRUE)
									{
										if (bit_is_set(Isb_App_DigOut[AppIndex].Value, 0))
										{
											uint8_t Port = (Pin0 & ISB_APP_DIGOUT_PIN0_MASKPORT) >> 3;
											uint8_t Pin = Pin0 & ISB_APP_DIGOUT_PIN0_MASKPIN;
											if (Port != 0)
											{
												if (bit_is_clear(Isb_App_DigOut[AppIndex].Cfg0, ISB_APP_DIGOUT_CFG0_PIN0_INVERTED))
												{
													Lib_Pin_Set(Port, Pin, LIB_PIN_OUTPUT_LOW);
												}
												else
												{
													Lib_Pin_Set(Port, Pin, LIB_PIN_OUTPUT_HIGH);
												}
											}
										}
										else
										{
											uint8_t Port = (Pin0 & ISB_APP_DIGOUT_PIN0_MASKPORT) >> 3;
											uint8_t Pin = Pin0 & ISB_APP_DIGOUT_PIN0_MASKPIN;
											if (Port != 0)
											{
												if (bit_is_clear(Isb_App_DigOut[AppIndex].Cfg0, ISB_APP_DIGOUT_CFG0_PIN0_INVERTED))
												{
													Lib_Pin_Set(Port, Pin, LIB_PIN_OUTPUT_HIGH);
												}
												else
												{
													Lib_Pin_Set(Port, Pin, LIB_PIN_OUTPUT_LOW);
												}
											}
										}
										Isb_App_DigOut[AppIndex].IsChanged = FALSE;
									}
									break;
							#endif /* ISB_APP_DIGOUT_DESTINATION_FEATURE_RELAIS == TRUE */
							#if ISB_APP_DIGOUT_DESTINATION_FEATURE_SSR == TRUE
								case ISB_APP_DIGOUT_CFG0_OPERATION_SSR:
									if (Isb_App_DigOut[AppIndex].IsChanged == TRUE)
									{
										if (bit_is_clear(Isb_App_DigOut[AppIndex].Cfg0, ISB_APP_DIGOUT_CFG0_PIN1_ENABLED))
										{
											Isb_App_DigOut[AppIndex].Counter = 1000 / ISB_APP_DIGOUT_EXECTIME;
										}
										else
										{
											Isb_App_DigOut[AppIndex].Counter = 5000 / ISB_APP_DIGOUT_EXECTIME;
										}
										Isb_App_DigOut[AppIndex].IsChanged = FALSE;
									}
									// Impuls
									if (Isb_App_DigOut[AppIndex].Counter != 0)
									{
										Isb_App_DigOut[AppIndex].Counter--;
										// Kontrolleingang
										if (bit_is_set(Isb_App_DigOut[AppIndex].Cfg0, ISB_APP_DIGOUT_CFG0_PIN1_ENABLED))
										{
											uint8_t Port = (Pin1 & ISB_APP_DIGOUT_PIN1_MASKPORT) >> 3;
											uint8_t Pin = Pin1 & ISB_APP_DIGOUT_PIN1_MASKPIN;
											if (bit_is_set(Isb_App_DigOut[AppIndex].Cfg0, ISB_APP_DIGOUT_CFG0_PIN1_PULLUP))
											{
												Lib_Pin_Set(Port, Pin, LIB_PIN_INPUT_PULLUP);
											}
											else
											{
												Lib_Pin_Set(Port, Pin, LIB_PIN_INPUT);
											}
											uint8_t State = 0;
											State = Lib_Pin_Get(Port, Pin);
											if (bit_is_set(Isb_App_DigOut[AppIndex].Cfg0, ISB_APP_DIGOUT_CFG0_PIN1_INVERTED))
											{
												if (State != 0)
												{
													State = 0;
												}
												else
												{
													State = 1;
												}
											}
											if (State == Isb_App_DigOut[AppIndex].Value)
											{
												Isb_App_DigOut[AppIndex].Counter = 0;
											}
										}
										// Impuls
										uint8_t Port = (Pin0 & ISB_APP_DIGOUT_PIN0_MASKPORT) >> 3;
										uint8_t Pin = Pin0 & ISB_APP_DIGOUT_PIN0_MASKPIN;
										if ((Isb_App_DigOut[AppIndex].Counter / (500 / ISB_APP_DIGOUT_EXECTIME)) % 2 != 0)
										{
											// Impuls Start
											if (bit_is_clear(Isb_App_DigOut[AppIndex].Cfg0, ISB_APP_DIGOUT_CFG0_PIN0_INVERTED))
											{
												Lib_Pin_Set(Port, Pin, LIB_PIN_OUTPUT_LOW);
											}
											else
											{
												Lib_Pin_Set(Port, Pin, LIB_PIN_OUTPUT_HIGH);
											}
										}
										else
										{
											// Impuls Ende
											Lib_Pin_Set(Port, Pin, LIB_PIN_OUTPUT_TRISTATE);
										}
									}
									break;
							#endif /* ISB_APP_DIGOUT_DESTINATION_FEATURE_SSR == TRUE */
							#if ISB_APP_DIGOUT_DESTINATION_FEATURE_SLAVE_USART0 == TRUE
								case ISB_APP_DIGOUT_CFG0_OPERATION_SLAVEUSART0:
									if (Isb_App_DigOut[AppIndex].IsChanged == TRUE)
									{
										#if defined(ISB_INF_USART0_SLAVE)
											Isb_Msg_t Isb_Slave_Msg;
											Isb_Slave_Msg.Flags = ISB_MSG_FLAGS_TOF_MULTICAST | ISB_MSG_FLAGS_DLC_4;
											Isb_Slave_Msg.SourceId = 0;
											Isb_Slave_Msg.DestId = Isb_Prg_Index;
											Isb_Slave_Msg.Data[0] = ISB_MSG_TOP_1BIT;
											Isb_Slave_Msg.Data[1] = ISB_MSG_CTRL_CMD_WRITE;
											Isb_Slave_Msg.Data[2] = ISB_MSG_TOP_1BIT_TOV_BOOL;
											Isb_Slave_Msg.Data[3] = Isb_App_DigOut[AppIndex].Value;
											Isb_Inf_Usart_Slave_Tx(0, &Isb_Slave_Msg);
										#endif /* ISB_INF_USART0_SLAVE */
										Isb_App_DigOut[AppIndex].IsChanged = FALSE;
									}
									break;
							#endif /* ISB_APP_DIGOUT_DESTINATION_FEATURE_SLAVE_USART0 == TRUE */
							#if ISB_APP_DIGOUT_DESTINATION_FEATURE_SLAVE_USART1 == TRUE
								case ISB_APP_DIGOUT_CFG0_OPERATION_SLAVEUSART1:
									if (Isb_App_DigOut[AppIndex].IsChanged == TRUE)
									{
										#if defined(ISB_INF_USART1_SLAVE)
											Isb_Msg_t Isb_Slave_Msg;
											Isb_Slave_Msg.Flags = ISB_MSG_FLAGS_TOF_MULTICAST | ISB_MSG_FLAGS_DLC_4;
											Isb_Slave_Msg.SourceId = 0;
											Isb_Slave_Msg.DestId = Isb_Prg_Index;
											Isb_Slave_Msg.Data[0] = ISB_MSG_TOP_1BIT;
											Isb_Slave_Msg.Data[1] = ISB_MSG_CTRL_CMD_WRITE;
											Isb_Slave_Msg.Data[2] = ISB_MSG_TOP_1BIT_TOV_BOOL;
											Isb_Slave_Msg.Data[3] = Isb_App_DigOut[AppIndex].Value;
											Isb_Inf_Usart_Slave_Tx(1, &Isb_Slave_Msg);
										#endif /* ISB_INF_USART1_SLAVE */
										Isb_App_DigOut[AppIndex].IsChanged = FALSE;
									}
									break;
							#endif /* ISB_APP_DIGOUT_DESTINATION_FEATURE_SLAVE_USART1 == TRUE */
							default:
// TODO:
//	Set Global DigOut Error
//	Clear Channel Enabled
								break;
						}
						// Rückmeldungsfunktion
						#if ISB_APP_DIGOUT_FEATURE_RESULT == TRUE
							uint8_t Result = 0;
							if (bit_is_set(Isb_App_DigOut[AppIndex].Cfg0, ISB_APP_DIGOUT_CFG0_PIN1_ENABLED))
							{
								uint8_t Port = (Pin1 & ISB_APP_DIGOUT_PIN1_MASKPORT) >> 3;
								uint8_t Pin = Pin1 & ISB_APP_DIGOUT_PIN1_MASKPIN;
								if (bit_is_set(Isb_App_DigOut[AppIndex].Cfg0, ISB_APP_DIGOUT_CFG0_PIN1_PULLUP))
								{
									Lib_Pin_Set(Port, Pin, LIB_PIN_INPUT_PULLUP);
								}
								else
								{
									Lib_Pin_Set(Port, Pin, LIB_PIN_INPUT);
								}
								Lib_Pin_Set(Port, Pin, LIB_PIN_INPUT_PULLUP);
								Result = Lib_Pin_Get(Port, Pin);
								if (bit_is_set(Isb_App_DigOut[AppIndex].Cfg0, ISB_APP_DIGOUT_CFG0_PIN1_INVERTED))
								{
									if (Result != 0)
									{
										Result = 0;
									}
									else
									{
										Result = 1;
									}
								}
							}
							else
							{
								Result = 0;
								if ((Isb_App_DigOut[AppIndex].Value == 1) & (bit_is_clear(Isb_App_DigOut[AppIndex].Cfg1, ISB_APP_DIGOUT_CFG1_RESULT_INVERTED)))
								{
									Result = 1;
								}
								if ((Isb_App_DigOut[AppIndex].Value == 0) & (bit_is_set(Isb_App_DigOut[AppIndex].Cfg1, ISB_APP_DIGOUT_CFG1_RESULT_INVERTED)))
								{
									Result = 1;
								}
							}
							if (Isb_Obj[Obj_1].Data[0] != Result)
							{
								Isb_Obj[Obj_1].Data[0] = Result;
								Isb_Obj[Obj_1].IsChanged = TRUE;
							}
						#endif /* ISB_APP_DIGOUT_FEATURE_RESULT == TRUE */
					}
				}
				Isb_App_DigOut_Ctrl &= ~(1 << ISB_CTRL_SOFTIRQ_EXEC);
			}
		#endif /* ISB_APP_DIGOUT_MAX */

		#if defined(ISB_APP_LCD_MAX)
			if (bit_is_set(Isb_App_Lcd_Ctrl, ISB_CTRL_SOFTIRQ_EXEC))
			{
// TODO: ->
// TODO: Alles



//Lcd_Clear();
//char Buffer[20];
//itoa(Isb_App_Float_Sensor[AppIndex].Value, Buffer, 10);
//Lcd_String(Buffer);
//Lcd_SetCursor(0, 2);
//uint16_t Temp = 0;
//itoa(Temp, Buffer, 10);
//Lcd_String(Buffer);



//#				for (uint8_t AppIndex = 0; AppIndex < ISB_APP_LCD_MAX; AppIndex++)
//#				{
//					uint8_t Ch = pgm_read_byte(&pgmIsb_App_Lcd_Ch_Array[AppIndex]);
//					if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_ENABLED))
//					{
//						uint8_t Pin0 = pgm_read_byte(&pgmIsb_App_Lcd_Pin0_Array[AppIndex]);



//					}
//#				}
// TODO: Alles
// TODO: <-
				Isb_App_Lcd_Ctrl &= ~(1 << ISB_CTRL_SOFTIRQ_EXEC);
			}
		#endif /* ISB_APP_LCD_MAX */

		#ifdef ISB_APP_HEATING_DEDIETRICH_CF124SH_MAX
			if (bit_is_set(Isb_App_Heating_Dedietrich_Cf124sh_Ctrl, ISB_CTRL_SOFTIRQ_EXEC))
			{
				for (uint8_t AppIndex = 0; AppIndex < ISB_APP_HEATING_DEDIETRICH_CF124SH_MAX; AppIndex++)
				{
					uint8_t Ch = pgm_read_byte(&pgmIsb_App_Heating_DeDietrich_CF124SH_Ch_Array[AppIndex]);
					// RT = Rücklauftemperatur
					uint8_t Obj_0 = pgm_read_byte(&pgmIsb_App_Heating_DeDietrich_CF124SH_Obj_0_Array[AppIndex]);
					// ET = Eingangstemperatur
					uint8_t Obj_1 = pgm_read_byte(&pgmIsb_App_Heating_DeDietrich_CF124SH_Obj_1_Array[AppIndex]);
					// KT = Kesseltemperatur
					uint8_t Obj_2 = pgm_read_byte(&pgmIsb_App_Heating_DeDietrich_CF124SH_Obj_2_Array[AppIndex]);
					// VT = Vorlauftemperatur
					uint8_t Obj_3 = pgm_read_byte(&pgmIsb_App_Heating_DeDietrich_CF124SH_Obj_3_Array[AppIndex]);
					// RgT = Rauchgastemperatur
					uint8_t Obj_4 = pgm_read_byte(&pgmIsb_App_Heating_DeDietrich_CF124SH_Obj_4_Array[AppIndex]);
					// Meldung "Ein"
					uint8_t Obj_5 = pgm_read_byte(&pgmIsb_App_Heating_DeDietrich_CF124SH_Obj_5_Array[AppIndex]);
					// Betriebsstundenzähler Gesamt
					uint8_t Obj_6 = pgm_read_byte(&pgmIsb_App_Heating_DeDietrich_CF124SH_Obj_6_Array[AppIndex]);
					// Ladepumpe
					uint8_t Obj_7 = pgm_read_byte(&pgmIsb_App_Heating_DeDietrich_CF124SH_Obj_7_Array[AppIndex]);
					// Betriebsstundenzähler Ladepumpe
					uint8_t Obj_8 = pgm_read_byte(&pgmIsb_App_Heating_DeDietrich_CF124SH_Obj_8_Array[AppIndex]);
					// Meldung "Anheizen"
					uint8_t Obj_9 = pgm_read_byte(&pgmIsb_App_Heating_DeDietrich_CF124SH_Obj_9_Array[AppIndex]);
					// Meldung "Feuererhaltung"
					uint8_t Obj_10 = pgm_read_byte(&pgmIsb_App_Heating_DeDietrich_CF124SH_Obj_10_Array[AppIndex]);
					// Meldung "Übertemperatur"
					uint8_t Obj_11 = pgm_read_byte(&pgmIsb_App_Heating_DeDietrich_CF124SH_Obj_11_Array[AppIndex]);
					// Meldung "Untertemperatur Rücklaufanhebung"
					uint8_t Obj_12 = pgm_read_byte(&pgmIsb_App_Heating_DeDietrich_CF124SH_Obj_12_Array[AppIndex]);
					// Meldung "Störung"
					uint8_t Obj_13 = pgm_read_byte(&pgmIsb_App_Heating_DeDietrich_CF124SH_Obj_13_Array[AppIndex]);
					// Initialize
					if (bit_is_clear(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_INITIALIZED))
					{
/*
						uint16_t eepAddr_Cfg0 = 0;
						uint16_t eepAddr_Cfg1 = 0;
						uint16_t eepAddr_Cfg2 = 0;
						uint16_t eepAddr_Cfg3 = 0;
						uint16_t eepAddr_Cfg4 = 0;
						uint16_t eepAddr_Cfg5 = 0;
						uint16_t eepAddr_Cfg6 = 0;
						uint16_t eepAddr_Cfg7 = 0;
						uint16_t eepAddr_Cfg8 = 0;
						uint16_t eepAddr_Cfg9 = 0;
*/
						uint16_t eepAddr_Obj_0_Ctrl = 0;
						uint16_t eepAddr_Obj_0_Tov = 0;
						uint16_t eepAddr_Obj_0_InitValue = 0;
						uint16_t eepAddr_Obj_1_Ctrl = 0;
						uint16_t eepAddr_Obj_1_Tov = 0;
						uint16_t eepAddr_Obj_1_InitValue = 0;
						uint16_t eepAddr_Obj_2_Ctrl = 0;
						uint16_t eepAddr_Obj_2_Tov = 0;
						uint16_t eepAddr_Obj_2_InitValue = 0;
						uint16_t eepAddr_Obj_3_Ctrl = 0;
						uint16_t eepAddr_Obj_3_Tov = 0;
						uint16_t eepAddr_Obj_3_InitValue = 0;
						uint16_t eepAddr_Obj_4_Ctrl = 0;
						uint16_t eepAddr_Obj_4_Tov = 0;
						uint16_t eepAddr_Obj_4_InitValue = 0;
						uint16_t eepAddr_Obj_5_Ctrl = 0;
						uint16_t eepAddr_Obj_5_Tov = 0;
						uint16_t eepAddr_Obj_5_InitValue = 0;
						uint16_t eepAddr_Obj_6_Ctrl = 0;
						uint16_t eepAddr_Obj_6_Tov = 0;
						uint16_t eepAddr_Obj_6_InitValue = 0;
						uint16_t eepAddr_Obj_7_Ctrl = 0;
						uint16_t eepAddr_Obj_7_Tov = 0;
						uint16_t eepAddr_Obj_7_InitValue = 0;
						uint16_t eepAddr_Obj_8_Ctrl = 0;
						uint16_t eepAddr_Obj_8_Tov = 0;
						uint16_t eepAddr_Obj_8_InitValue = 0;
						uint16_t eepAddr_Obj_9_Ctrl = 0;
						uint16_t eepAddr_Obj_9_Tov = 0;
						uint16_t eepAddr_Obj_9_InitValue = 0;
						uint16_t eepAddr_Obj_10_Ctrl = 0;
						uint16_t eepAddr_Obj_10_Tov = 0;
						uint16_t eepAddr_Obj_10_InitValue = 0;
						uint16_t eepAddr_Obj_11_Ctrl = 0;
						uint16_t eepAddr_Obj_11_Tov = 0;
						uint16_t eepAddr_Obj_11_InitValue = 0;
						uint16_t eepAddr_Obj_12_Ctrl = 0;
						uint16_t eepAddr_Obj_12_Tov = 0;
						uint16_t eepAddr_Obj_12_InitValue = 0;
						uint16_t eepAddr_Obj_13_Ctrl = 0;
						uint16_t eepAddr_Obj_13_Tov = 0;
						uint16_t eepAddr_Obj_13_InitValue = 0;
						switch (AppIndex)
						{
							#if defined(ISB_APP_HEATING_DEDIETRICH_CF124SH_0)
								case ISB_APP_HEATING_DEDIETRICH_CF124SH_0:
/*
									eepAddr_Cfg0 = ISB_APP_DIGOUT_0_EEADDR_CFG0;
									eepAddr_Cfg1 = ISB_APP_DIGOUT_0_EEADDR_CFG1;
									eepAddr_Cfg2 = ISB_APP_DIGOUT_0_EEADDR_CFG2;
									eepAddr_Cfg3 = ISB_APP_DIGOUT_0_EEADDR_CFG3;
									eepAddr_Cfg4 = ISB_APP_DIGOUT_0_EEADDR_CFG4;
									eepAddr_Cfg5 = ISB_APP_DIGOUT_0_EEADDR_CFG5;
									eepAddr_Cfg6 = ISB_APP_DIGOUT_0_EEADDR_CFG6;
									eepAddr_Cfg7 = ISB_APP_DIGOUT_0_EEADDR_CFG7;
									eepAddr_Cfg8 = ISB_APP_DIGOUT_0_EEADDR_CFG8;
									eepAddr_Cfg9 = ISB_APP_DIGOUT_0_EEADDR_CFG9;
*/
									eepAddr_Obj_0_Ctrl = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_0_Tov = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_0_InitValue = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_1_Ctrl = ISB_APP_DIGOUT_0_OBJ_1_EEADDR_CTRL;
									eepAddr_Obj_1_Tov = ISB_APP_DIGOUT_0_OBJ_1_EEADDR_TOV;
									eepAddr_Obj_1_InitValue = ISB_APP_DIGOUT_0_OBJ_1_EEADDR_INITVALUE;
									eepAddr_Obj_2_Ctrl = ISB_APP_DIGOUT_0_OBJ_2_EEADDR_CTRL;
									eepAddr_Obj_2_Tov = ISB_APP_DIGOUT_0_OBJ_2_EEADDR_TOV;
									eepAddr_Obj_2_InitValue = ISB_APP_DIGOUT_0_OBJ_2_EEADDR_INITVALUE;
									eepAddr_Obj_3_Ctrl = ISB_APP_DIGOUT_0_OBJ_3_EEADDR_CTRL;
									eepAddr_Obj_3_Tov = ISB_APP_DIGOUT_0_OBJ_3_EEADDR_TOV;
									eepAddr_Obj_3_InitValue = ISB_APP_DIGOUT_0_OBJ_3_EEADDR_INITVALUE;
									eepAddr_Obj_4_Ctrl = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_4_Tov = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_4_InitValue = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_5_Ctrl = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_5_Tov = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_5_InitValue = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_6_Ctrl = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_6_Tov = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_6_InitValue = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_7_Ctrl = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_7_Tov = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_7_InitValue = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_8_Ctrl = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_8_Tov = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_8_InitValue = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_9_Ctrl = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_9_Tov = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_9_InitValue = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_10_Ctrl = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_10_Tov = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_10_InitValue = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_11_Ctrl = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_11_Tov = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_11_InitValue = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_12_Ctrl = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_12_Tov = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_12_InitValue = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_INITVALUE;
									eepAddr_Obj_13_Ctrl = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_CTRL;
									eepAddr_Obj_13_Tov = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_TOV;
									eepAddr_Obj_13_InitValue = ISB_APP_DIGOUT_0_OBJ_0_EEADDR_INITVALUE;
									break;
							#endif /* ISB_APP_HEATING_DEDIETRICH_CF124SH_0 */
						}
						Isb_Ch[Ch].Ctrl = Isb_Ch_Ctrl_Get(Ch);
						if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_ENABLED))
						{
/*
							Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Cfg0 = lib_eep_fw_read_byte((uint8_t *)eepAddr_Cfg0);
							Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Cfg1 = lib_eep_fw_read_byte((uint8_t *)eepAddr_Cfg1);
							Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Cfg2 = lib_eep_fw_read_byte((uint8_t *)eepAddr_Cfg2);
							Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Cfg3 = lib_eep_fw_read_byte((uint8_t *)eepAddr_Cfg3);
							Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Cfg4 = lib_eep_fw_read_byte((uint8_t *)eepAddr_Cfg4);
							Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Cfg5 = lib_eep_fw_read_byte((uint8_t *)eepAddr_Cfg5);
							Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Cfg6 = lib_eep_fw_read_byte((uint8_t *)eepAddr_Cfg6);
							Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Cfg7 = lib_eep_fw_read_byte((uint8_t *)eepAddr_Cfg7);
							Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Cfg8 = lib_eep_fw_read_byte((uint8_t *)eepAddr_Cfg8);
							Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Cfg9 = lib_eep_fw_read_byte((uint8_t *)eepAddr_Cfg9);
*/
							Isb_Obj[Obj_0].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_0_Ctrl);
							Isb_Obj[Obj_0].Top = ISB_MSG_TOP_1BIT;
							Isb_Obj[Obj_0].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_0_Tov);
							for (uint8_t i = 0; i < 5; i++)
							{
								Isb_Obj[Obj_0].Data[i] = lib_eep_fw_read_byte((uint8_t *)(eepAddr_Obj_0_InitValue + i));
							}
							Isb_Obj[Obj_0].IsChanged = FALSE;
							Isb_Obj[Obj_1].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_1_Ctrl);
							Isb_Obj[Obj_1].Top = ISB_MSG_TOP_1BIT;
							Isb_Obj[Obj_1].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_1_Tov);
							for (uint8_t i = 0; i < 5; i++)
							{
								Isb_Obj[Obj_1].Data[i] = lib_eep_fw_read_byte((uint8_t *)(eepAddr_Obj_1_InitValue + i));
							}
							Isb_Obj[Obj_1].IsChanged = FALSE;
							Isb_Obj[Obj_2].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_2_Ctrl);
							Isb_Obj[Obj_2].Top = ISB_MSG_TOP_1BIT;
							Isb_Obj[Obj_2].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_2_Tov);
							for (uint8_t i = 0; i < 5; i++)
							{
								Isb_Obj[Obj_2].Data[i] = lib_eep_fw_read_byte((uint8_t *)(eepAddr_Obj_2_InitValue + i));
							}
							Isb_Obj[Obj_2].IsChanged = FALSE;
							Isb_Obj[Obj_3].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_3_Ctrl);
							Isb_Obj[Obj_3].Top = ISB_MSG_TOP_1BIT;
							Isb_Obj[Obj_3].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_3_Tov);
							for (uint8_t i = 0; i < 5; i++)
							{
								Isb_Obj[Obj_3].Data[i] = lib_eep_fw_read_byte((uint8_t *)(eepAddr_Obj_3_InitValue + i));
							}
							Isb_Obj[Obj_3].IsChanged = FALSE;
							Isb_Obj[Obj_4].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_0_Ctrl);
							Isb_Obj[Obj_4].Top = ISB_MSG_TOP_1BIT;
							Isb_Obj[Obj_4].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_0_Tov);
							for (uint8_t i = 0; i < 5; i++)
							{
								Isb_Obj[Obj_4].Data[i] = lib_eep_fw_read_byte((uint8_t *)(eepAddr_Obj_0_InitValue + i));
							}
							Isb_Obj[Obj_4].IsChanged = FALSE;
							Isb_Obj[Obj_5].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_0_Ctrl);
							Isb_Obj[Obj_5].Top = ISB_MSG_TOP_1BIT;
							Isb_Obj[Obj_5].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_0_Tov);
							for (uint8_t i = 0; i < 5; i++)
							{
								Isb_Obj[Obj_5].Data[i] = lib_eep_fw_read_byte((uint8_t *)(eepAddr_Obj_0_InitValue + i));
							}
							Isb_Obj[Obj_5].IsChanged = FALSE;
							Isb_Obj[Obj_6].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_0_Ctrl);
							Isb_Obj[Obj_6].Top = ISB_MSG_TOP_1BIT;
							Isb_Obj[Obj_6].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_0_Tov);
							for (uint8_t i = 0; i < 5; i++)
							{
								Isb_Obj[Obj_6].Data[i] = lib_eep_fw_read_byte((uint8_t *)(eepAddr_Obj_0_InitValue + i));
							}
							Isb_Obj[Obj_6].IsChanged = FALSE;
							Isb_Obj[Obj_7].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_0_Ctrl);
							Isb_Obj[Obj_7].Top = ISB_MSG_TOP_1BIT;
							Isb_Obj[Obj_7].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_0_Tov);
							for (uint8_t i = 0; i < 5; i++)
							{
								Isb_Obj[Obj_7].Data[i] = lib_eep_fw_read_byte((uint8_t *)(eepAddr_Obj_0_InitValue + i));
							}
							Isb_Obj[Obj_7].IsChanged = FALSE;
							Isb_Obj[Obj_8].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_0_Ctrl);
							Isb_Obj[Obj_8].Top = ISB_MSG_TOP_1BIT;
							Isb_Obj[Obj_8].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_0_Tov);
							for (uint8_t i = 0; i < 5; i++)
							{
								Isb_Obj[Obj_8].Data[i] = lib_eep_fw_read_byte((uint8_t *)(eepAddr_Obj_0_InitValue + i));
							}
							Isb_Obj[Obj_8].IsChanged = FALSE;
							Isb_Obj[Obj_9].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_0_Ctrl);
							Isb_Obj[Obj_9].Top = ISB_MSG_TOP_1BIT;
							Isb_Obj[Obj_9].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_0_Tov);
							for (uint8_t i = 0; i < 5; i++)
							{
								Isb_Obj[Obj_9].Data[i] = lib_eep_fw_read_byte((uint8_t *)(eepAddr_Obj_0_InitValue + i));
							}
							Isb_Obj[Obj_9].IsChanged = FALSE;
							Isb_Obj[Obj_10].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_0_Ctrl);
							Isb_Obj[Obj_10].Top = ISB_MSG_TOP_1BIT;
							Isb_Obj[Obj_10].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_0_Tov);
							for (uint8_t i = 0; i < 5; i++)
							{
								Isb_Obj[Obj_10].Data[i] = lib_eep_fw_read_byte((uint8_t *)(eepAddr_Obj_0_InitValue + i));
							}
							Isb_Obj[Obj_10].IsChanged = FALSE;
							Isb_Obj[Obj_11].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_0_Ctrl);
							Isb_Obj[Obj_11].Top = ISB_MSG_TOP_1BIT;
							Isb_Obj[Obj_11].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_0_Tov);
							for (uint8_t i = 0; i < 5; i++)
							{
								Isb_Obj[Obj_11].Data[i] = lib_eep_fw_read_byte((uint8_t *)(eepAddr_Obj_0_InitValue + i));
							}
							Isb_Obj[Obj_11].IsChanged = FALSE;
							Isb_Obj[Obj_12].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_0_Ctrl);
							Isb_Obj[Obj_12].Top = ISB_MSG_TOP_1BIT;
							Isb_Obj[Obj_12].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_0_Tov);
							for (uint8_t i = 0; i < 5; i++)
							{
								Isb_Obj[Obj_12].Data[i] = lib_eep_fw_read_byte((uint8_t *)(eepAddr_Obj_0_InitValue + i));
							}
							Isb_Obj[Obj_12].IsChanged = FALSE;
							Isb_Obj[Obj_13].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_0_Ctrl);
							Isb_Obj[Obj_13].Top = ISB_MSG_TOP_1BIT;
							Isb_Obj[Obj_13].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_0_Tov);
							for (uint8_t i = 0; i < 5; i++)
							{
								Isb_Obj[Obj_13].Data[i] = lib_eep_fw_read_byte((uint8_t *)(eepAddr_Obj_0_InitValue + i));
							}
							Isb_Obj[Obj_13].IsChanged = FALSE;
						}
						Isb_Ch[Ch].Ctrl |= (1<<ISB_CH_CTRL_INITIALIZED);
					}
					// Exec
					if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_ENABLED))
					{
// TODO: ->
// TODO: Alles

// TODO:
						// Überwachung RT
						if (Isb_Obj[Obj_0].IsChanged == TRUE)
						{
							Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Obj_0_Counter = 0;
							Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Error &= ~(1 << ISB_APP_HEATING_DEDIETRICH_CF124SH_ERROR_KRTS);
						}
						else
						{
							Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Obj_0_Counter++;
							if (Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Obj_0_Counter >= ISB_APP_HEATING_DEDIETRICH_CF124SH_OBJ_COUNTER_MAX_ERROR)
							{
								Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Error |= (1 << ISB_APP_HEATING_DEDIETRICH_CF124SH_ERROR_KRTS);
								Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Obj_0_Counter = ISB_APP_HEATING_DEDIETRICH_CF124SH_OBJ_COUNTER_MAX;
							}
							if (Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Obj_0_Counter >= ISB_APP_HEATING_DEDIETRICH_CF124SH_OBJ_COUNTER_MAX)
							{
								Isb_Obj[Obj_0].Ctrl |= (1 << ISB_OBJ_CTRL_READONINIT);
							}
						}
						uint32_t RT = Lib_FloatToInteger(Isb_Obj[Obj_0].Data[0] + (Isb_Obj[Obj_0].Data[1] << 8));

// TODO:
						// Überwachung ET
						if (Isb_Obj[Obj_1].IsChanged == TRUE)
						{
							Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Obj_1_Counter = 0;
							Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Error &= ~(1 << ISB_APP_HEATING_DEDIETRICH_CF124SH_ERROR_KETS);
						}
						else
						{
							Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Obj_1_Counter++;
							if (Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Obj_1_Counter >= ISB_APP_HEATING_DEDIETRICH_CF124SH_OBJ_COUNTER_MAX_ERROR)
							{
								Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Error |= (1 << ISB_APP_HEATING_DEDIETRICH_CF124SH_ERROR_KETS);
								Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Obj_1_Counter = ISB_APP_HEATING_DEDIETRICH_CF124SH_OBJ_COUNTER_MAX;
							}
							if (Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Obj_1_Counter >= ISB_APP_HEATING_DEDIETRICH_CF124SH_OBJ_COUNTER_MAX)
							{
								Isb_Obj[Obj_1].Ctrl |= (1 << ISB_OBJ_CTRL_READONINIT);
							}
						}
						uint32_t ET = Lib_FloatToInteger(Isb_Obj[Obj_1].Data[0] + (Isb_Obj[Obj_1].Data[1] << 8));

// TODO:
						// Überwachung KT
						if (Isb_Obj[Obj_2].IsChanged == TRUE)
						{
							Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Obj_2_Counter = 0;
							Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Error &= ~(1 << ISB_APP_HEATING_DEDIETRICH_CF124SH_ERROR_KTS);
						}
						else
						{
							Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Obj_2_Counter++;
							if (Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Obj_2_Counter >= ISB_APP_HEATING_DEDIETRICH_CF124SH_OBJ_COUNTER_MAX_ERROR)
							{
								Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Error |= (1 << ISB_APP_HEATING_DEDIETRICH_CF124SH_ERROR_KTS);
								Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Obj_2_Counter = ISB_APP_HEATING_DEDIETRICH_CF124SH_OBJ_COUNTER_MAX;
							}
							if (Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Obj_2_Counter >= ISB_APP_HEATING_DEDIETRICH_CF124SH_OBJ_COUNTER_MAX)
							{
								Isb_Obj[Obj_2].Ctrl |= (1 << ISB_OBJ_CTRL_READONINIT);
							}
						}
						uint32_t KT = Lib_FloatToInteger(Isb_Obj[Obj_2].Data[0] + (Isb_Obj[Obj_2].Data[1] << 8));

// TODO:
						// Überwachung VT
						if (Isb_Obj[Obj_3].IsChanged == TRUE)
						{
							Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Obj_3_Counter = 0;
							Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Error &= ~(1 << ISB_APP_HEATING_DEDIETRICH_CF124SH_ERROR_KVTS);
						}
						else
						{
							Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Obj_3_Counter++;
							if (Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Obj_3_Counter >= ISB_APP_HEATING_DEDIETRICH_CF124SH_OBJ_COUNTER_MAX_ERROR)
							{
								Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Error |= (1 << ISB_APP_HEATING_DEDIETRICH_CF124SH_ERROR_KVTS);
								Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Obj_3_Counter = ISB_APP_HEATING_DEDIETRICH_CF124SH_OBJ_COUNTER_MAX;
							}
							if (Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Obj_3_Counter >= ISB_APP_HEATING_DEDIETRICH_CF124SH_OBJ_COUNTER_MAX)
							{
								Isb_Obj[Obj_3].Ctrl |= (1 << ISB_OBJ_CTRL_READONINIT);
							}
						}
						uint32_t VT = Lib_FloatToInteger(Isb_Obj[Obj_3].Data[0] + (Isb_Obj[Obj_3].Data[1] << 8));

// TODO:
						// Überwachung RgT
//						if (Isb_Obj[Obj_4].IsChanged == TRUE)
//						{
//							Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Obj_4_Counter = 0;
//							Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Error &= ~(1 << ISB_APP_HEATING_DEDIETRICH_CF124SH_ERROR_RGTS);
//						}
//						else
//						{
//							Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Obj_4_Counter++;
//							if (Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Obj_4_Counter >= ISB_APP_HEATING_DEDIETRICH_CF124SH_OBJ_COUNTER_MAX_ERROR)
//							{
//								Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Error |= (1 << ISB_APP_HEATING_DEDIETRICH_CF124SH_ERROR_RGTS);
//								Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Obj_4_Counter = ISB_APP_HEATING_DEDIETRICH_CF124SH_OBJ_COUNTER_MAX;
//							}
//							if (Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Obj_4_Counter >= ISB_APP_HEATING_DEDIETRICH_CF124SH_OBJ_COUNTER_MAX)
//							{
//								Isb_Obj[Obj_4].Ctrl |= (1 << ISB_OBJ_CTRL_READONINIT);
//							}
//						}
//						uint32_t RgT = Lib_FloatToInteger(Isb_Obj[Obj_4].Data[0] + (Isb_Obj[Obj_4].Data[1] << 8));

// TODO:
						// Meldung "Ein"
						if (KT > 6500)
						{
							// Meldung "Ein" = TRUE
							if (Isb_Obj[Obj_5].Data[0] != TRUE)
							{
								Isb_Obj[Obj_5].Data[0] = TRUE;
								Isb_Obj[Obj_5].isChanged = TRUE;
							}
						}
						if (KT < 6500)
						{
							// Meldung "Ein" = FALSE
							if (Isb_Obj[Obj_5].Data[0] != FALSE)
							{
								Isb_Obj[Obj_5].Data[0] = FALSE;
								Isb_Obj[Obj_5].isChanged = TRUE;
							}
						}

// TODO:
						//  Betriebsstundenzähler Gesamt
//						if (Ladepumpe == TRUE)
//						{
//							// Inc Betriebsstundenzähler
//							if ( Betriebsstundenzähler > x)
//							{
//								// Aktualisiere EEprom
//							}
//						}

// TODO:
						// Ladepumpe
						if (KT > 6000)
						{
							// Ladepumpe "Ein" = TRUE
							if (Isb_Obj[Obj_7].Data[0] != TRUE)
							{
								Isb_Obj[Obj_7].Data[0] = TRUE;
								Isb_Obj[Obj_7].isChanged = TRUE;
							}
						}
						if (KT < 6000)
						{
							// Ladepumpe "Ein" = FALSE
							if (Isb_Obj[Obj_7].Data[0] != FALSE)
							{
								Isb_Obj[Obj_7].Data[0] = FALSE;
								Isb_Obj[Obj_7].isChanged = TRUE;
							}
						}

// TODO:
						//  Betriebsstundenzähler Ladepumpe
//						if (Ladepumpe == TRUE)
//						{
//							// Inc Betriebsstundenzähler
//							if ( Betriebsstundenzähler > x)
//							{
//								// Aktualisiere EEprom
//							}
//						}

// TODO:
						// Meldung "Anheizen"
//						if ((Isb_Obj[Obj_5].Data[0] == FALSE) & (KTalt < (KTneu  + 2°C)))
//						{
//							// Meldung "Anheizen" = TRUE
//							KTalt = (KTalt + KTneu) / 2;
//							if (Isb_Obj[Obj_9].Data[0] != TRUE)
//							{
//								Isb_Obj[Obj_9].Data[0] = TRUE;
//								Isb_Obj[Obj_9].isChanged = TRUE;
//							}
//						}
//						else
//						{
//							// Meldung "Anheizen" = FALSE
//							if (Isb_Obj[Obj_9].Data[0] != FALSE)
//							{
//								Isb_Obj[Obj_9].Data[0] = FALSE;
//								Isb_Obj[Obj_9].isChanged = TRUE;
//							}
//						}

// TODO:
						// Meldung "Feuererhaltung"
//						if ((Meldung "Ein" Alt == TRUE) & (Meldung "Ein" == FALSE))
//						{
//							// Meldung Feuererhaltung = TRUE
//							if (Isb_Obj[Obj_10].Data[0] != TRUE)
//							{
//								Isb_Obj[Obj_10].Data[0] = TRUE;
//								Isb_Obj[Obj_10].isChanged = TRUE;
//							}
//						}
//						if ((Meldung "Feuererhaltung" == TRUE) & (KT < z°C))
//						{
//							// Meldung Feuererhaltung = FALSE
//							if (Isb_Obj[Obj_10].Data[0] != FALSE)
//							{
//								Isb_Obj[Obj_10].Data[0] = FALSE;
//								Isb_Obj[Obj_10].isChanged = TRUE;
//							}
//						}

// TODO:
						// Meldung "Übertemperatur"
//						if (KT > 8500)
//						{
//							// Meldung "Übertemperatur" = TRUE
//							if (Isb_Obj[Obj_11].Data[0] != TRUE)
//							{
//								Isb_Obj[Obj_11].Data[0] = TRUE;
//								Isb_Obj[Obj_11].isChanged = TRUE;
//							}
//						}
//						else
//						{
//							// Meldung "Übertemperatur" = FALSE
//							if (Isb_Obj[Obj_11].Data[0] != FALSE)
//							{
//								Isb_Obj[Obj_11].Data[0] = FALSE;
//								Isb_Obj[Obj_11].isChanged = TRUE;
//							}
//						}

// TODO:
						// Meldung "Untertemperatur Rücklaufanhebung"
//						if ((Isb_Obj[Obj_5].Data[0] == TRUE) & (ET < 5500))
//						{
//							// Meldung "Untertemperatur Rücklaufanhebung" = TRUE
//							if (Isb_Obj[Obj_12].Data[0] != TRUE)
//							{
//								Isb_Obj[Obj_12].Data[0] = TRUE;
//								Isb_Obj[Obj_12].isChanged = TRUE;
//							}
//						}
//						else
//						{
//							// Meldung "Untertemperatur Rücklaufanhebung" = FALSE
//							if (Isb_Obj[Obj_12].Data[0] != FALSE)
//							{
//								Isb_Obj[Obj_12].Data[0] = FALSE;
//								Isb_Obj[Obj_12].isChanged = TRUE;
//							}
//						}

// TODO:
						// Meldung "Störung"
//						if (Isb_App_Heating_DeDietrich_CF124SH[AppIndex].Error != 0)
//						{
//							// Meldung "Störung" = TRUE;
//							if (Isb_Obj[Obj_13].Data[0] != TRUE)
//							{
//								Isb_Obj[Obj_13].Data[0] = TRUE;
//								Isb_Obj[Obj_13].isChanged = TRUE;
//							}
//						}
//						if (Reset == TRUE)
//						{
//							// Meldung "Störung" = FALSE;
//						}

// TODO: Alles
// TODO: <-
					}
				}
				Isb_App_Heating_Dedietrich_Cf124sh_Ctrl &= ~(1 << ISB_CTRL_SOFTIRQ_EXEC);
			}
		#endif /* ISB_APP_HEATING_DEDIETRICH_CF124SH_MAX */

		#ifdef ISB_APP_HEATING_VIESSMANN_VITOLA_BIFFERAL_MAX
			if (bit_is_set(Isb_App_Heating_Viessmann_Vitola_Bifferal_Ctrl, ISB_CTRL_SOFTIRQ_EXEC))
			{
				for (uint8_t AppIndex = 0; AppIndex < ISB_APP_HEATING_VIESSMANN_VITOLA_BIFFERAL_MAX; AppIndex++)
				{
					uint8_t Ch = pgm_read_byte(&pgmIsb_App_Heating_Viessmann_Vitola_Bifferal_Ch_Array[AppIndex]);
					if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_ENABLED))
					{
// TODO: ->
// TODO: Alles
	// KETS = KRTS
//						Obj_0
	// KTS
//						Obj_1
	// KATS = KVTS
//						Obj_2
	// RGTS
//						Obj_3
	// BRENNER
//						Obj_4
	// LP
//						Obj_5
	// Betriebsstundenzähler BRENNER
//						Obj_6
	// Betriebsstundenzähler LP
//						Obj_7
	// Meldung ""
	// Meldung "Feuer aus."
	// Warnung ""
	// Alarm 1 ""
	// Alarm 2 "Übertemperatur"
// TODO: Alles
// TODO: <-
					}
				}
				Isb_App_Heating_Viessmann_Vitola_Bifferal_Ctrl &= ~(1 << ISB_CTRL_SOFTIRQ_EXEC);
			}
		#endif /* ISB_APP_HEATING_VIESSMANN_VITOLA_BIFFERAL_MAX */

		#ifdef ISB_APP_HEATING_HK_MAX
			if (bit_is_set(Isb_App_Heating_Hk_Ctrl, ISB_CTRL_SOFTIRQ_EXEC))
			{
				for (uint8_t AppIndex = 0; AppIndex < ISB_APP_HEATING_HK_MAX; AppIndex++)
				{
					uint8_t Ch = pgm_read_byte(&pgmIsb_App_Heating_Hk_Ch_Array[AppIndex]);
					if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_ENABLED))
					{
// TODO: ->
// TODO: Alles
	// VTS
//						Obj_0
	// RTS
//						Obj_1
	// LP
//						Obj_2
	// Betriebsart
//						Obj_3
	// VTSoll
//						Obj_4
	// RTMax
	// RTMin
	// Betriebsstundenzähler LP
//						Obj_
	// Meldung "Wärme nicht ausreichend."
	// Meldung "HK Ein/Aus."
	// Warnung ""
	// Alarm 1 ""
	// Alarm 2 "Übertemperatur"
// TODO: Alles
// TODO: <-
					}
				}
				Isb_App_Heating_Hk_Ctrl &= ~(1 << ISB_CTRL_SOFTIRQ_EXEC);
			}
		#endif /* ISB_APP_HEATING_HK_MAX */

		#ifdef ISB_APP_HOTWATER_CIRCULATION_MAX
			if (bit_is_set(Isb_App_HotWater_Circulation_Ctrl, ISB_CTRL_SOFTIRQ_EXEC))
			{
				for (uint8_t AppIndex = 0; AppIndex < ISB_APP_HOTWATER_CIRCULATION_MAX; AppIndex++)
				{
					uint8_t Ch = pgm_read_byte(&pgmIsb_App_HotWater_Circulation_Ch_Array[AppIndex]);
					uint8_t Obj_0 = pgm_read_byte(&pgmIsb_App_HotWater_Circulation_Obj_0_Array[AppIndex]);
					uint8_t Obj_1 = pgm_read_byte(&pgmIsb_App_HotWater_Circulation_Obj_1_Array[AppIndex]);
					uint8_t Obj_2 = pgm_read_byte(&pgmIsb_App_HotWater_Circulation_Obj_2_Array[AppIndex]);
					// Initialize
					if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_INITIALIZED))
					{
						uint16_t eepAddr_OperatingMode = 0;
						uint16_t eepAddr_Cfg1 = 0;
						uint16_t eepAddr_Cfg2 = 0;
//						uint16_t eepAddr_Obj_0_Ctrl = 0;
//						uint16_t eepAddr_Obj_0_Top = 0;
//						uint16_t eepAddr_Obj_0_Tov = 0;
//						uint16_t eepAddr_Obj_1_Ctrl = 0;
//						uint16_t eepAddr_Obj_1_Top = 0;
//						uint16_t eepAddr_Obj_1_Tov = 0;
//						uint16_t eepAddr_Obj_2_Ctrl = 0;
//						uint16_t eepAddr_Obj_2_Top = 0;
//						uint16_t eepAddr_Obj_2_Tov = 0;
						switch (AppIndex)
						{
							#if defined(ISB_APP_HOTWATER_CIRCULATION_0)
								case ISB_APP_HOTWATER_CIRCULATION_0:
									eepAddr_OperatingMode = ISB_APP_HOTWATER_CIRCULATION_0_OPERATINGMODE;
									eepAddr_Cfg1 = ISB_APP_HOTWATER_CIRCULATION_0_CFG1;
									eepAddr_Cfg2 = ISB_APP_HOTWATER_CIRCULATION_0_CFG2;
//									eepAddr_Obj_0_Ctrl = ISB_APP_HOTWATER_CIRCULATION_0_OBJ_0_EEADDR_CTRL;
//									eepAddr_Obj_0_Top = ISB_APP_HOTWATER_CIRCULATION_0_OBJ_0_EEADDR_TOP;
//									eepAddr_Obj_0_Tov = ISB_APP_HOTWATER_CIRCULATION_0_OBJ_0_EEADDR_TOV;
//									eepAddr_Obj_1_Ctrl = ISB_APP_HOTWATER_CIRCULATION_0_OBJ_1_EEADDR_CTRL;
//									eepAddr_Obj_1_Top = ISB_APP_HOTWATER_CIRCULATION_0_OBJ_1_EEADDR_TOP;
//									eepAddr_Obj_1_Tov = ISB_APP_HOTWATER_CIRCULATION_0_OBJ_1_EEADDR_TOV;
//									eepAddr_Obj_2_Ctrl = ISB_APP_HOTWATER_CIRCULATION_0_OBJ_2_EEADDR_CTRL;
//									eepAddr_Obj_2_Top = ISB_APP_HOTWATER_CIRCULATION_0_OBJ_2_EEADDR_TOP;
//									eepAddr_Obj_2_Tov = ISB_APP_HOTWATER_CIRCULATION_0_OBJ_2_EEADDR_TOV;
									break;
							#endif /* ISB_APP_HOTWATER_CIRCULATION_0 */
						}
						if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_ENABLED))
						{
							Isb_App_HotWater_Circulation[AppIndex].OperatingMode = lib_eep_fw_read_byte((uint8_t *)eepAddr_OperatingMode);
							Isb_App_HotWater_Circulation[AppIndex].Cfg1 = lib_eep_fw_read_byte((uint8_t *)eepAddr_Cfg1);
							Isb_App_HotWater_Circulation[AppIndex].Cfg2 = lib_eep_fw_read_byte((uint8_t *)eepAddr_Cfg2);
							switch (Isb_App_HotWater_Circulation[AppIndex].OperatingMode)
							{
								case ISB_APP_HOTWATER_CIRCULATION_OPERATINGMODE_TIMECONTROLLED:
									break;
								case ISB_APP_HOTWATER_CIRCULATION_OPERATINGMODE_TEMPERATURECONTROLLED1:
									break;
								case ISB_APP_HOTWATER_CIRCULATION_OPERATINGMODE_TEMPERATURECONTROLLED2:
									break;
								default:
									break;
							}
							Isb_Obj[Obj_0].Ctrl = 0x07;
							Isb_Obj[Obj_0].Top = ISB_MSG_TOP_1BIT;
							Isb_Obj[Obj_0].Tov = 0;
							Isb_Obj[Obj_0].Data[0] = FALSE;
							Isb_Obj[Obj_0].IsChanged = FALSE;
//							Isb_Obj[Obj_1].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_1_Ctrl);
//							Isb_Obj[Obj_1].Top = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_1_Top);
//							Isb_Obj[Obj_1].Top = ISB_MSG_TOP_FLOAT;
//							Isb_Obj[Obj_1].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_1_Tov);
//							Isb_Obj[Obj_1].IsChanged = FALSE;
//							Isb_Obj[Obj_2].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_2_Ctrl);
//							Isb_Obj[Obj_2].Top = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_2_Top);
//							Isb_Obj[Obj_2].Top = ISB_MSG_TOP_FLOAT;
//							Isb_Obj[Obj_2].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddr_Obj_2_Tov);
//							Isb_Obj[Obj_2].IsChanged = FALSE;
						}
						Isb_Ch[Ch].Ctrl |= (1<<ISB_CH_CTRL_INITIALIZED);
					}
					// Exec
					if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_ENABLED))
					{
// TODO: ->
// TODO: Alles
						// Wenn Pumpe läuft
						if (Isb_Obj[Obj_0].Data[0] == TRUE)
						{
							// Runtime erhöhen
							Isb_App_HotWater_Circulation[AppIndex].PumpRuntimeToday++;
							Isb_App_HotWater_Circulation[AppIndex].PumpRuntimeNow++;
						}
						switch (Isb_App_HotWater_Circulation[AppIndex].OperatingMode)
						{
							case ISB_APP_HOTWATER_CIRCULATION_OPERATINGMODE_TIMECONTROLLED:
								// Pumpe einschalten
								if (Isb_App_HotWater_Circulation[AppIndex].Interval != 0)
								{
									Isb_App_HotWater_Circulation[AppIndex].Interval--;
								}
								else
								{
									Isb_App_HotWater_Circulation[AppIndex].Interval = Isb_App_HotWater_Circulation[AppIndex].Cfg1 * 60 * 1000 / ISB_APP_HOTWATER_CIRCULATION_EXECTIME;
									Isb_App_HotWater_Circulation[AppIndex].Duration = Isb_App_HotWater_Circulation[AppIndex].Cfg2 * 60 * 1000 / ISB_APP_HOTWATER_CIRCULATION_EXECTIME;
									Isb_Obj[Obj_0].Data[0] = TRUE;
									Isb_Obj[Obj_0].IsChanged = TRUE;
								}
								// Pumpe ausschalten
								if (Isb_Obj[Obj_0].Data[0] == TRUE)
								{
									if (Isb_App_HotWater_Circulation[AppIndex].Duration != 0)
									{
										Isb_App_HotWater_Circulation[AppIndex].Duration--;
									}
									else
									{
										Isb_Obj[Obj_0].Data[0] = FALSE;
										Isb_Obj[Obj_0].IsChanged = TRUE;
									}
								}
								break;
							case ISB_APP_HOTWATER_CIRCULATION_OPERATINGMODE_TEMPERATURECONTROLLED1:
								// Pumpe einschalten
//								uint16_t Vts = Isb_Obj[Obj_1].Data[3] + (uint16_t)(Isb_Obj[Obj_1].Data[3]<<8);
//								if (VTS > (RTS + ? °C))
								{
									Isb_App_HotWater_Circulation[AppIndex].Duration = Isb_App_HotWater_Circulation[AppIndex].Cfg2 * 60 * 1000 / ISB_APP_HOTWATER_CIRCULATION_EXECTIME;
									Isb_Obj[Obj_0].Data[0] = TRUE;
									Isb_Obj[Obj_0].IsChanged = TRUE;
								}
								// Pumpe ausschalten
//								uint16_t RT = EEP;
//								if (RTS > RT)
								{
									Isb_Obj[Obj_0].Data[0] = FALSE;
									Isb_Obj[Obj_0].IsChanged = TRUE;
								}
								break;
							case ISB_APP_HOTWATER_CIRCULATION_OPERATINGMODE_TEMPERATURECONTROLLED2:
								// Pumpe einschalten
//								if (VTS > (RTS + ? °C))
								{
									Isb_App_HotWater_Circulation[AppIndex].Duration = Isb_App_HotWater_Circulation[AppIndex].Cfg2 * 60 * 1000 / ISB_APP_HOTWATER_CIRCULATION_EXECTIME;
									Isb_Obj[Obj_0].Data[0] = TRUE;
									Isb_Obj[Obj_0].IsChanged = TRUE;
								}
								// Pumpe ausschalten
								if (Isb_Obj[Obj_0].Data[0] == TRUE)
								{
									if (Isb_App_HotWater_Circulation[AppIndex].Duration != 0)
									{
										Isb_App_HotWater_Circulation[AppIndex].Duration--;
									}
									else
									{
										Isb_Obj[Obj_0].Data[0] = FALSE;
										Isb_Obj[Obj_0].IsChanged = TRUE;
									}
								}
								break;
							default:
								// Pumpe ausschalten
								if (Isb_Obj[Obj_0].Data[0] != FALSE)
								{
									Isb_Obj[Obj_0].Data[3] = FALSE;
									Isb_Obj[Obj_0].IsChanged = FALSE;
								}
								break;
						}
/*
						TimerLamellenschaltung++;
						if (TimerLamellenschaltung > 1 Woche)
						{
							if ((RTS < 71 °C) | (Laufzeit < 3min))
							{
								Anforderung = 75 °C;
								Isb_App_HotWater_Circulation[AppIndex].Pump = TRUE;
							}
							else
							{
								TimerLamellenschaltung = 0;
								Anforderung = 0 °C;
								Isb_App_HotWater_Circulation[AppIndex].Pump = FALSE;
							}
						}
*/
/*
						TimerFest++;
						if (TimerFest > 1Tag)
						{
							if (Laufzeit < 1min)
							{
								Isb_App_HotWater_Circulation[AppIndex].Pump = TRUE;
							}
							else
							{
								TimerFest = 0;
								Isb_App_HotWater_Circulation[AppIndex].Pump = FALSE;
								Laufzeit = 0;
							}
						}
*/
// TODO: Alles
// TODO: <-
					}
				}
				Isb_App_HotWater_Circulation_Ctrl &= ~(1 << ISB_CTRL_SOFTIRQ_EXEC);
			}
		#endif /* ISB_APP_HOTWATER_CIRCULATION_MAX */

	}



#endif /* ISB_APP_C_ */
