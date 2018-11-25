/**
 * @file		avrlib/trunk/lib/isb_inf_can.c
 *
 * @brief		iSysBus Interface Can.
 *
 * This file includes iSysBus Interface Can.
 *
 * @author		© Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
 *
 * @date		$Date: 2011-08-03 15:23:38 +0200 (Mi, 03 Aug 2011) $
 *
 * @version		$Rev: 4514 $
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





#ifndef ISB_INF_CAN_C_
	#define ISB_INF_CAN_C_



	uint8_t Isb_Inf_Can_Init(const uint8_t aInf) {
		uint8_t Result = FALSE;
		switch (aInf) {
			#if ISB_INF_CAN0 == 1
				case 0:
					Result = Inf_Can_Init(INF_CAN0_SSPORT, INF_CAN0_SSPIN, INF_CAN0_SPICFG, INF_CAN0_CNF1, INF_CAN0_CNF2, INF_CAN0_CNF3, INF_CAN0_RSPORT, INF_CAN0_RSPIN, INF_CAN0_MODE);
					break;
			#endif /* ISB_INF_CAN0 == 1 */
			#if ISB_INF_CAN1 == 1
				case 1:
					Result = Inf_Can_Init(INF_CAN1_SSPORT, INF_CAN1_SSPIN, INF_CAN1_SPICFG, INF_CAN1_CNF1, INF_CAN1_CNF2, INF_CAN1_CNF3, INF_CAN1_RSPORT, INF_CAN1_RSPIN, INF_CAN1_MODE);
				break;
			#endif /* ISB_INF_CAN1 == 1 */
			#if ISB_INF_CAN2 == 1
				case 1:
					Result = Inf_Can_Init(INF_CAN2_SSPORT, INF_CAN2_SSPIN, INF_CAN2_SPICFG, INF_CAN2_CNF1, INF_CAN2_CNF2, INF_CAN2_CNF3, INF_CAN2_RSPORT, INF_CAN2_RSPIN, INF_CAN2_MODE);
					break;
			#endif /* ISB_INF_CAN2 == 1 */
		}
		return Result;
	}



	uint8_t Isb_Inf_Can_Rx(const uint8_t aInf, Isb_Msg_t * aIsb_Msg) {
		uint8_t aSSPort;
		uint8_t aSSPin;
		uint8_t aSpiCfg;
		uint8_t aRSPort;
		uint8_t aRSPin;
		switch (aInf) {
			#if ISB_INF_CAN0 == 1
				case 0:
					aSSPort = INF_CAN0_SSPORT;
					aSSPin = INF_CAN0_SSPIN;
					aSpiCfg = INF_CAN0_SPICFG;
					aRSPort = INF_CAN0_RSPORT;
					aRSPin = INF_CAN0_RSPIN;
					break;
			#endif /* ISB_INF_CAN0 == 1 */
			#if ISB_INF_CAN1 == 1
				case 1:
					aSSPort = INF_CAN1_SSPORT;
					aSSPin = INF_CAN1_SSPIN;
					aSpiCfg = INF_CAN1_SPICFG;
					aRSPort = INF_CAN1_RSPORT;
					aRSPin = INF_CAN1_RSPIN;
					break;
			#endif /* ISB_INF_CAN1 == 1 */
			#if ISB_INF_CAN2 == 1
				case 2:
					aSSPort = INF_CAN2_SSPORT;
					aSSPin = INF_CAN2_SSPIN;
					aSpiCfg = INF_CAN2_SPICFG;
					aRSPort = INF_CAN2_RSPORT;
					aRSPin = INF_CAN2_RSPIN;
					break;
			#endif /* ISB_INF_CAN2 == 1 */
			default:
				return FALSE;
				break;
		}
		Inf_Can_Msg_t aCanMsg;
		if (Inf_Can_Rx(aSSPort, aSSPin, aSpiCfg, aRSPort, aRSPin, &aCanMsg) == TRUE) {
			aIsb_Msg->Flags = ((aCanMsg.SIdH & 0xC0) >> 2) | (aCanMsg.Dlc & ISB_MSG_FLAGS_DLC_MASK);
			aIsb_Msg->DestId = (uint16_t)((aCanMsg.EIdH & 0xF8) >> 3) + (uint16_t)((aCanMsg.SIdL & 0x03) << 5) + (uint16_t)((aCanMsg.SIdL & 0xE0) << 2) + (uint16_t)((aCanMsg.SIdH & 0x3F) << 10);
			aIsb_Msg->SourceId = (uint16_t)aCanMsg.EIdL + (uint16_t)((aCanMsg.EIdH & 0x07) << 8);
			if (bit_is_set(aCanMsg.Dlc, 6)) {
				aIsb_Msg->Flags |= 0x40;
			}
			else {
				for (uint8_t i = 0; i < aCanMsg.Dlc; i++) {
					aIsb_Msg->Data[i] = aCanMsg.Data[i];
				}
			}
			return TRUE;
		}
		return FALSE;
	}



	uint8_t Isb_Inf_Can_Tx(const uint8_t aInf, const Isb_Msg_t * aIsb_Msg) {
		uint8_t aSSPort;
		uint8_t aSSPin;
		uint8_t aSpiCfg;
		uint8_t aRSPort;
		uint8_t aRSPin;
		switch (aInf) {
			#if ISB_INF_CAN0 == 1
				case 0:
					aSSPort = INF_CAN0_SSPORT;
					aSSPin = INF_CAN0_SSPIN;
					aSpiCfg = INF_CAN0_SPICFG;
					aRSPort = INF_CAN0_RSPORT;
					aRSPin = INF_CAN0_RSPIN;
					break;
			#endif /* ISB_INF_CAN0 == 1 */
			#if ISB_INF_CAN1 == 1
				case 1:
					aSSPort = INF_CAN1_SSPORT;
					aSSPin = INF_CAN1_SSPIN;
					aSpiCfg = INF_CAN1_SPICFG;
					aRSPort = INF_CAN1_RSPORT;
					aRSPin = INF_CAN1_RSPIN;
					break;
			#endif /* ISB_INF_CAN1 == 1 */
			#if ISB_INF_CAN2 == 1
				case 2:
					aSSPort = INF_CAN2_SSPORT;
					aSSPin = INF_CAN2_SSPIN;
					aSpiCfg = INF_CAN2_SPICFG;
					aRSPort = INF_CAN2_RSPORT;
					aRSPin = INF_CAN2_RSPIN;
					break;
			#endif /* ISB_INF_CAN2 == 1 */
			default:
				return FALSE;
				break;
		}
		Inf_Can_Msg_t aCanMsg;
		// Write Message to SendBuffer - TXBnSIDH:
		//	[7..6] = Type
		//	[5..0] = Dest[15..10]
		aCanMsg.SIdH = ((aIsb_Msg->Flags << 2) & 0xC0) | (aIsb_Msg->DestId >> 10);
		// Write Message to SendBuffer - TXBnSIDL:
		//	[7..5] = Dest[9..7]
		//	[4] = 0
		//	[3] = 1
		//	[2] = 0
		//	[1..0] = Dest[6..5]
		aCanMsg.SIdL = ((uint8_t)(aIsb_Msg->DestId >> 2) & 0xE0) | 0x08 | ((uint8_t)(aIsb_Msg->DestId >> 5) & 0x03);
		// Write Message to SendBuffer - TXBnEID8:
		//	[7..3] = Dest[4..0]
		//	[2..0] = Source[10..8]
		aCanMsg.EIdH = ((uint8_t)((aIsb_Msg->DestId << 3) & 0xF8)) | ((uint8_t)((aIsb_Msg->SourceId >> 8) & 0x07));
		// Write Message to SendBuffer - TXBnEID0:
		//	[7..0] = Source[7..0]
		aCanMsg.EIdL = (uint8_t)aIsb_Msg->SourceId;
		// Write Message to SendBuffer - DataLength
		aCanMsg.Dlc = aIsb_Msg->Flags & ISB_MSG_FLAGS_DLC_MASK;
		// RTR
		if (bit_is_set(aIsb_Msg->Flags, 6)) {
			aCanMsg.Dlc |= 0x40;
		}
		else {
			for (uint8_t i = 0; i < aCanMsg.Dlc; i++) {
				aCanMsg.Data[i] = aIsb_Msg->Data[i];
			}
		}
		if (Inf_Can_Tx(aSSPort, aSSPin, aSpiCfg, aRSPort, aRSPin, &aCanMsg) == TRUE) {
			return TRUE;
		}
		return FALSE;
	}



#endif /* ISB_INF_CAN_C_ */
