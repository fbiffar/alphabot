#include "InfraRed.h"

InfraRed::InfraRed()
{
    
    front_InfraRed = 0; //PB0
    front_left_InfraRed = 1; //PB1
    up_left_InfraRed = 7 ; //PD7
    left_InfraRed = 4; //PD4
    down_left_InfraRed = 1; //PD1 

    //set input registers 
    DDRB &= ~(1 << front_InfraRed) ;
    DDRB &= ~(1 << front_left_InfraRed); 
    DDRD &= ~(1 << up_left_InfraRed) ;
    DDRD &= ~(1 << left_InfraRed) ;
    DDRD &= ~(1 << down_left_InfraRed); 
    
    //deactivate pull up mode 
    // PORTB &= ~(1 << front_InfraRed);
    // PORTB &= ~(1 << front_left_InfraRed);
    // PORTD &= ~(1 << up_left_InfraRed);
    // PORTD &= ~(1 << left_InfraRed); 
    // PORTD &= ~(1 << down_left_InfraRed); 
    //activate pull up mode 
    PORTB |= (1 << front_InfraRed) | (1 << front_left_InfraRed);
    PORTD |= (1 << up_left_InfraRed)| (1 << left_InfraRed) |(1 << down_left_InfraRed);
    
}

void InfraRed::read_IR(int* IR_range, int sensor)
{
    switch(sensor){    
    case 0:    
        IR_range[0] = PIND >> down_left_InfraRed & 1;
    break; 
    case 1:    
        IR_range[1] = PIND >> left_InfraRed & 1;
    break;  
    case 2:    
        IR_range[2] = PIND >> up_left_InfraRed & 1;
    break; 
    case 3:    
        IR_range[3] = PINB >> front_left_InfraRed & 1;
    break; 
    case 4:    
        IR_range[4] = PINB >> front_InfraRed & 1 ;
    break; 

    default:     
    IR_range[0] = PIND >> down_left_InfraRed & 1;
    IR_range[1] = PIND >> left_InfraRed & 1;
    IR_range[2] = PIND >> up_left_InfraRed & 1;
    IR_range[3] = PINB >> front_left_InfraRed & 1;
    IR_range[4] = PINB >> front_InfraRed & 1 ;
    }

}