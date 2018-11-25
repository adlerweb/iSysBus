/**
 * @file		avrlib/trunk/lib/isb_grp.c
 *
 * @brief		iSysBus Groups.
 *
 * This file includes iSysBus Groups.
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





#ifndef ISB_GRP_C_
	#define ISB_GRP_C_



	void Isb_Grp_Init(void) {
		for (uint8_t GrpIndex = 0; GrpIndex < ISB_GRP_MAX; GrpIndex++) {
			Isb_Grp[GrpIndex].Id = lib_eep_fw_read_byte((uint8_t *)(ISB_GRP_EEADDR_START + GrpIndex * 3));
			Isb_Grp[GrpIndex].Id |= lib_eep_fw_read_byte((uint8_t *)(ISB_GRP_EEADDR_START + GrpIndex * 3 + 1)) << 8;
			Isb_Grp[GrpIndex].Obj = lib_eep_fw_read_byte((uint8_t *)(ISB_GRP_EEADDR_START + GrpIndex * 3 + 2));
		}
	}



#endif /* ISB_GRP_C_ */
