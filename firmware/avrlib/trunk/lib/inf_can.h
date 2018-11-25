/**
 * @file		avrlib/trunk/lib/inf_can.h
 *
 * @brief		Interface Can.
 *
 * This file includes Interface Can.
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





#ifndef INF_CAN_H_
	#define INF_CAN_H_



	typedef struct
	{
		uint8_t SIdL;
		uint8_t SIdH;
		uint8_t EIdL;
		uint8_t EIdH;
		uint8_t Dlc;
		uint8_t Data[8];
	} Inf_Can_Msg_t;



	#if defined(INF_CAN0_TX) || defined(INF_CAN0_RX) || defined(INF_CAN1_TX) || defined(INF_CAN1_RX) || defined(INF_CAN2_TX) || defined(INF_CAN2_RX)
		uint8_t Inf_Can_Init(const uint8_t aSSPort, const uint8_t aSSPin, const uint8_t aSpiCfg, const uint8_t aCnf1, const uint8_t aCnf2, const uint8_t aCnf3, const uint8_t aRSPort, const uint8_t aRSPin, const uint8_t aMode);
	#endif /* INF_CAN0_TX || INF_CAN0_RX || INF_CAN1_TX || INF_CAN1_RX || INF_CAN2_TX || INF_CAN2_RX */

	#if defined(INF_CAN0_TX) || defined(INF_CAN1_TX) || defined(INF_CAN2_TX)
		uint8_t Inf_Can_Tx(const uint8_t aSSPort, const uint8_t aSSPin, const uint8_t aSpiCfg, const uint8_t aRSPort, const uint8_t aRSPin, Inf_Can_Msg_t *aMsg);
	#endif /* INF_CAN0_TX || INF_CAN1_TX || INF_CAN2_TX */

	#if defined(INF_CAN0_RX) || defined(INF_CAN1_RX) || defined(INF_CAN2_RX)
		uint8_t Inf_Can_Rx(const uint8_t aSSPort, const uint8_t aSSPin, const uint8_t aSpiCfg, const uint8_t aRSPort, const uint8_t aRSPin, Inf_Can_Msg_t *aMsg);
	#endif /* INF_CAN0_RX || INF_CAN1_RX || INF_CAN2_RX */



#endif /* INF_CAN_H_ */
