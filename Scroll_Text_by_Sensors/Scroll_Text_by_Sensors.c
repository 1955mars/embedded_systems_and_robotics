#include<avr/io.h>
#include<util/delay.h>
#include<string.h>
#include<mars/lcdd.h>
main()
{
	DDRC=0xFF;
	DDRA=0xFC;
	lcdstr();
	divcmd(0x01);
	while(1)
	{
	int k=0;
	for(int i=65;i<91;i++)
	{
		divdata(i);
	}
	while(PINA==0);
	while(1)
	{
	int k=7;
	if(PINA==1)
	{
		while(PINA==1);
		while(PINA==0)
		{
			k--;
			_delay_ms(25);
		}
		if(k<=0)
			k=1;
		if(PINA==2)
		{
			while(PINA==2);
			while(k>0)
			{
				divcmd(0x1c);
				divcmd(0x1c);
				_delay_ms(500);
				k--;
			}
		}
	}
	k=7;
	if(PINA==2)
	{
		while(PINA==2);
		while(PINA==0)
		{
			k--;
			_delay_ms(25);
		}
		if(k<=0)
			k=1;
		if(PINA==1)
		{
			while(PINA==1);
			while(k>0)
			{
				divcmd(0x1A);
				divcmd(0x1A);
				_delay_ms(500);
				k--;
			}
		}
	}
}
			
}
}
