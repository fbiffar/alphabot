#ifndef TRSensor_h
#define TRSensor_h

#include "TRSensor.h"
#include <stdint.h> 
#include <avr/io.h>
#include "Arduino.h"

class TRSensor
{
  public:
  /////////////////////////////////////////////////////////////////
  TRSensor();
  void read_sensors(unsigned int* sensorValues, unsigned int* TR_min, unsigned int*_TR_max);
  void read_sensors_calibration(unsigned int* sensorValues);
  void calibrate();

  /////////////////////////////////////////////////////////////////
  
  private:
  /////////////////////////////////////////////////////////////////
  int   Clock;  
  int Address ;
  int DataOut ;
  int CS ;
  int _numSensors;
  unsigned int *calibratedMin;
	unsigned int *calibratedMax;


  
  /////////////////////////////////////////////////////////////////


  /////////////////////////////////////////////////////////////////


};
#endif