#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//class solution
//{
//public:
//	static int getTotalCount(int month)
//	{
//		if (month < 3)
//			return 1;
//		return getTotalCount(month - 1) + getTotalCount(month - 2);
//
//	}
//};
//int main()
//{
//	int month;
//	cin >> month;
//	solution p;
//	int ret = p.getTotalCount(month);
//	cout << ret << endl;
//	return 0;
//}
//
int main()
{
	string _up, _down;
	while (cin >> _up >> _down)
	{
		string::iterator it1 = _up.begin();
		string::iterator it2 = _down.begin();
		while (it1 != _up.end() && it2 != _down.end())
		{
			if ((*it1) == '?' || (*it1) == (*it2))
			{
				it1++;
				it2++;
			}
			else if ((*it1) == '*')//֮������������������ӣ�����Ϊ��ͨ��������ض�����ַ�����ֹ��������ͬ�ַ�����
			{
				it1++;
				it2++;//����
				while ((*it1) == '?' || (*it1) == '*')
				{
					it1++;
					it2++;//����
				}
				while ((*it2) != (*it1) && it2 != _down.end())
					it2++;
			}
			else
			{
				cout << "false" << endl;
				break;
			}
		}
		if (it1 == _up.end() && it2 == _down.end())
			cout << "true" << endl;
	}
	return 0;
}
//ţ��
//���ӣ�https://www.nowcoder.com/questionTerminal/43072d50a6eb44d2a6c816a283b02036
//��Դ��ţ����

//#include <iostream>
//using namespace std;
//
//
//
//int main()
//{
//	string regex;
//	string str;
//	while (cin >> regex >> str)
//	{
//
//		int j = 0;
//		int i = 0;
//		bool flag = false;
//		while (str[i] != '\0' || regex[j] != '\0')
//		{
//			if (regex[j] == '*')
//			{
//				j++;
//				flag = true;
//			}
//			else if (str[i] == regex[j] || regex[j] == '?')
//			{
//				i++;
//				j++;
//			}
//			else if (flag == true)
//			{
//				while (str[i] != regex[j])
//				{
//					i++;
//				}
//				flag = false;
//			}
//			else
//			{
//				cout << "false" << endl;
//				break;
//			}
//		}
//		if (str[i] == '\0'&&str[j] == '\0')
//		{
//			cout << "true" << endl;
//		}
//
//	}
//	return 0;
//
//}