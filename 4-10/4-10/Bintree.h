#include "common.h"


typedef struct BintreeNode
{
	Datatype data;
	struct BintreeNode *left;
	struct BintreeNode *right;
}BintreeNode;
typedef struct Bintree
{
	BintreeNode *root;
}Bintree;
//构造二叉树声明
void BintreeNodeInit(Bintree *t);
void BintreeNode_Create(Bintree *t);
void _BintreeNode_Create1(BintreeNode **t);
BintreeNode* _BintreeNode_Create();
BintreeNode* _BinTreeCreateByStr(char *str, int *i);
void BinTreeCreateByStr(Bintree *t, char *str, int *i);

//构造二叉树实现
void BintreeNodeInit(Bintree *t)
{
	t->root = NULL;
}
void BintreeNode_Create(Bintree *t)
{
	//t->root = _BintreeNode_Create();
	_BintreeNode_Create1(&t->root);
}
void _BintreeNode_Create1(BintreeNode **t)
{
	Datatype item;
	scanf("%c",&item);
	if (item == '#')
	{
		*t = NULL;
	}
	else
	{
		*t = (BintreeNode*)malloc(sizeof(BintreeNode));
		assert(*t != NULL);
		(*t)->data = item;
		_BintreeNode_Create1(&((*t)->left));
		_BintreeNode_Create1(&((*t)->right));
	}
}
BintreeNode* _BintreeNode_Create()
{
	Datatype x;
	scanf("%c",&x);
	if (x == '#')
	{
		return NULL;
	}
	else
	{
		BintreeNode *p = (BintreeNode*)malloc(sizeof(BintreeNode));
		assert(p != NULL);
		p->data = x;
		p->left = _BintreeNode_Create();
		p->right = _BintreeNode_Create();
		return p;
	}
}
void BinTreeCreateByStr(Bintree *t, char *str, int *i)
{
	t->root = _BinTreeCreateByStr(str, i);
}
BintreeNode* _BinTreeCreateByStr(char *str, int *i)
{
	assert(str != NULL);
	if (str[*i] == '#' || str[*i] == '\0')
		return NULL;
	else
	{
		BintreeNode *p = (BintreeNode*)malloc(sizeof(BintreeNode));
		p->data = str[*i];
		(*i)++;
		p->left = _BinTreeCreateByStr(str,i);
		(*i)++;
		p->right = _BinTreeCreateByStr(str, i);
		return p;
	}
}