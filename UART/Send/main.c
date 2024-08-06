#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

volatile unsigned char recv_data ;

void send_data(unsigned char x) {	
	while(!(UCSRA & (1<<UDRE)));
	UDR = x;
}

int main(void)
{
	UBRRL = 51; 
	UCSRB |= (1 << TXEN) | (1 << RXEN) | (1 << RXCIE) ; 
	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1); 

	DDRC |= (1 << 5);
	PORTC |= (1 << 5);
	
	DDRC &= ~(3<<3);
	PORTC |= (3<<3);

	while (1)
	{			
		if (!(PINC & (1 << 3))){
			send_data('1'); 
			_delay_ms(200);
			while (!(PINC & (1 << 3)));
		}
		if(!(PINC & (1 << 4))){
			send_data('2');
			_delay_ms(200);
			while (!(PINC & (1 << 4)));
		}
	}
}
ISR(USART_RXC_vect)
{
	recv_data = UDR;
	if (recv_data == 1){
			PORTC  |= (1<<5);
	}
	elif (recv_data == 2){
			PORTC  &= ~(1<<5);
	}
}
