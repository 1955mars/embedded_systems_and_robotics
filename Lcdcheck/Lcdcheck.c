#define F_CPU 2000000UL
#include<avr/io.h>
#include<util/delay.h>
#include<mars/lcdd.h>
#include<string.h>
main()
{
	DDRC=0xFF;
	lcdstr();
	divcmd(0x01);
	disp_string("MarsRenuLove",0x80);
	while(1)
	{
		
	}
}
