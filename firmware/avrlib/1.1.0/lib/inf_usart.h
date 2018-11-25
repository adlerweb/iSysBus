/**
 * @file		avrlib/trunk/lib/inf_usart.h
 *
 * @brief		Interface Usart.
 *
 * This file includes Interface Usart.
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





#ifndef INF_USART_H_
	#define INF_USART_H_



	#if defined(INF_USART0_TX) || defined(INF_USART0_RX) || defined(INF_USART1_TX) || defined(INF_USART1_RX)
		uint8_t Inf_Usart_Init(const uint8_t aInf, const uint8_t Ubrrl, const uint8_t Ubrrh, const uint8_t Uscra, const uint8_t Uscrb, const uint8_t Ucsrc);
	#endif /* INF_USART0_TX || INF_USART0_RX || INF_USART1_TX || INF_USART1_RX*/

	#if defined(INF_USART0_RX) || defined(INF_USART1_RX)
		uint8_t Inf_Usart_Rx(const uint8_t aInf, uint8_t *aChar);
	#endif /* INF_USART0_RX || INF_USART1_RX */

	#if defined(INF_USART0_RX)
		void __attribute__((always_inline)) Inf_Usart0_Rx_Irq(void);
	#endif /* INF_USART0_RX */

	#if defined(INF_USART1_RX)
		void __attribute__((always_inline)) Inf_Usart1_Rx_Irq(void);
	#endif /* INF_USART1_RX */

	#if defined(INF_USART0_TX) || defined(INF_USART1_TX)
		uint8_t Inf_Usart_Tx(const uint8_t aInf, const uint8_t *aChar);
	#endif /* INF_USART0_TX || INF_USART1_TX */

	#if defined(INF_USART0_TX)
		void __attribute__((always_inline)) Inf_Usart0_Tx_Irq(void);
	#endif /* INF_USART0_TX */

	#if defined(INF_USART1_TX)
		void __attribute__((always_inline)) Inf_Usart1_Tx_Irq(void);
	#endif /* INF_USART1_TX */



	#if defined(INF_USART0_RX)
		#if defined(INF_USART_RX0_BUFFER_SIZE)
			#warning "INF_USART_RX0_BUFFER_SIZE wurde überschrieben"
		#else /* INF_USART_RX0_BUFFER_SIZE */
			#define INF_USART_RX0_BUFFER_SIZE 64
		#endif /* INF_USART_RX0_BUFFER_SIZE */
	#endif /* INF_USART0_RX */

	#ifdef INF_USART0_TX
		#ifdef INF_USART_TX0_BUFFER_SIZE
			#warning "INF_USART_TX0_BUFFER_SIZE wurde überschrieben"
		#else /* INF_USART_TX0_BUFFER_SIZE */
			#define INF_USART_TX0_BUFFER_SIZE 64
		#endif /* INF_USART_TX0_BUFFER_SIZE */
	#endif /*INF_USART0_TX*/

	#if defined(INF_USART1_RX)
		#if defined(INF_USART_RX1_BUFFER_SIZE)
			#warning "INF_USART_RX1_BUFFER_SIZE wurde überschrieben"
		#else /* INF_USART_RX1_BUFFER_SIZE */
			#define INF_USART_RX1_BUFFER_SIZE 64
		#endif /* INF_USART_RX1_BUFFER_SIZE */
	#endif /*INF_USART1_RX*/

	#if defined(INF_USART1_TX)
		#if defined(INF_USART_TX1_BUFFER_SIZE)
			#warning "INF_USART_TX1_BUFFER_SIZE wurde überschrieben"
		#else /* INF_USART_TX1_BUFFER_SIZE */
			#define INF_USART_TX1_BUFFER_SIZE 64
		#endif /* INF_USART_TX1_BUFFER_SIZE */
	#endif /*INF_USART1_TX*/



	#if defined(INF_USART0_RX)
		static volatile uint8_t Inf_Usart_Rx0_Buffer[INF_USART_RX0_BUFFER_SIZE];
		static volatile uint8_t Inf_Usart_Rx0_Buffer_Tail = 0;
		static volatile uint8_t Inf_Usart_Rx0_Buffer_Head = 0;
		#define INF_USART_RX0_BUFFER_MASK (INF_USART_RX0_BUFFER_SIZE - 1)
	#endif /* INF_USART0_RX */

	#if defined(INF_USART0_TX)
		static volatile uint8_t Inf_Usart_Tx0_Buffer[INF_USART_TX0_BUFFER_SIZE];
		static volatile uint8_t Inf_Usart_Tx0_Buffer_Tail = 0;
		static volatile uint8_t Inf_Usart_Tx0_Buffer_Head = 0;
		#define INF_USART_TX0_BUFFER_MASK (INF_USART_TX0_BUFFER_SIZE - 1)
	#endif /* INF_USART0_TX */

	#if defined(INF_USART1_RX)
		static volatile uint8_t Inf_Usart_Rx1_Buffer[INF_USART_RX1_BUFFER_SIZE];
		static volatile uint8_t Inf_Usart_Rx1_Buffer_Tail = 0;
		static volatile uint8_t Inf_Usart_Rx1_Buffer_Head = 0;
		#define INF_USART_RX1_BUFFER_MASK (INF_USART_RX1_BUFFER_SIZE - 1)
	#endif /* INF_USART1_RX */

	#if defined(INF_USART1_TX)
		static volatile uint8_t Inf_Usart_Tx1_Buffer[INF_USART_TX1_BUFFER_SIZE];
		static volatile uint8_t Inf_Usart_Tx1_Buffer_Tail = 0;
		static volatile uint8_t Inf_Usart_Tx1_Buffer_Head = 0;
		#define INF_USART_TX1_BUFFER_MASK (INF_USART_TX1_BUFFER_SIZE - 1)
	#endif /* INF_USART1_TX */



#endif /*INF_USART_H_*/
