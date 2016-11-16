#ifndef HASHTABLE_H
#define HASHTABLE_H

#define N 10

typedef struct Node{
	int key;
	struct Node *prev;
	struct Node *next;
}Node_t;

typedef struct Hash{
	Node_t *T[N];
}Hash_t;

int HashFunction(int n);                    //散列函数
void ListInsert(Node_t *List, int key);     //链表插入
Node_t * ListSearch(Node_t *List, int key);      //链表查找
void ListDelete(Node_t *List, int key);      //链表删除
void PrinList(Node_t *List);                //打印链表
void ChainedHashInsert(Hash_t *T, int key); //散列表插入
void ChainedHashDelete(Hash_t *T, int key);  //散列表删除
Node_t *ChainedHashSearch(Hash_t *T, int key);  //散列表查找
void PrintTable(Hash_t *T);                 //打印散列表
#endif