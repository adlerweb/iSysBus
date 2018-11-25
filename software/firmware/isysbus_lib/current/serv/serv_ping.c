/*! @file  serv_ping.c
 * @brief Ein einfacher Ping Dienst, Sendet alles zurück 
 * @author Cosinus
 * @date   09.11.2006  
*/

#include <inttypes.h>
#include <isysbus_typedef.h>



void serv_ping_exec (pmessage_t msg, pdata_t response)
{

    response->length = msg->length;
    for (uint8_t i=0; i < msg->length; i++){ response->data[i] = msg->data[i];}
  }

