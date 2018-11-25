#ifndef MODUL_LOADER_H_
#define MODUL_LOADER_H_
/*! @file  modul_loader.h
   * @brief Dient zum automatischen einbinden von Software-Modulen
   * @author Cosinus
   * @date   11.11.2006
   */
#endif /*MODUL_LOADER_H_*/

#ifdef IF_CAN
#include <if/if_can.h>
#endif

#ifdef MOD_SPI
#include <mod/mod_spi.h>
#endif

#ifdef MOD_MCP2515
#include <mod/mod_mcp2515.h>
#endif

#ifdef MOD_UART
#include <mod/mod_uart.h>
#endif

#ifdef SERV_PING
#include <serv/serv_ping.h>
#endif

#ifdef SERV_IO
#include <serv/serv_io.h>
#endif

#ifdef SERV_OUTPUT
#include <serv/serv_output.h>
#endif
