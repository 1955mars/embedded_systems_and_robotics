#include<avr/io.h>
#include<util/delay.h>
#include<string.h>
#include<mars/lcd.h>
int keypad(void)
{
	while(1)
	{
		PORTC=0xE0;
		_delay_ms(10);
		{
			if(PINA==0x0E){ while(PINA==0x0E);return 1;}
			if(PINA==0x0D){ while(PINA==0x0D);return 2;}
			if(PINA==0x0B){ while(PINA==0x0B);return 3;}
			if(PINA==0x07){ while(PINA==0x07);return 4;}
	
		}

		PORTC=0xD0;
		_delay_ms(10);
		{
			if(PINA==0x0E){ while(PINA==0x0E);return 5;}
			if(PINA==0x0D){ while(PINA==0x0D);return 6;}
			if(PINA==0x0B){ while(PINA==0x0B);return 7;}
			if(PINA==0x07){ while(PINA==0x07);return 8;}
		}

		PORTC=0xB0;
		_delay_ms(10);
		{
			if(PINA==0x0E){ while(PINA==0x0E);return 9;}
			if(PINA==0x0D){ while(PINA==0x0D);return 10;}
			if(PINA==0x0B){ while(PINA==0x0B);return 11;}
			if(PINA==0x07){ while(PINA==0x07);return 12;}
	
		}

		PORTC=0x70;
		_delay_ms(10);
		{
			if(PINA==0x0E){ while(PINA==0x0E);return 13;}
			if(PINA==0x0D){ while(PINA==0x0D);return 14;}
			if(PINA==0x0B){ while(PINA==0x0B);return 15;}
			if(PINA==0x07){ while(PINA==0x07);return 16;}
		}
	}
}



main()
{
	DDRD=0xFF;
	DDRA=0xF0;
	PORTA=0x0F;
	DDRC=0xF0;
	lcdstr();
	divcmd(0x01);
	disp_string("Enter_Pass",0x80);
	int b=0;
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
			if(strcmp(data,"Pass123")==0)
			{
				divcmd(0x01);
				disp_string("Correct",0x84);
				_delay_ms(1000);
				data[0]='\0';
				divcmd(0x01);
				disp_string("Enter_Pass",0x80);
				b=0;	
				continue;
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
