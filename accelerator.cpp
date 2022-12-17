#include "accelerator.h"
#include <arduino.h>

Accelerator::Accelerator()
{
   Serial.println("Accelerator created!");
}


Accelerator::~Accelerator()
{
   Serial.println("Accelerator deleted!");
}

void Accelerator::makeMeasurement()
{
  
    sensorValueX = analogRead(analogInPinX);
    sensorValueY = analogRead(analogInPinY);
    sensorValueZ = analogRead(analogInPinZ);
    m.x=sensorValueX;
    m.y=sensorValueY;
    m.z=sensorValueZ;

}
Measurement Accelerator::getMeasurement()
{
  return m;
}
