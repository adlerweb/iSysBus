/**
 * @file		avrlib/trunk/lib/lib_crc.h
 *
 * @brief		Library Crc.
 *
 * This file includes Library Crc.
 *
 * @author		© Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
 *
 * @date		$Date: 2011-09-24 20:15:53 +0200 (Sa, 24. Sep 2011) $
 *
 * @version		$Rev: 5208 $
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





#ifndef LIB_CRC_H_
	#define LIB_CRC_H_



	uint8_t Lib_Crc_Calc8(const void * aData, uint16_t aLength);

	uint16_t Lib_Crc_Calc16(const void * aData, uint16_t aLength);



#endif /* LIB_CRC_H_ */
