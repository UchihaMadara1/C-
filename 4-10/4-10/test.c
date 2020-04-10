#define _CRT_SECURE_NO_WARNINGS
#include "Bintree.h"

int main()
{
	Bintree t;
	int i = 0;
	char *str = "ABC##DE##F##G#H##";
	BintreeNodeInit(&t);
	//BintreeNode_Create(&t);
	BinTreeCreateByStr(&t, str, &i);
	return 0;
}
