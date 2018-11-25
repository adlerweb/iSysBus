/**
 * @file		avrlib/trunk/lib/isb_obj.c
 *
 * @brief		iSysBus Object.
 *
 * This file includes the iSysBus Object.
 *
 * @author		© Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
 *
 * @date		$Date: 2011-10-16 23:48:09 +0200 (So, 16 Okt 2011) $
 *
 * @version		$Rev: 6141 $
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





#ifndef ISB_OBJ_C_
	#define ISB_OBJ_C_



	void Isb_Obj_Init(void) {

		#if defined(ISB_OBJ_1BIT_MAX)
			for (uint8_t ObjIndex = 0; ObjIndex < ISB_OBJ_1BIT_MAX; ObjIndex++) {
				uint8_t Ch = pgm_read_byte(&pgmIsb_Obj_1Bit_Ch_Array[ObjIndex]);
				uint16_t eepAddrCtrl = 0;
				uint16_t eepAddrTov = 0;
				uint16_t eepAddrValueInit = 0;
				switch (ObjIndex) {
					#if defined(ISB_OBJ_1BIT_0)
						case 0:
							eepAddrCtrl = ISB_OBJ_1BIT_0_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_0_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_0_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_0 */
					#if defined(ISB_OBJ_1BIT_1)
						case 1:
							eepAddrCtrl = ISB_OBJ_1BIT_1_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_1_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_1_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_1 */
					#if defined(ISB_OBJ_1BIT_2)
						case 2:
							eepAddrCtrl = ISB_OBJ_1BIT_2_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_2_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_2_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_2 */
					#if defined(ISB_OBJ_1BIT_3)
						case 3:
							eepAddrCtrl = ISB_OBJ_1BIT_3_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_3_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_3_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_3 */
					#if defined(ISB_OBJ_1BIT_4)
						case 4:
							eepAddrCtrl = ISB_OBJ_1BIT_4_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_4_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_4_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_4 */
					#if defined(ISB_OBJ_1BIT_5)
						case 5:
							eepAddrCtrl = ISB_OBJ_1BIT_5_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_5_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_5_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_5 */
					#if defined(ISB_OBJ_1BIT_6)
						case 6:
							eepAddrCtrl = ISB_OBJ_1BIT_6_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_6_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_6_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_6 */
					#if defined(ISB_OBJ_1BIT_7)
						case 7:
							eepAddrCtrl = ISB_OBJ_1BIT_7_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_7_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_7_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_7 */
					#if defined(ISB_OBJ_1BIT_8)
						case 8:
							eepAddrCtrl = ISB_OBJ_1BIT_8_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_8_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_8_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_8 */
					#if defined(ISB_OBJ_1BIT_9)
						case 9:
							eepAddrCtrl = ISB_OBJ_1BIT_9_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_9_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_9_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_9 */
					#if defined(ISB_OBJ_1BIT_10)
						case 10:
							eepAddrCtrl = ISB_OBJ_1BIT_10_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_10_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_10_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_10 */
					#if defined(ISB_OBJ_1BIT_11)
						case 11:
							eepAddrCtrl = ISB_OBJ_1BIT_11_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_11_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_11_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_11 */
					#if defined(ISB_OBJ_1BIT_12)
						case 12:
							eepAddrCtrl = ISB_OBJ_1BIT_12_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_12_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_12_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_12 */
					#if defined(ISB_OBJ_1BIT_13)
						case 13:
							eepAddrCtrl = ISB_OBJ_1BIT_13_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_13_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_13_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_13 */
					#if defined(ISB_OBJ_1BIT_14)
						case 14:
							eepAddrCtrl = ISB_OBJ_1BIT_14_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_14_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_14_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_14 */
					#if defined(ISB_OBJ_1BIT_15)
						case 15:
							eepAddrCtrl = ISB_OBJ_1BIT_15_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_15_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_15_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_15 */
					#if defined(ISB_OBJ_1BIT_16)
						case 16:
							eepAddrCtrl = ISB_OBJ_1BIT_16_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_16_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_16_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_16 */
					#if defined(ISB_OBJ_1BIT_17)
						case 17:
							eepAddrCtrl = ISB_OBJ_1BIT_17_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_17_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_17_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_17 */
					#if defined(ISB_OBJ_1BIT_18)
						case 18:
							eepAddrCtrl = ISB_OBJ_1BIT_18_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_18_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_18_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_18 */
					#if defined(ISB_OBJ_1BIT_19)
						case 19:
							eepAddrCtrl = ISB_OBJ_1BIT_19_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_19_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_19_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_19 */
					#if defined(ISB_OBJ_1BIT_20)
						case 20:
							eepAddrCtrl = ISB_OBJ_1BIT_20_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_20_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_20_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_20 */
					#if defined(ISB_OBJ_1BIT_21)
						case 21:
							eepAddrCtrl = ISB_OBJ_1BIT_21_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_21_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_21_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_21 */
					#if defined(ISB_OBJ_1BIT_22)
						case 22:
							eepAddrCtrl = ISB_OBJ_1BIT_22_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_22_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_22_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_22 */
					#if defined(ISB_OBJ_1BIT_23)
						case 23:
							eepAddrCtrl = ISB_OBJ_1BIT_23_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_23_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_23_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_23 */
					#if defined(ISB_OBJ_1BIT_24)
						case 24:
							eepAddrCtrl = ISB_OBJ_1BIT_24_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_24_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_24_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_24 */
					#if defined(ISB_OBJ_1BIT_25)
						case 25:
							eepAddrCtrl = ISB_OBJ_1BIT_25_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_25_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_25_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_25 */
					#if defined(ISB_OBJ_1BIT_26)
						case 26:
							eepAddrCtrl = ISB_OBJ_1BIT_26_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_26_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_26_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_26 */
					#if defined(ISB_OBJ_1BIT_27)
						case 27:
							eepAddrCtrl = ISB_OBJ_1BIT_27_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_27_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_27_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_27 */
					#if defined(ISB_OBJ_1BIT_28)
						case 28:
							eepAddrCtrl = ISB_OBJ_1BIT_28_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_28_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_28_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_28 */
					#if defined(ISB_OBJ_1BIT_29)
						case 29:
							eepAddrCtrl = ISB_OBJ_1BIT_29_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_29_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_29_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_29 */
					#if defined(ISB_OBJ_1BIT_30)
						case 30:
							eepAddrCtrl = ISB_OBJ_1BIT_30_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_30_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_30_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_30 */
					#if defined(ISB_OBJ_1BIT_31)
						case 31:
							eepAddrCtrl = ISB_OBJ_1BIT_31_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_31_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_31_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_31 */
					#if defined(ISB_OBJ_1BIT_32)
						case 32:
							eepAddrCtrl = ISB_OBJ_1BIT_32_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_32_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_32_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_32 */
					#if defined(ISB_OBJ_1BIT_33)
						case 33:
							eepAddrCtrl = ISB_OBJ_1BIT_33_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_33_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_33_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_33 */
					#if defined(ISB_OBJ_1BIT_34)
						case 34:
							eepAddrCtrl = ISB_OBJ_1BIT_34_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_34_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_34_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_34 */
					#if defined(ISB_OBJ_1BIT_35)
						case 35:
							eepAddrCtrl = ISB_OBJ_1BIT_35_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_35_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_35_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_35 */
					#if defined(ISB_OBJ_1BIT_36)
						case 36:
							eepAddrCtrl = ISB_OBJ_1BIT_36_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_36_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_36_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_36 */
					#if defined(ISB_OBJ_1BIT_37)
						case 37:
							eepAddrCtrl = ISB_OBJ_1BIT_37_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_37_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_37_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_37 */
					#if defined(ISB_OBJ_1BIT_38)
						case 38:
							eepAddrCtrl = ISB_OBJ_1BIT_38_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_38_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_38_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_38 */
					#if defined(ISB_OBJ_1BIT_39)
						case 39:
							eepAddrCtrl = ISB_OBJ_1BIT_39_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_39_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_39_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_39 */
					#if defined(ISB_OBJ_1BIT_40)
						case 40:
							eepAddrCtrl = ISB_OBJ_1BIT_40_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_40_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_40_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_40 */
					#if defined(ISB_OBJ_1BIT_41)
						case 41:
							eepAddrCtrl = ISB_OBJ_1BIT_41_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_41_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_41_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_41 */
					#if defined(ISB_OBJ_1BIT_42)
						case 42:
							eepAddrCtrl = ISB_OBJ_1BIT_42_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_42_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_42_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_42 */
					#if defined(ISB_OBJ_1BIT_43)
						case 43:
							eepAddrCtrl = ISB_OBJ_1BIT_43_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_43_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_43_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_43 */
					#if defined(ISB_OBJ_1BIT_44)
						case 44:
							eepAddrCtrl = ISB_OBJ_1BIT_44_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_44_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_44_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_44 */
					#if defined(ISB_OBJ_1BIT_45)
						case 45:
							eepAddrCtrl = ISB_OBJ_1BIT_45_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_45_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_45_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_45 */
					#if defined(ISB_OBJ_1BIT_46)
						case 46:
							eepAddrCtrl = ISB_OBJ_1BIT_46_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_46_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_46_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_46 */
					#if defined(ISB_OBJ_1BIT_47)
						case 47:
							eepAddrCtrl = ISB_OBJ_1BIT_47_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_47_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_47_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_47 */
					#if defined(ISB_OBJ_1BIT_48)
						case 48:
							eepAddrCtrl = ISB_OBJ_1BIT_48_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_48_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_48_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_48 */
					#if defined(ISB_OBJ_1BIT_49)
						case 49:
							eepAddrCtrl = ISB_OBJ_1BIT_49_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_49_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_49_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_49 */
					#if defined(ISB_OBJ_1BIT_50)
						case 50:
							eepAddrCtrl = ISB_OBJ_1BIT_50_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_50_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_50_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_50 */
					#if defined(ISB_OBJ_1BIT_51)
						case 51:
							eepAddrCtrl = ISB_OBJ_1BIT_51_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_51_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_51_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_51 */
					#if defined(ISB_OBJ_1BIT_52)
						case 52:
							eepAddrCtrl = ISB_OBJ_1BIT_52_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_52_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_52_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_52 */
					#if defined(ISB_OBJ_1BIT_53)
						case 53:
							eepAddrCtrl = ISB_OBJ_1BIT_53_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_53_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_53_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_53 */
					#if defined(ISB_OBJ_1BIT_54)
						case 54:
							eepAddrCtrl = ISB_OBJ_1BIT_54_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_54_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_54_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_54 */
					#if defined(ISB_OBJ_1BIT_55)
						case 55:
							eepAddrCtrl = ISB_OBJ_1BIT_55_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_55_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_55_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_55 */
					#if defined(ISB_OBJ_1BIT_56)
						case 56:
							eepAddrCtrl = ISB_OBJ_1BIT_56_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_56_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_56_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_56 */
					#if defined(ISB_OBJ_1BIT_57)
						case 57:
							eepAddrCtrl = ISB_OBJ_1BIT_57_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_57_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_57_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_57 */
					#if defined(ISB_OBJ_1BIT_58)
						case 58:
							eepAddrCtrl = ISB_OBJ_1BIT_58_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_58_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_58_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_58 */
					#if defined(ISB_OBJ_1BIT_59)
						case 59:
							eepAddrCtrl = ISB_OBJ_1BIT_59_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_59_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_59_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_59 */
					#if defined(ISB_OBJ_1BIT_60)
						case 60:
							eepAddrCtrl = ISB_OBJ_1BIT_60_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_60_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_60_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_60 */
					#if defined(ISB_OBJ_1BIT_61)
						case 61:
							eepAddrCtrl = ISB_OBJ_1BIT_61_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_61_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_61_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_61 */
					#if defined(ISB_OBJ_1BIT_62)
						case 62:
							eepAddrCtrl = ISB_OBJ_1BIT_62_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_62_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_62_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_62 */
					#if defined(ISB_OBJ_1BIT_63)
						case 63:
							eepAddrCtrl = ISB_OBJ_1BIT_63_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_1BIT_63_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_1BIT_63_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_1BIT_63 */
				}
				if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_ENABLED)) {
					Isb_Obj_1Bit[ObjIndex].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddrCtrl);
					if (bit_is_set(Isb_Obj_1Bit[ObjIndex].Ctrl, ISB_OBJ_CTRL_ENABLED)) {
						Isb_Obj_1Bit[ObjIndex].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddrTov);
						Isb_Obj_1Bit[ObjIndex].Value = lib_eep_fw_read_byte((uint8_t *)eepAddrValueInit);
						Isb_Obj_1Bit[ObjIndex].IsChanged = FALSE;
					}
				}
			}
		#endif /* ISB_OBJ_1BIT_MAX */

		#if defined(ISB_OBJ_4BIT_MAX)
			for (uint8_t ObjIndex = 0; ObjIndex < ISB_OBJ_4BIT_MAX; ObjIndex++) {
				uint8_t Ch = pgm_read_byte(&pgmIsb_Obj_4Bit_Ch_Array[ObjIndex]);
				uint16_t eepAddrCtrl = 0;
				uint16_t eepAddrTov = 0;
				uint16_t eepAddrValueInit = 0;
				switch (ObjIndex) {
					#if defined(ISB_OBJ_4BIT_0)
						case 0:
							eepAddrCtrl = ISB_OBJ_4BIT_0_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_0_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_0_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_0 */
					#if defined(ISB_OBJ_4BIT_1)
						case 1:
							eepAddrCtrl = ISB_OBJ_4BIT_1_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_1_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_1_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_1 */
					#if defined(ISB_OBJ_4BIT_2)
						case 2:
							eepAddrCtrl = ISB_OBJ_4BIT_2_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_2_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_2_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_2 */
					#if defined(ISB_OBJ_4BIT_3)
						case 3:
							eepAddrCtrl = ISB_OBJ_4BIT_3_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_3_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_3_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_3 */
					#if defined(ISB_OBJ_4BIT_4)
						case 4:
							eepAddrCtrl = ISB_OBJ_4BIT_4_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_4_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_4_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_4 */
					#if defined(ISB_OBJ_4BIT_5)
						case 5:
							eepAddrCtrl = ISB_OBJ_4BIT_5_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_5_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_5_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_5 */
					#if defined(ISB_OBJ_4BIT_6)
						case 6:
							eepAddrCtrl = ISB_OBJ_4BIT_6_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_6_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_6_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_6 */
					#if defined(ISB_OBJ_4BIT_7)
						case 7:
							eepAddrCtrl = ISB_OBJ_4BIT_7_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_7_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_7_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_7 */
					#if defined(ISB_OBJ_4BIT_8)
						case 8:
							eepAddrCtrl = ISB_OBJ_4BIT_8_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_8_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_8_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_8 */
					#if defined(ISB_OBJ_4BIT_9)
						case 9:
							eepAddrCtrl = ISB_OBJ_4BIT_9_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_9_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_9_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_9 */
					#if defined(ISB_OBJ_4BIT_10)
						case 10:
							eepAddrCtrl = ISB_OBJ_4BIT_10_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_10_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_10_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_10 */
					#if defined(ISB_OBJ_4BIT_11)
						case 11:
							eepAddrCtrl = ISB_OBJ_4BIT_11_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_11_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_11_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_11 */
					#if defined(ISB_OBJ_4BIT_12)
						case 12:
							eepAddrCtrl = ISB_OBJ_4BIT_12_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_12_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_12_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_12 */
					#if defined(ISB_OBJ_4BIT_13)
						case 13:
							eepAddrCtrl = ISB_OBJ_4BIT_13_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_13_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_13_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_13 */
					#if defined(ISB_OBJ_4BIT_14)
						case 14:
							eepAddrCtrl = ISB_OBJ_4BIT_14_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_14_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_14_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_14 */
					#if defined(ISB_OBJ_4BIT_15)
						case 15:
							eepAddrCtrl = ISB_OBJ_4BIT_15_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_15_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_15_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_15 */
					#if defined(ISB_OBJ_4BIT_16)
						case 16:
							eepAddrCtrl = ISB_OBJ_4BIT_16_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_16_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_16_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_16 */
					#if defined(ISB_OBJ_4BIT_17)
						case 17:
							eepAddrCtrl = ISB_OBJ_4BIT_17_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_17_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_17_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_17 */
					#if defined(ISB_OBJ_4BIT_18)
						case 18:
							eepAddrCtrl = ISB_OBJ_4BIT_18_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_18_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_18_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_18 */
					#if defined(ISB_OBJ_4BIT_19)
						case 19:
							eepAddrCtrl = ISB_OBJ_4BIT_19_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_19_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_19_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_19 */
					#if defined(ISB_OBJ_4BIT_20)
						case 20:
							eepAddrCtrl = ISB_OBJ_4BIT_20_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_20_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_20_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_20 */
					#if defined(ISB_OBJ_4BIT_21)
						case 21:
							eepAddrCtrl = ISB_OBJ_4BIT_21_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_21_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_21_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_21 */
					#if defined(ISB_OBJ_4BIT_22)
						case 22:
							eepAddrCtrl = ISB_OBJ_4BIT_22_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_22_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_22_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_22 */
					#if defined(ISB_OBJ_4BIT_23)
						case 23:
							eepAddrCtrl = ISB_OBJ_4BIT_23_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_23_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_23_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_23 */
					#if defined(ISB_OBJ_4BIT_24)
						case 24:
							eepAddrCtrl = ISB_OBJ_4BIT_24_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_24_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_24_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_24 */
					#if defined(ISB_OBJ_4BIT_25)
						case 25:
							eepAddrCtrl = ISB_OBJ_4BIT_25_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_25_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_25_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_25 */
					#if defined(ISB_OBJ_4BIT_26)
						case 26:
							eepAddrCtrl = ISB_OBJ_4BIT_26_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_26_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_26_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_26 */
					#if defined(ISB_OBJ_4BIT_27)
						case 27:
							eepAddrCtrl = ISB_OBJ_4BIT_27_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_27_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_27_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_27 */
					#if defined(ISB_OBJ_4BIT_28)
						case 28:
							eepAddrCtrl = ISB_OBJ_4BIT_28_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_28_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_28_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_28 */
					#if defined(ISB_OBJ_4BIT_29)
						case 29:
							eepAddrCtrl = ISB_OBJ_4BIT_29_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_29_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_29_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_29 */
					#if defined(ISB_OBJ_4BIT_30)
						case 30:
							eepAddrCtrl = ISB_OBJ_4BIT_30_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_30_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_30_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_30 */
					#if defined(ISB_OBJ_4BIT_31)
						case 31:
							eepAddrCtrl = ISB_OBJ_4BIT_31_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_4BIT_31_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_4BIT_31_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_4BIT_31 */
				}
				if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_ENABLED)) {
					Isb_Obj_4Bit[ObjIndex].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddrCtrl);
					if (bit_is_set(Isb_Obj_4Bit[ObjIndex].Ctrl, ISB_OBJ_CTRL_ENABLED)) {
						Isb_Obj_4Bit[ObjIndex].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddrTov);
						Isb_Obj_4Bit[ObjIndex].Value = lib_eep_fw_read_byte((uint8_t *)eepAddrValueInit);
						Isb_Obj_4Bit[ObjIndex].IsChanged = FALSE;
					}
				}
			}
		#endif /* ISB_OBJ_4BIT_MAX */

		#if defined(ISB_OBJ_8BIT_MAX)
			for (uint8_t ObjIndex = 0; ObjIndex < ISB_OBJ_8BIT_MAX; ObjIndex++) {
				uint8_t Ch = pgm_read_byte(&pgmIsb_Obj_8Bit_Ch_Array[ObjIndex]);
				uint16_t eepAddrCtrl = 0;
				uint16_t eepAddrTov = 0;
				uint16_t eepAddrValueInit = 0;
				switch (ObjIndex) {
					#if defined(ISB_OBJ_8BIT_0)
						case 0:
							eepAddrCtrl = ISB_OBJ_8BIT_0_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_0_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_0_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_0 */
					#if defined(ISB_OBJ_8BIT_1)
						case 1:
							eepAddrCtrl = ISB_OBJ_8BIT_1_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_1_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_1_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_1 */
					#if defined(ISB_OBJ_8BIT_2)
						case 2:
							eepAddrCtrl = ISB_OBJ_8BIT_2_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_2_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_2_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_2 */
					#if defined(ISB_OBJ_8BIT_3)
						case 3:
							eepAddrCtrl = ISB_OBJ_8BIT_3_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_3_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_3_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_3 */
					#if defined(ISB_OBJ_8BIT_4)
						case 4:
							eepAddrCtrl = ISB_OBJ_8BIT_4_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_4_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_4_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_4 */
					#if defined(ISB_OBJ_8BIT_5)
						case 5:
							eepAddrCtrl = ISB_OBJ_8BIT_5_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_5_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_5_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_5 */
					#if defined(ISB_OBJ_8BIT_6)
						case 6:
							eepAddrCtrl = ISB_OBJ_8BIT_6_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_6_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_6_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_6 */
					#if defined(ISB_OBJ_8BIT_7)
						case 7:
							eepAddrCtrl = ISB_OBJ_8BIT_7_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_7_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_7_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_7 */
					#if defined(ISB_OBJ_8BIT_8)
						case 8:
							eepAddrCtrl = ISB_OBJ_8BIT_8_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_8_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_8_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_8 */
					#if defined(ISB_OBJ_8BIT_9)
						case 9:
							eepAddrCtrl = ISB_OBJ_8BIT_9_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_9_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_9_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_9 */
					#if defined(ISB_OBJ_8BIT_10)
						case 10:
							eepAddrCtrl = ISB_OBJ_8BIT_10_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_10_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_10_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_10 */
					#if defined(ISB_OBJ_8BIT_11)
						case 11:
							eepAddrCtrl = ISB_OBJ_8BIT_11_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_11_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_11_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_11 */
					#if defined(ISB_OBJ_8BIT_12)
						case 12:
							eepAddrCtrl = ISB_OBJ_8BIT_12_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_12_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_12_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_12 */
					#if defined(ISB_OBJ_8BIT_13)
						case 13:
							eepAddrCtrl = ISB_OBJ_8BIT_13_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_13_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_13_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_13 */
					#if defined(ISB_OBJ_8BIT_14)
						case 14:
							eepAddrCtrl = ISB_OBJ_8BIT_14_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_14_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_14_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_14 */
					#if defined(ISB_OBJ_8BIT_15)
						case 15:
							eepAddrCtrl = ISB_OBJ_8BIT_15_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_15_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_15_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_15 */
					#if defined(ISB_OBJ_8BIT_16)
						case 16:
							eepAddrCtrl = ISB_OBJ_8BIT_16_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_16_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_16_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_16 */
					#if defined(ISB_OBJ_8BIT_17)
						case 17:
							eepAddrCtrl = ISB_OBJ_8BIT_17_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_17_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_17_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_17 */
					#if defined(ISB_OBJ_8BIT_18)
						case 18:
							eepAddrCtrl = ISB_OBJ_8BIT_18_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_18_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_18_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_18 */
					#if defined(ISB_OBJ_8BIT_19)
						case 19:
							eepAddrCtrl = ISB_OBJ_8BIT_19_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_19_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_19_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_19 */
					#if defined(ISB_OBJ_8BIT_20)
						case 20:
							eepAddrCtrl = ISB_OBJ_8BIT_20_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_20_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_20_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_20 */
					#if defined(ISB_OBJ_8BIT_21)
						case 21:
							eepAddrCtrl = ISB_OBJ_8BIT_21_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_21_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_21_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_21 */
					#if defined(ISB_OBJ_8BIT_22)
						case 22:
							eepAddrCtrl = ISB_OBJ_8BIT_22_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_22_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_22_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_22 */
					#if defined(ISB_OBJ_8BIT_23)
						case 23:
							eepAddrCtrl = ISB_OBJ_8BIT_23_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_23_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_23_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_23 */
					#if defined(ISB_OBJ_8BIT_24)
						case 24:
							eepAddrCtrl = ISB_OBJ_8BIT_24_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_24_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_24_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_24 */
					#if defined(ISB_OBJ_8BIT_25)
						case 25:
							eepAddrCtrl = ISB_OBJ_8BIT_25_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_25_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_25_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_25 */
					#if defined(ISB_OBJ_8BIT_26)
						case 26:
							eepAddrCtrl = ISB_OBJ_8BIT_26_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_26_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_26_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_26 */
					#if defined(ISB_OBJ_8BIT_27)
						case 27:
							eepAddrCtrl = ISB_OBJ_8BIT_27_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_27_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_27_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_27 */
					#if defined(ISB_OBJ_8BIT_28)
						case 28:
							eepAddrCtrl = ISB_OBJ_8BIT_28_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_28_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_28_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_28 */
					#if defined(ISB_OBJ_8BIT_29)
						case 29:
							eepAddrCtrl = ISB_OBJ_8BIT_29_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_29_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_29_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_29 */
					#if defined(ISB_OBJ_8BIT_30)
						case 30:
							eepAddrCtrl = ISB_OBJ_8BIT_30_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_30_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_30_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_30 */
					#if defined(ISB_OBJ_8BIT_31)
						case 31:
							eepAddrCtrl = ISB_OBJ_8BIT_31_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_8BIT_31_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_8BIT_31_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_8BIT_31 */
				}
				if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_ENABLED)) {
					Isb_Obj_8Bit[ObjIndex].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddrCtrl);
					if (bit_is_set(Isb_Obj_8Bit[ObjIndex].Ctrl, ISB_OBJ_CTRL_ENABLED)) {
						Isb_Obj_8Bit[ObjIndex].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddrTov);
						Isb_Obj_8Bit[ObjIndex].Value = lib_eep_fw_read_byte((uint8_t *)eepAddrValueInit);
						Isb_Obj_8Bit[ObjIndex].IsChanged = FALSE;
					}
				}
			}
		#endif /* ISB_OBJ_8BIT_MAX */

		#if defined(ISB_OBJ_FLOAT_MAX)
			for (uint8_t ObjIndex = 0; ObjIndex < ISB_OBJ_FLOAT_MAX; ObjIndex++) {
				uint8_t Ch = pgm_read_byte(&pgmIsb_Obj_Float_Ch_Array[ObjIndex]);
				uint16_t eepAddrCtrl = 0;
				uint16_t eepAddrTov = 0;
				uint16_t eepAddrValueInit = 0;
				switch (ObjIndex) {
					#if defined(ISB_OBJ_FLOAT_0)
						case 0:
							eepAddrCtrl = ISB_OBJ_FLOAT_0_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_0_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_0_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_0 */
					#if defined(ISB_OBJ_FLOAT_1)
						case 1:
							eepAddrCtrl = ISB_OBJ_FLOAT_1_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_1_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_1_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_1 */
					#if defined(ISB_OBJ_FLOAT_2)
						case 2:
							eepAddrCtrl = ISB_OBJ_FLOAT_2_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_2_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_2_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_2 */
					#if defined(ISB_OBJ_FLOAT_3)
						case 3:
							eepAddrCtrl = ISB_OBJ_FLOAT_3_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_3_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_3_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_3 */
					#if defined(ISB_OBJ_FLOAT_4)
						case 4:
							eepAddrCtrl = ISB_OBJ_FLOAT_4_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_4_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_4_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_4 */
					#if defined(ISB_OBJ_FLOAT_5)
						case 5:
							eepAddrCtrl = ISB_OBJ_FLOAT_5_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_5_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_5_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_5 */
					#if defined(ISB_OBJ_FLOAT_6)
						case 6:
							eepAddrCtrl = ISB_OBJ_FLOAT_6_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_6_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_6_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_6 */
					#if defined(ISB_OBJ_FLOAT_7)
						case 7:
							eepAddrCtrl = ISB_OBJ_FLOAT_7_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_7_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_7_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_7 */
					#if defined(ISB_OBJ_FLOAT_8)
						case 8:
							eepAddrCtrl = ISB_OBJ_FLOAT_8_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_8_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_8_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_8 */
					#if defined(ISB_OBJ_FLOAT_9)
						case 9:
							eepAddrCtrl = ISB_OBJ_FLOAT_9_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_9_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_9_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_9 */
					#if defined(ISB_OBJ_FLOAT_10)
						case 10:
							eepAddrCtrl = ISB_OBJ_FLOAT_10_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_10_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_10_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_10 */
					#if defined(ISB_OBJ_FLOAT_11)
						case 11:
							eepAddrCtrl = ISB_OBJ_FLOAT_11_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_11_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_11_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_11 */
					#if defined(ISB_OBJ_FLOAT_12)
						case 12:
							eepAddrCtrl = ISB_OBJ_FLOAT_12_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_12_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_12_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_12 */
					#if defined(ISB_OBJ_FLOAT_13)
						case 13:
							eepAddrCtrl = ISB_OBJ_FLOAT_13_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_13_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_13_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_13 */
					#if defined(ISB_OBJ_FLOAT_14)
						case 14:
							eepAddrCtrl = ISB_OBJ_FLOAT_14_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_14_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_14_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_14 */
					#if defined(ISB_OBJ_FLOAT_15)
						case 15:
							eepAddrCtrl = ISB_OBJ_FLOAT_15_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_15_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_15_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_15 */
					#if defined(ISB_OBJ_FLOAT_16)
						case 16:
							eepAddrCtrl = ISB_OBJ_FLOAT_16_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_16_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_16_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_16 */
					#if defined(ISB_OBJ_FLOAT_17)
						case 17:
							eepAddrCtrl = ISB_OBJ_FLOAT_17_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_17_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_17_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_17 */
					#if defined(ISB_OBJ_FLOAT_18)
						case 18:
							eepAddrCtrl = ISB_OBJ_FLOAT_18_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_18_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_18_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_18 */
					#if defined(ISB_OBJ_FLOAT_19)
						case 19:
							eepAddrCtrl = ISB_OBJ_FLOAT_19_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_19_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_19_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_19 */
					#if defined(ISB_OBJ_FLOAT_20)
						case 20:
							eepAddrCtrl = ISB_OBJ_FLOAT_20_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_20_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_20_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_20 */
					#if defined(ISB_OBJ_FLOAT_21)
						case 21:
							eepAddrCtrl = ISB_OBJ_FLOAT_21_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_21_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_21_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_21 */
					#if defined(ISB_OBJ_FLOAT_22)
						case 22:
							eepAddrCtrl = ISB_OBJ_FLOAT_22_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_22_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_22_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_22 */
					#if defined(ISB_OBJ_FLOAT_23)
						case 23:
							eepAddrCtrl = ISB_OBJ_FLOAT_23_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_23_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_23_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_23 */
					#if defined(ISB_OBJ_FLOAT_24)
						case 24:
							eepAddrCtrl = ISB_OBJ_FLOAT_24_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_24_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_24_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_24 */
					#if defined(ISB_OBJ_FLOAT_25)
						case 25:
							eepAddrCtrl = ISB_OBJ_FLOAT_25_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_25_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_25_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_25 */
					#if defined(ISB_OBJ_FLOAT_26)
						case 26:
							eepAddrCtrl = ISB_OBJ_FLOAT_26_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_26_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_26_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_26 */
					#if defined(ISB_OBJ_FLOAT_27)
						case 27:
							eepAddrCtrl = ISB_OBJ_FLOAT_27_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_27_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_27_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_27 */
					#if defined(ISB_OBJ_FLOAT_28)
						case 28:
							eepAddrCtrl = ISB_OBJ_FLOAT_28_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_28_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_28_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_28 */
					#if defined(ISB_OBJ_FLOAT_29)
						case 29:
							eepAddrCtrl = ISB_OBJ_FLOAT_29_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_29_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_29_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_29 */
					#if defined(ISB_OBJ_FLOAT_30)
						case 30:
							eepAddrCtrl = ISB_OBJ_FLOAT_30_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_30_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_30_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_30 */
					#if defined(ISB_OBJ_FLOAT_31)
						case 31:
							eepAddrCtrl = ISB_OBJ_FLOAT_31_EEADDR_CTRL;
							eepAddrTov = ISB_OBJ_FLOAT_31_EEADDR_TOV;
							eepAddrValueInit = ISB_OBJ_FLOAT_31_EEADDR_VALUEINIT;
							break;
					#endif /* ISB_OBJ_FLOAT_31 */
				}
				if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_ENABLED)) {
					Isb_Obj_Float[ObjIndex].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddrCtrl);
					if (bit_is_set(Isb_Obj_Float[ObjIndex].Ctrl, ISB_OBJ_CTRL_ENABLED)) {
						Isb_Obj_Float[ObjIndex].Tov = lib_eep_fw_read_byte((uint8_t *)eepAddrTov);
						Isb_Obj_Float[ObjIndex].Value = lib_eep_fw_read_byte((uint8_t *)eepAddrValueInit);
						Isb_Obj_Float[ObjIndex].IsChanged = FALSE;
					}
				}
			}
		#endif /* ISB_OBJ_FLOAT_MAX */

	}



	void Isb_Obj_Exec(void) {

		#if defined(ISB_OBJ_1BIT_MAX)
			if (bit_is_set(Isb_Obj_1Bit_Ctrl, ISB_CTRL_SOFTIRQ_EXEC)) {
				for (uint8_t ObjIndex = 0; ObjIndex < ISB_OBJ_1BIT_MAX; ObjIndex++) {
					uint8_t Ch = pgm_read_byte(&pgmIsb_Obj_1Bit_Ch_Array[ObjIndex]);
					if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_ENABLED)) {
						if (bit_is_set(Isb_Obj_1Bit[ObjIndex].Ctrl, ISB_OBJ_CTRL_ENABLED)) {
							if (bit_is_set(Isb_Obj_1Bit[ObjIndex].Ctrl, ISB_OBJ_CTRL_SEND)) {
								if (Isb_Obj_1Bit[ObjIndex].IsChanged == TRUE) {
									for (uint8_t GrpIndex = 0; GrpIndex < ISB_GRP_MAX; GrpIndex++) {
										uint8_t Obj = pgm_read_byte(&pgmIsb_Obj_1Bit_Obj_Array[ObjIndex]);
										if ((Isb_Grp[GrpIndex].Obj == Obj) & (Isb_Grp[GrpIndex].Id != 0)) {
											Isb_Msg_t TxMsg;
											TxMsg.Flags = ISB_MSG_FLAGS_TOF_MULTICAST | ISB_MSG_FLAGS_DLC_4;
											TxMsg.DestId = Isb_Grp[GrpIndex].Id;
											TxMsg.SourceId = Isb_Node_Id;
											TxMsg.Data[0] = ISB_MSG_TOP_1BIT;
											TxMsg.Data[1] = ISB_MSG_CTRL_CMD_WRITE;
											TxMsg.Data[2] = Isb_Obj_1Bit[ObjIndex].Tov;
											TxMsg.Data[3] = Isb_Obj_1Bit[ObjIndex].Value;
											Isb_SendMsg(&TxMsg);
											break;
										}
									}
									Isb_Obj_1Bit[ObjIndex].IsChanged = FALSE;
								}
							}
							if (bit_is_set(Isb_Obj_1Bit[ObjIndex].Ctrl, ISB_OBJ_CTRL_READONINIT)) {
								// TODO;
								Isb_Obj_1Bit[ObjIndex].Ctrl &= ~(1 << ISB_OBJ_CTRL_READONINIT);
							}
						}
					}
				}
				Isb_Obj_1Bit_Ctrl &= ~(1 << ISB_CTRL_SOFTIRQ_EXEC);
			}
		#endif /* ISB_OBJ_1BIT_MAX */

		#if defined(ISB_OBJ_4BIT_MAX)
			if (bit_is_set(Isb_Obj_4Bit_Ctrl, ISB_CTRL_SOFTIRQ_EXEC)) {
				for (uint8_t ObjIndex = 0; ObjIndex < ISB_OBJ_4BIT_MAX; ObjIndex++) {
					uint8_t Ch = pgm_read_byte(&pgmIsb_Obj_4Bit_Ch_Array[ObjIndex]);
					if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_ENABLED)) {
						if (bit_is_set(Isb_Obj_4Bit[ObjIndex].Ctrl, ISB_OBJ_CTRL_ENABLED)) {
							if (bit_is_set(Isb_Obj_4Bit[ObjIndex].Ctrl, ISB_OBJ_CTRL_SEND)) {
								if (Isb_Obj_4Bit[ObjIndex].IsChanged == TRUE) {
									for (uint8_t GrpIndex = 0; GrpIndex < ISB_GRP_MAX; GrpIndex++) {
										uint8_t Obj = pgm_read_byte(&pgmIsb_Obj_4Bit_Obj_Array[ObjIndex]);
										if ((Isb_Grp[GrpIndex].Obj == Obj) & (Isb_Grp[GrpIndex].Id != 0)) {
											Isb_Msg_t TxMsg;
											TxMsg.Flags = ISB_MSG_FLAGS_TOF_MULTICAST | ISB_MSG_FLAGS_DLC_4;
											TxMsg.DestId = Isb_Grp[GrpIndex].Id;
											TxMsg.SourceId = Isb_Node_Id;
											TxMsg.Data[0] = ISB_MSG_TOP_4BIT;
											TxMsg.Data[1] = ISB_MSG_CTRL_CMD_WRITE;
											TxMsg.Data[2] = Isb_Obj_4Bit[ObjIndex].Tov;
											TxMsg.Data[3] = Isb_Obj_4Bit[ObjIndex].Value;
											Isb_SendMsg(&TxMsg);
											break;
										}
									}
									Isb_Obj_4Bit[ObjIndex].IsChanged = FALSE;
								}
							}
							if (bit_is_set(Isb_Obj_4Bit[ObjIndex].Ctrl, ISB_OBJ_CTRL_READONINIT)) {
								// TODO;
								Isb_Obj_4Bit[ObjIndex].Ctrl &= ~(1 << ISB_OBJ_CTRL_READONINIT);
							}
						}
					}
				}
				Isb_Obj_4Bit_Ctrl &= ~(1 << ISB_CTRL_SOFTIRQ_EXEC);
			}
		#endif /* ISB_OBJ_4BIT_MAX */

		#if defined(ISB_OBJ_8BIT_MAX)
			if (bit_is_set(Isb_Obj_8Bit_Ctrl, ISB_CTRL_SOFTIRQ_EXEC)) {
				for (uint8_t ObjIndex = 0; ObjIndex < ISB_OBJ_8BIT_MAX; ObjIndex++) {
					uint8_t Ch = pgm_read_byte(&pgmIsb_Obj_8Bit_Ch_Array[ObjIndex]);
					if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_ENABLED)) {
						if (bit_is_set(Isb_Obj_8Bit[ObjIndex].Ctrl, ISB_OBJ_CTRL_ENABLED)) {
							if (bit_is_set(Isb_Obj_8Bit[ObjIndex].Ctrl, ISB_OBJ_CTRL_SEND)) {
								if (Isb_Obj_8Bit[ObjIndex].IsChanged == TRUE) {
									for (uint8_t GrpIndex = 0; GrpIndex < ISB_GRP_MAX; GrpIndex++) {
										uint8_t Obj = pgm_read_byte(&pgmIsb_Obj_8Bit_Obj_Array[ObjIndex]);
										if ((Isb_Grp[GrpIndex].Obj == Obj) & (Isb_Grp[GrpIndex].Id != 0)) {
											Isb_Msg_t TxMsg;
											TxMsg.Flags = ISB_MSG_FLAGS_TOF_MULTICAST | ISB_MSG_FLAGS_DLC_4;
											TxMsg.DestId = Isb_Grp[GrpIndex].Id;
											TxMsg.SourceId = Isb_Node_Id;
											TxMsg.Data[0] = ISB_MSG_TOP_8BIT;
											TxMsg.Data[1] = ISB_MSG_CTRL_CMD_WRITE;
											TxMsg.Data[2] = Isb_Obj_8Bit[ObjIndex].Tov;
											TxMsg.Data[3] = Isb_Obj_8Bit[ObjIndex].Value;
											Isb_SendMsg(&TxMsg);
											break;
										}
									}
									Isb_Obj_8Bit[ObjIndex].IsChanged = FALSE;
								}
							}
							if (bit_is_set(Isb_Obj_8Bit[ObjIndex].Ctrl, ISB_OBJ_CTRL_READONINIT)) {
								// TODO;
								Isb_Obj_8Bit[ObjIndex].Ctrl &= ~(1 << ISB_OBJ_CTRL_READONINIT);
							}
						}
					}
				}
				Isb_Obj_8Bit_Ctrl &= ~(1 << ISB_CTRL_SOFTIRQ_EXEC);
			}
		#endif /* ISB_OBJ_8BIT_MAX */

		#if defined(ISB_OBJ_FLOAT_MAX)
			if (bit_is_set(Isb_Obj_Float_Ctrl, ISB_CTRL_SOFTIRQ_EXEC)) {
				for (uint8_t ObjIndex = 0; ObjIndex < ISB_OBJ_FLOAT_MAX; ObjIndex++) {
					uint8_t Ch = pgm_read_byte(&pgmIsb_Obj_Float_Ch_Array[ObjIndex]);
					if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_ENABLED)) {
						if (bit_is_set(Isb_Obj_Float[ObjIndex].Ctrl, ISB_OBJ_CTRL_ENABLED)) {
							if (bit_is_set(Isb_Obj_Float[ObjIndex].Ctrl, ISB_OBJ_CTRL_SEND)) {
								if (Isb_Obj_Float[ObjIndex].IsChanged == TRUE) {
									for (uint8_t GrpIndex = 0; GrpIndex < ISB_GRP_MAX; GrpIndex++) {
										uint8_t Obj = pgm_read_byte(&pgmIsb_Obj_Float_Obj_Array[ObjIndex]);
										if ((Isb_Grp[GrpIndex].Obj == Obj) & (Isb_Grp[GrpIndex].Id != 0)) {
											Isb_Msg_t TxMsg;
											TxMsg.Flags = ISB_MSG_FLAGS_TOF_MULTICAST | ISB_MSG_FLAGS_DLC_5;
											TxMsg.DestId = Isb_Grp[GrpIndex].Id;
											TxMsg.SourceId = Isb_Node_Id;
											TxMsg.Data[0] = ISB_MSG_TOP_FLOAT;
											TxMsg.Data[1] = ISB_MSG_CTRL_CMD_WRITE;
											TxMsg.Data[2] = Isb_Obj_Float[ObjIndex].Tov;
											TxMsg.Data[3] = (uint8_t)Isb_Obj_Float[ObjIndex].Value;
											TxMsg.Data[4] = (uint8_t)(Isb_Obj_Float[ObjIndex].Value >> 8);
											Isb_SendMsg(&TxMsg);
											break;
										}
									}
									Isb_Obj_Float[ObjIndex].IsChanged = FALSE;
								}
							}
							if (bit_is_set(Isb_Obj_Float[ObjIndex].Ctrl, ISB_OBJ_CTRL_READONINIT)) {
								// TODO;
								Isb_Obj_Float[ObjIndex].Ctrl &= ~(1 << ISB_OBJ_CTRL_READONINIT);
							}
						}
					}
				}
				Isb_Obj_Float_Ctrl &= ~(1 << ISB_CTRL_SOFTIRQ_EXEC);
			}
		#endif /* ISB_OBJ_FLOAT_MAX */

	}



	void Isb_Obj_Rx(const Isb_Msg_t * aIsb_Msg) {
		for (uint8_t GrpIndex = 0; GrpIndex < ISB_GRP_MAX; GrpIndex++) {
			if ((aIsb_Msg->DestId == Isb_Grp[GrpIndex].Id) & (aIsb_Msg->DestId != 0)) {

				#if defined(ISB_OBJ_1BIT_MAX)
					for (uint8_t ObjIndex = 0; ObjIndex < ISB_OBJ_1BIT_MAX; ObjIndex++) {
//						uint8_t Ch = pgm_read_byte(&pgmIsb_Obj_1Bit_Ch_Array[ObjIndex]);
						uint8_t Obj = pgm_read_byte(&pgmIsb_Obj_1Bit_Obj_Array[ObjIndex]);
						if (bit_is_set(Isb_Obj_1Bit[ObjIndex].Ctrl, ISB_OBJ_CTRL_ENABLED)) {
							if (Obj == Isb_Grp[GrpIndex].Obj) {
								if ((aIsb_Msg->Flags & ISB_MSG_FLAGS_DLC_MASK) == ISB_MSG_FLAGS_DLC_4) {
									if (aIsb_Msg->Data[0] == ISB_MSG_TOP_1BIT) {
										if ((aIsb_Msg->Data[1] & ISB_MSG_CTRL_CMD_MASK) == ISB_MSG_CTRL_CMD_READ) {
											if (bit_is_set(Isb_Obj_1Bit[ObjIndex].Ctrl, ISB_OBJ_CTRL_READ)) {
												Isb_Msg_t TxMsg;
												TxMsg.Flags = ISB_MSG_FLAGS_TOF_MULTICAST | ISB_MSG_FLAGS_DLC_4;
												TxMsg.DestId = aIsb_Msg->DestId;
												TxMsg.SourceId = Isb_Node_Id;
												TxMsg.Data[0] = ISB_MSG_TOP_1BIT;
												TxMsg.Data[1] = ISB_MSG_CTRL_CMD_ANSWER;
												TxMsg.Data[2] = Isb_Obj_1Bit[ObjIndex].Tov;
												TxMsg.Data[3] = Isb_Obj_1Bit[ObjIndex].Value;
												Isb_SendMsg(&TxMsg);
											}
										}
										if ((aIsb_Msg->Data[1] & ISB_MSG_CTRL_CMD_MASK) == ISB_MSG_CTRL_CMD_ANSWER) {
											if (bit_is_set(Isb_Obj_1Bit[ObjIndex].Ctrl, ISB_OBJ_CTRL_UPDATE)) {
												if (aIsb_Msg->Data[2] == Isb_Obj_1Bit[ObjIndex].Tov) {
													Isb_Obj_1Bit[ObjIndex].Value = aIsb_Msg->Data[3];
												}
											}
										}
										if ((aIsb_Msg->Data[1] & ISB_MSG_CTRL_CMD_MASK) == ISB_MSG_CTRL_CMD_WRITE) {
											if (bit_is_set(Isb_Obj_1Bit[ObjIndex].Ctrl, ISB_OBJ_CTRL_WRITE)) {
												if (aIsb_Msg->Data[2] == Isb_Obj_1Bit[ObjIndex].Tov) {
													if (Isb_Obj_1Bit[ObjIndex].Value != aIsb_Msg->Data[3]) {
														Isb_Obj_1Bit[ObjIndex].Value = aIsb_Msg->Data[3];
														Isb_Obj_1Bit[ObjIndex].IsChanged = TRUE;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				#endif /* ISB_OBJ_1BIT_MAX */

				#if defined(ISB_OBJ_4BIT_MAX)
					for (uint8_t ObjIndex = 0; ObjIndex < ISB_OBJ_4BIT_MAX; ObjIndex++) {
//						uint8_t Ch = pgm_read_byte(&pgmIsb_Obj_4Bit_Ch_Array[ObjIndex]);
						uint8_t Obj = pgm_read_byte(&pgmIsb_Obj_4Bit_Obj_Array[ObjIndex]);
						if (bit_is_set(Isb_Obj_4Bit[ObjIndex].Ctrl, ISB_OBJ_CTRL_ENABLED)) {
							if (Obj == Isb_Grp[GrpIndex].Obj) {
								if ((aIsb_Msg->Flags & ISB_MSG_FLAGS_DLC_MASK) == ISB_MSG_FLAGS_DLC_4) {
									if (aIsb_Msg->Data[0] == ISB_MSG_TOP_4BIT) {
										if ((aIsb_Msg->Data[1] & ISB_MSG_CTRL_CMD_MASK) == ISB_MSG_CTRL_CMD_READ) {
											if (bit_is_set(Isb_Obj_4Bit[ObjIndex].Ctrl, ISB_OBJ_CTRL_READ)) {
												Isb_Msg_t TxMsg;
												TxMsg.Flags = ISB_MSG_FLAGS_TOF_MULTICAST | ISB_MSG_FLAGS_DLC_4;
												TxMsg.DestId = aIsb_Msg->DestId;
												TxMsg.SourceId = Isb_Node_Id;
												TxMsg.Data[0] = ISB_MSG_TOP_4BIT;
												TxMsg.Data[1] = ISB_MSG_CTRL_CMD_ANSWER;
												TxMsg.Data[2] = Isb_Obj_4Bit[ObjIndex].Tov;
												TxMsg.Data[3] = Isb_Obj_4Bit[ObjIndex].Value;
												Isb_SendMsg(&TxMsg);
											}
										}
										if ((aIsb_Msg->Data[1] & ISB_MSG_CTRL_CMD_MASK) == ISB_MSG_CTRL_CMD_ANSWER) {
											if (bit_is_set(Isb_Obj_4Bit[ObjIndex].Ctrl, ISB_OBJ_CTRL_UPDATE)) {
												if (aIsb_Msg->Data[2] == Isb_Obj_4Bit[ObjIndex].Tov) {
													Isb_Obj_4Bit[ObjIndex].Value = aIsb_Msg->Data[3];
												}
											}
										}
										if ((aIsb_Msg->Data[1] & ISB_MSG_CTRL_CMD_MASK) == ISB_MSG_CTRL_CMD_WRITE) {
											if (bit_is_set(Isb_Obj_4Bit[ObjIndex].Ctrl, ISB_OBJ_CTRL_WRITE)) {
												if (aIsb_Msg->Data[2] == Isb_Obj_4Bit[ObjIndex].Tov) {
													if (Isb_Obj_4Bit[ObjIndex].Value != aIsb_Msg->Data[3]) {
														Isb_Obj_4Bit[ObjIndex].Value = aIsb_Msg->Data[3];
														Isb_Obj_4Bit[ObjIndex].IsChanged = TRUE;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				#endif /* ISB_OBJ_4BIT_MAX */

				#if defined(ISB_OBJ_8BIT_MAX)
					for (uint8_t ObjIndex = 0; ObjIndex < ISB_OBJ_8BIT_MAX; ObjIndex++) {
//						uint8_t Ch = pgm_read_byte(&pgmIsb_Obj_8Bit_Ch_Array[ObjIndex]);
						uint8_t Obj = pgm_read_byte(&pgmIsb_Obj_8Bit_Obj_Array[ObjIndex]);
						if (bit_is_set(Isb_Obj_8Bit[ObjIndex].Ctrl, ISB_OBJ_CTRL_ENABLED)) {
							if (Obj == Isb_Grp[GrpIndex].Obj) {
								if ((aIsb_Msg->Flags & ISB_MSG_FLAGS_DLC_MASK) == ISB_MSG_FLAGS_DLC_4) {
									if (aIsb_Msg->Data[0] == ISB_MSG_TOP_8BIT) {
										if ((aIsb_Msg->Data[1] & ISB_MSG_CTRL_CMD_MASK) == ISB_MSG_CTRL_CMD_READ) {
											if (bit_is_set(Isb_Obj_8Bit[ObjIndex].Ctrl, ISB_OBJ_CTRL_READ)) {
												Isb_Msg_t TxMsg;
												TxMsg.Flags = ISB_MSG_FLAGS_TOF_MULTICAST | ISB_MSG_FLAGS_DLC_4;
												TxMsg.DestId = aIsb_Msg->DestId;
												TxMsg.SourceId = Isb_Node_Id;
												TxMsg.Data[0] = ISB_MSG_TOP_8BIT;
												TxMsg.Data[1] = ISB_MSG_CTRL_CMD_ANSWER;
												TxMsg.Data[2] = Isb_Obj_8Bit[ObjIndex].Tov;
												TxMsg.Data[3] = Isb_Obj_8Bit[ObjIndex].Value;
												Isb_SendMsg(&TxMsg);
											}
										}
										if ((aIsb_Msg->Data[1] & ISB_MSG_CTRL_CMD_MASK) == ISB_MSG_CTRL_CMD_ANSWER) {
											if (bit_is_set(Isb_Obj_8Bit[ObjIndex].Ctrl, ISB_OBJ_CTRL_UPDATE)) {
												if (aIsb_Msg->Data[2] == Isb_Obj_8Bit[ObjIndex].Tov) {
													Isb_Obj_8Bit[ObjIndex].Value = aIsb_Msg->Data[3];
												}
											}
										}
										if ((aIsb_Msg->Data[1] & ISB_MSG_CTRL_CMD_MASK) == ISB_MSG_CTRL_CMD_WRITE) {
											if (bit_is_set(Isb_Obj_8Bit[ObjIndex].Ctrl, ISB_OBJ_CTRL_WRITE)) {
												if (aIsb_Msg->Data[2] == Isb_Obj_8Bit[ObjIndex].Tov) {
													if (Isb_Obj_8Bit[ObjIndex].Value != aIsb_Msg->Data[3]) {
														Isb_Obj_8Bit[ObjIndex].Value = aIsb_Msg->Data[3];
														Isb_Obj_8Bit[ObjIndex].IsChanged = TRUE;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				#endif /* ISB_OBJ_8BIT_MAX */

				#if defined(ISB_OBJ_FLOAT_MAX)
					for (uint8_t ObjIndex = 0; ObjIndex < ISB_OBJ_FLOAT_MAX; ObjIndex++) {
//						uint8_t Ch = pgm_read_byte(&pgmIsb_Obj_1Bit_Ch_Array[ObjIndex]);
						uint8_t Obj = pgm_read_byte(&pgmIsb_Obj_1Bit_Obj_Array[ObjIndex]);
						if (bit_is_set(Isb_Obj_Float[ObjIndex].Ctrl, ISB_OBJ_CTRL_ENABLED)) {
							if (Obj == Isb_Grp[GrpIndex].Obj) {
								if ((aIsb_Msg->Flags & ISB_MSG_FLAGS_DLC_MASK) == ISB_MSG_FLAGS_DLC_4) {
									if (aIsb_Msg->Data[0] == ISB_MSG_TOP_FLOAT) {
										if ((aIsb_Msg->Data[1] & ISB_MSG_CTRL_CMD_MASK) == ISB_MSG_CTRL_CMD_READ) {
											if (bit_is_set(Isb_Obj_Float[ObjIndex].Ctrl, ISB_OBJ_CTRL_READ)) {
												Isb_Msg_t TxMsg;
												TxMsg.Flags = ISB_MSG_FLAGS_TOF_MULTICAST | ISB_MSG_FLAGS_DLC_5;
												TxMsg.DestId = aIsb_Msg->DestId;
												TxMsg.SourceId = Isb_Node_Id;
												TxMsg.Data[0] = ISB_MSG_TOP_FLOAT;
												TxMsg.Data[1] = ISB_MSG_CTRL_CMD_ANSWER;
												TxMsg.Data[2] = Isb_Obj_Float[ObjIndex].Tov;
												TxMsg.Data[3] = (uint8_t)Isb_Obj_Float[ObjIndex].Value;
												TxMsg.Data[4] = (uint8_t)(Isb_Obj_Float[ObjIndex].Value >> 8);
												Isb_SendMsg(&TxMsg);
											}
										}
										if ((aIsb_Msg->Data[1] & ISB_MSG_CTRL_CMD_MASK) == ISB_MSG_CTRL_CMD_ANSWER) {
											if (bit_is_set(Isb_Obj_Float[ObjIndex].Ctrl, ISB_OBJ_CTRL_UPDATE)) {
												if (aIsb_Msg->Data[2] == Isb_Obj_Float[ObjIndex].Tov) {
													Isb_Obj_Float[ObjIndex].Value = aIsb_Msg->Data[3];
													Isb_Obj_Float[ObjIndex].Value |= aIsb_Msg->Data[4] << 8;
												}
											}
										}
										if ((aIsb_Msg->Data[1] & ISB_MSG_CTRL_CMD_MASK) == ISB_MSG_CTRL_CMD_WRITE) {
											if (bit_is_set(Isb_Obj_Float[ObjIndex].Ctrl, ISB_OBJ_CTRL_WRITE)) {
												if (aIsb_Msg->Data[2] == Isb_Obj_Float[ObjIndex].Tov) {
													if (Isb_Obj_Float[ObjIndex].Value != ((uint16_t)aIsb_Msg->Data[3] + (uint16_t)aIsb_Msg->Data[4] >> 8) {
														Isb_Obj_Float[ObjIndex].Value = aIsb_Msg->Data[3];
														Isb_Obj_Float[ObjIndex].Value |= aIsb_Msg->Data[4] << 8;
														Isb_Obj_Float[ObjIndex].IsChanged = TRUE;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				#endif /* ISB_OBJ_FLOAT_MAX */

			}
		}
	}



#endif /* ISB_OBJ_C_ */
