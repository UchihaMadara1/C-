#define _CRT_SECURE_NO_WARNINGS
//oj快到碗里来
#include<iostream>
#include<vector>
using namespace std;
#define PI 3.14
//int main()
//{
//	double n, r;
//	while (cin >> n >> r)
//	{
//		if (2 * r * PI >= n)
//			cout << "Yes" << endl;
//		else
//			cout << "No" << endl;
//	}
//	return 0;
//}
//OJ青蛙跳台阶
class solution
{
public:
	int floorjump(int number)
	{
		vector<int> jmp(number + 1,0);
		jmp[0] = 1;
		int sum = 0;
		for (int i = 1; i <= number; ++i)
		{
			for (int j = 0; j <= i; ++j)
				sum += jmp[j];
			jmp[i] = sum;
			sum = 0;
		}
		return jmp[number];
	}
};
int main()
{
	int number;
	solution p;
	while (cin >> number)
		cout << p.floorjump(number) << endl;
	return 0;
}