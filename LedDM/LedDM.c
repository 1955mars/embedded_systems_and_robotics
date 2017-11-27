#include<avr/io.h>
#include<util/delay.h>
main()
{
DDRB=0xFF;
DDRD=0xFF;
while(1)
{
int x=0x01,y=0x80,u=128,v=1,t=50;
PORTB=x;
for(int z=0;z<=3;z++)
{
while(y>=v)
{
	PORTD=~y;
	_delay_ms(t);
	if(y!=v)
	{
		y>>=1;
	}
	else
		break;
}
if (z==0) x=x*2;
while(x<=u)
{
	PORTB=x;
	_delay_ms(t);
	if(x!=u)
	x<<=1;
	else
	break;
	
}
y=y*2;
while(y<=u)
{
	PORTD=~y;
	_delay_ms(t);
	if (y!=u)
	y<<=1;
	else
	break;
	
}
x=x/2;
v=v*2;
while(x>=v)
{
	PORTB=x;
	_delay_ms(t);
	if(x!=v)
	x>>=1;
	else
	break;
}
y=y/2;
x=x*2;
u=u/2;	
}
}
}
