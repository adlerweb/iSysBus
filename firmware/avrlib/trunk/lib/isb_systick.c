/**
 * @file		avrlib/trunk/lib/isb_systick.c
 *
 * @brief		iSysBus Systemtimer (TODO add Prg_Adc, Prg_TwiDs1621, Prg_1wireDs1820).
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





#ifndef ISB_SYSTICK_C_
	#define ISB_SYSTICK_C_



void Isb_Systick_Init(void)
{

	#if defined(__AVR_ATmega8__)
		#warning "TIMER0_COMP_vect missing."
		#error "No definition for this MCU available."
	#elif defined(__AVR_ATmega16__)
	TCCR0 = (1 << WGM01) | (1 << CS01) | (1 << CS00);
	TCNT0 = 0;
	OCR0 = (F_CPU / 64) / 1000;
	TIMSK = (1 << OCIE0);
	#elif defined(__AVR_ATmega32__)
	TCCR0 = (1 << WGM01) | (1 << CS01) | (1 << CS00);
	TCNT0 = 0;
	OCR0 = (F_CPU / 64) / 1000;
	TIMSK = (1 << OCIE0);
	#elif defined(__AVR_ATmega48__) | defined(__AVR_ATmega48V__)
	TCCR0A = (1 << WGM01);
	TCCR0B = (1 << CS01) | (1 << CS00);
	TCNT0 = 0;
	OCR0A = (F_CPU / 64) / 1000;
	TIMSK0 = (1 << OCIE0A);
	#elif defined(__AVR_ATmega64__)
	TCCR0 = (1 << WGM01) | (1 << CS01) | (1 << CS00);
	TCNT0 = 0;
	OCR0 = (F_CPU / 64) / 1000;
	TIMSK = (1 << OCIE0);
	#elif defined(__AVR_ATmega88__) | defined(__AVR_ATmega88V__)
	TCCR0A = (1 << WGM01);
	TCCR0B = (1 << CS01) | (1 << CS00);
	TCNT0 = 0;
	OCR0A = (F_CPU / 64) / 1000;
	TIMSK0 = (1 << OCIE0A);
	#elif defined(__AVR_ATmega128__)
	TCCR0 = (1 << WGM01) | (1 << CS01) | (1 << CS00);
	TCNT0 = 0;
	OCR0 = (F_CPU / 64) / 1000;
	TIMSK = (1 << OCIE0);
	#elif defined(__AVR_ATmega168__) | defined(__AVR_ATmega168V__)
	TCCR0A = (1 << WGM01);
	TCCR0B = (1 << CS01) | (1 << CS00);
	TCNT0 = 0;
	OCR0A = (F_CPU / 64) / 1000;
	TIMSK0 = (1 << OCIE0A);
	#elif defined(__AVR_ATmega169P__) | defined(__AVR_ATmega169PV__)
	TCCR0A = (1 << WGM01) | (1 << CS01) | (1 << CS00);
	TCNT0 = 0;
	OCR0A = (F_CPU / 64) / 1000;
	TIMSK0 = (1 << OCIE0A);
	#elif defined(__AVR_ATmega644__)
	TCCR0A = (1 << WGM01);
	TCCR0B = (1 << CS01) | (1 << CS00);
	TCNT0 = 0;
	OCR0A = (F_CPU / 64) / 1000;
	TIMSK0 = (1 << OCIE0A);
	#elif defined(__AVR_AT90CAN32__)
	TCCR0A = (1 << WGM01) | (1 << CS01) | (1 << CS00);
	TCNT0 = 0;
	OCR0A = (F_CPU / 64) / 1000;
	TIMSK0 = (1 << OCIE0A);
	#elif defined(__AVR_AT90CAN64__)
	TCCR0A = (1 << WGM01) | (1 << CS01) | (1 << CS00);
	TCNT0 = 0;
	OCR0A = (F_CPU / 64) / 1000;
	TIMSK0 = (1 << OCIE0A);
	#elif defined(__AVR_AT90CAN128__)
	TCCR0A = (1 << WGM01) | (1 << CS01) | (1 << CS00);
	TCNT0 = 0;
	OCR0A = (F_CPU / 64) / 1000;
	TIMSK0 = (1 << OCIE0A);
	#else
		#error "No definition for this MCU available."
	#endif

	Isb_Systick_Clock.Seconds = 0;
	Isb_Systick_Clock.Minutes = 0;
	Isb_Systick_Clock.Hour = 0;
	Isb_Systick_Clock.Dow = 1;
	Isb_Systick_Clock.Day = 1;
	Isb_Systick_Clock.Month = 1;
	Isb_Systick_Clock.Year = 0;;

}



void Isb_Systick_Exec(void)
{

	if (bit_is_set(Isb_Systick_Ctrl, ISB_CTRL_SOFTIRQ_EXEC))
	{

		if (Isb_Systick_IrqClock >= 1000)
		{
			Isb_Systick_IrqClock = 0;
			Isb_Systick_Clock.Seconds++;
			if (Isb_Systick_Clock.Seconds == 60)
			{
				Isb_Systick_Clock.Seconds = 0;
				Isb_Systick_Clock.Minutes++;
				if (Isb_Systick_Clock.Minutes == 60)
				{
					Isb_Systick_Clock.Minutes = 0;
					Isb_Systick_Clock.Hour++;
					if (Isb_Systick_Clock.Hour == 24)
					{
						Isb_Systick_Clock.Hour = 0;
						Isb_Systick_Clock.Day++;
						Isb_Systick_Clock.Dow++;
						if (Isb_Systick_Clock.Dow == 8)
						{
							Isb_Systick_Clock.Dow = 1;
						}
						uint8_t newMonth = 0;
						if (Isb_Systick_Clock.Month == 2)
						{
							if ((Isb_Systick_Clock.Year % 4) == 0)
							{
								newMonth = 1;
								if ((Isb_Systick_Clock.Year % 100) == 0)
								{
									newMonth = 0;
									if ((Isb_Systick_Clock.Year % 400) == 0)
									{
										newMonth = 1;
									}
								}
							}
							if (newMonth)
							{
								if (Isb_Systick_Clock.Day < (daysPerMonth[Isb_Systick_Clock.Month] + 2))
								{
									newMonth = 0;
								}
							}
							else
							{
								if (Isb_Systick_Clock.Day == (daysPerMonth[Isb_Systick_Clock.Month] + 1))
								{
									newMonth = 1;
								}
							}
						}
						else
						{
							if (Isb_Systick_Clock.Day == (daysPerMonth[Isb_Systick_Clock.Month] + 1))
							{
								newMonth = 1;
							}
						}
						if (newMonth)
						{
							Isb_Systick_Clock.Day = 1;
							Isb_Systick_Clock.Month++;
							if (Isb_Systick_Clock.Month == 13)
							{
								Isb_Systick_Clock.Month = 1;
								Isb_Systick_Clock.Year++;
							}
						}
					}
				}
			}
		}

		if (bit_is_clear(Isb_Systick_Ctrl, ISB_CTRL_RUNNING))
		{
			uint16_t Isb_Systick_Delay = 1000;
			if (Isb_Systick_Delay_Counter == Isb_Systick_Delay)
			{
				Isb_Systick_Ctrl |= (1<<ISB_CTRL_RUNNING);
			}
			Isb_Systick_Delay_Counter++;
		}

	#if defined(IF_RF_RFM12)
		if (If_Rf_Rfm12_IrqExec > IF_RF_RFM12_EXECTIME)
		{
			If_Rf_Rfm12_IrqExec = 0;
			If_Rf_Rfm12_Ctrl |= (1 << IF_RF_RFM12_CTRL_SOFTIRQ_EXEC);
		}
	#endif /* IF_RF_RFM12 */

	#if defined(ISB_APP_DIGOUT_MAX) && defined(ISB_APP_H_)
		if (Isb_App_DigOut_IrqExec >= ISB_APP_DIGOUT_EXECTIME)
		{
			Isb_App_DigOut_IrqExec = 0;
			Isb_App_DigOut_Ctrl |= (1 << ISB_CTRL_SOFTIRQ_EXEC);
		}
	#endif /* ISB_APP_DIGOUT_MAX && ISB_APP_H_ */

	#if defined(ISB_APP_DIGIN_MAX) && defined(ISB_APP_H_)
		if (Isb_App_DigIn_IrqExec >= ISB_APP_DIGIN_EXECTIME)
		{
			Isb_App_DigIn_IrqExec = 0;
			Isb_App_DigIn_Ctrl |= (1 << ISB_CTRL_SOFTIRQ_EXEC);
		}
	#endif /* ISB_APP_DIGIN_MAX && ISB_APP_H_ */

	#if defined(ISB_APP_ANAIN_MAX) && defined(ISB_APP_H_)
		if (Isb_App_AnaIn_IrqExec >= ISB_APP_ANAIN_EXECTIME)
		{
			Isb_App_AnaIn_IrqExec = 0;
			Isb_App_AnaIn_Ctrl |= (1 << ISB_CTRL_SOFTIRQ_EXEC);
		}
	#endif /* ISB_APP_ANAIN_MAX && ISB_APP_H_ */

	#if defined(ISB_APP_LCD_MAX) && defined(ISB_APP_H_)
		if (Isb_App_Lcd_IrqExec >= ISB_APP_LCD_EXECTIME)
		{
			Isb_App_Lcd_IrqExec = 0;
			Isb_App_Lcd_Ctrl |= (1 << ISB_CTRL_SOFTIRQ_EXEC);
		}
	#endif /* ISB_APP_LCD_MAX && ISB_APP_H_ */

	#if defined(ISB_APP_CLOCK_MAX) && defined(ISB_APP_H_)
		if (Isb_App_Clock_IrqExec >= ISB_APP_CLOCK_EXECTIME)
		{
			Isb_App_Clock_IrqExec = 0;
			Isb_App_Clock_Ctrl |= (1 << ISB_CTRL_SOFTIRQ_EXEC);
		}
	#endif /* ISB_APP_CLOCK_MAX && ISB_APP_H_ */

	#if defined(ISB_OBJ_MAX) && defined(ISB_OBJ_H_)
		if (Isb_Obj_IrqExec >= ISB_OBJ_EXECTIME)
		{
			Isb_Obj_IrqExec = 0;
			Isb_Obj_Ctrl |= (1 << ISB_CTRL_SOFTIRQ_EXEC);
		}
	#endif /* ISB_OBJ_MAX && ISB_OBJ_H_ */

	#if defined(ISB_OBJ_1BIT_MAX) && defined(ISB_OBJ_H_)
		if (Isb_Obj_1Bit_IrqExec >= ISB_OBJ_1BIT_EXECTIME)
		{
			Isb_Obj_1Bit_IrqExec = 0;
			Isb_Obj_1Bit_Ctrl |= (1 << ISB_CTRL_SOFTIRQ_EXEC);
		}
	#endif /* ISB_OBJ_1BIT_MAX && ISB_OBJ_H_ */

	#if defined(ISB_OBJ_4BIT_MAX) && defined(ISB_OBJ_H_)
		if (Isb_Obj_4Bit_IrqExec >= ISB_OBJ_4BIT_EXECTIME)
		{
			Isb_Obj_4Bit_IrqExec = 0;
			Isb_Obj_4Bit_Ctrl |= (1 << ISB_CTRL_SOFTIRQ_EXEC);
		}
	#endif /* ISB_OBJ_4BIT_MAX && ISB_OBJ_H_ */

	#if defined(ISB_OBJ_8BIT_MAX) && defined(ISB_OBJ_H_)
		if (Isb_Obj_8Bit_IrqExec >= ISB_OBJ_8BIT_EXECTIME)
		{
			Isb_Obj_8Bit_IrqExec = 0;
			Isb_Obj_8Bit_Ctrl |= (1 << ISB_CTRL_SOFTIRQ_EXEC);
		}
	#endif /* ISB_OBJ_8BIT_MAX && ISB_OBJ_H_ */

	#if defined(ISB_OBJ_16BIT_MAX) && defined(ISB_OBJ_H_)
		if (Isb_Obj_16Bit_IrqExec >= ISB_OBJ_16BIT_EXECTIME)
		{
			Isb_Obj_16Bit_IrqExec = 0;
			Isb_Obj_16Bit_Ctrl |= (1 << ISB_CTRL_SOFTIRQ_EXEC);
		}
	#endif /* ISB_OBJ_16BIT_MAX && ISB_OBJ_H_ */

	#if defined(ISB_OBJ_32BIT_MAX) && defined(ISB_OBJ_H_)
		if (Isb_Obj_32Bit_IrqExec >= ISB_OBJ_32BIT_EXECTIME)
		{
			Isb_Obj_32Bit_IrqExec = 0;
			Isb_Obj_32Bit_Ctrl |= (1 << ISB_CTRL_SOFTIRQ_EXEC);
		}
	#endif /* ISB_OBJ_32BIT_MAX && ISB_OBJ_H_ */

	#if defined(ISB_OBJ_FLOAT_MAX) && defined(ISB_OBJ_H_)
		if (Isb_Obj_Float_IrqExec >= ISB_OBJ_FLOAT_EXECTIME)
		{
			Isb_Obj_Float_IrqExec = 0;
			Isb_Obj_Float_Ctrl |= (1 << ISB_CTRL_SOFTIRQ_EXEC);
		}
	#endif /* ISB_OBJ_FLOAT_MAX && ISB_OBJ_H_ */

	Isb_Systick_Ctrl &= ~(1 << ISB_CTRL_SOFTIRQ_EXEC);
	}

}



