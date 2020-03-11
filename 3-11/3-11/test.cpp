#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//class Test
//{
//public:
//	int a;
//	int b;
//	virtual void fun()
//	{}
//	Test(int i = 0,int j = 0)
//	{
//		a = i;
//		b = j;
//	}
//	int getA()
//	{
//		return a;
//	}
//	int getB()
//	{
//		return b;
//	}
//};
//int main()
//{
//	Test obj(5,10);
//	//change A and B;
//	int* pint = (int *)&obj;
//	*(pint + 0) = 100;
//	pint++;
//	*(pint) = 200;
//	cout << "a = " << obj.getA() << endl;
//	cout << "b = " << obj.getB() << endl;
//	return 0;
//}
size_t chequer(int m, int n)
{
	if (m == 1)
		return n + 1;
	if (n == 1)
		return m + 1;
	return chequer(m - 1,n) + chequer(m,n - 1);
}
int main()
{
	int ret = chequer(2, 2);
	cout << ret << endl;
}