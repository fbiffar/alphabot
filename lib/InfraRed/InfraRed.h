#ifndef InfraRed_h
#define InfraRed_h

#include "InfraRed.h"
#include <avr/io.h>
#include <stdint.h>

class InfraRed
{
public:
  /////////////////////////////////////////////////////////////////
  InfraRed();
  void read_IR(int *IR_range, int sensor);
  /////////////////////////////////////////////////////////////////

private:
  /////////////////////////////////////////////////////////////////
  int ir_front;   // PB0
  int ir_left_f1; // PB1
  int ir_left_f2; // PD7
  int ir_left_b1; // PD4
  int ir_left_b2; // PD0
  /////////////////////////////////////////////////////////////////

  /////////////////////////////////////////////////////////////////
};
#endif