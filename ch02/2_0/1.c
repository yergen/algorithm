#include<stdio.h>
int main()
{
	int A[6] = {5,2,4,6,1,3};
	int j, i, key;
	for (j = 1; j < 6; j++)
	{
		key = A[j];
		i = j - 1;
		while(i >= 0 && A[i] > key)
		{
			A[i + 1] = A[i];
			i = i - 1;
			A[i + 1] = key;
		}
	}
	for (i = 0; i < 6; i++)
		printf("%-4d",&A[i]);
	return 0;
}