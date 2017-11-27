#include<avr/io.h>
#include<util/delay.h>
#include<string.h>
#include<mars/lcd.h>
main()
{
	DDRB=0xFF;
	DDRD=0xFF;
	DDRA=0xF0;
	PORTA=0x0F;
	PORTD=0x0E;
	DDRC=0xF0;
	PORTC=0xE0;
	lcdstr();
	divcmd(0x01);
	while(1)
	{
		if(PINA==0x0E)
		{
			divcmd(0x01);
			disp_string("Left",0x83);
			PORTB=1;
			_delay_ms(10);
		}
		else if(PINA==0x0D)
		{
			divcmd(0x01);
			disp_string("Forward",0x83);
			PORTB=10;
			_delay_ms(10);
			
		}
		else if(PINA==11)
		{
			divcmd(0x01);
			disp_string("Backward",0x83);
			PORTB=5;
			_delay_ms(10);
		}
		else if(PINA==7)
		{
			divcmd(0x01);
			disp_string("Right",0x83);
			PORTB=4;
			_delay_ms(10);
		}
		else
		{
			divcmd(0x01);
			disp_string("Stop",0x83);
			PORTB=0;
			_delay_ms(10);
		}
	}
}