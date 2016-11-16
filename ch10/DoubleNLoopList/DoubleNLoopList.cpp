#include<stdio.h>
#include<stdlib.h>
#include"DoubleList.h"

void CreateList(node_t **ListHead)
{
	*ListHead = NULL;
}
void InsertNode(node_t **ListHead, int key)
{
	node_t *ListNode;
	ListNode = (node_t *)malloc(sizeof(node_t));
	if(!ListNode)
		fprintf(stderr,"不能分配内存\n");

	ListNode -> key = key;

	ListNode -> next = *ListHead;
	if((*ListHead) != NULL)
		(*ListHead) -> prev = ListNode;

	ListNode -> prev = NULL;

	*ListHead = ListNode;
}

node_t *SearchNode(node_t **ListHead, int key)
{
	node_t *PtrNode;

	PtrNode = *ListHead;
	while(PtrNode != NULL && PtrNode -> key != key)
	/*
	*如果PtrNode为最后一个节点不必担心，
	*仍可赋值，则会在下一步while中判定退出;
	*/
		PtrNode = PtrNode -> next;

	return PtrNode;
}

void DeleteNode(node_t **ListHead, int key)
{
	node_t *PtrNode;
	PtrNode = SearchNode(ListHead, key);
	if(PtrNode == NULL)
		fprintf(stderr,"删除时，链表中没有关键字：%d\n",key);
	if(PtrNode -> prev != NULL)
		PtrNode -> prev -> next = PtrNode -> next;
	else
		*ListHead = PtrNode -> next;
	if(PtrNode -> next != NULL)
		PtrNode -> next -> prev = PtrNode -> prev;

	free(PtrNode);
}

void PrintNode(node_t **ListHead)
{
	node_t *PtrNode;

	PtrNode = *ListHead;
	while(PtrNode != NULL)
	{
		printf("%-3d",PtrNode -> key);
		PtrNode = PtrNode -> next;
	}
	printf("\n");
}