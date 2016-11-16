#include<stdio.h>
#include<stdlib.h>
#include"HashTable.h"

int main()
{
	int i;
	int A[10] = {1,21,5,25,15,17,28,18,6,66};
	Hash_t *H = (Hash_t *)malloc(sizeof(Hash_t)); 
	for(i = 0; i < N; i++)
	{
		H ->T[i] = (Node_t *)malloc(sizeof(Node_t));
		H ->T[i] -> next = NULL;
		//H ->T[i] -> key = NULL;
		//H ->T[i] -> prev = NULL;
	}
	for(i = 0; i < N; i++)
		ChainedHashInsert(H,A[i]);
	PrintTable(H);
	if(ChainedHashSearch(H,15) != NULL)
		printf("Yes\n");
	else 
		printf("No\n");
	ChainedHashDelete(H,28);
	PrintTable(H);
	ChainedHashDelete(H,18);
	PrintTable(H);

	free(H);
	return 0;
}