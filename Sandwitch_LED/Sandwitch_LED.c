#include<avr/io.h>
#include<util/delay.h>
main()
{
DDRB=0xFF;
while(1)
{	
	int j=1;
	for(int i=1;i<=128;i=i*2)
	{
		PORTB=j;
		j=j+(i*2);
		_delay_ms(200);
	}
	j=j-1;
	for(int i=1;i<=128;i=i*2)
	{
		j=j-(i*2);
		PORTB=j;
		_delay_ms(200);
	}

}
}
