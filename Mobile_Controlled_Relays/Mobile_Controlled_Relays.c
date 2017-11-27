#include<avr/io.h>
#include<util/delay.h>
main()
{
	DDRA=0xF0;
	DDRB=0xFF;
	while(1)
	{
		PORTB=PINA;
	}
}
		
