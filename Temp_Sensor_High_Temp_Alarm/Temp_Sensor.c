#include<avr/io.h>
#include<util/delay.h>
#include<string.h>
#include<mars/lcdd.h>
int ADC_read(int chn)
{
	ADMUX=chn|0x40;//(1<<REFSO)|(0<<REFS1)
	ADCSRA=0xd7;
	while((ADCSRA&0x10)==0);
	return ADC;

}
main()
{
	DDRC=0xFF;
	DDRA=0xFE;
	lcdstr();
	divcmd(0x01);
	int chn=0,z,x;
	while(1)
	{
		divcmd(0x01);
		z=ADC_read(chn);
		z=z/2;
		x=z%2;
		if(x!=0);
		{
			x=5;
		}
		disp_string("Digital_Thermo",0x80);
		disp_string(".",0xc6);
		disp_string("'C",0xc9);
		disp_number(z,0xc5);
		disp_number(x,0xc7);
		_delay_ms(500);
		if(z>=40)
		{
			PORTC=0x08;
			_delay_ms(200);
		}
	}
}
