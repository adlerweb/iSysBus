/**
 * @file		avrlib/trunk/core/isb_bl.h
 *
 * @brief		iSysBus Bootloader-Core.
 *
 * This file includes the iSysBus bootloader-core.
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





#ifndef ISB_BL_H_
	#define ISB_BL_H_



	#include <avr/boot.h>
	#include <avr/pgmspace.h>
	#include <avr/eeprom.h>
	#include <util/delay.h>
	#include <avr/wdt.h>
	#include <string.h>



	#include "./../lib/def.h"
	#include "./../lib/isb_def.h"
	#include "./../lib/isb_typ.h"
	#include "./../lib/isb_eep_def.h"
	#include "./../lib/isb_config_def.h"



	#define PORTA_PIN0								1
	#define PORTA_PIN1								2
	#define PORTA_PIN2								3
	#define PORTA_PIN3								4
	#define PORTA_PIN4								5
	#define PORTA_PIN5								6
	#define PORTA_PIN6								7
	#define PORTA_PIN7								8

	#define PORTB_PIN0								9
	#define PORTB_PIN1								10
	#define PORTB_PIN2								11
	#define PORTB_PIN3								12
	#define PORTB_PIN4								13
	#define PORTB_PIN5								14
	#define PORTB_PIN6								15
	#define PORTB_PIN7								16

	#define PORTC_PIN0								17
	#define PORTC_PIN1								18
	#define PORTC_PIN2								19
	#define PORTC_PIN3								20
	#define PORTC_PIN4								21
	#define PORTC_PIN5								22
	#define PORTC_PIN6								23
	#define PORTC_PIN7								24

	#define PORTD_PIN0								25
	#define PORTD_PIN1								26
	#define PORTD_PIN2								27
	#define PORTD_PIN3								28
	#define PORTD_PIN4								29
	#define PORTD_PIN5								30
	#define PORTD_PIN6								31
	#define PORTD_PIN7								32

	#define PORTE_PIN0								33
	#define PORTE_PIN1								34
	#define PORTE_PIN2								35
	#define PORTE_PIN3								36
	#define PORTE_PIN4								37
	#define PORTE_PIN5								38
	#define PORTE_PIN6								39
	#define PORTE_PIN7								40

	#define PORTF_PIN0								41
	#define PORTF_PIN1								42
	#define PORTF_PIN2								43
	#define PORTF_PIN3								44
	#define PORTF_PIN4								45
	#define PORTF_PIN5								46
	#define PORTF_PIN6								47
	#define PORTF_PIN7								48

	#define PORTG_PIN0								49
	#define PORTG_PIN1								50
	#define PORTG_PIN2								51
	#define PORTG_PIN3								52
	#define PORTG_PIN4								53
	#define PORTG_PIN5								54
	#define PORTG_PIN6								55
	#define PORTG_PIN7								56

	#define PORTH_PIN0								57
	#define PORTH_PIN1								58
	#define PORTH_PIN2								59
	#define PORTH_PIN3								60
	#define PORTH_PIN4								61
	#define PORTH_PIN5								62
	#define PORTH_PIN6								63
	#define PORTH_PIN7								64

	#define MCP2515_RX0BF							128
	#define MCP2515_RX1BF							129



	#define INTERRUPT0								0
	#define INTERRUPT1								1
	#define INTERRUPT2								2
	#define INTERRUPT3								3
	#define INTERRUPT4								4
	#define INTERRUPT5								5
	#define INTERRUPT6								6
	#define INTERRUPT7								7



#endif /* ISB_BL_H_ */
