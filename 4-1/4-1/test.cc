#define _CRT_SECURE_NO_WARNINGS
class Solution {
public:
	int Add(int num1, int num2)
	{
		int a, b;
		while (num1&num2)
		{
			a = num1;
			b = num2;
			num1 = a ^ b;
			num2 = (unsigned int)(a & b) << 1;
		}
		return num1^num2;
	}
};

//
#include<iostream>
using namespace std;
int main()
{
	double a, b, c;
	while (cin >> a >> b >> c)
	{
		if (a + b > c&&a + c > b&&b + c > a)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
