/*
 * Frame description for the isysbus isbd protocol, "switch data" frame.
 * License: GPL
 * Author: Tobias Hain (grondhal (at) grondhal.de)
 */
#pragma once
#include "isb_frame.hpp"

typedef struct isb_frame_switch_data_v2_ {
  isb_frame_switch_data_v2_()
  : cmd(cmd_write), // default: schreiben

    tov(TOV_SWITCH),
    value(0x00)
    //b4(0), b5(0), b6(0), b7(0)   
  {};
  unsigned char cmd;
  const unsigned char tov;// = TOV_BOOL;
  unsigned char value;
  //const unsigned char b4;
  //const unsigned char b5;
  //const unsigned char b6;
  //const unsigned char b7;
} isb_frame_switch_data_v2;

typedef struct switch_frame_v2_ {
   switch_frame_v2_(const unsigned short mulid, const unsigned short srcid) {
    h.flags.dlc += sizeof(isb_frame_switch_data_v2);
    h.flags.rtr = 0;
    h.flags.reserved = 0;
    
    h.dest.u.mulid.id = mulid;
    h.source.port = 0;
    h.source.addr = srcid; 
    
    h.top = TOP_SWITCH;
   
    reserved = 0;
    sb = isb_frame_stopbyte;

   };
   isb_frame_head_multicast h;
   isb_frame_switch_data_v2 d;
   unsigned char reserved;
   isb_frame_checksum checks;
   unsigned char sb;
} __attribute__((__packed__)) switch_frame_v2;
