/**
 * @file		avrlib/trunk/lib/isb_ch.h
 *
 * @brief		iSysBus Channel.
 *
 * This file includes the iSysBus Channel.
 *
 * @author		© Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
 *
 * @date		$Date: 2011-05-13 23:11:50 +0200 (Fr, 13. Mai 2011) $
 *
 * @version		$Rev: 4475 $
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





#ifndef ISB_CH_H_
	#define ISB_CH_H_



	#if defined(ISB_CH_MAX)

		typedef struct Isb_Ch_t Isb_Ch_t;

		struct Isb_Ch_t {
			uint16_t Ctrl;
		};

		Isb_Ch_t Isb_Ch[ISB_CH_MAX];

	#endif /* ISB_CH_MAX */



	void Isb_Ch_Init(void);



#endif /* ISB_CH_H_ */
