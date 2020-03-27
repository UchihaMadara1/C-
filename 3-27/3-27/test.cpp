#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
//int main()
//{
//	int n = 5;
//	if (n++ > 5)
//		cout << n << endl;
//	cout << --n << endl;
//	return 0;
//}
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		if (str1.size() < str2.size())
		{
			string tmp = str1;
			str1 = str2;
			str2 = tmp;
		}
		int flag = 0;
		if (str1.size() == 0 || str2.size() == 0)
			flag = str1.size() + str2.size();
		int i = 0, j = 0;
		while (str1[i] != '\0'&&str2[j] != '\0')
		{
			if (str1[i] == str2[j])
			{
				i++;
				j++;
			}
			else if (str1[i + 1] == str2[j + 1])
			{
				i++;
				j++;
				flag++;
			}
			else if (str1[i + 1] == str2[j])
			{
				i++;
			}
		}
		flag += (str1.size() - str2.size());
		cout << flag << endl;
	}
	return 0;
}