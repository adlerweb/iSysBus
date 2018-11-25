/**
 * @file		avrlib/trunk/lib/inf_can_def.h
 *
 * @brief		Interface Can Defines.
 *
 * This file includes Interface Can Defines.
 *
 * @author		© Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
 *
 * @date		$Date: 2011-09-24 23:37:23 +0200 (Sa, 24 Sep 2011) $
 *
 * @version		$Rev: 5210 $
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





#ifndef INF_CAN_DEF_H_
	#define INF_CAN_DEF_H_



	#if defined(INF_CAN0_RX) || defined(INF_CAN0_TX)
//	#if defined(INF_CAN0)
		#if INF_CAN0_CLOCK == 2000000 & INF_CAN0_SPEED == 50000
			#define INF_CAN0_SPICFG							0x03
			// T1 15, T2 5 BTQ 20 SP% 75 SJW 1 Err% 0
			#define INF_CAN0_CNF1							0x00
			#define INF_CAN0_CNF2							0xB6
			#define INF_CAN0_CNF3							0x04
		#elif INF_CAN0_CLOCK == 4000000 & INF_CAN0_SPEED == 50000
			#define INF_CAN0_SPICFG							0x03
			// T1 15, T2 5 BTQ 20 SP% 75 SJW 1 Err% 0
			#define INF_CAN0_CNF1							0x01
			#define INF_CAN0_CNF2							0xB6
			#define INF_CAN0_CNF3							0x04
		#elif INF_CAN0_CLOCK == 8000000 & INF_CAN0_SPEED == 50000
			#define INF_CAN0_SPICFG							0x03
			// T1 15, T2 5 BTQ 20 SP% 75 SJW 1 Err% 0
			#define INF_CAN0_CNF1							0x03
			#define INF_CAN0_CNF2							0xB6
			#define INF_CAN0_CNF3							0x04
		#elif INF_CAN0_CLOCK == 4000000 & INF_CAN0_SPEED == 125000
			#define INF_CAN0_SPICFG							0x03
			// T1 12, T2 4 BTQ 16 SP% 75 SJW 1 Err% 0
			#define INF_CAN0_CNF1							0x00
			#define INF_CAN0_CNF2							0xAC
			#define INF_CAN0_CNF3							0x03
		#elif INF_CAN_CLOCK == 8000000 & INF_CAN_SPEED == 125000
			#define INF_CAN0_SPICFG							0x03
			// T1 12, T2 4 BTQ 16 SP% 75 SJW 1 Err% 0
			#define INF_CAN0_CNF1							0x01
			#define INF_CAN0_CNF2							0xAC
			#define INF_CAN0_CNF3							0x03
		#else
			#error "inf_can.def.h -> INF_CAN0_CLOCK | INF_CAN0_SPEED"
		#endif

		#if INF_CAN0_SS == PORTB_PIN0
			#define INF_CAN0_SSPORT							0x02
			#define INF_CAN0_SSPIN							0x00
			#define INF_CAN0_SS_INIT						DDRB |= (1 << DDB0)
			#define INF_CAN0_SS_LOW							PORTB &= ~(1 << PB0)
			#define INF_CAN0_SS_HIGH						PORTB |= (1 << PB0)
		#elif INF_CAN0_SS == PORTB_PIN2
			#define INF_CAN0_SSPORT							0x02
			#define INF_CAN0_SSPIN							0x02
			#define INF_CAN0_SS_INIT						DDRB |= (1 << DDB2)
			#define INF_CAN0_SS_LOW							PORTB &= ~(1 << PB2)
			#define INF_CAN0_SS_HIGH						PORTB |= (1 << PB2)
		#elif INF_CAN0_SS == PORTB_PIN4
			#define INF_CAN0_SSPORT							0x02
			#define INF_CAN0_SSPIN							0x04
			#define INF_CAN0_SS_INIT						DDRB |= (1 << DDB4)
			#define INF_CAN0_SS_LOW							PORTB &= ~(1 << PB4)
			#define INF_CAN0_SS_HIGH						PORTB |= (1 << PB4)
		#else
			#error "inf_can.def.h -> INF_CAN0_SS"
		#endif

		#if INF_CAN0_RS == NONE
			#define INF_CAN0_RSPORT							0x00
			#define INF_CAN0_RSPIN							0x00
		#elif INF_CAN0_RS == PORTC_PIN2
			#define INF_CAN0_RSPORT							0x03
			#define INF_CAN0_RSPIN							0x02
			#define INF_CAN0_RS_INIT						DDRC |= (1 << DDC2)
			#define INF_CAN0_RS_LOW							PORTC &= ~(1 << PC2)
			#define INF_CAN0_RS_HIGH						PORTC |= (1 << PC2)
		#elif INF_CAN0_RS == MCP2515_RX0BF
			#define INF_CAN0_RSPORT							0xFF
			#define INF_CAN0_RSPIN							0x02
		#elif INF_CAN0_RS == MCP2515_RX1BF
			#define INF_CAN0_RSPORT							0xFF
			#define INF_CAN0_RSPIN							0x02
		#else
			#error "inf_can.def.h -> INF_CAN0_RS"
		#endif

		#if INF_CAN0_INT == INTERRUPT0
		#elif INF_CAN0_INT == INTERRUPT1
		#elif INF_CAN0_INT == INTERRUPT2
		#elif INF_CAN0_INT == INTERRUPT3
		#elif INF_CAN0_INT == INTERRUPT4
		#elif INF_CAN0_INT == INTERRUPT5
		#elif INF_CAN0_INT == INTERRUPT6
		#elif INF_CAN0_INT == INTERRUPT7
		#else
			#error "inf_can.def.h -> INF_CAN0_INT"
		#endif

	#endif /* INF_CAN0 */



	#if defined(INF_CAN1)

		#if INF_CAN1_CLOCK == 2000000 & INF_CAN1_SPEED == 50000
			#define INF_CAN1_SPICFG							0x03
			// T1 15, T2 5 BTQ 20 SP% 75 SJW 1 Err% 0
			#define INF_CAN1_CNF1							0x00
			#define INF_CAN1_CNF2							0xB6
			#define INF_CAN1_CNF3							0x04
		#elif INF_CAN1_CLOCK == 4000000 & INF_CAN1_SPEED == 50000
			#define INF_CAN1_SPICFG							0x03
			// T1 15, T2 5 BTQ 20 SP% 75 SJW 1 Err% 0
			#define INF_CAN1_CNF1							0x01
			#define INF_CAN1_CNF2							0xB6
			#define INF_CAN1_CNF3							0x04
		#elif INF_CAN1_CLOCK == 8000000 & INF_CAN1_SPEED == 50000
			#define INF_CAN1_SPICFG							0x03
			// T1 15, T2 5 BTQ 20 SP% 75 SJW 1 Err% 0
			#define INF_CAN1_CNF1							0x03
			#define INF_CAN1_CNF2							0xB6
			#define INF_CAN1_CNF3							0x04
		#elif INF_CAN1_CLOCK == 4000000 & INF_CAN1_SPEED == 125000
			#define INF_CAN1_SPICFG							0x03
			// T1 12, T2 4 BTQ 16 SP% 75 SJW 1 Err% 0
			#define INF_CAN1_CNF1							0x00
			#define INF_CAN1_CNF2							0xAC
			#define INF_CAN1_CNF3							0x03
		#elif INF_CAN_CLOCK == 8000000 & INF_CAN_SPEED == 125000
			#define INF_CAN1_SPICFG							0x03
			// T1 12, T2 4 BTQ 16 SP% 75 SJW 1 Err% 0
			#define INF_CAN1_CNF1							0x01
			#define INF_CAN1_CNF2							0xAC
			#define INF_CAN1_CNF3							0x03
		#else
			#error "inf_can.def.h -> INF_CAN1_CLOCK | INF_CAN1_SPEED"
		#endif

		#if INF_CAN1_SS == PORTB_PIN2
			#define INF_CAN1_SSPORT							0x02
			#define INF_CAN1_SSPIN							0x02
			#define INF_CAN1_SS_INIT						DDRB |= (1 << DDB2)
			#define INF_CAN1_SS_LOW							PORTB &= ~(1 << PB2)
			#define INF_CAN1_SS_HIGH						PORTB |= (1 << PB2)
		#elif INF_CAN1_SS == PORTB_PIN4
			#define INF_CAN1_SSPORT							0x02
			#define INF_CAN1_SSPIN							0x04
			#define INF_CAN1_SS_INIT						DDRB |= (1 << DDB4)
			#define INF_CAN1_SS_LOW							PORTB &= ~(1 << PB4)
			#define INF_CAN1_SS_HIGH						PORTB |= (1 << PB4)
		#else
			#error "inf_can.def.h -> INF_CAN1_SS"
		#endif

		#if INF_CAN1_RS == NONE
			#define INF_CAN1_RSPORT							0x00
			#define INF_CAN1_RSPIN							0x00
		#elif INF_CAN1_RS == PORTC_PIN2
			#define INF_CAN1_RSPORT							0x03
			#define INF_CAN1_RSPIN							0x02
			#define INF_CAN1_RS_INIT						DDRC |= (1 << DDC2)
			#define INF_CAN1_RS_LOW							PORTC &= ~(1 << PC2)
			#define INF_CAN1_RS_HIGH						PORTC |= (1 << PC2)
		#elif INF_CAN1_RS == MCP2515_RX0BF
			#define INF_CAN1_RSPORT							0xFF
			#define INF_CAN1_RSPIN							0x02
		#elif INF_CAN1_RS == MCP2515_RX1BF
			#define INF_CAN1_RSPORT							0xFF
			#define INF_CAN1_RSPIN							0x02
		#else
			#error "inf_can.def.h -> INF_CAN1_RS"
		#endif

		#if INF_CAN1_INT == INTERRUPT0
		#elif INF_CAN1_INT == INTERRUPT1
		#elif INF_CAN1_INT == INTERRUPT2
		#elif INF_CAN1_INT == INTERRUPT3
		#elif INF_CAN1_INT == INTERRUPT4
		#elif INF_CAN1_INT == INTERRUPT5
		#elif INF_CAN1_INT == INTERRUPT6
		#elif INF_CAN1_INT == INTERRUPT7
		#else
			#error "inf_can.def.h -> INF_CAN1_INT"
		#endif

	#endif /* INF_CAN1 */



	#if defined(INF_CAN2)

		#if INF_CAN2_CLOCK == 2000000 & INF_CAN2_SPEED == 50000
			#define INF_CAN2_SPICFG							0x03
			// T1 15, T2 5 BTQ 20 SP% 75 SJW 1 Err% 0
			#define INF_CAN2_CNF1							0x00
			#define INF_CAN2_CNF2							0xB6
			#define INF_CAN2_CNF3							0x04
		#elif INF_CAN2_CLOCK == 4000000 & INF_CAN2_SPEED == 50000
			#define INF_CAN2_SPICFG							0x03
			// T1 15, T2 5 BTQ 20 SP% 75 SJW 1 Err% 0
			#define INF_CAN2_CNF1							0x01
			#define INF_CAN2_CNF2							0xB6
			#define INF_CAN2_CNF3							0x04
		#elif INF_CAN2_CLOCK == 8000000 & INF_CAN2_SPEED == 50000
			#define INF_CAN2_SPICFG							0x03
			// T1 15, T2 5 BTQ 20 SP% 75 SJW 1 Err% 0
			#define INF_CAN2_CNF1							0x03
			#define INF_CAN2_CNF2							0xB6
			#define INF_CAN2_CNF3							0x04
		#elif INF_CAN2_CLOCK == 4000000 & INF_CAN2_SPEED == 125000
			#define INF_CAN2_SPICFG							0x03
			// T1 12, T2 4 BTQ 16 SP% 75 SJW 1 Err% 0
			#define INF_CAN2_CNF1							0x00
			#define INF_CAN2_CNF2							0xAC
			#define INF_CAN2_CNF3							0x03
		#elif INF_CAN_CLOCK == 8000000 & INF_CAN_SPEED == 125000
			#define INF_CAN2_SPICFG							0x03
			// T1 12, T2 4 BTQ 16 SP% 75 SJW 1 Err% 0
			#define INF_CAN2_CNF1							0x01
			#define INF_CAN2_CNF2							0xAC
			#define INF_CAN2_CNF3							0x03
		#else
			#error "inf_can.def.h -> INF_CAN2_CLOCK | INF_CAN2_SPEED"
		#endif

		#if INF_CAN2_SS == PORTB_PIN2
			#define INF_CAN2_SSPORT							0x02
			#define INF_CAN2_SSPIN							0x02
			#define INF_CAN2_SS_INIT						DDRB |= (1 << DDB2)
			#define INF_CAN2_SS_LOW							PORTB &= ~(1 << PB2)
			#define INF_CAN2_SS_HIGH						PORTB |= (1 << PB2)
		#elif INF_CAN2_SS == PORTB_PIN4
			#define INF_CAN2_SSPORT							0x02
			#define INF_CAN2_SSPIN							0x04
			#define INF_CAN2_SS_INIT						DDRB |= (1 << DDB4)
			#define INF_CAN2_SS_LOW							PORTB &= ~(1 << PB4)
			#define INF_CAN2_SS_HIGH						PORTB |= (1 << PB4)
		#else
			#error "inf_can.def.h -> INF_CAN2_SS"
		#endif

		#if INF_CAN2_RS == NONE
			#define INF_CAN2_RSPORT							0x00
			#define INF_CAN2_RSPIN							0x00
		#elif INF_CAN2_RS == PORTC_PIN2
			#define INF_CAN2_RSPORT							0x03
			#define INF_CAN2_RSPIN							0x02
			#define INF_CAN2_RS_INIT						DDRC |= (1 << DDC2)
			#define INF_CAN2_RS_LOW							PORTC &= ~(1 << PC2)
			#define INF_CAN2_RS_HIGH						PORTC |= (1 << PC2)
		#elif INF_CAN2_RS == MCP2515_RX0BF
			#define INF_CAN2_RSPORT							0xFF
			#define INF_CAN2_RSPIN							0x02
		#elif INF_CAN2_RS == MCP2515_RX1BF
			#define INF_CAN2_RSPORT							0xFF
			#define INF_CAN2_RSPIN							0x02
		#else
			#error "inf_can.def.h -> INF_CAN2_RS"
		#endif

		#if INF_CAN2_INT == INTERRUPT0
		#elif INF_CAN2_INT == INTERRUPT1
		#elif INF_CAN2_INT == INTERRUPT2
		#elif INF_CAN2_INT == INTERRUPT3
		#elif INF_CAN2_INT == INTERRUPT4
		#elif INF_CAN2_INT == INTERRUPT5
		#elif INF_CAN2_INT == INTERRUPT6
		#elif INF_CAN2_INT == INTERRUPT7
		#else
			#error "inf_can.def.h -> INF_CAN2_INT"
		#endif

	#endif /* INF_CAN2 */



#endif /* INF_CAN_DEF_H_ */
