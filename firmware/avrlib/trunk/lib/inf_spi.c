/**
 * @file		avrlib/trunk/lib/inf_spi.c
 *
 * @brief		Interface Spi.
 *
 * This file includes Interface Spi.
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





#ifndef INF_SPI_C_
	#define INF_SPI_C_



	#ifndef ISYSBUS_LIB
		#include "inf_spi_def.h"
		#include "inf_spi.h"
	#endif /* ISYSBUS_LIB */



	void Inf_Spi_Init(const unsigned char aCfg)
	{

		if (bit_is_set(aCfg, SPE))
		{
			if (bit_is_set(aCfg, MSTR))
			{
				INF_SPI_DDR |= (1 << INF_SPI_DD_MOSI) | (1 << INF_SPI_DD_SCK);
				INF_SPI_DDR &= ~(1 << INF_SPI_DD_MISO);
			}
			else
			{
				INF_SPI_DDR |= (1 << INF_SPI_DD_MISO);
				INF_SPI_DDR &= ~(1 << INF_SPI_DD_MOSI) & ~(1 << INF_SPI_DD_SCK);
			}
		}
		else
		{
			INF_SPI_DDR &= ~(1 << INF_SPI_DD_MISO) & ~(1 << INF_SPI_DD_MOSI) & ~(1 << INF_SPI_DD_SCK);
		}

		SPCR = aCfg;
		SPSR = 0;

	}



	unsigned char Inf_Spi_Rx(void)
	{

		SPDR = 0;
		loop_until_bit_is_set(SPSR, SPIF);
		return SPDR;

	}
 


	void Inf_Spi_Tx(const unsigned char Data)
	{

		SPDR = Data;
		loop_until_bit_is_set(SPSR, SPIF);

	}



	unsigned char Inf_Spi_TxRx(const unsigned char Data)
	{

		SPDR = Data;
		loop_until_bit_is_set(SPSR, SPIF);
		return SPDR;

	}



#endif /* INF_SPI_C_ */
