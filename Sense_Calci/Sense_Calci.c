#include<avr/io.h>
#include<util/delay.h>
#include<string.h>
#include<mars/lcd.h>
#include<mars/kp.h>
#include<math.h>
int ADC_read(int chn)
{
	ADMUX=chn|0x40;//(1<<REFSO)|(0<<REFS1)
	ADCSRA=0xd7;
	while((ADCSRA&0x10)==0);
	return ADC;

}

int s_keypad(void)
{
	int chn1=0,chn2=1,z,y,x;
	for(int i=0;i<70;i++)
	{	
		z=ADC_read(chn1);
		x=ADC_read(chn2);
		if(z>100&&z<190&&x<250)
		{
			y=1;
			disp_number(1,0xc0);
			_delay_ms(10);
		}

		if(z>190&&z<280&&x<250)
		{
			y=2;
			disp_number(2,0xc0);
			_delay_ms(10);
		}
		if(z>280&&z<370&&x<250)
		{
			y=3;
			disp_number(3,0xc0);
			_delay_ms(10);
		}
		if(z>370&&z<460&&x<250)
		{
			y=5;
			disp_number(4,0xc0);
			_delay_ms(10);
		}
		if(z>460&&z<550&&x<250)
		{
			y=6;
			disp_number(5,0xc0);
			_delay_ms(10);
		}
		if(z>550&&z<640&&x<250)
		{
			y=7;
			disp_number(6,0xc0);
			_delay_ms(10);
		}
		if(z>640&&z<730&&x<250)
		{
			y=9;
			disp_number(7,0xc0);
			_delay_ms(10);
		}
		if(z>730&&z<820&&x<250)
		{
			y=10;
			disp_number(8,0xc0);
			_delay_ms(10);
		}
		if(z>820&&z<910&&x<250)
		{
			y=11;
			disp_number(9,0xc0);
			_delay_ms(10);
		}
		if(z>910&&x<250)
		{
			y=14;
			disp_number(0,0xc0);
			_delay_ms(10);
		}
		if(x>250&&x<375)
		{
			y=4;
			disp_string("+",0xc0);
			_delay_ms(10);
		}
		if(x>375&&x<450)
		{
			y=8;
			disp_string("-",0xc0);
			_delay_ms(10);
		}
		if(x>450&&x<575)
		{
			y=12;
			disp_string("*",0xc0);
			_delay_ms(10);
		}
		if(x>575&&x<650)
		{
			y=16;
			disp_string("/",0xc0);
			_delay_ms(10);
		}
		if(x>650)
		{
			y=15;
			disp_string("=",0xc0);
			_delay_ms(10);
		}
		_delay_ms(10);

	}
	return y;
}

main()
{
	DDRD=0xFF;
	lcdstr();
	divcmd(0x01);
	while(1)
	{
		int q;
		q=calculator();
		if(q==1)
		{
			continue;
		}
		else
		{
			divcmd(0x01);
			disp_string("Thank You",0x82);
			_delay_ms(2000);
			break;
		}
	}
}


