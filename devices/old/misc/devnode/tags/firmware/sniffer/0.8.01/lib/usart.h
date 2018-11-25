#ifndef USART_H_
#define USART_H_

void usartInit (const uint32_t aBaud);
uint8_t usartReceiveChar (uint8_t* aChar);
uint8_t usartSendChar (uint8_t* aChar);
uint8_t usartSend (sniffer_t* aMsg);

#endif /*USART_H_*/
