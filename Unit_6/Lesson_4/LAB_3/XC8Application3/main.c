/*
 * main.c
 *
 * Created: 3/22/2024 9:13:16 PM
 *  Author: HOSSAM DIAB
 */ 
#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// #define IO_base 0x20
// #define MCUCR  *((volatile unsigned int *)(IO_base+0x35)) 
// #define GICR  *((volatile unsigned int *)(IO_base+0x3B))
// #define MCUCSR  *((volatile unsigned int *)(IO_base+0x34))
// #define SREG  *((volatile unsigned int *)(IO_base+0x3F))
//#define DDRD  *((volatile unsigned int *)(IO_base+0x11))
//#define PORTD  *((volatile unsigned int *)(IO_base+0x12))

int i=0 ;


int main(void)
{
	
	
	DDRD |= (0b111<<5); // SETTING THE PORTD AS AN OUTPUT FOR 5:7 PINS 
	
	SREG |= (1<<7); // ENABLING THE INTERRUPTS 
	GICR |= (0b111<<5); // ENABLING EXTERNAL INTERRUPT

	MCUCR |= (0b11<<2); // to make the INT1 RISING EDGE	
	MCUCR |= (1<<0); // to make the INT0 SENSITIVE TO ANY LOGICAL CHANGE
	MCUCSR &= ~(1<<6); // to make the INT2 FALLING EDGE
	
	

    while(1){
		PORTD &= ~(0b111<<5);// reset all the pins between 5:7 in Port D
			
	}
   
}

ISR(INT0_vect){
	PORTD |= (0b1<<5);
	_delay_ms(1000);
}
ISR(INT1_vect){
	
		PORTD |= (0b1<<6);
		_delay_ms(1000);
}

ISR(INT2_vect){
	
			PORTD |= (0b1<<7);
			_delay_ms(1000);

}