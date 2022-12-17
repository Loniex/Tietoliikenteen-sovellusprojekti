#ifndef ACCELERATOR_H
#define ACCELERATOR_H

#include "messaging.h"

struct Measurement
{
  int x;
  int y;
  int z;
};

class Accelerator
{
public:
  Accelerator();
  ~Accelerator();
  void makeMeasurement();
  Measurement getMeasurement();

  const int analogInPinX = A0;  // X-kanavan kytkentänapa
  const int analogInPinY = A1;  // Y-kanavan kytkentänapa
  const int analogInPinZ = A2;  // Z-kanavan kytkentänapa
  int sensorValueX = 0;
  int sensorValueY = 0;
  int sensorValueZ = 0;

private:
  Measurement m;
 
};

#endif // ACCELERATOR_H
