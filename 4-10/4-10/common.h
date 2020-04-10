#pragma
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#define Datatype char 
void swap(Datatype *a, Datatype *b)
{
	Datatype tmp = *a;
	*a = *b;
	*b = tmp;
}