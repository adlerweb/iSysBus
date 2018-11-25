#ifndef MOD_MCP2515_H_
#define MOD_MCP2515_H_


/* 125 khz bei 8MHZ by Microchip Can bit rate calculator
CNF1/BRGCON1    b'00000001'     0x01
CNF2/BRGCON2    b'10111000'     0xB8
CNF3/BRGCON3    b'00000101'     0x05
*/
#define MOD_MCP2515

#include <mod/mod_mcp2515_defs.h>

void mod_mcp2515_write( uint8_t adress, uint8_t data );

uint8_t mod_mcp2515_read(uint8_t adress);

void mod_mcp2515_modify(uint8_t adress, uint8_t mask, uint8_t data);


#endif /*MOD_MCP2515_H_*/
