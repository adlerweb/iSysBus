#ifndef ISB_DATAGRAM_H
#define ISB_DATAGRAM_H

#include <string>
#include <stdint.h>

class ISBDatagram {
    private: 
  uint8_t tov;
  uint8_t top;
  uint8_t cmd;
  uint32_t value;
  public:
    ISBDatagram(std::string data);
    uint32_t getValue();
    uint8_t getTOV();
    uint8_t getTOP();
    uint8_t getCmd();

    void setTOV(uint8_t);
    void setTOP(uint8_t);
    void setCmd(uint8_t);
    void setValue(uint32_t);
};
#endif
