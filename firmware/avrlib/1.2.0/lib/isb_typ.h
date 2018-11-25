/**
 * @file		avrlib/trunk/lib/isb_typ.h
 *
 * @brief		iSysBus Types.
 *
 * This file includes iSysBus Types.
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





#ifndef ISB_TYP_H_
	#define ISB_TYP_H_



	typedef struct Isb_Msg_t Isb_Msg_t;
	struct Isb_Msg_t
	{
		uint8_t Flags;
		uint16_t DestId;
		uint16_t SourceId;
		uint8_t Data[8];
	};



#endif /* ISB_TYP_H_ */