void Isb_Systick_Irq_Timer(void)
{

	Isb_Systick_Ctrl |= (1 << ISB_CTRL_SOFTIRQ_EXEC);
	Isb_Systick_IrqClock++;

	#if defined(IF_RF_RFM12)
	If_Rf_Rfm12_IrqExec++;
	#endif /* IF_RF_RFM12 */

	#if defined(ISB_APP_DIGOUT_MAX) && defined(ISB_APP_H_)
	Isb_App_DigOut_IrqExec++;
	#endif /* ISB_APP_DIGOUT_MAX && ISB_APP_H_ */

	#if defined(ISB_APP_DIGIN_MAX) && defined(ISB_APP_H_)
	Isb_App_DigIn_IrqExec++;
	#endif /* ISB_APP_DIGIN_MAX && ISB_APP_H_ */

	#if defined(ISB_APP_ANAIN_MAX) && defined(ISB_APP_H_)
	Isb_App_AnaIn_IrqExec++;
	#endif /* ISB_APP_ANAIN_MAX && ISB_APP_H_ */

	#if defined(ISB_APP_LCD_MAX) && defined(ISB_APP_H_)
	Isb_App_Lcd_IrqExec++;
	#endif /* ISB_APP_LCD_MAX && ISB_APP_H_ */

	#if defined(ISB_APP_CLOCK_MAX) && defined(ISB_APP_H_)
	Isb_App_Clock_IrqExec++;
	#endif /* ISB_APP_CLOCK_MAX && ISB_APP_H_ */

	#if defined(ISB_OBJ_MAX) && defined(ISB_OBJ_H_)
	Isb_Obj_IrqExec++;
	#endif /* ISB_OBJ_MAX && ISB_OBJ_H_ */

	#if defined(ISB_OBJ_1BIT_MAX) && defined(ISB_OBJ_H_)
	Isb_Obj_1Bit_IrqExec++;
	#endif /* ISB_OBJ_1BIT_MAX && ISB_OBJ_H_ */

	#if defined(ISB_OBJ_4BIT_MAX) && defined(ISB_OBJ_H_)
	Isb_Obj_4Bit_IrqExec++;
	#endif /* ISB_OBJ_4BIT_MAX && ISB_OBJ_H_ */

	#if defined(ISB_OBJ_8BIT_MAX) && defined(ISB_OBJ_H_)
	Isb_Obj_8Bit_IrqExec++;
	#endif /* ISB_OBJ_8BIT_MAX && ISB_OBJ_H_ */

	#if defined(ISB_OBJ_16BIT_MAX) && defined(ISB_OBJ_H_)
	Isb_Obj_16Bit_IrqExec++;
	#endif /* ISB_OBJ_16BIT_MAX && ISB_OBJ_H_ */

	#if defined(ISB_OBJ_32BIT_MAX) && defined(ISB_OBJ_H_)
	Isb_Obj_32Bit_IrqExec++;
	#endif /* ISB_OBJ_32BIT_MAX && ISB_OBJ_H_ */

	#if defined(ISB_OBJ_FLOAT_MAX) && defined(ISB_OBJ_H_)
	Isb_Obj_Float_IrqExec++;
	#endif /* ISB_OBJ_FLOAT_MAX && ISB_OBJ_H_ */

	#if defined(HW_EUROTRONIC_SPARMATIC_ZERO_H_) && defined(HW_EUROTRONIC_SPARMATIC_ZERO_H_)
	Hw_Eurotronic_Sparmatic_Zero_MotorUeberwachungCount++;
	#endif /* HW_EUROTRONIC_SPARMATIC_ZERO_H_ && HW_EUROTRONIC_SPARMATIC_ZERO_H_ */

}



	#if defined(__AVR_ATmega8__)
		#warning "TIMER0_COMP_vect missing."
		#error "No definition for this MCU available."
	#elif defined(__AVR_ATmega16__)