int password(void)
{
	DDRD=0xFF;
	DDRA=0xF0;
	PORTA=0x0F;
	DDRC=0xF0;
	lcdstr();
	divcmd(0x01);
	disp_string("Enter_Pass",0x80);
	int b=0,cal;
	char data[16]="";
	while(1)
	{	
		
		int k;
		if(b!=0)
		divcmd(0x01);
		b++;
		disp_string(data,0x80);
		k=keypad();
		if(k==1)
		{
			while(PINA==0x0E);
			divcmd(0x01);
			char no1[30]=". , - ? ! 1",no11[30]="";
			disp_string(no1,0xc0);
			int y=0,m=0;
			while (y<100)
			{
				if(PINA==0x0E)
				{
					while(PINA==0x0E);
					disp_string(data,0x80);
					divcmd(0x80+strlen(data));
					divdata(no1[m]);
					_delay_ms(30);
					y=0;
					m=m+2;
					if((m-1)>strlen(no1))m=0;
				}
				_delay_ms(10);
				y++;
			}
			m=m-2;
			no11[0]=no1[m];
			strcat(data,no11);
		}
		if(k==2)
		{
			while(PINA==0x0D);
			divcmd(0x01);
			char no1[30]="a b c A B C 2",*help="",no11[30]="";
			disp_string(no1,0xc0);
			int y=0,m=0;
			while (y<100)
			{
				if(PINA==0x0D)
				{
					while(PINA==0x0D);
					disp_string(data,0x80);
					divcmd(0x80+strlen(data));
					divdata(no1[m]);
					_delay_ms(30);
					y=0;
					m=m+2;
					if((m-1)>strlen(no1))m=0;
				}
				_delay_ms(10);
				y++;
			}
			m=m-2;
			no11[0]=no1[m];
			strcat(data,no11);
		}

		if(k==3)
		{
						while(PINA==0x0B);
						divcmd(0x01);
						char no1[30]="d e f D E F 3",*help="",no11[30]="";
						disp_string(no1,0xc0);
						int y=0,m=0;
						while (y<100)
						{
							if(PINA==0x0B)
							{
								while(PINA==0x0B);
								disp_string(data,0x80);
								divcmd(0x80+strlen(data));
								divdata(no1[m]);
								_delay_ms(30);
								y=0;
								m=m+2;
								if((m-1)>strlen(no1))m=0;
							}
							_delay_ms(10);
							y++;
						}
						m=m-2;
						no11[0]=no1[m];
						strcat(data,no11);
		}

		if(k==4)
		{
			while(PINA==0x07);
			divcmd(0x01);
			char dup[16]="",dup2[2];
			int s,z=strlen(data);
			data[z-1]='\0';
			disp_string(data,0x80);
			
		}
				

		if(k==5)
		{
						while(PINA==0x0E);
						divcmd(0x01);
						char no1[30]="g h i G H I 4",*help="",no11[30]="";
						disp_string(no1,0xc0);
						int y=0,m=0;
						while (y<100)
						{
							if(PINA==0x0E)
							{
								while(PINA==0x0E);
								disp_string(data,0x80);
								divcmd(0x80+strlen(data));
								divdata(no1[m]);
								_delay_ms(30);
								y=0;
								m=m+2;
								if((m-1)>strlen(no1))m=0;
							}
							_delay_ms(10);
							y++;
						}
						m=m-2;
						no11[0]=no1[m];
						strcat(data,no11);
		}
		if(k==6)
		{
						while(PINA==0x0D);
						divcmd(0x01);
						char no1[30]="j k l J K L 5",*help="",no11[30]="";
						disp_string(no1,0xc0);
						int y=0,m=0;
						while (y<100)
						{
							if(PINA==0x0D)
							{
								while(PINA==0x0D);
								disp_string(data,0x80);
								divcmd(0x80+strlen(data));
								divdata(no1[m]);
								_delay_ms(30);
								y=0;
								m=m+2;
								if((m-1)>strlen(no1))m=0;
							}
							_delay_ms(10);
							y++;
						}
						m=m-2;
						no11[0]=no1[m];
						strcat(data,no11);
		}
		if(k==7)
		{
						while(PINA==0x0B);
						divcmd(0x01);
						char no1[30]="m n o M N O 6",*help="",no11[30]="";
						disp_string(no1,0xc0);
						int y=0,m=0;
						while (y<100)
						{
							if(PINA==0x0B)
							{
								while(PINA==0x0B);
								disp_string(data,0x80);
								divcmd(0x80+strlen(data));
								divdata(no1[m]);
								_delay_ms(30);
								y=0;
								m=m+2;
								if((m-1)>strlen(no1))m=0;
							}
							_delay_ms(10);
							y++;
						}
						m=m-2;
						no11[0]=no1[m];
						strcat(data,no11);
		}
		
		if(k==8)
		{
			if(strcmp(data,"ma")==0)
			{
				divcmd(0x01);
				disp_string("Calculator ON",0x83);
				_delay_ms(1000);
				cal=calculator();
				return cal;
			}
			else
			{
				divcmd(0x01);
				disp_string("Incorrect",0x84);
				_delay_ms(1000);
				data[0]='\0';
				divcmd(0x01);
				disp_string("Enter_Pass",0x80);
				b=0;	
				continue;
			}
		}


		if(k==9)
		{
						while(PINA==0x0E);
						divcmd(0x01);
						char no1[30]="p q r s P Q R S 7",*help="",no11[30]="";
						disp_string(no1,0xc0);
						int y=0,m=0;
						while (y<100)
						{
							if(PINA==0x0E)
							{
								while(PINA==0x0E);
								disp_string(data,0x80);
								divcmd(0x80+strlen(data));
								divdata(no1[m]);
								_delay_ms(30);
								y=0;
								m=m+2;
								if((m-1)>strlen(no1))m=0;
							}
							_delay_ms(10);
							y++;
						}
						m=m-2;
						no11[0]=no1[m];
						strcat(data,no11);
		}


		if(k==10)
		{
						while(PINA==0x0D);
						divcmd(0x01);
						char no1[30]="t u v T U V 8",*help="",no11[30]="";
						disp_string(no1,0xc0);
						int y=0,m=0;
						while (y<100)
						{
							if(PINA==0x0D)
							{
								while(PINA==0x0D);
								disp_string(data,0x80);
								divcmd(0x80+strlen(data));
								divdata(no1[m]);
								_delay_ms(30);
								y=0;
								m=m+2;
								if((m-1)>strlen(no1))m=0;
							}
							_delay_ms(10);
							y++;
						}
						m=m-2;
						no11[0]=no1[m];
						strcat(data,no11);
		}

		if(k==11)
		{
						while(PINA==0x0B);
						divcmd(0x01);
						char no1[30]="w x y z W X Y Z 9",*help="",no11[30]="";
						disp_string(no1,0xc0);
						int y=0,m=0;
						while (y<100)
						{
							if(PINA==0x0B)
							{
								while(PINA==0x0B);
								disp_string(data,0x80);
								divcmd(0x80+strlen(data));
								divdata(no1[m]);
								_delay_ms(30);
								y=0;
								m=m+2;
								if((m-1)>strlen(no1))m=0;
							}
							_delay_ms(10);
							y++;
						}
						m=m-2;
						no11[0]=no1[m];
						strcat(data,no11);
		}

		if(k==13)
		{
						while(PINA==0x0E);
						divcmd(0x01);
						char no1[30]="*",*help="",no11[30]="";
						disp_string(no1,0xc0);
						int y=0,m=0;
						while (y<100)
						{
							if(PINA==0x0E)
							{
								while(PINA==0x0E);
								disp_string(data,0x80);
								divcmd(0x80+strlen(data));
								divdata(no1[m]);
								_delay_ms(30);
								y=0;
								m=m+2;
								if((m-1)>strlen(no1))m=0;
							}
							_delay_ms(10);
							y++;
						}
						m=m-2;
						no11[0]=no1[m];
						strcat(data,no11);
		}
		
		if(k==14)
		{
						while(PINA==0x0D);
						divcmd(0x01);
						char no1[30]="0",*help="",no11[30]="";
						disp_string(no1,0xc0);
						int y=0,m=0;
						while (y<100)
						{
							if(PINA==0x0D)
							{
								while(PINA==0x0D);
								disp_string(data,0x80);
								divcmd(0x80+strlen(data));
								divdata(no1[m]);
								_delay_ms(30);
								y=0;
								m=m+2;
								if((m-1)>strlen(no1))m=0;
							}
							_delay_ms(10);
							y++;
						}
						m=m-2;
						no11[0]=no1[m];
						strcat(data,no11);
		}

		if(k==15)
		{
						while(PINA==0x0B);
						divcmd(0x01);
						char no1[30]="#",*help="",no11[30]="";
						disp_string(no1,0xc0);
						int y=0,m=0;
						while (y<100)
						{
							if(PINA==0x0B)
							{
								while(PINA==0x0B);
								disp_string(data,0x80);
								divcmd(0x80+strlen(data));
								divdata(no1[m]);
								_delay_ms(30);
								y=0;
								m=m+2;
								if((m-1)>strlen(no1))m=0;
							}
							_delay_ms(10);
							y++;
						}
						m=m-2;
						no11[0]=no1[m];
						strcat(data,no11);
		}

	}

}


