#include<avr/io.h>
#include<util/delay.h>
#include<string.h>
#include<mars/lcd.h>
void airtel(void);
void timer_0_init(void)
{
	TCCR0=0b00011010;
	DDRB=0x08;
}
main()
{
	DDRD=0xFF;
	lcdstr();
	divcmd(0x01);
	timer_0_init();
while(1)
{
	sari();
}
}

void sari(void)
{
OCR0=59;
_delay_ms(1000);
OCR0=52;
_delay_ms(1000);
OCR0=46;
_delay_ms(1000);
OCR0=42;
_delay_ms(1000);
OCR0=38;
_delay_ms(1000);
OCR0=34;
_delay_ms(1000);
OCR0=30;
_delay_ms(1000);
OCR0=46;
_delay_ms(1000);
}


