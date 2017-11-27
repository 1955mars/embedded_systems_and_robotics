#include<avr/io.h>
#include<util/delay.h>
main()
{
int x,y;
DDRB=0xFF;
DDRD=0xFF;
x=0b00011011;
y=0b00000000;
PORTB=~x;
PORTD=~y;
}

