/**
 * @file		avrlib/trunk/lib/lib_ds1621.h
 *
 * @brief		Library Ds1621.
 *
 * This file includes Library Ds1621.
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





#ifndef LIB_DS1621_H_
	#define LIB_DS1621_H_



	uint8_t Lib_Ds1621_StartConvertT(uint8_t aSla);
	uint8_t Lib_Ds1621_ReadTemperature(uint8_t aSla, uint16_t *aData);



#endif /* LIB_DS1621_H_ */
