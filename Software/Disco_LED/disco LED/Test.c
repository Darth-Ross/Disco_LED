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
#include <disco_functions.h>

void test(void) {
	
	DDRD = 0xFF;		//Port D as output
	PORTD = 0x00;		//Port D = low
	
	TCCR1B = 0x05;		//16 bit timer on scale 1024
	TCNT1 = 0;		
	
	char red = 255;
	char green = 0;
	char blue = 0;
	
	while(1) {
		RGB(red, green, blue);
	}
} 


