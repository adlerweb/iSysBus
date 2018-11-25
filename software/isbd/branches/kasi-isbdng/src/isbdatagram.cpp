#include "isbdatagram.h"
#include <string.h>
#include <stdio.h>
#include "isb_frame.hpp"

ISBDatagram::ISBDatagram(std::string data) {
  const char *bytes = data.c_str();

  top = bytes[0];
  cmd = bytes[1];
  tov = bytes[2];
	uint16_t tmp;

  switch (top) {
		case TOP_FLOAT:
		case TOP_TIME:
		case TOP_U16:
		case TOP_S16:
    	memcpy(&tmp,bytes+3,2);
			value = tmp;
			break;
		case TOP_DATE:
		case TOP_S32:
		case TOP_U32:
    	memcpy(&value,bytes+3,4);
			break;
		case TOP_SWITCH:
		default:
    	value = bytes[3];
			break;
	}
}

uint32_t ISBDatagram::getValue() {
  return value;
}
uint8_t ISBDatagram::getTOV() {
  return tov;
}
uint8_t ISBDatagram::getTOP() {
  return top;
}
uint8_t ISBDatagram::getCmd() {
  return cmd;
}

