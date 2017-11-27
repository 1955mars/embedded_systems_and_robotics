#include<avr/io.h>
#include<util/delay.h>
#include<string.h>
#include<mars/lcdd.h>//Includes the lcd display control functions on PORTC


char *s[]={"Smart_Bee","WF Bot","Bot_Communique","Back",};//Choosing Our Menu
int select(int,int);

//Here starts our main part
main()
{
	DDRD=0xF0;
	DDRB=0xFF;
	DDRC=0xFF;
	DDRA=0xFC;//PORTA is used for IR Sensors
	lcdstr();// Initializing the Lcd display(lcdstr,divcmd,divdata,disp_string,disp_number -->Funtions related)
	divcmd(0x01);//Clearing the previous data on the lcd screen
	int k=0,i,j=0;// k used for changing the text on lcd only when input(gesture) is given..
	PORTB=0;
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
			PORTB=3;
			while(PINA==3);
			PORTB=0;
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
				if(PINA==3)
				{
					PORTB=3;
					while(PINA==3);
					PORTB=0;
					_delay_ms(10);
					if(k==3)
					{
						k=j=0;
						break;
					}
					int e=0,s=0;
					DDRD=0xF0;
					int q=0,w=0;
					divcmd(0x01);
					disp_string("Password",0x80);
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
						disp_string("*",0x80+w);
						q=q*10+e;
						w++;
						
					}
					int u;
					u=select(k,q);
					_delay_ms(200);
					j++;
					if(u==0)
					{
						divcmd(0x01);
						disp_string("Incorrect",0x80);
						_delay_ms(500);
						j++;
	
					}
					}
								
				if(PINA==1)//For sliding the apps left wards
				{
					i=0;
					while(i<1000)// If takes more time to slide then not considering as a gesture
					{
						PORTB=1;
						while(PINA==1);
						PORTB=0;
						if(PINA==2)
						{
							PORTB=2;
							while(PINA==2);
							PORTB=0;
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
						PORTB=2;
						while(PINA==2);
						PORTB=0;
						if(PINA==1)
						{
							PORTB=1;
							while(PINA==1);
							PORTB=0;
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


int select(int k,int q)
{	
	disp_string("Slide ",0xc0);
	int i;
	while(1)
	{
	if(PINA==2)
	{
		i=0;
		while(i<1000)
		{
			while(PINA==2);
			PORTB=0;
			if(PINA==1)
			{
				PORTB=k;
				while(PINA==1);
				PORTB=0;
				for(int k=0;k<14;k++)
				{
					divcmd(0x1C);
					_delay_ms(60);
				}
				if(k==1)
				goto enter;
				if(k==2)
				goto communique;
			}
			i++;
			_delay_us(500);
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
				PORTB=k;
				while(PINA==2);
				PORTB=0;
				for(int k=0;k<14;k++)
				{
					divcmd(0x1A);
					_delay_ms(60);
				}
				if(k==1)
					goto enter;
				if(k==2)
					goto communique;
					
			}
			i++;
			_delay_us(500);
		}
	}
	}
	enter:
	if(q==1234)
	{	
		divcmd(0x01);
		disp_string("Robo_Activated",0x80);
		disp_string("Unplug wire",0xc0);
		while(1)
		{
			divcmd(0x1A);
			_delay_ms(400);
		}
	}
	else
	{
		return 0;
	}
	communique:
	if(q==1234)
	{
		divcmd(0x01);
		disp_string("Start_Commnctng",0x81);
		int e=0,s=0;
		s=PIND;
		int q=0,w=0;
		divcmd(0x01);
		while(1)
		{
			while(PIND==s)
			{
				if(PINA==1)//For sliding the apps left wards
			{
				i=0;
				while(i<1000)// If takes more time to slide then not considering as a gesture
				{
					while(PINA==1);
					if(PINA==2)
					{
						PORTB=q;
						while(PINA==2);
						PORTB=0;
						for(int k=0;k<14;k++)
						{
							divcmd(0x1A);
							_delay_ms(60);
						}
					
					}
					goto next;
					i++;
					_delay_us(500);
				}
			}
			}
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
	}
	next:
	divcmd(0x01);
	disp_string("HI",0x80);
	while(1)
	{
	}
}

