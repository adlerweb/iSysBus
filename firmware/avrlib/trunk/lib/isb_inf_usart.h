/**
 * @file		avrlib/trunk/lib/isb_inf_usart.h
 *
 * @brief		iSysBus Interface Usart.
 *
 * This file includes iSysBus Interface Usart.
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





#ifndef ISB_INF_USART_H_
	#define ISB_INF_USART_H_



	uint8_t Isb_Inf_Usart_Init(const uint8_t aInf);
	uint8_t Isb_Inf_Usart_Rx(const uint8_t aInf, Isb_Msg_t * aMsg);
	uint8_t Isb_Inf_Usart_Tx(const uint8_t aInf, const Isb_Msg_t * aMsg);



#endif /* ISB_INF_USART_H_ */
