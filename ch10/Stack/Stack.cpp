#include<stdio.h>
#include<stdlib.h>

#define N 10
typedef int DataType;
typedef struct{
	DataType A[N];
	int top;
}Stack_t;

Stack_t *BuiltStack();
bool IsEmptyStack(Stack_t *Stack);
bool IsFullStack(Stack_t *Stack);
void Push(Stack_t *Stack, DataType x);
DataType Pop(Stack_t *Stack);
DataType GetTop(Stack_t *Stack);
void PrintStack(Stack_t *Stack);

Stack_t *BuiltStack()
{
	Stack_t *Stack = (Stack_t *)malloc(sizeof(Stack_t));
	Stack -> top = -1;
	return Stack;
}

bool IsEmptyStack(Stack_t *Stack)
{
	return (Stack -> top == -1);
}

bool IsFullStack(Stack_t *Stack)
{
	return (Stack -> top >= N - 1);
}

void Push(Stack_t *Stack, DataType x)
{
	Stack -> A[++(Stack -> top)] = x;
}

DataType Pop(Stack_t *Stack)
{
	if(IsEmptyStack(Stack))
	{
		fprintf(stderr,"underflow\n");
		return -1;
	}
	else
		return (Stack -> A[(Stack -> top)--]);
}

DataType GetTop(Stack_t *Stack)
{
	return (Stack -> A[Stack -> top]);
}

void PrintStack(Stack_t *Stack)
{
	int i;

	if(IsEmptyStack(Stack))
		fprintf(stderr,"underflow\n");
	else
	{
		for(i = 0; i <= Stack -> top; i++)
			printf("%-3d",Stack -> A[i]);
		printf("\n");
	}
}
int main()
{
	Stack_t *Stack;

	Stack = BuiltStack();
	Push(Stack,4);
	PrintStack(Stack);
	printf("TOP:%d\n",GetTop(Stack));
	Push(Stack,1);
	PrintStack(Stack);
	printf("TOP:%d\n",GetTop(Stack));
	Push(Stack,3);
	PrintStack(Stack);
	printf("TOP:%d\n",GetTop(Stack));
	Pop(Stack);
	Pop(Stack);
	PrintStack(Stack);

	return 0;
}