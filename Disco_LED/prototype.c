/*
* prototype.c
*
* Created: 21-2-2018 20:30:53
*  Author: Jorre
*/

#define F_CPU 16000000UL

//Functions
#include <disco_functions.h>
#include <irremote.h>
#include <remotes.h>
#include <commonTimer.h>

//AVR
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void) 
{
	commandAction command;
	
	initialise_ATmega328P();
	initIR(5, RGB_REMOTE_ADDRESS, RGB_REMOTE);
	init100usTimer2(F_CPU);
	
	while(1) 
	{										
		command = getIRCommandRec();
		getCommand(command);
		display_RGB(red_Value,green_Value,blue_Value);
	}
	
	
	return 1;
} 



