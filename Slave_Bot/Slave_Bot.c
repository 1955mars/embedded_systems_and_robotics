#include<avr/io.h>
#include<util/delay.h>
#include<string.h>
#include<mars/lcdd.h>//Includes the lcd display control functions on PORTC


char *s[]={"Smart_Bee","WF Bot","Math Bot","Back",};//Choosing Our Menu
char *s1[]={"","Digital_Clock","Stop_Watch","LDM_Game","Start","Music"};//Inside app names
void select(int);

//Here starts our main part
main()
{
	DDRD=0xF0;
	DDRB=0;
	DDRC=0xFF;//PORTA is used for IR Sensors
	lcdstr();// Initializing the Lcd display(lcdstr,divcmd,divdata,disp_string,disp_number -->Funtions related)
	divcmd(0x01);//Clearing the previous data on the lcd screen

	int k=0,i,j=0;// k used for changing the text on lcd only when input(gesture) is given..
	while(1)
	{
		if(k==j)
		{
			divcmd(0x01);
			disp_string(s[k],0x82);
			k=j;
		}
		k=0;j=2;
		if(PIND==3)
		{	
			while(PIND==3);
			k++;
			while(1)
			{
				if(k>3)
				 k=1;
				if(k<1)
				 k=3;
				if(k!=j)
				{
					divcmd(0x01);
					disp_string(s[k],0x83);
					disp_number(k,0x80);
					j=k;
				}
				if(PIND==3)
				{
					while(PIND==3);
					_delay_ms(10);
					if(k==3)
					{
						k=j=0;
						break;
					}
					int e=0,s=0;
					while(1)
					{
					DDRD=0xF0;
					int q=0,w=0;
					divcmd(0x01);
					disp_string("Enter PIN__",0x80);
					while(w<4)
					{
						while(==s);
						e=;
						if(w==0)
						{
							divcmd(0x01);
							divcmd(0x80);
						}
						s=e;
						disp_number(e,0x80+w);
						q=q*10+e;
						w++;
						
					}
					if(q==1234)
					{
						select(k);
						_delay_ms(200);
						j++;
					}
					else
					{
						divcmd(0x01);
						disp_string("Incorrect",0x80);
						_delay_ms(500);
	
					}
					}

				}
						
						
				if(PIND==1)//For sliding the apps left wards
				{
					i=0;
					while(i<1000)// If takes more time to slide then not considering as a gesture
					{
						while(PIND==1);
						if(PIND==2)
						{
							while(PIND==2);
							for(int k=0;k<14;k++)
							{
								divcmd(0x1A);
								_delay_ms(60);
							}
							k++;
							break;
					
						}
						i++;
						_delay_us(500);
					}
				}
				if(PIND==2)
				{
					i=0;
					while(i<1000)
					{
						while(PIND==2);
						if(PIND==1)
						{
							while(PIND==1);
							for(int k=0;k<14;k++)
							{
								divcmd(0x1C);
								_delay_ms(60);
							}
							k--;
							break;
					
						}
						i++;
						_delay_us(500);
					}
				}

			}
		}
	}
}


void select(int a)
{	
	divcmd(0x01);
	disp_string("Welcome",0x80);
	while(1);
}

