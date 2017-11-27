//Calculating the speed of a passing object using two IR sensors
#include<avr/io.h>
#include<util/delay.h>
#include<string.h>
#include<mars/lcd.h>
main()
{
	DDRA=0xFC;
	DDRD=0xFF;
	lcdstr();
	divcmd(0x01);
	int dist,i=0,j=0,k;
	float speed=0,m;
	while(1)
	{
		if(PINA==1)
		{
			while(PINA==1);
			i=0;
			while(1)
			{
				if(PINA==2)
				{
					while(PINA==2);
					j=0;
					speed=(5*36)/(i*10);
					k=speed;
					m=k+0.5;
					divcmd(0x01);
					break;
				}
				_delay_ms(10);
				i++;
			}
		}
		if(j==0)
		{
			disp_string("Speed ",0x80);
			disp_string("KMPH",0x8B);
			disp_number(speed,0x88);
			j++;
		}
	}
}
