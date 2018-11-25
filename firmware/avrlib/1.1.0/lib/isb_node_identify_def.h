/**
 * @file		avrlib/trunk/lib/isb_node_identify_def.h
 *
 * @brief		iSysBus Node Identify Defines.
 *
 * This file includes iSysBus Node Identify Defines.
 *
 * @author		© Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
 *
 * @date		$Date: 2010-05-29 01:02:58 +0200 (Sa, 29 Mai 2010) $
 *
 * @version		$Rev: 3919 $
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





#ifndef ISB_NODE_IDENTIFY_DEF_H_
	#define ISB_NODE_IDENTIFY_DEF_H_



	#if ISB_NODE_IDENTIFY == NONE
	#elif ISB_NODE_IDENTIFY == PORTA_PIN0
		#define ISB_NODE_IDENTIFY_INIT					DDRA &= ~(1 << DDA0)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTA |= (1 << PA0)
		#define ISB_NODE_IDENTIFY_REGISTER				PINA
		#define ISB_NODE_IDENTIFY_BIT					PA0
	#elif ISB_NODE_IDENTIFY == PORTA_PIN1
		#define ISB_NODE_IDENTIFY_INIT					DDRA &= ~(1 << DDA1)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTA |= (1 << PA1)
		#define ISB_NODE_IDENTIFY_REGISTER				PINA
		#define ISB_NODE_IDENTIFY_BIT					PA1
	#elif ISB_NODE_IDENTIFY == PORTA_PIN0
		#define ISB_NODE_IDENTIFY_INIT					DDRA &= ~(1 << DDA2)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTA |= (1 << PA2)
		#define ISB_NODE_IDENTIFY_REGISTER				PINA
		#define ISB_NODE_IDENTIFY_BIT					PA2
	#elif ISB_NODE_IDENTIFY == PORTA_PIN3
		#define ISB_NODE_IDENTIFY_INIT					DDRA &= ~(1 << DDA3)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTA |= (1 << PA3)
		#define ISB_NODE_IDENTIFY_REGISTER				PINA
		#define ISB_NODE_IDENTIFY_BIT					PA3
	#elif ISB_NODE_IDENTIFY == PORTA_PIN4
		#define ISB_NODE_IDENTIFY_INIT					DDRA &= ~(1 << DDA4)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTA |= (1 << PA4)
		#define ISB_NODE_IDENTIFY_REGISTER				PINA
		#define ISB_NODE_IDENTIFY_BIT					PA4
	#elif ISB_NODE_IDENTIFY == PORTA_PIN5
		#define ISB_NODE_IDENTIFY_INIT					DDRA &= ~(1 << DDA5)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTA |= (1 << PA5)
		#define ISB_NODE_IDENTIFY_REGISTER				PINA
		#define ISB_NODE_IDENTIFY_BIT					PA5
	#elif ISB_NODE_IDENTIFY == PORTA_PIN6
		#define ISB_NODE_IDENTIFY_INIT					DDRA &= ~(1 << DDA6)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTA |= (1 << PA6)
		#define ISB_NODE_IDENTIFY_REGISTER				PINA
		#define ISB_NODE_IDENTIFY_BIT					PA6
	#elif ISB_NODE_IDENTIFY == PORTA_PIN7
		#define ISB_NODE_IDENTIFY_INIT					DDRA &= ~(1 << DDA7)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTA |= (1 << PA7)
		#define ISB_NODE_IDENTIFY_REGISTER				PINA
		#define ISB_NODE_IDENTIFY_BIT					PA7
	#elif ISB_NODE_IDENTIFY == PORTB_PIN0
		#define ISB_NODE_IDENTIFY_INIT					DDRB &= ~(1 << DDB0)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTB |= (1 << PB0)
		#define ISB_NODE_IDENTIFY_REGISTER				PINB
		#define ISB_NODE_IDENTIFY_BIT					PB0
	#elif ISB_NODE_IDENTIFY == PORTB_PIN1
		#define ISB_NODE_IDENTIFY_INIT					DDRB &= ~(1 << DDB1)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTB |= (1 << PB1)
		#define ISB_NODE_IDENTIFY_REGISTER				PINB
		#define ISB_NODE_IDENTIFY_BIT					PB1
	#elif ISB_NODE_IDENTIFY == PORTB_PIN2
		#define ISB_NODE_IDENTIFY_INIT					DDRB &= ~(1 << DDB2)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTB |= (1 << PB2)
		#define ISB_NODE_IDENTIFY_REGISTER				PINB
		#define ISB_NODE_IDENTIFY_BIT					PB2
	#elif ISB_NODE_IDENTIFY == PORTB_PIN3
		#define ISB_NODE_IDENTIFY_INIT					DDRB &= ~(1 << DDB3)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTB |= (1 << PB3)
		#define ISB_NODE_IDENTIFY_REGISTER				PINB
		#define ISB_NODE_IDENTIFY_BIT					PB3
	#elif ISB_NODE_IDENTIFY == PORTB_PIN4
		#define ISB_NODE_IDENTIFY_INIT					DDRB &= ~(1 << DDB4)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTB |= (1 << PB4)
		#define ISB_NODE_IDENTIFY_REGISTER				PINB
		#define ISB_NODE_IDENTIFY_BIT					PB4
	#elif ISB_NODE_IDENTIFY == PORTB_PIN5
		#define ISB_NODE_IDENTIFY_INIT					DDRB &= ~(1 << DDB5)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTB |= (1 << PB5)
		#define ISB_NODE_IDENTIFY_REGISTER				PINB
		#define ISB_NODE_IDENTIFY_BIT					PB5
	#elif ISB_NODE_IDENTIFY == PORTB_PIN6
		#define ISB_NODE_IDENTIFY_INIT					DDRB &= ~(1 << DDB6)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTB |= (1 << PB6)
		#define ISB_NODE_IDENTIFY_REGISTER				PINB
		#define ISB_NODE_IDENTIFY_BIT					PB6
	#elif ISB_NODE_IDENTIFY == PORTB_PIN7
		#define ISB_NODE_IDENTIFY_INIT					DDRB &= ~(1 << DDB7)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTB |= (1 << PB7)
		#define ISB_NODE_IDENTIFY_REGISTER				PINB
		#define ISB_NODE_IDENTIFY_BIT					PB7
	#elif ISB_NODE_IDENTIFY == PORTC_PIN0
		#define ISB_NODE_IDENTIFY_INIT					DDRC &= ~(1 << DDC0)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTC |= (1 << PC0)
		#define ISB_NODE_IDENTIFY_REGISTER				PINC
		#define ISB_NODE_IDENTIFY_BIT					PC0
	#elif ISB_NODE_IDENTIFY == PORTC_PIN1
		#define ISB_NODE_IDENTIFY_INIT					DDRC &= ~(1 << DDC1)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTC |= (1 << PC1)
		#define ISB_NODE_IDENTIFY_REGISTER				PINC
		#define ISB_NODE_IDENTIFY_BIT					PC1
	#elif ISB_NODE_IDENTIFY == PORTC_PIN2
		#define ISB_NODE_IDENTIFY_INIT					DDRC &= ~(1 << DDC2)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTC |= (1 << PC2)
		#define ISB_NODE_IDENTIFY_REGISTER				PINC
		#define ISB_NODE_IDENTIFY_BIT					PC2
	#elif ISB_NODE_IDENTIFY == PORTC_PIN3
		#define ISB_NODE_IDENTIFY_INIT					DDRC &= ~(1 << DDC3)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTC |= (1 << PC3)
		#define ISB_NODE_IDENTIFY_REGISTER				PINC
		#define ISB_NODE_IDENTIFY_BIT					PC3
	#elif ISB_NODE_IDENTIFY == PORTC_PIN4
		#define ISB_NODE_IDENTIFY_INIT					DDRC &= ~(1 << DDC4)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTC |= (1 << PC4)
		#define ISB_NODE_IDENTIFY_REGISTER				PINC
		#define ISB_NODE_IDENTIFY_BIT					PC4
	#elif ISB_NODE_IDENTIFY == PORTC_PIN5
		#define ISB_NODE_IDENTIFY_INIT					DDRC &= ~(1 << DDC5)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTC |= (1 << PC5)
		#define ISB_NODE_IDENTIFY_REGISTER				PINC
		#define ISB_NODE_IDENTIFY_BIT					PC5
	#elif ISB_NODE_IDENTIFY == PORTC_PIN6
		#define ISB_NODE_IDENTIFY_INIT					DDRC &= ~(1 << DDC6)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTC |= (1 << PC6)
		#define ISB_NODE_IDENTIFY_REGISTER				PINC
		#define ISB_NODE_IDENTIFY_BIT					PC6
	#elif ISB_NODE_IDENTIFY == PORTC_PIN7
		#define ISB_NODE_IDENTIFY_INIT					DDRC &= ~(1 << DDC7)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTC |= (1 << PC7)
		#define ISB_NODE_IDENTIFY_REGISTER				PINC
		#define ISB_NODE_IDENTIFY_BIT					PC7
	#elif ISB_NODE_IDENTIFY == PORTD_PIN0
		#define ISB_NODE_IDENTIFY_INIT					DDRD &= ~(1 << DDD0)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTD |= (1 << PD0)
		#define ISB_NODE_IDENTIFY_REGISTER				PIND
		#define ISB_NODE_IDENTIFY_BIT					PD0
	#elif ISB_NODE_IDENTIFY == PORTD_PIN1
		#define ISB_NODE_IDENTIFY_INIT					DDRD &= ~(1 << DDD1)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTD |= (1 << PD1)
		#define ISB_NODE_IDENTIFY_REGISTER				PIND
		#define ISB_NODE_IDENTIFY_BIT					PD1
	#elif ISB_NODE_IDENTIFY == PORTD_PIN2
		#define ISB_NODE_IDENTIFY_INIT					DDRD &= ~(1 << DDD2)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTD |= (1 << PD2)
		#define ISB_NODE_IDENTIFY_REGISTER				PIND
		#define ISB_NODE_IDENTIFY_BIT					PD2
	#elif ISB_NODE_IDENTIFY == PORTD_PIN3
		#define ISB_NODE_IDENTIFY_INIT					DDRD &= ~(1 << DDD3)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTD |= (1 << PD3)
		#define ISB_NODE_IDENTIFY_REGISTER				PIND
		#define ISB_NODE_IDENTIFY_BIT					PD3
	#elif ISB_NODE_IDENTIFY == PORTD_PIN4
		#define ISB_NODE_IDENTIFY_INIT					DDRD &= ~(1 << DDD4)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTD |= (1 << PD4)
		#define ISB_NODE_IDENTIFY_REGISTER				PIND
		#define ISB_NODE_IDENTIFY_BIT					PD4
	#elif ISB_NODE_IDENTIFY == PORTD_PIN5
		#define ISB_NODE_IDENTIFY_INIT					DDRD &= ~(1 << DDD5)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTD |= (1 << PD5)
		#define ISB_NODE_IDENTIFY_REGISTER				PIND
		#define ISB_NODE_IDENTIFY_BIT					PD5
	#elif ISB_NODE_IDENTIFY == PORTD_PIN6
		#define ISB_NODE_IDENTIFY_INIT					DDRD &= ~(1 << DDD6)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTD |= (1 << PD6)
		#define ISB_NODE_IDENTIFY_REGISTER				PIND
		#define ISB_NODE_IDENTIFY_BIT					PD6
	#elif ISB_NODE_IDENTIFY == PORTD_PIN7
		#define ISB_NODE_IDENTIFY_INIT					DDRD &= ~(1 << DDD7)
		#define ISB_NODE_IDENTIFY_PULLUP				PORTD |= (1 << PD7)
		#define ISB_NODE_IDENTIFY_REGISTER				PIND
		#define ISB_NODE_IDENTIFY_BIT					PD7
	#else
		#error "main.c -> ISB_NODE_IDENTIFY"
	#endif



#endif /* ISB_NODE_IDENTIFY_DEF_H_ */
