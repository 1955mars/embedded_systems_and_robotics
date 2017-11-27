#include<avr/io.h>
#include<util/delay.h>
void main()
{
	int x=128,y=1;
	DDRB=0xFF;
	PORTB=0x00;
	while(1)
	{
	 if (x!=y)
	 {
	 	PORTB=x+y;
	 	y=y*2;
		x=x/2;
	
	  }
	  else 
	  {
	    PORTB=
	_delay_ms(1000);
}


}
b
