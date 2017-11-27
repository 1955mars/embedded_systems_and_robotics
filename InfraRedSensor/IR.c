#include<avr/io.h>
#include<util/delay.h>
#include<string.h>
#include<mars/lcd.h>
main()
{
	DDRD=0xFF;
	DDRA=0xfe;
	lcdstr();
	int i=0;
	while(1)
	{
		divcmd(0x01);
		disp_string("Visitors_In",0x82);
		divcmd(0xc5);
		divdata(i+48);
		if(PINA==1)
		{	
				i++;
				while(PINA==1)
				{}
			
		
			
		}
		
		_delay_ms(100);

	}

}
