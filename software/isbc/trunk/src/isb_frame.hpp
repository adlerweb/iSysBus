/*
 * Frame description for the isysbus isbd protocol.
 * License: GPL
 * Author: Tobias Hain (grondhal (at) grondhal.de)
 */
#pragma once


// type of frame
typedef enum isb_frame_tof_vals_ {
 TOF_UNICAST=0,
 TOF_MULTICAST=2,
 TOF_BROADCAST=3
} isb_frame_tof_vals;

typedef struct isb_frame_unicast_addr_ {
 unsigned short addr:11;
 unsigned short port:5;
} isb_frame_unicast_addr;//  __attribute__((__packed__));

typedef struct isb_frame_multicast_id_ {
 unsigned short id;
} isb_frame_multicast_id;//  __attribute__((__packed__));

typedef struct isb_frame_broadcast_id_ {
 unsigned short id;
} isb_frame_broadcast_id;//  __attribute__((__packed__));


typedef struct isb_frame_addr_id_ {
 union {
   isb_frame_unicast_addr ud;
   isb_frame_multicast_id mulid;
   isb_frame_broadcast_id brid;
 } u;
} isb_frame_addr_id;//  __attribute__((__packed__));

typedef struct isb_frame_flags_ {
 isb_frame_flags_() : dlc(0) {};
 unsigned char dlc:4; //> data length counter
 unsigned char tof:2; //> isb_frame_tof_vals
 unsigned char rtr:1; //> remote transmit request (wird erwaehnt, aber nicht naeher beschrieben: http://wiki.isysbus.org/index.php/Paketaufbau_RS232 )
 unsigned char reserved:1;
} isb_frame_flags __attribute__((__packed__));

typedef struct isb_frame_head_ {
 isb_frame_head_()
 : startbyte(0x01)
 {};
 unsigned char startbyte;
 isb_frame_flags flags;
 isb_frame_addr_id dest __attribute__((__packed__));
 isb_frame_unicast_addr source __attribute__((__packed__));
} isb_frame_head; // size: 6 bytes

typedef struct isb_frame_head_top_ : isb_frame_head_ {
 isb_frame_head_top_() {
  flags.dlc+=1; // top is a data byte by protocol specification
 };
 unsigned char top;
} isb_frame_head_top; // size: 7 bytes

typedef struct isb_frame_head_unicast_ : isb_frame_head_ {
 isb_frame_head_unicast_() {
  flags.tof=TOF_UNICAST;
 };

} isb_frame_head_unicast;

typedef struct isb_frame_head_multicast_ : isb_frame_head_top {
 isb_frame_head_multicast_() {
  flags.tof=TOF_MULTICAST;  
 };

} isb_frame_head_multicast;

typedef struct isb_frame_head_broadcast_ : isb_frame_head_top {
 isb_frame_head_broadcast_() {
  flags.tof=TOF_BROADCAST;
 };

} isb_frame_head_broadcast;




#if 0
typedef enum isb_frame_ctrl_bits_ {
 CTRL_READ_WRITE=0x80 // Bit gesetzt = write, Bit nicht gesetzt = read
} isb_frame_ctrl_bits;
#endif

typedef enum isb_frame_cmd_ {
  cmd_read=0, cmd_answer=1, cmd_write=2 
} isb_frame_cmd;

typedef enum isb_frame_top_vals_ {
// quelle: http://wiki.isysbus.org/index.php/TOP
  TOP_RESERVED=0x00,
  TOP_SWITCH=0x01,
  TOP_DIM=0x02,

  TOP_MOTOR=0x03,
  TOP_CTRL=0x04,
  TOP_DEZ=0x05,
  TOP_REL=0x06,
  TOP_FLOAT=0x07,
  TOP_ACCESS_CTRL=0x08,
  TOP_UNUSED1=0x09,
  TOP_D8BIT=0x0a,
  TOP_D16BIT=0x0b,
  TOP_D32BIT=0x0c,
  TOP_UNUSED2=0x0d,
  TOP_BOOTMSG=0x20
} isb_frame_top_vals;

// type of value
typedef enum isb_frame_tov_vals_ {
// quelle: http://wiki.isysbus.org/index.php/TOV
  TOV_RESERVED=0x00,
  TOV_BOOL=0x01,
  TOV_SWITCH=0x02,
  TOV_ACTIVATE=0x03,
  TOV_UP_DOWN=0x04,
  TOV_OPEN_CLOSE=0x05,
  TOV_START=0x06,
  TOV_BINARY=0x07,
} isb_frame_tov_vals;



//typedef unsigned short isb_frame_checksum;
typedef unsigned char isb_frame_checksum;

const static unsigned char isb_frame_stopbyte = 0x0d;


// frame aufbau:
// <head> <data> <checksum> <stopbyte>

