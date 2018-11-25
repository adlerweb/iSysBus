/**
 * @file		avrlib/trunk/lib/isb_obj.h
 *
 * @brief		iSysBus Object.
 *
 * This file includes the iSysBus Object.
 *
 * @author		© Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
 *
 * @date		$Date: 2012-05-08 11:50:50 +0200 (Di, 08. Mai 2012) $
 *
 * @version		$Rev: 7805 $
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





#ifndef ISB_OBJ_H_
	#define ISB_OBJ_H_



	#if defined(ISB_OBJ_MAX)

		#if ISB_OBJ_MAX == 1
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH };
		#elif ISB_OBJ_MAX == 2
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH };
		#elif ISB_OBJ_MAX == 3
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH };
		#elif ISB_OBJ_MAX == 4
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH };
		#elif ISB_OBJ_MAX == 5
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH };
		#elif ISB_OBJ_MAX == 6
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH };
		#elif ISB_OBJ_MAX == 7
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH };
		#elif ISB_OBJ_MAX == 8
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH };
		#elif ISB_OBJ_MAX == 9
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH };
		#elif ISB_OBJ_MAX == 10
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH };
		#elif ISB_OBJ_MAX == 11
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH };
		#elif ISB_OBJ_MAX == 12
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH };
		#elif ISB_OBJ_MAX == 13
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH };
		#elif ISB_OBJ_MAX == 14
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH };
		#elif ISB_OBJ_MAX == 15
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH };
		#elif ISB_OBJ_MAX == 16
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH };
		#elif ISB_OBJ_MAX == 17
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH };
		#elif ISB_OBJ_MAX == 18
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH };
		#elif ISB_OBJ_MAX == 19
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH };
		#elif ISB_OBJ_MAX == 20
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH };
		#elif ISB_OBJ_MAX == 21
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH };
		#elif ISB_OBJ_MAX == 22
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH };
		#elif ISB_OBJ_MAX == 23
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH };
		#elif ISB_OBJ_MAX == 24
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH };
		#elif ISB_OBJ_MAX == 25
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH };
		#elif ISB_OBJ_MAX == 26
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH, ISB_OBJ_25_CH };
		#elif ISB_OBJ_MAX == 27
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH, ISB_OBJ_25_CH, ISB_OBJ_26_CH };
		#elif ISB_OBJ_MAX == 28
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH, ISB_OBJ_25_CH, ISB_OBJ_26_CH, ISB_OBJ_27_CH };
		#elif ISB_OBJ_MAX == 29
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH, ISB_OBJ_25_CH, ISB_OBJ_26_CH, ISB_OBJ_27_CH, ISB_OBJ_28_CH };
		#elif ISB_OBJ_MAX == 30
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH, ISB_OBJ_25_CH, ISB_OBJ_26_CH, ISB_OBJ_27_CH, ISB_OBJ_28_CH, ISB_OBJ_29_CH };
		#elif ISB_OBJ_MAX == 31
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH, ISB_OBJ_25_CH, ISB_OBJ_26_CH, ISB_OBJ_27_CH, ISB_OBJ_28_CH, ISB_OBJ_29_CH, ISB_OBJ_30_CH };
		#elif ISB_OBJ_MAX == 32
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH, ISB_OBJ_25_CH, ISB_OBJ_26_CH, ISB_OBJ_27_CH, ISB_OBJ_28_CH, ISB_OBJ_29_CH, ISB_OBJ_30_CH, ISB_OBJ_31_CH };
		#elif ISB_OBJ_MAX == 33
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH, ISB_OBJ_25_CH, ISB_OBJ_26_CH, ISB_OBJ_27_CH, ISB_OBJ_28_CH, ISB_OBJ_29_CH, ISB_OBJ_30_CH, ISB_OBJ_31_CH, ISB_OBJ_32_CH };
		#elif ISB_OBJ_MAX == 34
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH, ISB_OBJ_25_CH, ISB_OBJ_26_CH, ISB_OBJ_27_CH, ISB_OBJ_28_CH, ISB_OBJ_29_CH, ISB_OBJ_30_CH, ISB_OBJ_31_CH, ISB_OBJ_32_CH, ISB_OBJ_33_CH };
		#elif ISB_OBJ_MAX == 35
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH, ISB_OBJ_25_CH, ISB_OBJ_26_CH, ISB_OBJ_27_CH, ISB_OBJ_28_CH, ISB_OBJ_29_CH, ISB_OBJ_30_CH, ISB_OBJ_31_CH, ISB_OBJ_32_CH, ISB_OBJ_33_CH, ISB_OBJ_34_CH };
		#elif ISB_OBJ_MAX == 36
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH, ISB_OBJ_25_CH, ISB_OBJ_26_CH, ISB_OBJ_27_CH, ISB_OBJ_28_CH, ISB_OBJ_29_CH, ISB_OBJ_30_CH, ISB_OBJ_31_CH, ISB_OBJ_32_CH, ISB_OBJ_33_CH, ISB_OBJ_34_CH, ISB_OBJ_35_CH };
		#elif ISB_OBJ_MAX == 37
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH, ISB_OBJ_25_CH, ISB_OBJ_26_CH, ISB_OBJ_27_CH, ISB_OBJ_28_CH, ISB_OBJ_29_CH, ISB_OBJ_30_CH, ISB_OBJ_31_CH, ISB_OBJ_32_CH, ISB_OBJ_33_CH, ISB_OBJ_34_CH, ISB_OBJ_35_CH, ISB_OBJ_36_CH };
		#elif ISB_OBJ_MAX == 38
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH, ISB_OBJ_25_CH, ISB_OBJ_26_CH, ISB_OBJ_27_CH, ISB_OBJ_28_CH, ISB_OBJ_29_CH, ISB_OBJ_30_CH, ISB_OBJ_31_CH, ISB_OBJ_32_CH, ISB_OBJ_33_CH, ISB_OBJ_34_CH, ISB_OBJ_35_CH, ISB_OBJ_36_CH, ISB_OBJ_37_CH };
		#elif ISB_OBJ_MAX == 39
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH, ISB_OBJ_25_CH, ISB_OBJ_26_CH, ISB_OBJ_27_CH, ISB_OBJ_28_CH, ISB_OBJ_29_CH, ISB_OBJ_30_CH, ISB_OBJ_31_CH, ISB_OBJ_32_CH, ISB_OBJ_33_CH, ISB_OBJ_34_CH, ISB_OBJ_35_CH, ISB_OBJ_36_CH, ISB_OBJ_37_CH, ISB_OBJ_38_CH };
		#elif ISB_OBJ_MAX == 40
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH, ISB_OBJ_25_CH, ISB_OBJ_26_CH, ISB_OBJ_27_CH, ISB_OBJ_28_CH, ISB_OBJ_29_CH, ISB_OBJ_30_CH, ISB_OBJ_31_CH, ISB_OBJ_32_CH, ISB_OBJ_33_CH, ISB_OBJ_34_CH, ISB_OBJ_35_CH, ISB_OBJ_36_CH, ISB_OBJ_37_CH, ISB_OBJ_38_CH, ISB_OBJ_39_CH };
		#elif ISB_OBJ_MAX == 41
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH, ISB_OBJ_25_CH, ISB_OBJ_26_CH, ISB_OBJ_27_CH, ISB_OBJ_28_CH, ISB_OBJ_29_CH, ISB_OBJ_30_CH, ISB_OBJ_31_CH, ISB_OBJ_32_CH, ISB_OBJ_33_CH, ISB_OBJ_34_CH, ISB_OBJ_35_CH, ISB_OBJ_36_CH, ISB_OBJ_37_CH, ISB_OBJ_38_CH, ISB_OBJ_39_CH, ISB_OBJ_40_CH };
		#elif ISB_OBJ_MAX == 42
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH, ISB_OBJ_25_CH, ISB_OBJ_26_CH, ISB_OBJ_27_CH, ISB_OBJ_28_CH, ISB_OBJ_29_CH, ISB_OBJ_30_CH, ISB_OBJ_31_CH, ISB_OBJ_32_CH, ISB_OBJ_33_CH, ISB_OBJ_34_CH, ISB_OBJ_35_CH, ISB_OBJ_36_CH, ISB_OBJ_37_CH, ISB_OBJ_38_CH, ISB_OBJ_39_CH, ISB_OBJ_40_CH, ISB_OBJ_41_CH };
		#elif ISB_OBJ_MAX == 43
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH, ISB_OBJ_25_CH, ISB_OBJ_26_CH, ISB_OBJ_27_CH, ISB_OBJ_28_CH, ISB_OBJ_29_CH, ISB_OBJ_30_CH, ISB_OBJ_31_CH, ISB_OBJ_32_CH, ISB_OBJ_33_CH, ISB_OBJ_34_CH, ISB_OBJ_35_CH, ISB_OBJ_36_CH, ISB_OBJ_37_CH, ISB_OBJ_38_CH, ISB_OBJ_39_CH, ISB_OBJ_40_CH, ISB_OBJ_41_CH, ISB_OBJ_42_CH };
		#elif ISB_OBJ_MAX == 44
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH, ISB_OBJ_25_CH, ISB_OBJ_26_CH, ISB_OBJ_27_CH, ISB_OBJ_28_CH, ISB_OBJ_29_CH, ISB_OBJ_30_CH, ISB_OBJ_31_CH, ISB_OBJ_32_CH, ISB_OBJ_33_CH, ISB_OBJ_34_CH, ISB_OBJ_35_CH, ISB_OBJ_36_CH, ISB_OBJ_37_CH, ISB_OBJ_38_CH, ISB_OBJ_39_CH, ISB_OBJ_40_CH, ISB_OBJ_41_CH, ISB_OBJ_42_CH, ISB_OBJ_43_CH };
		#elif ISB_OBJ_MAX == 45
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH, ISB_OBJ_25_CH, ISB_OBJ_26_CH, ISB_OBJ_27_CH, ISB_OBJ_28_CH, ISB_OBJ_29_CH, ISB_OBJ_30_CH, ISB_OBJ_31_CH, ISB_OBJ_32_CH, ISB_OBJ_33_CH, ISB_OBJ_34_CH, ISB_OBJ_35_CH, ISB_OBJ_36_CH, ISB_OBJ_37_CH, ISB_OBJ_38_CH, ISB_OBJ_39_CH, ISB_OBJ_40_CH, ISB_OBJ_41_CH, ISB_OBJ_42_CH, ISB_OBJ_43_CH, ISB_OBJ_44_CH };
		#elif ISB_OBJ_MAX == 46
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH, ISB_OBJ_25_CH, ISB_OBJ_26_CH, ISB_OBJ_27_CH, ISB_OBJ_28_CH, ISB_OBJ_29_CH, ISB_OBJ_30_CH, ISB_OBJ_31_CH, ISB_OBJ_32_CH, ISB_OBJ_33_CH, ISB_OBJ_34_CH, ISB_OBJ_35_CH, ISB_OBJ_36_CH, ISB_OBJ_37_CH, ISB_OBJ_38_CH, ISB_OBJ_39_CH, ISB_OBJ_40_CH, ISB_OBJ_41_CH, ISB_OBJ_42_CH, ISB_OBJ_43_CH, ISB_OBJ_44_CH, ISB_OBJ_45_CH };
		#elif ISB_OBJ_MAX == 47
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH, ISB_OBJ_25_CH, ISB_OBJ_26_CH, ISB_OBJ_27_CH, ISB_OBJ_28_CH, ISB_OBJ_29_CH, ISB_OBJ_30_CH, ISB_OBJ_31_CH, ISB_OBJ_32_CH, ISB_OBJ_33_CH, ISB_OBJ_34_CH, ISB_OBJ_35_CH, ISB_OBJ_36_CH, ISB_OBJ_37_CH, ISB_OBJ_38_CH, ISB_OBJ_39_CH, ISB_OBJ_40_CH, ISB_OBJ_41_CH, ISB_OBJ_42_CH, ISB_OBJ_43_CH, ISB_OBJ_44_CH, ISB_OBJ_45_CH, ISB_OBJ_46_CH };
		#elif ISB_OBJ_MAX == 48
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH, ISB_OBJ_25_CH, ISB_OBJ_26_CH, ISB_OBJ_27_CH, ISB_OBJ_28_CH, ISB_OBJ_29_CH, ISB_OBJ_30_CH, ISB_OBJ_31_CH, ISB_OBJ_32_CH, ISB_OBJ_33_CH, ISB_OBJ_34_CH, ISB_OBJ_35_CH, ISB_OBJ_36_CH, ISB_OBJ_37_CH, ISB_OBJ_38_CH, ISB_OBJ_39_CH, ISB_OBJ_40_CH, ISB_OBJ_41_CH, ISB_OBJ_42_CH, ISB_OBJ_43_CH, ISB_OBJ_44_CH, ISB_OBJ_45_CH, ISB_OBJ_46_CH, ISB_OBJ_47_CH };
		#elif ISB_OBJ_MAX == 49
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH, ISB_OBJ_25_CH, ISB_OBJ_26_CH, ISB_OBJ_27_CH, ISB_OBJ_28_CH, ISB_OBJ_29_CH, ISB_OBJ_30_CH, ISB_OBJ_31_CH, ISB_OBJ_32_CH, ISB_OBJ_33_CH, ISB_OBJ_34_CH, ISB_OBJ_35_CH, ISB_OBJ_36_CH, ISB_OBJ_37_CH, ISB_OBJ_38_CH, ISB_OBJ_39_CH, ISB_OBJ_40_CH, ISB_OBJ_41_CH, ISB_OBJ_42_CH, ISB_OBJ_43_CH, ISB_OBJ_44_CH, ISB_OBJ_45_CH, ISB_OBJ_46_CH, ISB_OBJ_47_CH, ISB_OBJ_48_CH };
		#elif ISB_OBJ_MAX == 50
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH, ISB_OBJ_25_CH, ISB_OBJ_26_CH, ISB_OBJ_27_CH, ISB_OBJ_28_CH, ISB_OBJ_29_CH, ISB_OBJ_30_CH, ISB_OBJ_31_CH, ISB_OBJ_32_CH, ISB_OBJ_33_CH, ISB_OBJ_34_CH, ISB_OBJ_35_CH, ISB_OBJ_36_CH, ISB_OBJ_37_CH, ISB_OBJ_38_CH, ISB_OBJ_39_CH, ISB_OBJ_40_CH, ISB_OBJ_41_CH, ISB_OBJ_42_CH, ISB_OBJ_43_CH, ISB_OBJ_44_CH, ISB_OBJ_45_CH, ISB_OBJ_46_CH, ISB_OBJ_47_CH, ISB_OBJ_48_CH, ISB_OBJ_49_CH };
		#elif ISB_OBJ_MAX == 51
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH, ISB_OBJ_25_CH, ISB_OBJ_26_CH, ISB_OBJ_27_CH, ISB_OBJ_28_CH, ISB_OBJ_29_CH, ISB_OBJ_30_CH, ISB_OBJ_31_CH, ISB_OBJ_32_CH, ISB_OBJ_33_CH, ISB_OBJ_34_CH, ISB_OBJ_35_CH, ISB_OBJ_36_CH, ISB_OBJ_37_CH, ISB_OBJ_38_CH, ISB_OBJ_39_CH, ISB_OBJ_40_CH, ISB_OBJ_41_CH, ISB_OBJ_42_CH, ISB_OBJ_43_CH, ISB_OBJ_44_CH, ISB_OBJ_45_CH, ISB_OBJ_46_CH, ISB_OBJ_47_CH, ISB_OBJ_48_CH, ISB_OBJ_49_CH, ISB_OBJ_50_CH };
		#elif ISB_OBJ_MAX == 52
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH, ISB_OBJ_25_CH, ISB_OBJ_26_CH, ISB_OBJ_27_CH, ISB_OBJ_28_CH, ISB_OBJ_29_CH, ISB_OBJ_30_CH, ISB_OBJ_31_CH, ISB_OBJ_32_CH, ISB_OBJ_33_CH, ISB_OBJ_34_CH, ISB_OBJ_35_CH, ISB_OBJ_36_CH, ISB_OBJ_37_CH, ISB_OBJ_38_CH, ISB_OBJ_39_CH, ISB_OBJ_40_CH, ISB_OBJ_41_CH, ISB_OBJ_42_CH, ISB_OBJ_43_CH, ISB_OBJ_44_CH, ISB_OBJ_45_CH, ISB_OBJ_46_CH, ISB_OBJ_47_CH, ISB_OBJ_48_CH, ISB_OBJ_49_CH, ISB_OBJ_50_CH, ISB_OBJ_51_CH };
		#elif ISB_OBJ_MAX == 53
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH, ISB_OBJ_25_CH, ISB_OBJ_26_CH, ISB_OBJ_27_CH, ISB_OBJ_28_CH, ISB_OBJ_29_CH, ISB_OBJ_30_CH, ISB_OBJ_31_CH, ISB_OBJ_32_CH, ISB_OBJ_33_CH, ISB_OBJ_34_CH, ISB_OBJ_35_CH, ISB_OBJ_36_CH, ISB_OBJ_37_CH, ISB_OBJ_38_CH, ISB_OBJ_39_CH, ISB_OBJ_40_CH, ISB_OBJ_41_CH, ISB_OBJ_42_CH, ISB_OBJ_43_CH, ISB_OBJ_44_CH, ISB_OBJ_45_CH, ISB_OBJ_46_CH, ISB_OBJ_47_CH, ISB_OBJ_48_CH, ISB_OBJ_49_CH, ISB_OBJ_50_CH, ISB_OBJ_51_CH, ISB_OBJ_52_CH };
		#elif ISB_OBJ_MAX == 54
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH, ISB_OBJ_25_CH, ISB_OBJ_26_CH, ISB_OBJ_27_CH, ISB_OBJ_28_CH, ISB_OBJ_29_CH, ISB_OBJ_30_CH, ISB_OBJ_31_CH, ISB_OBJ_32_CH, ISB_OBJ_33_CH, ISB_OBJ_34_CH, ISB_OBJ_35_CH, ISB_OBJ_36_CH, ISB_OBJ_37_CH, ISB_OBJ_38_CH, ISB_OBJ_39_CH, ISB_OBJ_40_CH, ISB_OBJ_41_CH, ISB_OBJ_42_CH, ISB_OBJ_43_CH, ISB_OBJ_44_CH, ISB_OBJ_45_CH, ISB_OBJ_46_CH, ISB_OBJ_47_CH, ISB_OBJ_48_CH, ISB_OBJ_49_CH, ISB_OBJ_50_CH, ISB_OBJ_51_CH, ISB_OBJ_52_CH, ISB_OBJ_53_CH };
		#elif ISB_OBJ_MAX == 55
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH, ISB_OBJ_25_CH, ISB_OBJ_26_CH, ISB_OBJ_27_CH, ISB_OBJ_28_CH, ISB_OBJ_29_CH, ISB_OBJ_30_CH, ISB_OBJ_31_CH, ISB_OBJ_32_CH, ISB_OBJ_33_CH, ISB_OBJ_34_CH, ISB_OBJ_35_CH, ISB_OBJ_36_CH, ISB_OBJ_37_CH, ISB_OBJ_38_CH, ISB_OBJ_39_CH, ISB_OBJ_40_CH, ISB_OBJ_41_CH, ISB_OBJ_42_CH, ISB_OBJ_43_CH, ISB_OBJ_44_CH, ISB_OBJ_45_CH, ISB_OBJ_46_CH, ISB_OBJ_47_CH, ISB_OBJ_48_CH, ISB_OBJ_49_CH, ISB_OBJ_50_CH, ISB_OBJ_51_CH, ISB_OBJ_52_CH, ISB_OBJ_53_CH, ISB_OBJ_54_CH };
		#elif ISB_OBJ_MAX == 56
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { ISB_OBJ_0_CH, ISB_OBJ_1_CH, ISB_OBJ_2_CH, ISB_OBJ_3_CH, ISB_OBJ_4_CH, ISB_OBJ_5_CH, ISB_OBJ_6_CH, ISB_OBJ_7_CH, ISB_OBJ_8_CH, ISB_OBJ_9_CH, ISB_OBJ_10_CH, ISB_OBJ_11_CH, ISB_OBJ_12_CH, ISB_OBJ_13_CH, ISB_OBJ_14_CH, ISB_OBJ_15_CH, ISB_OBJ_16_CH, ISB_OBJ_17_CH, ISB_OBJ_18_CH, ISB_OBJ_19_CH, ISB_OBJ_20_CH, ISB_OBJ_21_CH, ISB_OBJ_22_CH, ISB_OBJ_23_CH, ISB_OBJ_24_CH, ISB_OBJ_25_CH, ISB_OBJ_26_CH, ISB_OBJ_27_CH, ISB_OBJ_28_CH, ISB_OBJ_29_CH, ISB_OBJ_30_CH, ISB_OBJ_31_CH, ISB_OBJ_32_CH, ISB_OBJ_33_CH, ISB_OBJ_34_CH, ISB_OBJ_35_CH, ISB_OBJ_36_CH, ISB_OBJ_37_CH, ISB_OBJ_38_CH, ISB_OBJ_39_CH, ISB_OBJ_40_CH, ISB_OBJ_41_CH, ISB_OBJ_42_CH, ISB_OBJ_43_CH, ISB_OBJ_44_CH, ISB_OBJ_45_CH, ISB_OBJ_46_CH, ISB_OBJ_47_CH, ISB_OBJ_48_CH, ISB_OBJ_49_CH, ISB_OBJ_50_CH, ISB_OBJ_51_CH, ISB_OBJ_52_CH, ISB_OBJ_53_CH, ISB_OBJ_54_CH, ISB_OBJ_55_CH };
		#else
			static const uint8_t pgmIsb_Obj_Ch_Array[] PROGMEM = { 0 };
			#error ISB_OBJ_MAX
		#endif /* ISB_OBJ_MAX == ? */

		typedef struct Isb_Obj_t Isb_Obj_t;

		struct Isb_Obj_t
		{
			uint8_t Ctrl;
			uint8_t Top;
			uint8_t Tov;
			uint8_t Data[5];
			uint8_t IsChanged;
		};

		static uint8_t Isb_Obj_Ctrl = 0;
		static uint16_t Isb_Obj_IrqExec = 0;
		static Isb_Obj_t Isb_Obj[ISB_OBJ_MAX];

	#endif /* ISB_OBJ_MAX */



	void Isb_Obj_Exec(void);
	void Isb_Obj_Rx(const Isb_Msg_t * aIsb_Msg);
	uint8_t Isb_Obj_getDlc(uint8_t aTop);



#endif /* ISB_OBJ_H_ */
