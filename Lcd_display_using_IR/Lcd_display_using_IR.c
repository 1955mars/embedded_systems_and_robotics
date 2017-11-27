#include<avr/io.h>
#include<util/delay.h>
#include<string.h>
#include<mars/lcd.h>
int ADC_read(int chn)
{
	ADMUX=chn|0x40;//(1<<REFSO)|(0<<REFS1)
	ADCSRA=0xd7;
	while((ADCSRA&0x10)==0);
	return ADC;

}

main()
{
	DDRB=0xFF;
	DDRD=0xFF;
	lcdstr();
	divcmd(0x01);
	int chn1=1,z,y,x=0;
	while(1)
	{
	for(int i=0;i<100;i++)
	{	
		z=ADC_read(chn1);
		if(z>100&&z<190)
		{
			y=1;
			disp_number(y,0xcF);
			_delay_ms(10);
		}

		if(z>190&&z<280)
		{
			y=2;
			disp_number(y,0xcF);
			_delay_ms(10);
		}
		if(z>280&&z<370)
		{
			y=3;
			disp_number(y,0xcF);
			_delay_ms(10);
		}
		if(z>370&&z<460)
		{
			y=4;
			disp_number(y,0xcF);
			_delay_ms(10);
		}
		if(z>460&&z<550)
		{
			y=5;
			disp_number(y,0xcF);
			_delay_ms(10);
		}
		if(z>550&&z<640)
		{
			y=6;
			disp_number(y,0xcF);
			_delay_ms(10);
		}
		if(z>640&&z<730)
		{
			y=7;
			disp_number(y,0xcF);
			_delay_ms(10);
		}
		if(z>730&&z<820)
		{
			y=8;
			disp_number(y,0xcF);
			_delay_ms(10);
		}
		if(z>820&&z<910)
		{
			y=9;
			disp_number(y,0xcF);
			_delay_ms(10);
		}
		if(z>910)
		{
			y=0;
			disp_number(y,0xcF);
			_delay_ms(10);
		}
		_delay_ms(10);

	}
	x=x*10+y;
	disp_number(x,0x8F);
	_delay_ms(500);
	}
}