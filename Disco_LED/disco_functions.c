/*
 * Disco_Functions.c
 *
 * Created: 30-1-2018 1:33:41
 *  Author: Jorre van Merrienboer
 */ 
#include <avr/io.h>
#include <disco_functions.h>




void RGB(float red, float green, float blue) {		
	int timer_Ref;

	red = (red / 255) * 100;
	green = (green / 255) * 100;
	blue = (blue / 255) * 100;
	
		/////////////
		// RED LED //
		/////////////
		
		if(red == 0) {					
			PORTD &= ~(1 << PIND3);
		}
		
		if(red > 0 && red <= 10) {
			timer_Ref = 0;
			TCNT1 = 0;
			
			while(1) {
				if(TCNT1 > 16 && timer_Ref == 1) {
					PORTD &= ~(1 << PIND3);
					break;
				}
				if(TCNT1 > 140 && timer_Ref != 1) {
					PORTD |= (1 << PIND3);
					timer_Ref = 1;
					TCNT1 = 0;
				}
			}
		}
		
		if(red > 10 && red <= 20) {
			timer_Ref = 0;
			TCNT1 = 0;
			
			while(1) {
				if(TCNT1 > 31 && timer_Ref == 1) {
					PORTD &= ~(1 << PIND3);
					break;
				}
				if(TCNT1 > 125 && timer_Ref != 1) {
					PORTD |= (1 << PIND3);
					timer_Ref = 1;
					TCNT1 = 0;
				}
			}
		}
		
		if(red > 20 && red <= 30) {
			timer_Ref = 0;
			TCNT1 = 0;
			
			while(1) {
				if(TCNT1 > 47 && timer_Ref == 1) {
					PORTD &= ~(1 << PIND3);
					break;
				}
				if(TCNT1 > 109 && timer_Ref != 1) {
					PORTD |= (1 << PIND3);
					timer_Ref = 1;
					TCNT1 = 0;
				}
			}
		}
		
		if(red > 30 && red <= 40) {
			timer_Ref = 0;
			TCNT1 = 0;
			
			while(1) {
				if(TCNT1 > 62 && timer_Ref == 1) {
					PORTD &= ~(1 << PIND3);
					break;
				}
				if(TCNT1 > 93 && timer_Ref != 1) {
					PORTD |= (1 << PIND3);
					timer_Ref = 1;
					TCNT1 = 0;
				}
			}
		}
		
		if(red > 40 && red <= 50) {
			timer_Ref = 0;
			TCNT1 = 0;
			
			while(1) {
				if(TCNT1 > 78 && timer_Ref == 1) {
					PORTD &= ~(1 << PIND3);
					break;
				}
				if(TCNT1 > 78 && timer_Ref != 1) {
					PORTD |= (1 << PIND3);
					timer_Ref = 1;
					TCNT1 = 0;
				}
			}
		}
		
		if(red > 50 && red <= 60) {
			timer_Ref = 0;
			TCNT1 = 0;
			
			while(1) {
				if(TCNT1 > 94 && timer_Ref == 1) {
					PORTD &= ~(1 << PIND3);
					break;
				}
				if(TCNT1 > 62 && timer_Ref != 1) {
					PORTD |= (1 << PIND3);
					timer_Ref = 1;
					TCNT1 = 0;
				}
			}
		}
		
		if(red > 60 && red <= 70) {	
			timer_Ref = 0;
			TCNT1 = 0;
				
			while(1) {
				if(TCNT1 > 109 && timer_Ref == 1) {
					PORTD &= ~(1 << PIND3);
					break;
				}
				if(TCNT1 > 47 && timer_Ref != 1) {
					PORTD |= (1 << PIND3);
					timer_Ref = 1;
					TCNT1 = 0;
				}
			}
		}
	
		if(red > 70 && red <= 80) {
			timer_Ref = 0;
			TCNT1 = 0;
			
			while(1) {
				if(TCNT1 > 125 && timer_Ref == 1) {
					PORTD &= ~(1 << PIND3);
					break;
				}
				if(TCNT1 > 31 && timer_Ref != 1) {
					PORTD |= (1 << PIND3);
					timer_Ref = 1;
					TCNT1 = 0;
				}
			}
		}
		
		if(red > 80 && red <= 90) {
			timer_Ref = 0;
			TCNT1 = 0;
			
			while(1) {
				if(TCNT1 > 140 && timer_Ref == 1) {
					PORTD &= ~(1 << PIND3);
					break;
				}
				if(TCNT1 > 16 && timer_Ref != 1) {
					PORTD |= (1 << PIND3);
					timer_Ref = 1;
					TCNT1 = 0;
				}
			}
		}
		
		if(red > 90 && red <= 100) {
			PORTD |= (1 << PIND3);
		}
		
		//////////////
		// Blue LED //
		//////////////
		
		if(blue == 0) {
			PORTD &= ~(1 << PIND4);
		}
		
		if(blue > 0 && blue <= 25) {
			timer_Ref = 0;
			TCNT1 = 0;
			
			while(1) {
				if(TCNT1 > 39 && timer_Ref == 1) {
					PORTD &= ~(1 << PIND4);
					break;
				}
				if(TCNT1 > 117 && timer_Ref != 1) {
					PORTD |= (1 << PIND4);
					timer_Ref = 1;
					TCNT1 = 0;
				}
			}
		}
		
		if(blue > 25 && blue <= 50) {
			timer_Ref = 0;
			TCNT1 = 0;
			
			while(1) {
				if(TCNT1 > 78 && timer_Ref == 1) {
					PORTD &= ~(1 << PIND4);
					break;
				}
				if(TCNT1 > 78 && timer_Ref != 1) {
					PORTD |= (1 << PIND4);
					timer_Ref = 1;
					TCNT1 = 0;
				}
			}
		}
		
		if(blue > 50 && blue <= 75) {
			timer_Ref = 0;
			TCNT1 = 0;
			
			while(1) {
				if(TCNT1 > 117 && timer_Ref == 1) {
					PORTD &= ~(1 << PIND4);
					break;
				}
				if(TCNT1 > 39 && timer_Ref != 1) {
					PORTD |= (1 << PIND4);
					timer_Ref = 1;
					TCNT1 = 0;
				}
			}
		}
		
		if(blue > 75 && blue <= 100) {
			PORTD |= (1 << PIND4);
		}
		
		///////////////
		// Green LED //
		///////////////
		
		if(green == 0) {
			PORTD &= ~(1 << PIND2);
		}
		
		if(green > 0 && green <= 25) {
			timer_Ref = 0;
			TCNT1 = 0;
			
			while(1) {
				if(TCNT1 > 39 && timer_Ref == 1) {
					PORTD &= ~(1 << PIND2);
					break;
				}
				if(TCNT1 > 117 && timer_Ref != 1) {
					PORTD |= (1 << PIND2);
					timer_Ref = 1;
					TCNT1 = 0;
				}
			}
		}
		
		if(green > 25 && green <= 50) {
			timer_Ref = 0;
			TCNT1 = 0;
			
			while(1) {
				if(TCNT1 > 78 && timer_Ref == 1) {
					PORTD &= ~(1 << PIND2);
					break;
				}
				if(TCNT1 > 78 && timer_Ref != 1) {
					PORTD |= (1 << PIND2);
					timer_Ref = 1;
					TCNT1 = 0;
				}
			}
		}
		
		if(green > 50 && green <= 75) {
			timer_Ref = 0;
			TCNT1 = 0;
			
			while(1) {
				if(TCNT1 > 117 && timer_Ref == 1) {
					PORTD &= ~(1 << PIND2);
					break;
				}
				if(TCNT1 > 39 && timer_Ref != 1) {
					PORTD |= (1 << PIND2);
					timer_Ref = 1;
					TCNT1 = 0;
				}
			}
		}
		
		if(green > 75 && green <= 100) {
			PORTD |= (1 << PIND2);
		}
}

void pwm_RED() {
	
}