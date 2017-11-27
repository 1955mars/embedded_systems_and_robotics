#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
#include<mars/lcdd.h>
#include<string.h>
#include<math.h>
void timer0_init()
{
	TCCR0=(1<<WGM01)|(1<<COM00)|(1<<CS01);
	DDRB|=(1<<PB3);
}
main()
{
	DDRB=0xFF;
	DDRC=0xFF;
	DDRA=0xFE;
	lcdstr();
	timer0_init();
	divcmd(0x01);
	int sa[]={240,270,300,320,360,405,450};
	int i=0;
	while(1)
	{
		if(PINA==1)
		{
			while(PINA==1);
			OCR0=(F_CPU/(sa[i]*16))-1;
			disp_number(OCR0,0x8f);
			_delay_ms(100);
				i++;
		}
		else
			OCR0=0;
	}
}
	
