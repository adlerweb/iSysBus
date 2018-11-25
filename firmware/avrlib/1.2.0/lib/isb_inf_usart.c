/**
 * @file		avrlib/trunk/lib/isb_inf_usart.c
 *
 * @brief		iSysBus Interface Usart.
 *
 * This file includes iSysBus Interface Usart.
 *
 * @author		© Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
 *
 * @date		$Date: 2011-08-03 15:18:11 +0200 (Mi, 03 Aug 2011) $
 *
 * @version		$Rev: 4513 $
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





#ifndef ISB_INF_USART_C_
	#define ISB_INF_USART_C_



	uint8_t Isb_Inf_Usart_Init(const uint8_t aInf) {
		uint8_t Result = FALSE;
		switch (aInf) {
			#if ISB_INF_USART0 == 1
				case 0:
					Result = Inf_Usart_Init(0, INF_USART0_UBRRL, INF_USART0_UBRRH, INF_USART0_UCSRA, INF_USART0_UCSRB, INF_USART0_UCSRC);
					break;
			#endif /* ISB_INF_USART0 == 1 */
			#if ISB_INF_USART1 == 1
				case 1:
					Result = Inf_Usart_Init(1, INF_USART1_UBRRL, INF_USART1_UBRRH, INF_USART1_UCSRA, INF_USART1_UCSRB, INF_USART1_UCSRC);
				break;
			#endif /* ISB_INF_USART1 == 1 */
		}
		return Result;
	}



	uint8_t Isb_Inf_Usart_Tx(const uint8_t aInf, const Isb_Msg_t * aIsb_Msg) {
		uint8_t Result = FALSE;
		uint8_t Free_Space = 0;
		uint8_t Startbyte = 0;
		uint8_t Stopbyte = 0;
		switch (aInf) {
			#if defined(INF_USART0_TX)
				case 0:
					cli();
					if (Inf_Usart_Tx0_Buffer_Tail > Inf_Usart_Tx0_Buffer_Head) {
						Free_Space = Inf_Usart_Tx0_Buffer_Tail - Inf_Usart_Tx0_Buffer_Head;
					}
					else {
						Free_Space = (Inf_Usart_Tx0_Buffer_Tail + INF_USART_TX0_BUFFER_SIZE - Inf_Usart_Tx0_Buffer_Head);
					}
					sei();
					Startbyte = ISB_INF_USART0_STARTBYTE;
					Stopbyte = ISB_INF_USART0_STOPBYTE;
					break;
			#endif /* INF_USART0_TX */
			#if defined(INF_USART1_TX)
				case 1:
					cli();
					if (Inf_Usart_Tx1_Buffer_Tail > Inf_Usart_Tx1_Buffer_Head) {
						Free_Space = Inf_Usart_Tx1_Buffer_Tail - Inf_Usart_Tx1_Buffer_Head;
					}
					else {
						Free_Space = (Inf_Usart_Tx1_Buffer_Tail + INF_USART_TX1_BUFFER_SIZE - Inf_Usart_Tx1_Buffer_Head);
					}
					sei();
					Startbyte = ISB_INF_USART1_STARTBYTE;
					Stopbyte = ISB_INF_USART1_STOPBYTE;
					break;
			#endif /* INF_USART1_TX */
		}
		uint8_t aIsb_Msg_Dlc = aIsb_Msg->Flags & 0x0F;
		if (Free_Space > (9 + aIsb_Msg_Dlc)) {
			uint8_t aChar;
			aChar = Startbyte;
			Inf_Usart_Tx(aInf, &aChar);
			Inf_Usart_Tx(aInf, &aIsb_Msg->Flags);
			aChar = (uint8_t)aIsb_Msg->DestId;
			Inf_Usart_Tx(aInf, &aChar);
			aChar = (uint8_t)(aIsb_Msg->DestId >> 8);
			Inf_Usart_Tx(aInf, &aChar);
			aChar = (uint8_t)aIsb_Msg->SourceId;
			Inf_Usart_Tx(aInf, &aChar);
			aChar = (uint8_t)(aIsb_Msg->SourceId >> 8);
			Inf_Usart_Tx(aInf, &aChar);
			for (uint8_t i = 0; i < aIsb_Msg_Dlc; i++) {
				Inf_Usart_Tx(aInf, &aIsb_Msg->Data[i]);
			}
			aChar = 0x00;
			Inf_Usart_Tx(aInf, &aChar);
			aChar = Lib_Crc_Calc8(aIsb_Msg, (5 + aIsb_Msg_Dlc));
			Inf_Usart_Tx(aInf, &aChar);
			aChar = Stopbyte;
			Inf_Usart_Tx(aInf, &aChar);
			Result = TRUE;
		}
		return Result;
	}



	uint8_t Isb_Inf_Usart_Rx(const uint8_t aInf, Isb_Msg_t * aIsb_Msg) {
		uint8_t Result = FALSE;
		uint8_t Mask;
		static volatile uint8_t * Buffer;
		static volatile uint8_t * Head;
		static volatile uint8_t * Tail;
		uint8_t Startbyte = 0;
		uint8_t Stopbyte = 0;
		switch (aInf) {
			#if defined(INF_USART0_RX)
				case 0:
					Mask = INF_USART_RX0_BUFFER_MASK;
					Buffer = Inf_Usart_Rx0_Buffer;
					Head = &Inf_Usart_Rx0_Buffer_Head;
					Tail = &Inf_Usart_Rx0_Buffer_Tail;
					Startbyte = ISB_INF_USART0_STARTBYTE;
					Stopbyte = ISB_INF_USART0_STOPBYTE;
					break;
			#endif /* INF_USART0_RX */
			#if defined(INF_USART1_RX)
				case 1:
					Mask = INF_USART_RX1_BUFFER_MASK;
					Buffer = Inf_Usart_Rx1_Buffer;
					Head = &Inf_Usart_Rx1_Buffer_Head;
					Tail = &Inf_Usart_Rx1_Buffer_Tail;
					Startbyte = ISB_INF_USART1_STARTBYTE;
					Stopbyte = ISB_INF_USART1_STOPBYTE;
					break;
			#endif /* INF_USART1_RX */
			default:
				return Result;
				break;
		}
		uint8_t Tmp_Tail;
		uint8_t Rel_Pos = 0;
		uint8_t Start_Pos = 0;
		uint8_t Isb_Msg_Dlc = 0;
		Tmp_Tail = (*Tail + 1) & Mask;
		while (Tmp_Tail != ((*Head + 1) & Mask)) {
			if (Rel_Pos == 0) {
				if (Buffer[Tmp_Tail] == Startbyte) {
					Start_Pos = Tmp_Tail;
					Rel_Pos++;
				}
				else {
					*Tail = Tmp_Tail;
					Rel_Pos = 0;
				}
			}
			else if (Rel_Pos == 1) {
				aIsb_Msg->Flags = Buffer[Tmp_Tail];
				Rel_Pos++;
				if (bit_is_clear (aIsb_Msg->Flags, 6)) {
					Isb_Msg_Dlc = aIsb_Msg->Flags & ISB_MSG_FLAGS_DLC_MASK;
				}
			}
			else if (Rel_Pos == 2) {
				aIsb_Msg->DestId = (uint16_t)Buffer[Tmp_Tail];
				Rel_Pos++;
			}
			else if (Rel_Pos == 3) {
				aIsb_Msg->DestId += (uint16_t)(Buffer[Tmp_Tail] << 8);
				Rel_Pos++;
			}
			else if (Rel_Pos == 4) {
				aIsb_Msg->SourceId = (uint16_t)Buffer[Tmp_Tail];
				Rel_Pos++;
			}
			else if (Rel_Pos == 5) {
				aIsb_Msg->SourceId += (uint16_t)(Buffer[Tmp_Tail] << 8);
				Rel_Pos++;
			}
			else if ((Rel_Pos == 6) & (Isb_Msg_Dlc >= 1)) {
				aIsb_Msg->Data[0] = Buffer[Tmp_Tail];
				Rel_Pos++;
			}
			else if ((Rel_Pos == 7) & (Isb_Msg_Dlc >= 2)) {
				aIsb_Msg->Data[1] = Buffer[Tmp_Tail];
				Rel_Pos++;
			}
			else if ((Rel_Pos == 8) & (Isb_Msg_Dlc >= 3)) {
				aIsb_Msg->Data[2] = Buffer[Tmp_Tail];
				Rel_Pos++;
			}
			else if ((Rel_Pos == 9) & (Isb_Msg_Dlc >= 4)) {
				aIsb_Msg->Data[3] = Buffer[Tmp_Tail];
				Rel_Pos++;
			}
			else if ((Rel_Pos == 10) & (Isb_Msg_Dlc >= 5)) {
				aIsb_Msg->Data[4] = Buffer[Tmp_Tail];
				Rel_Pos++;
			}
			else if ((Rel_Pos == 11) & (Isb_Msg_Dlc >= 6)) {
				aIsb_Msg->Data[5] = Buffer[Tmp_Tail];
				Rel_Pos++;
			}
			else if ((Rel_Pos == 12) & (Isb_Msg_Dlc >= 7)) {
				aIsb_Msg->Data[6] = Buffer[Tmp_Tail];
				Rel_Pos++;
			}
			else if ((Rel_Pos == 13) & (Isb_Msg_Dlc == 8)) {
				aIsb_Msg->Data[7] = Buffer[Tmp_Tail];
				Rel_Pos++;
			}
			else if (Rel_Pos == (6 + Isb_Msg_Dlc)) {
				Rel_Pos++;
			}
			else if (Rel_Pos == (7 + Isb_Msg_Dlc)) {
				if (Buffer[Tmp_Tail] == Lib_Crc_Calc8(aIsb_Msg, (5 + Isb_Msg_Dlc))) {
					Rel_Pos++;
				}
				else {
					*Tail = Start_Pos;
					Rel_Pos = 0;
					continue;
				}
			}
			else if (Rel_Pos == (8 + Isb_Msg_Dlc)) {
				if (Buffer[Tmp_Tail] != Stopbyte) {
					*Tail = Start_Pos;
					Rel_Pos = 0;
					continue;
				}
				else {
					*Tail = Tmp_Tail;
					Result = TRUE;
				}
			}
			Tmp_Tail = (Tmp_Tail + 1) & Mask;
		}
		return Result;
	}



#endif /* ISB_INF_USART_C_ */
