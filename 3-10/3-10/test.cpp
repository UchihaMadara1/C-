#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
//class AB
//{
//public:
//	//AB(int a = 0) :_a(a)
//	//{
//		//cout << "this is copy function"<<endl;
//	//}
//	static int n;
//public:
//	AB()
//	{ 
//		n++;
//		cout << "this is create function" << endl;
//	}
//	~AB()
//	{
//		n--;
//		cout << "this is delete function" << endl;
//	}
//	static int get_n(){ return n; }
//private:
//	int _a;
//};
//int  AB::n = 0;
//void main()
//{
//	//AB A(4), B(5), C[3], *p[2] = {&A,&B};
//	AB *p = new AB;
//	delete p;
//	cout << "n = " << AB::get_n() << endl;
//}
//bool Is_Lexicographically(const string *arr, int n)
//{
//	int flag = 0;
//	for (int i = 0; i < n - 1; ++i)
//	{
//		if (arr[i] <= arr[i + 1])
//			flag++;
//	}
//	if (flag == n - 1)
//		return true;
//	return false;
//}
//bool Is_Lengths(const string* arr, int n)
//{
//	int flag = 0;
//	for(int i = 0; i < n - 1; ++i)
//	{
//		if (arr[i].size() <= arr[i + 1].size())
//			flag++;
//	}
//	if (flag == n - 1)
//		return true;
//	return false;
//}
//int main()
//{
//	string arr[100];
//	int n, i = 0;
//	cin >> n;
//	while (i < n)
//	{
//		getline(cin, arr[i++]);
//	}
//	if (Is_Lexicographically(arr, n) && !Is_Lengths(arr, n))
//		cout << "lexicographically" << endl;
//	else if (!Is_Lexicographically(arr, n) && Is_Lengths(arr, n))
//		cout << "lengths" << endl;
//	else if (Is_Lexicographically(arr, n) && Is_Lengths(arr, n))
//		cout << "both" << endl;
//	else
//		cout << "none" << endl;
//	return 0;
//}
