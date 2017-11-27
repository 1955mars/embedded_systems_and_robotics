#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
#include<mars/lcdd.h>
#include<string.h>

unsigned int ADC_read(unsigned int chn)
{
	ADMUX=chn|0x40;//(1<<REFSO)|(0<<REFS1)
	ADCSRA=0xd7;
	while((ADCSRA&0x10)==0);
	return ADC;

}
main()
{
	DDRC=0xFF;
	lcdstr();
	int x,y,z;
	while(1)
	{
		x=ADC_read(0);
		y=ADC_read(1);
		z=ADC_read(2);
		disp_number(x,0x89);
		disp_number(y,0xc9);
		disp_number(z,0xcf);
		_delay_ms(10);
	}
}
