#include <i2cdevice.h>

void Ledblink::on()
{
  sendCommand("led","on");
}

void Ledblink::off()
{
  sendCommand("led","off");
}

void Ledblink::setActive()
{

}

void Ledblink::clearActive()
{
  
}
