/*! @file  if_can.c
 * @brief iSysBus Can Interface,im moment mit einem buffer 
 * @author Cosinus
 * @date   21.08.2006  
*/
#include <isysbus_typedef.h>
#include <mod/mod_spi.h>
#include <mod/mod_mcp2515.h>
#include <if/if_can.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void mcp2515_initCANBuffers(void);

#ifdef en_standardcan
volatile uint8_t if_can_exide = _BV(3);
volatile uint8_t if_can_lastextframe = 1;
#endif

//#ifdef debug
volatile uint8_t if_can_init_value = 0;
//#endif

//von kreatives-chaos.com, unter GPL

uint8_t if_can_init(void)
{   
    uint8_t sreg_temp;
    sreg_temp = SREG;
    
    mod_spi_init();
    
    //Reset
    SS_LOW();
    mod_spi_readwrite( MCP_RESET );
    SS_HIGH();
    
    _delay_ms(2);
    
    mcp2515_initCANBuffers();
    
    //Geschwindigkeit konfigurieren    
    mod_mcp2515_write( MCP_CNF1, IF_CAN_CNF1 );
    mod_mcp2515_write( MCP_CNF2, IF_CAN_CNF2 );
    mod_mcp2515_write( MCP_CNF3, IF_CAN_CNF3 );
    
    
    
    // Alles Empfangen, inclusive RTR (MCP2515 Doku seite 27)
    mod_mcp2515_write( MCP_RXB0CTRL, _BV(6)|_BV(5)|_BV(3));
    mod_mcp2515_write( MCP_RXB1CTRL, _BV(6)|_BV(5)|_BV(3));
       

    //Betriebsmoduls setzen
    mod_mcp2515_modify( MCP_CANCTRL, 0xE0, IF_CAN_MODE);

    //�berpr�fen, ob Betriebsmodus richtig gesetzt wurde
    uint8_t canctrl = mod_mcp2515_read( MCP_CANCTRL );
  	if_can_init_value = canctrl;
    canctrl &= 0xE0;
    if ((canctrl ) == IF_CAN_MODE) {return 1; }
    else {
        return 0;
    }
    SREG = sreg_temp;
}
    

uint8_t if_can_send(pmessage_t msg)
{
    uint8_t sreg_temp;
    sreg_temp = SREG;
        
    uint8_t status, address;

     // Status des MCP2515 auslesen
     SS_LOW();
     mod_spi_readwrite(MCP_READ_STATUS);
     status = mod_spi_readwrite(0xff);
     mod_spi_readwrite(0xff);
     SS_HIGH();

     /* Statusbyte:
      *
      * Bit     Funktion
      *  2     TXB0CNTRL.TXREQ
      *  4     TXB1CNTRL.TXREQ
      *  6     TXB2CNTRL.TXREQ
      */

     if (bit_is_clear(status, 2)) {
          address = 0x00;
     }
     else if (bit_is_clear(status, 4)) {
          address = 0x02;
     }
     else if (bit_is_clear(status, 6)) {
          address = 0x04;
     }
     else {
          /* Alle Puffer sind belegt,
             Nachricht kann nicht verschickt werden */
          SREG = sreg_temp;
          return 0;
     }

     SS_LOW();          // CS Low
     mod_spi_readwrite(MCP_LOAD_TX0 | address);

     // Standard ID einstellen
     mod_spi_readwrite( msg->port );
     //SIDL
     uint8_t dhigh=(msg->destination>>8);
     uint8_t dlow =(msg->destination & 0xFF);
     uint8_t sidl=(uint8_t)(dhigh<<5) + (uint8_t)(dlow >>6);
#ifdef en_standardcan
	 sidl|=if_can_exide;
#else
     sidl|=_BV(3); //Extended frame senden !!! Doku seite 20
#endif
     mod_spi_readwrite( sidl );
     
     // Extended ID high
     uint8_t shigh=(msg->source>>8);
     uint8_t eidh=(dlow <<2) + (shigh & 0x03);
     mod_spi_readwrite( eidh );
     // Extended ID low
     mod_spi_readwrite((uint8_t)msg->source);

     uint8_t length = msg->length;

     if (length > 8) {
          length = 8;
     }

     // Ist die Nachricht ein "Remote Transmit Request" ?
     if (msg->flags & _BV(MSG_RTR))
     {
          /* Ein RTR hat zwar eine L�nge,
             aber enth�lt keine Daten */

          // Nachrichten L�nge + RTR einstellen
          mod_spi_readwrite(MCP_RTR_MASK | length);
     }
     else
     {
          // Nachrichten L�nge einstellen
          mod_spi_readwrite(length);

          // Daten
          for (uint8_t i=0;i<length;i++) {
               mod_spi_readwrite(msg->data[i]);
          }
     }
     SS_HIGH();         // CS auf High

     asm volatile ("nop");

     /* CAN Nachricht verschicken
        die letzten drei Bit im RTS Kommando geben an welcher
        Puffer gesendet werden soll */
     SS_LOW();          // CS wieder Low
     if (address == 0x00) {
          mod_spi_readwrite(MCP_RTS_TX0);
     } else {
          mod_spi_readwrite(0x80 | address);
     }
     SS_HIGH();          // CS auf High

     SREG = sreg_temp;
     return 1;
};

