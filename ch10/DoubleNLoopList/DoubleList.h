#ifndef DOUBLELIST_H
#define DOUBLELIST_H

//定义双向无循环链表结构
typedef struct node{
	int key;
	struct node *prev;
	struct node *next;
}node_t;

//链表操作
void CreateList(node_t **ListHead);
void InsertNode(node_t **ListHead, int key);
node_t *SearchNode(node_t **ListHead, int key);;
void DeleteNode(node_t **ListNode, int key);
void PrintNode(node_t **ListHead);

#endif