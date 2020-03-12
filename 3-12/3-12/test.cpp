#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//int _divisor(int a,int b)//辗转相除法求最大公因数
//{
//	if (a * b <= 0)
//		return -1;
//	int tmp;
//	if (a < b)
//	{
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	while (b)
//	{
//		tmp = a%b;
//		a = b;
//		b = tmp;
//	}
//	return a;
//}
//int _Gcd(int a,int b)//辗转相除法的递归形式
//{
//	if (a % b == 0)
//		return b;
//	return (b,a%b);
//}
//int _multiple(int a,int b)//求最小公倍数
//{
//	if (a * b <= 0)
//		return -1;
//	//int mid = _divisor(a, b);
//	int mid = _Gcd(a,b);
//	return (a * b) / mid;
//}
int _divisor(int num1,int num2)
{
	if (num1 * num2 <= 0)
		return -1;
	int tmp = num1 > num2 ? num2 : num1;
	while (1)
	{
		if (num1 % tmp == 0 && num2 % tmp == 0)
			return tmp;
		else if (tmp > 0)//两个数均为正数
			tmp--;
		else//两个数均为负数
		{
			tmp++;
		}
	}
}
int _multiple(int num1,int num2)
{
	if (num1 * num2 <= 0)
		return -1;
	int tmp = num1 > num2 ? num1 : num2;//两个数均为正数
	while (1)
	{
		if (tmp % num1 == 0 && tmp % num2 == 0)
			break;
		else
			tmp += tmp;
	}
	return tmp;
}
int main()
{
	int ret = _multiple(12,8);
	cout << ret << endl;
	return 0;
}
