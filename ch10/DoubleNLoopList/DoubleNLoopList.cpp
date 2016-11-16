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
		fprintf(stderr,"���ܷ����ڴ�\n");

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
	*���PtrNodeΪ���һ���ڵ㲻�ص��ģ�
	*�Կɸ�ֵ���������һ��while���ж��˳�;
	*/
		PtrNode = PtrNode -> next;

	return PtrNode;
}

void DeleteNode(node_t **ListHead, int key)
{
	node_t *PtrNode;
	PtrNode = SearchNode(ListHead, key);
	if(PtrNode == NULL)
		fprintf(stderr,"ɾ��ʱ��������û�йؼ��֣�%d\n",key);
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