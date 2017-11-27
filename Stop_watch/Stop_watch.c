#include<avr/io.h>
#include<util/delay.h>
#include<string.h>
#include<mars/lcd.h>
void lcdstr(void);
void divcmd4(int);
void sendcmd(int);
void senddata(int);
void divdata4(int);
void min(int u)
{

	
		divcmd(0xc7);
		divdata((u/10)+48);
		divdata((u%10)+48);
		divdata(':');

}
void sec(int u)
{

	
		divcmd(0xcA);
		divdata((u/10)+48);
		divdata((u%10)+48);
		divdata(':');

}
void hour(int j)
{
	divcmd(0xc4);
	divdata((j/10)+48);
	divdata((j%10)+48);
	divdata(':');
}

void sw(void)
{
	disp_string("STOP-WATCH",0x83);
}
main()
{
DDRD=0xFF;
DDRC=0xF0;
DDRA=0xF0;
PORTA=0x0F;
PORTC=0xE0;
lcdstr();
divcmd(0x01);
int s=0,y=0,z=0;
while(1)
{	
	for(int i=0;i<=10;i++)
	{
		
		if(PINA==0x0E)
		{
			_delay_ms(20);
			while(PINA==0x0E||PINA==0x0F);
			
		}

		else if(PINA==11)
		{
			_delay_ms(20);
			s=0;y=0;z=0;i=0;
			while(PINA==11||PINA==0x0F)
			{
			int k;
			sw();
			hour(y);
			min(s);
			sec(z);
			divcmd(0xcd);
			k=i%10;
			divdata((i/100)+48);
			divdata((i/10)+48);
			divdata(k+48);
			divdata(':');
			}
		}
		else if(PINA==7)
		{
			_delay_ms(20);
			int k;
			sw();
			hour(y);
			min(s);
			sec(z);
			divcmd(0xcd);
			k=i%10;
			divdata((i/100)+48);
			divdata((i/10)+48);
			divdata(k+48);
			divdata(':');
		}
		else
		{
			int k;
			sw();
			hour(y);
			min(s);
			sec(z);
			divcmd(0xcd);
			k=i%10;
			divdata((i/100)+48);
			divdata((i/10)+48);
			divdata(k+48);
			divdata(':');
		}

	}
	z++;
	if(z>59)
	{
		z=0;
		s++;
	}
	if(s>59)
	{
		s=0;
		y++;
	}
	if(y>23)
	{
		y=0;
	}
			
}

}
