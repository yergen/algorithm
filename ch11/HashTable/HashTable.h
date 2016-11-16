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

int HashFunction(int n);                    //ɢ�к���
void ListInsert(Node_t *List, int key);     //�������
Node_t * ListSearch(Node_t *List, int key);      //�������
void ListDelete(Node_t *List, int key);      //����ɾ��
void PrinList(Node_t *List);                //��ӡ����
void ChainedHashInsert(Hash_t *T, int key); //ɢ�б����
void ChainedHashDelete(Hash_t *T, int key);  //ɢ�б�ɾ��
Node_t *ChainedHashSearch(Hash_t *T, int key);  //ɢ�б����
void PrintTable(Hash_t *T);                 //��ӡɢ�б�
#endif