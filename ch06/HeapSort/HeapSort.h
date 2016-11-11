#ifndef HEAPSORT_H
#define HEAPSORT_H

#define Parent(i) (((i) - 1) / 2)
#define Left(i)   ((2 * (i)) + 1)
#define Right(i)  ((2 * (i)) + 2)

void MaxHeapify(int A[], int i, int size);
void BuildMaxHeap(int A[], int size);
void HeapSort(int A[], int size);
void PrintHeap(int A[], int size);
#endif