/*
 * Disco_Functions.c
 *
 * Created: 30-1-2018 1:33:41
 *  Author: Jorre van Merrienboer
 */ 

#define F_CPU 8000000UL

// AVR-libraries
#include <avr/io.h>
#include <avr/common.h>
#include <util/delay.h>

// Function-libraries
#include <disco_functions.h>
#include <irremote.h>


void initialiseATmega328P(void)
{
	/////////
	// I/0 //
	/////////

	DDRD = 0xFF;				// Set PORT D as output
	DDRB = 0xFF;				// Set PORT B as output
	
	PORTD = 0;					// Set PORT D to 0
	PORTB = 0;					// Set PORT B to 0

	/////////////
	// Timer 0 //
	/////////////

	/* Set waveform generation mode to fast PWM */
	TCCR0A |= (1 << 0);			// Set WGM00 to 1
	TCCR0A |= (1 << 1);			// Set WGM01 to 1
	TCCR0B &= ~(1 << 3);		// Set WGM02 to 0
	
	/* Set compare output mode A to inverting */
	TCCR0A |= (1 << 6);			// Set COM0A0 to 1
	TCCR0A |= (1 << 7);			// Set COM0A1 to 1
	
	/* Set compare output mode B to inverting */
	TCCR0A |= (1 << 4);			// Set COM0B0 to 1
	TCCR0A |= (1 << 5);			// Set COM0B1 to 1
	
	/* Setting prescaler to 64, PWM frequency is around 1kHz */
	TCCR0B |= (1 << 0);			// Set CS00 to 1
	TCCR0B |= (1 << 1);			// Set CS01 to 1
	TCCR0B &= ~(1 << 2);		// Set CS02 to 0
	
	/////////////
	// Timer 1 //
	/////////////
	
	/* Set waveform generation mode to fast PWM 8 bit */
	TCCR1A |= (1 << 0);			// Set WGM10 to 1
	TCCR1A &= ~(1 << 1);		// Set WGM11 to 0
	
	TCCR1B |= (1 << 3);			// Set WGM12 to 1
	TCCR1B &= ~(1 << 4);		// Set WGM13 to 0
	
	/* Set compare output mode A to inverting */
	TCCR1A |= (1 << 6);			// Set COM1A0 to 1
	TCCR1A |= (1 << 7);			// Set COM1A1 to 1
	
	/* Setting prescaler to 64, PWM frequency is around 1kHz */
	TCCR1B |= (1 << 0);			// Set CS10 to 1
	TCCR1B |= (1 << 1);			// Set CS11 to 1
	TCCR1B &= ~(1 << 2);		// Set CS12 to 0
	
	/////////////
	// General //
	///////////// 
	
	TCNT0 = 0;
	TCNT1 = 0;
	
	PORTB |= (1 << 3);			// Turn on successful initialization LED. 
}

void displayRGB(char red, char green, char blue) 
{
	char PWM_RED;
	char PWM_GREEN;
	char PWM_BLUE;
	
	PWM_RED = 255 - ((red / 100) * brightness_Percentage);
	PWM_GREEN = 255 - ((green / 100) * brightness_Percentage);
	PWM_BLUE = 255 - ((blue / 100) * brightness_Percentage);	

	OCR0A = PWM_RED;
	OCR1A = PWM_GREEN;
	OCR0B = PWM_BLUE;
}

void testRGB(void) 
{
		displayRGB(255,0,0);
		_delay_ms(500);
		displayRGB(255,128,0);
		_delay_ms(500);
		displayRGB(255,255,0);
		_delay_ms(500);
		displayRGB(128,255,0);
		_delay_ms(500);
		displayRGB(0,255,128);
		_delay_ms(500);
		displayRGB(0,255,255);
		_delay_ms(500);
		displayRGB(0,128,255);
		_delay_ms(500);
		displayRGB(0,0,255);
		_delay_ms(500);
		displayRGB(127,0,255);
		_delay_ms(500);
		displayRGB(255,0,255);
		_delay_ms(500);
		displayRGB(255,0,127);
		_delay_ms(500);
		displayRGB(128,128,128);
		_delay_ms(500);
		displayRGB(0,0,0);
}

// Make safety for underflow or overflow
void brightness(char select)
{
	if(select == 1)
	{
		brightness_Percentage += 5;
		if(brightness_Percentage >= 100)	//Overflow protection 
		{
			brightness_Percentage = 100;
		}	
	}
	else
	{
		brightness_Percentage -= 5;
		if(brightness_Percentage <= 1)		//Underflow protection
		{
			brightness_Percentage = 1;	
		}
	}
}

void powerOff(void)
{
	commandAction command;
	displayRGB(0,0,0);
	
	while(command != ON)
	{
		command = getIRCommandRec();
	}
}

void ledFLASH(void)
{

}

// Create all commands
void executeCommand(commandAction command) 
{
	if(command == CMD_REPEAT)
	{
		command = previous_Command;
	}

	switch(command) 
	{
		case OFF:
			powerOff();
			break;
	
		case BPLUS:
			brightness(1);
			previous_Command = command;
			break;
		
		case BMIN:
			brightness(0);
			previous_Command = command;
			break;
		
		case FLASH:
			// Create function
			ledFLASH();
			break;
		
		case STROBE:
			testRGB();
			break;
		
		case FADE:
			// Create function
			break;
		
		case SMOOTH:
			// Create function
			break;
			
			// Red
		case R:
			red_Value = 255;
			green_Value = 0;
			blue_Value = 0;
			break;
			
			// Green
		case G:
			red_Value = 0;
			green_Value = 255;
			blue_Value = 0;
			break;
			
			// Blue
		case B:
			red_Value = 0;
			green_Value = 0;
			blue_Value = 255;
			break;
			
			// White
		case W:
			red_Value = 255;
			green_Value = 255;
			blue_Value = 255;
			break;
				
			// Orange-red
		case B1:
			red_Value = 255;
			green_Value = 64;
			blue_Value = 0;
			break;
		 
			// Green-blue
		case B2:
			red_Value = 0;
			green_Value = 255;
			blue_Value = 64;
			break;
		
			// Blue-red
		case B3:
			red_Value = 64;
			green_Value = 255;
			blue_Value = 0;
			break;
		
			// Orange
		case B4:
			red_Value = 255;
			green_Value = 128;
			blue_Value = 0;
			break;
		
			// Cyan 3
		case B5:
			red_Value = 0;
			green_Value = 255;
			blue_Value = 128;
			break;
		
			// Purple 1
		case B6:
			red_Value = 128;
			green_Value = 0;
			blue_Value = 255;
			break;
		
			// Orange 2
		case B7:
			red_Value = 255;
			green_Value = 191;
			blue_Value = 0;
			break;	
		
			// Cyan 2
		case B8:
			red_Value = 0;
			green_Value = 255;
			blue_Value = 191;
			break;
		
			// Purple 2
		case B9:
			red_Value = 191;
			green_Value = 0;
			blue_Value = 255;
			break;
		
			//	Yellow
		case B10:
			red_Value = 255;
			green_Value = 255;
			blue_Value = 0;
			break;
		
			// Cyan 1
		case B11:
			red_Value = 0;
			green_Value = 255;
			blue_Value = 255;
			break;
		
			// Magenta
		case B12:
			red_Value = 255;
			green_Value = 0;
			blue_Value = 255;
			break;
			
		default:
			break;	
	}
}

