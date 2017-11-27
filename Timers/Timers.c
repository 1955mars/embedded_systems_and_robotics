#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
#include<mars/lcdd.h>
#include<string.h>
void timer0_init()
{
	TCCR0=(1<<CS01);
	DDRB|=(1<<PB3);
}
main()
{
DDRB=0xFF;
DDRC=0xFF;
lcdstr();
divcmd(0x01);
timer0_init();
while(1)
{
	disp_number(TCNT0,0x8f);
	divcmd(0x01);
}
}
