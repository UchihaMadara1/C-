#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
/*链接：https://www.nowcoder.com/questionTerminal/a5190a7c3ec045ce9273beebdfe029ee
来源：牛客网

一个袋子里面有n个球，每个球上面都有一个号码(拥有相同号码的球是无区别的)。如果一个袋子是幸运的当且仅当所有球的号码的和大于所有球的号码的积。
例如：如果袋子里面的球的号码是{1, 1, 2, 3}，这个袋子就是幸运的，因为1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
你可以适当从袋子里移除一些球(可以移除0个,但是别移除完)，要使移除后的袋子是幸运的。现在让你编程计算一下你可以获得的多少种不同的幸运的袋子。

输入描述:
第一行输入一个正整数n(n ≤ 1000)
第二行为n个数正整数xi(xi ≤ 1000)


输出描述:
输出可以产生的幸运的袋子数
*/
//int main() {
//	int n;
//	cin >> n;
//	vector<int> number(n);
//	for (int i = 0; i<n; i++) {
//		cin >> number[i];
//	}
//	sort(number.begin(), number.end());
//	int ones = 0;
//	while (ones<n and number[ones] == 1) {
//		++ones; // 计算1的个数
//	}
//	if (ones <= 0) { //无1则无解
//		cout << 0 << endl;
//		return 0;
//	}
//	vector<int> prod = { 1 }; //记录可行的乘积
//	vector<int> sum = { 0 };  //及和
//	int pre = 0;
//	for (int i = ones; i<n; ++i) {
//		int m = sum.size();
//		int k = 0;
//		if (number[i] == number[i - 1]) {
//			//如果与前一数一样就没必要重复添加到前面的袋子
//			k = pre;
//		}
//		for (; k<m; ++k) {
//			//加入number[i]到各袋子后，是否是幸运的（比负的1的数量多就行）
//			if (sum[k] + number[i] - prod[k] * number[i] > -ones) {
//				prod.push_back(prod[k] * number[i]);//保存当前袋子乘积及和
//				sum.push_back(sum[k] + number[i]);
//			}
//		}
//		pre = m;
//	}
//	int count = ones>2 ? ones - 1 : 0;//只有1组成的幸运袋子数
//	for (int k = 1; k<sum.size(); ++k) {//通过加入不同数量的1以使各袋子幸运
//		count += ones + sum[k] - prod[k];
//	}
//	cout << count << endl;
//	return 0;
//}
//int n, a[1005];
//int dfs(int step, int sum, int mul){
//	int i, j, res = 0;
//	for (i = step + 1; i<n; i++){
//		int nSum = sum + a[i], nMul = mul*a[i];
//		if (nSum>nMul) res += 1 + dfs(i, nSum, nMul);
//		else if (a[i] == 1) res += dfs(i, nSum, nMul);
//		else break;
//		while (i<n - 1 && a[i] == a[i + 1]) i++;
//	}
//	return res;
//}
//int main(){
//	scanf("%d", &n);
//	for (int i = 0; i<n; i++) scanf("%d", a + i);
//	sort(a, a + n);
//	printf("%d\n", dfs(0, 1, 1));
//}
/////////////////////////////////////////////////////////////////
//输入一个日期，判断是这一年的多少天
//class solution
//{
//public:
//	bool Is_leap(int year)
//	{
//		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
//			return true;
//		return false;
//	}
//	int Eve_2_days(int year)
//	{
//		if (Is_leap(year))
//			return 29;
//		return 28;
//	}
//public:
//	int fun(int year, int month, int day)
//	{
//		int Month_days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//		if (year <= 0 || month <= 0 || day <= 0 || month > 12)
//			return -1;
//		if ((month == 2 && day > Eve_2_days(year)) || day > Month_days[month])
//			return -1;
//		int flag = 0;
//		for (int i = 1; i < month; ++i)
//		{
//			if (i == 2)
//			{
//				flag += Eve_2_days(year);
//				continue;
//			}
//			flag += Month_days[i];
//		}
//		flag += day;
//		return flag;
//	}
//};
//int main()
//{
//	int year, month, day;
//	solution p;
//	while (cin >> year >> month >> day)
//	{
//		cout << p.fun(year, month, day) << endl;
//	}
//	return 0;
//}