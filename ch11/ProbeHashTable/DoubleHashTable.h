#ifndef DOUBLEHASHTABLE_H
#define DOUBLEHASHTABLE_H

#define N 13

//这里没有删除操作，在必须有时，应采用链接法解决冲突。
int Function1(int key);
int Function2(int key);
int HashFunction(int key, int i);//双重散列法
int HashInsert(int *T, int key);
int HashSearch(int *T, int key);
void PrintHash(int *T);
#endif