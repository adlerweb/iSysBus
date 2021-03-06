/**
 * @file		avrlib/trunk/lib/isb_grp.h
 *
 * @brief		iSysBus Groups.
 *
 * This file includes iSysBus Groups.
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





#ifndef ISB_GRP_H_
	#define ISB_GRP_H_



	typedef struct Isb_Grp_t Isb_Grp_t;

	struct Isb_Grp_t {
		uint16_t Id;
		uint8_t Obj;
	};

	Isb_Grp_t Isb_Grp[ISB_GRP_MAX];



	void Isb_Grp_Init(void);



#endif /* ISB_GRP_H_ */
