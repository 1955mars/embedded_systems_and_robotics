#include<avr/io.h>
#include<util/delay.h>
#include<mars/lcdd.h>
#include<string.h>
main()
{
	DDRB=0xFF;
	DDRA=0xFC;
	DDRC=0xFF;
	lcdstr();
	clear();
	PORTB=10;
	int rot=0,area[10],z=0,dist=0,total,h=0,f3=0;
	for(int i ;i<10;i++)
	{	area[i]=0;	}
	while(1)
	{
		if(PINA==1)
		{
			while(PINA==1);
			rot++;
			f3++;
			total=rot;
			dist=rot;
			divcmd(0x01);
			disp_string("Dist",0x80);
			disp_number(total,0x8f);
			if(h>0)
			{
				disp_number(h,0x8B);
			}
			for(int j=0,h=4;j<=z;j++)
			{
				disp_number(area[j],0xc0+h);
				h+=2;
			}
			if(total>=100)
			{
				total=0;
				rot=0;
				h++;
			}
			if(f3==3)
			{
				rot++;
				f3=0;
			}
	
		}
		if(PINA==2||PINA==3)
		{
			PORTB=6;
				{
			DDRA=0xFE;
			int k=0;
			while(PINA==1);
			while(k<=7)
			{
				if(PINA==1)
					while(PINA==1);
					k=k+1;
				}
			}
			DDRA=0xFC;
			PORTB=10;
		}
		
	}

}
		
		

