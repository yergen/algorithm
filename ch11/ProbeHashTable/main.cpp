#include<stdio.h>
#include<stdlib.h>
#include"DoubleHashTable.h"


int main()
{
	int T[13] = {NULL};
	printf("%d\n",HashInsert(T, 79));
	printf("%d\n",HashInsert(T, 69));
	printf("%d\n",HashInsert(T, 72));
	printf("%d\n",HashInsert(T, 50));
	printf("%d\n",HashInsert(T, 98));
	printf("%d\n",HashInsert(T, 14));
	printf("%d\n",HashSearch(T, 72));
	printf("%d\n",HashSearch(T, 73));
	PrintHash(T);
	return 0;
}