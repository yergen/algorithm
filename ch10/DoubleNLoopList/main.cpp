#include<stdio.h>
#include<stdlib.h>
#include"DoubleList.h"

int main()
{
   /*
	*������ָ���ָ������Ϊ*ListHead�ĵ�ַ�ڸı䣻
	*��ListHead�ĵ�ַ����ı䣬����ֱ�ӵ����βΣ�
	*����Ӱ������Ĵ��ݡ�
	*/
	node_t **ListHead;
	ListHead = (node_t **)malloc(sizeof(node_t));
	if(!ListHead)
		fprintf(stderr,"���ܷ����ڴ�\n");
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