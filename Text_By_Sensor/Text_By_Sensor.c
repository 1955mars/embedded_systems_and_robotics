#include<avr/io.h>
#include<util/delay.h>
#include<mars/lcdd.h>
#include<string.h>
main()
{
	DDRC=0xFF;
	lcdstr();
	divcmd(0x01);
	char data[16]="";
	int b=0;
	int k=1;
while(1)
{
	if(b!=0)
	b++;
	disp_string(data,0x80);
	if(PINA==2)
	{	
		while(PINA==2);
		k++;
	}
	if(k>15)
		k=1;

	if(k==1)
		{
			char no1[30]=". , - ? ! 1",no11[30]="";
			disp_string(data,0x80);
			disp_string(no1,0xc0);
			int y=0,m=0;
			if(PINA==1)
			{	while(PINA==1);
			while (y<100)
			{
				if(PINA==1)
				{
					while(PINA==1);
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
		if(k==2)
		{
			disp_string(data,0x80);
			char no1[30]="a b c A B C 2",*help="",no11[30]="";
			disp_string(no1,0xc0);
			int y=0,m=0;
			if(PINA==1)
			{	while(PINA==1);
			while (y<100)
			{
				if(PINA==1)
				{
					while(PINA==1);
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

		if(k==3)
		{
						disp_string(data,0x80);
						char no1[30]="d e f D E F 3",*help="",no11[30]="";
						disp_string(no1,0xc0);
						int y=0,m=0;
						if(PINA==1)
						{	while(PINA==1);
						while (y<100)
						{
							if(PINA==1)
							{
								while(PINA==1);
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

		if(k==4)
		{
			continue;
			divcmd(0x01);
			char dup[16]="",dup2[2];
			int s,z=strlen(data);
			data[z-1]='\0';
			disp_string(data,0x80);
			
		}
				

		if(k==5)
		{
						disp_string(data,0x80);
						char no1[30]="g h i G H I 4",*help="",no11[30]="";
						disp_string(no1,0xc0);
						int y=0,m=0;
						if(PINA==1)
						{	while(PINA==1);
						while (y<100)
						{
							if(PINA==1)
							{
								while(PINA==1);
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
		if(k==6)
		{
						disp_string(data,0x80);
						char no1[30]="j k l J K L 5",*help="",no11[30]="";
						disp_string(no1,0xc0);
						int y=0,m=0;
						if(PINA==1)
						{	while(PINA==1);
						while (y<100)
						{
							if(PINA==1)
							{
								while(PINA==1);
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
		if(k==7)
		{
						
						disp_string(data,0x80);
						char no1[30]="m n o M N O 6",*help="",no11[30]="";
						disp_string(no1,0xc0);
						int y=0,m=0;
						if(PINA==1)
						{	while(PINA==1);
						while (y<100)
						{
							if(PINA==1)
							{
								while(PINA==1);
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
		
		if(k==8)
		{
			continue;
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
						
						disp_string(data,0x80);
						char no1[30]="p q r s P Q R S 7",*help="",no11[30]="";
						disp_string(no1,0xc0);
						int y=0,m=0;
						if(PINA==1)
						{	while(PINA==1);
						while (y<100)
						{
							if(PINA==1)
							{
								while(PINA==1);
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


		if(k==10)
		{
						
						disp_string(data,0x80);
						char no1[30]="t u v T U V 8",*help="",no11[30]="";
						disp_string(no1,0xc0);
						int y=0,m=0;
						while (y<100)
						{
							if(PINA==1)
							{
								while(PINA==1);
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
						
						disp_string(data,0x80);
						char no1[30]="w x y z W X Y Z 9",*help="",no11[30]="";
						disp_string(no1,0xc0);
						int y=0,m=0;
						while (y<100)
						{
							if(PINA==1)
							{
								while(PINA==1);
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
						
						disp_string(data,0x80);
						char no1[30]="*",*help="",no11[30]="";
						disp_string(no1,0xc0);
						int y=0,m=0;
						while (y<100)
						{
							if(PINA==1)
							{
								while(PINA==1);
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
	
						
						disp_string(data,0x80);
						char no1[30]="0",*help="",no11[30]="";
						disp_string(no1,0xc0);
						int y=0,m=0;
						while (y<100)
						{
							if(PINA==1)
							{
								while(PINA==1);
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
						
						disp_string(data,0x80);
						char no1[30]="#",*help="",no11[30]="";
						disp_string(no1,0xc0);
						int y=0,m=0;
						while (y<100)
						{
							if(PINA==1)
							{
								while(PINA==1);
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
