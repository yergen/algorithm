#include<stdio.h>
#include<stdlib.h>

int Merge(int *A, int p, int q, int r);
int MergeSort(int *A, int p, int r);

int Merge(int *A, int p, int q, int r)
{
	int i, j, k, inversion = 0;

	int n1 = q - p + 1;
	int n2 = r - q;
	int *L = (int *)malloc(sizeof(int)*n1);
	int *R = (int *)malloc(sizeof(int)*n2);

	for (i = 0; i < n1; i++)
		L[i] = A[p + i];
	for (j = 0; j < n2; j++)
		R[j] = A[q + 1 + j];

	for (i = 0, j = 0,k = p; k <= r; k++)
	{
		if (i == n1)
			A[k] = R[j++];
		else if (j == n2)
			A[k] = L[i++];
		else if (L[i] <= R[j])
			A[k] = L[i++];
		else
		{
			A[k] = R[j++];
			inversion += n1 - i;
		}
	}
	return inversion;
}

int MergeSort(int *A, int p, int r)
{
	int q, inversion;

	if (p < r)
	{
		inversion = 0;
		q = (p + r) / 2;
		inversion += MergeSort(A, p, q);
		inversion += MergeSort(A, q + 1, r);
		inversion += Merge(A, p, q, r);
		return inversion;
	}
	else
		return 0;

}

int main()
{
	int A[5] = {2, 3, 5, 6, 1};
	int i,inversion;

	for (i = 0; i < 5; i++)
		printf("%3d", A[i]);
	printf("\n");

	inversion = MergeSort(A, 0, 4);

	for (i = 0; i < 5; i++)
		printf("%3d", A[i]);
	printf("\n");

	printf("inversion:%3d\n",inversion);

	return 0;
}