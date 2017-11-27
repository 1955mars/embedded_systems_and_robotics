#include<avr/io.h>
#include<util/delay.h>
#include<mars/lcdd.h>
#include<string.h>
int ADC_read(int chn)
{
	ADMUX=chn|0x40;//(1<<REFSO)|(0<<REFS1)
	ADCSRA=0xd7;
	while((ADCSRA&0x10)==0);
	return ADC;

}

main()
{
	DDRC=0xFF;
	lcdstr();
	divcmd(0x01);
	int x=0,y=0,u=1,v=1;
	while(1)
	{
		DDRA=0b11111010;
		PORTA=0b11111000;
		x=ADC_read(2);
		DDRA=0b11110101;
		PORTA=0b11110100;
		y=ADC_read(3);
		
		
		disp_number(x,0x8f);
		disp_number(y,0xcf);
		_delay_ms(100);
	}
}
