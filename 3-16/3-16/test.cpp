#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
/*���ӣ�https://www.nowcoder.com/questionTerminal/a5190a7c3ec045ce9273beebdfe029ee
��Դ��ţ����

һ������������n����ÿ�������涼��һ������(ӵ����ͬ����������������)�����һ�����������˵ĵ��ҽ���������ĺ���ĺʹ���������ĺ���Ļ���
���磺��������������ĺ�����{1, 1, 2, 3}��������Ӿ������˵ģ���Ϊ1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
������ʵ��Ӵ������Ƴ�һЩ��(�����Ƴ�0��,���Ǳ��Ƴ���)��Ҫʹ�Ƴ���Ĵ��������˵ġ����������̼���һ������Ի�õĶ����ֲ�ͬ�����˵Ĵ��ӡ�

��������:
��һ������һ��������n(n �� 1000)
�ڶ���Ϊn����������xi(xi �� 1000)


�������:
������Բ��������˵Ĵ�����
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
//		++ones; // ����1�ĸ���
//	}
//	if (ones <= 0) { //��1���޽�
//		cout << 0 << endl;
//		return 0;
//	}
//	vector<int> prod = { 1 }; //��¼���еĳ˻�
//	vector<int> sum = { 0 };  //����
//	int pre = 0;
//	for (int i = ones; i<n; ++i) {
//		int m = sum.size();
//		int k = 0;
//		if (number[i] == number[i - 1]) {
//			//�����ǰһ��һ����û��Ҫ�ظ���ӵ�ǰ��Ĵ���
//			k = pre;
//		}
//		for (; k<m; ++k) {
//			//����number[i]�������Ӻ��Ƿ������˵ģ��ȸ���1����������У�
//			if (sum[k] + number[i] - prod[k] * number[i] > -ones) {
//				prod.push_back(prod[k] * number[i]);//���浱ǰ���ӳ˻�����
//				sum.push_back(sum[k] + number[i]);
//			}
//		}
//		pre = m;
//	}
//	int count = ones>2 ? ones - 1 : 0;//ֻ��1��ɵ����˴�����
//	for (int k = 1; k<sum.size(); ++k) {//ͨ�����벻ͬ������1��ʹ����������
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
//����һ�����ڣ��ж�����һ��Ķ�����
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