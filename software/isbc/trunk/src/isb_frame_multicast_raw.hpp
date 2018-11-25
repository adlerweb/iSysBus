/*
 * Raw Multicast Frame description for the isysbus isbd protocol.
 * License: GPL
 * Author: Tobias Hain (grondhal (at) grondhal.de)
 */
#pragma once

#include "isb_frame.hpp"

typedef struct isb_multicast_raw_frame_v2_ {
   isb_multicast_raw_frame_v2_(const unsigned short mulid, const unsigned short srcaddr,
                               const unsigned char x_ctrl, const isb_frame_top_vals x_top,
                               const unsigned char num_data_bytes
                               //const isb_frame_tov_vals x_tov,
                               //const unsigned char x_b3, const unsigned char x_b4, const unsigned char x_b5,
                               //const unsigned char x_b6, const unsigned char x_b7
                               ) 
   {
    h.flags.dlc += 1+num_data_bytes; // ctrl und databytes
    h.flags.tof = TOF_MULTICAST;
    h.flags.rtr = 0;
    h.flags.reserved = 0;
    
    h.dest.u.mulid.id = mulid;
    h.source.port = 0; // srcport;  ungenutzt bei multicast
    h.source.addr = srcaddr; 
    h.top = x_top;
    ctrl = x_ctrl;
   
    //sb = isb_frame_stopbyte;

   };
   isb_frame_head_multicast h __attribute__((__packed__));
   unsigned char ctrl;
} __attribute__((__packed__)) isb_multicast_raw_frame_v2;

typedef struct isb_multicast_raw_frame_v2_trailer_ {
   isb_multicast_raw_frame_v2_trailer_() {
     sb = isb_frame_stopbyte;     
     reserved = 0;
   };
   unsigned char reserved;
   isb_frame_checksum checks;
   unsigned char sb;
} __attribute__((__packed__)) isb_multicast_raw_frame_v2_trailer;
