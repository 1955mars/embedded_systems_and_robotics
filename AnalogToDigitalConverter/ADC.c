#include<avr/io.h>
#include<util/delay.h>
#include<string.h>
#include<mars/lcd.h>
int ADC_read(int chn)
{
	ADMUX=chn|0x40;//(1<<REFSO)|(0<<REFS1)
	ADCSRA=0xd7;
	while((ADCSRA&0x10)==0);
	return ADC;

}

main()
{
	DDRB=0xFF;
	int chn=0,z;
	while(1)
	{
		z=ADC_read(chn);
		if(z<200)
		{
			PORTB=0;
			_delay_ms(1000);
		
		}
		if(z>200&&z<400)
		{
			PORTB=1;
			_delay_ms(1000);
		}
		if(z>400&&z<800)
		{
			PORTB=4;
			_delay_ms(1000);
		}
		if(z>800)
		{
			PORTB=5;
			_delay_ms(1000);
		}
	}
}

	















