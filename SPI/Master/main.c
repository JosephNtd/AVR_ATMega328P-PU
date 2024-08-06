#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>

void Master_Init(void){
    DDRB |= (1 << PB3) | (1 << PB5) | (1 << PB2);
    DDRB &= ~ (1 << PB4);
    SPCR |= (1<<SPE)|(1<<MSTR)|(1<<SPR0);
    PORTB |= (1 << PB2);
}
void SPI_MasterTransmit(char cData)
{
    PORTB &= ~ (1 << PB2);
    SPDR = cData;
    while(!(SPSR & (1<<SPIF)));
    PORTB |= (1 << PB2);
}

int main(void){
    Master_Init();
    DDRD &= ~(1 << PD2);
    DDRD &= ~(1 << PD3);
    PORTD |= (3 << PD2);
    DDRD |= (1 << PD7); 
    while(1){

        if (!(PIND & (1 << PD2))){
            PORTD &= ~(1 << PD7); 
            SPI_MasterTransmit('1');
            _delay_ms(100);
            while(!(PIND & (1 << PD2)));
        }
        
        if (!(PIND & (1 << PD3))){
            PORTD |= (1 << PD7); 
            SPI_MasterTransmit('2');
            _delay_ms(100);
            while(!(PIND & (1 << PD3)));
        }
    }
    return (0);
}
