#include<stdio.h>
#include<stdlib.h>

#define INFINITY 65536

void Merge(int *A, int p, int q, int r);
void MergeSort(int *A, int p, int r);

void Merge(int *A,  int p,  int q, int r)
{
	int i, j, k;

	int n1 = q - p + 1;
	int n2 = r - q;
	int *L = (int *)malloc(sizeof(int)*(n1+1));	
	int *R = (int *)malloc(sizeof(int)*(n2+1));
	if (L == NULL || R == NULL)
		printf("…Í«Îø’º‰ ß∞‹\n");

	for(i = 0; i < n1; i++)
		L[i] = A[p + i];
	for (j = 0; j < n2; j++)
		R[j] = A[q + 1 + j];

	L[n1] = INFINITY;
	R[n2] = INFINITY;

	i = 0;
	j = 0;

	for (k = p; k <= r; k++)
	{
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
	}
}

void MergeSort(int *A, int p, int r)
{
	int q;

	if(p < r)
	{
		q = (p + r) / 2;
		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);
	}
}
int main()
{
	int A[8] = {1, 5, 3, 5, 4, 9, 6, 7};
	int i;
	printf("πÈ≤¢≈≈–Ú\n");
	printf("================≈≈–Ú«∞===============");
	printf("\n");

	for (i = 0; i < 8; i++)
		printf("%3d", A[i]);
	printf("\n");

	MergeSort(A, 0, 7);

	printf("================≈≈–Ú∫Û===============");
	printf("\n");

	for (i = 0; i < 8; i++)
		printf("%3d", A[i]);
	printf("\n");

	return 0;
}