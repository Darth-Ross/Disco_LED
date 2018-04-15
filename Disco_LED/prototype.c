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
	
	init();
	
	char red = 4;
	char green = 0;
	char blue = 0;
	
	while(1) {
		RGB(red, green, blue);
	}
	
	return 1;
} 


