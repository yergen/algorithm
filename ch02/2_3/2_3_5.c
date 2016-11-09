#include<stdio.h>

int BinarySearch(int *A,int v);

int BinarySearch(int *A,int v)
{
	int low = 0;
	int high = sizeof(A)/sizeof(int);
	int mid;

	while(low < high)
	{
		mid = (low + high)/2;

		if(A[mid] == v)
			return mid;
		else if(A[mid] < v)
			low = mid + 1;
		else
			high = mid;
	}
	return -1;
}

int main()
{
	int A[6] = {1,3,4,6,7,8};
	int v;
	int index;
	printf("Please input a number that below 9:");
	scanf("%d",&v);
	index = BinarySearch(A,v);
	printf("The index is %d\n",index);

	return 0;
}