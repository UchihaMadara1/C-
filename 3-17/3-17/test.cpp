#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Date
{
public:
	bool JudgeRapYear(int year);
	int JudgeDay(int year,int month,int day);
};
bool Date::JudgeRapYear(int year)//判断当年是否为闰年
{
	if (year % 400 == 0||year % 100 != 0 && year % 4 == 0)
	{
		return true;
	}
	return false;
}
int Date::JudgeDay(int year,int month,int day)
{
	int Nowday = 0;
	if (year <= 0)
		return -1;
	if (JudgeRapYear(year))
	{
		switch (month)
		{
		case 1:
			if (day > 31)
				return -1;
			Nowday = 0 + day;
			break;
		case 2:
			if (day > 29)
				return -1;
			Nowday = 31 + day;
			break;
		case 3:
			if (day > 31)
				return -1;
			Nowday = 60 + day;
			break;
		case 4:
			if (day > 30)
				return -1;
			Nowday = 91 + day;
			break;
		case 5:
			if (day > 31)
				return -1;
			Nowday = 121 + day;
			break;
		case 6:
			if (day > 30)
				return -1;
			Nowday = 152 + day;
			break;
		case 7:
			if (day > 31)
				return -1;
			Nowday = 182 + day;
			break;
		case 8:
			if (day > 31)
				return false;
			Nowday = 213 + day;
			break;
		case 9:
			if (day > 30)
				return -1;
			Nowday = 244 + day;
			break;
		case 10:
			if (day > 31)
				return -1;
			Nowday = 274 + day;
			break;
		case 11:
			if (day > 30)
				return -1;
			Nowday = 305 + day;
			break;
		case 12:
			if (day > 31)
				return -1;
			Nowday = 335 + day;
			break;
		default:
			return -1;
		}
	}
	else
	{
		switch (month)
		{
		case 1:
			if (day > 31)
				return -1;
			Nowday = 0 + day;
			break;
		case 2:
			if (day > 28)
				return -1;
			Nowday = 31 + day;
			break;
		case 3:
			if (day > 31)
				return -1;
			Nowday = 59 + day;
			break;
		case 4:
			if (day > 30)
				return -1;
			Nowday = 90 + day;
			break;
		case 5:
			if (day > 31)
				return -1;
			Nowday = 120 + day;
			break;
		case 6:
			if (day > 30)
				return -1;
			Nowday = 151 + day;
			break;
		case 7:
			if (day > 31)
				return -1;
			Nowday = 181 + day;
			break;
		case 8:
			if (day > 31)
				return -1;
			Nowday = 212 + day;
			break;
		case 9:
			if (day > 30)
				return -1;
			Nowday = 243 + day;
			break;
		case 10:
			if (day > 31)
				return -1;
			Nowday = 273 + day;
			break;
		case 11:
			if (day > 30)
				return -1;
			Nowday = 304 + day;
			break;
		case 12:
			if (day > 31)
				return -1;
			Nowday = 334 + day;
			break;
		default:
			return -1;
		}
	}
	return Nowday;
}
int main()
{
	int Y, M, D;
	cout << "输入年月日" << endl;
	while (cin >> Y >> M >> D)
	{
		Date A;
		int p = A.JudgeDay(Y,M,D);
		cout << p << endl;
	}
	return 0;
}
