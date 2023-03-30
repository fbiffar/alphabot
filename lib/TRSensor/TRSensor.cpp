#include "TRSensor.h" 

#include "Arduino.h"

TRSensor::TRSensor()
{
  Clock = 5;  
  Address = 4;
  DataOut = 3;
  CS = 2;

  _numSensors = 5;

  // calibratedMin = (unsigned int*)malloc(sizeof(unsigned int) * _numSensors);
	// calibratedMax = (unsigned int*)malloc(sizeof(unsigned int) * _numSensors);
	
	// for(int i=0;i<_numSensors;i++)
	// {
	// 	calibratedMin[i] = 1023;
	// 	calibratedMax[i] = 0;
	// }

  DDRB |= (1 << Address) | (1 << CS) | (1 << Clock);
  PORTB &= ~(1 << Clock);//set clock to 0 
  DDRB &= ~(1 << DataOut); // set to input
  PORTB &= ~(1 << DataOut);// deactivate pull up 
  
  ADCSRA = 0x86;
  ADCSRB = 0x00;
  ADMUX = 0x30;
  
}

void TRSensor::read_sensors(unsigned int* sensorValues, unsigned int* TR_min, unsigned int* TR_max)
{

  int i,j;
  unsigned int values[] = {0,0,0,0,0,0};

  for(j = 0;j < _numSensors + 1;j++)
  {
    
    PORTB &= ~(1 << CS);
    for(i = 0;i < 10;i++)
    {
      //0 to 4 clock transfer channel address
      if((i < 4) && (j >> (3 - i) & 0x01)){
        PORTB |= (1 << Address);
      }
      else{
        PORTB &= ~(1 << Address);
      }
      //0 to 10 clock receives the previous conversion result
      values[j] <<= 1;
    
      if(PINB & (1 << DataOut)) {
        
        values[j] |= 0x01;
      }
    
      PORTB |= (1 << Clock);
      PORTB &= ~(1 << Clock);
    }
    //sent 11 to 16 clock 
    for(i = 0;i < 6;i++)
    {
      PORTB |= (1 << Clock);
      PORTB &= ~(1 << Clock);
    }
    PORTB |= (1 << CS);
  }

  for(i = 0;i < _numSensors;i++)
  {
    unsigned int range = TR_max[i]-TR_min[i];

    if ((values[i+1]/10) > TR_max[i])
      sensorValues[i] =  TR_max[i]; 
    else if (values[i+1]/10 < TR_min[i])
      sensorValues[i] = TR_min[i];
    else{
    sensorValues[i] = (values[i+1] - TR_min[i]) / range;
    }
  }

}

// Reads the sensors 10 times and uses the results for
// calibration.  The sensor values are not returned; instead, the
// maximum and minimum values found over time are stored internally
// and used for the readCalibrated() method.
// void TRSensor::calibrate()
// {
// 	int i;
// 	unsigned int sensor_values[_numSensors];
// 	unsigned int max_sensor_values[_numSensors];
// 	unsigned int min_sensor_values[_numSensors];

// 	int j;
// 	for(j=0;j<10;j++)
// 	{
// 		read_sensors_calibration(sensor_values);
// 		for(i=0;i<_numSensors;i++)
// 		{
// 			// set the max we found THIS time
// 			if(j == 0 || max_sensor_values[i] < sensor_values[i])
// 				max_sensor_values[i] = sensor_values[i];

// 			// set the min we found THIS time
// 			if(j == 0 || min_sensor_values[i] > sensor_values[i])
// 				min_sensor_values[i] = sensor_values[i];
// 		}
// 	}
  
//   // record the min and max calibration values
//   for(i=0;i<_numSensors;i++)
//   {
//     if(min_sensor_values[i] > calibratedMax[i])
//       calibratedMax[i] = min_sensor_values[i];
//     if(max_sensor_values[i] < calibratedMin[i])
//       calibratedMin[i] = max_sensor_values[i];
//   }
// }

void TRSensor::read_sensors_calibration(unsigned int sensorValues[])
{

  int i,j;
  unsigned int values[] = {0,0,0,0,0,0};

  for(j = 0;j < _numSensors + 1;j++)
  {
    
    PORTB &= ~(1 << CS);
    for(i = 0;i < 10;i++)
    {
      //0 to 4 clock transfer channel address
      if((i < 4) && (j >> (3 - i) & 0x01)){
        PORTB |= (1 << Address);
      }
      else{
        PORTB &= ~(1 << Address);
      }
      //0 to 10 clock receives the previous conversion result
      values[j] <<= 1;
    
      if(PINB & (1 << DataOut)) {
        
        values[j] |= 0x01;
      }
    
      PORTB |= (1 << Clock);
      PORTB &= ~(1 << Clock);
    }
    //sent 11 to 16 clock 
    for(i = 0;i < 6;i++)
    {
      PORTB |= (1 << Clock);
      PORTB &= ~(1 << Clock);
    }
    PORTB |= (1 << CS);
  }

  for(i = 0;i < _numSensors;i++)
  {
   
    sensorValues[i] =(int)(values[i+1]/100.0 +0.5);
  }

}