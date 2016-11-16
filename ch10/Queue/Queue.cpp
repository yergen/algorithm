#include<stdio.h>
#include<stdlib.h>

#define N 12
typedef struct Queue{
	int length;
	int head, tail;
	int *A;
}Queue_t;

void InitQueue(Queue_t *queue);
void Enqueue(Queue_t *queue, int key);
int Dequeue(Queue_t *queue);
bool IsEmptyQueue(Queue_t *queue);
bool IsFullQueue(Queue_t *queue);

void InitQueue(Queue_t *queue)
{
	queue -> length = N;
	queue -> A = (int *)malloc(sizeof(int) * queue -> length);
	queue -> head = queue -> tail = 0;
}

void Enqueue(Queue_t *queue, int key)
{
	if(IsFullQueue(queue))
		fprintf(stderr,"Queue overflow\n");

	queue -> A[queue -> tail] = key;
	if(queue -> tail == queue -> length - 1)
		queue -> tail = 0;
	else 
		queue -> tail = queue -> tail + 1;
}

int Dequeue(Queue_t *queue)
{
	int key;
	if(IsEmptyQueue(queue))
		fprintf(stderr,"Queue overflow\n");

	key = queue -> A[queue -> head];
	if(queue -> head == queue -> length - 1)
		queue -> head = 0;
	else
		queue -> head = queue -> head + 1;

	return key;
}

bool IsEmptyQueue(Queue_t *queue)
{
	return (queue -> head == queue -> tail);
}

bool IsFullQueue(Queue_t *queue)
{
	return (queue -> head == queue -> tail + 1);
}
int main()
{
	int i;
	Queue_t *queue;
	queue = (Queue_t *)malloc(sizeof(Queue_t));
	InitQueue(queue);
	for(i = 0; i < N - 1; i++)
		Enqueue(queue,i);
	Dequeue(queue);
	printf("%-3d\n",Dequeue(queue));
	Enqueue(queue,10);
	Enqueue(queue,11);
	Enqueue(queue,12);
	return 0;
}