#include<stdio.h>
#include<stdlib.h>

#define N 10
int DirectAddSearch(int *T, int k);
void DirectAddInsert(int *T, int x);
void DirectAddDelete(int *T, int x);

int DirectAddSearch(int *T, int k)
{
	return T[k];
}

void DirectAddInsert(int *T, int x)
{
	T[x] = x;
}
void DirectAddDelete(int *T, int x)
{
	T[x] = NULL;
}

int main()
{
	int i, key;
	int T[10] = {NULL};
	for(i = 0; i < N; i++)
	{
		DirectAddInsert(T,i);
	}
	key = DirectAddSearch(T, 5);
	printf("%-3d\n",key);
	DirectAddDelete(T,5);
	DirectAddDelete(T,4);
	for(i = 0; i < 10; i++)
	{
		if(T[i] != NULL)
			printf("%-3d",T[i]);
	}
	printf("\n");

	return 0;
}