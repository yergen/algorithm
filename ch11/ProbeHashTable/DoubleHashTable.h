#ifndef DOUBLEHASHTABLE_H
#define DOUBLEHASHTABLE_H

#define N 13

//����û��ɾ���������ڱ�����ʱ��Ӧ�������ӷ������ͻ��
int Function1(int key);
int Function2(int key);
int HashFunction(int key, int i);//˫��ɢ�з�
int HashInsert(int *T, int key);
int HashSearch(int *T, int key);
void PrintHash(int *T);
#endif