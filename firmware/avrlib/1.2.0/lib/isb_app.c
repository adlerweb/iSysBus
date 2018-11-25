/**
 * @file		avrlib/trunk/lib/isb_app.c
 *
 * @brief		iSysBus Application.
 *
 * This file includes iSysBus Application.
 *
 * @author		© Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
 *
 * @date		$Date: 2011-09-23 10:08:26 +0200 (Fr, 23 Sep 2011) $
 *
 * @version		$Rev: 5205 $
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



	void Isb_App_Init(void) {

		#if defined(ISB_APP_DIGOUT_MAX)
			for (uint8_t AppIndex = 0; AppIndex < ISB_APP_DIGOUT_MAX; AppIndex++) {
				uint16_t eeAddrCfg0 = 0;
				uint16_t eeAddrCfg1 = 0;
				uint16_t eeAddrCfg2 = 0;
				uint16_t eeAddrCfg3 = 0;
				uint16_t eeAddrCfg4 = 0;
				uint16_t eeAddrCfg5 = 0;
				uint16_t eeAddrCfg6 = 0;
				uint16_t eeAddrCfg7 = 0;
				uint16_t eeAddrCfg8 = 0;
				uint16_t eeAddrCfg9 = 0;
				switch (AppIndex) {
					#if defined(ISB_APP_DIGOUT_0)
						case 0:
							eeAddrCfg0 = ISB_APP_DIGOUT_0_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGOUT_0_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGOUT_0_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGOUT_0_EEADDR_CFG3;
							eeAddrCfg4 = ISB_APP_DIGOUT_0_EEADDR_CFG4;
							eeAddrCfg5 = ISB_APP_DIGOUT_0_EEADDR_CFG5;
							eeAddrCfg6 = ISB_APP_DIGOUT_0_EEADDR_CFG6;
							eeAddrCfg7 = ISB_APP_DIGOUT_0_EEADDR_CFG7;
							eeAddrCfg8 = ISB_APP_DIGOUT_0_EEADDR_CFG8;
							eeAddrCfg9 = ISB_APP_DIGOUT_0_EEADDR_CFG9;
							break;
					#endif /* ISB_APP_DIGOUT_0 */
					#if defined(ISB_APP_DIGOUT_1)
						case 1:
							eeAddrCfg0 = ISB_APP_DIGOUT_1_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGOUT_1_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGOUT_1_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGOUT_1_EEADDR_CFG3;
							eeAddrCfg4 = ISB_APP_DIGOUT_1_EEADDR_CFG4;
							eeAddrCfg5 = ISB_APP_DIGOUT_1_EEADDR_CFG5;
							eeAddrCfg6 = ISB_APP_DIGOUT_1_EEADDR_CFG6;
							eeAddrCfg7 = ISB_APP_DIGOUT_1_EEADDR_CFG7;
							eeAddrCfg8 = ISB_APP_DIGOUT_1_EEADDR_CFG8;
							eeAddrCfg9 = ISB_APP_DIGOUT_1_EEADDR_CFG9;
							break;
					#endif /* ISB_APP_DIGOUT_1 */
					#if defined(ISB_APP_DIGOUT_2)
						case 2:
							eeAddrCfg0 = ISB_APP_DIGOUT_2_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGOUT_2_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGOUT_2_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGOUT_2_EEADDR_CFG3;
							eeAddrCfg4 = ISB_APP_DIGOUT_2_EEADDR_CFG4;
							eeAddrCfg5 = ISB_APP_DIGOUT_2_EEADDR_CFG5;
							eeAddrCfg6 = ISB_APP_DIGOUT_2_EEADDR_CFG6;
							eeAddrCfg7 = ISB_APP_DIGOUT_2_EEADDR_CFG7;
							eeAddrCfg8 = ISB_APP_DIGOUT_2_EEADDR_CFG8;
							eeAddrCfg9 = ISB_APP_DIGOUT_2_EEADDR_CFG9;
							break;
					#endif /* ISB_APP_DIGOUT_2 */
					#if defined(ISB_APP_DIGOUT_3)
						case 3:
							eeAddrCfg0 = ISB_APP_DIGOUT_3_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGOUT_3_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGOUT_3_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGOUT_3_EEADDR_CFG3;
							eeAddrCfg4 = ISB_APP_DIGOUT_3_EEADDR_CFG4;
							eeAddrCfg5 = ISB_APP_DIGOUT_3_EEADDR_CFG5;
							eeAddrCfg6 = ISB_APP_DIGOUT_3_EEADDR_CFG6;
							eeAddrCfg7 = ISB_APP_DIGOUT_3_EEADDR_CFG7;
							eeAddrCfg8 = ISB_APP_DIGOUT_3_EEADDR_CFG8;
							eeAddrCfg9 = ISB_APP_DIGOUT_3_EEADDR_CFG9;
							break;
					#endif /* ISB_APP_DIGOUT_3 */
					#if defined(ISB_APP_DIGOUT_4)
						case 4:
							eeAddrCfg0 = ISB_APP_DIGOUT_4_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGOUT_4_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGOUT_4_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGOUT_4_EEADDR_CFG3;
							eeAddrCfg4 = ISB_APP_DIGOUT_4_EEADDR_CFG4;
							eeAddrCfg5 = ISB_APP_DIGOUT_4_EEADDR_CFG5;
							eeAddrCfg6 = ISB_APP_DIGOUT_4_EEADDR_CFG6;
							eeAddrCfg7 = ISB_APP_DIGOUT_4_EEADDR_CFG7;
							eeAddrCfg8 = ISB_APP_DIGOUT_4_EEADDR_CFG8;
							eeAddrCfg9 = ISB_APP_DIGOUT_4_EEADDR_CFG9;
							break;
					#endif /* ISB_APP_DIGOUT_4 */
					#if defined(ISB_APP_DIGOUT_5)
						case 5:
							eeAddrCfg0 = ISB_APP_DIGOUT_5_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGOUT_5_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGOUT_5_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGOUT_5_EEADDR_CFG3;
							eeAddrCfg4 = ISB_APP_DIGOUT_5_EEADDR_CFG4;
							eeAddrCfg5 = ISB_APP_DIGOUT_5_EEADDR_CFG5;
							eeAddrCfg6 = ISB_APP_DIGOUT_5_EEADDR_CFG6;
							eeAddrCfg7 = ISB_APP_DIGOUT_5_EEADDR_CFG7;
							eeAddrCfg8 = ISB_APP_DIGOUT_5_EEADDR_CFG8;
							eeAddrCfg9 = ISB_APP_DIGOUT_5_EEADDR_CFG9;
							break;
					#endif /* ISB_APP_DIGOUT_5 */
					#if defined(ISB_APP_DIGOUT_6)
						case 6:
							eeAddrCfg0 = ISB_APP_DIGOUT_6_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGOUT_6_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGOUT_6_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGOUT_6_EEADDR_CFG3;
							eeAddrCfg4 = ISB_APP_DIGOUT_6_EEADDR_CFG4;
							eeAddrCfg5 = ISB_APP_DIGOUT_6_EEADDR_CFG5;
							eeAddrCfg6 = ISB_APP_DIGOUT_6_EEADDR_CFG6;
							eeAddrCfg7 = ISB_APP_DIGOUT_6_EEADDR_CFG7;
							eeAddrCfg8 = ISB_APP_DIGOUT_6_EEADDR_CFG8;
							eeAddrCfg9 = ISB_APP_DIGOUT_6_EEADDR_CFG9;
							break;
					#endif /* ISB_APP_DIGOUT_6 */
					#if defined(ISB_APP_DIGOUT_7)
						case 7:
							eeAddrCfg0 = ISB_APP_DIGOUT_7_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGOUT_7_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGOUT_7_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGOUT_7_EEADDR_CFG3;
							eeAddrCfg4 = ISB_APP_DIGOUT_7_EEADDR_CFG4;
							eeAddrCfg5 = ISB_APP_DIGOUT_7_EEADDR_CFG5;
							eeAddrCfg6 = ISB_APP_DIGOUT_7_EEADDR_CFG6;
							eeAddrCfg7 = ISB_APP_DIGOUT_7_EEADDR_CFG7;
							eeAddrCfg8 = ISB_APP_DIGOUT_7_EEADDR_CFG8;
							eeAddrCfg9 = ISB_APP_DIGOUT_7_EEADDR_CFG9;
							break;
					#endif /* ISB_APP_DIGOUT_7 */
					#if defined(ISB_APP_DIGOUT_8)
						case 8:
							eeAddrCfg0 = ISB_APP_DIGOUT_8_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGOUT_8_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGOUT_8_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGOUT_8_EEADDR_CFG3;
							eeAddrCfg4 = ISB_APP_DIGOUT_8_EEADDR_CFG4;
							eeAddrCfg5 = ISB_APP_DIGOUT_8_EEADDR_CFG5;
							eeAddrCfg6 = ISB_APP_DIGOUT_8_EEADDR_CFG6;
							eeAddrCfg7 = ISB_APP_DIGOUT_8_EEADDR_CFG7;
							eeAddrCfg8 = ISB_APP_DIGOUT_8_EEADDR_CFG8;
							eeAddrCfg9 = ISB_APP_DIGOUT_8_EEADDR_CFG9;
							break;
					#endif /* ISB_APP_DIGOUT_8 */
					#if defined(ISB_APP_DIGOUT_9)
						case 9:
							eeAddrCfg0 = ISB_APP_DIGOUT_9_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGOUT_9_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGOUT_9_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGOUT_9_EEADDR_CFG3;
							eeAddrCfg4 = ISB_APP_DIGOUT_9_EEADDR_CFG4;
							eeAddrCfg5 = ISB_APP_DIGOUT_9_EEADDR_CFG5;
							eeAddrCfg6 = ISB_APP_DIGOUT_9_EEADDR_CFG6;
							eeAddrCfg7 = ISB_APP_DIGOUT_9_EEADDR_CFG7;
							eeAddrCfg8 = ISB_APP_DIGOUT_9_EEADDR_CFG8;
							eeAddrCfg9 = ISB_APP_DIGOUT_9_EEADDR_CFG9;
							break;
					#endif /* ISB_APP_DIGOUT_9 */
					#if defined(ISB_APP_DIGOUT_10)
						case 10:
							eeAddrCfg0 = ISB_APP_DIGOUT_10_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGOUT_10_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGOUT_10_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGOUT_10_EEADDR_CFG3;
							eeAddrCfg4 = ISB_APP_DIGOUT_10_EEADDR_CFG4;
							eeAddrCfg5 = ISB_APP_DIGOUT_10_EEADDR_CFG5;
							eeAddrCfg6 = ISB_APP_DIGOUT_10_EEADDR_CFG6;
							eeAddrCfg7 = ISB_APP_DIGOUT_10_EEADDR_CFG7;
							eeAddrCfg8 = ISB_APP_DIGOUT_10_EEADDR_CFG8;
							eeAddrCfg9 = ISB_APP_DIGOUT_10_EEADDR_CFG9;
							break;
					#endif /* ISB_APP_DIGOUT_10 */
					#if defined(ISB_APP_DIGOUT_11)
						case 11:
							eeAddrCfg0 = ISB_APP_DIGOUT_11_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGOUT_11_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGOUT_11_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGOUT_11_EEADDR_CFG3;
							eeAddrCfg4 = ISB_APP_DIGOUT_11_EEADDR_CFG4;
							eeAddrCfg5 = ISB_APP_DIGOUT_11_EEADDR_CFG5;
							eeAddrCfg6 = ISB_APP_DIGOUT_11_EEADDR_CFG6;
							eeAddrCfg7 = ISB_APP_DIGOUT_11_EEADDR_CFG7;
							eeAddrCfg8 = ISB_APP_DIGOUT_11_EEADDR_CFG8;
							eeAddrCfg9 = ISB_APP_DIGOUT_11_EEADDR_CFG9;
							break;
					#endif /* ISB_APP_DIGOUT_11 */
					#if defined(ISB_APP_DIGOUT_12)
						case 12:
							eeAddrCfg0 = ISB_APP_DIGOUT_12_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGOUT_12_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGOUT_12_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGOUT_12_EEADDR_CFG3;
							eeAddrCfg4 = ISB_APP_DIGOUT_12_EEADDR_CFG4;
							eeAddrCfg5 = ISB_APP_DIGOUT_12_EEADDR_CFG5;
							eeAddrCfg6 = ISB_APP_DIGOUT_12_EEADDR_CFG6;
							eeAddrCfg7 = ISB_APP_DIGOUT_12_EEADDR_CFG7;
							eeAddrCfg8 = ISB_APP_DIGOUT_12_EEADDR_CFG8;
							eeAddrCfg9 = ISB_APP_DIGOUT_12_EEADDR_CFG9;
							break;
					#endif /* ISB_APP_DIGOUT_12 */
					#if defined(ISB_APP_DIGOUT_13)
						case 13:
							eeAddrCfg0 = ISB_APP_DIGOUT_13_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGOUT_13_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGOUT_13_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGOUT_13_EEADDR_CFG3;
							eeAddrCfg4 = ISB_APP_DIGOUT_13_EEADDR_CFG4;
							eeAddrCfg5 = ISB_APP_DIGOUT_13_EEADDR_CFG5;
							eeAddrCfg6 = ISB_APP_DIGOUT_13_EEADDR_CFG6;
							eeAddrCfg7 = ISB_APP_DIGOUT_13_EEADDR_CFG7;
							eeAddrCfg8 = ISB_APP_DIGOUT_13_EEADDR_CFG8;
							eeAddrCfg9 = ISB_APP_DIGOUT_13_EEADDR_CFG9;
							break;
					#endif /* ISB_APP_DIGOUT_13 */
					#if defined(ISB_APP_DIGOUT_14)
						case 14:
							eeAddrCfg0 = ISB_APP_DIGOUT_14_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGOUT_14_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGOUT_14_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGOUT_14_EEADDR_CFG3;
							eeAddrCfg4 = ISB_APP_DIGOUT_14_EEADDR_CFG4;
							eeAddrCfg5 = ISB_APP_DIGOUT_14_EEADDR_CFG5;
							eeAddrCfg6 = ISB_APP_DIGOUT_14_EEADDR_CFG6;
							eeAddrCfg7 = ISB_APP_DIGOUT_14_EEADDR_CFG7;
							eeAddrCfg8 = ISB_APP_DIGOUT_14_EEADDR_CFG8;
							eeAddrCfg9 = ISB_APP_DIGOUT_14_EEADDR_CFG9;
							break;
					#endif /* ISB_APP_DIGOUT_14 */
					#if defined(ISB_APP_DIGOUT_15)
						case 15:
							eeAddrCfg0 = ISB_APP_DIGOUT_15_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGOUT_15_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGOUT_15_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGOUT_15_EEADDR_CFG3;
							eeAddrCfg4 = ISB_APP_DIGOUT_15_EEADDR_CFG4;
							eeAddrCfg5 = ISB_APP_DIGOUT_15_EEADDR_CFG5;
							eeAddrCfg6 = ISB_APP_DIGOUT_15_EEADDR_CFG6;
							eeAddrCfg7 = ISB_APP_DIGOUT_15_EEADDR_CFG7;
							eeAddrCfg8 = ISB_APP_DIGOUT_15_EEADDR_CFG8;
							eeAddrCfg9 = ISB_APP_DIGOUT_15_EEADDR_CFG9;
							break;
					#endif /* ISB_APP_DIGOUT_15 */
				}
				uint8_t Ch = pgm_read_byte(&pgmIsb_App_DigOut_Ch_Array[AppIndex]);
				if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_ENABLED)) {
					Isb_App_DigOut[AppIndex].Cfg0 = lib_eep_fw_read_byte((uint8_t *)eeAddrCfg0);
					Isb_App_DigOut[AppIndex].Cfg1 = lib_eep_fw_read_byte((uint8_t *)eeAddrCfg1);
					Isb_App_DigOut[AppIndex].Cfg2 = lib_eep_fw_read_byte((uint8_t *)eeAddrCfg2);
					Isb_App_DigOut[AppIndex].Cfg3 = lib_eep_fw_read_byte((uint8_t *)eeAddrCfg3);
					Isb_App_DigOut[AppIndex].Cfg4 = lib_eep_fw_read_byte((uint8_t *)eeAddrCfg4);
					Isb_App_DigOut[AppIndex].Cfg5 = lib_eep_fw_read_byte((uint8_t *)eeAddrCfg5);
					Isb_App_DigOut[AppIndex].Cfg6 = lib_eep_fw_read_byte((uint8_t *)eeAddrCfg6);
					Isb_App_DigOut[AppIndex].Cfg7 = lib_eep_fw_read_byte((uint8_t *)eeAddrCfg7);
					Isb_App_DigOut[AppIndex].Cfg8 = lib_eep_fw_read_byte((uint8_t *)eeAddrCfg8);
					Isb_App_DigOut[AppIndex].Cfg9 = lib_eep_fw_read_byte((uint8_t *)eeAddrCfg9);
//					uint8_t Pin0 = pgm_read_byte(&pgmIsb_App_DigOut_Pin0_Array[AppIndex]);
//					uint8_t Pin1 = pgm_read_byte(&pgmIsb_App_DigOut_Pin1_Array[AppIndex]);
//					uint8_t Port = 0;
//					uint8_t Pin = 0;
//					switch (Isb_App_DigOut[AppIndex].Cfg & ISB_APP_DIGOUT_CFG_MODE_MASK) {
//						case ISB_APP_DIGOUT_CFG_MODE_STD:
//							Port = (Isb_App_DigOut[AppIndex].Pin0 & ISB_APP_DIGOUT_PIN0_MASKPORT) >> 3;
//							Pin = Isb_App_DigOut[AppIndex].Pin0 & ISB_APP_DIGOUT_PIN0_MASKPIN;
//							if (Port != 0) {
//								if (bit_is_clear(Isb_App_DigOut[AppIndex].Cfg, ISB_APP_DIGOUT_CFG_PIN0_INVERTED)) {
//									Lib_Pin_Set(Port, Pin, LIB_PIN_OUTPUT_LOW);
//								}
//								else {
//									Lib_Pin_Set(Port, Pin, LIB_PIN_OUTPUT_HIGH);
//								}
//							}
//							break;
//						case ISB_APP_DIGOUT_CFG_MODE_SSR:
//							Port = (Isb_App_DigOut[AppIndex].Pin0 & ISB_APP_DIGOUT_PIN0_MASKPORT) >> 3;
//							Pin = Isb_App_DigOut[AppIndex].Pin0 & ISB_APP_DIGOUT_PIN0_MASKPIN;
//							if (Port != 0) {
//								if (bit_is_clear(Isb_App_DigOut[AppIndex].Cfg, ISB_APP_DIGOUT_CFG_PIN0_INVERTED)) {
//									Lib_Pin_Set(Port, Pin, LIB_PIN_OUTPUT_LOW);
//								}
//								else {
//									Lib_Pin_Set(Port, Pin, LIB_PIN_OUTPUT_HIGH);
//								}
//							}
//							Port = (Isb_App_DigOut[AppIndex].Pin1 & ISB_APP_DIGOUT_PIN1_MASKPORT) >> 3;
//							Pin = Isb_App_DigOut[AppIndex].Pin1 & ISB_APP_DIGOUT_PIN1_MASKPIN;
//							if (Port != 0) {
//								if (bit_is_clear(Isb_App_DigOut[AppIndex].Pin1, ISB_APP_DIGOUT_CFG_PIN1_PULLUP)) {
//									Lib_Pin_Set(Port, Pin, LIB_PIN_INPUT);
//								}
//								else {
//									Lib_Pin_Set(Port, Pin, LIB_PIN_INPUT_PULLUP);
//								}
//							}
//							break;
//						case ISB_APP_DIGOUT_CFG_MODE_SLAVEUSART0:
//							break;
//						case ISB_APP_DIGOUT_CFG_MODE_SLAVEUSART1:
//							break;
//						default:
//							break;
//					}
				}
			}
		#endif /* ISB_APP_DIGOUT_MAX */

		#if defined(ISB_APP_DIGIN_MAX)
			for (uint8_t AppIndex = 0; AppIndex < ISB_APP_DIGIN_MAX; AppIndex++) {
				uint16_t eeAddrCfg0 = 0;
				uint16_t eeAddrCfg1 = 0;
				uint16_t eeAddrCfg2 = 0;
				uint16_t eeAddrCfg3 = 0;
				switch (AppIndex) {
					#if defined(ISB_APP_DIGIN_0)
						case 0:
							eeAddrCfg0 = ISB_APP_DIGIN_0_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGIN_0_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGIN_0_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGIN_0_EEADDR_CFG3;
							break;
					#endif /* ISB_APP_DIGIN_0 */
					#if defined(ISB_APP_DIGIN_1)
						case 1:
							eeAddrCfg0 = ISB_APP_DIGIN_1_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGIN_1_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGIN_1_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGIN_1_EEADDR_CFG3;
							break;
					#endif /* ISB_APP_DIGIN_1 */
					#if defined(ISB_APP_DIGIN_2)
						case 2:
							eeAddrCfg0 = ISB_APP_DIGIN_2_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGIN_2_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGIN_2_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGIN_2_EEADDR_CFG3;
							break;
					#endif /* ISB_APP_DIGIN_2 */
					#if defined(ISB_APP_DIGIN_3)
						case 3:
							eeAddrCfg0 = ISB_APP_DIGIN_3_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGIN_3_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGIN_3_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGIN_3_EEADDR_CFG3;
							break;
					#endif /* ISB_APP_DIGIN_3 */
					#if defined(ISB_APP_DIGIN_4)
						case 4:
							eeAddrCfg0 = ISB_APP_DIGIN_4_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGIN_4_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGIN_4_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGIN_4_EEADDR_CFG3;
							break;
					#endif /* ISB_APP_DIGIN_4 */
					#if defined(ISB_APP_DIGIN_5)
						case 5:
							eeAddrCfg0 = ISB_APP_DIGIN_5_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGIN_5_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGIN_5_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGIN_5_EEADDR_CFG3;
							break;
					#endif /* ISB_APP_DIGIN_5 */
					#if defined(ISB_APP_DIGIN_6)
						case 6:
							eeAddrCfg0 = ISB_APP_DIGIN_6_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGIN_6_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGIN_6_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGIN_6_EEADDR_CFG3;
							break;
					#endif /* ISB_APP_DIGIN_6 */
					#if defined(ISB_APP_DIGIN_7)
						case 7:
							eeAddrCfg0 = ISB_APP_DIGIN_7_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGIN_7_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGIN_7_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGIN_7_EEADDR_CFG3;
							break;
					#endif /* ISB_APP_DIGIN_7 */
					#if defined(ISB_APP_DIGIN_8)
						case 8:
							eeAddrCfg0 = ISB_APP_DIGIN_8_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGIN_8_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGIN_8_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGIN_8_EEADDR_CFG3;
							break;
					#endif /* ISB_APP_DIGIN_8 */
					#if defined(ISB_APP_DIGIN_9)
						case 9:
							eeAddrCfg0 = ISB_APP_DIGIN_9_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGIN_9_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGIN_9_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGIN_9_EEADDR_CFG3;
							break;
					#endif /* ISB_APP_DIGIN_9 */
					#if defined(ISB_APP_DIGIN_10)
						case 10:
							eeAddrCfg0 = ISB_APP_DIGIN_10_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGIN_10_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGIN_10_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGIN_10_EEADDR_CFG3;
							break;
					#endif /* ISB_APP_DIGIN_10 */
					#if defined(ISB_APP_DIGIN_11)
						case 11:
							eeAddrCfg0 = ISB_APP_DIGIN_11_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGIN_11_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGIN_11_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGIN_11_EEADDR_CFG3;
							break;
					#endif /* ISB_APP_DIGIN_11 */
					#if defined(ISB_APP_DIGIN_12)
						case 12:
							eeAddrCfg0 = ISB_APP_DIGIN_12_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGIN_12_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGIN_12_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGIN_12_EEADDR_CFG3;
							break;
					#endif /* ISB_APP_DIGIN_12 */
					#if defined(ISB_APP_DIGIN_13)
						case 13:
							eeAddrCfg0 = ISB_APP_DIGIN_13_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGIN_13_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGIN_13_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGIN_13_EEADDR_CFG3;
							break;
					#endif /* ISB_APP_DIGIN_13 */
					#if defined(ISB_APP_DIGIN_14)
						case 14:
							eeAddrCfg0 = ISB_APP_DIGIN_14_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGIN_14_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGIN_14_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGIN_14_EEADDR_CFG3;
							break;
					#endif /* ISB_APP_DIGIN_14 */
					#if defined(ISB_APP_DIGIN_15)
						case 15:
							eeAddrCfg0 = ISB_APP_DIGIN_15_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_DIGIN_15_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_DIGIN_15_EEADDR_CFG2;
							eeAddrCfg3 = ISB_APP_DIGIN_15_EEADDR_CFG3;
							break;
					#endif /* ISB_APP_DIGIN_15 */
				}
				uint8_t Ch = pgm_read_byte(&pgmIsb_App_DigIn_Ch_Array[AppIndex]);
				if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_ENABLED)) {
					Isb_App_DigIn[AppIndex].Cfg0 = lib_eep_fw_read_byte((uint8_t *)eeAddrCfg0);
					Isb_App_DigIn[AppIndex].Cfg1 = lib_eep_fw_read_byte((uint8_t *)eeAddrCfg1);
					Isb_App_DigIn[AppIndex].Cfg2 = lib_eep_fw_read_byte((uint8_t *)eeAddrCfg2);
					Isb_App_DigIn[AppIndex].Cfg3 = lib_eep_fw_read_byte((uint8_t *)eeAddrCfg3);
					uint8_t Pin0 = pgm_read_byte(&pgmIsb_App_DigIn_Pin0_Array[AppIndex]);
					uint8_t Port = (Pin0 & ISB_APP_DIGIN_PIN0_MASKPORT) >> 3;
					uint8_t Pin = Pin0 & ISB_APP_DIGIN_PIN0_MASKPIN;
					if (Port != 0) {
						if ((Pin0 & PULLUP) == 0) {
							Lib_Pin_Set(Port, Pin, LIB_PIN_INPUT);
						}
						else {
							Lib_Pin_Set(Port, Pin, LIB_PIN_INPUT_PULLUP);
						}
					}
				}
			}
		#endif /* ISB_APP_DIGIN_MAX */

		#if defined(ISB_APP_ANAIN_MAX)
			for (uint8_t AppIndex = 0; AppIndex < ISB_APP_ANAIN_MAX; AppIndex++) {
				uint16_t eeAddrCfg0 = 0;
				uint16_t eeAddrCfg1 = 0;
				uint16_t eeAddrCfg2 = 0;
				uint16_t eeAddrOn1 = 0;
				uint16_t eeAddrOff1 = 0;
				uint16_t eeAddrOn2 = 0;
				uint16_t eeAddrOff2 = 0;
				switch (AppIndex) {
					#if defined(ISB_APP_ANAIN_0)
						case 0:
							eeAddrCfg0 = ISB_APP_APPIN_0_EEADDR_CFG0;
							eeAddrCfg1 = ISB_APP_APPIN_0_EEADDR_CFG1;
							eeAddrCfg2 = ISB_APP_APPIN_0_EEADDR_CFG2;
							eeAddrOn1 = ISB_APP_APPIN_0_EEADDR_ON1;
							eeAddrOff1 = ISB_APP_APPIN_0_EEADDR_OFF1;
							eeAddrOn2 = ISB_APP_APPIN_0_EEADDR_ON2;
							eeAddrOff2 = ISB_APP_APPIN_0_EEADDR_OFF2;
							break;
					#endif /* ISB_APP_ANAIN_0 */
				}
				uint8_t Ch = pgm_read_byte(&pgmIsb_App_DigIn_Ch_Array[AppIndex]);
				if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_ENABLED)) {
					Isb_App_AnaIn[AppIndex].Cfg0 = lib_eep_fw_read_byte((uint8_t *)eeAddrCfg0);
					Isb_App_AnaIn[AppIndex].Cfg1 = lib_eep_fw_read_byte((uint8_t *)eeAddrCfg1);
					Isb_App_AnaIn[AppIndex].Cfg2 = lib_eep_fw_read_byte((uint8_t *)eeAddrCfg2);
					Isb_App_AnaIn[AppIndex].On1 = lib_eep_fw_read_byte((uint8_t *)eeAddrOn1);
					Isb_App_AnaIn[AppIndex].Off1 = lib_eep_fw_read_byte((uint8_t *)eeAddrOff1);
					Isb_App_AnaIn[AppIndex].On2 = lib_eep_fw_read_byte((uint8_t *)eeAddrOn2);
					Isb_App_AnaIn[AppIndex].Off2 = lib_eep_fw_read_byte((uint8_t *)eeAddrOff2);
				}
			}
		#endif /* ISB_APP_ANAIN_MAX */

		#if defined(ISB_APP_LCD_MAX)
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
		#endif /* ISB_APP_LCD_MAX */

	}



	void Isb_App_Convert_None(uint16_t Value, void *Destination) {
		*(uint16_t *)Destination = Value;
	}



	void Isb_App_Convert_PT100(uint16_t Value, void *Destination) {
		Value = Value << 1;
		*(uint16_t *)Destination = Value;
	}



	void Isb_App_Exec(void) {

		#if defined(ISB_APP_DIGOUT_MAX)
			if (bit_is_set(Isb_App_DigOut_Ctrl, ISB_CTRL_SOFTIRQ_EXEC)) {
				for (uint8_t AppIndex = 0; AppIndex < ISB_APP_DIGOUT_MAX; AppIndex++) {
					uint8_t Ch = pgm_read_byte(&pgmIsb_App_DigOut_Ch_Array[AppIndex]);
					if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_ENABLED)) {
						uint8_t Obj_1Bit_0 = pgm_read_byte(&pgmIsb_App_DigOut_Obj_1Bit_0_Array[AppIndex]);
						uint8_t Obj_1Bit_1 = pgm_read_byte(&pgmIsb_App_DigOut_Obj_1Bit_1_Array[AppIndex]);
						uint8_t Obj_1Bit_2 = pgm_read_byte(&pgmIsb_App_DigOut_Obj_1Bit_2_Array[AppIndex]);
						uint8_t Obj_1Bit_3 = pgm_read_byte(&pgmIsb_App_DigOut_Obj_1Bit_3_Array[AppIndex]);
						// Verknüpfungsfunktion
						switch (Isb_App_DigOut[AppIndex].Cfg0 & ISB_APP_DIGOUT_CFG0_LOGIC_MODE_MASK) {
							case ISB_APP_DIGOUT_CFG0_LOGIC_MODE_AND:
								if ((Isb_Obj_1Bit[Obj_1Bit_0].IsChanged == TRUE) | (Isb_Obj_1Bit[Obj_1Bit_1].IsChanged == TRUE)) {
									if ((Isb_Obj_1Bit[Obj_1Bit_0].Value != 0) & (Isb_Obj_1Bit[Obj_1Bit_1].Value != 0)) {
										Isb_App_DigOut[AppIndex].LogicValue = 1;
										Isb_App_DigOut[AppIndex].LogicIsChanged = TRUE;
									}
									else {
										Isb_App_DigOut[AppIndex].LogicValue = 0;
										Isb_App_DigOut[AppIndex].LogicIsChanged = TRUE;
									}
								}
								break;
							case ISB_APP_DIGOUT_CFG0_LOGIC_MODE_OR:
								if ((Isb_Obj_1Bit[Obj_1Bit_0].IsChanged == TRUE) | (Isb_Obj_1Bit[Obj_1Bit_1].IsChanged == TRUE)) {
									if ((Isb_Obj_1Bit[Obj_1Bit_0].Value != 0) | (Isb_Obj_1Bit[Obj_1Bit_1].Value != 0)) {
										Isb_App_DigOut[AppIndex].LogicValue = 1;
										Isb_App_DigOut[AppIndex].LogicIsChanged = TRUE;
									}
									else {
										Isb_App_DigOut[AppIndex].LogicValue = 0;
										Isb_App_DigOut[AppIndex].LogicIsChanged = TRUE;
									}
								}
								break;
							default:
								if (Isb_Obj_1Bit[Obj_1Bit_0].IsChanged == TRUE) {
									Isb_App_DigOut[AppIndex].LogicValue = Isb_Obj_1Bit[Obj_1Bit_0].Value;
									Isb_App_DigOut[AppIndex].LogicIsChanged = TRUE;
								}						
								break;
						}
						// Zeitfunktion
						uint8_t Value = Isb_App_DigOut[AppIndex].LogicValue;
						if ((Isb_App_DigOut[AppIndex].Cfg1 & ISB_APP_DIGOUT_CFG1_TIME_MODE_MASK) != ISB_APP_DIGOUT_CFG1_TIME_MODE_NONE) {
							if ((Isb_App_DigOut[AppIndex].Cfg1 & ISB_APP_DIGOUT_CFG1_TIME_MODE_MASK) == ISB_APP_DIGOUT_CFG1_TIME_MODE_DELAY) {
								if (bit_is_set(Isb_App_DigOut[AppIndex].Cfg1, ISB_APP_DIGOUT_CFG1_TIME_POWERUPDELAY_ENABLED)) {
									if (Value == 1) {
										if (Isb_App_DigOut[AppIndex].TimeOnCount != 0) {
											Isb_App_DigOut[AppIndex].TimeOnCount--;
											Value = 0;
										}
									}
									else {
										Isb_App_DigOut[AppIndex].TimeOnCount = (Isb_App_DigOut[AppIndex].Cfg2 + Isb_App_DigOut[AppIndex].Cfg3 * 60 + Isb_App_DigOut[AppIndex].Cfg4 * 60 * 60) * 1000;
									}
								}
								if (bit_is_set(Isb_App_DigOut[AppIndex].Cfg1, ISB_APP_DIGOUT_CFG1_TIME_POWERDOWNDELAY_ENABLED)) {
									if (Value == 0) {
										if (Isb_App_DigOut[AppIndex].TimeOffCount != 0) {
											Isb_App_DigOut[AppIndex].TimeOffCount--;
											Value = 1;
										}
									}
									else {
										Isb_App_DigOut[AppIndex].TimeOffCount = (Isb_App_DigOut[AppIndex].Cfg5 + Isb_App_DigOut[AppIndex].Cfg6 * 60 + Isb_App_DigOut[AppIndex].Cfg7 * 60 * 60) * 1000;
									}
								}
							}
/*
							if ((Isb_App_DigOut[AppIndex].Cfg1 & ISB_APP_DIGOUT_CFG1_TIME_MODE_MASK) == ISB_APP_DIGOUT_CFG1_TIME_MODE_STAIRCASEFUNCTION) {
								if (Value == 0) {
									if (Isb_App_DigOut[AppIndex].TimeOffCount != 0) {
										Isb_App_DigOut[AppIndex].TimeOffCount--;
										Value = 1;
									}
#									if ((bit_is_set(Isb_App_DigOut[AppIndex].Cfg1, ISB_APP_DIGOUT_CFG1_TIME_RETRIGGER_ENABLED)) | (Isb_App_DigOut[AppIndex].TimeOnCount == 0)) {
#										if (bit_is_set(Isb_App_DigOut[AppIndex].Cfg1, ISB_APP_DIGOUT_CFG1_TIME_PUMP_ENABLED)) {
#											Isb_App_DigOut[AppIndex].TimeOnCount += (Isb_App_DigOut[AppIndex].Cfg2 + Isb_App_DigOut[AppIndex].Cfg3 * 60 + Isb_App_DigOut[AppIndex].Cfg4 * 60 * 60) * 1000;
#										}
#										else {
#											Isb_App_DigOut[AppIndex].TimeOnCount = (Isb_App_DigOut[AppIndex].Cfg2 + Isb_App_DigOut[AppIndex].Cfg3 * 60 + Isb_App_DigOut[AppIndex].Cfg4 * 60 * 60) * 1000;
#										}
#									}
								}
								else {
									Isb_App_DigOut[AppIndex].TimeOffCount = (Isb_App_DigOut[AppIndex].Cfg5 + Isb_App_DigOut[AppIndex].Cfg6 * 60 + Isb_App_DigOut[AppIndex].Cfg7 * 60 * 60) * 1000;
								}
							}
*/
						}
						if (Isb_App_DigOut[AppIndex].TimeValue != Value) {
							Isb_App_DigOut[AppIndex].TimeValue = Value;
							Isb_App_DigOut[AppIndex].TimeIsChanged = TRUE;
						}
						// Sperrfunktion
//						if ((Isb_App_DigOut[AppIndex].SpecialCfg1 & ISB_APP_SPECIALCFG1_MODE_MASK) == ISB_APP_SPECIALCFG1_MODE_BLOCKINGFUNCTION) {
//							if ((Isb_App_DigOut[AppIndex].TimeIsChanged == TRUE) | (Isb_Obj_1Bit[Obj_1Bit_2].IsChanged == TRUE)) {
//								if (((Isb_Obj_1Bit[Obj_1Bit_2].Value == 0) & (bit_is_clear(Isb_App_DigOut[AppIndex].SpecialCfg2, ISB_APP_SPECIALCFG2_BLOCKINGFUNCTION_INVERTED))) | ((Isb_Obj_1Bit[Obj_1Bit_2].Value == 0) & (bit_is_clear(Isb_App_DigOut[AppIndex].SpecialCfg2, ISB_APP_SPECIALCFG2_BLOCKINGFUNCTION_INVERTED)))) {
//									// Activiert
//									if (bit_is_clear(Isb_App_DigOut[AppIndex].SpecialCfg2, ISB_APP_SPECIALCFG2_BLOCKINGFUNCTION_MERKER)) {
//										if ((Isb_App_DigOut[AppIndex].SpecialCfg2 & ISB_APP_SPECIALCFG2_BLOCKINGFUNCTION_MODEON_MASK) == ISB_APP_SPECIALCFG2_BLOCKINGFUNCTION_MODEON_OFF) {
//											Isb_App_DigOut[AppIndex].SpecialValue = 0;
//											Isb_App_DigOut[AppIndex].SpecialIsChanged = TRUE;
//										}
//										if ((Isb_App_DigOut[AppIndex].SpecialCfg2 & ISB_APP_SPECIALCFG2_BLOCKINGFUNCTION_MODEON_MASK) == ISB_APP_SPECIALCFG2_BLOCKINGFUNCTION_MODEON_ON) {
//											Isb_App_DigOut[AppIndex].SpecialValue = 1;
//											Isb_App_DigOut[AppIndex].SpecialIsChanged = TRUE;
//										}
//										if ((Isb_App_DigOut[AppIndex].SpecialCfg2 & ISB_APP_SPECIALCFG2_BLOCKINGFUNCTION_MODEON_MASK) == ISB_APP_SPECIALCFG2_BLOCKINGFUNCTION_MODEON_BLINK) {
// TODO:
//										}
//										Isb_App_DigOut[AppIndex].SpecialCfg2 |= (1<<ISB_APP_SPECIALCFG2_BLOCKINGFUNCTION_MERKER);
//									}
//								}
//								else {
//									// Deaktiviert
//									if (bit_is_clear(Isb_App_DigOut[AppIndex].SpecialCfg2, ISB_APP_SPECIALCFG2_BLOCKINGFUNCTION_MERKER)) {
//										if ((Isb_App_DigOut[AppIndex].SpecialCfg2 & ISB_APP_SPECIALCFG2_BLOCKINGFUNCTION_MODEOFF_MASK) == ISB_APP_SPECIALCFG2_BLOCKINGFUNCTION_MODEOFF_OFF) {
//											Isb_App_DigOut[AppIndex].SpecialValue = 0;
//											Isb_App_DigOut[AppIndex].SpecialIsChanged = TRUE;
//										}
//										if ((Isb_App_DigOut[AppIndex].SpecialCfg2 & ISB_APP_SPECIALCFG2_BLOCKINGFUNCTION_MODEOFF_MASK) == ISB_APP_SPECIALCFG2_BLOCKINGFUNCTION_MODEOFF_ON) {
//											Isb_App_DigOut[AppIndex].SpecialValue = 1;
//											Isb_App_DigOut[AppIndex].SpecialIsChanged = TRUE;
//										}
//										if ((Isb_App_DigOut[AppIndex].SpecialCfg2 & ISB_APP_SPECIALCFG2_BLOCKINGFUNCTION_MODEON_MASK) == ISB_APP_SPECIALCFG2_BLOCKINGFUNCTION_MODEOFF_BLINK) {
// TODO:
//										}
//										if ((Isb_App_DigOut[AppIndex].SpecialCfg2 & ISB_APP_SPECIALCFG2_BLOCKINGFUNCTION_MODEON_MASK) == ISB_APP_SPECIALCFG2_BLOCKINGFUNCTION_MODEOFF_REAL) {
//											Isb_App_DigOut[AppIndex].SpecialValue = Isb_App_DigOut[AppIndex].TimeValue;
//											Isb_App_DigOut[AppIndex].SpecialIsChanged = TRUE;
//										}
//										Isb_App_DigOut[AppIndex].SpecialCfg2 |= (1<<ISB_APP_SPECIALCFG2_BLOCKINGFUNCTION_MERKER);
//									}
//									else {
//										Isb_App_DigOut[AppIndex].SpecialValue = Isb_App_DigOut[AppIndex].TimeValue;
//										Isb_App_DigOut[AppIndex].SpecialIsChanged = TRUE;
//									}
//								}
//							}
//						}
//						else {
							if (Isb_App_DigOut[AppIndex].TimeIsChanged == TRUE) {
								Isb_App_DigOut[AppIndex].SpecialValue = Isb_App_DigOut[AppIndex].TimeValue;
								Isb_App_DigOut[AppIndex].SpecialIsChanged = TRUE;
							}						
//						}
						// Zwangsstellungsfunktion
//						if ((Isb_App_DigOut[AppIndex].SpecialCfg1 & ISB_APP_SPECIALCFG1_MODE_MASK) == ISB_APP_SPECIALCFG1_MODE_BONDAGEFUNCTION) {
//							if ((Isb_App_DigOut[AppIndex].SpecialIsChanged == TRUE) | (Isb_Obj_1Bit[Obj_1Bit_2].IsChanged == TRUE)) {
//
//								if (Isb_Obj_1Bit[Obj_1Bit_2].Value == 0) {
//									if (bit_is_clear(Isb_App_DigOut[AppIndex].SpecialCfg2, ISB_APP_SPECIALCFG2_BONDAGEFUNCTION_MERKER)) {
//										if ((Isb_App_DigOut[AppIndex].SpecialCfg2 & ISB_APP_SPECIALCFG2_BONDAGEFUNCTION_MODEOFF_MASK) == ISB_APP_SPECIALCFG2_BONDAGEFUNCTION_MODEOFF_OFF) {
//											Isb_App_DigOut[AppIndex].Value = 0;
//											Isb_App_DigOut[AppIndex].IsChanged = TRUE;
//										}
//										if ((Isb_App_DigOut[AppIndex].SpecialCfg2 & ISB_APP_SPECIALCFG2_BONDAGEFUNCTION_MODEOFF_MASK) == ISB_APP_SPECIALCFG2_BONDAGEFUNCTION_MODEOFF_ON) {
//											Isb_App_DigOut[AppIndex].Value = 1;
//											Isb_App_DigOut[AppIndex].IsChanged = TRUE;
//										}
//										Isb_App_DigOut[AppIndex].SpecialCfg2 |= (1<<ISB_APP_SPECIALCFG2_BONDAGEFUNCTION_MERKER);
//									}
//								}
//								else {
//									Isb_App_DigOut[AppIndex].Value = Isb_App_DigOut[AppIndex].SpecialValue;
//									Isb_App_DigOut[AppIndex].IsChanged = TRUE;
//								}
//
//							}
//						}
//						else {
							if (Isb_App_DigOut[AppIndex].SpecialIsChanged == TRUE) {
								Isb_App_DigOut[AppIndex].Value = Isb_App_DigOut[AppIndex].SpecialValue;
								Isb_App_DigOut[AppIndex].IsChanged = TRUE;
							}						
//						}
						// Ausgang
// -> TODO:
						if (Isb_App_DigOut[AppIndex].IsChanged == TRUE) {
							uint8_t Pin0 = pgm_read_byte(&pgmIsb_App_DigOut_Pin0_Array[AppIndex]);
//							uint8_t Pin1 = pgm_read_byte(&pgmIsb_App_DigOut_Pin1_Array[AppIndex]);
							switch (Isb_App_DigOut[AppIndex].Cfg0 & ISB_APP_DIGOUT_CFG0_OPERATION_MASK) {
								case ISB_APP_DIGOUT_CFG0_OPERATION_STD:
									if (bit_is_set(Isb_App_DigOut[AppIndex].Value, 0)) {
										uint8_t Port = (Pin0 & ISB_APP_DIGOUT_PIN0_MASKPORT) >> 3;
										uint8_t Pin = Pin0 & ISB_APP_DIGOUT_PIN0_MASKPIN;
										if (Port != 0) {
											if (bit_is_clear(Isb_App_DigOut[AppIndex].Cfg0, ISB_APP_DIGOUT_CFG0_PIN0_INVERTED)) {
												Lib_Pin_Set(Port, Pin, LIB_PIN_OUTPUT_LOW);
											}
											else {
												Lib_Pin_Set(Port, Pin, LIB_PIN_OUTPUT_HIGH);
											}
										}
									}
									else {
										uint8_t Port = (Pin0 & ISB_APP_DIGOUT_PIN0_MASKPORT) >> 3;
										uint8_t Pin = Pin0 & ISB_APP_DIGOUT_PIN0_MASKPIN;
										if (Port != 0) {
											if (bit_is_clear(Isb_App_DigOut[AppIndex].Cfg0, ISB_APP_DIGOUT_CFG0_PIN0_INVERTED)) {
												Lib_Pin_Set(Port, Pin, LIB_PIN_OUTPUT_HIGH);
											}
											else {
												Lib_Pin_Set(Port, Pin, LIB_PIN_OUTPUT_LOW);
											}
										}
									}
									Isb_App_DigOut[AppIndex].IsChanged = FALSE;
									break;
								case ISB_APP_DIGOUT_CFG0_OPERATION_SSR:
//									if (Isb_App_DigOut_Ssr_Index == AppIndex) {
//										if ((Isb_App_DigOut_Ssr_Counter == 250) | (Isb_App_DigOut_Ssr_Counter == 175) | (Isb_App_DigOut_Ssr_Counter == 100)) {
//											// Ausgang High
//											uint8_t Port = (Isb_App_DigOut[AppIndex].Pin0 & ISB_APP_DIGOUT_PIN0_MASKPORT) >> 3;
//											uint8_t Pin = Isb_App_DigOut[AppIndex].Pin0 & ISB_APP_DIGOUT_PIN0_MASKPIN;
//											if (Port != 0) {
//												if (bit_is_clear(Isb_App_DigOut[AppIndex].Cfg, ISB_APP_DIGOUT_CFG_PIN0_INVERTED)) {
//													Lib_Pin_Set(Port, Pin, LIB_PIN_OUTPUT_HIGH);
//												}
//												else {
//													Lib_Pin_Set(Port, Pin, LIB_PIN_OUTPUT_LOW);
//												}
//											}
//										}
//										if ((Isb_App_DigOut_Ssr_Counter == 225) | (Isb_App_DigOut_Ssr_Counter == 150) | (Isb_App_DigOut_Ssr_Counter == 50)) {
//											// Ausgang Low
//											uint8_t Port = (Isb_App_DigOut[AppIndex].Pin0 & ISB_APP_DIGOUT_PIN0_MASKPORT) >> 3;
//											uint8_t Pin = Isb_App_DigOut[AppIndex].Pin0 & ISB_APP_DIGOUT_PIN0_MASKPIN;
//											if (Port != 0) {
//												if (bit_is_clear(Isb_App_DigOut[AppIndex].Cfg, ISB_APP_DIGOUT_CFG_PIN0_INVERTED)) {
//													Lib_Pin_Set(Port, Pin, LIB_PIN_OUTPUT_LOW);
//												}
//												else {
//													Lib_Pin_Set(Port, Pin, LIB_PIN_OUTPUT_HIGH);
//												}
//											}
//										}
//										if ((Isb_App_DigOut_Ssr_Counter == 200) | (Isb_App_DigOut_Ssr_Counter == 125) | (Isb_App_DigOut_Ssr_Counter == 25)) {
//											// Lese Kontrolleingang
//											uint8_t Port = (Isb_App_DigOut[AppIndex].Pin1 & ISB_APP_DIGOUT_PIN1_MASKPORT) >> 3;
//											uint8_t Pin = Isb_App_DigOut[AppIndex].Pin1 & ISB_APP_DIGOUT_PIN1_MASKPIN;
//											uint8_t Value = Lib_Pin_Get(Port, Pin);
//											// Kontrolleingang invertieren?
//											if (bit_is_set(Isb_App_DigOut[AppIndex].Pin1, ISB_APP_DIGOUT_CFG_PIN1_INVERTED)) {
//												if (Value != 0) {
//													Value = 0;
//												}
//												else {
//													Value = 1;
//												}
//											}
//											// Schaltvorgang einleiten
//											if (((bit_is_clear(Isb_App_DigOut[AppIndex].Value, 0)) & (bit_is_clear(Value, 0))) | ((bit_is_set(Isb_App_DigOut[AppIndex].Value, 0)) & (bit_is_set(Value, 0)))) {
//												Isb_App_DigOut[AppIndex].IsChanged = FALSE;
//												Isb_App_DigOut_Ssr_Counter = 0;
//											}
//										}
//										if (Isb_App_DigOut_Ssr_Counter == 5) {
//											// Relais schaltet nicht - Channel deaktivieren
////											Isb_Ch[Isb_Prg_DigOut[Isb_Prg_Index].Ch].Ctrl &= ~(1 << ISB_CH_CTRL_ENABLED);
//											Isb_App_DigOut[AppIndex].IsChanged = FALSE;
//										}
//									}
//									if (Isb_App_DigOut_Ssr_Counter == 0) {
//										// Lese Kontrolleingang
//										uint8_t Port = (Isb_App_DigOut[AppIndex].Pin1 & ISB_APP_DIGOUT_PIN1_MASKPORT) >> 3;
//										uint8_t Pin = Isb_App_DigOut[AppIndex].Pin1 & ISB_APP_DIGOUT_PIN1_MASKPIN;
//										uint8_t Value = Lib_Pin_Get(Port, Pin);
//										// Kontrolleingang invertieren?
//										if (bit_is_set(Isb_App_DigOut[AppIndex].Pin1, ISB_APP_DIGOUT_CFG_PIN1_INVERTED)) {
//											if (Value != 0) {
//												Value = 0;
//											}
//											else {
//												Value = 1;
//											}
//										}
//										// Schaltvorgang einleiten
//										if (((bit_is_clear(Isb_App_DigOut[AppIndex].Value, 0)) & (bit_is_clear(Value, 0))) | ((bit_is_set(Isb_App_DigOut[AppIndex].Value, 0)) & (bit_is_set(Value, 0)))) {
//											Isb_App_DigOut[AppIndex].IsChanged = FALSE;
//										}
//										else {
//											Isb_App_DigOut_Ssr_Index = AppIndex;
//											Isb_App_DigOut_Ssr_Counter = 250;
//										}
//									}
									break;
								case ISB_APP_DIGOUT_CFG0_OPERATION_SLAVEUSART0:
//									;
//									#if defined(ISB_INF_USART0_SLAVE)
//										Isb_Msg_t Isb_Slave_Msg;
//										Isb_Slave_Msg.Flags = ISB_MSG_FLAGS_TOF_MULTICAST | ISB_MSG_FLAGS_DLC_4;
//										Isb_Slave_Msg.SourceId = 0;
//										Isb_Slave_Msg.DestId = Isb_Prg_Index;
//										Isb_Slave_Msg.Data[0] = ISB_MSG_TOP_1BIT;
//										Isb_Slave_Msg.Data[1] = ISB_MSG_CTRL_CMD_WRITE;
//										Isb_Slave_Msg.Data[2] = ISB_MSG_TOP_1BIT_TOV_BOOL;
//										Isb_Slave_Msg.Data[3] = Isb_App_DigOut[AppIndex].Value;
//										Isb_Inf_Usart_Slave_Tx(0, &Isb_Slave_Msg);
//									#endif /* ISB_INF_USART0_SLAVE */
//									Isb_App_DigOut[AppIndex].IsChanged = FALSE;
									break;
								case ISB_APP_DIGOUT_CFG0_OPERATION_SLAVEUSART1:
//									;
//									#if defined(ISB_INF_USART1_SLAVE)
//										Isb_Msg_t Isb_Slave_Msg;
//										Isb_Slave_Msg.Flags = ISB_MSG_FLAGS_TOF_MULTICAST | ISB_MSG_FLAGS_DLC_4;
//										Isb_Slave_Msg.SourceId = 0;
//										Isb_Slave_Msg.DestId = Isb_Prg_Index;
//										Isb_Slave_Msg.Data[0] = ISB_MSG_TOP_1BIT;
//										Isb_Slave_Msg.Data[1] = ISB_MSG_CTRL_CMD_WRITE;
//										Isb_Slave_Msg.Data[2] = ISB_MSG_TOP_1BIT_TOV_BOOL;
//										Isb_Slave_Msg.Data[3] = Isb_App_DigOut[AppIndex].Value;
//										Isb_Inf_Usart_Slave_Tx(1, &Isb_Slave_Msg);
//									#endif /* ISB_INF_USART1_SLAVE */
//									Isb_App_DigOut[AppIndex].IsChanged = FALSE;
									break;
//								default:
//									break;
							}
						}
// <- TODO:










///					}
///				}
///				if (Isb_Prg_DigOut_Ssr_Counter > 0) {
///					Isb_Prg_DigOut_Ssr_Counter--;
///				}
///				Isb_Prg_DigOut_Ctrl &= ~(1 << ISB_CTRL_SOFTIRQ_EXEC);
///			}
//			#if defined(ISB_INF_USART0_SLAVE) | defined(ISB_INF_USART1_SLAVE)
//				Isb_Msg_t Isb_Slave_Msg;
//			#endif /* ISB_INF_USART0_SLAVE | ISB_INF_USART1_SLAVE */
//			#if defined(ISB_INF_USART0_SLAVE)
//				if (Isb_Inf_Usart_Slave_Rx(0, &Isb_Slave_Msg) == TRUE) {
//	Isb_Slave_Msg.Flags = ISB_MSG_FLAGS_TOF_MULTICAST | ISB_MSG_FLAGS_DLC_4;
//	Isb_Slave_Msg.SourceId = 0;
//	Isb_Slave_Msg.DestId = Isb_Prg_Index;
//	Isb_Slave_Msg.Data[0] = ISB_MSG_TOP_1BIT;
//	Isb_Slave_Msg.Data[1] = ISB_MSG_CTRL_CMD_WRITE;
//	Isb_Slave_Msg.Data[2] = ISB_MSG_TOP_1BIT_TOV_BOOL;
//	Isb_Prg_DigOut[Isb_Prg_Index].Value = Isb_Slave_Msg.Data[3];
//					;
//				}
//			#endif /* ISB_INF_USART0_SLAVE */
//			#if defined(ISB_INF_USART1_SLAVE)
//				if (Isb_Inf_Usart_Slave_Rx(1, &Isb_Slave_Msg) == TRUE) {
//					;
//				}
//			#endif /* ISB_INF_USART1_SLAVE */










						// Rückmeldungsfunktion
						Value = 0;
						if ((Isb_App_DigOut[AppIndex].Value == 1) & (bit_is_clear(Isb_App_DigOut[AppIndex].Cfg9, ISB_APP_DIGOUT_CFG9_RESULT_INVERTED))) {
							Value = 1;
						}
						if ((Isb_App_DigOut[AppIndex].Value == 0) & (bit_is_set(Isb_App_DigOut[AppIndex].Cfg9, ISB_APP_DIGOUT_CFG9_RESULT_INVERTED))) {
							Value = 1;
						}
						if (Isb_Obj_1Bit[Obj_1Bit_3].Value != Value) {
							Isb_Obj_1Bit[Obj_1Bit_3].Value = Value;
							Isb_Obj_1Bit[Obj_1Bit_3].IsChanged = TRUE;
						}
					}
				}
				Isb_App_DigOut_Ctrl &= ~(1 << ISB_CTRL_SOFTIRQ_EXEC);
			}
		#endif /* ISB_APP_DIGOUT_MAX */

		#if defined(ISB_APP_DIGIN_MAX)
			if (bit_is_set(Isb_App_DigIn_Ctrl, ISB_CTRL_SOFTIRQ_EXEC)) {
				for (uint8_t AppIndex = 0; AppIndex < ISB_APP_DIGIN_MAX; AppIndex++) {
					uint8_t Ch = pgm_read_byte(&pgmIsb_App_DigIn_Ch_Array[AppIndex]);
					if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_ENABLED)) {
						uint8_t Pin0 = pgm_read_byte(&pgmIsb_App_DigIn_Pin0_Array[AppIndex]);
//						uint8_t Obj_1Bit_0 = pgm_read_byte(&pgmIsb_App_DigIn_Obj_1Bit_0_Array[AppIndex]);
						uint8_t Obj_1Bit_1 = pgm_read_byte(&pgmIsb_App_DigIn_Obj_1Bit_1_Array[AppIndex]);
						uint8_t Obj_1Bit_2 = pgm_read_byte(&pgmIsb_App_DigIn_Obj_1Bit_2_Array[AppIndex]);
//						uint8_t Obj_4Bit_0 = pgm_read_byte(&pgmIsb_App_DigIn_Obj_4Bit_0_Array[AppIndex]);
//						uint8_t Obj_8Bit_0 = pgm_read_byte(&pgmIsb_App_DigIn_Obj_8Bit_0_Array[AppIndex]);



// -> TODO:
//						if (Isb_Obj_1Bit[Obj_1Bit_0].Value == 0) {



// Pin einlesen
							switch (Isb_App_DigIn[AppIndex].Cfg0 & ISB_APP_DIGIN_CFG0_MODE_MASK) {
								case ISB_APP_DIGIN_CFG0_MODE_STD:
									;
									uint8_t Port = (Pin0 & ISB_APP_DIGIN_PIN0_MASKPORT) >> 3;
									uint8_t Pin = Pin0 & ISB_APP_DIGIN_PIN0_MASKPIN;
									if (Port != 0) {
										if (bit_is_clear(Isb_App_DigIn[AppIndex].Cfg0, ISB_APP_DIGIN_CFG0_PIN0_INVERTED)) {
											if (Lib_Pin_Get(Port, Pin) != 0) {
												Isb_App_DigIn[AppIndex].Value = 1;
											}
											else {
												Isb_App_DigIn[AppIndex].Value = 0;
											}
										}
										else {
											if (Lib_Pin_Get(Port, Pin) != 0) {
												Isb_App_DigIn[AppIndex].Value = 0;
											}
											else {
												Isb_App_DigIn[AppIndex].Value = 1;
											}
										}
									}
									break;
								case ISB_APP_DIGIN_CFG0_MODE_SLAVEUSART0:
// -> TODO:
									Isb_App_DigIn[AppIndex].Value = 0;
// <- TODO:
									break;
								case ISB_APP_DIGIN_CFG0_MODE_SLAVEUSART1:
// -> TODO:
									Isb_App_DigIn[AppIndex].Value = 0;
// <- TODO:
									break;
							}



// Pin auswerten
							if (Isb_App_DigIn[AppIndex].Value != 0) {
								// Global
								Isb_App_DigIn[AppIndex].CountHigh++;
								// Event "High" > 40ms
								if (Isb_App_DigIn[AppIndex].CountHigh == 4) {
									Isb_App_DigIn[AppIndex].Event |= (1 << ISB_APP_DIGIN_EVENT_HIGH);
								}
								// Event "High Long" > 400ms
								if (Isb_App_DigIn[AppIndex].CountHigh == 40) {
									Isb_App_DigIn[AppIndex].Event |= (1 << ISB_APP_DIGIN_EVENT_HIGHLONG);
								}
								// Event "High Repeat"
								if (Isb_App_DigIn[AppIndex].CountHigh == 100) {
									Isb_App_DigIn[AppIndex].CountHigh = 90;
									Isb_App_DigIn[AppIndex].Event |= (1 << ISB_APP_DIGIN_EVENT_HIGHREPEAT);
								}
								// Event "Low Short" = 40-400ms
//								if (Isb_App_DigIn[AppIndex].CountLow != 0) {
//									if (Isb_App_DigIn[AppIndex].CountLow < 40) {
//										Isb_App_DigIn[AppIndex].Event |= (1 << ISB_APP_DIGIN_EVENT_LOWSHORT);
//									}
//								}
								// Global
								Isb_App_DigIn[AppIndex].CountLow = 0;
							}
							else {
								// Global
								Isb_App_DigIn[AppIndex].CountLow++;
								// Event "Low" > 40ms
								if (Isb_App_DigIn[AppIndex].CountLow == 4) {
									Isb_App_DigIn[AppIndex].Event |= (1 << ISB_APP_DIGIN_EVENT_LOW);
								}
								// Event "Low Long" > 400ms
//								if (Isb_App_DigIn[AppIndex].CountLow == 40) {
//									Isb_App_DigIn[AppIndex].Event |= (1 << ISB_APP_DIGIN_EVENT_LOWLONG);
//								}
								// Event "Low Repeat"
//								if (Isb_App_DigIn[AppIndex].CountLow == 100) {
//									Isb_App_DigIn[AppIndex].CountLow = 90;
//									Isb_App_DigIn[AppIndex].Event |= (1 << ISB_APP_DIGIN_EVENT_LOWREPEAT);
//								}
								// Event "High Short" = 40-400ms
								if (Isb_App_DigIn[AppIndex].CountHigh != 0) {
									if (Isb_App_DigIn[AppIndex].CountHigh < 40) {
										Isb_App_DigIn[AppIndex].Event |= (1 << ISB_APP_DIGIN_EVENT_HIGHSHORT);
									}
								}
								// Global
								Isb_App_DigIn[AppIndex].CountHigh = 0;
							}



// Event auswerten
							switch (Isb_App_DigIn[AppIndex].Cfg1 & ISB_APP_DIGIN_CFG1_MODE_MASK) {
								case ISB_APP_DIGIN_CFG1_MODE_SWITCH:
									// Betriebsart = Schaltsensor/Störmeldeeingang
									switch (Isb_App_DigIn[AppIndex].Cfg1 & ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_MASK) {
										case ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_0:
											// 1 Schaltobjekt - Ohne Unterscheidung Kurz/Lang - Ohne Repeat 
											if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGH)) {
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_0) {
													// None
												}
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_1) {
													// Aus
													if (Isb_Obj_1Bit[Obj_1Bit_1].Value != 0) {
														Isb_Obj_1Bit[Obj_1Bit_1].Value = 0;
														Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
													}
												}
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_2) {
													// Ein
													if (Isb_Obj_1Bit[Obj_1Bit_1].Value != 1) {
														Isb_Obj_1Bit[Obj_1Bit_1].Value = 1;
														Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
													}
												}
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_3) {
													// Um
													if (Isb_Obj_1Bit[Obj_1Bit_1].Value == 0) {
														if (Isb_Obj_1Bit[Obj_1Bit_1].Value != 1) {
															Isb_Obj_1Bit[Obj_1Bit_1].Value = 1;
															Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
														}
													}
													else {
														if (Isb_Obj_1Bit[Obj_1Bit_1].Value != 0) {
															Isb_Obj_1Bit[Obj_1Bit_1].Value = 0;
															Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
														}
													}
												}
												Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGH);
											}
											if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_LOW)) {
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_0) {
													// None
												}
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_1) {
													// Aus
													if (Isb_Obj_1Bit[Obj_1Bit_1].Value != 0) {
														Isb_Obj_1Bit[Obj_1Bit_1].Value = 0;
														Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
													}
												}
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_2) {
													// Ein
													if (Isb_Obj_1Bit[Obj_1Bit_1].Value != 1) {
														Isb_Obj_1Bit[Obj_1Bit_1].Value = 1;
														Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
													}
												}
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_3) {
													// Um
													if (Isb_Obj_1Bit[Obj_1Bit_1].Value == 0) {
														if (Isb_Obj_1Bit[Obj_1Bit_1].Value != 1) {
															Isb_Obj_1Bit[Obj_1Bit_1].Value = 1;
															Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
														}
													}
													else {
														if (Isb_Obj_1Bit[Obj_1Bit_1].Value != 0) {
															Isb_Obj_1Bit[Obj_1Bit_1].Value = 0;
															Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
														}
													}
												}
												Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_LOW);
											}
											break;
										case ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_1:
											// 1 Schaltobjekt - Ohne Unterscheidung Kurz/Lang - Mit Repeat 
											if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGH)) {
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_0) {
													// None
												}
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_1) {
													// Aus
													if (Isb_Obj_1Bit[Obj_1Bit_1].Value != 0) {
														Isb_Obj_1Bit[Obj_1Bit_1].Value = 0;
														Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
													}
												}
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_2) {
													// Ein
													if (Isb_Obj_1Bit[Obj_1Bit_1].Value != 1) {
														Isb_Obj_1Bit[Obj_1Bit_1].Value = 1;
														Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
													}
												}
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_3) {
													// Um
													if (Isb_Obj_1Bit[Obj_1Bit_1].Value == 0) {
														if (Isb_Obj_1Bit[Obj_1Bit_1].Value != 1) {
															Isb_Obj_1Bit[Obj_1Bit_1].Value = 1;
															Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
														}
													}
													else {
														if (Isb_Obj_1Bit[Obj_1Bit_1].Value != 0) {
															Isb_Obj_1Bit[Obj_1Bit_1].Value = 0;
															Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
														}
													}
												}
												Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGH);
											}
											if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_LOW)) {
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_0) {
													// None
												}
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_1) {
													// Aus
													if (Isb_Obj_1Bit[Obj_1Bit_1].Value != 0) {
														Isb_Obj_1Bit[Obj_1Bit_1].Value = 0;
														Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
													}
												}
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_2) {
													// Ein
													if (Isb_Obj_1Bit[Obj_1Bit_1].Value != 1) {
														Isb_Obj_1Bit[Obj_1Bit_1].Value = 1;
														Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
													}
												}
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_3) {
													// Um
													if (Isb_Obj_1Bit[Obj_1Bit_1].Value == 0) {
														if (Isb_Obj_1Bit[Obj_1Bit_1].Value != 1) {
															Isb_Obj_1Bit[Obj_1Bit_1].Value = 1;
															Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
														}
													}
													else {
														if (Isb_Obj_1Bit[Obj_1Bit_1].Value != 0) {
															Isb_Obj_1Bit[Obj_1Bit_1].Value = 0;
															Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
														}
													}
												}
												Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_LOW);
											}
											if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHREPEAT)) {
// TODO:


												Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHREPEAT);
											}
											break;
										case ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_2:
											// 2 Schaltobjekte - Mit Unterscheidung Kurz/Lang - Ohne Repeat 
											if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHSHORT)) {
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_0) {
													// None
												}
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_1) {
													// Aus
													if (Isb_Obj_1Bit[Obj_1Bit_1].Value != 0) {
														Isb_Obj_1Bit[Obj_1Bit_1].Value = 0;
														Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
													}
												}
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_2) {
													// Ein
													if (Isb_Obj_1Bit[Obj_1Bit_1].Value != 1) {
														Isb_Obj_1Bit[Obj_1Bit_1].Value = 1;
														Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
													}
												}
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_3) {
													// Um
													if (Isb_Obj_1Bit[Obj_1Bit_1].Value == 0) {
														if (Isb_Obj_1Bit[Obj_1Bit_1].Value != 1) {
															Isb_Obj_1Bit[Obj_1Bit_1].Value = 1;
															Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
														}
													}
													else {
														if (Isb_Obj_1Bit[Obj_1Bit_1].Value != 0) {
															Isb_Obj_1Bit[Obj_1Bit_1].Value = 0;
															Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
														}
													}
												}
												Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHSHORT);
											}
											if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHLONG)) {
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_0) {
													// None
												}
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_1) {
													// Aus
													if (Isb_Obj_1Bit[Obj_1Bit_2].Value != 0) {
														Isb_Obj_1Bit[Obj_1Bit_2].Value = 0;
														Isb_Obj_1Bit[Obj_1Bit_2].IsChanged = TRUE;
													}
												}
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_2) {
													// Ein
													if (Isb_Obj_1Bit[Obj_1Bit_2].Value != 1) {
														Isb_Obj_1Bit[Obj_1Bit_2].Value = 1;
														Isb_Obj_1Bit[Obj_1Bit_2].IsChanged = TRUE;
													}
												}
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_3) {
													// Um
													if (Isb_Obj_1Bit[Obj_1Bit_2].Value == 0) {
														if (Isb_Obj_1Bit[Obj_1Bit_2].Value != 1) {
															Isb_Obj_1Bit[Obj_1Bit_2].Value = 1;
															Isb_Obj_1Bit[Obj_1Bit_2].IsChanged = TRUE;
														}
													}
													else {
														if (Isb_Obj_1Bit[Obj_1Bit_2].Value != 0) {
															Isb_Obj_1Bit[Obj_1Bit_2].Value = 0;
															Isb_Obj_1Bit[Obj_1Bit_2].IsChanged = TRUE;
														}
													}
												}
												Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHLONG);
											}
											break;
										case ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_3:
											// 2 Schaltobjekte - Mit Unterscheidung Kurz/Lang - Mit Repeat 
											if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHSHORT)) {
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_0) {
													// None
												}
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_1) {
													// Aus
													if (Isb_Obj_1Bit[Obj_1Bit_1].Value != 0) {
														Isb_Obj_1Bit[Obj_1Bit_1].Value = 0;
														Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
													}
												}
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_2) {
													// Ein
													if (Isb_Obj_1Bit[Obj_1Bit_1].Value != 1) {
														Isb_Obj_1Bit[Obj_1Bit_1].Value = 1;
														Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
													}
												}
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_3) {
													// Um
													if (Isb_Obj_1Bit[Obj_1Bit_1].Value == 0) {
														if (Isb_Obj_1Bit[Obj_1Bit_1].Value != 1) {
															Isb_Obj_1Bit[Obj_1Bit_1].Value = 1;
															Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
														}
													}
													else {
														if (Isb_Obj_1Bit[Obj_1Bit_1].Value != 0) {
															Isb_Obj_1Bit[Obj_1Bit_1].Value = 0;
															Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
														}
													}
												}
												Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHSHORT);
											}
											if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHLONG)) {
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_0) {
													// None
												}
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_1) {
													// Aus
													if (Isb_Obj_1Bit[Obj_1Bit_2].Value != 0) {
														Isb_Obj_1Bit[Obj_1Bit_2].Value = 0;
														Isb_Obj_1Bit[Obj_1Bit_2].IsChanged = TRUE;
													}
												}
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_2) {
													// Ein
													if (Isb_Obj_1Bit[Obj_1Bit_2].Value != 1) {
														Isb_Obj_1Bit[Obj_1Bit_2].Value = 1;
														Isb_Obj_1Bit[Obj_1Bit_2].IsChanged = TRUE;
													}
												}
												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_3) {
													// Um
													if (Isb_Obj_1Bit[Obj_1Bit_2].Value == 0) {
														if (Isb_Obj_1Bit[Obj_1Bit_2].Value != 1) {
															Isb_Obj_1Bit[Obj_1Bit_2].Value = 1;
															Isb_Obj_1Bit[Obj_1Bit_2].IsChanged = TRUE;
														}
													}
													else {
														if (Isb_Obj_1Bit[Obj_1Bit_2].Value != 0) {
															Isb_Obj_1Bit[Obj_1Bit_2].Value = 0;
															Isb_Obj_1Bit[Obj_1Bit_2].IsChanged = TRUE;
														}
													}
												}
												Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHLONG);
											}
											if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHREPEAT)) {
// TODO:


												Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHREPEAT);
											}
											break;
									}
									break;
