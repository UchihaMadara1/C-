#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//bool _Is_per(int m)
//{
//	int flag = 0;
//	for (int i = 2; i <= m; ++i)
//	{
//		if (m % i == 0)
//			flag += (m / i);
//	}
//	if (flag == m)
//		return true;
//	return false;
//}
//static int count(int n)
//{
//	if (n > 500000 || n <= 0)
//		return -1;
//	int count = 0;
//	for (int i = 1; i <= n; ++i)
//	{
//		count += _Is_per(i);
//	}
//	return count;
//}
//int main()
//{
//	int n;
//	int ret = 0;
//	while (cin >> n)
//	{
//		//ret = count(n);
//		ret = count(n);
//		cout << ret << endl;
//	}
//	return 0;
//}
//#include<iostream>
//#include<string>
//using namespace std;
//static string _big(string&left, string&right)
//{
//	if (left == "joker JOKER" || right == "joker JOKER")
//		return "joker JOKER";
//	if (left.size() == 7 && right.size() != 7)
//		return left;
//	if (right.size() == 7 && left.size() != 7)
//		return right;
//	if (left.size() != right.size())
//		return "ERROR";
//	switch (left.size())
//	{
//	case 1:
//	{
//			  if (left == "2" || right == "2")
//			  {
//				  if (left == "JOKER" || right == "JOKER")
//					  return "JOKER";
//				  else if (left == "joker" || right == "joker")
//					  return "joker";
//				  return "2";
//			  }
//			  return left > right ? left : right;
//	}
//	case 3:
//	case 5:
//	case 7:
//	case 9: 
//		return left > right ? left : right;
//	default:
//		return "ERROR";
//	}
//}
//int main()
//{
//	string s;
//	while (getline(cin, s))
//	{
//		string left = s,right = s;
//		string::iterator l_it = find(left.begin(),left.end(),'-');
//		left.erase(l_it,left.end());
//		string::iterator r_it = find(right.begin(),right.end(),'-');
//		right.erase(right.begin(),++r_it);
//		string ret = _big(left,right);
//		cout << ret << endl;
//	}
//	return 0;
//}
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
static string _big(string&left, string&right)
{
	if (left == "joker JOKER" || right == "joker JOKER")
		return "joker JOKER";
	if (left.size() == 7 && right.size() != 7)
		return left;
	if (right.size() == 7 && left.size() != 7)
		return right;
	if (left.size() != right.size())
		return "ERROR";
	switch (left.size())
	{
	case 1:
	{
			  if (left == "JOKER" || right == "JOKER")
				  return "JOKER";
			  else if (left == "joker" || right == "joker")
				  return "joker";
			  else if (left == "2" || right == "2")
				  return "2";
			  else if (left == "A" || right == "A")
				  return "A";
			  else if (left == "K" || right == "K")
				  return "K";
			  else if (left == "Q" || right == "Q")
				  return "Q";
			  else if (left == "J" || right == "J")
				  return "J";
			  return left > right ? left : right;
	}
	case 3:
	{
			  if (left == "2 2" || right == "2 2")
				  return "2 2";
			  else if (left == "A A" || right == "A A")
				  return "A A";
			  else if (left == "K K" || right == "K K")
				  return "K K";
			  else if (left == "Q Q" || right == "Q Q")
				  return "Q Q";
			  else if (left == "J J" || right == "J J")
				  return "J J";
			  return left > right ? left : right;
	}
	case 5:
	{
			  if (left == "2 2 2" || right == "2 2 2")
				  return "2 2 2";
			  else if (left == "A A A" || right == "A A A")
				  return "A A A";
			  else if (left == "K K K" || right == "K K K")
				  return "K K K";
			  else if (left == "Q Q Q" || right == "Q Q Q")
				  return "Q Q Q";
			  else if (left == "J J J" || right  == "J J J")
				  return "J J J";
			  return left > right ? left : right;
	}
	case 7:
	{
			  if (left == "2 2 2 2" || right == "2 2 2 2")
				  return "2 2 2 2";
			  else if (left == "A A A A" || right == "A A A A")
				  return "A A A A";
			  else if (left == "K K K K" || right == "K K K K")
				  return "K K K K";
			  else if (left == "Q Q Q Q" || right == "Q Q Q Q")
				  return "Q Q Q Q";
			  else if (left == "J J J J" || right == "J J J J")
				  return "J J J J";
			  return left > right ? left : right;
	}
	case 9:
		return left > right ? left : right;
	default:
		return "ERROR";
	}
}
int main()
{
	string s;
	while (getline(cin, s))
	{
		string left = s, right = s;
		string::iterator l_it = find(left.begin(), left.end(), '-');
		left.erase(l_it, left.end());
		string::iterator r_it = find(right.begin(), right.end(), '-');
		right.erase(right.begin(), ++r_it);
		string ret = _big(left, right);
		cout << ret << endl;
	}
	return 0;
}