/**
 * @file		avrlib/trunk/lib/lib_ds1621.c
 *
 * @brief		Library Ds1621.
 *
 * This file includes Library Ds1621.
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





#ifndef LIB_DS1621_C_
	#define LIB_DS1621_C_



	uint8_t Lib_Ds1621_ReadTemperature(uint8_t aSla, uint16_t * aData) {
		uint8_t SlaW = (aSla << 1);
		uint8_t SlaR = (aSla << 1) + 1;
		uint8_t State = FALSE;
		if (If_Twi_Start(SlaW) == TRUE) {
			if (If_Twi_Write(0xAA) == TRUE) {
				if (If_Twi_RepStart(SlaR) == TRUE) {
					* aData = (uint16_t)(If_Twi_ReadAck() << 8);
					* aData |= (uint16_t)If_Twi_ReadNack();
					State = TRUE;
				}
			}
		}
		If_Twi_Stop();
		return State;
	}



//	void ReadAccessTH(void) {
//		;
//	}



//	void WriteAccessTH(void) {
//		;
//	}



//	void ReadAccessTL(void) {
//		;
//	}



//	void WriteAccessTL(void) {
//		;
//	}



//	void ReadAccessConfig(void) {
//		;
//	}



//	void WriteAccessConfig(void) {
//		;
//	}



//	void ReadCounter(void) {
//		;
//	}



//	void ReadSlope(void) {
//		;
//	}



	uint8_t Lib_Ds1621_StartConvertT(uint8_t aSla) {
		uint8_t SlaW = (aSla << 1);
		uint8_t State = FALSE;
		if (If_Twi_Start(SlaW) == TRUE) {
			if (If_Twi_Write(0xEE) == TRUE) {
				State = TRUE;
			}
		}
		If_Twi_Stop();
		return State;
	}



//	uint8_t Lib_Ds1621_StopConvertT(uint8_t aSla) {
//		;
//		return 0;
//	}



#endif /* LIB_DS1621_C_ */
