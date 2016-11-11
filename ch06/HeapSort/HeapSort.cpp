#include<stdio.h>
#include"HeapSort.h"

void MaxHeapify(int A[], int i, int size)
{
	int l, r, largest, temp;

	l = Left(i);
	r = Right(i);

	if(l < size && A[l] > A[i])
		largest = l;
	else 
		largest = i;
	if(r < size && A[r] > A[largest])
		largest = r;
	if(largest != i)
	{
		temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		MaxHeapify(A, largest, size);
	}
}

void BuildMaxHeap(int A[], int size)
{
	int i;

	for(i = size/2 - 1; i >= 0; i--)//start last not leaf node
		MaxHeapify(A, i, size);
}

void HeapSort(int A[], int size)
{
	int i,temp;

	BuildMaxHeap(A, size);
	PrintHeap(A, size);
	for(i = size - 1; i > 0; i--)
	{
		temp = A[0];
		A[0] = A[i];
		A[i] = temp;

		MaxHeapify(A, 0, i);
	}
}

void PrintHeap(int A[], int size)
{
	int i;

	for(i = 0; i < size; i++)
		printf("%-3d", A[i]);
	printf("\n");
}