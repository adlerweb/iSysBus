/**
 * @file		avrlib/trunk/lib/lib_mcp2515.h
 *
 * @brief		Library Mcp2515.
 *
 * This file includes Library Mcp2515.
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





#ifndef LIB_MCP2515_H_
	#define LIB_MCP2515_H_



	uint8_t Lib_Mcp2515_Read(const uint8_t aSSPort, const uint8_t aSSPin, const uint8_t aAddr);

	void Lib_Mcp2515_Write(const uint8_t aSSPort, const uint8_t aSSPin, const uint8_t aAddr, const uint8_t aData);

	void Lib_Mcp2515_Modify(const uint8_t aSSPort, const uint8_t aSSPin, const uint8_t aAddr, const uint8_t aMask, const uint8_t aData);



#endif /* LIB_MCP2515_H_ */
