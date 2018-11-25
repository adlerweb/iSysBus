#ifndef SERV_CONFIG_H_
#define SERV_CONFIG_H_

#include <inttypes.h>
#include <isysbus_typedef.h>
#include <avr/eeprom.h>

#define SERV_CONFIG_PORT 138

extern uint16_t node_address;
extern uint16_t ee_node_address EEMEM;

uint8_t serv_config_init(void);
void serv_config_exec (message_t* msg ,data_t* response);

#define CONFIG_CMD_READ 0x01
#define CONFIG_CMD_WRITE 0x02
#define CONFIG_CMD_CHILDCOUNT 0x03

#endif /*SERV_CONFIG_H_*/
