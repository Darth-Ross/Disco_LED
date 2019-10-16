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

unsigned char red_Max;
unsigned char green_Max;
unsigned char blue_Max;

signed char brightness_Percentage;

commandAction previous_Command;

void displayRGB(char red, char green, char blue);
void initialiseATmega328P(void);
void testRGB(void);
void executeCommand(commandAction command);


#endif /* DISCO-FUNCTIONS_H_ */