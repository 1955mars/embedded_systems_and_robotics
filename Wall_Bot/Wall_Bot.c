#include<avr/io.h>
#include<util/delay.h>
#include<string.h>
#include<mars/lcdd.h>//Includes the lcd display control functions on PORTC


char *s[]={"Smart_Bee","WF Bot","Math Bot","Back",};//Choosing Our Menu
//Inside app names
void select(int);

//Here starts our main part
main()
{
	DDRD=0;
	DDRB=0xFF;
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
				/*if(PIND==3)
				{
					while(PIND==3);
					if(k==3)
					{
						k=j=0;
						break;
					}
					while(PIND==0);
					int s;
					s=PIND;
					while(PIND==s);
					select(s);

				}
				*/		
						
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
	if(a==1)
	{
		while(PORTB=0xFF);
		{
			DDRB=0xFF;
			DDRA=0xFC;
			DDRC=0xFF;
			lcdstr();
			clear();
			PORTB=10;
			int rot=0,area[10],z=0,dist=0,total,h=0,f3=0;
			for(int i ;i<10;i++)
			{	area[i]=0;	}
			while(1)
			{
			if(PINA==1)
			{
				while(PINA==1);
				rot++;
				f3++;
				total=rot;
				dist=rot;
				divcmd(0x01);
				disp_string("Dist",0x80);
				disp_number(total,0x8f);
				if(h>0)
				{
					disp_number(h,0x8B);
				}
				for(int j=0,h=4;j<=z;j++)
				{
					disp_number(area[j],0xc0+h);
					h+=2;
				}
				if(total>=100)
				{
					total=0;
					rot=0;
					h++;
				}
				if(f3==3)
				{
					rot++;
					f3=0;
				}
		
			}
			if(PINA==2||PINA==3)
			{
				PORTB=6;
				DDRA=0xFE;
				int k=0;
				while(PINA==1);
				while(k<=7)
				{
					if(PINA==1)
					{
						while(PINA==1);
						k=k+1;
					}
				}
				DDRA=0xFC;
				PORTB=10;
			}
			
		}

	}
	
	if(a==2)
	{
		int q=0;
		while(1)
		{
			if(PIND!=0)
			{
				q=PIND;
				while(PIND!=0);
			divcmd(0x01);
			disp_number(q,0x80);
			}
		}
	}
}

}
