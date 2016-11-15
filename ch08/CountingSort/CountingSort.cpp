#include<stdio.h>
#include<stdlib.h>

void CountingSort(int *A, int *B, int max, int size);

void CountingSort(int *A, int *B, int max, int size)
{
	int i, j;
	int *C = (int *)malloc(sizeof(int) * (max + 1));

	for(i = 0; i <= max; i++)
		C[i] = 0;
	for(j = 0; j < size; j++)
		C[A[j]] = C[A[j]] + 1;
	//C[i] now contains the number of elements equal to i.
	for(i = 1; i <= max; i++)
		C[i] = C[i] + C[i - 1];
	//C[i] now contains the number of elements less than or equal to i.

	for(j = size - 1; j >= 0; j--)
	{
		B[C[A[j]] - 1] = A[j];
		C[A[j]] = C[A[j]] - 1;
	}

	free(C);
}
int main()
{
	int i;
	int A[8] = {2,5,3,0,2,3,0,3};
	int B[8] ={0};

	CountingSort(A, B, 5, 8);

	for(i = 0; i < 8; i++)
		printf("%-3d", B[i]);
	printf("\n");

	return 0;

}
