#include<avr/io.h>
#include<string.h>
#include<util/delay.h>
#include<mars/lcd.h>
main()
{
	DDRD=0xFF;
	lcdstr();
	divcmd(0x01);
	DDRA=0xFE;
	DDRB=0xFF;
	int rot=0,s;
	while(1)
	{	
		divcmd(0x01);
		disp_string("RPM",0x81);
		divcmd(0xc5);
		s=rot*12;
		while(s>0)
		{
			divcmd(0x04);
			int j;
			j=s%10;
			divdata(j+48);
			s=s/10;
		}
		rot=0;
		for(int i=0;i<200;i++)
		{
		PORTB=0x01;
		if(PINA==0)
			{	while(PINA==0)
				{}
				rot++;
			}
			_delay_ms(10);
			
		}

	}
}
	
