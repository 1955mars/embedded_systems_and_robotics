#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
#include<string.h>
void lcdstr(void);
void divcmd4(int);
void sendcmd(int);
void senddata(int);
void divdata4(int);
void min(int u)
{

	
		divcmd4(0xc7);
		divdata4((u/10)+48);
		divdata4((u%10)+48);
		divdata4(':');

}
void hour(int j)
{
	divcmd4(0xc4);
	divdata4((j/10)+48);
	divdata4((j%10)+48);
	divdata4(':');
}

void dc(void)
{
	divcmd4(0x81);
	divdata4('D');
	divdata4('i');
	divdata4('g');
	divdata4('i');
	divdata4('t');
	divdata4('a');
	divdata4('l');
	divdata4(' ');
	divdata4('C');
	divdata4('l');
	divdata4('o');
	divdata4('c');
	divdata4('k');
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
divcmd4(0x01);
int s=0;
int y=0;
while(1)
{	
	for(int i=0;i<=59;i++)
	{
		int k;
		dc();
		hour(y);
		min(s);
		divcmd4(0xcA);
		k=i%10;
		divdata4((i/10)+48);
		divdata4(k+48);
		_delay_ms(1000);
	}
	s++;
	if(s>59)
	{
		s=0;
		y++;
	}
	if(y>23)
	{
		y=0;
	}
			
}

}
