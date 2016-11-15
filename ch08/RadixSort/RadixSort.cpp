#include<stdio.h>
#include<stdlib.h>

int GetNumInPos(int num, int pos);
void RadixSort(int *A, int d, int size);

int GetNumInPos(int num, int pos)
{
	int i, temp = 1;

	for(i = 0; i < pos - 1; i++)
		temp *= 10;

	return (num / temp) % 10;
}

void RadixSort(int *A, int d, int size)
{
	int i, j, k, pos, a;
	int *B[10], C[10] ={0};

	for(i = 0; i < 10; i++)
	{
		B[i] = (int *)malloc(sizeof(int) * size);
		for(j = 0; j <= size; j++)
			B[i][j] = 0;
	}

 	for(pos = 1; pos <= d; pos++)
	{
		for(j = 0; j < size; j++)
		{
			a = GetNumInPos(A[j], pos);
			C[a] = C[a] + 1;
			B[a][C[a] - 1] = A[j];
		}

		for(i = 0, j = 0; i < 10; i++)
		{
			for(k = 1; k <= C[i]; k++)
			{
				A[j++] = B[i][k-1];
				B[i][k-1] = 0;
			}
			C[i] = 0;
		} 
	}
	free(B);
}
int main()
{
	int i;
	int A[7] = {329,457,657,839,436,720,355}; 

 	RadixSort(A,3,7);

	for(i = 0; i < 7; i++)
		printf("%-4d",A[i]);
	printf("\n");

	return 0;
}