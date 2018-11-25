//Bootloader
//#define uart_puts_P(a) asm volatile ("nop");
#define UART_BAUD	4800UL			/**< UART Baudrate */
#include "oshb.h"
#undef DebugUART
#include "mod_can.h"
#include <avr/boot.h>
#include <avr/interrupt.h>
//#include "uart.h"
#include "can.h"
#include "mcp2515_defs.h"
#include "spi.h"

//#define DebugUART


#define CommandID 55
#define SendDataID 56

// Todo: 4Byte oder mehr
#define hwaddr 100
void main (void)
{
   //Move Interrupts
   /* Enable change of Interrupt Vectors */
   GICR = (1<<IVCE);
   /* Move interrupts to boot Flash section */
   //GICR = (1<<IVSEL);
   sei();
   spi_init();
   //uart_init();
   //uart_puts_P("bootldr");
   mod_can_init();
   message msg;
   pmessage pmsg;
   pmsg = &msg;
   uint16_t pFlash =0;
   uint8_t DeviceSelected = 0;
   uint8_t addresscount;

   while (1==1) {
      sei();
      //uart_puts_P("_");
      //cli();
      if (can_readMessage(pmsg)== CAN_OK){
	 //sei();
	 /*     uart_puts_P("can res");
	    uart_puts_P("\n\n");
	    uint8_t i;
	    for (i=0;i<pmsg->length;i++) {
	    uart_put_hex(pmsg->data[i]);
	    uart_puts_P("\n");
	    }

	    uart_put_hex(mcp2515_readRegister(MCP_EFLG));  */
	 if (pmsg->destination.i16 == CommandID)   //Paket mit Command erhalten
	 {
	    if (pmsg->data[0] == 1)   //Select device
	    {
	       if ( pmsg->data[1]== hwaddr){
		  DeviceSelected =1;   //Gerät hör auf Updates
		  pmsg->data[0] = 255;


	       }

	    }
	    if ((pmsg->data[0] == 2)&& (DeviceSelected!=0))   //Erase page
	    {
	       //
	       boot_page_erase(pmsg->data[1]*256+pmsg->data[2]);
	       boot_spm_busy_wait();
	       pmsg->data[0] = 254;
	       pFlash=0;

	    }
	    if ((pmsg->data[0] == 3)&& (DeviceSelected!=0))   //write page
	    {

	       boot_page_write(pmsg->data[1]*256+pmsg->data[2]);
	       boot_spm_busy_wait();
	       pmsg->data[0] = 253;

	    }
	    pmsg->destination = pmsg->source;
	    pmsg->source.i16 = 0;
#ifdef DebugUART
	    uart_puts_P("canCom\n");
#endif
	    can_sendMessage(pmsg);

	 }
	 if (pmsg->destination.i16 == SendDataID)
	 {
	    //pFlash =pmsg->port;  //Adresse zum schreiben übergeben
	    boot_page_fill (pFlash, pmsg->data[0]+pmsg->data[1]*256);
	    pFlash+=2;
	    boot_page_fill (pFlash, pmsg->data[2]+pmsg->data[3]*256);
	    pFlash+=2;
	    boot_page_fill (pFlash, pmsg->data[4]+pmsg->data[5]*256);
	    pFlash+=2;
	    boot_page_fill (pFlash, pmsg->data[6]+pmsg->data[7]*256);
	    pFlash+=2;
	    pmsg->destination = pmsg->source;
	    pmsg->source.i16 = 0;
	    //pmsg->data[0] = 56;
	    pmsg->data[0] = pFlash;
#ifdef DebugUART

	    uart_puts_P("canData\n");
#endif
	    can_sendMessage(pmsg);
	 }

      }

   }

}

