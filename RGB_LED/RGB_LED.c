#include<avr/io.h>
#include<util/delay.h>
main()
{
	DDRA=0xFF;
	while(1)
	{
		PORTA=0b00001001;
		_delay_ms(200);
		PORTA=0b00000101;
		_delay_ms(200);
		PORTA=0b00001001;
		_delay_ms(200);

	}
}
	
