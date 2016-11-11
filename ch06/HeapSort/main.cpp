#include<stdio.h>
#include"HeapSort.h"

int main()
{
	int A[10] = {4,1,3,2,16,9,10,14,8,7};

	HeapSort(A, 10);
	PrintHeap(A, 10);

	return 0;
}