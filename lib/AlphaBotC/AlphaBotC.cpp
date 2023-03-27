#include "AlphaBotC.h"

#include <stdint.h>  // for uint8_t and uint16_t types


//  Default Arduino Car pin define -> rewrite to embedded c !
AlphaBot::AlphaBot()
{  
  //enable fast pwm
  TCCR0A = 0xA3;
  TCCR0B = 0x03;
  TCNT0 = 0x00;
  OCR0A = 0x00;
  OCR0B = 0x00;

  LMotorSpeedPin = OCR0A;         //Left Motor Speed pin (ENA) 
  LMotorSpeed = 5; 
  LMotorForward = 0;             //Motor-L forward (IN1). A0
  LMotorBackward = 1;            //Motor-L backward (IN2) A1
  
  RMotorSpeedPin = OCR0B;         //Right Motor Speed pin (ENB)
  RMotorSpeed = 6; 
  RMotorForward = 3;             //Motor-R forward (IN4) A3
  RMotorBackward = 2;            //Motor-R backward (IN3) A2
 
  DDRC |= (1 << LMotorForward)| (1 << LMotorBackward)| (1 << RMotorForward)| (1 << RMotorBackward); //set to output pins A0-A3 
  
  DDRD |=  (1 << LMotorSpeed)| (1 << RMotorSpeed);  // set pin5(ENA) and pin6(ENB) to output

  PORTC &= 0xF0;
  PORTD |=  (1 << LMotorSpeed)| (1 << RMotorSpeed);    
  
}

//drive logic input speed of left and rigth motor 
void AlphaBot::MotorRun(int LS,int RS, int direction)
{ 
  if( direction != 4)
  {
    forward();
    velocity(LS, RS);
  }
  else
  {
    backward();
    velocity(LS, RS);
  }
}

void AlphaBot::forward()
{
  PORTC &= 0xF0;
  PORTC |= 0x06;
}

void AlphaBot::backward()
{
  PORTC &= 0xF0;
  PORTC |= 0x09;
}
void AlphaBot::velocity (int left_motor, int right_motor)
{
OCR0A = (unsigned char)left_motor;
OCR0B = (unsigned char)right_motor;
}
