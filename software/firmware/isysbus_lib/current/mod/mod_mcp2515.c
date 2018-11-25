/*! @file  mod_mcp2515.c
 * @brief Lesen und schreiben in den mcp2515 
 * @author Cosinus
 * @date   21.08.2006  
*/
#include <isysbus_typedef.h>
#include <mod/mod_spi.h>
#include <mod/mod_mcp2515_defs.h>


void mod_mcp2515_write( uint8_t adress, uint8_t data )
{
    SS_LOW();
    
    mod_spi_readwrite(MCP_WRITE); 
    mod_spi_readwrite(adress);
    mod_spi_readwrite(data);
    
    SS_HIGH();
}


uint8_t mod_mcp2515_read(uint8_t adress)
{
    uint8_t data;
    
    SS_LOW();
    
    mod_spi_readwrite(MCP_READ);
    mod_spi_readwrite(adress);
    data = mod_spi_readwrite(0xff);  
    
    SS_HIGH();
    
    return data;
}

//von kreatives-chaos.com
void mod_mcp2515_modify(uint8_t adress, uint8_t mask, uint8_t data)
{
    SS_LOW();

    mod_spi_readwrite(MCP_BITMOD);
    mod_spi_readwrite(adress);
    mod_spi_readwrite(mask);
    mod_spi_readwrite(data);

    SS_HIGH();
}

