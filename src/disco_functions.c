/*
 * Disco_Functions.c
 *
 * Created: 30-1-2018 1:33:41
 *  Author: Jorre van Merrienboer
 */ 

#define F_CPU 16000000UL

// AVR-libraries
#include <avr/io.h>
#include <avr/common.h>
#include <util/delay.h>

// Function-libraries
#include <disco_functions.h>
#include <irremote.h>


void initialise_ATmega328P(void)
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
	
	red_Value = 0;
	green_Value = 0;
	blue_Value = 0;
}

// Outputs all the signals according to the RGB values
void display_RGB(char red, char green, char blue) 
{
	char PWM_RED;
	char PWM_GREEN;
	char PWM_BLUE;
	
	PWM_RED = 255 - red;
	PWM_GREEN = 255 - green;
	PWM_BLUE = 255 - blue;	

	OCR0A = PWM_RED;
	OCR1A = PWM_GREEN;
	OCR0B = PWM_BLUE;
}

// Tests the RGB ledstrip with all colours
void testRGB(void) 
{
		display_RGB(255,0,0);
		_delay_ms(500);
		display_RGB(255,128,0);
		_delay_ms(500);
		display_RGB(255,255,0);
		_delay_ms(500);
		display_RGB(128,255,0);
		_delay_ms(500);
		display_RGB(0,255,128);
		_delay_ms(500);
		display_RGB(0,255,255);
		_delay_ms(500);
		display_RGB(0,128,255);
		_delay_ms(500);
		display_RGB(0,0,255);
		_delay_ms(500);
		display_RGB(127,0,255);
		_delay_ms(500);
		display_RGB(255,0,255);
		_delay_ms(500);
		display_RGB(255,0,127);
		_delay_ms(500);
		display_RGB(128,128,128);
		_delay_ms(500);
		display_RGB(0,0,0);
}

// Changes brightnes up or down based on select
void brightness(char select)
{
	if(select == 1)
	{
		if(red_Value > 0)
		{
			red_Value+=10;
		}
		
		if(green_Value > 0)
		{
			green_Value+=10;
		}
		
		if(blue_Value > 0)
		{
			blue_Value+=10;
		}
		
	}
	else
	{
		if(red_Value > 0)
		{
			red_Value-=10;
		}
		
		if(green_Value > 0)
		{
			green_Value-=10;
		}
		
		if(blue_Value > 0)
		{
			blue_Value-=10;
		}
	}
}

// Turns the system off and on again if called upon again
void systemControl(void)
{
	commandAction command;
	display_RGB(0,0,0);
	
	while(command != ON)
	{
		command = getIRCommandRec();
	}
}

// Decides which function will be executed according to the command of the IR remote
void getCommand(commandAction command) 
{
	switch(command) {
		
		case OFF:
			systemControl();
			break;
		
		case BPLUS:
			brightness(1);
			break;
		
		case BMIN:
			brightness(0);
			break;
		
		case FLASH:
			// Create function
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
			red_Value = red_Value;
			green_Value = green_Value;
			blue_Value =  blue_Value;
			break;	
	}
}

