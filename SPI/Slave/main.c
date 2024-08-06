#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>

volatile unsigned char recv_data;

void Slave_Init(void){
    DDRB |= (1 << PB4);
    DDRB &= ~ (1 << PB2) | (1 << PB3) | (1 << PB5);
    SPCR |= (1<<SPE) | (1 << SPIE) | (1<<SPR0);
}

int main(void){
    Slave_Init();
    DDRD  |= (1 << PD7) | (1 << PD6);
    PORTD &= (1 << PD6);
    PORTD &= ~(1 << PD7);  
    sei();
    while(1){

    }
}
ISR(SPI_STC_vect){
    
    while(!(SPSR & (1<<SPIF)));
    recv_data = SPDR;
    PORTD |= (1<<PD6);
    
    if (recv_data == '1'){
        PORTD |= (1 << PD7);
    }
    if (recv_data == '2'){
        PORTD &= ~(1 << PD7);
    }
}