#include<avr/io.h>
#include<util/delay.h>
main()
{
int x;
DDRB=0xFF;
PORTB=0x00;
for(x=0x00;;x++)
{
	PORTB=x;
	delay_ms(100);
}
}