ISR(TIMER0_COMP_vect)
{
	Isb_Systick_Irq_Timer();
}
	#elif defined(__AVR_ATmega32__)
ISR(TIMER0_COMP_vect)
{
	Isb_Systick_Irq_Timer();
}
	#elif defined(__AVR_ATmega48__) | defined(__AVR_ATmega48V__)
ISR(TIMER0_COMPA_vect)
{
	Isb_Systick_Irq_Timer();
}
	#elif defined(__AVR_ATmega64__)
ISR(TIMER0_COMP_vect)
{
	Isb_Systick_Irq_Timer();
}
	#elif defined(__AVR_ATmega88__) | defined(__AVR_ATmega88V__)
ISR(TIMER0_COMPA_vect)
{
	Isb_Systick_Irq_Timer();
}
	#elif defined(__AVR_ATmega128__)
ISR(TIMER0_COMP_vect)
{
	Isb_Systick_Irq_Timer();
}
	#elif defined(__AVR_ATmega168__) | defined(__AVR_ATmega168V__)
ISR(TIMER0_COMPA_vect)
{
	Isb_Systick_Irq_Timer();
}
	#elif defined(__AVR_ATmega169P__) | defined(__AVR_ATmega169PV__)
ISR(TIMER0_COMP_vect)
{
	Isb_Systick_Irq_Timer();
}
	#elif defined(__AVR_ATmega644__)
ISR(TIMER0_COMPA_vect)
{
	Isb_Systick_Irq_Timer();
}
	#elif defined(__AVR_AT90CAN32__)
ISR(TIMER0_COMP_vect)
{
	Isb_Systick_Irq_Timer();
}
	#elif defined(__AVR_AT90CAN64__)
ISR(TIMER0_COMP_vect)
{
	Isb_Systick_Irq_Timer();
}
	#elif defined(__AVR_AT90CAN128__)
ISR(TIMER0_COMP_vect)
{
	Isb_Systick_Irq_Timer();
}
	#else
		#error "No definition for this MCU available."
	#endif



#endif /* ISB_SYSTICK_C_ */
