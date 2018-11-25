/**
 * @file		avrlib/trunk/lib/lib_mcp2515.c
 *
 * @brief		Library Mcp2515.
 *
 * This file includes Library Mcp2515.
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





#ifndef LIB_MCP2515_C_
	#define LIB_MCP2515_C_



	uint8_t Lib_Mcp2515_Read(const uint8_t aSSPort, const uint8_t aSSPin, const uint8_t aAddr) {
		uint8_t aData;
		Lib_Pin_Set(aSSPort, aSSPin, LIB_PIN_OUTPUT_LOW);
		Inf_Spi_TxRx(LIB_MCP2515_READ);
		Inf_Spi_TxRx(aAddr);
		aData = Inf_Spi_TxRx(0xff);
		Lib_Pin_Set(aSSPort, aSSPin, LIB_PIN_OUTPUT_HIGH);
		return aData;
	}



	void Lib_Mcp2515_Write(const uint8_t aSSPort, const uint8_t aSSPin, const uint8_t aAddr, const uint8_t aData) {
		Lib_Pin_Set(aSSPort, aSSPin, LIB_PIN_OUTPUT_LOW);
		Inf_Spi_TxRx(LIB_MCP2515_WRITE);
		Inf_Spi_TxRx(aAddr);
		Inf_Spi_TxRx(aData);
		Lib_Pin_Set(aSSPort, aSSPin, LIB_PIN_OUTPUT_HIGH);
	}



	void Lib_Mcp2515_Modify(const uint8_t aSSPort, const uint8_t aSSPin, const uint8_t aAddr, const uint8_t aMask, const uint8_t aData) {
		Lib_Pin_Set(aSSPort, aSSPin, LIB_PIN_OUTPUT_LOW);
		Inf_Spi_TxRx(LIB_MCP2515_BIT_MODIFY);
		Inf_Spi_TxRx(aAddr);
		Inf_Spi_TxRx(aMask);
		Inf_Spi_TxRx(aData);
		Lib_Pin_Set(aSSPort, aSSPin, LIB_PIN_OUTPUT_HIGH);
	}



#endif /* LIB_MCP2515_C_ */
