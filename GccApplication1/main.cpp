/*
 * GccApplication1.cpp
 *
 * Created: 02.11.2019 14:34:55
 * Author : Ness
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(INT0_vect)
{
	class LED
	{
		
	public:
	         
	void init() {ddrB.bit0 = 1;}         
	void on() {portB.bit0 = 1;}         
	void off() {portB.bit0 = 0;} 
	
	};
}

int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
		
		
		
    }
}


