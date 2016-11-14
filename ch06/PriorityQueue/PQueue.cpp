#include<stdio.h>
#include<stdlib.h>
//#include<limits.h>
#include"PQueue.h"

void MaxHeapify(heap_t *heap, int i)
{
	int l, r, largest, temp;

	l = Left(i);
	r = Right(i);

	if(l <= heap -> heap_size && heap -> A[l] > heap -> A[i])
		largest = l;
	else largest = i;
	if(r <= heap -> heap_size && heap -> A[r] > heap -> A[largest])
		largest = r;
	if(largest != i)
	{
		temp = heap -> A[i];
		heap -> A[i] = heap -> A[largest];
		heap -> A[largest] = temp;

		MaxHeapify(heap, largest);
	}
}

void BuildMaxHeap(heap_t *heap)
{
	int i;
	
	heap -> heap_size = heap -> length;
	for(i = heap -> length / 2 - 1; i >= 0; i--)
		MaxHeapify(heap, i);
}

int HeapMaximum(heap_t *heap)
{
	return heap -> A[0];
}

int HeapExtractMax(heap_t *heap)
{
	int max;

	if(heap -> heap_size < 1)
	{
		fprintf(stderr, "heap underflow");
		exit(0);
	}

	max = heap -> A[0];
	heap -> A[0] = heap -> A[heap -> heap_size - 1];
	heap -> heap_size = heap -> heap_size - 1;
	MaxHeapify(heap, 0);
	
	return 0;
}

void HeapIncreaseKey(heap_t *heap, int i, int key)
{
	int temp;

	if(key < heap -> A[i])
	{
		fprintf(stderr, "new key is smaller than current key");
		exit(0);
	}
	heap -> A[i] = key;
	while(i > 0 && heap -> A[Parent(i)] < heap -> A[i])
	{
		temp = heap -> A[Parent(i)];
		heap -> A[Parent(i)] = heap -> A[i];
		heap -> A[i] = temp;

		i = Parent(i);
	}
}

void MaxHeapInsert(heap_t *heap, int key)
{
	heap -> heap_size += 1;
	heap -> A[heap -> heap_size - 1] = INFINIT;

	HeapIncreaseKey(heap, heap -> heap_size, key);
}