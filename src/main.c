/*
* prototype.c
*
* Created: 21-2-2018 20:30:53
*  Author: Jorre
*/

#define F_CPU 8000000UL

//AVR-libraries
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

//Function-libraries
#include <disco_functions.h>
#include <irremote.h>
#include <remotes.h>
#include <commonTimer.h>

/*
Nog te doen & gevonden problemen
- REPEAT_CMD eleganter inplementeren
- FADE command implementeren
- FLASH command implementeren
- SMOOTH command implementeren

*/
int main(void) 
{
	initialiseATmega328P();
	initIR(5, RGB_REMOTE_ADDRESS, RGB_REMOTE);
	init100usTimer2(F_CPU);
	
	commandAction command = NO_ACTION;
	
	brightness_Percentage = 100;
	
	red_Value = 0;
	green_Value = 0;
	blue_Value = 0;
	
	while(1) 
	{							
		command = getIRCommandRec();
		executeCommand(command);
		displayRGB(red_Value, green_Value, blue_Value);	
	}
	
	return 1;
} 



