////////////////////////////////////////////
//
//OJ����ϰ_����
//����λ��Ϊ������ż��λ��Ϊż��
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	/**
	*  ����λ�϶�����������ż��λ�϶���ż��
	*  ���룺����arr�����ȴ���2
	*  len��arr�ĳ���
	*  ��arr����������λ�϶�����������ż��λ�϶���ż��
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