#include<avr/io.h>
#include<util/delay.h>
#include<mars/lcdd.h>
#include<string.h>
#define For 0b00000011;
#define Lef 0b00001000;
#define Rig 0b00000100;
main()
{
	DDRA=0xF0;
	DDRB=0xFF;
	int path[100];
	for(int i=0;i<100;i++)
	{
		path[i]=2;
	}
	int k=0;
	while(1)
	{
		if(PINA==0b00000011)
		{
			PORTB=5;
			_delay_ms(10);
		}
		if(PINA==0b00000111)
		{
			PORTB=4;
			_delay_ms(10);
		}
		if(PINA==0b00001011)
		{
			PORTB=1;
			_delay_ms(10);
		}
		if(PINA==0b00000100)
		{
			PORTB=6;
			_delay_ms(10);
		}
		if(PINA==0b00001000)
		{
			PORTB=9;
			_delay_ms(10);
		}
		if(PINA==0b00000101)
		{
			PORTB=6
		
	}
}
			


