/**
 * @file		avrlib/trunk/lib/inf_spi_def.h
 *
 * @brief		Interface Spi Defines.
 *
 * This file includes Interface Spi Defines.
 *
 * @author		© Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
 *
 * @date		$Date: 2012-05-03 16:09:41 +0200 (Do, 03. Mai 2012) $
 *
 * @version		$Rev: 7505 $
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





#ifndef INF_SPI_DEF_H_
	#define INF_SPI_DEF_H_



	#ifndef ISB
		#include <avr/io.h>
	#endif /* ISB */



	#if defined(__AVR_ATmega8__)
		#define INF_SPI_DDR								DDRB
		#define INF_SPI_DD_SCK							PB5
		#define INF_SPI_DD_MISO							PB4
		#define INF_SPI_DD_MOSI							PB3
		#define INF_SPI_DD_SS							PB2
		#define IF_SPI_PIN								PINB
		#define IF_SPI_PIN_SCK							PB5
		#define IF_SPI_PIN_MISO							PB4
		#define IF_SPI_PIN_MOSI							PB3
		#define IF_SPI_PIN_SS							PB2
	#elif defined(__AVR_ATmega16__)
		#define INF_SPI_DDR								DDRB
		#define INF_SPI_DD_SCK							PB7
		#define INF_SPI_DD_MISO							PB6
		#define INF_SPI_DD_MOSI							PB5
		#define INF_SPI_DD_SS							PB4
		#define IF_SPI_PIN								PINB
		#define IF_SPI_PIN_SCK							PB7
		#define IF_SPI_PIN_MISO							PB6
		#define IF_SPI_PIN_MOSI							PB5
		#define IF_SPI_PIN_SS							PB4
	#elif defined(__AVR_ATmega32__)
		#define INF_SPI_DDR								DDRB
		#define INF_SPI_DD_SCK							PB7
		#define INF_SPI_DD_MISO							PB6
		#define INF_SPI_DD_MOSI							PB5
		#define INF_SPI_DD_SS							PB4
		#define IF_SPI_PIN								PINB
		#define IF_SPI_PIN_SCK							PB7
		#define IF_SPI_PIN_MISO							PB6
		#define IF_SPI_PIN_MOSI							PB5
		#define IF_SPI_PIN_SS							PB4
	#elif defined(__AVR_ATmega64__)
		#define INF_SPI_DDR								DDRB
		#define INF_SPI_DD_SCK							PB1
		#define INF_SPI_DD_MISO							PB3
		#define INF_SPI_DD_MOSI							PB2
		#define INF_SPI_DD_SS							PB0
		#define IF_SPI_PIN								PINB
		#define IF_SPI_PIN_SCK							PB1
		#define IF_SPI_PIN_MISO							PB3
		#define IF_SPI_PIN_MOSI							PB2
		#define IF_SPI_PIN_SS							PB0
	#elif defined (__AVR_ATmega128__)
		#define INF_SPI_DDR								DRB
		#define INF_SPI_DD_SCK							PB1
		#define INF_SPI_DD_MISO							PB3
		#define INF_SPI_DD_MOSI							PB2
		#define INF_SPI_DD_SS							PB0
		#define IF_SPI_PIN								PINB
		#define IF_SPI_PIN_SCK							PB1
		#define IF_SPI_PIN_MISO							PB3
		#define IF_SPI_PIN_MOSI							PB2
		#define IF_SPI_PIN_SS							PB0
	#elif defined(__AVR_ATmega48__) || defined(__AVR_ATmega88__) || defined(__AVR_ATmega168__)
		#define INF_SPI_DDR								DDRB
		#define INF_SPI_DD_SCK							PB5
		#define INF_SPI_DD_MISO							PB4
		#define INF_SPI_DD_MOSI							PB3
		#define INF_SPI_DD_SS							PB2
		#define IF_SPI_PIN								PINB
		#define IF_SPI_PIN_SCK							PB5
		#define IF_SPI_PIN_MISO							PB4
		#define IF_SPI_PIN_MOSI							PB3
		#define IF_SPI_PIN_SS							PB2
	#elif defined(__AVR_ATmega169P__)
		#define INF_SPI_DDR								DDRB
		#define INF_SPI_DD_SCK							PB1
		#define INF_SPI_DD_MISO							PB3
		#define INF_SPI_DD_MOSI							PB2
		#define INF_SPI_DD_SS							PB0
		#define IF_SPI_PIN								PINB
		#define IF_SPI_PIN_SCK							PB1
		#define IF_SPI_PIN_MISO							PB3
		#define IF_SPI_PIN_MOSI							PB2
		#define IF_SPI_PIN_SS							PB0
	#elif defined(__AVR_ATmega644__)
		#define INF_SPI_DDR								DDRB
		#define INF_SPI_DD_SCK							PB7
		#define INF_SPI_DD_MISO							PB6
		#define INF_SPI_DD_MOSI							PB5
		#define INF_SPI_DD_SS							PB4
		#define IF_SPI_PIN								PINB
		#define IF_SPI_PIN_SCK							PB7
		#define IF_SPI_PIN_MISO							PB6
		#define IF_SPI_PIN_MOSI							PB5
		#define IF_SPI_PIN_SS							PB4
	#elif defined(__AVR_AT90CAN32__) || defined(__AVR_AT90CAN64__) || defined(__AVR_AT90CAN128__)
		#define INF_SPI_DDR								DDRB
		#define INF_SPI_DD_SCK							PB1
		#define INF_SPI_DD_MISO							PB3
		#define INF_SPI_DD_MOSI							PB2
		#define INF_SPI_DD_SS							PB0
		#define IF_SPI_PIN								PINB
		#define IF_SPI_PIN_SCK							PB1
		#define IF_SPI_PIN_MISO							PB3
		#define IF_SPI_PIN_MOSI							PB2
		#define IF_SPI_PIN_SS							PB0
	#else
		#error "No definition for this MCU available."
	#endif



#endif /* INF_SPI_DEF_H_ */
