#ifndef DOUBLELIST_H
#define DOUBLELIST_H

//����˫����ѭ������ṹ
typedef struct node{
	int key;
	struct node *prev;
	struct node *next;
}node_t;

//�������
void CreateList(node_t **ListHead);
void InsertNode(node_t **ListHead, int key);
node_t *SearchNode(node_t **ListHead, int key);;
void DeleteNode(node_t **ListNode, int key);
void PrintNode(node_t **ListHead);

#endif