/*
 * Disco_Functions.c
 *
 * Created: 30-1-2018 1:33:41
 *  Author: Jorre van Merrienboer
 */ 
#include <avr/io.h>
#include <disco_functions.h>

void RGB(int red, int green, int blue) {
	OCR0A = red;
//	OCR0B = blue;
}

void init(void) {
	DDRD = 0xFF;
	
	TCCR0A |= (1 << 7);			// Set compare output mode A to non inverting
	TCCR0A &= ~(1 << 6);	
/*	
	TCCR0A |= (1 << 5);			// Set compare output mode B to non inverting
	TCCR0A &= ~(1 << 4);
*/	
	TCCR0B &= ~(1 << 7);		// Set FOC0A to 0
	TCCR0B &= ~(1 << 6);		// Set FOC0B to 0
	
	TCCR0A |= (1 << 0);			// Set WGM00 to 1
	TCCR0A |= (1 << 1);			// Set WGM01 to 1
	TCCR0B |= (1 << 3);			// Set WGM02 to 1
								// Set waveform generation mode to fast PWM
						
	TCCR0B |= (1 << 0);			// Set CS0 to 1
	TCCR0B |= (1 << 1);			// Set CS1 to 1
	TCCR0B &= ~(1 << 2);		// Set CS2 to 0
								// Setting prescaler to 64, PWM frequency is around 1kHz
	
	TIFR0 = 0;
	TCNT0 = 0;
	
}