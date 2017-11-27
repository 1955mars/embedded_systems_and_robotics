#include<avr/io.h>
#include<util/delay.h>
#include<mars/lcdd.h>
#include<string.h>
main()
{
	DDRA=0xF0;
	DDRC=0xFF;
	DDRB=0xFF;
	lcdstr();
	divcmd(0x01);
	int x=0,y=0;
	while(1)
	{
		PORTB=PINA;
		disp_number(PINA,0x8f);
	}
}
