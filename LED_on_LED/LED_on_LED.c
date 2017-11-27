#include<avr/io.h>
#include<util/delay.h>
main()
{
DDRB=0xFF;
DDRD=0xFF;
while(1)
{
	
	PORTB=0x7C;
	PORTD=~(0x80);
	_delay_ms(5);
	PORTB=0x40;
	PORTD=~(0x60);
	_delay_ms(5);
	
	PORTB=0x7C;
	PORTD=~(0x10);
	_delay_ms(5);
	PORTB=0x54;
	PORTD=~(0x08);
	_delay_ms(5);
	
	
	PORTB=0x7C;
	PORTD=~(0x04);
	_delay_ms(5);
	PORTB=0x44;
	PORTD=~(0x02);
	_delay_ms(5);
	PORTB=0x38;
	PORTD=~(0x01);
	_delay_ms(5);
}
}
