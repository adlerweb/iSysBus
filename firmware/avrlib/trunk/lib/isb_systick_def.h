/**
 * @file		avrlib/trunk/lib/isb_systick_def.h
 *
 * @brief		iSysBus Systemtimer Defines.
 *
 * This file includes the iSysBus Systemtimer Defines.
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





#ifndef ISB_SYSTICK_DEF_H_
	#define ISB_SYSTICK_DEF_H_



	#define ISB_CTRL_SOFTIRQ_EXEC				0
//	#define ISB_CTRL_							1
//	#define ISB_OBJ_CTRL_WRITE					2
//	#define ISB_OBJ_CTRL_SEND					3
//	#define ISB_OBJ_CTRL_UPDATE					4
//	#define ISB_OBJ_CTRL_READONINIT				5
	#define ISB_CTRL_RUNNING					6
	#define ISB_CTRL_RESTORE					7



#endif /* ISB_SYSTICK_DEF_H_ */
