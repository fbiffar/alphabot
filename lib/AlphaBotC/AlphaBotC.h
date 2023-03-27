#ifndef AlphaBotC_h
#define AlphaBotC_h

#include "AlphaBotC.h"
#include <avr/io.h>
#include <stdint.h> 


class AlphaBot
{
  public:
  /////////////////////////////////////////////////////////////////
  AlphaBot();
  void MotorRun(int LS,int RS, int direction); 
  void Forward(int Speed);
  void forward();
  void backward();
  void velocity(int left, int right);

  /////////////////////////////////////////////////////////////////
  
  private:
  /////////////////////////////////////////////////////////////////
  int RMotorSpeedPin;            //Right Motor Speed pin (ENA)
  int RMotorBackward;           //Motor-R backward (IN1)
  int RMotorForward;           //Motor-R forward (IN2).
  int RMotorSpeed;
  int LMotorSpeedPin;             //Left Motor Speed pin (ENB)
  int LMotorForward;            //Motor-L forward (IN3)
  int LMotorBackward;           //Motor-L backward (IN4)
  int LMotorSpeed;

  /////////////////////////////////////////////////////////////////

  ////////////////////////////////////////////////////////////////

};
#endif
