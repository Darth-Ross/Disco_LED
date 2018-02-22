/*
 * Disco_Functions.c
 *
 * Created: 30-1-2018 1:33:41
 *  Author: Jorre van Merrienboer
 */ 
#include <avr/io.h>
#include <disco_functions.h>


void RGB(char red, char green, char blue) {		

	red = 1;
	green = green/255 * 100;
	blue = blue/255 * 100;
	
	switch(red) {
		case 1:
			if(red > 25 && red <= 50) {
				TCNT1 = 0;

				if(TCNT1 > 78) {
					PORTD |= (1 << PIND3);
					TCNT1 = 0;
				
					if(TCNT1 > 78 ) {
						PORTD &= ~(1 << PIND3);
						break;
					}
				}
			}
	
	
	}
}
	/*
		if(red == 0) {					
			PORTD &= ~(1 << PIND3);
		}
		
		if(red > 0 && red <= 25) {		
			TCNT1 = 0;

			if(TCNT1 > 117) {
				PORTD |= (1 << PIND3);
				TCNT1 = 0;
				
				if(TCNT1 > 39) {
					PORTD &= ~(1 << PIND3);
				}
			}
		}
	
		if(red > 25 && red <= 50) {
			TCNT1 = 0;

			if(TCNT1 > 78) {
				PORTD |= (1 << PIND3);
				TCNT1 = 0;
				
				if(TCNT1 > 78 ) {
					PORTD &= ~(1 << PIND3);
				}
			}
		}
		
		if(red > 50 && red <= 75) {
				TCNT1 = 0;

				if(TCNT1 > 39) {
					PORTD |= (1 << PIND3);
					TCNT1 = 0;
					
					if(TCNT1 > 117) {
						PORTD &= ~(1 << PIND3);
					}
				}
		}
		
		if(red > 75 && red <= 100) {
			PORTD |= (1 << PIND3);
			
		}
}


*/
