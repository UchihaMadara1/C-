#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
//����һ�Ŷ������ĸ��ڵ��һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
//·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
//(ע��: �ڷ���ֵ��list�У����鳤�ȴ�����鿿ǰ)
//�ݹ�ⷨ
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
//��һ��byte���ֶ�Ӧ�Ķ�����������1�����������������3�Ķ�����Ϊ00000011���������2��1.
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
