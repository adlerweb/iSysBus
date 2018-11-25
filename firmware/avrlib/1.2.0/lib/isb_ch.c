/**
 * @file		avrlib/trunk/lib/isb_ch.c
 *
 * @brief		iSysBus Channel.
 *
 * This file includes the iSysBus Channel.
 *
 * @author		© Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
 *
 * @date		$Date: 2010-05-28 11:38:03 +0200 (Fr, 28 Mai 2010) $
 *
 * @version		$Rev: 3913 $
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





#ifndef ISB_CH_C_
	#define ISB_CH_C_



	void Isb_Ch_Init(void) {
		for (uint8_t ChIndex = 0; ChIndex < ISB_CH_MAX; ChIndex++) {
			uint16_t eepAddrCtrl = 0;
			uint16_t eepAddrCrc = 0;
			switch (ChIndex) {
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
				default:
					eepAddrCtrl = 0;
					eepAddrCrc = 0;
					break;
			}
			Isb_Ch[ChIndex].Ctrl = 0;
			if (eepAddrCtrl < eepAddrCrc) {
				uint8_t Crc = 0;
				for (uint16_t eepAddr = eepAddrCtrl; eepAddr <= eepAddrCrc; eepAddr++) {
//					Crc += lib_eep_fw_read_byte((uint8_t *)eepAddr);
				}
				if (Crc == 0) {
					Isb_Ch[ChIndex].Ctrl = lib_eep_fw_read_byte((uint8_t *)eepAddrCtrl);
				}
			}
		}
	}



#endif /* ISB_CH_C_ */
