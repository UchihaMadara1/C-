#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//int _Judge(int n)
//{
//	int flag = 0;
//	for (int i = 0; i < 32;++i)
//	{
//		if ((n & 1) == 1)
//			flag++;
//		n = n >> 1;
//	}
//	return flag;
//}
//int main()
//{
//	int n;
//	int m;
//	while (cin >> n)
//	{
//		m = n;
//		int flag = 0;
//		while (n)
//		{
//			n = n & (n - 1);
//			flag++;
//		}
//		cout << flag << endl;
//		int ret = _Judge(m);
//		cout << ret << endl;
//	}
//	return 0;
//}
#include<vector>
#include<algorithm>
//class Gloves {
//public:
//	int _findMinimum(int n, vector<int> left, vector<int> right)
//	{
//		int left_s = left.size();
//		int right_s = 0;
//		int count = 0;
//		for (unsigned int i = 0; i < left.size(); ++i)
//		{
//			if (left[i] == 0 || right[i] == 0)
//				left_s--;
//			if (left[i] != 0 && right[i] != 0)
//			{
//				for (unsigned int j = 0; j < right.size(); ++j)
//				{
//					if (j != i)
//					{
//						count += right[j];
//					}
//				}
//				count += 1;//加最后一个自己的颜色
//				right_s = max(count,right_s);
//				count = 0;
//			}
//		}
//		return left_s + right_s;
//	}
//};
//int main()
//{
//	int n;
//	vector<int>left, right;
//	Gloves p;
//	int ret;
//	while (cin >> n)
//	{
//		int tmp;
//		for (int i = 0; i < n; ++i)
//		{
//			cin >> tmp;
//			left.push_back(tmp);
//		}
//		for (int i = 0; i < n; ++i)
//		{
//			cin >> tmp;
//			right.push_back(tmp);
//		}
//		ret = p._findMinimum(n,left,right);
//		cout << ret << endl;
//	}
//	return 0;
//}
////////////////////////////////////////////////////////
//https://blog.csdn.net/qq_43763344/article/details/93639712
class Gloves{
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		int left_sum = 0, left_min = INT_MAX;
		int right_sum = 0, right_min = INT_MAX;
		int sum = 0;
		// 遍历每一种颜色的左右手套序列
		for (int i = 0; i<n; i++){
			//对于有0存在的颜色手套，累加
			if (left[i] * right[i] == 0)
				sum += left[i] + right[i];
			// 对于左右手都有的颜色手套，执行累加 - 最小值 +1
			// 找到最小值和总数
			else{
				left_sum += left[i];
				right_sum += right[i];
				left_min = min(left_min, left[i]);
				right_min = min(right_min, right[i]);
			}
		}
		//结果为有左右都有数量的手套序列的结果+有0存在的手套数+最后再加一肯定就能保证了
		return sum +
			min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
	}
};

int main()
{
	int n = INT_MAX;
	int m = INT_MIN;
	return 0;
}