#include<avr/io.h>
#include<util/delay.h>
#include<string.h>
void lcdstr(void);
void divcmd4(int);
void sendcmd(int);
void senddata(int);
void divdata4(int);
void mystring(int);
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
int k=1;
while(1)
{
if(k==1||k==3) mystring(k);
else if (k==2) mystring(k);
else if(k==4) mystring(k);
else k=1;
for(int i=0;i<10;i++)
{
divcmd4(0x84);
divdata4(0);
_delay_ms(100);
}
k++;
}
}

void mystring(int k)
{
	divcmd4(0x40);
	divdata4(0x04); 
	divdata4(0x0E); 
	divdata4(0x0E); 
	divdata4(0x1F); 
	divdata4(0x04);
	if(k==1||k==3)
	{ 
		divdata4(0x04); 
		divdata4(0x04);
	}
	else if(k==2)
	{
		 divdata4(0x08);
		 divdata4(0x10);
	}
	else if(k==4)
	{
		divdata4(0x02);
		divdata4(0x01);
	}
	divdata4(0x00);
}
