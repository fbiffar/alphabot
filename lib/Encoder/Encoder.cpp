#include "Encoder.h"

Encoder::Encoder()
{
    left_encoder  = 2; //PD3
    right_encoder = 3; //PD2
    DDRD &= ~(1 << left_encoder); //Set the direction of the PORTD 2 pin as input
    PORTD |= (1 << left_encoder); //Enable internal pull-up for PORTD 2 pin 
    DDRD &= ~(1 << right_encoder); //Set the direction of the PORTD 3 pin as input
    PORTD |= (1 << right_encoder); //Enable internal pull-up for PORTD 3 pin
    left_position_encoder_interrupt_init();
    right_position_encoder_interrupt_init();

}

void Encoder::left_position_encoder_interrupt_init()
{
    cli(); //Clears the global interrupt
    EICRA = EICRA | 0x02; // INT0 is set to trigger with falling edge 
    EIMSK = EIMSK | 0x01; // Enable Interrupt INT0 for left position encoder   
    sei(); // Enables the global interrupt
}

void Encoder::right_position_encoder_interrupt_init()
{
    cli(); //Clears the global interrupt
    EICRA = EICRA | 0x08; // INT1 is set to trigger with falling edge
    EIMSK = EIMSK | 0x02; // Enable Interrupt INT1 for right position encoder
    sei();
}
