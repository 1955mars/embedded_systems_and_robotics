#include<avr/io.h>
#include<util/delay.h>
#include<string.h>
void lcdstr(void);
void divcmd4(int);
void sendcmd(int);
void senddata(int);
void divdata4(int);
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
int k;
lcdstr();
divcmd4(0x01);
int i=123;
while(i<=200)
{
divcmd4(0x83);
_delay_ms(1000);
k=i;
while(k>0)
{
divcmd4(0x04);
int j;
j=k%10;
k=k/10;
divdata4(j+48);
_delay_us(10);
}
i++;
}
}
