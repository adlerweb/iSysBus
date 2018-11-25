#ifndef IF_CAN_CONFIG_H_
#define IF_CAN_CONFIG_H_

/* 125 khz bei 8MHZ by Microchip Can bit rate calculator
CNF1/BRGCON1    b'00000001'     0x01
CNF2/BRGCON2    b'10111000'     0xB8
CNF3/BRGCON3    b'00000101'     0x05
*/
#define IF_CAN

#define IF_CAN_CNF1 0x01
#define IF_CAN_CNF2 0xB8
#define IF_CAN_CNF3 0x05

#define IF_CAN_MODE MODE_NORMAL //Normal Moduls
//#define IF_CAN_MODE MODE_LOOPBACK //Loopback zum debuggen 



#endif /*IF_CAN_CONFIG_H_*/