int calculator(void)
{
	int k,x=0,y=0,z=0,u=0,v=0;
	divcmd(0x01);
	disp_number(x,0xcF);
	while(1)
	{
		k=s_keypad();
		if(k==1)
		{
			while(PINA==0x0E);
			x=(x*10)+1;
			disp_number(x,0xcF);
		}
		if(k==2)
		{
			while(PINA==0x0D);
			x=(x*10)+2;
			disp_number(x,0xcF);
		}
		if(k==3)
		{
			while(PINA==0x0B);
			x=(x*10)+3;
			disp_number(x,0xcF);
		}
		if(k==4)
		{
			while(PINA==0x07);
			divcmd(0x01);
			if(x==0&&y==0)
				y=u;
			else
				y=x;
			disp_number(u,0x8F);
			disp_number(y,0xc7);
			disp_string("+",0x80);
			x=0;
			z=1;
		}
		if(k==5)
		{
			while(PINA==0x0E);
			x=(x*10)+4;
			disp_number(x,0xcF);
		}
		if(k==6)
		{
			while(PINA==0x0D);
			x=(x*10)+5;
			disp_number(x,0xcF);
		}
		if(k==7)
		{
			while(PINA==0x0B);
			x=(x*10)+6;
			disp_number(x,0xcF);
		}
		if(k==8)
		{
			while(PINA==0x07);
			divcmd(0x01);
			if(x==0&&y==0)
				y=u;
			else
				y=x;
			disp_number(u,0x8F);
			disp_number(y,0xc7);
			disp_string("-",0x80);
			x=0;
			z=2;
		}
		if(k==9)
		{
			while(PINA==0x0E);
			x=(x*10)+7;
			disp_number(x,0xcF);
		}
		if(k==10)
		{
			while(PINA==0x0D);
			x=(x*10)+8;
			disp_number(x,0xcF);
		}
		if(k==11)
		{
			while(PINA==0x0B);
			x=(x*10)+9;
			disp_number(x,0xcF);
		}
		if(k==12)
		{
			while(PINA==0x07);
			divcmd(0x01);
			if(x==0&&y==0)
				y=u;
			else
				y=x;
			disp_number(u,0x8F);
			disp_number(y,0xc7);
			disp_string("x",0x80);
			x=0;
			z=3;
		}
		if(k==14)
		{
			while(PINA==0x0D);
			x=(x*10)+0;
			disp_number(x,0xcF);
		}
		if(k==15)
		{
			while(PINA==0x0B);
			divcmd(0x01);
			if(z==1)
			{
				disp_number(x+y,0x8F); 
				u=x+y;
				x=0;
				y=0;
			}
			if(z==2)
			{
				disp_number(x-y,0x8F);
				u=x-y;
				x=0;
				y=0;
			}
			if(z==3)
			{
				disp_number(x*y,0x8F);
				u=x*y;
				x=0;
				y=0;
				
			}
			if(z==4)
			{
				disp_number(x/y,0x8F);
				u=x/y;
				x=0;
				y=0;
			}
		}
		if(k==16)
		{
			while(PINA==0x07);
			divcmd(0x01);
			if(x==0&&y==0)
				y=u;
			else
				y=x;
			disp_number(u,0x8F);
			disp_number(y,0xc7);
			disp_string("/",0x80);
			x=0;
			z=4;
		}

		
	}
}


		
	
