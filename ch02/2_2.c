#include<stdio.h>

void BubbleSort(int *A, int n);

void BubbleSort(int *A, int n)
{
	int i, j, temp;

	for(i = 0; i < n - 1; i++)
		for(j = n - 1;j > i; j--)
			if(A[j] < A[j - 1])
			{
				temp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = temp;
			}
}

int main()
{
	int i;
	int A[6] ={1, 6, 3, 5, 8, 4};

	BubbleSort(A,sizeof(A)/sizeof(int));
	for(i = 0; i < 6; i++)
		printf("%3d",A[i]);
	printf("\n");

	return 0;
}