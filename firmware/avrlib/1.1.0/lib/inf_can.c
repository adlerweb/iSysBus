/**
 * @file		avrlib/trunk/lib/inf_can.c
 *
 * @brief		Interface Can.
 *
 * This file includes Interface Can.
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





#ifndef INF_CAN_C_
	#define INF_CAN_C_



	#if defined(INF_CAN0_TX) || defined(INF_CAN0_RX) || defined(INF_CAN1_TX) || defined(INF_CAN1_RX) || defined(INF_CAN2_TX) || defined(INF_CAN2_RX)
		uint8_t Inf_Can_Init(const uint8_t aSSPort, const uint8_t aSSPin, const uint8_t aSpiCfg, const uint8_t aCnf1, const uint8_t aCnf2, const uint8_t aCnf3, const uint8_t aRSPort, const uint8_t aRSPin, const uint8_t aMode) {
			Lib_Pin_Set(aSSPort, aSSPin, LIB_PIN_OUTPUT_HIGH);
			Inf_Spi_Init(aSpiCfg);
			Lib_Pin_Set(aSSPort, aSSPin, LIB_PIN_OUTPUT_LOW);
			Inf_Spi_TxRx(LIB_MCP2515_RESET);
			Lib_Pin_Set(aSSPort, aSSPin, LIB_PIN_OUTPUT_HIGH);
			_delay_ms(2);
			Lib_Mcp2515_Write(aSSPort, aSSPin, LIB_MCP2515_CNF1, aCnf1);
			Lib_Mcp2515_Write(aSSPort, aSSPin, LIB_MCP2515_CNF2, aCnf2);
			Lib_Mcp2515_Write(aSSPort, aSSPin, LIB_MCP2515_CNF3, aCnf3);
			Lib_Mcp2515_Write(aSSPort, aSSPin, LIB_MCP2515_RXB0CTRL, 0x64);
			Lib_Mcp2515_Write(aSSPort, aSSPin, LIB_MCP2515_RXB1CTRL, 0x60);
			Lib_Mcp2515_Write(aSSPort, aSSPin, LIB_MCP2515_CANINTE, 0x03);
			if (aRSPort != 0) {
				if (aRSPort < 8) {
					Lib_Pin_Set(aRSPort, aRSPin, LIB_PIN_OUTPUT_LOW);
				}
				else if (aRSPort < 16) {
					Lib_Pin_Set(aRSPort, aRSPin, LIB_PIN_OUTPUT_HIGH);
				}
				else if (aRSPort == 0xFC) {
					Lib_Mcp2515_Modify(aSSPort, aSSPin, LIB_MCP2515_BFPCTRL, 0x14, 0x04);
				}
				else if (aRSPort == 0xFD) {
					Lib_Mcp2515_Modify(aSSPort, aSSPin, LIB_MCP2515_BFPCTRL, 0x28, 0x08);
				}
				else if (aRSPort == 0xFE) {
					Lib_Mcp2515_Modify(aSSPort, aSSPin, LIB_MCP2515_BFPCTRL, 0x14, 0x14);
				}
				else if (aRSPort == 0xFF) {
					Lib_Mcp2515_Modify(aSSPort, aSSPin, LIB_MCP2515_BFPCTRL, 0x28, 0x28);
				}
			}
			Lib_Mcp2515_Write(aSSPort, aSSPin, LIB_MCP2515_BFPCTRL, 0x0C);
			Lib_Mcp2515_Modify(aSSPort, aSSPin, LIB_MCP2515_CANCTRL, 0xE0, aMode);
			if (((Lib_Mcp2515_Read(aSSPort, aSSPin, LIB_MCP2515_CANCTRL)) & 0xE0) == aMode) {
				return TRUE;
			}
			return FALSE;
		}
	#endif /* INF_CAN0_TX || INF_CAN0_RX || INF_CAN1_TX || INF_CAN1_RX || INF_CAN2_TX || INF_CAN2_RX */



	#if defined(INF_CAN0_RX) || defined(INF_CAN1_RX) || defined(INF_CAN2_RX)
		uint8_t Inf_Can_Rx(const uint8_t aSSPort, const uint8_t aSSPin, const uint8_t aSpiCfg, const uint8_t aRSPort, const uint8_t aRSPin, Inf_Can_Msg_t * aInf_Can_Msg) {
			uint8_t State = 0;
			uint8_t CmdSave = 0;
			Lib_Pin_Set(aSSPort, aSSPin, LIB_PIN_OUTPUT_HIGH);
			Inf_Spi_Init(aSpiCfg);
			Lib_Pin_Set(aSSPort, aSSPin, LIB_PIN_OUTPUT_LOW);
			Inf_Spi_Tx(LIB_MCP2515_RX_STATUS);
			State = Inf_Spi_TxRx(0xFF);
			Inf_Spi_TxRx(0xFF);
			Lib_Pin_Set(aSSPort, aSSPin, LIB_PIN_OUTPUT_HIGH);
			if (bit_is_set(State, LIB_MCP2515_RX_STATUS_INSTRUCTION_CANINTF_RX0IF)) {
				CmdSave = LIB_MCP2515_READ_RX_BUFFER0;
			}
			else if (bit_is_set(State, LIB_MCP2515_RX_STATUS_INSTRUCTION_CANINTF_RX1IF)) {
				CmdSave = LIB_MCP2515_READ_RX_BUFFER1;
			}
			else {
				return FALSE;
			}
			Lib_Pin_Set(aSSPort, aSSPin, LIB_PIN_OUTPUT_LOW);
			Inf_Spi_Tx(CmdSave);
			aInf_Can_Msg->SIdH = Inf_Spi_TxRx(0x00);
			aInf_Can_Msg->SIdL = Inf_Spi_TxRx(0x00);
			aInf_Can_Msg->EIdH = Inf_Spi_TxRx(0x00);
			aInf_Can_Msg->EIdL = Inf_Spi_TxRx(0x00);
			aInf_Can_Msg->Dlc = Inf_Spi_TxRx(0x00);
			if (bit_is_clear(aInf_Can_Msg->Dlc, 6)) {
				for (uint8_t i = 0; i < aInf_Can_Msg->Dlc; i++) {
					aInf_Can_Msg->Data[i] = Inf_Spi_TxRx(0x00);
				}
			}
			else {
				for (uint8_t i = 0; i < 8; i++) {
					aInf_Can_Msg->Data[i] = 0x00;
				}
			}
			Lib_Pin_Set(aSSPort, aSSPin, LIB_PIN_OUTPUT_HIGH);
			return TRUE;
		}
	#endif /* INF_CAN0_RX || INF_CAN1_RX || INF_CAN2_RX */



	#if defined(INF_CAN0_TX) || defined(INF_CAN1_TX) || defined(INF_CAN2_TX)
		uint8_t Inf_Can_Tx(const uint8_t aSSPort, const uint8_t aSSPin, const uint8_t aSpiCfg, const uint8_t aRSPort, const uint8_t aRSPin, Inf_Can_Msg_t * aInf_Can_Msg) {
			uint8_t State = 0;
			uint8_t CmdLoad = 0;
			uint8_t CmdSend = 0;
			Lib_Pin_Set(aSSPort, aSSPin, LIB_PIN_OUTPUT_HIGH);
			Inf_Spi_Init(aSpiCfg);
			Lib_Pin_Set(aSSPort, aSSPin, LIB_PIN_OUTPUT_LOW);
			Inf_Spi_Tx(LIB_MCP2515_READ_STATUS);
			State = Inf_Spi_TxRx(0xFF);
			Inf_Spi_TxRx(0xFF);
			Lib_Pin_Set(aSSPort, aSSPin, LIB_PIN_OUTPUT_HIGH);
			if (bit_is_clear(State, LIB_MCP2515_READ_STATUS_TXB0CTRL_TXREQ)) {
				CmdLoad = LIB_MCP2515_LOAD_TX_BUFFER0;
				CmdSend = LIB_MCP2515_RTS_TX0;
			}
			else if (bit_is_clear(State, LIB_MCP2515_READ_STATUS_TXB1CTRL_TXREQ)) {
				CmdLoad = LIB_MCP2515_LOAD_TX_BUFFER1;
				CmdSend = LIB_MCP2515_RTS_TX1;
			}
			else if (bit_is_clear(State, LIB_MCP2515_READ_STATUS_TXB2CTRL_TXREQ)) {
				CmdLoad = LIB_MCP2515_LOAD_TX_BUFFER2;
				CmdSend = LIB_MCP2515_RTS_TX2;
			}
			else {
				return FALSE;
			}
			Lib_Pin_Set(aSSPort, aSSPin, LIB_PIN_OUTPUT_LOW);
			Inf_Spi_Tx(CmdLoad);
			Inf_Spi_Tx(aInf_Can_Msg->SIdH);
			Inf_Spi_Tx(aInf_Can_Msg->SIdL);
			Inf_Spi_Tx(aInf_Can_Msg->EIdH);
			Inf_Spi_Tx(aInf_Can_Msg->EIdL);
			Inf_Spi_Tx(aInf_Can_Msg->Dlc);
			if (bit_is_clear(aInf_Can_Msg->Dlc, 6)) {
				for (uint8_t i = 0; i < aInf_Can_Msg->Dlc; i++)
				{
					Inf_Spi_Tx(aInf_Can_Msg->Data[i]);
				}
			}
			Lib_Pin_Set(aSSPort, aSSPin, LIB_PIN_OUTPUT_HIGH);
			asm volatile("nop");
			Lib_Pin_Set(aSSPort, aSSPin, LIB_PIN_OUTPUT_LOW);
			Inf_Spi_Tx(CmdSend);
			Lib_Pin_Set(aSSPort, aSSPin, LIB_PIN_OUTPUT_HIGH);
			return TRUE;
		}
	#endif /* INF_CAN0_TX || INF_CAN1_TX || INF_CAN2_TX */



#endif /* INF_CAN_C_ */
