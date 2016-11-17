#include<stdio.h>
#include<stdlib.h>
#include"DoubleHashTable.h"

int Function1(int key)
{
	return key % N;
}
int Function2(int key)
{
	return 1 + (key % 11);
}
int HashFunction(int key, int i)//Ë«ÖØÉ¢ÁĞ·¨
{
	return (Function1(key) + i * Function2(key)) % N;
}
int HashInsert(int *T, int key)
{
	int i = 0, j;

	do
	{
		j = HashFunction(key, i);
		if(T[j] == NULL)
		{
			T[j] = key;
			return j;
		}
		else 
			i = i + 1;
	}while(i < N);

	fprintf(stderr,"Hash table overflow!\n");
	return -1;
}
int HashSearch(int *T, int key)
{
	int i = 0, j;

	do
	{
		j = HashFunction(key, i);
		if(T[j] == key)
			return j;
		else 
			i = i + 1;
	}while(T[j] != NULL && i < N);

	fprintf(stderr,"There is not the key:%d in HashTable!\n",key);
	return -1;
}

void PrintHash(int *T)
{
	int i;
	
	for(i = 0; i < N; i++)
	{
		if(T[i] != NULL)
			printf("%-3d",T[i]);
	}
	printf("\n");
}