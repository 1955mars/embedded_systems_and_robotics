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
	divcmd4(0x06);//Increment Mode
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
char *str="ABC";
int k=strlen(str),z=0;
lcdstr();
divcmd4(0x01);
while(1)
{
divcmd4(0x80);
_delay_ms(1000);
int i=0;
int s=z;
if(16-z-k==0)
{
	int i=k-1;
	divcmd4(0xc0);
	_delay_ms(1000);
	while(i>0)
	{
		divdata4(str[i]);
while(s>0)
{
	divdata4(' ');
	s--;
}
while(str[i]!='\0')
{
divdata4(str[i]);
_delay_us(100);
i++;
}
z++;
}
}
