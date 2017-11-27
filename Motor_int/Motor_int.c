#include<avr/io.h>
#include<util/delay.h>
void lcd(void);
void div_cmd4(int);
void div_data4(int);
void sendcmd(int);
void senddata(int);
main()
{
DDRB=0xFF;
DDRD=0xFF;
char *str="Front";
while(1)
{
int i=0;
PORTB=0x0A;
div_cmd4(0x80);
while(str[i]!='/0')
{
	div_data4(str[i]);
}
_delay_ms(3000);
PORTB=0X05;
}
}

void lcd(void)
{
	div_cmd4(0x02);
	div_cmd4(0x28);
	div_cmd4(0x0c);
	div_cmd4(0x06);
}

void div_cmd4(int a)
{
	sendcmd(a&0xff);
	sendcmd((a<<4)&0xff);
}

void sendcmd(int b)
{
	PORTB=b;
	PORTB+=4;
	_delay_ms(1);
	PORTB-=4;
}

void div_data4(int c)
{
	senddata(c&0xff);
	senddata((c<<4)&0xff);
}

void senddata(int d)
{
	PORTB=d;
	PORTB+=5;
	_delay_ms(1);
	PORTB-=4;
}
