/*
 * Disco_Functions.c
 *
 * Created: 30-1-2018 1:33:41
 *  Author: Jorre van Merrienboer
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <disco_functions.h>
#include <util/delay.h>

void display_RGB(char red, char green, char blue) {
	
	red = 255 - red;
	green = 255 - green;
	blue = 255 - blue;

	OCR0A = red;
	OCR0B = blue;
	OCR2B = green;
}

void initialise_ATmega328P(void) {
	
	
	/////////////
	// Timer 0 //
	/////////////
	
	DDRD = 0xFF;
	
	TCCR0A |= (1 << 0);			// Set WGM00 to 1
	TCCR0A |= (1 << 1);			// Set WGM01 to 1
	TCCR0B &= ~(1 << 3);		// Set WGM02 to 0
	// Set waveform generation mode to fast PWM 
	
	TCCR0A |= (1 << 7);			// Set compare output mode A to inverting
	TCCR0A |= (1 << 6);	

	TCCR0A |= (1 << 5);			// Set compare output mode B to inverting
	TCCR0A |= (1 << 4);

	TCCR0B &= ~(1 << 7);		// Set FOC0A to 0
	TCCR0B &= ~(1 << 6);		// Set FOC0B to 0
						
	TCCR0B |= (1 << 0);			// Set CS00 to 1
	TCCR0B |= (1 << 1);			// Set CS01 to 1
	TCCR0B &= ~(1 << 2);		// Set CS02 to 0
								// Setting prescaler to 64, PWM frequency is around 
								
	/////////////						
	// Timer 2 //
	/////////////
							
	TCCR2A |= (1 << 0);			// Set WGM20 to 1
	TCCR2A |= (1 << 1);			// Set WGM21 to 1
	TCCR2B &= ~(1 << 3);		// Set WGM22 to 0
	// Set waveform generation mode to fast PWM 
		
	TCCR2A |= (1 << 5);			// Set compare output mode A to inverting
	TCCR2A |= (1 << 4);

	TCCR2B &= ~(1 << 7);		// Set FOC2A to 0
	TCCR2B &= ~(1 << 6);		// Set FOC2B to 0
	
	TCCR2B &= ~(1 << 0);		// Set CS20 to 0
	TCCR2B &= ~(1 << 1);		// Set CS21 to 0
	TCCR2B |=(1 << 2);			// Set CS22 to 1
	// Setting prescaler to 64, PWM frequency is around 1kHz
	
	display_RGB(0,0,0);					// To make sure the PWM starts at 0
}

void testRGB(void) {
		display_RGB(255,0,0);
		_delay_ms(500);
		display_RGB(255,128,0);
		_delay_ms(500);
		display_RGB(255,255,0);
		_delay_ms(500);
		display_RGB(128,255,0);
		_delay_ms(500);
		display_RGB(0,255,128);
		_delay_ms(500);
		display_RGB(0,255,255);
		_delay_ms(500);
		display_RGB(0,128,255);
		_delay_ms(500);
		display_RGB(0,0,255);
		_delay_ms(500);
		display_RGB(127,0,255);
		_delay_ms(500);
		display_RGB(255,0,255);
		_delay_ms(500);
		display_RGB(255,0,127);
		_delay_ms(500);
		display_RGB(128,128,128);
		_delay_ms(500);
		display_RGB(0,0,0);
		
}