#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//		string::reverse_iterator rit = str.rbegin();
//		while (rit != str.rend())
//		{
//			cout <<*rit;
//			*rit++;
//		}
//		cout << endl;
//	}
//	return 0;
//}
static int Get_Max_Pstrsz(string str1, string str2)
{
	vector<vector<int>> record(str1.size(), vector<int>(str2.size(),0));
	//vector<vector<int> > record(str1.length(), vector<int>(str2.length()));
	int max_str = 0;
	for (int i = 0; i < str1.size(); ++i)
	{
		for (int j = 0; j < str2.size(); ++j)
		{
			if (str1[i] == str2[j])
			{
				if (i == 0 || j == 0)
				{
					record[i][j] = 1;
				}
				else
				{
					record[i][j] = record[i - 1][j - 1] + 1;
				}
			}
			else
			{
				record[i][j] == 0;
			}
			if (max_str < record[i][j])
			{
				max_str = record[i][j];
			}
		}
	}
	return max_str;
}
static string Get_Max_Pstr(string str1, string str2)
{
	vector<vector<int>> record(str1.size(), vector<int>(str2.size(), 0));
	//vector<vector<int> > record(str1.length(), vector<int>(str2.length()));
	int max_str = 0,end_str = 0;
	for (int i = 0; i < str1.size(); ++i)
	{
		for (int j = 0; j < str2.size(); ++j)
		{
			if (str1[i] == str2[j])
			{
				if (i == 0 || j == 0)
				{
					record[i][j] = 1;
				}
				else
				{
					record[i][j] = record[i - 1][j - 1] + 1;
				}
			}
			else
			{
				record[i][j] == 0;
			}
			if (max_str < record[i][j])
			{
				max_str = record[i][j];
				end_str = i;
			}
		}
	}
	return str1.substr(end_str - max_str + 1,max_str);
}
int main()
{
	string str1, str2;
	int ret;
	string ret_str;
	while(cin >> str1 >> str2)
	{
		ret = Get_Max_Pstrsz(str1, str2);
		ret_str = Get_Max_Pstr(str1, str2);
		cout << ret << endl;
		cout << ret_str << endl;
	}
	return 0;
}