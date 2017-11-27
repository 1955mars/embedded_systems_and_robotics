#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
#define Baud_Rate 1200UL
#define ubrr_value ((F_CPU/(16UL*Baud_Rate))-1)
#include<mars/lcdd.h>
#include<string.h>
unsigned char usart_rec()
{
	while(!(UCSRA & (1<<RXC)));
	{}
	return UDR;
}
unsigned char usart_send(unsigned char data)
{
	while(!(UCSRA & (1<<UDRE)));
	UDR=data;
}

void usart_init(void)
{
	UBRRL = ubrr_value;
	UBRRH = (ubrr_value>>8);
	UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	UCSRB=(1<<RXEN)|(1<<TXEN);
}
main()
{
	unsigned int x;
	usart_init();
	DDRB=0XFF;
	DDRC=0xFF;
	lcdstr();
	divcmd(0x01);
	divcmd(0x80);
	int u=0;
	while(1)
	{
		x=usart_rec();
		usart_send(x);
		if(u==16)
		{
			divcmd(0x88);
		}
		
		else if(u==32)
		{
			PORTC=8;
			_delay_ms(500);
			PORTC=0;
			continue;
		}
			
		divdata(x);
		_delay_ms(100);
		u++;
		
			
	
	}
}
	
