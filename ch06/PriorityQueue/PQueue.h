#ifndef PQUEUE_H
#define PQUEUE_H

#define INFINIT -65536
#define Parent(i) ((i - 1) / 2)
#define Left(i)   (2 * i + 1)
#define Right(i)  (2 * i + 2)

typedef struct{
	int *A;
	int length;
	int heap_size;
}heap_t;

void MaxHeapify(heap_t *heap);
void BuildMaxHeap(heap_t *heap);
int HeapMaximum(heap_t *heap);
int HeapExtractMax(heap_t *heap);
void HeapIncreaseKey(heap_t *heap, int i, int key);
void MaxHeapInsert(heap_t *heap, int key);

#endif