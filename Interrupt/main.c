#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdbool.h>

volatile bool state = false;

int main(void) {
    DDRB |= (1 << PB5);
    DDRD &= ~(1 << PD2);
    EICRA |= (1 << ISC01);
    EIMSK |= (1 << INT0);
    sei();
    while(1) {
       
    }
    return 0;
}
ISR(INT0_vect){
    state = !state;
     if(state){
        PORTB |=(1 << 5);
    } else{
        PORTB &= ~(1 << 5);
    }   
}