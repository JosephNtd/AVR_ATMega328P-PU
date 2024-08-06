/*
 include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


int main(void) {
    DDRB |= (1 << 5);
    PORTB |= (1 << 5);
    DDRD &= ~(1 << 2);
    
    while (1) {
         if(!(PIND & (1 << 2)) == 0){
            PORTB ^= (1 << 5);
            _delay_ms(100);
            while(!(PIND & (1 << 2)) == 0);
        }  
    }
    return 0;
} 
*/
 #include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>

bool led_state = false;

int main() {
    DDRB |= (1 << PB5);

    while (1) {

        led_state = !led_state;
        if (led_state) {
            PORTB |= (1 << PB5);
        } else {
            PORTB &= ~(1 << PB5);
        }
        _delay_ms(500);
    }

    return 0;
}