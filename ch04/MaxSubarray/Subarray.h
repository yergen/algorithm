#ifndef SUBARRAY_H
#define SUBARRAY_H

#define NINFINITY -65536

struct array_struct{
	int low;
	int high;
	int sum;
};

struct array_struct FindMaxCrossingSubarray(int *A, int low, int mid, int high);
struct array_struct FindMaximunSubarray(int *A,int low, int high);


#endif
