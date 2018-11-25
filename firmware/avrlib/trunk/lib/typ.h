/**
 * @file		avrlib/trunk/lib/typ.h
 *
 * @brief		Types.
 *
 * This file includes Types.
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





#ifndef TYP_H_
	#define TYP_H_



	typedef union convert_w {
		unsigned int w;
		unsigned char b[2];
	} CONVERT_W;



	typedef union convert_dw {
		unsigned long dw;
		unsigned int w[2];
		unsigned char b[4];
	} CONVERT_DW;



#endif /* TYP_H_ */
