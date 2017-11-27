#include<avr/io.h>
#include<util/delay.h>
#include<string.h>
#include<mars/lcd.h>
main()
{
	DDRD=0xFF;
	lcdstr();
	divcmd(0x01);
	char *str="Mansoor";
	int s=strlen(str),i=0,j,k=0;
	while(1)
	{
		if(i<=16-s)
		{
			divcmd(0x01);
			disp_string(str,0x80+i);
			_delay_ms(1000);
		}
		if(i>16-s&&i<=16)
		{
			divcmd(0x01);
			divcmd(0x80+i);
			for(j=0;j<(16-i);j++)
			{
				divdata(str[j]);
			}
			_delay_ms(1000);
		}
		i++;
		if(i>16)
		{
			if(k>=s)
		{
			divcmd(0x01);
			disp_string(str,0x80+i);
			_delay_ms(1000);
		}
		if(k<s)
		{
			divcmd(0x01);
			divcmd(0xc0+i);
			for(j=s-k;j>0;j--)
			{
				divdata(str[j]);
			}
			_delay_ms(1000);
		}
		k++;
		}

	}
}