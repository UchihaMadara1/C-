#define _CRT_SECURE_NO_WARNINGS

//------------------------------------------------
#include<reg52.h>
#define uchar unsigned char
#define uint  unsigned int

//----------------����ӿ�------------------------
#define  K_IN  P1      //ָ����������˿�
#define  Star_Stop 1   //ָ����������˿�
#define  Time_ADD  2   //ָ����������˿�
#define  Time_SUB  4   //ָ����������˿�
#define  Turn_EW   8   //ָ����������˿�
#define  Turn_SN  16   //ָ����������˿�

sbit D_R = P3 ^ 0;
sbit D_Y = P3 ^ 1;
sbit D_G = P3 ^ 2;
//----------------�������------------------------
uchar Key_C;      //�¼�ֵ
uchar Key_L;      //�ϴμ�ֵ
uchar Trg;        //����(�м�����)triger
uchar Trg_L;      //�ϴδ���
uchar Key_P;      //ȷʵ����
uchar n_2ms, n_0D5s, D_SEC = 60;  //60ʵ������30��
uchar code D_seg[] = {            //��������
	0xc0, 0xf9, 0xa4, 0xb0, 0x99,
	0x92, 0x82, 0xf8, 0x80, 0x90 }; //0-9
bit  s_g, run, hong;
//----------------��ʱ----------------------------
void delay(uint z)
{
	uint x, y;
	for (x = z; x > 0; x--)  for (y = 123; y > 0; y--);
}
//----------------������--------------------------
void KeyRead(void)   //���������ڶ˿ڣ��͵�ȫ�ֱ���
{
	Key_L = Key_C;     //�ϴΰ�����ֵ
	Trg_L = Trg;
	Key_C = ~K_IN;     //������룬�м����£�������1
	Trg = Key_C & (Key_C ^ Key_L);
	Key_P = Key_C & Trg_L;  //ȷ�ϰ���
}
//----------------��ʼ��--------------------------
void init(void)
{
	TMOD = 0x01;       //T0��ʱ��ʽ1
	TH0 = (65536 - 2000) / 256; //2ms@12MHz
	TL0 = (65536 - 2000) % 256;
	TR0 = 1;           //����T0
	ET0 = 1;           //��T0�ж�
	EA = 1;            //�����ж�
	//---------------------
	D_Y = 0;           //�ص�
	D_R = hong;        //���ȡ���ڵ�ǰ��hong
	D_G = ~D_R;        //�̵����෴
	n_0D5s = D_SEC;    //����ʱ������(2������ֵ)
}
//----------------������--------------------------
void main(void)
{
	hong = 1;          //hong = 1: ����Ϊ���
	init();
	run = 1;           //����������
	while (1) {
		delay(8);        //��ʱ8ms
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
//----------------T0�жϺ���----------------------
void T0_INT(void) interrupt 1
{
	TL0 = (65536 - 2000) % 256; //����д���ֵ
	TH0 = (65536 - 2000) / 256; //2ms@12MHz
	//----------------������ʾ------------------------
	s_g = ~s_g;            //ʮλ��λ������ʾ
	if (s_g)  { P2 = 0; P0 = D_seg[(n_0D5s / 2) / 10]; P2 = 1; }
	else      { P2 = 0; P0 = D_seg[(n_0D5s / 2) % 10]; P2 = 2; }
	//----------------�޸�ʱ��------------------------
	n_2ms--;
	if (n_2ms % 5 == 0)  KeyRead();  //10ms��һ�ΰ���
	if (n_2ms == 0) {
		n_2ms = 250;         //��ʱ500ms
		if (run) {           //�������������
			n_0D5s--;          //�͵���ʱ
			if (n_0D5s == 1)  n_0D5s = D_SEC + 1;//����1�����¿�ʼ
			if (n_0D5s == D_SEC + 1)  {//��������¿�ʼ
				if (hong) {      //�����ǰ�Ǻ����
					hong = 0;      //����͸ĳ��̵���
					D_Y = 0;       //�رջƵ�
					D_G = 1;       //���̵�
					D_R = 0;       //�رպ��
				}
				else {           //����͸ĳɺ����
					hong = 1;
					D_Y = 0;       //�رջƵ�
					D_G = 0;       //�ر��̵�
					D_R = 1;       //�򿪺��
				}
			}
			if (n_0D5s <= 11)  {//��������5��
				D_Y = ~D_Y;      //�Ƶ���˸
				D_G = 0;         //�ر��̵�
				D_R = 0;         //�رպ��
			}
		}
	} }
//----------------�������------------------------
