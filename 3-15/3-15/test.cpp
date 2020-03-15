#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
//输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
//路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
//(注意: 在返回值的list中，数组长度大的数组靠前)
//递归解法
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
//class Solution {
//public:
//	vector<vector<int>> buffer;
//	vector<int> tmp;
//	vector<vector<int> > FindPath(TreeNode* root, int expectNumber)
//	{
//		if (root == nullptr)
//			return buffer;
//		tmp.push_back(root->val);
//		if (expectNumber - root->val == 0 && root->left == nullptr&&root->right == nullptr)
//			buffer.push_back(tmp);
//		FindPath(root->left, expectNumber - root->val);
//		FindPath(root->right, expectNumber - root->val);
//		if (tmp.size() != 0)
//			tmp.pop_back();
//		return buffer;
//	}
//};
//求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1.
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		int Maxcount = 0;
		while (n)
		{
			if (n & 1)
			{
				count++;
				Maxcount = max(count, Maxcount);
			}
			else
			{
				count = 0;
			}
			n = n >> 1;
		}
		cout << Maxcount << endl;
	}
	return 0;
}
