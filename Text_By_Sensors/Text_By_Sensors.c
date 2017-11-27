#include<avr/io.h>
#include<util/delay.h>
#include<mars/lcdd.h>
#include<string.h>
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
	DDRA=0xFC;
	lcdstr();
	divcmd(0x01);
	unsigned int h=0,y=0;
	while(1)
	{
		int z=0,j,k;
		j=ADC_read(z);
		k=ADC_read(z+1);

		if(j>220&&j<310)
		{
			_delay_ms(500);
			h=(h*10)+8;
		}
		if(j>310&&j<410)
		{
			_delay_ms(500);
			h=(h*10)+6;
		}
		if(j>410&&j<510)
		{
			_delay_ms(500);
			h=(h*10)+4;
		}
		if(j>510)
		{
			_delay_ms(500);
			h=(h*10)+2;
		}
		disp_number(h,0x8f);
		_delay_ms(100);
		
	}
}
		
