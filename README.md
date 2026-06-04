# LapPCF8574
An Arduino library to drive the PCF8574 I/O expander
     
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

uint8_t read();
-------------

void write(uint8_t);
-------------

bool pinRead(uint8_t);
-------------

void pinWrite(uint8_t, bool);
-------------

void lsl(uint8_t, bool);
-------------

void lsr(uint8_t, bool);
-------------
