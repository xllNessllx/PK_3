/*
 * GccApplication1.cpp
 *
 * Created: 02.11.2019 14:34:55
 * Author : Ness
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 1000000UL
#include <util/delay.h>

void ledOff();
void ledRed();
void ledYellow();

void init(){
	DDRB = 0b11111111;
	DDRC = 0b00000000;
	
	PORTC = 0xFF;
}

void ledRed(){
	while(1){
		PORTB = (1 << PB0);
		_delay_ms(200);
		PORTB = (0 << PB0);
		_delay_ms(200);
		if(~PINC & 0x02){
			break;
		}
		if(~PINC & 0x01){
			ledOff();
		}
	}
}

void ledYellow(){
	while(1){
		PORTB = (1 << PB1);
		_delay_ms(200);
		PORTB = (0 << PB1);
		_delay_ms(200);
		if(~PINC & 0x01){
			break;
		}
		if(~PINC & 0x02){
			ledOff();
		}
	}
}

void ledOff(){
	while(1){
		_delay_ms(200);
		if(~PINC & 0x01){
			ledRed();
		}
		if(~PINC & 0x02){
			ledYellow();
		}
	}
}

int main(void)
{
    /* Replace with your application code */
	
	init();
	
    while (1) 
    {
	
		if(~PINC & 0x01){
			ledRed();
		}
		else if(~PINC & 0x02){
			ledYellow();
		}
    }
}


