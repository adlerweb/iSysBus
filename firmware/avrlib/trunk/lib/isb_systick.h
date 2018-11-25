/**
 * @file		avrlib/trunk/lib/isb_systick.h
 *
 * @brief		iSysBus Systemtimer.
 *
 * This file includes the iSysBus Systemtimer.
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





#ifndef ISB_SYSTICK_H_
	#define ISB_SYSTICK_H_



	const uint8_t daysPerMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };



	typedef struct Isb_Systick_Clock_t Isb_Systick_Clock_t;

	struct Isb_Systick_Clock_t
	{
		uint8_t Seconds;	// 0-59
		uint8_t Minutes;	// 0-59
		uint8_t Hour;		// 0-23
		uint8_t Day;		// 1-31
		uint8_t Dow;		// 1-7 -> 1=Montag
		uint8_t Month;		// 1-12
		uint16_t Year;		// 0-65535
	};



	uint8_t Isb_Systick_Ctrl = 0;
	uint16_t Isb_Systick_IrqClock = 0;
	Isb_Systick_Clock_t Isb_Systick_Clock;
	uint16_t Isb_Systick_Delay_Counter = 0;


	void Isb_Systick_Init(void);
	void Isb_Systick_Exec(void);
	void Isb_Systick_Irq_Timer(void);



#endif /* ISB_SYSTICK_H_ */
