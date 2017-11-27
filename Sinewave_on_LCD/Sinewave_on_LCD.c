#include<avr/io.h>
#include<util/delay.h>
#include<string.h>
void lcdstr(void);
void divcmd4(int);
void sendcmd(int);
void senddata(int);
void divdata4(int);
void sin1(void)
{
	divcmd4(0x40);
	divdata4(3);
	divdata4(4);
	divdata4(8);
	divdata4(16);
	divdata4(16);
	divdata4(16);
	divdata4(16);
}
void sin2(void)
{
	divcmd4(0x48);
	divdata4(0x18);
	divdata4(4);
	divdata4(2);
	divdata4(1);
	divdata4(1);
	divdata4(1);
	divdata4(1);
}
void sin3(void)
{
	divcmd4(0x50);
	divdata4(16);
	divdata4(16);
	divdata4(16);
	divdata4(16);
	divdata4(8);
	divdata4(4);
	divdata4(3);
}
void sin4(void)
{
	divcmd4(0x58);
	divdata4(1);
	divdata4(1);
	divdata4(1);
	divdata4(1);
	divdata4(2);
	divdata4(4);
	divdata4(0x18);
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
	sin1();sin2();sin3();sin4();
	divcmd4(0x01);
	while(1)
	{	
		int i=4;
		divcmd4(0x1c);
		while(i!=44)
		{
		divcmd4(0x80+i-4);
		divdata4(0);
		divdata4(1);
		divcmd4(0xc2+i-4);
		divdata4(2);
		divdata4(3);
		_delay_ms(10);
		i=i+4;
		}
	}
}
