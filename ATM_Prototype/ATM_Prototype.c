//				ATM_Prototype

#include<avr/io.h>
#include<util/delay.h>
#include<string.h>
#include<mars/lcdd.h>//Includes the lcd display control functions on PORTC


char *s[]={"ATM__","Banking","Balance_Enquiry","Transfer","Credit","Services","Change_Password","Back"};//Choosing Our Menu
char *s1[]={"","Digital_Clock","Stop_Watch","LDM_Game","Start","Music"};//Inside app names
void select(int);

//Here starts our main part
main()
{
	DDRD=0xF0;//PORTD is used for the columns of the LED  DOT  MATRIX
	DDRB=0xFF;//PORTB is used for the  rows   of the LED  DOT  MATRIX
	DDRC=0xFF;//PORTC is used for the Lcd display
	DDRA=0xFC;//PORTA is used for IR Sensors
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
		if(PINA==3)
		{	
			while(PINA==3);
			k++;
			while(1)
			{
				if(k>7)
				 k=1;
				if(k<1)
				 k=7;
				if(k!=j)
				{
					divcmd(0x01);
					disp_string(s[k],0x83);
					disp_number(k,0x80);
					j=k;
				}
				if(PINA==3)
				{
					while(PINA==3);
					_delay_ms(10);
					if(k==7)
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
						while(PIND==s);
						e=PIND;
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
						
						
				if(PINA==1)//For sliding the apps left wards
				{
					i=0;
					while(i<1000)// If takes more time to slide then not considering as a gesture
					{
						while(PINA==1);
						if(PINA==2)
						{
							while(PINA==2);
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
				if(PINA==2)
				{
					i=0;
					while(i<1000)
					{
						while(PINA==2);
						if(PINA==1)
						{
							while(PINA==1);
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

