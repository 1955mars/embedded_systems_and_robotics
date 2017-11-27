#include<avr/io.h>
#include<util/delay.h>
#include<string.h>
#include<mars/lcd.h>
void timer(void)
{
	TCCR0=0x1A;;
	DDRB=0x08;
}

int ADC_read(int chn)
{
	ADMUX=chn|0x40;//(1<<REFSO)|(0<<REFS1)
	ADCSRA=0xd7;
	while((ADCSRA&0x10)==0);
	return ADC;

}
main()
{
	DDRD=0xFF;
	lcdstr();
	divcmd(0x01);
	timer();
	int chn=0,chn1=1,x,y;
	while(1)
	{
		divcmd(0x01);
		x=ADC_read(chn);
		y=ADC_read(chn1);
		x=x/4;
		y=y/4;
		disp_string("x",0x88);
		disp_number(x,0x8F);
		disp_string("y",0xc8);
		disp_number(y,0xcF);
		OCR0=x;
		_delay_ms(100);
		OCR0=y;
		_delay_ms(100);
	}
}
			

