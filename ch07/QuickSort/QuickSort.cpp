#include<stdio.h>

int Partition(int A[], int p, int r);
void QuickSort(int A[], int p, int r);

void QuickSort(int A[], int p, int r)
{
	int q;

	if(p < r)
	{
		q = Partition(A, p, r);
		QuickSort(A, p, q - 1);
		QuickSort(A, q + 1, r);
	}
}

int Partition(int A[], int p, int r)
{
	int i, j, temp;

	i = p - 1;
	for(j = p; j < r; j++)
	{
		if(A[j] <= A[r])
		{
			i = i + 1;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	temp = A[i + 1];
	A[i + 1] = A[r];
	A[r] = temp;

	return i + 1;

}
int main()
{
	int i;
	int A[8] = {2,8,7,1,3,5,6,4};

	QuickSort(A, 0, 7);

	for(i = 0; i < 8; i++)
		fprintf(stdout, "%-3d",A[i]);
	printf("\n");

	return 0;
}