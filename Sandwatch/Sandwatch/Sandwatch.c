#include<avr/io.h>
#include<util/delay.h>
main()
{
DDRB=0xFF;
while(1)
{
int k=0,j=128;
while(j>0)
{
for(int i=1;i<=j;i=i*2)
{
	PORTB=i+k;
	_delay_ms(100);
}
k=k+j;
j=j/2;
}
}
}
