/*
 * disco_functions.h
 *
 * Created: 30-1-2018 1:40:30
 *  Author: Jorre
 */ 


#ifndef DISCO_FUNCTIONS_H_
#define DISCO_FUNCTIONS_H_

#include "irremote.h"

unsigned char red_Value;
unsigned char green_Value;
unsigned char blue_Value;

void display_RGB(char red, char green, char blue);
void initialise_ATmega328P(void);
void testRGB(void);
void getCommand(commandAction command);


#endif /* DISCO-FUNCTIONS_H_ */