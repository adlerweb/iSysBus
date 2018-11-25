#ifndef MOD_UART_CONF_H_
#define MOD_UART_CONF_H_

#define MOD_UART

#define UART_BAUD 9600 /*! Bautrate der uart festlegen */
//#define UART_BAUDRATE_DOUBLE_SPEED 1

//#define UART_NO_RX 1
//#define UART_NO_TX 1

/**
 * @brief   Anzahl der Bytes des Sendepuffers ( 4, 8, 16, 32, 64 usw. ... )
 */
 
#define TX_BUF_SIZE   64
#define RX_BUF_SIZE   64

#endif /*MOD_UART_CONF_H_*/
