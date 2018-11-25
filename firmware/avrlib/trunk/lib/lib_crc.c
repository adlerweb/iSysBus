/**
 * @file		avrlib/trunk/lib/lib_crc.c
 *
 * @brief		Library Crc.
 *
 * This file includes Library Crc.
 *
 * @author		© Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
 *
 * @date		$Date: 2010-05-28 11:38:03 +0200 (Fr, 28. Mai 2010) $
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





#ifndef LIB_CRC_C_
	#define LIB_CRC_C_



	uint8_t Lib_Crc_Calc8(const void * aData, uint16_t aLength) {
		uint8_t Sum = 0;
		for (uint16_t i = 0; i < aLength; i++) {
			Sum += *(uint8_t *)(aData + i);
		}
		return (uint8_t)((Sum ^ 0xFF) + 1);
	}



	uint16_t Lib_Crc_Calc16(const void * aData, uint16_t aLength) {
		uint32_t Sum = 0;
		while (1) {
			if (aLength < 2) {
				break;
			}
			Sum += *((uint16_t *)aData);
			aData += 2;
			aLength -= 2;
		}
		if (aLength) {
			Sum += *(uint8_t *) aData;
		}
		while ((aLength = (uint16_t) (Sum >> 16)) != 0) {
			Sum = (uint16_t) Sum + aLength;
		}
		return (uint16_t) Sum ^ 0xFFFF;
	}



#endif /* LIB_CRC_C_ */
