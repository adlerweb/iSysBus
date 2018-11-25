/**
 * @file		avrlib/trunk/lib/isb_inf_usart_def.h
 *
 * @brief		iSysBus Interface Usart Defines.
 *
 * This file includes iSysBus Interface Usart Defines.
 *
 * @author		© Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
 *
 * @date		$Date: 2011-08-03 15:18:11 +0200 (Mi, 03 Aug 2011) $
 *
 * @version		$Rev: 4513 $
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





#ifndef ISB_INF_USART_DEF_H_
	#define ISB_INF_USART_DEF_H_



	#if ISB_INF_USART0 == 1

		#define INF_USART0_RX
		#define INF_USART0_TX

		#define INF_USART0_BAUDRATE						ISB_INF_USART0_BAUDRATE
		#define INF_USART0_STARTBITS					ISB_INF_USART0_STARTBITS
		#define INF_USART0_DATABITS						ISB_INF_USART0_DATABITS
		#define INF_USART0_PARITY						ISB_INF_USART0_PARITY
		#define INF_USART0_STOPBITS						ISB_INF_USART0_STOPBITS

		#define ISB_INF_USART0_STARTBYTE				0x01
		#define ISB_INF_USART0_STOPBYTE					0x0D

	#endif /* ISB_INF_USART0 == 1 */



	#if ISB_INF_USART1 == 1

		#define INF_USART1_RX
		#define INF_USART1_TX

		#define INF_USART1_BAUDRATE						ISB_INF_USART1_BAUDRATE
		#define INF_USART1_STARTBITS					ISB_INF_USART1_STARTBITS
		#define INF_USART1_DATABITS						ISB_INF_USART1_DATABITS
		#define INF_USART1_PARITY						ISB_INF_USART1_PARITY
		#define INF_USART1_STOPBITS						ISB_INF_USART1_STOPBITS

		#define ISB_INF_USART1_STARTBYTE				0x01
		#define ISB_INF_USART1_STOPBYTE					0x0D

	#endif /* ISB_INF_USART1 == 1 */



#endif /* ISB_INF_USART_DEF_H_ */
