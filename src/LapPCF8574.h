#ifndef LAPPCF8574_H
#define LAPPCF8574_H
#include <Arduino.h>
#include <Wire.h>

class LapPCF8574 {
  
  public:
    LapPCF8574();
    LapPCF8574(uint8_t);
    LapPCF8574(uint8_t, TwoWire *);
    LapPCF8574(TwoWire *);
    bool begin();
    bool connected();
    uint8_t read();
    void write(uint8_t);
    bool pinRead(uint8_t);
    void pinWrite(uint8_t, bool);
    void lsl(uint8_t, bool);
    void lsr(uint8_t, bool);

  private:
    uint8_t _addr;
    TwoWire *_wire;
    uint8_t _dataWrite;  // needed for pinWrite
};

#endif
