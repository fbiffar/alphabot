#include "TRSensor.h"  

TRSensor::TRSensor()
{
  Clock = 5;  
  Address = 4;
  DataOut = 3;
  CS = 2;

  _numSensors = 5;


  DDRB |= (1 << Address) | (1 << CS) | (1 << Clock);
  PORTB &= ~(1 << Clock);//set clock to 0 
  DDRB &= ~(1 << DataOut); // set to input
  PORTB &= ~(1 << DataOut);// deactivate pull up 
  
  ADCSRA = 0x86;
  ADCSRB = 0x00;
  ADMUX = 0x30;
  
}

void TRSensor::read_sensors(int* sensorValues)
{

  char i,j;
  unsigned int channel = 0;
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
    sensorValues[i] = values[i+1];
  }

}