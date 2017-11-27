#include<avr/io.h>
#include<util/delay.h>
void gameover(void)
{
	while(1)
	{
		for(int i=0;i<50;i++)
		{
		PORTB=0x1E;
		PORTD=~0x80;
		_delay_ms(5);
	
	
		PORTB=0x10;
		PORTD=~0x40;
		_delay_ms(5);
		
		PORTB=0x10;
		PORTD=~0x20;
		_delay_ms(5);
		
		}
		for(int i=0;i<50;i++)
		{

		PORTB=0x1E;
		PORTD=~0x20;
		_delay_ms(5);

		PORTB=0x12;
		PORTD=~0x10;
		_delay_ms(5);

		PORTB=0x1E;
		PORTD=~0x08;
		_delay_ms(5);
		}
		for(int i=0;i<50;i++)
		{

		PORTB=0x16;
		PORTD=~0x08;
		_delay_ms(5);

		PORTB=0x16;
		PORTD=~0x04;
		_delay_ms(5);

		PORTB=0x1E;
		PORTD=~0x02;
		_delay_ms(5);
		}
		for(int i=0;i<50;i++)
		{
		PORTB=0x02;
		PORTD=~0x04;
		_delay_ms(5);
		PORTB=0x1E;
		PORTD=~2;
		_delay_ms(5);
		PORTB=0x02;
		PORTD=~1;
		_delay_ms(5);
		}
	}
	
}
main()
{
	DDRB=0xFF;
	DDRD=0xFF;
	DDRA=0xFC;
	int x=1,y=128,t=200;
	PORTB=x;
	PORTD=~y;
	_delay_ms(5000);
	while(1)
	{
		if(PINA==0)
		{	
			while(PINA==0)
			{
				y=y/2;
				PORTB=x;
				PORTD=~y;
				_delay_ms(t);
			if(y<1)
			{
				gameover();
			}
			}
		}
		
		if(PINA==1)
		{
			while(PINA==1)
			{
				x=x*2;
				PORTB=x;
				PORTD=~y;
				_delay_ms(t);
				if(x>128)
				{
					gameover();
				}
			}
		}
		if(PINA==2)
		{
			while(PINA==2)
			{
				y=y*2;
				PORTB=x;
				PORTD=~y;
				_delay_ms(t);
				if(y>128)
				{
					gameover();
				}
			}
		}
		if(PINA==3)
		{
			while(PINA==3)
			{
				x=x/2;
				PORTB=x;
				PORTD=~y;
				_delay_ms(t);
				if(x<1)
				{
					gameover();
				}
			}
		}
			

	}
}

