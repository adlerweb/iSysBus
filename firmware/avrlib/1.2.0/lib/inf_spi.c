/**
 * @file		avrlib/trunk/lib/inf_spi.c
 *
 * @brief		Interface Spi.
 *
 * This file includes Interface Spi.
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





#ifndef INF_SPI_C_
	#define INF_SPI_C_



	void Inf_Spi_Init(const uint8_t aCfg) {
		// Bit 0	0=Disabled, 1=Enabled
		// Bit 1	0=Slave, 1=Master
		// Bit 2	DORD (Data Order)
		// Bit 3	CPOL (Clock Polarity)
		// Bit 4	CPHA (Clock Phase)
		// Bit 5	SPR0
		// Bit 6	SPR1
		// Bit 7	SPI2X
		SPCR &= ~(1 << SPE);
		if (bit_is_set(aCfg, 0)) {
			if (bit_is_set(aCfg, 1)) {
				INF_SPI_DDR |= (1 << INF_SPI_DD_MOSI) | (1 << INF_SPI_DD_SCK);
				INF_SPI_DDR &= ~(1 << INF_SPI_DD_MISO);
				SPCR |= (1 << MSTR);
			}
			else {
				INF_SPI_DDR |= (1 << INF_SPI_DD_MISO);
				INF_SPI_DDR &= ~(1 << INF_SPI_DD_MOSI) & ~(1 << INF_SPI_DD_SCK);
				SPCR &= ~(1 << MSTR);
			}
			SPCR |= (1 << SPE);
		}
		else {
			INF_SPI_DDR &= ~(1 << INF_SPI_DD_MISO) & ~(1 << INF_SPI_DD_MOSI) & ~(1 << INF_SPI_DD_SCK);
		}
	}



	uint8_t Inf_Spi_Rx(void) {
		SPDR = 0;
		loop_until_bit_is_set(SPSR, SPIF);
		return SPDR;
	}
 


	void Inf_Spi_Tx(const uint8_t Data) {
		SPDR = Data;
		loop_until_bit_is_set(SPSR, SPIF);
	}



	uint8_t Inf_Spi_TxRx(const uint8_t Data) {
		SPDR = Data;
		loop_until_bit_is_set(SPSR, SPIF);
		return SPDR;
	}



#endif /* INF_SPI_C_ */