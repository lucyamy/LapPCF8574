# LapPCF8574
An Arduino library to drive the PCF8574 I/O expander. It is small and simple, but likely lets you do what you need.
     
The library
-----------
The library allows you to read and write 8-bit values, or a single bit. You can also shift the output left and right.

  **LapPCF8574** is invoked as:
 
  **LapPCF8574();**
  
  **LapPCF8574(uint8_t i2cAddess);**
  
  **LapPCF8574(uint8_ti2cAddress, TwoWire \*wire inferface);**
  
  **LapPCF8574(TwoWire \*wire inferface);**

void begin();
-------------
This must be called before using any other function. If the device is connected to the bus, it returns true, otherwise false.

bool connected();
-------------
Returns *true* if a PCF8574 is connected at the specified address, otherwise returns false.

uint8_t read();
-------------
Reads a byte.

void write(uint8_t value);
-------------
Writes a byte.

bool pinRead(uint8_t pin);
-------------
Reads a single bit, from the specified pin, 0 to 7.

void pinWrite(uint8_t pin, bool value);
-------------
Writes a single bit, to the specified pin, 0 to 7.

void lsl(uint8_t number, bool rotate);
-------------
Logocally shifts the output bits left. Shift should be 0-7, but higger values will simply clear the output to zero (if
*rotate* is zero.

If *rotate* is false, the rightmost bits will be filled with zero. If true the rightmost bits will be the bits shifted
out of the left.

void lsr(uint8_t, bool);
-------------
Logocally shifts the output bits right. Shift should be 0-7, but higger values will simply clear the output to zero (if
*rotate* is zero.

If *rotate* is false, the leftmost bits will be filled with zero. If true the leftmost bits will be the bits shifted
out of the right.

