/**
 * @file		avrlib/trunk/lib/lib_pin.c
 *
 * @brief		Library Pin.
 *
 * This file includes Library Pin.
 *
 * @author		© Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
 *
 * @date		$Date: 2011-10-11 23:03:14 +0200 (Di, 11 Okt 2011) $
 *
 * @version		$Rev: 6042 $
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





#ifndef LIB_PIN_C_
	#define LIB_PIN_C_



	#if defined(__AVR_ATmega8__)
		uint8_t NUL;
		volatile uint8_t* DDRx[] = {&NUL, &NUL, &DDRB, &DDRC, &DDRD, &NUL, &NUL, &NUL};
		volatile uint8_t* PORTx[] = {&NUL, &NUL, &PORTB, &PORTC, &PORTD, &NUL, &NUL, &NUL};
		volatile uint8_t* PINx[] = {&NUL, &NUL, &PINB, &PINC, &PIND, &NUL, &NUL, &NUL};
	#elif defined(__AVR_ATmega16__)
		uint8_t NUL;
		volatile uint8_t* DDRx[] = {&NUL, &DDRA, &DDRB, &DDRC, &DDRD, &NUL, &NUL, &NUL};
		volatile uint8_t* PORTx[] = {&NUL, &PORTA, &PORTB, &PORTC, &PORTD, &NUL, &NUL, &NUL};
		volatile uint8_t* PINx[] = {&NUL, &PINA, &PINB, &PINC, &PIND, &NUL, &NUL, &NUL};
	#elif defined(__AVR_ATmega32__)
		uint8_t NUL;
		volatile uint8_t* DDRx[] = {&NUL, &DDRA, &DDRB, &DDRC, &DDRD, &NUL, &NUL, &NUL};
		volatile uint8_t* PORTx[] = {&NUL, &PORTA, &PORTB, &PORTC, &PORTD, &NUL, &NUL, &NUL};
		volatile uint8_t* PINx[] = {&NUL, &PINA, &PINB, &PINC, &PIND, &NUL, &NUL, &NUL};
	#elif defined(__AVR_ATmega48__)
		uint8_t NUL;
		volatile uint8_t* DDRx[] = {&NUL, &NUL, &DDRB, &DDRC, &DDRD, &NUL, &NUL, &NUL};
		volatile uint8_t* PORTx[] = {&NUL, &NUL, &PORTB, &PORTC, &PORTD, &NUL, &NUL, &NUL};
		volatile uint8_t* PINx[] = {&NUL, &NUL, &PINB, &PINC, &PIND, &NUL, &NUL, &NUL};
	#elif defined(__AVR_ATmega48V__)
		uint8_t NUL;
		volatile uint8_t* DDRx[] = {&NUL, &NUL, &DDRB, &DDRC, &DDRD, &NUL, &NUL, &NUL};
		volatile uint8_t* PORTx[] = {&NUL, &NUL, &PORTB, &PORTC, &PORTD, &NUL, &NUL, &NUL};
		volatile uint8_t* PINx[] = {&NUL, &NUL, &PINB, &PINC, &PIND, &NUL, &NUL, &NUL};
	#elif defined(__AVR_ATmega64__)
		uint8_t NUL;
		volatile uint8_t* DDRx[] = {&NUL, &DDRA, &DDRB, &DDRC, &DDRD, &DDRE, &DDRF, &DDRG};
		volatile uint8_t* PORTx[] = {&NUL, &PORTA, &PORTB, &PORTC, &PORTD, &PORTE, &PORTF, &PORTG};
		volatile uint8_t* PINx[] = {&NUL, &PINA, &PINB, &PINC, &PIND, &PINE, &PINF, &PING};
	#elif defined(__AVR_ATmega88__)
		uint8_t NUL;
		volatile uint8_t* DDRx[] = {&NUL, &NUL, &DDRB, &DDRC, &DDRD, &NUL, &NUL, &NUL};
		volatile uint8_t* PORTx[] = {&NUL, &NUL, &PORTB, &PORTC, &PORTD, &NUL, &NUL, &NUL};
		volatile uint8_t* PINx[] = {&NUL, &NUL, &PINB, &PINC, &PIND, &NUL, &NUL, &NUL};
	#elif defined(__AVR_ATmega88V__)
		uint8_t NUL;
		volatile uint8_t* DDRx[] = {&NUL, &NUL, &DDRB, &DDRC, &DDRD, &NUL, &NUL, &NUL};
		volatile uint8_t* PORTx[] = {&NUL, &NUL, &PORTB, &PORTC, &PORTD, &NUL, &NUL, &NUL};
		volatile uint8_t* PINx[] = {&NUL, &NUL, &PINB, &PINC, &PIND, &NUL, &NUL, &NUL};
	#elif defined(__AVR_ATmega128__)
		uint8_t NUL;
		volatile uint8_t* DDRx[] = {&NUL, &DDRA, &DDRB, &DDRC, &DDRD, &DDRE, &DDRF, &DDRG};
		volatile uint8_t* PORTx[] = {&NUL, &PORTA, &PORTB, &PORTC, &PORTD, &PORTE, &PORTF, &PORTG};
		volatile uint8_t* PINx[] = {&NUL, &PINA, &PINB, &PINC, &PIND, &PINE, &PINF, &PING};
	#elif defined(__AVR_ATmega168__)
		uint8_t NUL;
		volatile uint8_t* DDRx[] = {&NUL, &NUL, &DDRB, &DDRC, &DDRD, &NUL, &NUL, &NUL};
		volatile uint8_t* PORTx[] = {&NUL, &NUL, &PORTB, &PORTC, &PORTD, &NUL, &NUL, &NUL};
		volatile uint8_t* PINx[] = {&NUL, &NUL, &PINB, &PINC, &PIND, &NUL, &NUL, &NUL};
	#elif defined(__AVR_ATmega168V__)
		uint8_t NUL;
		volatile uint8_t* DDRx[] = {&NUL, &NUL, &DDRB, &DDRC, &DDRD, &NUL, &NUL, &NUL};
		volatile uint8_t* PORTx[] = {&NUL, &NUL, &PORTB, &PORTC, &PORTD, &NUL, &NUL, &NUL};
		volatile uint8_t* PINx[] = {&NUL, &NUL, &PINB, &PINC, &PIND, &NUL, &NUL, &NUL};
	#elif defined(__AVR_ATmega169P__)
		uint8_t NUL;
		volatile uint8_t* DDRx[] = {&NUL, &DDRA, &DDRB, &DDRC, &DDRD, &DDRE, &DDRF, &DDRG};
		volatile uint8_t* PORTx[] = {&NUL, &PORTA, &PORTB, &PORTC, &PORTD, &PORTE, &PORTF, &PORTG};
		volatile uint8_t* PINx[] = {&NUL, &PINA, &PINB, &PINC, &PIND, &PINE, &PINF, &PING};
	#elif defined(__AVR_ATmega169PV__)
		uint8_t NUL;
		volatile uint8_t* DDRx[] = {&NUL, &DDRA, &DDRB, &DDRC, &DDRD, &DDRE, &DDRF, &DDRG};
		volatile uint8_t* PORTx[] = {&NUL, &PORTA, &PORTB, &PORTC, &PORTD, &PORTE, &PORTF, &PORTG};
		volatile uint8_t* PINx[] = {&NUL, &PINA, &PINB, &PINC, &PIND, &PINE, &PINF, &PING};
	#elif defined(__AVR_ATmega644__)
		uint8_t NUL;
		volatile uint8_t* DDRx[] = {&NUL, &DDRA, &DDRB, &DDRC, &DDRD, &NUL, &NUL, &NUL};
		volatile uint8_t* PORTx[] = {&NUL, &PORTA, &PORTB, &PORTC, &PORTD, &NUL, &NUL, &NUL};
		volatile uint8_t* PINx[] = {&NUL, &PINA, &PINB, &PINC, &PIND, &NUL, &NUL, &NUL};
	#elif defined(__AVR_AT90CAN32__)
		uint8_t NUL;
		volatile uint8_t* DDRx[] = {&NUL, &DDRA, &DDRB, &DDRC, &DDRD, &DDRE, &DDRF, &DDRG};
		volatile uint8_t* PORTx[] = {&NUL, &PORTA, &PORTB, &PORTC, &PORTD, &PORTE, &PORTF, &PORTG};
		volatile uint8_t* PINx[] = {&NUL, &PINA, &PINB, &PINC, &PIND, &PINE, &PINF, &PING};
	#elif defined(__AVR_AT90CAN64__)
		uint8_t NUL;
		volatile uint8_t* DDRx[] = {&NUL, &DDRA, &DDRB, &DDRC, &DDRD, &DDRE, &DDRF, &DDRG};
		volatile uint8_t* PORTx[] = {&NUL, &PORTA, &PORTB, &PORTC, &PORTD, &PORTE, &PORTF, &PORTG};
		volatile uint8_t* PINx[] = {&NUL, &PINA, &PINB, &PINC, &PIND, &PINE, &PINF, &PING};
	#elif defined(__AVR_AT90CAN128__)
		uint8_t NUL;
		volatile uint8_t* DDRx[] = {&NUL, &DDRA, &DDRB, &DDRC, &DDRD, &DDRE, &DDRF, &DDRG};
		volatile uint8_t* PORTx[] = {&NUL, &PORTA, &PORTB, &PORTC, &PORTD, &PORTE, &PORTF, &PORTG};
		volatile uint8_t* PINx[] = {&NUL, &PINA, &PINB, &PINC, &PIND, &PINE, &PINF, &PING};
	#else
		#error "No definition for this MCU available."
	#endif



	uint8_t Lib_Pin_Get(const uint8_t aPort, const uint8_t aPin) {
		return (*(PINx[aPort]) >> aPin) & 1;
	}



	void __attribute__((noinline)) Lib_Pin_Set(const uint8_t aPort, const uint8_t aPin, const uint8_t aCmd) {
		uint8_t mask;
		uint8_t tmp;
		volatile uint8_t *reg;
		uint8_t Pxx = aPin;
		for (mask = 1; Pxx--; mask <<= 1) ;
		reg = PORTx[aPort];
		tmp = *reg | mask;
		if (! (aCmd & 2)) {
			tmp ^= mask;
		}
		*reg = tmp;
		reg = DDRx[aPort];
		tmp = *reg | mask;
		if (! (aCmd & 1)) {
			tmp ^= mask;
		}
		*reg = tmp;
	}



#endif /*LIB_PIN_H_*/
