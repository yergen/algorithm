#include<stdio.h>
#include<stdlib.h>
#include"HashTable.h"

int HashFunction(int n)
{
	return n % 10;
}

void ListInsert(Node_t *List, int key)
{
	Node_t *L;
	L = (Node_t *)malloc(sizeof(Node_t));
	if(!L)
		fprintf(stderr,"不能分配足够内存！\n");

	L -> key = key;

	L -> next = List -> next;
	if(List -> next != NULL)
		List -> next -> prev = L;

	List -> next = L;
	List -> prev = List;
}
Node_t * ListSearch(Node_t *List, int key)
{
	Node_t *L;

	L = List -> next;
	while(L != NULL && L -> key != key)
		L = L -> next;

	return L;
}
void ListDelete(Node_t *List, int key)
{
	Node_t *L;

	L = ListSearch(List, key);
	if(L == NULL)
		fprintf(stderr,"删除时，链表中没有关键字：%d\n",key);
	else
	{
		if(List -> next == L)//删除的是链表中第一个元素时
			List -> next = L -> next;
		else
			L -> prev -> next = L -> next;

		if(L -> next != NULL)
			L -> next -> prev = L -> prev;
	}

	free(L);
}
void PrinList(Node_t *List)
{
	Node_t *L;

	L = List -> next;
	while(L != NULL)
	{
		printf("%-3d",L -> key);
		L = L -> next;
	}
	printf("\n");
}
void ChainedHashInsert(Hash_t *T, int key) 
{
	ListInsert(T ->T[HashFunction(key)],key);
}
void ChainedHashDelete(Hash_t *T, int key)
{
	ListDelete(T ->T[HashFunction(key)],key);
}
Node_t *ChainedHashSearch(Hash_t *T, int key)
{
	return ListSearch(T ->T[HashFunction(key)],key);
}
void PrintTable(Hash_t *T)
{
	int i;
	for(i = 0; i < N; i++)
	{
		if(T -> T[i] -> next != NULL)
		{
			printf("%-2d: ",i);
			PrinList(T -> T[i]);
		}
	}
	printf("\n");
}