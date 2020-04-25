#define _CRT_SECURE_NO_WARNINGS

//#include<reg52.h> 
#include "reg52.h"
#define uchar unsigned char 
#define uint unsigned int

//0-F共阳极
code uchar table[] = { 0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e };
uchar num = 0, ii = 0, jj = 0;
/*------------------------------------------------
 延时z ms函数
 --------------------------------------------------*/
void delay(uint z)    //延时函数  z ms
{
	uint x, y;  
	for (x = z; x>0; x--)    
		for (y = 110; y>0; y--);
}
//主数码管显示
void display_zhu(uint y)   //显示部分
{
	uint shi = y / 10;
	uint ge = y % 10; 
	delay(1);           
	P1 = 0x01;
	P0 = table[shi];
	delay(1);
	P1 = 0x02;
	P0 = table[ge];
	delay(1);
	P0 = 0xff;
}
//从数码管显示
void display_cong(uint y)//显示部分
{
	uint shi = y / 10;
	uint ge = y % 10;
	delay(1);
	P1 = 0x04;
	P0 = table[shi];
	delay(1);
	P1 = 0x08;
	P0 = table[ge];
	delay(1);
	P0 = 0xff;
}
/*------------------------------
          中断初始化
---------------------------------*/
void T_initial()
{
	TMOD = 0x10; //定时器1工作方式为1
	TH1 = (65535 - 46080) / 256;//定时50ms N=19456---11.0592MHZ
	TL1 = (65535 - 46080) % 256;
	EA = 1; //开总中断允许；
	ET1 = 1;//定时器1中断允许
}
/*-------------------------------
主函数
----------------------------------*/
void main()
{
	P0 = 0Xff;
	P2 = 0xff;
	P1 = 0;
	T_initial();
	TR1 = 1; //计时开始
	while (1)  //主干道停，支干道行
	{
		uchar i;
		ii = 20;
		P2 = 0x53;
		if (ii)
		{
			while (ii > 5)
			{
				display_zhu(ii);
				display_cong(ii - 2);
			}
			/*while (2 < ii&ii <= 5)
			{
				P2 = 0x53;
				for (i = 100; i > 0; --i)
				{
					display_zhu(ii);
					display_cong(ii - 2);
				}
				P2 = 0x73;
				for (i = 80; i > 0; --i)
				{
					display_zhu(ii);
					display_cong(ii - 2);
				}
			}*/

			while (0 < ii&ii <= 5)
			{
				P2 = 0x63;
				for (i = 100; i > 0; --i)
				{
					display_zhu(ii);
					display_cong(ii);
				}
				//display_zhu(ii);
				//display_cong(ii - 2);
			}
			if (ii == 0)
			{
				P2 = 0x63;
				for (i = 150; i > 0; --i)
				{
					display_zhu(0);
					display_cong(0);
				}
			}
		}
		jj = 25; //主干道行，支干道停
		P2 = 0x35;
		if (jj)
		{
			display_zhu(jj);
			while (jj > 5)
			{
				display_zhu(jj);
				display_cong(jj - 2);
			}
			/*while (2 < jj&jj <= 5)
			{
				P2 = 0x35;
				for (i = 100; i > 0; --i)
				{
					display_zhu(jj);
					display_cong(jj - 2);
				}
				P2 = 0x37;
				for (i = 80; i > 0; --i)
				{
					display_zhu(jj);
					display_cong(jj - 2);
				}
			}*/
			while (0 < jj&jj <= 5)
			{
				P2 = 0x36;
				for (i = 100; i > 0; --i) 
				{
					display_zhu(jj);
					display_cong(jj);
				}
				//display_zhu(jj);
				//display_cong(jj);
			}
			if (jj == 0)
			{
				P2 = 0x36;
				for (i = 150; i > 0; --i)
				{
					display_zhu(0);
					display_cong(0);
				}
			}
		}
	}
}
/*-------------------------------
        定时器中断-1s 计时子函数
----------------------------------*/
void T1_time()interrupt 3 //定时器1中断程序
{
	TH1 = (65535 - 46080) / 256;
	TL1 = (65535 - 46080) % 256;
	num++;
	if (num == 20) //定时到1s
	{
		num = 0;
		ii--;
		jj--;
	}
}