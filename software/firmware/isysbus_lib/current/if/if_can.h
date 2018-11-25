#ifndef IF_CAN_H_
#define IF_CAN_H_
/*! @file  if_can.h
 * @brief can Interface 
 * @author Cosinus
 * @date   20.08.2006  
*/

#include <if/if_can_conf.h>
#include <avr/io.h>
#include <isysbus_typedef.h>



uint8_t if_can_init(void);

uint8_t if_can_send(pmessage_t msg);

uint8_t if_can_receive(pmessage_t msg);

#ifdef en_standardcan
extern volatile uint8_t if_can_exide;
extern volatile uint8_t if_can_lastextframe;
#endif

//#ifdef debug
extern volatile uint8_t if_can_init_value;
//#endif

#endif /*IF_CAN_H__*/
