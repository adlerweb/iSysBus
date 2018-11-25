/**
 * @file		avrlib/trunk/core/isb_fw_switch.c
 *
 * @brief		iSysBus Firmware-Switch-Core.
 *
 * This file includes the iSysBus Firmware-Switch-Core.
 *
 * @author		© Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
 *
 * @date		$Date: 2011-09-05 01:44:12 +0200 (Mo, 05. Sep 2011) $
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





#ifndef ISB_FW_SWITCH_C_
	#define ISB_FW_SWITCH_C_



	#include "./../lib/lib_pin_def.h"

	#include "./../lib/lib_eep.h"
	#include "./../lib/lib_pin.h"



	void Node_Reboot(void);
	void Isb_SendMsg(Isb_Msg_t * aMsg);



	uint16_t Isb_Node_Id = 0;
	uint8_t Isb_Firmware_Offset = 0;
	uint8_t Isb_Node_Operating_Mode = 0;
	uint8_t Error = 0;



	#include "./../lib/lib_eep.c"
	#include "./../lib/lib_pin.c"



	#if ISB_INF_USART0 == 1 || ISB_INF_USART1 == 1
		#include "./../lib/isb_inf_usart_def.h"
		#include "./../lib/inf_usart_def.h"
		#include "./../lib/isb_inf_usart.h"
		#include "./../lib/inf_usart.h"
		#include "./../lib/lib_crc.h"
		#include "./../lib/lib_crc.c"
		#include "./../lib/inf_usart.c"
		#include "./../lib/isb_inf_usart.c"
	#endif /* ISB_INF_USART0 == 1 || ISB_INF_USART1 == 1 */



	#if ISB_INF_CAN0 == 1 || ISB_INF_CAN1 == 1 || ISB_INF_CAN2 == 1
		#include "./../lib/isb_inf_can_def.h"
		#include "./../lib/inf_can_def.h"
		#include "./../lib/lib_mcp2515_def.h"
		#include "./../lib/inf_spi_def.h"
		#include "./../lib/isb_inf_can.h"
		#include "./../lib/inf_can.h"
		#include "./../lib/lib_mcp2515.h"
		#include "./../lib/inf_spi.h"
		#include "./../lib/inf_spi.c"
		#include "./../lib/lib_mcp2515.c"
		#include "./../lib/inf_can.c"
		#include "./../lib/isb_inf_can.c"
	#endif /* ISB_INF_CAN0 == 1 || ISB_INF_CAN1 == 1 || ISB_INF_CAN2 == 1 */



	#if ISB_INF_USART0_SLAVE == 1 || ISB_INF_USART1_SLAVE == 1
		#include "./../lib/isb_inf_usart_slave_def.h"
		#include "./../lib/inf_usart_def.h"
		#include "./../lib/isb_inf_usart_slave.h"
		#include "./../lib/inf_usart.h"
		#include "./../lib/lib_crc.h"
		#include "./../lib/lib_crc.c"
		#include "./../lib/inf_usart.c"
		#include "./../lib/isb_inf_usart_slave.c"
	#endif /* ISB_INF_USART0_SLAVE == 1 || ISB_INF_USART1_SLAVE == 1 */



	#define ISB_SRV_CONFIG_PASS 0x0123
	#include "./../lib/isb_config_def.h"
	#include "./../lib/isb_config.h"
	#include "./../lib/isb_config.c"



	#include "./../lib/isb_systick_def.h"
	#include "./../lib/isb_systick.h"
	#include "./../lib/isb_ch_def.h"
	#include "./../lib/isb_ch.h"
	#include "./../lib/isb_app_def.h"
	#include "./../lib/isb_app.h"
	#include "./../lib/isb_obj_def.h"
	#include "./../lib/isb_obj.h"
	#include "./../lib/isb_grp_def.h"
	#include "./../lib/isb_grp.h"



	#if defined(LIB_ADC)
		#include "./../lib/lib_adc_def.h"
		#include "./../lib/lib_adc.h"
	#endif /* LIB_ADC */

	#if defined(INF_TWI) | defined(LIB_DS1621)
		#include "./../lib/inf_twi_def.h"
		#include "./../lib/inf_twi.h"
	#endif /* INF_TWI | LIB_DS1621 */

	#if defined(LIB_DS1621)
		#include "./../lib/lib_ds1621_def.h"
		#include "./../lib/lib_ds1621.h"
	#endif /* LIB_DS1621 */

	#if defined(LIB_LCD)
		#include "./../lib/lib_lcd_def.h"
		#include "./../lib/lib_lcd.h"
	#endif /* LIB_LCD */

	#if defined(LIB_LCD)
		#include "./../lib/lib_lcd.c"
	#endif /* LIB_LCD */

	#if defined(LIB_DS1621)
		#include "./../lib/lib_ds1621.c"
	#endif /* LIB_DS1621 */

	#if defined(INF_TWI) | defined(LIB_DS1621)
		#include "./../lib/inf_twi.c"
	#endif /* INF_TWI | LIB_DS1621 */

	#if defined(LIB_ADC)
		#include "./../lib/lib_adc.c"
	#endif /* LIB_ADC */



	#include "./../lib/isb_systick.c"
	#include "./../lib/isb_ch.c"
	#include "./../lib/isb_app.c"
	#include "./../lib/isb_obj.c"
	#include "./../lib/isb_grp.c"



	void Node_Reboot(void) {
		while (1) ;
	}



	void Isb_SendMsg(Isb_Msg_t * aMsg) {
		#if ISB_INF_USART0 == 1
			Isb_Inf_Usart_Tx(0, aMsg);
		#endif /* ISB_INF_USART0 == 1 */
		#if ISB_INF_USART1 == 1
			Isb_Inf_Usart_Tx(1, aMsg);
		#endif /* ISB_INF_USART1 == 1 */
		#if ISB_INF_CAN0 == 1
			Isb_Inf_Can_Tx(0, aMsg);
		#endif /* ISB_INF_CAN0 == 1 */
		#if ISB_INF_CAN1 == 1
			Isb_Inf_Can_Tx(1, aMsg);
		#endif /* ISB_INF_CAN1 == 1 */
		#if ISB_INF_CAN2 == 1
			Isb_Inf_Can_Tx(2, aMsg);
		#endif /* ISB_INF_CAN2 == 1 */
		if ((aMsg->Flags & ISB_MSG_FLAGS_TOF_MASK) == ISB_MSG_FLAGS_TOF_MULTICAST) {
			if (Error == 0) {
				Isb_Obj_Rx(aMsg);
			}
		}
	}



	int main(void) {
		wdt_enable(WDTO_500MS);
		wdt_reset();
		Isb_Node_Id = lib_eep_read_word((uint16_t *)EEP__ISB_NODE_ID_0);
		if ((Isb_Node_Id == 0) | (Isb_Node_Id > 2047)) {
			lib_eep_write_byte((uint8_t *)EEP__ISB_NODE_OPERATING_MODE, ISB_NODE_OPERATING_MODE__BL_NORM);
			Node_Reboot();
		}
		for (uint8_t i = 0; i < 4; i++) {
			lib_eep_write_byte((uint8_t *)(EEP__ISB_FIRMWARE_CODE_0 + i), Isb_Firmware_Code[i]);
		}
		Isb_Firmware_Offset = lib_eep_read_byte((uint8_t *)EEP__ISB_FIRMWARE_OFFSET);
		Isb_Node_Operating_Mode = lib_eep_read_byte((uint8_t *)EEP__ISB_NODE_OPERATING_MODE);
		if ((Isb_Node_Operating_Mode != ISB_NODE_OPERATING_MODE__FW_NORM) & (Isb_Node_Operating_Mode != ISB_NODE_OPERATING_MODE__FW_CFG))
		{
			Isb_Node_Operating_Mode = ISB_NODE_OPERATING_MODE__FW_NORM;
			lib_eep_write_byte((uint8_t *)EEP__ISB_NODE_OPERATING_MODE, Isb_Node_Operating_Mode);
		}
		for (uint8_t i = 0; i < 4; i++)
		{
			if (lib_eep_read_byte((uint8_t *)(EEP__ISB_CONFIG_CODE_0 + i)) != Isb_Firmware_Code[i])
			{
				Error |= ERROR__CONFIG_CODE;
			}
		}
		#if defined(INF_TWI_C_)
			Inf_Twi_Init(0, 12);
// TODO:
Lib_Pin_Set(4, 2, LIB_PIN_OUTPUT_HIGH);
		#endif /* INF_TWI_C_ */
		if (Error == 0) {
			Isb_Systick_Init();
			Isb_Ch_Init();
			Isb_Grp_Init();
			Isb_Obj_Init();
			Isb_Obj_Exec();
			Isb_App_Init();
			Isb_App_Exec();
		}
		sei();
		#if ISB_INF_USART0 == 1
			Isb_Inf_Usart_Init(0);
		#endif /* ISB_INF_USART0 == 1 */
		#if ISB_INF_USART1 == 1
			Isb_Inf_Usart_Init(1);
		#endif /* ISB_INF_USART1 == 1 */
		#if ISB_INF_CAN0 == 1
			Isb_Inf_Can_Init(0);
		#endif /* ISB_INF_CAN0 == 1 */
		#if ISB_INF_CAN1 == 1
			Isb_Inf_Can_Init(1);
		#endif /* ISB_INF_CAN1 == 1 */
		#if ISB_INF_CAN2 == 1
			Isb_Inf_Can_Init(2);
		#endif /* ISB_INF_CAN2 == 1 */
		#if ISB_INF_USART0_SLAVE == 1
			Isb_Inf_Usart_Slave_Init(0);
		#endif /* ISB_INF_USART0_SLAVE == 1 */
		#if ISB_INF_USART1_SLAVE == 1
			Isb_Inf_Usart_Slave_Init(1);
		#endif /* ISB_INF_USART1_SLAVE == 1 */
		Isb_Msg_t Isb_Msg;
		Isb_Msg.Flags = ISB_MSG_FLAGS_TOF_MULTICAST | ISB_MSG_FLAGS_DLC_7;
		Isb_Msg.DestId = ISB_MSG_MULTICAST_GROUPID_FW_START;
		Isb_Msg.SourceId = Isb_Node_Id;
		Isb_Msg.Data[0] = ISB_MSG_TOP__SERIAL_NUMBER__MODE__ERROR;
		for (uint8_t i = 0; i < 4; i++) {
			Isb_Msg.Data[i + 1] = lib_eep_read_byte((uint8_t *)(EEP__ISB_NODE_SERIAL_NUMBER_0 + i));
		}
		Isb_Msg.Data[5] = lib_eep_read_byte((uint8_t *)EEP__ISB_NODE_OPERATING_MODE);
		Isb_Msg.Data[6] = Error;
		Isb_SendMsg(&Isb_Msg);
		for (;;) {
			wdt_reset();
			if (Error == 0) {
				Isb_Systick_Exec();
				Isb_Obj_Exec();
				Isb_App_Exec();
			}
			#if ISB_INF_USART0 == 1
				if (Isb_Inf_Usart_Rx(0, &Isb_Msg) == TRUE) {
					#if ISB_INF_USART1 == 1
						Isb_Inf_Usart_Tx(1, &Isb_Msg);
					#endif /* ISB_INF_USART1 == 1 */
					#if ISB_INF_CAN0 == 1
						Isb_Inf_Can_Tx(0, &Isb_Msg);
					#endif /* ISB_INF_CAN0 == 1 */
					#if ISB_INF_CAN1 == 1
						Isb_Inf_Can_Tx(1, &Isb_Msg);
					#endif /* ISB_INF_CAN1 == 1 */
					#if ISB_INF_CAN2 == 1
						Isb_Inf_Can_Tx(2, &Isb_Msg);
					#endif /* ISB_INF_CAN2 == 1 */
					if ((Isb_Msg.Flags & ISB_MSG_FLAGS_TOF_MASK) == ISB_MSG_FLAGS_TOF_UNICAST) {
						if (Isb_Msg.DestId == Isb_Node_Id) {
							Isb_Config_Rx(&Isb_Msg);
						}
					}
					if ((Isb_Msg.Flags & ISB_MSG_FLAGS_TOF_MASK) == ISB_MSG_FLAGS_TOF_MULTICAST) {
						if (Error == 0) {
							Isb_Obj_Rx(&Isb_Msg);
						}
					}
				}
			#endif /* ISB_INF_USART0 == 1 */
			#if ISB_INF_USART1 == 1
				if (Isb_Inf_Usart_Rx(0, &Isb_Msg) == TRUE) {
					#if ISB_INF_USART0 == 1
						Isb_Inf_Usart_Tx(0, &Isb_Msg);
					#endif /* ISB_INF_USART0 == 1 */
					#if ISB_INF_CAN0 == 1
						Isb_Inf_Can_Tx(0, &Isb_Msg);
					#endif /* ISB_INF_CAN0 == 1 */
					#if ISB_INF_CAN1 == 1
						Isb_Inf_Can_Tx(1, &Isb_Msg);
					#endif /* ISB_INF_CAN1 == 1 */
					#if ISB_INF_CAN2 == 1
						Isb_Inf_Can_Tx(2, &Isb_Msg);
					#endif /* ISB_INF_CAN2 == 1 */
					if ((Isb_Msg.Flags & ISB_MSG_FLAGS_TOF_MASK) == ISB_MSG_FLAGS_TOF_UNICAST) {
						if (Isb_Msg.DestId == Isb_Node_Id) {
							Isb_Config_Rx(&Isb_Msg);
						}
					}
					if ((Isb_Msg.Flags & ISB_MSG_FLAGS_TOF_MASK) == ISB_MSG_FLAGS_TOF_MULTICAST) {
						if (Error == 0) {
							Isb_Obj_Rx(&Isb_Msg);
						}
					}
				}
			#endif /* ISB_INF_USART1 == 1 */
			#if ISB_INF_CAN0 == 1
				if (Isb_Inf_Can_Rx(0, &Isb_Msg) == TRUE) {
					#if ISB_INF_USART0 == 1
						Isb_Inf_Usart_Tx(0, &Isb_Msg);
					#endif /* ISB_INF_USART0 == 1 */
					#if ISB_INF_USART1 == 1
						Isb_Inf_Usart_Tx(1, &Isb_Msg);
					#endif /* ISB_INF_USART1 == 1 */
					#if ISB_INF_CAN1 == 1
						Isb_Inf_Can_Tx(1, &Isb_Msg);
					#endif /* ISB_INF_CAN1 == 1 */
					#if ISB_INF_CAN2 == 1
						Isb_Inf_Can_Tx(2, &Isb_Msg);
					#endif /* ISB_INF_CAN2 == 1 */
					if ((Isb_Msg.Flags & ISB_MSG_FLAGS_TOF_MASK) == ISB_MSG_FLAGS_TOF_UNICAST) {
						if (Isb_Msg.DestId == Isb_Node_Id) {
							Isb_Config_Rx(&Isb_Msg);
						}
					}
					if ((Isb_Msg.Flags & ISB_MSG_FLAGS_TOF_MASK) == ISB_MSG_FLAGS_TOF_MULTICAST) {
						if (Error == 0) {
							Isb_Obj_Rx(&Isb_Msg);
						}
					}
				}
			#endif /* ISB_INF_CAN0 == 1 */
			#if ISB_INF_CAN1 == 1
				if (Isb_Inf_Can_Rx(0, &Isb_Msg) == TRUE) {
					#if ISB_INF_USART0 == 1
						Isb_Inf_Usart_Tx(0, &Isb_Msg);
					#endif /* ISB_INF_USART0 == 1 */
					#if ISB_INF_USART1 == 1
						Isb_Inf_Usart_Tx(1, &Isb_Msg);
					#endif /* ISB_INF_USART1 == 1 */
					#if ISB_INF_CAN0 == 1
						Isb_Inf_Can_Tx(0, &Isb_Msg);
					#endif /* ISB_INF_CAN0 == 1 */
					#if ISB_INF_CAN2 == 1
						Isb_Inf_Can_Tx(2, &Isb_Msg);
					#endif /* ISB_INF_CAN2 == 1 */
					if ((Isb_Msg.Flags & ISB_MSG_FLAGS_TOF_MASK) == ISB_MSG_FLAGS_TOF_UNICAST) {
						if (Isb_Msg.DestId == Isb_Node_Id) {
							Isb_Config_Rx(&Isb_Msg);
						}
					}
					if ((Isb_Msg.Flags & ISB_MSG_FLAGS_TOF_MASK) == ISB_MSG_FLAGS_TOF_MULTICAST) {
						if (Error == 0) {
							Isb_Obj_Rx(&Isb_Msg);
						}
					}
				}
			#endif /* ISB_INF_CAN1 == 1 */
			#if ISB_INF_CAN2 == 1
				if (Isb_Inf_Can_Rx(0, &Isb_Msg) == TRUE) {
					#if ISB_INF_USART0 == 1
						Isb_Inf_Usart_Tx(0, &Isb_Msg);
					#endif /* ISB_INF_USART0 == 1 */
					#if ISB_INF_USART1 == 1
						Isb_Inf_Usart_Tx(1, &Isb_Msg);
					#endif /* ISB_INF_USART1 == 1 */
					#if ISB_INF_CAN0 == 1
						Isb_Inf_Can_Tx(0, &Isb_Msg);
					#endif /* ISB_INF_CAN0 == 1 */
					#if ISB_INF_CAN1 == 1
						Isb_Inf_Can_Tx(1, &Isb_Msg);
					#endif /* ISB_INF_CAN1 == 1 */
					if ((Isb_Msg.Flags & ISB_MSG_FLAGS_TOF_MASK) == ISB_MSG_FLAGS_TOF_UNICAST) {
						if (Isb_Msg.DestId == Isb_Node_Id) {
							Isb_Config_Rx(&Isb_Msg);
						}
					}
					if ((Isb_Msg.Flags & ISB_MSG_FLAGS_TOF_MASK) == ISB_MSG_FLAGS_TOF_MULTICAST) {
						if (Error == 0) {
							Isb_Obj_Rx(&Isb_Msg);
						}
					}
				}
			#endif /* ISB_INF_CAN2 == 1 */
		}
	}



#endif /* ISB_FW_SWITCH_C_ */
