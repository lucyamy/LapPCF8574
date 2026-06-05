#include "LapPCF8574.h"

LapPCF8574::LapPCF8574() {
  _addr = 0x20;
  _wire = &Wire;
  _dataWrite = 0xff;
}

LapPCF8574::LapPCF8574(uint8_t addr) {
  _addr = addr;
  _wire = &Wire;
  _dataWrite = 0xff;
}

LapPCF8574::LapPCF8574(TwoWire *wire) {
  _addr = 0x20;
  _wire = wire;
  _dataWrite = 0xff;
}

LapPCF8574::LapPCF8574(uint8_t addr, TwoWire *wire) {
  _addr = addr;
  _wire = wire;
  _dataWrite = 0xff;
}

bool LapPCF8574::begin() {
  if(connected())
    return true;
  else
    return false;
}

bool LapPCF8574::connected() {
  _wire->beginTransmission(_addr);
  return (_wire->endTransmission() == 0);
}

void LapPCF8574::write(uint8_t data) {
  _dataWrite = data;
  _wire->beginTransmission(_addr);
  _wire->write(_dataWrite);
  _wire->write(0xff);
  _wire->endTransmission();
}

uint8_t LapPCF8574::read() {
  uint8_t data = 0;   // if _wire->available() returns zero at once, data will not be assigned.
                      // So the compiler will nag me. So I initialise it. That's why.
  _wire->requestFrom(_addr | 0x01, 1);
  while (_wire->available())
    data = _wire->read();
  return data;
}

bool LapPCF8574::digitalRead(uint8_t pin) {
  bool bit;
  uint8_t data = read();
  uint8_t mask = 1 << pin;
  data &= mask;
  bit = data ? HIGH : LOW;
  return bit;
}

void LapPCF8574::digitalWrite(uint8_t pin, bool bit) {
  if (bit)
    _dataWrite |= (1 << pin);
  else
    _dataWrite &= ~(1 << pin);
  write(_dataWrite);
}

void LapPCF8574::pinMode(uint8_t pin, uint8_t mode) {
}

void LapPCF8574::lsr(uint8_t shift, bool rot) {
  if((shift == 0) || (_dataWrite == 0)) return;
  if(rot) {
    shift %= 8;
    _dataWrite = (_dataWrite >> shift) | (_dataWrite << (7 - shift));
  } else {
    if(shift > 7) _dataWrite = 0;
    if(_dataWrite != 0) _dataWrite >>= shift;
  }
  write(_dataWrite);
}

void LapPCF8574::lsl(uint8_t shift, bool rot) {
  if ((shift == 0) || (_dataWrite == 0)) return;
  if(rot) {
    shift %= 8;
    _dataWrite = (_dataWrite << shift) | (_dataWrite >> (7 - shift));
  } else {
    if(shift > 7) _dataWrite = 0;
  if (_dataWrite != 0) _dataWrite <<= shift;
  }
  write(_dataWrite);
}
