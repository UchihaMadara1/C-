#define _CRT_SECURE_NO_WARNINGS

//------------------------------------------------
#include<reg52.h>
#define uchar unsigned char
#define uint  unsigned int

//----------------定义接口------------------------
#define  K_IN  P1      //指定按键输入端口
#define  Star_Stop 1   //指定按键输入端口
#define  Time_ADD  2   //指定按键输入端口
#define  Time_SUB  4   //指定按键输入端口
#define  Turn_EW   8   //指定按键输入端口
#define  Turn_SN  16   //指定按键输入端口

sbit D_R = P3 ^ 0;
sbit D_Y = P3 ^ 1;
sbit D_G = P3 ^ 2;
//----------------定义变量------------------------
uchar Key_C;      //新键值
uchar Key_L;      //上次键值
uchar Trg;        //触发(有键按下)triger
uchar Trg_L;      //上次触发
uchar Key_P;      //确实按下
uchar n_2ms, n_0D5s, D_SEC = 60;  //60实际上是30秒
uchar code D_seg[] = {            //共阳段码
	0xc0, 0xf9, 0xa4, 0xb0, 0x99,
	0x92, 0x82, 0xf8, 0x80, 0x90 }; //0-9
bit  s_g, run, hong;
//----------------延时----------------------------
void delay(uint z)
{
	uint x, y;
	for (x = z; x > 0; x--)  for (y = 123; y > 0; y--);
}
//----------------读按键--------------------------
void KeyRead(void)   //读按键所在端口，送到全局变量
{
	Key_L = Key_C;     //上次按键数值
	Trg_L = Trg;
	Key_C = ~K_IN;     //反相读入，有键按下，将读入1
	Trg = Key_C & (Key_C ^ Key_L);
	Key_P = Key_C & Trg_L;  //确认按下
}
//----------------初始化--------------------------
void init(void)
{
	TMOD = 0x01;       //T0定时方式1
	TH0 = (65536 - 2000) / 256; //2ms@12MHz
	TL0 = (65536 - 2000) % 256;
	TR0 = 1;           //启动T0
	ET0 = 1;           //开T0中断
	EA = 1;            //开总中断
	//---------------------
	D_Y = 0;           //关灯
	D_R = hong;        //红灯取决于当前的hong
	D_G = ~D_R;        //绿灯则相反
	n_0D5s = D_SEC;    //倒计时的秒数(2倍的数值)
}
//----------------主函数--------------------------
void main(void)
{
	hong = 1;          //hong = 1: 东西为红灯
	init();
	run = 1;           //开机即运行
	while (1) {
		delay(8);        //延时8ms
		if (Star_Stop & Key_P) {
			run = ~run;
			if (!run)  init();
		}
		if (Time_ADD & Key_P && !run) {
			D_SEC += 2;
			if (D_SEC > 120)  D_SEC = 120;
			n_0D5s = D_SEC;
		}
		if (Time_SUB & Key_P && !run) {
			D_SEC -= 2;
			if (D_SEC < 20)  D_SEC = 20;
			n_0D5s = D_SEC;
		}
		if (Turn_EW & Key_P && run && hong)   n_0D5s = 11;
		if (Turn_SN & Key_P && run && !hong)  n_0D5s = 11;
	}
}
//----------------T0中断函数----------------------
void T0_INT(void) interrupt 1
{
	TL0 = (65536 - 2000) % 256; //重新写入初值
	TH0 = (65536 - 2000) / 256; //2ms@12MHz
	//----------------数码显示------------------------
	s_g = ~s_g;            //十位个位交替显示
	if (s_g)  { P2 = 0; P0 = D_seg[(n_0D5s / 2) / 10]; P2 = 1; }
	else      { P2 = 0; P0 = D_seg[(n_0D5s / 2) % 10]; P2 = 2; }
	//----------------修改时间------------------------
	n_2ms--;
	if (n_2ms % 5 == 0)  KeyRead();  //10ms读一次按键
	if (n_2ms == 0) {
		n_2ms = 250;         //定时500ms
		if (run) {           //如果是正在运行
			n_0D5s--;          //就倒计时
			if (n_0D5s == 1)  n_0D5s = D_SEC + 1;//减到1就重新开始
			if (n_0D5s == D_SEC + 1)  {//如果是重新开始
				if (hong) {      //如果当前是红灯亮
					hong = 0;      //下面就改成绿灯亮
					D_Y = 0;       //关闭黄灯
					D_G = 1;       //打开绿灯
					D_R = 0;       //关闭红灯
				}
				else {           //否则就改成红灯亮
					hong = 1;
					D_Y = 0;       //关闭黄灯
					D_G = 0;       //关闭绿灯
					D_R = 1;       //打开红灯
				}
			}
			if (n_0D5s <= 11)  {//如果是最后5秒
				D_Y = ~D_Y;      //黄灯闪烁
				D_G = 0;         //关闭绿灯
				D_R = 0;         //关闭红灯
			}
		}
	} }
//----------------程序结束------------------------
