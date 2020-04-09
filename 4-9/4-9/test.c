#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
union
{
	char c;
	int i;
}u,*ptr;
int main()
{
	int sz = sizeof(u);
	ptr = &u;
	u.i = 1;
	if (u.c == 1)
	{
		printf("Ð¡¶Ë\n");
	}
	else
	{
		printf("´ó¶Ë\n");
	}
	return 0;
}
//typedef struct Data
//{
//	int a;
//	int b;
//	int c;
//}Data;
//int main()
//{
//	Data data;
//	Data *ptr = &data;
//	data.a = 400;
//	data.b = 500;
//	data.c = 600;
//	return 0;
//}