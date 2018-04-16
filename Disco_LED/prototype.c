/*
* prototype.c
*
* Created: 21-2-2018 20:30:53
*  Author: Jorre
*/

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <disco_functions.h>

int main(void) {
	
	initialise_ATmega328P();
	testRGB();
	
	while(1) {	
		
		display_RGB(0,0,0);
	}
	
	return 1;
} 


