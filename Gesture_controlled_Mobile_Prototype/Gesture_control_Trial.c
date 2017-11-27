/* Project:- Controlling the Lcd display and other connected devices by gestures of our fingures using Micro controllers




*/

#include<avr/io.h>
#include<util/delay.h>
#include<string.h>
#include<mars/lcdd.h>//Includes the lcd display control functions on PORTC


char *s[]={"Menu","Organizer","Tools","Games","LDM Patterns","Media","Robot","Back"};//Choosing Our Menu
char *s1[]={"","Digital_Clock","Stop_Watch","LDM_Game","Start","Music"};//Inside app names
void select(int);

//DC functions min and hour

void min(int u)//Function used to display the min in DC
{

	
		divcmd(0xc7);
		divdata((u/10)+48);
		divdata((u%10)+48);
		divdata(':');

}

void hour(int j)//Function used to display hours in DC
{
	divcmd(0xc4);
	divdata((j/10)+48);
	divdata((j%10)+48);
	divdata(':');
}

//Game Functions
void gameover(void)//To display LOST characters on LED DOT MATRIX DISPLAY
{
	
		for(int i=0;i<50;i++)
		{
		PORTB=0x1E;
		PORTD=~0x80;
		_delay_ms(5);
	
	
		PORTB=0x10;
		PORTD=~0x40;
		_delay_ms(5);
		
		PORTB=0x10;
		PORTD=~0x20;
		_delay_ms(5);
		
		}
		for(int i=0;i<50;i++)
		{

		PORTB=0x1E;
		PORTD=~0x20;
		_delay_ms(5);

		PORTB=0x12;
		PORTD=~0x10;
		_delay_ms(5);

		PORTB=0x1E;
		PORTD=~0x08;
		_delay_ms(5);
		}
		for(int i=0;i<50;i++)
		{

		PORTB=0x16;
		PORTD=~0x08;
		_delay_ms(5);

		PORTB=0x16;
		PORTD=~0x04;
		_delay_ms(5);

		PORTB=0x1E;
		PORTD=~0x02;
		_delay_ms(5);
		}
		for(int i=0;i<50;i++)
		{
		PORTB=0x02;
		PORTD=~0x04;
		_delay_ms(5);
		PORTB=0x1E;
		PORTD=~2;
		_delay_ms(5);
		PORTB=0x02;
		PORTD=~1;
		_delay_ms(5);
		}
	
	
}


//Media Function
void sari(void)
{
OCR0=59;
_delay_ms(200);
OCR0=52;
_delay_ms(200);
OCR0=46;
_delay_ms(200);
OCR0=42;
_delay_ms(200);
OCR0=38;
_delay_ms(200);
OCR0=34;
_delay_ms(200);
OCR0=30;
_delay_ms(200);
OCR0=46;
_delay_ms(200);
}

//Timer Initialization function for media application
void timer_0_init(void)
{
	TCCR0=0b00011010;
	DDRB=0x08;
}


//Here starts our main part
main()
{
	DDRD=0xFF;//PORTD is used for the columns of the LED  DOT  MATRIX
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
					select(k);
					_delay_ms(200);
					j++;
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
	if(a==1)
	{
		divcmd(0x01);
		int s=28;
		int y=10;
		while(1)
		{	
			for(int i=0;i<=59;i++)
			{
				if(PINA==3)
				{
					while(PINA==3);
					_delay_ms(10);
					return;
				}
				int k;
				disp_string(s1[a],0x81);
				hour(y);
				min(s);
				divcmd(0xcA);
				k=i%10;
				divdata((i/10)+48);
				divdata(k+48);
				_delay_ms(1000);
			}
			s++;
			if(s>59)
			{
				s=0;
				y++;
			}
			if(y>23)
			{
				y=0;
			}
			
		}
	}

	if(a==3)
	{
		int x=1,y=128,t=200;
		PORTB=x;
		PORTD=~y;
		divcmd(0x01);
		disp_string("00 L 2 R",0x80);
		disp_string("01 T 2 B",0x88);
		disp_string("10 R 2 L",0xc0);
		disp_string("11 B 2 T",0xc8);
		_delay_ms(5000);
		while(1)
		{
			if(PINA==0)
			{	
				while(PINA==0)
				{
					y=y/2;
					PORTB=x;
					PORTD=~y;
					_delay_ms(t);
					if(y<1)
					{
						gameover();
						PORTD=0;
						PORTB=0;
						return;
					}
				}
			}
		
			if(PINA==1)
			{
				while(PINA==1)
				{
					x=x*2;
					PORTB=x;
					PORTD=~y;
					_delay_ms(t);
					if(x>128)
					{
						gameover();
						PORTD=0;
						PORTB=0;
						return;
					}
				}
			}
			if(PINA==2)
			{
				while(PINA==2)
				{
					y=y*2;
					PORTB=x;
					PORTD=~y;
					_delay_ms(t);
					if(y>128)
					{
						gameover();
						PORTD=0;
						PORTB=0;
						return;
					}
				}
			}
			if(PINA==3)
			{
				while(PINA==3)
				{
					x=x/2;
					PORTB=x;
					PORTD=~y;
					_delay_ms(t);
					if(x<1)
					{
						gameover();
						PORTD=0;
						PORTB=0;
						return;
					}
				}
			}
			

		}
	}

	if(a==4)
	{
		divcmd(0x01);
		disp_string("Touch 2 Stop",0x82);
		while(1)
		{
			int x=0x01,y=0x80,u=128,v=1,t=50;
			PORTB=x;
			for(int z=0;z<=3;z++)
			{
				if(PINA==3)
				{
					while(PINA==3);
					PORTB=0;
					PORTD=0;
					return;
				}
				while(y>=v)
				{
					PORTD=~y;
					_delay_ms(t);
					if(y!=v)
					{
						y>>=1;
					}
					else
						break;
				}
				if (z==0) x=x*2;
				while(x<=u)
				{
					PORTB=x;
					_delay_ms(t);
					if(x!=u)
						x<<=1;
					else
						break;
	
				}
				y=y*2;
				while(y<=u)
				{
					PORTD=~y;
					_delay_ms(t);
					if (y!=u)
						y<<=1;
					else
						break;
	
				}
				x=x/2;
				v=v*2;
				while(x>=v)
				{
					PORTB=x;
					_delay_ms(t);
					if(x!=v)
					x>>=1;
					else
						break;
				}
				y=y/2;
				x=x*2;
				u=u/2;	
			}
		}

	}

	if(a==5)
	{
		divcmd(0x01);
		timer_0_init();
		disp_string("Touch 2 Stop",0x81);
		while(1)
		{
			sari();
			if(PINA==3)
			{
				while(PINA==3);
				TCCR0=0;
				DDRB=0xFF;
				PORTB=0;
				return;
			}
		}

	}

	if(a==6)
	{
		divcmd(0x01);
		int p=0;
		while(1)
		{
		
			disp_string("Front-00",0x80);
			disp_string("Stop-11",0xc0);
			if(PINA==1)
			{
				PORTB=4;
			}
			if(PINA==2)
			{
				PORTB=1;
			}
			if(PINA==3)
			{
				PORTB=5;
			}
			if(PINA==0)
			{
				PORTB=10;
			}
		}
	}
}

