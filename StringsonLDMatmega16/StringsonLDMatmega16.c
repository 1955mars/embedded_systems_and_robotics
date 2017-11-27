#include<avr/io.h>
#include<util/delay.h>
main()
{
DDRB=0xFF;
DDRD=0xFF;
int z=2,j;
while(1)
{
for(int k=128;k>=1;k=k/2)
{
if (z%2==0)
{
	j=1;
	for(int i=1;i<=128;i=i*2)
	{
		PORTB=j;
		j=j+(i*2);
		PORTD=~k;
		_delay_ms(100);
	}
}
else
{
	j=128;
	for(int i=128;i>=1;i=i/2)
	{
		PORTB=j;
		j=j+(i/2);
		PORTD=~k;
		_delay_ms(100);
	}
}
z++;
}
}
}
