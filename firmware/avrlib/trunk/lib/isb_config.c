/**
 * @file		avrlib/trunk/lib/isb_config.c
 *
 * @brief		iSysBus Configuration.
 *
 * This file includes iSysBus Configuration.
 *
 * @author		© Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
 *
 * @date		$Date: 2010-05-28 11:38:03 +0200 (Fr, 28. Mai 2010) $
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





#ifndef ISB_SRV_CONFIG_C_
	#define ISB_SRV_CONFIG_C_



	void Isb_Config_Rx(Isb_Msg_t * aIsb_Msg) {
		uint8_t Dlc;
		Isb_Msg_t MsgTx;
		uint16_t Addr;
		Dlc = aIsb_Msg->Flags & ISB_MSG_FLAGS_DLC_MASK;
		MsgTx.Flags = aIsb_Msg->Flags;
		MsgTx.DestId = aIsb_Msg->SourceId;
		MsgTx.SourceId = Isb_Node_Id;
		for (uint8_t i = 0; i < Dlc; i++) {
			MsgTx.Data[i] = aIsb_Msg->Data[i];
		}
		if (aIsb_Msg->Data[0] == ISB_CONFIG_CMD_SETMODE) {
			if (Dlc == ISB_MSG_FLAGS_DLC_2) {
				MsgTx.Flags = ISB_MSG_FLAGS_TOF_UNICAST | ISB_MSG_FLAGS_DLC_2;
				MsgTx.Data[0] |= ISB_CONFIG_ANSWER_ACK;
				if (aIsb_Msg->Data[1] == ISB_NODE_OPERATING_MODE__BL_NORM) {
					lib_eep_write_byte((uint8_t *)EEP__ISB_NODE_OPERATING_MODE, ISB_NODE_OPERATING_MODE__BL_NORM);
				}
				if (aIsb_Msg->Data[1] == ISB_NODE_OPERATING_MODE__BL_FLASH) {
					lib_eep_write_byte((uint8_t *)EEP__ISB_NODE_OPERATING_MODE, ISB_NODE_OPERATING_MODE__BL_FLASH);
				}
				if (aIsb_Msg->Data[1] == ISB_NODE_OPERATING_MODE__FW_NORM) {
					uint8_t crc = lib_eep_read_byte((uint8_t *)EEP__ISB_CONFIG_CRC);
					crc++;
					lib_eep_write_byte((uint8_t *)EEP__ISB_CONFIG_CRC, crc);
					lib_eep_write_byte((uint8_t *)EEP__ISB_NODE_OPERATING_MODE, ISB_NODE_OPERATING_MODE__FW_NORM);
				}
				if (aIsb_Msg->Data[1] == ISB_NODE_OPERATING_MODE__FW_CFG) {
					lib_eep_write_byte((uint8_t *)EEP__ISB_NODE_OPERATING_MODE, ISB_NODE_OPERATING_MODE__FW_CFG);
				}
				Node_Reboot();
			}
		}
		else if (aIsb_Msg->Data[0] == ISB_CONFIG_CMD_INITEEPROM) {
			if (Dlc == ISB_MSG_FLAGS_DLC_1) {
				if (Isb_Node_Operating_Mode == ISB_NODE_OPERATING_MODE__FW_CFG) {
					MsgTx.Flags = ISB_MSG_FLAGS_TOF_UNICAST | ISB_MSG_FLAGS_DLC_1;
					MsgTx.Data[0] |= ISB_CONFIG_ANSWER_ACK;
					for (uint16_t ee_Addr = Isb_Firmware_Offset; ee_Addr < EEP_SIZE; ee_Addr++) {
						wdt_reset();
						lib_eep_write_byte((uint8_t *) ee_Addr, 0x00);
					}
					for (uint8_t i = 0; i < 4; i++) {
						lib_eep_write_byte((uint8_t *)(EEP__ISB_CONFIG_CODE_0 + i), Isb_Firmware_Code[i]);
					}
					Node_Reboot();
				}
			}
		}
		else if (aIsb_Msg->Data[0] == ISB_CONFIG_CMD_READEEPROMBLOCK) {
			if (Dlc > ISB_MSG_FLAGS_DLC_3) {
				Addr = (uint16_t)aIsb_Msg->Data[1] + (uint16_t)(aIsb_Msg->Data[2] << 8);
				if (Addr < EEP_SIZE) {
					MsgTx.Data[0] |= ISB_CONFIG_ANSWER_ACK;
					for (uint8_t i = 0; i < (Dlc - 3); i++) {
						MsgTx.Data[3 + i] = lib_eep_read_byte((uint8_t *)(Addr + i));
					}
				}
			}
		}
		else if (aIsb_Msg->Data[0] == ISB_CONFIG_CMD_WRITEEEPROMBLOCK) {
			if (Dlc > ISB_MSG_FLAGS_DLC_3) {
				if (Isb_Node_Operating_Mode == ISB_NODE_OPERATING_MODE__FW_CFG) {
					Addr = (uint16_t)aIsb_Msg->Data[1] + (uint16_t)(aIsb_Msg->Data[2] << 8);
					if ((Addr >= Isb_Firmware_Offset) & (Addr < EEP_SIZE)) {
						MsgTx.Data[0] |= ISB_CONFIG_ANSWER_ACK;
						for (uint8_t i = 0; i < (Dlc - 3); i++) {
							lib_eep_write_byte((uint8_t *)(Addr + i), aIsb_Msg->Data[3 + i]);
						}
					}
				}
			}
		}
		MsgTx.Data[0] |= ISB_CONFIG_ANSWER_NACK;
		Isb_SendMsg(&MsgTx);
	}



#endif /* ISB_SRV_CONFIG_C_ */
