/**
 * @file		avrlib/trunk/lib/inf_usart.c
 *
 * @brief		Interface Usart.
 *
 * This file includes Interface Usart.
 *
 * @author		© Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
 *
 * @date		$Date: 2011-10-21 12:10:15 +0200 (Fr, 21. Okt 2011) $
 *
 * @version		$Rev: 6285 $
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





#ifndef INF_USART_C_
	#define INF_USART_C_



	#if defined(INF_USART0_TX) || defined(INF_USART0_RX) || defined(INF_USART1_TX) || defined(INF_USART1_RX)
		uint8_t Inf_Usart_Init(const uint8_t aInf, const uint8_t aUbrrl, const uint8_t aUbrrh, const uint8_t aUcsra, const uint8_t aUcsrb, const uint8_t aUcsrc) {
			uint8_t Result = FALSE;
			switch (aInf) {
				#if defined(INF_USART0_RX) || defined(INF_USART0_TX)
					case 0:
						#if defined(INF_USART0_RX)
							Inf_Usart_Rx0_Buffer_Tail = Inf_Usart_Rx0_Buffer_Head;
						#endif /* INF_USART0_RX */
						#if defined(INF_USART0_TX)
							Inf_Usart_Tx0_Buffer_Tail = Inf_Usart_Tx0_Buffer_Head;
						#endif /* INF_USART0_TX */
						#if defined(__AVR_ATmega8__) || defined(__AVR_ATmega16__) || (__AVR_ATmega32__)
							UCSRA = aUcsra;
							UBRRH = aUbrrh;
							UBRRL = aUbrrl;
							UCSRC = aUcsrc;
							UCSRB = aUcsrb;
							Result = TRUE;
						#elif defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)
							UCSR0A = aUcsra;
							UBRR0H = aUbrrh;
							UBRR0L = aUbrrl;
							UCSR0C = aUcsrc;
							UCSR0B = aUcsrb;
							Result = TRUE;
						#elif defined(__AVR_ATmega48__) || defined(__AVR_ATmega88__) || defined(__AVR_ATmega168__)
							UCSR0A = aUcsra;
							UBRR0H = aUbrrh;
							UBRR0L = aUbrrl;
							UCSR0C = aUcsrc;
							UCSR0B = aUcsrb;
							Result = TRUE;
						#elif defined(__AVR_ATmega169P__)
							UCSR0A = aUcsra;
							UBRR0H = aUbrrh;
							UBRR0L = aUbrrl;
							UCSR0C = aUcsrc;
							UCSR0B = aUcsrb;
							Result = TRUE;
						#elif defined(__AVR_ATmega644__)
							UCSR0A = aUcsra;
							UBRR0H = aUbrrh;
							UBRR0L = aUbrrl;
							UCSR0C = aUcsrc;
							UCSR0B = aUcsrb;
							Result = TRUE;
						#elif defined(__AVR_AT90CAN32__) || defined(__AVR_AT90CAN64__) || defined(__AVR_AT90CAN128__)
							UCSR0A = aUcsra;
							UBRR0H = aUbrrh;
							UBRR0L = aUbrrl;
							UCSR0C = aUcsrc;
							UCSR0B = aUcsrb;
							Result = TRUE;
						#else
							#error "inf_usart.c -> Inf_Usart_Init -> No definition for this MCU available."
						#endif
						break;
				#endif /* INF_USART0_RX || INF_USART0_TX */
				#if defined(INF_USART1_RX) || defined(INF_USART1_TX)
					case 1:
						#if defined(INF_USART1_RX)
							Inf_Usart_Rx1_Buffer_Tail = Inf_Usart_Rx1_Buffer_Head;
						#endif /* INF_USART1_RX */
						#if defined(INF_USART1_TX)
							Inf_Usart_Tx1_Buffer_Tail = Inf_Usart_Tx1_Buffer_Head;
						#endif /* INF_USART1_TX */
						#if defined(__AVR_ATmega8__) || defined(__AVR_ATmega16__) || defined(__AVR_ATmega32__)
							#error "inf_usart.c -> Inf_Usart_Init -> This MCU has only 1 USART."
						#elif defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)
							UCSR1A = aUcsra;
							UBRR1H = aUbrrh;
							UBRR1L = aUbrrl;
							UCSR1C = aUcsrc;
							UCSR1B = aUcsrb;
							Result = TRUE;
						#elif defined(__AVR_ATmega48__) || defined(__AVR_ATmega88__) || defined(__AVR_ATmega168__)
							#error "inf_usart.c -> Inf_Usart_Init -> This MCU has only 1 USART."
						#elif defined(__AVR_ATmega169P__)
							#error "inf_usart.c -> Inf_Usart_Init -> This MCU has only 1 USART."
						#elif defined(__AVR_ATmega644__)
							#error "inf_usart.c -> Inf_Usart_Init -> This MCU has only 1 USART."
						#elif defined(__AVR_AT90CAN32__) || defined(__AVR_AT90CAN64__) || defined(__AVR_AT90CAN128__)
							UCSR1A = aUcsra;
							UBRR1H = aUbrrh;
							UBRR1L = aUbrrl;
							UCSR1C = aUcsrc;
							UCSR1B = aUcsrb;
							Result = TRUE;
						#else
							#error "inf_usart.c -> Inf_Usart_Init -> No definition for this MCU available."
						#endif
						break;
				#endif /* INF_USART1_RX || INF_USART1_TX */
			}
			return Result;
		}

	#endif /* INF_USART0_TX || INF_USART0_RX || INF_USART1_TX || INF_USART1_RX*/



	#if defined(INF_USART0_RX) || defined(INF_USART1_RX)
		uint8_t Inf_Usart_Rx(const uint8_t aInf, uint8_t * aChar) {
			uint8_t Result = FALSE;
			switch (aInf) {
				#if defined(INF_USART0_RX)
					case 0:
						if (Inf_Usart_Rx0_Buffer_Head != Inf_Usart_Rx0_Buffer_Tail) {
							Inf_Usart_Rx0_Buffer_Tail = (Inf_Usart_Rx0_Buffer_Tail + 1) & INF_USART_RX0_BUFFER_MASK;
							*aChar = Inf_Usart_Rx0_Buffer[Inf_Usart_Rx0_Buffer_Tail];
							Result = TRUE;
						}
						break;
				#endif /* INF_USART0_RX */
				#if defined(INF_USART1_RX)
					case 1:
						if (Inf_Usart_Rx1_Buffer_Head != Inf_Usart_Rx1_Buffer_Tail) {
							Inf_Usart_Rx1_Buffer_Tail = (Inf_Usart_Rx1_Buffer_Tail + 1) & INF_USART_RX1_BUFFER_MASK;
							*aChar = Inf_Usart_Rx1_Buffer[Inf_Usart_Rx1_Buffer_Tail];
							Result = TRUE;
						}
						break;
				#endif /* INF_USART1_RX */
			}
			return Result;
		}
	#endif /* INF_USART0_RX || INF_USART1_RX */



	#if defined(INF_USART0_RX)
		#if defined(__AVR_ATmega8__) || defined(__AVR_ATmega16__) || (__AVR_ATmega32__)
			ISR (USART_RXC_vect) {
				uint8_t Tmp_Head;
				Tmp_Head = (Inf_Usart_Rx0_Buffer_Head + 1) & INF_USART_RX0_BUFFER_MASK;
				if (Tmp_Head != Inf_Usart_Rx0_Buffer_Tail) {
					Inf_Usart_Rx0_Buffer[Tmp_Head] = UDR;
					Inf_Usart_Rx0_Buffer_Head = Tmp_Head;
				}
			}
		#elif defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)
			ISR (USART0_RXC_vect) {
				uint8_t Tmp_Head;
				Tmp_Head = (Inf_Usart_Rx0_Buffer_Head + 1) & INF_USART_RX0_BUFFER_MASK;
				if (Tmp_Head != Inf_Usart_Rx0_Buffer_Tail) {
					Inf_Usart_Rx0_Buffer[Tmp_Head] = UDR0;
					Inf_Usart_Rx0_Buffer_Head = Tmp_Head;
				}
			}
		#elif defined(__AVR_ATmega48__) || defined(__AVR_ATmega88__) || defined(__AVR_ATmega168__)
			ISR (USART_RX_vect) {
				uint8_t Tmp_Head;
				Tmp_Head = (Inf_Usart_Rx0_Buffer_Head + 1) & INF_USART_RX0_BUFFER_MASK;
				if (Tmp_Head != Inf_Usart_Rx0_Buffer_Tail) {
					Inf_Usart_Rx0_Buffer[Tmp_Head] = UDR0;
					Inf_Usart_Rx0_Buffer_Head = Tmp_Head;
				}
			}
		#elif defined(__AVR_ATmega169P__)
			ISR (USART_RXC_vect) {
				uint8_t Tmp_Head;
				Tmp_Head = (Inf_Usart_Rx0_Buffer_Head + 1) & INF_USART_RX0_BUFFER_MASK;
				if (Tmp_Head != Inf_Usart_Rx0_Buffer_Tail) {
					Inf_Usart_Rx0_Buffer[Tmp_Head] = UDR0;
					Inf_Usart_Rx0_Buffer_Head = Tmp_Head;
				}
			}
		#elif defined(__AVR_ATmega644__)
			ISR (USART0_RX_vect) {
				uint8_t Tmp_Head;
				Tmp_Head = (Inf_Usart_Rx0_Buffer_Head + 1) & INF_USART_RX0_BUFFER_MASK;
				if (Tmp_Head != Inf_Usart_Rx0_Buffer_Tail) {
					Inf_Usart_Rx0_Buffer[Tmp_Head] = UDR0;
					Inf_Usart_Rx0_Buffer_Head = Tmp_Head;
				}
			}
		#elif defined(__AVR_AT90CAN32__) || defined(__AVR_AT90CAN64__) || defined(__AVR_AT90CAN128__)
			ISR (USART0_RXC_vect) {
				uint8_t Tmp_Head;
				Tmp_Head = (Inf_Usart_Rx0_Buffer_Head + 1) & INF_USART_RX0_BUFFER_MASK;
				if (Tmp_Head != Inf_Usart_Rx0_Buffer_Tail) {
					Inf_Usart_Rx0_Buffer[Tmp_Head] = UDR0;
					Inf_Usart_Rx0_Buffer_Head = Tmp_Head;
				}
			}
		#else
			#error "No definition for this MCU available."
		#endif
	#endif /* INF_USART0_RX */



	#if defined(INF_USART1_RX)
		#if defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)
			ISR (USART1_RXC_vect) {
				uint8_t Tmp_Head;
				Tmp_Head = (Inf_Usart_Rx1_Buffer_Head + 1) & INF_USART_RX1_BUFFER_MASK;
				if (Tmp_Head != Inf_Usart_Rx1_Buffer_Tail) {
					Inf_Usart_Rx1_Buffer[Tmp_Head] = UDR1;
					Inf_Usart_Rx1_Buffer_Head = Tmp_Head;
				}
			}
		#elif defined(__AVR_AT90CAN32__) || defined(__AVR_AT90CAN64__) || defined(__AVR_AT90CAN128__)
			ISR (USART1_RXC_vect) {
				uint8_t Tmp_Head;
				Tmp_Head = (Inf_Usart_Rx1_Buffer_Head + 1) & INF_USART_RX1_BUFFER_MASK;
				if (Tmp_Head != Inf_Usart_Rx1_Buffer_Tail) {
					Inf_Usart_Rx1_Buffer[Tmp_Head] = UDR1;
					Inf_Usart_Rx1_Buffer_Head = Tmp_Head;
				}
			}
		#else
			#error "No definition for this MCU available."
		#endif
	#endif /* INF_USART1_RX */



	#if defined(INF_USART0_TX) || defined(INF_USART1_TX)
		uint8_t Inf_Usart_Tx(const uint8_t aInf, const uint8_t * aChar) {
			uint8_t Result = FALSE;
			uint8_t Tmp_Head;
			switch (aInf) {
				#if defined(INF_USART0_TX)
					case 0:
						Tmp_Head = (Inf_Usart_Tx0_Buffer_Head + 1) & INF_USART_TX0_BUFFER_MASK;
						if (Tmp_Head != Inf_Usart_Tx0_Buffer_Tail) {
							Inf_Usart_Tx0_Buffer[Tmp_Head] = *aChar;
							Inf_Usart_Tx0_Buffer_Head = Tmp_Head;
							#if defined(__AVR_ATmega8__) || defined(__AVR_ATmega16__) || (__AVR_ATmega32__)
								UCSRB |= (1 << UDRIE);
								Result = TRUE;
							#elif defined(__AVR_ATmega64__) || (__AVR_ATmega128__)
								UCSR0B |= (1 << UDRIE);
								Result = TRUE;
							#elif defined(__AVR_ATmega48__) || defined(__AVR_ATmega88__) || (__AVR_ATmega168__)
								UCSR0B |= (1 << UDRIE0);
								Result = TRUE;
							#elif defined(__AVR_ATmega169P__)
								UCSR0B |= (1 << UDRIE0);
								Result = TRUE;
							#elif defined(__AVR_ATmega644__)
								UCSR0B |= (1 << UDRIE0);
								Result = TRUE;
							#elif defined(__AVR_AT90CAN32__) || defined(__AVR_AT90CAN64__) || defined(__AVR_AT90CAN128__)
								UCSR0B |= (1 << UDRIE0);
								Result = TRUE;
							#else
								#error "inf_usart.c -> Inf_Usart_Tx -> No definition for this MCU available."
							#endif
						}
						break;
				#endif /* INF_USART0_TX */
				#if defined(INF_USART1_TX)
					case 1:
						Tmp_Head = (Inf_Usart_Tx1_Buffer_Head + 1) & INF_USART_TX1_BUFFER_MASK;
						if (Tmp_Head != Inf_Usart_Tx1_Buffer_Tail) {
							Inf_Usart_Tx1_Buffer[Tmp_Head] = *aChar;
							Inf_Usart_Tx1_Buffer_Head = Tmp_Head;
							#if defined(__AVR_ATmega8__) || defined(__AVR_ATmega16__) || defined(__AVR_ATmega32__)
								#error "inf_usart.c -> Inf_Usart_Tx -> This MCU has only 1 USART."
							#elif defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)
								UCSR1B |= (1 << UDRIE);
								Result = TRUE;
							#elif defined(__AVR_ATmega48__) || defined(__AVR_ATmega88__) || defined(__AVR_ATmega168__)
								#error "inf_usart.c -> Inf_Usart_Tx -> This MCU has only 1 USART."
							#elif defined(__AVR_ATmega169P__)
								#error "inf_usart.c -> Inf_Usart_Tx -> This MCU has only 1 USART."
							#elif defined(__AVR_ATmega644__)
								#error "inf_usart.c -> Inf_Usart_Tx -> This MCU has only 1 USART."
							#elif defined(__AVR_AT90CAN32__) || defined(__AVR_AT90CAN64__) || defined(__AVR_AT90CAN128__)
								UCSR1B |= (1 << UDRIE1);
								Result = TRUE;
							#else
								#error "inf_usart.c -> Inf_Usart_Tx -> No definition for this MCU available."
							#endif
						}
						break;
				#endif /* INF_USART1_TX */
			}
			return Result;
		}

	#endif /* INF_USART0_TX || INF_USART1_TX */



	#if defined(INF_USART0_TX)
		#if defined(__AVR_ATmega8__) || defined(__AVR_ATmega16__) || (__AVR_ATmega32__)
			ISR (USART_UDRE_vect) {
				if (Inf_Usart_Tx0_Buffer_Head != Inf_Usart_Tx0_Buffer_Tail) {
					Inf_Usart_Tx0_Buffer_Tail = (Inf_Usart_Tx0_Buffer_Tail + 1) & INF_USART_TX0_BUFFER_MASK;
					UDR = Inf_Usart_Tx0_Buffer[Inf_Usart_Tx0_Buffer_Tail];
					UCSRA |= (1 << TXC);
				}
				else {
					UCSRB &= ~(1 << UDRIE);
				}
			}
		#elif defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)
			ISR (USART0_UDRE_vect) {
				if (Inf_Usart_Tx0_Buffer_Head != Inf_Usart_Tx0_Buffer_Tail) {
					Inf_Usart_Tx0_Buffer_Tail = (Inf_Usart_Tx0_Buffer_Tail + 1) & INF_USART_TX0_BUFFER_MASK;
					UDR0 = Inf_Usart_Tx0_Buffer[Inf_Usart_Tx0_Buffer_Tail];
					UCSR0A |= (1 << TXC0);
				}
				else {
					UCSR0B &= ~(1 << UDRIE);
				}
			}
		#elif defined(__AVR_ATmega48__) || defined(__AVR_ATmega88__) || defined(__AVR_ATmega168__)
			ISR (USART_UDRE_vect) {
				if (Inf_Usart_Tx0_Buffer_Head != Inf_Usart_Tx0_Buffer_Tail) {
					Inf_Usart_Tx0_Buffer_Tail = (Inf_Usart_Tx0_Buffer_Tail + 1) & INF_USART_TX0_BUFFER_MASK;
					UDR0 = Inf_Usart_Tx0_Buffer[Inf_Usart_Tx0_Buffer_Tail];
					UCSR0A |= (1 << TXC0);
				}
				else {
					UCSR0B &= ~(1 << UDRIE0);
				}
			}
		#elif defined(__AVR_ATmega169P__)
			ISR (USART_UDRE_vect) {
				if (Inf_Usart_Tx0_Buffer_Head != Inf_Usart_Tx0_Buffer_Tail) {
					Inf_Usart_Tx0_Buffer_Tail = (Inf_Usart_Tx0_Buffer_Tail + 1) & INF_USART_TX0_BUFFER_MASK;
					UDR0 = Inf_Usart_Tx0_Buffer[Inf_Usart_Tx0_Buffer_Tail];
					UCSR0A |= (1 << TXC0);
				}
				else {
					UCSR0B &= ~(1 << UDRIE0);
				}
			}
		#elif defined(__AVR_ATmega644__)
			ISR (USART0_UDRE_vect) {
				if (Inf_Usart_Tx0_Buffer_Head != Inf_Usart_Tx0_Buffer_Tail) {
					Inf_Usart_Tx0_Buffer_Tail = (Inf_Usart_Tx0_Buffer_Tail + 1) & INF_USART_TX0_BUFFER_MASK;
					UDR0 = Inf_Usart_Tx0_Buffer[Inf_Usart_Tx0_Buffer_Tail];
					UCSR0A |= (1 << TXC0);
				}
				else {
					UCSR0B &= ~(1 << UDRIE0);
				}
			}
		#elif defined(__AVR_AT90CAN32__) || defined(__AVR_AT90CAN64__) || defined(__AVR_AT90CAN128__)
			ISR (USART0_UDRE_vect) {
				if (Inf_Usart_Tx0_Buffer_Head != Inf_Usart_Tx0_Buffer_Tail) {
					Inf_Usart_Tx0_Buffer_Tail = (Inf_Usart_Tx0_Buffer_Tail + 1) & INF_USART_TX0_BUFFER_MASK;
					UDR0 = Inf_Usart_Tx0_Buffer[Inf_Usart_Tx0_Buffer_Tail];
					UCSR0A |= (1 << TXC0);
				}
				else {
					UCSR0B &= ~(1 << UDRIE0);
				}
			}
		#else
			#error "No definition for this MCU available."
		#endif
	#endif /* INF_USART0_TX */



	#if defined(INF_USART1_TX)
		#if defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)
			ISR (USART1_UDRE_vect) {
				if (Inf_Usart_Tx1_Buffer_Head != Inf_Usart_Tx1_Buffer_Tail) {
					Inf_Usart_Tx1_Buffer_Tail = (Inf_Usart_Tx1_Buffer_Tail + 1) & INF_USART_TX1_BUFFER_MASK;
					UDR1 = Inf_Usart_Tx1_Buffer[Inf_Usart_Tx1_Buffer_Tail];
					UCSR1A |= (1 << TXC1);
				}
				else {
					UCSR1B &= ~(1 << UDRIE1);
				}
			}
		#elif defined(__AVR_AT90CAN32__) || defined(__AVR_AT90CAN64__) || defined(__AVR_AT90CAN128__)
			ISR (USART1_UDRE_vect) {
				if (Inf_Usart_Tx1_Buffer_Head != Inf_Usart_Tx1_Buffer_Tail) {
					Inf_Usart_Tx1_Buffer_Tail = (Inf_Usart_Tx1_Buffer_Tail + 1) & INF_USART_TX1_BUFFER_MASK;
					UDR1 = Inf_Usart_Tx1_Buffer[Inf_Usart_Tx1_Buffer_Tail];
					UCSR1A |= (1 << TXC1);
				}
				else {
					UCSR1B &= ~(1 << UDRIE1);
				}
			}
		#else
			#error "No definition for this MCU available."
		#endif
	#endif /* INF_USART1_TX */



#endif /* ISB_INF_USART_C_ */
