#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
#include<string.h>
void lcdstr(void);
void divcmd4(int);
void sendcmd(int);
void senddata(int);
void divdata4(int);
void ball(void)
{
	divcmd4(0x40);
	divdata4(0x00);
	divdata4(0x0E);
	divdata4(0x1f);
	divdata4(0x1f);
	divdata4(0x1f);
	divdata4(0x0e);
	divdata4(0x00);
}
void lcdstr(void)
{
	divcmd4(0x02);//Home position Initialization with dividing function
	divcmd4(0x28);//4 bit mode
	divcmd4(0x06);//Decrement Mode
	divcmd4(0x0c);//Display on cursor off
}
void divcmd4(int b)
{
	sendcmd(b&0xF0);//First 4 bits
	sendcmd((b<<4)&0xF0);//Next 4
	_delay_ms(1);
}
void divdata4(int b)
{
	senddata(b&0xF0);//First 4 bits
	senddata((b<<4)&0xF0);//Next 4
	_delay_ms(1);
}
void sendcmd(int c)
{
	PORTD=c;
	PORTD+=4;
	_delay_ms(1);
	PORTD-=4;
}
void senddata(int c)
{
	PORTD=c;
	PORTD+=5;
	_delay_ms(1);
	PORTD-=4;
}


main()
{
	DDRD=0xFF;
	lcdstr();
	ball();
	divcmd4(0x01);
	while(1)
	{
		int i,j=0,k=0;
		for(i=0;i<32;i++)
		{
			if(i<16)
			{
				divcmd4(0x01);
				divcmd4(0x80+j);
				divdata4(0);
				_delay_ms(300);
				j++;
			}
			else
			{
				divcmd4(0x01);
				divcmd4(0xcF-k);
				divdata4(0);
				_delay_ms(300);
				k++;
			}
		}
	}
}
