/*
* prototype.c
*
* Created: 21-2-2018 20:30:53
*  Author: Jorre
*/

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <disco_functions.h>

int main(void) {
	
	DDRD = 0xFF;
	PORTD = 0x00;
	
	TCCR0B = 0x0 
	TCCR1B = 0x05;		//16 bit timer on scale 1024
	TCNT1 = 0;
	
	float red = 0xFF;
	float green = 0x00;
	float blue = 0x00;
	
	while(1) {
		RGB(red, green, blue);
	}
	
	return 1;
} 


