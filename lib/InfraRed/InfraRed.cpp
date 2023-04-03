#include "InfraRed.h"

InfraRed::InfraRed()
{

    ir_front = 0;   // PB0
    ir_left_f1 = 1; // PB1
    ir_left_f2 = 7; // PD7
    ir_left_b1 = 4; // PD4
    ir_left_b2 = 0; // PD0

    // set input registers = 0
    DDRB &= ~(1 << ir_front);
    DDRD &= ~(1 << ir_left_f2);
    DDRB &= ~(1 << ir_left_f1);
    DDRD &= ~(1 << ir_left_b1);
    DDRD &= ~(1 << ir_left_b2);

    // activate pull up mode
    PORTB |= (1 << ir_front) | (1 << ir_left_f1);
    PORTD |= (1 << ir_left_f2) | (1 << ir_left_b1) | (1 << ir_left_b2);
}

void InfraRed::read_IR(int *IR_range, int sensor)
{
    switch (sensor)
    {
    case 0:
        IR_range[0] = PINB >> ir_front & 1;
        break;
    case 1:
        IR_range[1] = PIND >> ir_left_f2 & 1;
        break;
    case 2:
        IR_range[2] = PINB >> ir_left_f1 & 1;
        break;
    case 3:
        IR_range[3] = PIND >> ir_left_b1 & 1;
        break;
    case 4:
        IR_range[4] = PIND >> ir_left_b2 & 1;
        break;

    default:
        IR_range[0] = PINB >> ir_front & 1;
        IR_range[1] = PIND >> ir_left_f2 & 1;
        IR_range[2] = PINB >> ir_left_f1 & 1;
        IR_range[3] = PIND >> ir_left_b1 & 1;
        IR_range[4] = PIND >> ir_left_b2 & 1;
    }
}