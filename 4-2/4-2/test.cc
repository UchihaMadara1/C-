////////////////////////////////////////////
//
//OJ题练习_排序
//奇数位上为奇数，偶数位上为偶数
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	/**
	*  奇数位上都是奇数或者偶数位上都是偶数
	*  输入：数组arr，长度大于2
	*  len：arr的长度
	*  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
	*/
	void oddInOddEvenInEven(vector<int>& arr, int len)
	{
		int i = 0, j = 0;
		while (len--)
		{
			if (i % 2 == 0 && arr[i] % 2 != 0)
			{
				j = i + 1;
				while (arr[j] % 2 != 0&&j <= len)
					j += 2;
				swap(arr[i],arr[j]);
			}
			else if (i % 2 == 1 && arr[i] % 2 != 1)
			{
				j = i + 1;
				while (arr[j] % 2 != 1&&j <= len)
					j += 2;
				swap(arr[i],arr[j]);
			}
			i++;
		}
	}
};
int main()
{
vector<int> arr(8, 0);
Solution p;
for (int i = 0; i < arr.size(); ++i)
{
	arr[i] = i + 1;
}
p.oddInOddEvenInEven(arr, arr.size());
vector<int>::iterator it = arr.begin();
while (it != arr.end())
{
cout << *it;
it++;
}
cout << endl;
	return 0;
}