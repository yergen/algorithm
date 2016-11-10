#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INSERTION_SORT_THRESHOLD 20
#define SELECTION_SORT_THRESHOLD 15

void Merge(int *A,int p,int q,int r);
void MergeSort(int *A,int p,int r);
void InsertSort(int *A,int p,int r);
void SelectSort(int *A,int p,int r);
void MixedSortInsert(int *A,int p,int r);
void MixedSortSeclet(int *A,int p,int r);

void Merge(int *A,int p,int q,int r)
{
	int i,j,k,n1,n2;

	n1 = q - p + 1;
	n2 = r - q;

	#ifdef MERGE_HEAP_ALLOCATION
		int *L = calloc(n1, sizeof(int));
		int *R = calloc(n2, sizeof(int));
	#else
		int *L = (int *)malloc(n1 * sizeof(int));
		int *R = (int *)malloc(n2 * sizeof(int));
	#endif
	
		memcpy(L,A + p, n1 * sizeof(int));
		memcpy(R,A + q + 1, n1 * sizeof(int));

	for(i = 0,j = 0,k = 0;k <= r;k++)
	{
		if(i == n1)
			A[k] = R[j++];
		else if(j == n2)
			A[k] = L[i++];
		else if(L[i] <= R[j])
			A[k] = L[i++];
		else
			A[k] = R[j++];
	}
	
	#ifdef MERGE_HEAP_ALLOCATION
		free(L);
		free(R);
	#endif
}

void MergeSort(int *A,int p,int r)
{
	int q;

	if(p < r)
	{
		q = (p + r) / 2;
		MergeSort(A,p,q);
		MergeSort(A,q + 1,r);
		Merge(A,p,q,r);
	}
}

void InsertSort(int *A,int p,int r)
{
	int i, j, key;

	for(j = p + 1; j <= r; j++)
	{
		key = A[j];
		i = j -1;

		while((i >= p) && (A[i] > key))
		{
			A[i + 1] = A[i];
			i = i - 1;
		}

		A[i + 1] = key;
	}
}

void SelectSort(int *A,int p,int r)
{
	int i, j, min, temp;

	for(i = p; i < r; i++)
	{
		min = i;
		for(j = i + 1; j <= r; j++)
			if(A[j] < A[min])
				min = j;
		temp = A[i];
		A[i] = A[min];
		A[min] = temp;
	}
}

void MixedSortInsert(int *A,int p,int r)
{
	if(p >= r) return;
	
	if(r - p < INSERTION_SORT_THRESHOLD)
		InsertSort(A,p,r);
	else
	{
		int q = (p + r) / 2;
		MergeSort(A,p,q);
		MergeSort(A,q + 1,r);
		Merge(A,p,q,r);
	}
}

void MixedSortSeclet(int *A,int p,int r)
{
	if(p >= r) return;

	if(r - p < SELECTION_SORT_THRESHOLD)
		SelectSort(A,p,r);
	else
	{
		int q = (p + r) / 2;
		MergeSort(A,p,q);
		MergeSort(A,q + 1,r);
		Merge(A,p,q,r);
	}
}

