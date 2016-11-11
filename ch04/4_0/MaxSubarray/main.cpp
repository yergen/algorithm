#include<stdio.h>
#include<stdlib.h>
#include"subarray.h"


int main()
{
	struct array_struct f;
	int A[16] ={
					13, -3, -25, 20, -3, -16, -23, 18,
					20, -7,  12, -5, -22, 15, -4,  7				
				};

	f = FindMaximunSubarray(A,0,15);

	printf("low = %d, high = %d, sum = %d\n",f.low, f.high, f.sum);

	return 0;
}