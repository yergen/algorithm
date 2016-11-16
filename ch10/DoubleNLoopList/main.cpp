#include<stdio.h>
#include<stdlib.h>
#include"DoubleList.h"

int main()
{
   /*
	*在这用指针的指针是因为*ListHead的地址在改变；
	*而ListHead的地址不会改变，可以直接当做形参，
	*不会影响后续的传递。
	*/
	node_t **ListHead;
	ListHead = (node_t **)malloc(sizeof(node_t));
	if(!ListHead)
		fprintf(stderr,"不能分配内存\n");
	CreateList(ListHead);
	InsertNode(ListHead, 1);
	PrintNode(ListHead);
	InsertNode(ListHead, 4);
	PrintNode(ListHead);
	InsertNode(ListHead, 16);
	PrintNode(ListHead);
	InsertNode(ListHead, 9);
	PrintNode(ListHead);
	InsertNode(ListHead, 25);
	PrintNode(ListHead);
	DeleteNode(ListHead, 4);
	PrintNode(ListHead);

	return 0;
}