//								case ISB_APP_DIGIN_CFG1_MODE_DIMMER:
//									// Betriebsart = Schalt-/Dimmsensor
//									switch (Isb_App_DigIn[AppIndex].Cfg1 & ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_MASK) {
//										case ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_0:
//											// Dimmen und Schalten
//											if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHSHORT)) {
//												// Schalten
//												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_0) {
//													// keine
//												}
//												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_1) {
//													// Ein
//													Isb_Obj_1Bit[Obj_1Bit_1].Value = 1;
//													Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
//												}
//												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_2) {
//													// Aus
//													Isb_Obj_1Bit[Obj_1Bit_1].Value = 0;
//													Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
//												}
//												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_3) {
//													// Um
//													if (Isb_Obj_1Bit[Obj_1Bit_1].Value == 0) {
//														Isb_Obj_1Bit[Obj_1Bit_1].Value = 1;
//													}
//													else {
//														Isb_Obj_1Bit[Obj_1Bit_1].Value = 0;
//													}
//													Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
//												}
//												Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHSHORT);
//											}
//											if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHLONG)) {
//												// Dimmen
//												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_0) {
//													// Heller
//													Isb_Obj_4Bit[Obj_4Bit_0].Value = (1 << ISB_APP_DIGIN_CFG3_DIMMER_DIRECTION) | (Isb_App_DigIn[AppIndex].Cfg3 & ISB_APP_DIGIN_CFG3_DIMMER_STEP_MASK);
//													Isb_Obj_4Bit[Obj_4Bit_0].IsChanged = TRUE;
//												}
//												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_0) {
//													// Dunkler
//													Isb_Obj_4Bit[Obj_4Bit_0].Value = (Isb_App_DigIn[AppIndex].Cfg3 & ISB_APP_DIGIN_CFG3_DIMMER_STEP_MASK);
//													Isb_Obj_4Bit[Obj_4Bit_0].IsChanged = TRUE;
//												}
//												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_0) {
//													// Heller/Dunkler
//													if (bit_is_clear(Isb_App_DigIn[AppIndex].Cfg3, ISB_APP_DIGIN_CFG3_DIMMER_DIRECTION)) {
//														Isb_Obj_4Bit[Obj_4Bit_0].Value = (1 << ISB_APP_DIGIN_CFG3_DIMMER_DIRECTION);
//													}
//													Isb_Obj_4Bit[Obj_4Bit_0].Value &= ~ISB_APP_DIGIN_CFG3_DIMMER_STEP_MASK;
//													Isb_Obj_4Bit[Obj_4Bit_0].Value |= (Isb_App_DigIn[AppIndex].Cfg3 & ISB_APP_DIGIN_CFG3_DIMMER_STEP_MASK);
//													Isb_Obj_4Bit[Obj_4Bit_0].IsChanged = TRUE;
//												}
//												Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHLONG);
//											}
//											if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHREPEAT)) {
//												// Dimmen
//												Isb_Obj_4Bit[Obj_4Bit_0].IsChanged = TRUE;
//												Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHREPEAT);
//											}
//											break;
//										case ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_1:
//											// Nur Dimmen
//											if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGH)) {
//												// Dimmen
//												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_0) {
//													// Heller
//													Isb_Obj_4Bit[Obj_4Bit_0].Value = (1 << ISB_APP_DIGIN_CFG3_DIMMER_DIRECTION) | (Isb_App_DigIn[AppIndex].Cfg3 & ISB_APP_DIGIN_CFG3_DIMMER_STEP_MASK);
//													Isb_Obj_4Bit[Obj_4Bit_0].IsChanged = TRUE;
//												}
//												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_0) {
//													// Dunkler
//													Isb_Obj_4Bit[Obj_4Bit_0].Value = (Isb_App_DigIn[AppIndex].Cfg3 & ISB_APP_DIGIN_CFG3_DIMMER_STEP_MASK);
//													Isb_Obj_4Bit[Obj_4Bit_0].IsChanged = TRUE;
//												}
//												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_0) {
//													// Heller/Dunkler
//													if (bit_is_clear(Isb_App_DigIn[AppIndex].Cfg3, ISB_APP_DIGIN_CFG3_DIMMER_DIRECTION)) {
//														Isb_Obj_4Bit[Obj_4Bit_0].Value = (1 << ISB_APP_DIGIN_CFG3_DIMMER_DIRECTION);
//													}
//													Isb_Obj_4Bit[Obj_4Bit_0].Value &= ~ISB_APP_DIGIN_CFG3_DIMMER_STEP_MASK;
//													Isb_Obj_4Bit[Obj_4Bit_0].Value |= (Isb_App_DigIn[AppIndex].Cfg3 & ISB_APP_DIGIN_CFG3_DIMMER_STEP_MASK);
//													Isb_Obj_4Bit[Obj_4Bit_0].IsChanged = TRUE;
//												}
//												Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGH);
//											}
//											if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHREPEAT)) {
//												// Dimmen
//												Isb_Obj_4Bit[Obj_4Bit_0].IsChanged = TRUE;
//												Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHREPEAT);
//											}
//											break;
//									}
//									break;
//								case ISB_APP_DIGIN_CFG1_MODE_JALOUSIE:
//									// Betriebsart = Jalousiesensor
//									switch (Isb_App_DigIn[AppIndex].Cfg1 & ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_MASK) {
//										case ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_0:
//											// Option 1-Taster-Betrieb (Kurz=Lamelle, Lang=Fahren)
//											if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHSHORT)) {
//												// Stop / Lamelle Auf/Zu
//												if (Isb_Obj_1Bit[Obj_1Bit_2].Value == 0) {
//													Isb_Obj_1Bit[Obj_1Bit_2].Value = 1;
//												}
//												else {
//													Isb_Obj_1Bit[Obj_1Bit_2].Value = 0;
//												}
//												Isb_Obj_1Bit[Obj_1Bit_2].IsChanged = TRUE;
//												Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHSHORT);
//											}
//											if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHLONG)) {
//												// Fahren Auf / Zu
//												if (Isb_Obj_1Bit[Obj_1Bit_1].Value == 0) {
//													Isb_Obj_1Bit[Obj_1Bit_1].Value = 1;
//												}
//												else {
//													Isb_Obj_1Bit[Obj_1Bit_1].Value = 0;
//												}
//												Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
//												Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHLONG);
//											}
//											break;
//										case ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_1:
//											// Option 1-Taster-Betrieb (Kurz=Fahren, Lang=Lamelle)
//											if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHSHORT)) {
//												// Fahren Auf / Zu
//												if (Isb_Obj_1Bit[Obj_1Bit_1].Value == 0) {
//													Isb_Obj_1Bit[Obj_1Bit_1].Value = 1;
//												}
//												else {
//													Isb_Obj_1Bit[Obj_1Bit_1].Value = 0;
//												}
//												Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
//												Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHSHORT);
//											}
//											if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHLONG)) {
//												// Stop / Lamelle Auf/Zu
//												if (Isb_Obj_1Bit[Obj_1Bit_2].Value == 0) {
//													Isb_Obj_1Bit[Obj_1Bit_2].Value = 1;
//												}
//												else {
//													Isb_Obj_1Bit[Obj_1Bit_2].Value = 0;
//												}
//												Isb_Obj_1Bit[Obj_1Bit_2].IsChanged = TRUE;
//												Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHLONG);
//											}
//											if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHREPEAT)) {
//												Isb_Obj_1Bit[Obj_1Bit_2].IsChanged = TRUE;
//												Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHREPEAT);
//											}
//											break;
//										case ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_2:
//											// Option 1-Taster-Betrieb (nur Fahren - Stop)
//											if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGH)) {
//												// Fahren Auf
//												if ((Isb_Obj_1Bit[Obj_1Bit_2].Value == 0) & (Isb_Obj_1Bit[Obj_1Bit_1].Value == 0)) {
//													Isb_Obj_1Bit[Obj_1Bit_1].Value = 1;
//													Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
//												}
//												// Stop
//												if ((Isb_Obj_1Bit[Obj_1Bit_2].Value == 0) & (Isb_Obj_1Bit[Obj_1Bit_1].Value == 1)) {
//													Isb_Obj_1Bit[Obj_1Bit_2].Value = 1;
//													Isb_Obj_1Bit[Obj_1Bit_2].IsChanged = TRUE;
//												}
//												// Fahren Ab
//												if ((Isb_Obj_1Bit[Obj_1Bit_2].Value == 1) & (Isb_Obj_1Bit[Obj_1Bit_1].Value == 1)) {
//													Isb_Obj_1Bit[Obj_1Bit_1].Value = 0;
//													Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
//												}
//												// Stop
//												if ((Isb_Obj_1Bit[Obj_1Bit_2].Value == 1) & (Isb_Obj_1Bit[Obj_1Bit_1].Value == 0)) {
//													Isb_Obj_1Bit[Obj_1Bit_2].Value = 0;
//													Isb_Obj_1Bit[Obj_1Bit_2].IsChanged = TRUE;
//												}
//												Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGH);
//											}
//											break;
//										case ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_3:
//											// Option 1-Schalter-Betrieb (nur Fahren)
//											if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGH)) {
//												// Fahren Ab
//												Isb_Obj_1Bit[Obj_1Bit_1].Value = 1;
//												Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
//												Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHSHORT);
//											}
//											if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_LOW)) {
//												// Fahren Auf
//												Isb_Obj_1Bit[Obj_1Bit_1].Value = 0;
//												Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
//												Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHSHORT);
//											}
//											break;
//										case ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_4:
//											// Option 2-Taster-Betrieb (Kurz=Lamelle, Lang=Fahren)
//											if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHSHORT)) {
//												// Stop / Lamelle Auf/Zu
//												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_0) {
//													Isb_Obj_1Bit[Obj_1Bit_2].Value = 0;
//												}
//												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_1) {
//													Isb_Obj_1Bit[Obj_1Bit_2].Value = 1;
//												}
//												Isb_Obj_1Bit[Obj_1Bit_2].IsChanged = TRUE;
//												Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHSHORT);
//											}
//											if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHLONG)) {
//												// Fahren Auf / Zu
//												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_0) {
//													Isb_Obj_1Bit[Obj_1Bit_1].Value = 0;
//												}
//												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_B_MASK) == ISB_APP_DIGIN_CFG2_ACTION_B_1) {
//													Isb_Obj_1Bit[Obj_1Bit_1].Value = 1;
//												}
//												Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
//												Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHLONG);
//											}
//											break;
//										case ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_5:
//											// Option 2-Schalter/Taster-Betrieb (nur Fahren)
//											if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGH)) {
//												// Fahren Auf / Zu
//												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_0) {
//													Isb_Obj_1Bit[Obj_1Bit_1].Value = 0;
//												}
//												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_1) {
//													Isb_Obj_1Bit[Obj_1Bit_1].Value = 1;
//												}
//												Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
//												Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHSHORT);
//											}
//											break;
//										case ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_6:
//											// Option 2-Taster-Betrieb (nur Fahren - Stop)
//											if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGH)) {
//												// Fahren Auf / Zu
//												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_0) {
//													// Fahren Auf
//													if ((Isb_Obj_1Bit[Obj_1Bit_2].Value == 0) & (Isb_Obj_1Bit[Obj_1Bit_1].Value == 0)) {
//														Isb_Obj_1Bit[Obj_1Bit_1].Value = 1;
//														Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
//													}
//													// Stop
//													if ((Isb_Obj_1Bit[Obj_1Bit_2].Value == 0) & (Isb_Obj_1Bit[Obj_1Bit_1].Value == 1)) {
//														Isb_Obj_1Bit[Obj_1Bit_2].Value = 1;
//														Isb_Obj_1Bit[Obj_1Bit_2].IsChanged = TRUE;
//													}
//												}
//												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_1) {
//													// Fahren Ab
//													if ((Isb_Obj_1Bit[Obj_1Bit_2].Value == 1) & (Isb_Obj_1Bit[Obj_1Bit_1].Value == 1)) {
//														Isb_Obj_1Bit[Obj_1Bit_1].Value = 0;
//														Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
//													}
//													// Stop
//													if ((Isb_Obj_1Bit[Obj_1Bit_2].Value == 1) & (Isb_Obj_1Bit[Obj_1Bit_1].Value == 0)) {
//														Isb_Obj_1Bit[Obj_1Bit_2].Value = 0;
//														Isb_Obj_1Bit[Obj_1Bit_2].IsChanged = TRUE;
//													}
//												}
//											}
//											break;
//										case ISB_APP_DIGIN_CFG1_OPERATINGFUNCTION_7:
//											// Option 2-Taster-Betrieb (nur Lamelle)
//											if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGH)) {
//												// Stop / Lamellen Auf / Zu
//												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_0) {
//													Isb_Obj_1Bit[Obj_1Bit_2].Value = 0;
//												}
//												if ((Isb_App_DigIn[AppIndex].Cfg2 & ISB_APP_DIGIN_CFG2_ACTION_A_MASK) == ISB_APP_DIGIN_CFG2_ACTION_A_1) {
//													Isb_Obj_1Bit[Obj_1Bit_2].Value = 1;
//												}
//												Isb_Obj_1Bit[Obj_1Bit_2].IsChanged = TRUE;
//												Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGH);
//											}
//											if (bit_is_set(Isb_App_DigIn[AppIndex].Event, ISB_APP_DIGIN_EVENT_HIGHREPEAT)) {
//												Isb_Obj_1Bit[Obj_1Bit_2].IsChanged = TRUE;
//												Isb_App_DigIn[AppIndex].Event &= ~(1<<ISB_APP_DIGIN_EVENT_HIGHREPEAT);
//											}
//											break;
//									}
//									break;
//								case ISB_APP_DIGIN_CFG1_MODE_xx:
//									// Betriebsart = Wert/Zwangsführung
//									break;
//								case ISB_APP_DIGIN_CFG1_MODE_xx:
//									// Betriebsart = Szene steuern
//									break;
//								case ISB_APP_DIGIN_CFG1_MODE_xx:
//									// Betriebsart = Schaltfolgen
//									break;
//								case ISB_APP_DIGIN_CFG1_MODE_xx:
//									// Betriebsart = Mehrfachbetätigung
//									break;
//								case ISB_APP_DIGIN_CFG1_MODE_xx:
//									// Betriebsart = Impulszähler
//									break;
							}



