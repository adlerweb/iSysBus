/*! @file  file
 * @brief Dient zum automatischen einbinden von Software-Modulen 
 * @author Cosinus
 * @date   11.11.2006  
*/

#include <modul_loader.h>

#ifdef IF_CAN
#include <if/if_can.c>
#endif

#ifdef MOD_SPI
#include <mod/mod_spi.c>
#endif

#ifdef MOD_MCP2515
#include <mod/mod_mcp2515.c>
#endif

#ifdef SERV_IO
#include <serv/serv_io.c>
#endif

#ifdef SERV_PING
#include <serv/serv_ping.c>
#endif

#ifdef MOD_UART
#include <mod/mod_uart.c>
#endif

#ifdef SERV_OUTPUT
#include <serv/serv_output.c>
#endif
