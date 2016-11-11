#include<stdio.h>
#include<stdlib.h>
#include"subarray.h"

struct array_struct FindMaxCrossingSubarray(int *A, int low, int mid, int high)
{
	int i, j, left_sum, right_sum;
	struct array_struct a;
	left_sum = NINFINITY;
	int sum = 0;
	
	for(i = mid; i >= low; i--)
	{
		sum = sum + A[i];
		if(sum > left_sum)
		{
			left_sum = sum;
			a.low = i;
		}
	}

	right_sum = NINFINITY;
	sum = 0;

	for(j = mid + 1; j <= high; j++)
	{
		sum = sum + A[j];
		if(sum > right_sum)
		{
			right_sum = sum;
			a.high = j;
		}
			
	}

	a.sum = left_sum + right_sum;
	return a;
}

struct array_struct FindMaximunSubarray(int *A,int low, int high)
{
	int mid;
	struct array_struct p, q, r, w;

	if(high == low)
	{
		p.low = low;
		p.high = high;
		p.sum = A[low];
		return p;
	}
	else 
	{
		mid = (low + high)/2;
		q = FindMaximunSubarray(A, low, mid);
		r = FindMaximunSubarray(A, mid + 1, high);
		w = FindMaxCrossingSubarray(A, low, mid, high);

		if(q.sum >= r.sum && q.sum >= w.sum)
				return q;
		else if(r.sum >= q.sum && r.sum >= w.sum)
				return r;
		else 
				return w;
	}
}