/**
 * @file		avrlib/trunk/lib/isb_systick.c
 *
 * @brief		iSysBus Systemtimer (TODO add Prg_Adc, Prg_TwiDs1621, Prg_1wireDs1820).
 *
 * This file includes the iSysBus Systemtimer.
 *
 * @author		© Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
 *
 * @date		$Date: 2011-09-05 01:44:12 +0200 (Mo, 05 Sep 2011) $
 *
 * @version		$Rev: 4827 $
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



	void Isb_Systick_Init(void) {
		#if defined(__AVR_ATmega8__) || defined(__AVR_ATmega16__) || defined(__AVR_ATmega32__) || defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)
			TCCR0 = (1 << WGM01) | (1 << CS01) | (1 << CS00);
			TCNT0 = 0;
			OCR0 = (F_CPU / 64) / 1000;
			TIMSK = (1 << OCIE0);
		#elif defined(__AVR_ATmega48__) || defined(__AVR_ATmega88__) || defined(__AVR_ATmega168__)
			TCCR0A = (1 << WGM01);
			TCCR0B = (1 << CS01) | (1 << CS00);
			TCNT0 = 0;
			OCR0A = (F_CPU / 64) / 1000;
			TIMSK0 = (1 << OCIE0A);
		#elif defined(__AVR_ATmega169P__) || defined(__AVR_ATmega169PV__)
			TCCR0A = (1 << WGM01) | (1 << CS01) | (1 << CS00);
			TCNT0 = 0;
			OCR0A = (F_CPU / 64) / 1000;
			TIMSK0 = (1 << OCIE0A);
		#elif defined(__AVR_ATmega644__)
			TCCR0A = (1 << WGM01) | (1 << CS01) | (1 << CS00);
			TCNT0 = 0;
			OCR0A = (F_CPU / 64) / 1000;
			TIMSK0 = (1 << OCIE0A);
		#elif defined(__AVR_AT90CAN32__) || defined(__AVR_AT90CAN64__) || defined(__AVR_AT90CAN128__)
			TCCR0A = (1 << WGM01) | (1 << CS01) | (1 << CS00);
			TCNT0 = 0;
			OCR0A = (F_CPU / 64) / 1000;
			TIMSK0 = (1 << OCIE0A);
		#else
			#error "No definition for this MCU available."
		#endif
	}



	void Isb_Systick_Exec(void) {
		if (bit_is_set(Isb_Systick_Ctrl, ISB_CTRL_SOFTIRQ_EXEC)) {

			#if defined(ISB_APP_DIGOUT_MAX) && defined(ISB_APP_H_)
				if (Isb_App_DigOut_IrqExec >= ISB_APP_DIGOUT_EXECTIME) {
					Isb_App_DigOut_Ctrl |= (1 << ISB_CTRL_SOFTIRQ_EXEC);
					Isb_App_DigOut_IrqExec = 0;
				}
			#endif /* ISB_APP_DIGOUT_MAX && ISB_APP_H_ */

			#if defined(ISB_APP_DIGIN_MAX) && defined(ISB_APP_H_)
				if (Isb_App_DigIn_IrqExec >= ISB_APP_DIGIN_EXECTIME) {
					Isb_App_DigIn_Ctrl |= (1 << ISB_CTRL_SOFTIRQ_EXEC);
					Isb_App_DigIn_IrqExec = 0;
				}
			#endif /* ISB_APP_DIGIN_MAX && ISB_APP_H_ */

			#if defined(ISB_APP_ANAIN_MAX) && defined(ISB_APP_H_)
				if (Isb_App_AnaIn_IrqExec >= ISB_APP_ANAIN_EXECTIME) {
					Isb_App_AnaIn_Ctrl |= (1 << ISB_CTRL_SOFTIRQ_EXEC);
					Isb_App_AnaIn_IrqExec = 0;
				}
			#endif /* ISB_APP_FLOAT_SENSOR_MAX && ISB_APP_H_ */

			#if defined(ISB_APP_LCD_MAX) && defined(ISB_APP_H_)
				if (Isb_App_Lcd_IrqExec >= ISB_APP_LCD_EXECTIME) {
					Isb_App_Lcd_Ctrl |= (1 << ISB_CTRL_SOFTIRQ_EXEC);
					Isb_App_Lcd_IrqExec = 0;
				}
			#endif /* ISB_APP_LCD_MAX && ISB_APP_H_ */

			#if defined(ISB_OBJ_1BIT_MAX) && defined(ISB_OBJ_H_)
				if (Isb_Obj_1Bit_IrqExec >= ISB_OBJ_1BIT_EXECTIME) {
					Isb_Obj_1Bit_Ctrl |= (1 << ISB_CTRL_SOFTIRQ_EXEC);
					Isb_Obj_1Bit_IrqExec = 0;
				}
			#endif /* ISB_OBJ_1BIT_MAX && ISB_OBJ_H_ */

			#if defined(ISB_OBJ_4BIT_MAX) && defined(ISB_OBJ_H_)
				if (Isb_Obj_4Bit_IrqExec >= ISB_OBJ_4BIT_EXECTIME) {
					Isb_Obj_4Bit_Ctrl |= (1 << ISB_CTRL_SOFTIRQ_EXEC);
					Isb_Obj_4Bit_IrqExec = 0;
				}
			#endif /* ISB_OBJ_4BIT_MAX && ISB_OBJ_H_ */

			#if defined(ISB_OBJ_8BIT_MAX) && defined(ISB_OBJ_H_)
				if (Isb_Obj_8Bit_IrqExec >= ISB_OBJ_8BIT_EXECTIME) {
					Isb_Obj_8Bit_Ctrl |= (1 << ISB_CTRL_SOFTIRQ_EXEC);
					Isb_Obj_8Bit_IrqExec = 0;
				}
			#endif /* ISB_OBJ_8BIT_MAX && ISB_OBJ_H_ */

			#if defined(ISB_OBJ_FLOAT_MAX) && defined(ISB_OBJ_H_)
				if (Isb_Obj_Float_IrqExec >= ISB_OBJ_FLOAT_EXECTIME) {
					Isb_Obj_Float_Ctrl |= (1 << ISB_CTRL_SOFTIRQ_EXEC);
					Isb_Obj_Float_IrqExec = 0;
				}
			#endif /* ISB_OBJ_FLOAT_MAX && ISB_OBJ_H_ */

			Isb_Systick_Ctrl &= ~(1 << ISB_CTRL_SOFTIRQ_EXEC);
		}
	}



	void Isb_Systick_Irq_Timer(void) {
		Isb_Systick_Ctrl |= (1 << ISB_CTRL_SOFTIRQ_EXEC);

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

		#if defined(ISB_OBJ_1BIT_MAX) && defined(ISB_OBJ_H_)
			Isb_Obj_1Bit_IrqExec++;
		#endif /* ISB_OBJ_1BIT_MAX && ISB_OBJ_H_ */

		#if defined(ISB_OBJ_4BIT_MAX) && defined(ISB_OBJ_H_)
			Isb_Obj_4Bit_IrqExec++;
		#endif /* ISB_OBJ_4BIT_MAX && ISB_OBJ_H_ */

		#if defined(ISB_OBJ_8BIT_MAX) && defined(ISB_OBJ_H_)
			Isb_Obj_8Bit_IrqExec++;
		#endif /* ISB_OBJ_8BIT_MAX && ISB_OBJ_H_ */

		#if defined(ISB_OBJ_FLOAT_MAX) && defined(ISB_OBJ_H_)
			Isb_Obj_Float_IrqExec++;
		#endif /* ISB_OBJ_FLOAT_MAX && ISB_OBJ_H_ */

	}



	#if defined(__AVR_ATmega8__) || defined(__AVR_ATmega16__) || defined(__AVR_ATmega32__) || defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)
		ISR(TIMER0_COMP_vect) {
			Isb_Systick_Irq_Timer();
		}
	#elif defined(__AVR_ATmega48__) || defined(__AVR_ATmega88__) || defined(__AVR_ATmega168__)
		ISR(TIMER0_COMP_vect) {
			Isb_Systick_Irq_Timer();
		}
	#elif defined(__AVR_ATmega169P__) || defined(__AVR_ATmega169PV__)
		ISR(TIMER0_COMP_vect) {
			Isb_Systick_Irq_Timer();
		}
	#elif defined(__AVR_ATmega644__)
		ISR(TIMER0_COMP_vect) {
			Isb_Systick_Irq_Timer();
		}
	#elif defined(__AVR_AT90CAN32__) || defined(__AVR_AT90CAN64__) || defined(__AVR_AT90CAN128__)
		ISR(TIMER0_COMP_vect) {
			Isb_Systick_Irq_Timer();
		}
	#else
		#error "No definition for this MCU available."
	#endif



#endif /* ISB_SYSTICK_C_ */
