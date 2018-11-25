/**
 * @file		avrlib/trunk/lib/inf_usart_def.h
 *
 * @brief		Interface Usart Defines.
 *
 * This file includes Interface Usart Defines.
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





#ifndef INF_USART_DEF_H_
	#define INF_USART_DEF_H_



	#if defined(INF_USART0_RX) || defined(INF_USART0_TX)
		#if F_CPU == 16000000 & INF_USART0_BAUDRATE == 115200 & INF_USART0_STARTBITS == 1 & INF_USART0_DATABITS == 8 & INF_USART0_PARITY == NONE & INF_USART0_STOPBITS == 1
			#if defined(__AVR_ATmega8__)
				#define INF_USART0_UBRRL						0x10
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X) | (1 << MPCM)
				#define INF_USART0_UCSRB						(1 << RXCIE) | (1 << UDRIE) | (1 << RXEN) | (1 << TXEN)
				#define INF_USART0_UCSRC						(1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0)
			#elif defined(__AVR_ATmega16__)
				#define INF_USART0_UBRRL						0x10
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X) | (1 << MPCM)
				#define INF_USART0_UCSRB						(1 << RXCIE) | (1 << UDRIE) | (1 << RXEN) | (1 << TXEN)
				#define INF_USART0_UCSRC						(1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0)
			#elif defined(__AVR_ATmega32__)
				#define INF_USART0_UBRRL						0x10
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X) | (1 << MPCM)
				#define INF_USART0_UCSRB						(1 << RXCIE) | (1 << UDRIE) | (1 << RXEN) | (1 << TXEN)
				#define INF_USART0_UCSRC						(1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0)
			#elif defined(__AVR_ATmega48__) | defined(__AVR_ATmega48V__)
				#define INF_USART0_UBRRL						0x10
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X0) | (1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_ATmega64__)
				#define INF_USART0_UBRRL						0x10
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X0) | (1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_ATmega88__) | defined(__AVR_ATmega88V__)
				#define INF_USART0_UBRRL						0x10
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X0) | (1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_ATmega128__)
				#define INF_USART0_UBRRL						0x10
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X0) | (1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_ATmega168__) | defined(__AVR_ATmega168V__)
				#define INF_USART0_UBRRL						0x10
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X0) | (1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_ATmega169P__) | defined(__AVR_ATmega169PV__)
				#define INF_USART0_UBRRL						0x10
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X0) | (1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_ATmega644__)
				#define INF_USART0_UBRRL						0x10
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X0) | (1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_AT90CAN32__)
				#define INF_USART0_UBRRL						0x10
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X0) | (1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_AT90CAN64__)
				#define INF_USART0_UBRRL						0x10
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X0) | (1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_AT90CAN128__)
				#define INF_USART0_UBRRL						0x10
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X0) | (1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#else
				#define INF_USART0_UBRRL						0
				#define INF_USART0_UBRRH						0
				#define INF_USART0_UCSRA						0
				#define INF_USART0_UCSRB						0
				#define INF_USART0_UCSRC						0
				#error "No definition for this MCU available."
			#endif
		#elif F_CPU == 14745600 & INF_USART0_BAUDRATE == 115200 & INF_USART0_STARTBITS == 1 & INF_USART0_DATABITS == 8 & INF_USART0_PARITY == NONE & INF_USART0_STOPBITS == 1
			#if defined(__AVR_ATmega8__)
				#define INF_USART0_UBRRL						0x0F
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X) | (1 << MPCM)
				#define INF_USART0_UCSRB						(1 << RXCIE) | (1 << UDRIE) | (1 << RXEN) | (1 << TXEN)
				#define INF_USART0_UCSRC						(1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0)
			#elif defined(__AVR_ATmega16__)
				#define INF_USART0_UBRRL						0x0F
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X) | (1 << MPCM)
				#define INF_USART0_UCSRB						(1 << RXCIE) | (1 << UDRIE) | (1 << RXEN) | (1 << TXEN)
				#define INF_USART0_UCSRC						(1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0)
			#elif defined(__AVR_ATmega32__)
				#define INF_USART0_UBRRL						0x0F
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X) | (1 << MPCM)
				#define INF_USART0_UCSRB						(1 << RXCIE) | (1 << UDRIE) | (1 << RXEN) | (1 << TXEN)
				#define INF_USART0_UCSRC						(1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0)
			#elif defined(__AVR_ATmega48__) | defined(__AVR_ATmega48V__)
				#define INF_USART0_UBRRL						0x0F
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X0) | (1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_ATmega64__)
				#define INF_USART0_UBRRL						0x0F
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X0) | (1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_ATmega88__) | defined(__AVR_ATmega88V__)
				#define INF_USART0_UBRRL						0x0F
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X0) | (1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_ATmega128__)
				#define INF_USART0_UBRRL						0x0F
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X0) | (1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_ATmega168__) | defined(__AVR_ATmega168V__)
				#define INF_USART0_UBRRL						0x0F
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X0) | (1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_ATmega169P__) | defined(__AVR_ATmega169PV__)
				#define INF_USART0_UBRRL						0x0F
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X0) | (1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_ATmega644__)
				#define INF_USART0_UBRRL						0x0F
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X0) | (1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_AT90CAN32__)
				#define INF_USART0_UBRRL						0x0F
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X0) | (1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_AT90CAN64__)
				#define INF_USART0_UBRRL						0x0F
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X0) | (1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_AT90CAN128__)
				#define INF_USART0_UBRRL						0x0F
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X0) | (1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#else
				#define INF_USART0_UBRRL						0
				#define INF_USART0_UBRRH						0
				#define INF_USART0_UCSRA						0
				#define INF_USART0_UCSRB						0
				#define INF_USART0_UCSRC						0
				#error "No definition for this MCU available."
			#endif
		#elif F_CPU == 8000000 & INF_USART0_BAUDRATE == 115200 & INF_USART0_STARTBITS == 1 & INF_USART0_DATABITS == 8 & INF_USART0_PARITY == NONE & INF_USART0_STOPBITS == 1
			#if defined(__AVR_ATmega8__)
				#define INF_USART0_UBRRL						0x07
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X) | (1 << MPCM)
				#define INF_USART0_UCSRB						(1 << RXCIE) | (1 << UDRIE) | (1 << RXEN) | (1 << TXEN)
				#define INF_USART0_UCSRC						(1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0)
			#elif defined(__AVR_ATmega16__)
				#define INF_USART0_UBRRL						0x07
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X) | (1 << MPCM)
				#define INF_USART0_UCSRB						(1 << RXCIE) | (1 << UDRIE) | (1 << RXEN) | (1 << TXEN)
				#define INF_USART0_UCSRC						(1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0)
			#elif defined(__AVR_ATmega32__)
				#define INF_USART0_UBRRL						0x07
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X) | (1 << MPCM)
				#define INF_USART0_UCSRB						(1 << RXCIE) | (1 << UDRIE) | (1 << RXEN) | (1 << TXEN)
				#define INF_USART0_UCSRC						(1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0)
			#elif defined(__AVR_ATmega48__) | defined(__AVR_ATmega48V__)
				#define INF_USART0_UBRRL						0x07
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X0) | (1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_ATmega64__)
				#define INF_USART0_UBRRL						0x07
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X0) | (1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_ATmega88__) | defined(__AVR_ATmega88V__)
				#define INF_USART0_UBRRL						0x07
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X0) | (1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_ATmega128__)
				#define INF_USART0_UBRRL						0x07
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X0) | (1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_ATmega168__) | defined(__AVR_ATmega168V__)
				#define INF_USART0_UBRRL						0x07
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X0) | (1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_ATmega169P__) | defined(__AVR_ATmega169PV__)
				#define INF_USART0_UBRRL						0x07
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X0) | (1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_ATmega644__)
				#define INF_USART0_UBRRL						0x07
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X0) | (1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_AT90CAN32__)
				#define INF_USART0_UBRRL						0x07
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X0) | (1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_AT90CAN64__)
				#define INF_USART0_UBRRL						0x07
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X0) | (1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_AT90CAN128__)
				#define INF_USART0_UBRRL						0x07
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << U2X0) | (1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#else
				#define INF_USART0_UBRRL						0
				#define INF_USART0_UBRRH						0
				#define INF_USART0_UCSRA						0
				#define INF_USART0_UCSRB						0
				#define INF_USART0_UCSRC						0
				#error "No definition for this MCU available."
			#endif
		#elif F_CPU == 8000000 & INF_USART0_BAUDRATE == 9600 & INF_USART0_STARTBITS == 1 & INF_USART0_DATABITS == 8 & INF_USART0_PARITY == NONE & INF_USART0_STOPBITS == 1
			#if defined(__AVR_ATmega8__)
				#define INF_USART0_UBRRL						0x33
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << MPCM)
				#define INF_USART0_UCSRB						(1 << RXCIE) | (1 << UDRIE) | (1 << RXEN) | (1 << TXEN)
				#define INF_USART0_UCSRC						(1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0)
			#elif defined(__AVR_ATmega16__)
				#define INF_USART0_UBRRL						0x33
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << MPCM)
				#define INF_USART0_UCSRB						(1 << RXCIE) | (1 << UDRIE) | (1 << RXEN) | (1 << TXEN)
				#define INF_USART0_UCSRC						(1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0)
			#elif defined(__AVR_ATmega32__)
				#define INF_USART0_UBRRL						0x33
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << MPCM)
				#define INF_USART0_UCSRB						(1 << RXCIE) | (1 << UDRIE) | (1 << RXEN) | (1 << TXEN)
				#define INF_USART0_UCSRC						(1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0)
			#elif defined(__AVR_ATmega48__) | defined(__AVR_ATmega48V__)
				#define INF_USART0_UBRRL						0x33
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_ATmega64__)
				#define INF_USART0_UBRRL						0x33
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_ATmega88__) | defined(__AVR_ATmega88V__)
				#define INF_USART0_UBRRL						0x33
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_ATmega128__)
				#define INF_USART0_UBRRL						0x33
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_ATmega168__) | defined(__AVR_ATmega168V__)
				#define INF_USART0_UBRRL						0x33
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_ATmega169P__) | defined(__AVR_ATmega169PV__)
				#define INF_USART0_UBRRL						0x33
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_ATmega644__)
				#define INF_USART0_UBRRL						0x33
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_AT90CAN32__)
				#define INF_USART0_UBRRL						0x33
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_AT90CAN64__)
				#define INF_USART0_UBRRL						0x33
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#elif defined(__AVR_AT90CAN128__)
				#define INF_USART0_UBRRL						0x33
				#define INF_USART0_UBRRH						0x00
				#define INF_USART0_UCSRA						(1 << MPCM0)
				#define INF_USART0_UCSRB						(1 << RXCIE0) | (1 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0)
				#define INF_USART0_UCSRC						(1 << UCSZ01) | (1 << UCSZ00)
			#else
				#define INF_USART0_UBRRL						0
				#define INF_USART0_UBRRH						0
				#define INF_USART0_UCSRA						0
				#define INF_USART0_UCSRB						0
				#define INF_USART0_UCSRC						0
				#error "No definition for this MCU available."
			#endif
		#else
			#define INF_USART0_UBRRL						0
			#define INF_USART0_UBRRH						0
			#define INF_USART0_UCSRA						0
			#define INF_USART0_UCSRB						0
			#define INF_USART0_UCSRC						0
			#error "F_CPU | INF_USART0_BAUDRATE | INF_USART0_STARTBITS | INF_USART0_DATABITS | INF_USART0_PARITY | INF_USART0_STOPBITS"
		#endif
	#endif /* INF_USART0_RX || INF_USART0_TX */



	#if defined(INF_USART1_RX) || defined(INF_USART1_TX)
		#if F_CPU == 16000000 & INF_USART1_BAUDRATE == 115200 & INF_USART1_STARTBITS == 1 & INF_USART1_DATABITS == 8 & INF_USART1_PARITY == NONE & INF_USART1_STOPBITS == 1
			#if defined(__AVR_ATmega8__)
				#define INF_USART1_UBRRL						0
				#define INF_USART1_UBRRH						0
				#define INF_USART1_UCSRA						0
				#define INF_USART1_UCSRB						0
				#define INF_USART1_UCSRC						0
				#error "This MCU has only 1 USART."
			#elif defined(__AVR_ATmega16__)
				#define INF_USART1_UBRRL						0
				#define INF_USART1_UBRRH						0
				#define INF_USART1_UCSRA						0
				#define INF_USART1_UCSRB						0
				#define INF_USART1_UCSRC						0
				#error "This MCU has only 1 USART."
			#elif defined(__AVR_ATmega32__)
				#define INF_USART1_UBRRL						0
				#define INF_USART1_UBRRH						0
				#define INF_USART1_UCSRA						0
				#define INF_USART1_UCSRB						0
				#define INF_USART1_UCSRC						0
				#error "This MCU has only 1 USART."
			#elif defined(__AVR_ATmega48__) | defined(__AVR_ATmega48V__)
				#define INF_USART1_UBRRL						0
				#define INF_USART1_UBRRH						0
				#define INF_USART1_UCSRA						0
				#define INF_USART1_UCSRB						0
				#define INF_USART1_UCSRC						0
				#error "This MCU has only 1 USART."
			#elif defined(__AVR_ATmega64__)
				#define INF_USART1_UBRRL						0x10
				#define INF_USART1_UBRRH						0x00
				#define INF_USART1_UCSRA						(1 << U2X1) | (1 << MPCM1)
				#define INF_USART1_UCSRB						(1 << RXCIE1) | (1 << UDRIE1) | (1 << RXEN1) | (1 << TXEN1)
				#define INF_USART1_UCSRC						(1 << UCSZ11) | (1 << UCSZ10)
			#elif defined(__AVR_ATmega88__) | defined(__AVR_ATmega88V__)
				#define INF_USART1_UBRRL						0
				#define INF_USART1_UBRRH						0
				#define INF_USART1_UCSRA						0
				#define INF_USART1_UCSRB						0
				#define INF_USART1_UCSRC						0
				#error "This MCU has only 1 USART."
			#elif defined(__AVR_ATmega128__)
				#define INF_USART1_UBRRL						0x10
				#define INF_USART1_UBRRH						0x00
				#define INF_USART1_UCSRA						(1 << U2X1) | (1 << MPCM1)
				#define INF_USART1_UCSRB						(1 << RXCIE1) | (1 << UDRIE1) | (1 << RXEN1) | (1 << TXEN1)
				#define INF_USART1_UCSRC						(1 << UCSZ11) | (1 << UCSZ10)
			#elif defined(__AVR_ATmega168__) | defined(__AVR_ATmega168V__)
				#define INF_USART1_UBRRL						0
				#define INF_USART1_UBRRH						0
				#define INF_USART1_UCSRA						0
				#define INF_USART1_UCSRB						0
				#define INF_USART1_UCSRC						0
				#error "This MCU has only 1 USART."
			#elif defined(__AVR_ATmega169P__) | defined(__AVR_ATmega169PV__)
				#define INF_USART1_UBRRL						0
				#define INF_USART1_UBRRH						0
				#define INF_USART1_UCSRA						0
				#define INF_USART1_UCSRB						0
				#define INF_USART1_UCSRC						0
				#error "This MCU has only 1 USART."
			#elif defined(__AVR_ATmega644__)
				#define INF_USART1_UBRRL						0
				#define INF_USART1_UBRRH						0
				#define INF_USART1_UCSRA						0
				#define INF_USART1_UCSRB						0
				#define INF_USART1_UCSRC						0
				#error "This MCU has only 1 USART."
			#elif defined(__AVR_AT90CAN32__)
				#define INF_USART1_UBRRL						0x10
				#define INF_USART1_UBRRH						0x00
				#define INF_USART1_UCSRA						(1 << U2X1) | (1 << MPCM1)
				#define INF_USART1_UCSRB						(1 << RXCIE1) | (1 << UDRIE1) | (1 << RXEN1) | (1 << TXEN1)
				#define INF_USART1_UCSRC						(1 << UCSZ11) | (1 << UCSZ10)
			#elif defined(__AVR_AT90CAN64__)
				#define INF_USART1_UBRRL						0x10
				#define INF_USART1_UBRRH						0x00
				#define INF_USART1_UCSRA						(1 << U2X1) | (1 << MPCM1)
				#define INF_USART1_UCSRB						(1 << RXCIE1) | (1 << UDRIE1) | (1 << RXEN1) | (1 << TXEN1)
				#define INF_USART1_UCSRC						(1 << UCSZ11) | (1 << UCSZ10)
			#elif defined(__AVR_AT90CAN128__)
				#define INF_USART1_UBRRL						0x10
				#define INF_USART1_UBRRH						0x00
				#define INF_USART1_UCSRA						(1 << U2X1) | (1 << MPCM1)
				#define INF_USART1_UCSRB						(1 << RXCIE1) | (1 << UDRIE1) | (1 << RXEN1) | (1 << TXEN1)
				#define INF_USART1_UCSRC						(1 << UCSZ11) | (1 << UCSZ10)
			#else
				#define INF_USART1_UBRRL						0
				#define INF_USART1_UBRRH						0
				#define INF_USART1_UCSRA						0
				#define INF_USART1_UCSRB						0
				#define INF_USART1_UCSRC						0
				#error "No definition for this MCU available."
			#endif
		#elif F_CPU == 14745600 & INF_USART1_BAUDRATE == 115200 & INF_USART1_STARTBITS == 1 & INF_USART1_DATABITS == 8 & INF_USART1_PARITY == NONE & INF_USART1_STOPBITS == 1
			#if defined(__AVR_ATmega8__)
				#define INF_USART1_UBRRL						0
				#define INF_USART1_UBRRH						0
				#define INF_USART1_UCSRA						0
				#define INF_USART1_UCSRB						0
				#define INF_USART1_UCSRC						0
				#error "This MCU has only 1 USART."
			#elif defined(__AVR_ATmega16__)
				#define INF_USART1_UBRRL						0
				#define INF_USART1_UBRRH						0
				#define INF_USART1_UCSRA						0
				#define INF_USART1_UCSRB						0
				#define INF_USART1_UCSRC						0
				#error "This MCU has only 1 USART."
			#elif defined(__AVR_ATmega32__)
				#define INF_USART1_UBRRL						0
				#define INF_USART1_UBRRH						0
				#define INF_USART1_UCSRA						0
				#define INF_USART1_UCSRB						0
				#define INF_USART1_UCSRC						0
				#error "This MCU has only 1 USART."
			#elif defined(__AVR_ATmega48__) | defined(__AVR_ATmega48V__)
				#define INF_USART1_UBRRL						0
				#define INF_USART1_UBRRH						0
				#define INF_USART1_UCSRA						0
				#define INF_USART1_UCSRB						0
				#define INF_USART1_UCSRC						0
				#error "This MCU has only 1 USART."
			#elif defined(__AVR_ATmega64__)
				#define INF_USART1_UBRRL						0x0F
				#define INF_USART1_UBRRH						0x00
				#define INF_USART1_UCSRA						(1 << U2X1) | (1 << MPCM1)
				#define INF_USART1_UCSRB						(1 << RXCIE1) | (1 << UDRIE1) | (1 << RXEN1) | (1 << TXEN1)
				#define INF_USART1_UCSRC						(1 << UCSZ11) | (1 << UCSZ10)
			#elif defined(__AVR_ATmega88__) | defined(__AVR_ATmega88V__)
				#define INF_USART1_UBRRL						0
				#define INF_USART1_UBRRH						0
				#define INF_USART1_UCSRA						0
				#define INF_USART1_UCSRB						0
				#define INF_USART1_UCSRC						0
				#error "This MCU has only 1 USART."
			#elif defined(__AVR_ATmega128__)
				#define INF_USART1_UBRRL						0x0F
				#define INF_USART1_UBRRH						0x00
				#define INF_USART1_UCSRA						(1 << U2X1) | (1 << MPCM1)
				#define INF_USART1_UCSRB						(1 << RXCIE1) | (1 << UDRIE1) | (1 << RXEN1) | (1 << TXEN1)
				#define INF_USART1_UCSRC						(1 << UCSZ11) | (1 << UCSZ10)
			#elif defined(__AVR_ATmega168__) | defined(__AVR_ATmega168V__)
				#define INF_USART1_UBRRL						0
				#define INF_USART1_UBRRH						0
				#define INF_USART1_UCSRA						0
				#define INF_USART1_UCSRB						0
				#define INF_USART1_UCSRC						0
				#error "This MCU has only 1 USART."
			#elif defined(__AVR_ATmega169P__) | defined(__AVR_ATmega169PV__)
				#define INF_USART1_UBRRL						0
				#define INF_USART1_UBRRH						0
				#define INF_USART1_UCSRA						0
				#define INF_USART1_UCSRB						0
				#define INF_USART1_UCSRC						0
				#error "This MCU has only 1 USART."
			#elif defined(__AVR_ATmega644__)
				#define INF_USART1_UBRRL						0
				#define INF_USART1_UBRRH						0
				#define INF_USART1_UCSRA						0
				#define INF_USART1_UCSRB						0
				#define INF_USART1_UCSRC						0
				#error "This MCU has only 1 USART."
			#elif defined(__AVR_AT90CAN32__)
				#define INF_USART1_UBRRL						0x0F
				#define INF_USART1_UBRRH						0x00
				#define INF_USART1_UCSRA						(1 << U2X1) | (1 << MPCM1)
				#define INF_USART1_UCSRB						(1 << RXCIE1) | (1 << UDRIE1) | (1 << RXEN1) | (1 << TXEN1)
				#define INF_USART1_UCSRC						(1 << UCSZ11) | (1 << UCSZ10)
			#elif defined(__AVR_AT90CAN64__)
				#define INF_USART1_UBRRL						0x0F
				#define INF_USART1_UBRRH						0x00
				#define INF_USART1_UCSRA						(1 << U2X1) | (1 << MPCM1)
				#define INF_USART1_UCSRB						(1 << RXCIE1) | (1 << UDRIE1) | (1 << RXEN1) | (1 << TXEN1)
				#define INF_USART1_UCSRC						(1 << UCSZ11) | (1 << UCSZ10)
			#elif defined(__AVR_AT90CAN128__)
				#define INF_USART1_UBRRL						0x0F
				#define INF_USART1_UBRRH						0x00
				#define INF_USART1_UCSRA						(1 << U2X1) | (1 << MPCM1)
				#define INF_USART1_UCSRB						(1 << RXCIE1) | (1 << UDRIE1) | (1 << RXEN1) | (1 << TXEN1)
				#define INF_USART1_UCSRC						(1 << UCSZ11) | (1 << UCSZ10)
			#else
				#define INF_USART1_UBRRL						0
				#define INF_USART1_UBRRH						0
				#define INF_USART1_UCSRA						0
				#define INF_USART1_UCSRB						0
				#define INF_USART1_UCSRC						0
				#error "No definition for this MCU available."
			#endif
		#else
			#define INF_USART1_UBRRL						0
			#define INF_USART1_UBRRH						0
			#define INF_USART1_UCSRA						0
			#define INF_USART1_UCSRB						0
			#define INF_USART1_UCSRC						0
			#error "F_CPU | INF_USART1_BAUDRATE | INF_USART1_STARTBITS | INF_USART1_DATABITS | INF_USART1_PARITY | INF_USART1_STOPBITS"
		#endif
	#endif /* INF_USART1_RX || INF_USART1_TX */



#endif /* INF_USART_DEF_H_ */
