#include<avr/io.h>
#include<util/delay.h>
void ssd(int value);
main()
{
DDRB=0XFF;
DDRD=0XFF;
int i;
for(i=1;i<=9;i++)
{
	ssd(i);

	}
}

void ssd(int value)
{
	switch (value)
	{
		case 1:
		{
			PORTB=~0b00011011;
			PORTD=~0b00011111;
			_delay_ms(2000);
		}
		case 2:
		{
			PORTB=~19;
			PORTD=~24;	_delay_ms(500);
		}
		case 3:
		{
			PORTB=~19;
			PORTD=~10;	_delay_ms(500);
		}
		case 4:
		{
			PORTB=~24;
			PORTD=~2;	_delay_ms(500);
		}
		case 5:
		{
			PORTB=~26;
			PORTD=~24;	_delay_ms(500);
		}
		case 6:
		{
			PORTB=~26;
			PORTD=~26;	_delay_ms(500);
		}
		case 7:
		{
			PORTB=~19;
			PORTD=~2;	_delay_ms(500);
		}
		case 8:
		{
			PORTB=~31;
			PORTD=~31;	_delay_ms(500);
		}
		case 9:
		{
			PORTB=~31;
			PORTD=~2;	_delay_ms(500);
		}
		case 0:
		{
			PORTB=~1;
			PORTD=~2;	_delay_ms(500);
		}
	}
}
