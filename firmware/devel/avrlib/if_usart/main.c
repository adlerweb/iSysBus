/**
 * @file		fw/fw_0/trunk/main.c
 *
 * @brief		Firmware.
 *
 * This file includes the Firmware.
 *
 * @author		� Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
 *
 * @date		$Date$
 *
 * @version		$Rev$
 *
 * @note
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see http:*www.gnu.org/licenses.
 */





#include <stdio.h>
#include <avr/interrupt.h>



#define USE_AVRLIB_ISB

#define IF_USART0_RX
#define IF_USART0_RX_BUFFER_SIZE				64

#define IF_USART0_TX
#define IF_USART0_TX_BUFFER_SIZE				64



#include "trunk/lib/def.h"

#include "trunk/lib/if_usart_def.h"
#include "trunk/lib/if_usart.h"
#include "trunk/lib/if_usart.c"



int main(void)
{
	uint8_t Char = 0;
	if_usart__init(0, 115200, 8, NONE, 1);
//	if_usart__init(0, 9600, 8, NONE, 1);
	sei();
	while (1)
	{
		if_usart__exec();
		if (if_usart__rx(0, &Char) == TRUE)
		{
			if_usart__tx(0, &Char);
		}
	}
	return 0;
}
