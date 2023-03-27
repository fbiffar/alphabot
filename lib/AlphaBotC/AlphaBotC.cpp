#include "AlphaBotC.h"

#include <stdint.h>  // for uint8_t and uint16_t types


//  Default Arduino Car pin define -> rewrite to embedded c !
AlphaBot::AlphaBot()
{  
  //enable fast pwm
  TCNT0 = 0x00;
  TCCR0A = 0xA3;
  TCCR0B = 0x03;
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
  DDRD |=  (1 << LMotorSpeed)| (1 << LMotorSpeed);  // set pin5(ENA) and pin6(ENB) to output

  PORTC &= 0xF0;
  PORTD |=  (1 << LMotorSpeed)| (1 << LMotorSpeed); 

  
  
}



//drive the left motor run forward
void AlphaBot::LeftMotorForward(unsigned char inLSpeed)
{
  //fwd high, bwd low, speed = LSpeed
  PORTC |= (1 << LMotorForward);
  PORTC &= ~(1 << LMotorBackward);
  LMotorSpeedPin = (unsigned char) inLSpeed; ;  //no clue                 

}

//drive the left motor run backward
void AlphaBot::LeftMotorBackward(unsigned char inLSpeed)
{
  //fwd low, bwd high, speed = LSpeed
  PORTC |= (1 << LMotorBackward);
  PORTC &= ~(1 << LMotorForward);
  LMotorSpeedPin = (unsigned char)inLSpeed;  //no clue       
}

//drive the left motor stop
void AlphaBot::LeftMotorStop()
{
  PORTC &= ~(1 << LMotorSpeedPin);
  //digitalWrite(LMotorSpeedPin,LOW);               
}

//drive the right motor run forward
void AlphaBot::RightMotorForward(unsigned char inRSpeed)
{
  RMotorSpeedPin = (unsigned char)inRSpeed;  //no clue             
  //fwd high, bwd low, speed = LSpeed
  PORTC |= (1 << RMotorForward);
  PORTC &= ~(1 << RMotorBackward);
  
}

//drive the right motor run backward
void AlphaBot::RightMotorBackward(unsigned char inRSpeed)
{
  RMotorSpeedPin = (unsigned char)inRSpeed;               
  //fwd low, bwd high, speed = LSpeed
  PORTC |= (1 << RMotorBackward);
  PORTC &= ~(1 << RMotorForward);
}

//drive the right motor stop
void AlphaBot::RightMotorStop()
{
  //digitalWrite(RMotorSpeedPin,LOW);  
  PORTC &= ~(1 << RMotorSpeedPin);       
}

//drive logic input speed of left and rigth motor 
bool AlphaBot::MotorRun(int LS,int RS, int direction)
{ 
  if(LS >= 0 && LS <= 255 && direction != 4)
  {
    LeftMotorForward(LS);
  }
  if(LS >= 0 && LS <= 255 && direction == 4)
  {
    LeftMotorBackward(LS);
  }
  
  if(RS >= 0 && RS <= 255 && direction != 4)
  {
    RightMotorForward(RS);
  }
  if(RS >= 0 && RS <= 255 && direction == 4)
  {
    RightMotorBackward(RS);
  }
  if (RS > 255 || RS < 0 || LS > 255 || LS < 0)
  {
    return false;
  }
  
  return true;
}



//drive the car run forward
void AlphaBot::Forward(unsigned char Speed)
{
  LeftMotorForward(Speed);
  RightMotorForward(Speed);
}

