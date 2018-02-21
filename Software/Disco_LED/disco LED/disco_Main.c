/*
 * disco LED.c
 *
 * Created: 13-11-2017 22:08:12
 * Author : Jorre van Merrienboer
 */ 
#include <Test.h>
#include <avr/io.h>
#include <avr/interrupt.h> 
#include <disco_functions.h>

int main(void) {
    while(1) {
		test();
    }
	
	return 1;
}

