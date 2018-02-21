/*
 * Disco_Functions.c
 *
 * Created: 30-1-2018 1:33:41
 *  Author: Jorre van Merrienboer
 */ 
#include <avr/io.h>
#include <disco_functions.h>


void RGB(char red, char green, char blue) {		//pwm functie maken
	if(red > 0) {
		PORTD |= (1 << PIND3);
	}
	else {
		PORTD &=~ (1 << PIND3);
	}	
	

	if(green > 0) {
		PORTD |= (1 << PIND2);
	}
	else {
		PORTD &=~ (1 << PIND2);
	}
	

	if(blue > 0) {
		PORTD |= (1 << PIND4);
	}
	else {
		PORTD &=~ (1 << PIND4);
	}
}

