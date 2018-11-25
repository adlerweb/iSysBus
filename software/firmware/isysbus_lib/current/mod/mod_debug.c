/*! @file  mod_debug.c
 * @brief 
 * @author Cosinus
 * @date   20.09.2006
*/

#include <isysbus_typedef.h>
#include "mod_debug.h"
#ifdef Debug

//kopiert aus can.c
void mod_debug_uart_show(message_t *msg)
{
    uint8_t i;

    uart_puts_P("\n\niSysBus Message:\n");

    uart_puts_P("destination: ");			//destination
    uart_put_dec(msg->destination,4,' ');
    uart_puts_P(" 0x");
    uart_put_hex((msg->destination >> 8));
    uart_put_hex((uint8_t)msg->destination);
     
     
    uart_puts_P("\nsource: ");			//source
    uart_put_dec(msg->source,4,' ');
    uart_puts_P(" 0x");
    uart_put_hex(msg->source >> 8);
    uart_put_hex( (uint8_t) msg->source );

    uart_puts_P("\nport : 0x");			//Port
    uart_put_hex(msg->port);
    
    uart_puts_P("\nlength : 0x");			//length
    uart_put_hex(msg->length);
    uart_puts_P("\ndata: ");
    
    for (i=0;i<msg->length;i++) 			//Data
    {
      uart_put_hex(msg->data[i]);
      uart_puts_P(" ");
    }
    uart_puts_P("\nflags : 0x");			//Flags
    uart_put_hex(msg->flags);
    uart_puts_P("\n");

}
#endif
