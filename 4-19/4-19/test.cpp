#define _CRT_SECURE_NO_WARNINGS

////////////////////////////////////////////////////////////////////
//奶牛买礼物
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct ListNode
{
	int price;//售价
	int run;//运费
}ListNode;
int main()
{
	int N = 5, B = 24;
	//cin >> N >> B;
	vector<int> dp(N);
	vector<ListNode> dpv(N);//初始化N个节点空间
	for (int i = 0; i < N; i++)
	{
		cin >> dpv[i].price >> dpv[i].run;
		dp[i] = dpv[i].price + dpv[i].run;
	}
	sort(dp.begin(), dp.end());//默认升序
	for (int i = 1; i < N; ++i)
	{
		if (dp[i - 1] == dp[i] && dpv[i - 1].price > dpv[i].price)
			swap(dpv[i - 1],dpv[i]);
	}
	//此时得到的向量空间就是升序的
	int count = 0;
	auto it = dp.begin();
	//关键优惠劵给哪个牛，应该是最大优惠的那个牛即礼物临届最贵的牛
	while (it != dp.end() && B - (*it) > 0)  
	{
		count++;
		B -= (*it);
		it++;
	}
	if (it == dp.end())//此时所有牛都获得礼物
	{}
	//此时B不能全额为下一头牛购买礼物
    else if (B >= (dpv[count].price / 2 + dpv[count].run)) 
	{
		count++;
	}
	cout << "最大奶牛数 = " << count << endl;
	system("pause");
	return 0;
}

