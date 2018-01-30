/*
 * Test.c
 *
 * Created: 13-11-2017 22:09:41
 *  Author: Jorre van Merrienboer
 */

#define F_CPU 16000000UL

#include <Test.h>
#include <avr/io.h>
#include <avr/interrupt.h>

void test(void) {
	
	DDRC = 0b11111111;
	PORTC = 0b00001100;
	
	DDRD = 0b00000000;
	
	TCCR1B = 0b00000101;		//16 bit timer on scale 1024
	TCNT1 = 0;
	
	EICRA = 0b00001100;			//External interrupt falling edge
	EIMSK = 0b00000010;			//External interrupt int1 
		
	sei();						//Enable interrupts
		
	while(1) {
		
	}
} 

ISR(INT1_vect) {
	
	int teller; 
	TCNT1 = 0;
	
	for(teller = 0; teller < 8; ) {
		if(TCNT1 > 7813) {
			teller++;
			TCNT1 = 0;
			PORTC ^= 1 << PINC5;
		}
	}
	
	reti();
}
