#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
static vector<int> Sort_poker(vector<int>poker, int k)
{
	std::stack<int> stack1;
	std::stack<int> stack2;
	while (k--)
	{
		for (int i = 0; i < poker.size(); i++)
		{
			if (i < (poker.size()) / 2)
				stack1.push(poker[i]);
			else
				stack2.push(poker[i]);
		}
		for (int j = 0; j < poker.size(); j++)
		{
			if (j % 2 == 0)
			{
				poker[j] = stack2.top();
				stack2.pop();
			}
			else
			{
				poker[j] = stack1.top();
				stack1.pop();
			}
		}
	}
	return poker;
}
int main()
{
	int T, n, k;
	cin >> T;
	for (int j = 0; j < T;j++)
	{
		while(cin >> n >> k)
		{
			vector<int> poker(2*n,0);
			vector<int> ret;
			for (int i = 0; i < 2*n; ++i)
			{
				poker[i];
			}
			ret = Sort_poker(poker, k); 
			for (int k = ret.size() - 1; k > 0; k--)
			{
				cout << ret[k] << " ";
			}
			cout <<ret[0]<< endl;
			break;
		}
	}
	return 0;
}
