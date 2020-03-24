#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
using namespace std;
static vector<int> _Find(const char ch, const string str1,vector<int> buffer)
{
	for (unsigned int i = 0; i < str1.size(); ++i)
	{
		if (ch == str1[i])
			buffer.push_back(i);
	}
	return buffer;
}
static void _Pulic_Str(string str1, string str2)
{
	int i = 0, j = 0, flag = 0, sz = 0;
	int pst = j;
	vector<int> buffer;
	string tmp = "\0";
	while (str1[i] != '\0'&&str2[j] != '\0')
	{
		if (str1[i] == str2[j])
		{
			flag++;
			i++;
			j++;
		}
		else
		{
			if (flag > sz)
			{
				sz = flag;
				flag = 0;
				pst = j - sz;
			}
			j++;
			buffer = _Find(str2[j], str1,buffer);
			while (i == -1 && str2[j] != '\0')
			{
				j++;
				buffer = _Find(str2[j], str1,buffer);
			}
		}
	}
	for (int k = pst; k < pst + sz; ++k)
		cout << str2[k];
	cout << endl;
}
int main()
{
	string str1, str2, ret;
	while (cin >> str1 >> str2)
	{
		if (str1.size() < str2.size())
		{
			string tmp = str1;
			str1 = str2;
			str2 = tmp;
		}
		_Pulic_Str(str1, str2);
	}
	return 0;
}
