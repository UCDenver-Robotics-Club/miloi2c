#include <i2cdevice.h>
//#include <Wire.h> // arduino's i2c libary
//#include <stdint.h>

String MILOI2C::sayHi()
{
  String hello = "this is a hello message";
  return hello;
}

MILOI2C::MILOI2C()
{
    address = 8;
    Wire.begin();
}

MILOI2C::MILOI2C(unsigned char address)
{
  (*this).address = address; // this is more fun than ->
  Wire.begin();
}

// MILOI2C::MILOI2C(uint8_t addr,TwoWire *ptr)
// {
//   wireptr = ptr;
//   address = addr;
//   Wire.begin();
// }

bool MILOI2C::ping()
{
  bool success = false;
  char *bf = "AA";
  String strvalue = "BB";

  // make the I2C request and send the data
  Wire.beginTransmission(address);
  Wire.write(bf);
  Wire.endTransmission();
  // request a responce from the i2c client
  int len = strlen(bf); // find the length of the test DATA
  Wire.requestFrom((uint8_t)this->address,(uint8_t)len);
  // wait for it...
  while(Wire.available())
  {

  }

  // make sure that that request is the correct request

  return success;
}

void MILOI2C::sendLine(String line)
{
  //wireptr->beginTransmission(8);

  Wire.beginTransmission(address); // transmit to device #8
  //  Wire.write("here's a value \n");
  //  Wire.write("x is ");        // sends five bytes
  //  Wire.write(x);              // sends one byte
  Wire.write(line.c_str()); // send the line as a c string
  Wire.endTransmission();    // stop transmitting

  //wireptr->write("testing!");

  //Wire.write(line);

  //wireptr->endTransmission();
}

String MILOI2C::readLine(uint8_t len)
{
  //String out = NULL; // value of string is initally null
  char buffer[len];
  // request the bytes from the client
  Wire.requestFrom(address,len);
  uint8_t bufferIndex=0;

  while(Wire.available())
  {
    buffer[bufferIndex] = Wire.read();
    bufferIndex++;
  }

  return String(buffer); // return the char buffer as a string object
}

int MILOI2C::stuff()
{
  return 100;
}

void MILOI2C::sendCommand(String device,String action)
{
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["device"] = device;
  root["action"] = action;
  // https://arduinojson.org/api/jsonobject/printto/
  String command;
  root.printTo(command);
  // send the json encoded data to the client.
  this->sendLine(command);
}
