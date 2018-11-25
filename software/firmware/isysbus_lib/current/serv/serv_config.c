/*! @file  serv_config.c
 * @brief  
 * @author Cosinus
 * @date   04.01.2007  
*/

#include "serv_config.h"

uint16_t node_address; 
uint16_t ee_node_address EEMEM = 15;

uint8_t serv_config_init(void)
{
    node_address = eeprom_read_word(&ee_node_address);
}

void serv_config_exec (message_t* msg ,data_t* response)
{
    uint8_t cmd = msg->data[0];
    uint8_t data0 = msg->data[1]; 
    uint8_t data1 = msg->data[2]; 
    uint8_t port = msg->data[3];
    uint8_t index = msg->data[4];
    
    if (port == 0)  //Knoten Config
    {
        if(index == 3) // KnotenId
        {
            if (cmd == CONFIG_CMD_READ) 
            {
                response->data[0] = 0x01; // OK
                response->data[1] = node_address >> 8;
                response->data[2] = (uint8_t) node_address; 
                response->length = 3;
            }
            if (cmd == CONFIG_CMD_WRITE)
            {
                node_address= data0 * 256 + data1;
                eeprom_write_byte(&ee_node_address,node_address);
                response->data[0] = 0x01; // OK
                response->length = 1;    
            }
        }
    }
}
                
                
    