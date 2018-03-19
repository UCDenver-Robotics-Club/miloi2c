#ifndef MILO_I2C_H
#define MILO_I2C_H
#include <arduino.h> // arduino st
#include <Wire.h> // arduino's i2c libary
#include <ArduinoJson.h> // arduino json lib
#include <stdint.h>

// https://github.com/adafruit/Adafruit_BNO055/blob/master/Adafruit_BNO055.h
// https://github.com/adafruit/DHT-sensor-library
// https://www.arduino.cc/en/Tutorial/MasterReader
// https://github.com/bblanchon/ArduinoJson

// class for handling generic functions for milo i2c
// its assumed that this program is going to be running on the prism

class MILOI2C
{
public:
  String sayHi(); // says hi, so I make sure I still know how to use the arduino build stuff with an external editor
  MILOI2C(); // constructor, sets a defult address
  MILOI2C(unsigned char address);
  //MILOI2C(uint8_t addr,TwoWire *ptr);
  bool ping(); // make sure the device is connected, may not be needed
  void sendLine(String line); // sends a string to the client
  String readLine(uint8_t len); // reads a line from the client
  int stuff(); // stuff...
  void sendCommand(String device,String action); // send a json command to the client
private:
  //void startI2c(); // not super nessary
  unsigned char address; // address of the i2c device
  //TwoWire *wireptr;
};

class Ledblink : public MILOI2C
{
public:
  Ledblink(unsigned char address) : MILOI2C(address) {}
  void on();
  void off();
};

class ColorDetector : public MILOI2C
{

};

class CointSort : public MILOI2C
{

};

#endif