//						}
// <- TODO:
					}
				}
				Isb_App_DigIn_Ctrl &= ~(1 << ISB_CTRL_SOFTIRQ_EXEC);
			}
		#endif /* ISB_APP_DIGIN_MAX */

		#if defined(ISB_APP_ANAIN_MAX)
			if (bit_is_set(Isb_App_AnaIn_Ctrl, ISB_CTRL_SOFTIRQ_EXEC)) {
				for (uint8_t AppIndex = 0; AppIndex < ISB_APP_ANAIN_MAX; AppIndex++) {
					uint8_t Ch = pgm_read_byte(&pgmIsb_App_AnaIn_Ch_Array[AppIndex]);
					if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_ENABLED)) {
						uint8_t Obj_Float_0 = pgm_read_byte(&pgmIsb_App_AnaIn_Obj_Float_0_Array[AppIndex]);
						uint8_t Obj_1Bit_0 = pgm_read_byte(&pgmIsb_App_AnaIn_Obj_1Bit_0_Array[AppIndex]);
						uint8_t Obj_1Bit_1 = pgm_read_byte(&pgmIsb_App_AnaIn_Obj_1Bit_1_Array[AppIndex]);
// Sensor einlesen
							switch (Isb_App_AnaIn[AppIndex].Cfg0 & ISB_APP_ANAIN_CFG0_MODE_MASK) {
								case ISB_APP_ANAIN_CFG0_MODE_ADC:
									// ...
									if (Isb_App_AnaIn[AppIndex].TimeCount == 1000) {
										Isb_App_AnaIn[AppIndex].TimeCount = 0;
									}
									if (Isb_App_AnaIn[AppIndex].TimeCount == 0) {
										Lib_Adc_Init(Isb_App_AnaIn[AppIndex].Cfg1, Isb_App_AnaIn[AppIndex].Cfg2, &Isb_App_AnaIn[AppIndex].Value, &Isb_App_Convert_None);
									}
									Isb_App_AnaIn[AppIndex].TimeCount++;
									break;
								case ISB_APP_ANAIN_CFG0_MODE_ADC_PT100:
									// ...
									if (Isb_App_AnaIn[AppIndex].TimeCount == 1000) {
										Isb_App_AnaIn[AppIndex].TimeCount = 0;
									}
									if (Isb_App_AnaIn[AppIndex].TimeCount == 0) {
										Lib_Adc_Init(Isb_App_AnaIn[AppIndex].Cfg1, Isb_App_AnaIn[AppIndex].Cfg2, &Isb_App_AnaIn[AppIndex].Value, &Isb_App_Convert_PT100);
									}
									Isb_App_AnaIn[AppIndex].TimeCount++;
									break;
								case ISB_APP_ANAIN_CFG0_MODE_DS1621:
									// ...
									if (Isb_App_AnaIn[AppIndex].TimeCount == 1000) {
										uint16_t Result;
										Lib_Ds1621_ReadTemperature(Isb_App_AnaIn[AppIndex].Cfg1, &Result);
										uint16_t Vorzeichen = 0x8000;
										if (Result < 0) {
											Vorzeichen = 0x0000;
										}
										uint16_t Mantisse = (Result >> 8) * 100;
										if (bit_is_set(Result, 7)) {
											Mantisse += 50;
										}
										uint16_t Exponent = 0;
										while (Mantisse > 2047) {
											Exponent++;
											Mantisse = Mantisse >> 1;
										}
										Exponent = Exponent << 11;
										Isb_App_AnaIn[AppIndex].Value = Vorzeichen + Exponent + Mantisse;
										Isb_App_AnaIn[AppIndex].TimeCount = 0;
									}
									if (Isb_App_AnaIn[AppIndex].TimeCount == 0) {
										Lib_Ds1621_StartConvertT(Isb_App_AnaIn[AppIndex].Cfg1);
									}
									Isb_App_AnaIn[AppIndex].TimeCount++;
									break;
								default:
									Isb_App_AnaIn[AppIndex].Value = 0x7FFF;
									break;
							}
// Sensor auswerten
						// Temperatursensor
						if (Isb_Obj_Float[Obj_Float_0].Value != Isb_App_AnaIn[AppIndex].Value) {
							Isb_Obj_Float[Obj_Float_0].Value = Isb_App_AnaIn[AppIndex].Value;
							Isb_Obj_Float[Obj_Float_0].IsChanged = TRUE;
						}
						// Temperaturschalter 1
						if (Isb_Obj_Float[Obj_Float_0].Value > Isb_App_AnaIn[AppIndex].On1) {
							if (Isb_Obj_1Bit[Obj_1Bit_0].Value != TRUE) {
								Isb_Obj_1Bit[Obj_1Bit_0].Value = TRUE;
								Isb_Obj_1Bit[Obj_1Bit_0].IsChanged = TRUE;
							}
						}
						if (Isb_Obj_Float[Obj_Float_0].Value < Isb_App_AnaIn[AppIndex].Off1) {
							if (Isb_Obj_1Bit[Obj_1Bit_0].Value != FALSE) {
								Isb_Obj_1Bit[Obj_1Bit_0].Value = FALSE;
								Isb_Obj_1Bit[Obj_1Bit_0].IsChanged = TRUE;
							}
						}
						// Temperaturschalter 2
						if (Isb_Obj_Float[Obj_Float_0].Value > Isb_App_AnaIn[AppIndex].On2) {
							if (Isb_Obj_1Bit[Obj_1Bit_1].Value != TRUE) {
								Isb_Obj_1Bit[Obj_1Bit_1].Value = TRUE;
								Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
							}
						}
						if (Isb_Obj_Float[Obj_Float_0].Value < Isb_App_AnaIn[AppIndex].Off2) {
							if (Isb_Obj_1Bit[Obj_1Bit_1].Value != FALSE) {
								Isb_Obj_1Bit[Obj_1Bit_1].Value = FALSE;
								Isb_Obj_1Bit[Obj_1Bit_1].IsChanged = TRUE;
							}
						}
					}
				}
				Isb_App_AnaIn_Ctrl &= ~(1 << ISB_CTRL_SOFTIRQ_EXEC);
			}
		#endif /* ISB_APP_ANAIN_MAX */

		#if defined(ISB_APP_LCD_MAX)
			if (bit_is_set(Isb_App_Lcd_Ctrl, ISB_CTRL_SOFTIRQ_EXEC)) {



//Lcd_Clear();
//char Buffer[20];
//itoa(Isb_App_Float_Sensor[AppIndex].Value, Buffer, 10);
//Lcd_String(Buffer);
//Lcd_SetCursor(0, 2);
//uint16_t Temp = 0;
//itoa(Temp, Buffer, 10);
//Lcd_String(Buffer);



//#				for (uint8_t AppIndex = 0; AppIndex < ISB_APP_LCD_MAX; AppIndex++) {
//					uint8_t Ch = pgm_read_byte(&pgmIsb_App_Lcd_Ch_Array[AppIndex]);
//					if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_ENABLED)) {
//						uint8_t Pin0 = pgm_read_byte(&pgmIsb_App_Lcd_Pin0_Array[AppIndex]);



//					}
//#				}
				Isb_App_Lcd_Ctrl &= ~(1 << ISB_CTRL_SOFTIRQ_EXEC);
			}
		#endif /* ISB_APP_LCD_MAX */

	}



#endif /* ISB_APP_C_ */
