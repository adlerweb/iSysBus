/*! @file  file
 * @brief  
 * @author Cosinus
 * @date   11.11.2006  
*/

#include "modul_functions.h"

void modules_init(void)
{
#ifdef IF_CAN
  if_can_init();
#endif

#ifdef SERV_IO 
  serv_io_init();
#endif 

#ifdef MOD_UART
  uart_init(); 
#endif

#ifdef SERV_OUTPUT
  serv_output_init();
#endif
    
}

void process_services(pmessage_t msg, pdata_t response)
{
  uint16_t index= ((msg->data[0] & 0x0F) * 256 ) + msg->data[1];
  uint8_t aktion = (msg->data[0] >> 4) & 0x0F;   //testen ob ohne carry geschoben wird

  
  #ifdef SERV_IO
  if (msg->port == SERV_IO_PORT) { serv_io_exec(aktion,index,msg->data[0], response);};
  #endif

  #ifdef SERV_MANAGEMENT
 // if (msg->port == SERV_MANAGEMENT_PORT) { serv_management_exec(msg, response);};
  #endif
  
  #ifdef SERV_PING
  if (msg->port == SERV_PING_PORT) { serv_ping_exec(msg, response);};
  #endif
  
  #ifdef SERV_OUTPUT
  if (msg->port == SERV_OUTPUT_PORT) { serv_output_exec(aktion,index,msg->data[0], response);};
  #endif 
}
