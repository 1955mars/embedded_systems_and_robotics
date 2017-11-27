#include<avr/io.h>
#include<util/delay.h>
#include<string.h>
#include<mars/lcd.h>
main()
{
	DDRD=0xFF;
	DDRA=0xF0;
	PORTA=0x0F;
	DDRC=0xF0;
	lcdstr();
	divcmd(0x01);
	disp_string("Type Text",0x80);
	char data[16]="";
	comebaby:
	while(1)
	{
		int sw=0;
		disp_string("sel ur rows   ",0xc0);
		PORTC=0xE0;
		while(1)
		{
			if(PINA==0x0E)
			{
				while(PINA==0x0E);
				PORTC=0xE0;
				disp_string("1",0xcc);
				_delay_ms(100);
				sw=1;
				break;
			}
			else if(PINA==0x0D)
			{
				while(PINA==0x0D);
				PORTC=0xD0;
				disp_string("2",0xcc);
				_delay_ms(100);
				sw=2;
				break;
			}
			else if(PINA==0x0B)
			{
				while(PINA==0x0B);
				PORTC=0xB0;
				disp_string("3",0xcc);
				_delay_ms(100);
				sw=3;
				break;
			}
			else if(PINA==7)
			{
				while(PINA==7);
				PORTC=0x70;
				disp_string("4",0xcc);
				_delay_ms(100);
				sw=4;
				break;
			}
		}
		int b=0;
		switch(sw)
		{
			case (1):
			{
				if(b==0)
				{
					divcmd(0x01);
					b++;
				}
				else
				{
					disp_string(data,0x80);
				}
				while(1)
				{
					disp_string("1  2  3  <---",0xc0);
					if(strlen(data)==0)
					{
						disp_string("Type_",0x80);
					}
					else
					{
						disp_string(data,0x80);
					}
					if(PINA==0x0E)
					{
						while(PINA==0x0E);
						divcmd(0x01);
						char no1[30]=". , - ? ! 1",*help="",no11[30]="";
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
					if(PINA==0x0D)
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
					if(PINA==0x0B)
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
					if(PINA==7)
					{
						while(PINA==7);
						goto comebaby;
					}

				}
			}


			case (2):
			{
				if(b==0)
				{
					divcmd(0x01);
					b++;
				}
				else
				{
					disp_string(data,0x80);
				}
				while(1)
				{
					disp_string("4  5  6  <---",0xc0);
					if(strlen(data)==0)
					{
						disp_string("Type_",0x80);
					}
					else
					{
						disp_string(data,0x80);
					}
					if(PINA==0x0E)
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
					if(PINA==0x0D)
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
					if(PINA==0x0B)
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
					if(PINA==7)
					{
						while(PINA==7);
						goto comebaby;
					}

				}
			}
			case (3):
			{
				if(b==0)
				{
					divcmd(0x01);
					b++;
				}
				else
				{
					disp_string(data,0x80);
				}
				while(1)
				{
					divcmd(0x01);
					disp_string("7 8 9 <---",0xc0);
					if(strlen(data)==0)
					{
						disp_string("Type_",0x80);
					}
					else
					{
						disp_string(data,0x80);
					}
					if(PINA==0x0E)
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
					if(PINA==0x0D)
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
					if(PINA==0x0B)
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
					if(PINA==7)
					{
						while(PINA==7);
						goto comebaby;
					}

				}
			}
			case (4):
			{
				if(b==0)
				{
					divcmd(0x01);
					b++;
				}
				else
				{
					disp_string(data,0x80);
				}
				while(1)
				{
					disp_string("4  5  6  <---",0xc0);
					if(strlen(data)==0)
					{
						disp_string("Type_",0x80);
					}
					else
					{
						disp_string(data,0x80);
					}
					if(PINA==0x0E)
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
					if(PINA==0x0D)
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
					if(PINA==0x0B)
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
					if(PINA==7)
					{
						while(PINA==7);
						goto comebaby;
					}

				}
			}

		}
	}
}	