uint8_t if_can_receive(pmessage_t msg)
{   
    uint8_t sreg_temp;
    sreg_temp = SREG;
    
	msg->flags = 0;
// Status auslesen
    uint8_t status = mod_mcp2515_read(MCP_CANINTF);
    /* RX0_IF = 0 (bit0)
     * RX1_IF = 1 */

    if ( status & MCP_RX0IF_MASK )
    {
        // Nachricht in Puffer 0

        SS_LOW();
        mod_spi_readwrite(MCP_READ_RX0);
    }
    else if (status & MCP_RX1IF_MASK)
    {
        // Nachricht in Puffer 1

        SS_LOW();
        mod_spi_readwrite(MCP_READ_RX1);
    }
    else {
        /* Fehler: Keine neue Nachricht vorhanden */
        
        SREG = sreg_temp;
        return 0x00;
    }

    // Standard ID auslesen
    //SIDH 
    msg->port=mod_spi_readwrite(0x00);
    
    //SIDL
    uint8_t SIDL=mod_spi_readwrite(0x00);
    //msg->destination = (SIDL >> 5) * 0xFF;
    
#ifdef en_standardcan
    if(SIDL & _BV(3))
    	if_can_lastextframe = 1;
    else
    	if_can_lastextframe = 0;
#endif
 
    //EID8 
    uint8_t EID8=mod_spi_readwrite(0x00);
    msg->destination = (uint8_t)(EID8 >> 2) 
                     + (uint8_t)(SIDL << 6) 
                     + (SIDL >> 5) * 256;
    //EID0
    uint8_t EID0=mod_spi_readwrite(0x00);
    msg->source = (uint8_t)(EID0) + (EID8 & 0x03) * 256; 

    // L�nge auslesen
    //RTR DLC bit 6
    uint8_t length = mod_spi_readwrite(0x00);
    //RTR flag setzten
    if (length & _BV(6)){msg->flags |= _BV(MSG_RTR);} 
    else {msg->flags &= ~_BV(MSG_RTR);}
    
    length &= 0x0f; // RTR rausfilter, es blei nur die l�nge �brig
    msg->length =length; 

    // Daten auslesen
    for (uint8_t i=0;i<length;i++) {
        msg->data[i] = mod_spi_readwrite(0x00);
    }

    SS_HIGH();
  //Interrupt Flag wir beim spi-command automatisch gel�scht??
    // Interrupt Flag l�schen
    if (bit_is_set(status,0)) {
        mod_mcp2515_modify( MCP_CANINTF, _BV(0), 0);
    } else {
        mod_mcp2515_modify( MCP_CANINTF, _BV(1), 0);
    }

    SREG = sreg_temp;
    return 1;    
}

//Achtung: nur zum testen: Copyright checken 
void mcp2515_initCANBuffers(void)
{
    uint8_t i, a1, a2, a3;
    
    // TODO: check why this is needed to receive extended 
    //   and standard frames
    // Mark all filter bits as don't care:
  /*  mcp2515_write_can_id(MCP_RXM0SIDH, 0, 0);
    mcp2515_write_can_id(MCP_RXM1SIDH, 0, 0);
    // Anyway, set all filters to 0:
    mcp2515_write_can_id(MCP_RXF0SIDH, 1, 0); // RXB0: extended 
    mcp2515_write_can_id(MCP_RXF1SIDH, 0, 0); //       AND standard
    mcp2515_write_can_id(MCP_RXF2SIDH, 1, 0); // RXB1: extended 
    mcp2515_write_can_id(MCP_RXF3SIDH, 0, 0); //       AND standard
    mcp2515_write_can_id(MCP_RXF4SIDH, 0, 0);
    mcp2515_write_can_id(MCP_RXF5SIDH, 0, 0);     */
    
    // Clear, deactivate the three transmit buffers
    // TXBnCTRL -> TXBnD7
    a1 = MCP_TXB0CTRL;
    a2 = MCP_TXB1CTRL;
    a3 = MCP_TXB2CTRL;
    for (i = 0; i < 14; i++) { // in-buffer loop
        mod_mcp2515_write(a1, 0);
        mod_mcp2515_write(a2, 0);
        mod_mcp2515_write(a3, 0);
        a1++;
        a2++;
        a3++;
    }
    
    // and clear, deactivate the two receive buffers.
    mod_mcp2515_write(MCP_RXB0CTRL, 0);
    mod_mcp2515_write(MCP_RXB1CTRL, 0);
}


