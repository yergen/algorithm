//��ԭ��
//���õ�ַ��http://blog.csdn.net/ture010love/article/details/6664501

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#include <assert.h>

#define P 101 /* �������� */
#define M 9 /* ����hash T�ĳ��ȣ�����ȫ��ϣ�£�n=m */
#define N M
typedef struct _hash_func
{
	int a;
	int b;
	int m;
} HASH_FUNC, *PHASH_FUNC;

#define HASH_FUC_SIZE sizeof(HASH_FUNC)
#define INT_SIZE sizeof(int)
#define HASH_MAP_ADDR(a,b,m,k) ((((a)*(k)+(b))%P)%(m)) /* h(x)= ((a*x+b)modp)mod m */
static int* T[M] = {0,}; /* �����ϣ��*/
static PHASH_FUNC p_hash_func = NULL; /*�����ϣ��Ĺ�ϣ����*/ 

/************************************************************************/
/*��ʼ����ϣ��*/
void init_hash_table(int* T[], int keys[]);
/*�����һ��ȫ��ϣ����, 0<=a<p, 0<b<p*/
PHASH_FUNC random_hash_func(int mod);
/*��ӡ��ȫ��ϣ��*/
void print_hash_table(int* T[]);
/*���ؼ���������ϣ��*/
void insert_keys_to_hash(int* T[], int keys[]);
/*�������ؼ��ֲ����ϣ��*/
void insert_key_to_hash(int* T[], int key);
/* ��ѯ�ؼ��֣���������ڣ��򷵻�0 */
int search_hash_key(int* T[], int key);
/************************************************************************/
void init_hash_table(int* T[], int keys[])
{
	int i = 0;
	int count[M];
	PHASH_FUNC ph = NULL;

	memset(count, 0, M*INT_SIZE);
	p_hash_func = random_hash_func(M); 
	
	for(i=0; i < N; i++)
	{
		count[HASH_MAP_ADDR(p_hash_func->a,p_hash_func->b, p_hash_func->m,keys[i])]++;
	}
	for(i=0;i<M;i++)
	{
		/* ����ڶ���ϣ��T[i]ֻ��1��Ԫ�أ���a=b=0,m=1,�����뼴��*/
		if(1==count[i])
		{		
			T[i] = (int*)malloc(HASH_FUC_SIZE+1*INT_SIZE);
			*(T[i]) = *(T[i]+1) = 0;
			*(T[i]+2) = 1;
			*(T[i]+3) = 0;
		}
		/* ����ڶ���ϣ��Ti]*/
		if(1<count[i])
		{
			ph = random_hash_func(count[i]*count[i]);
			T[i] = (int*)malloc(HASH_FUC_SIZE+ph->m*INT_SIZE);
			memset(T[i], 0, HASH_FUC_SIZE+ph->m*INT_SIZE);
			memcpy(T[i], ph, HASH_FUC_SIZE);
			free(ph);
			ph = NULL;
		}
	}
}

PHASH_FUNC random_hash_func(int mod)
{
	PHASH_FUNC pfuc = NULL;
	pfuc = (PHASH_FUNC)malloc(HASH_FUC_SIZE);
	pfuc->a = rand()%(P-1)+1;
	pfuc->b = rand()%P;
	pfuc->m = mod;

	return pfuc;
}

void insert_keys_to_hash(int* T[], int keys[])
{
	int i;
	for(i=0; i<N;i++) 
		insert_key_to_hash(T, keys[i]);
}

void insert_key_to_hash(int* T[], int key)
{
	int i = 0, j = 0;
	i = HASH_MAP_ADDR(p_hash_func->a,p_hash_func->b, p_hash_func->m,key);
	j = HASH_MAP_ADDR(*(T[i]),*(T[i]+1), *(T[i]+2),key);
	printf("key=%d,i=%d, j=%d, val=%d\n", key, i, j, *(T[i]+3+j));
	assert(*(T[i]+3+j)==0); // ʵ֤��T[i]�����Ƿ�����ͻ~
	*(T[i]+3+j) = key;
}

int search_hash_key(int* T[], int key)
{
	int i = 0, j = 0;
	i = HASH_MAP_ADDR(p_hash_func->a,p_hash_func->b, p_hash_func->m,key);
	j = HASH_MAP_ADDR(*(T[i]),*(T[i]+1), *(T[i]+2),key);
	if(!T[i] || *(T[i]+2)<=j)
		return 0;
	return *(T[i]+3+j);
}

void print_hash_table(int* T[])
{
	int i = 0, j = 0;
	printf("*********************************\n");
	printf("The hash table is:\n");
	for(i=0; i<M; i++)
	{
		if(!T[i])
		{
			printf("slot%-2d: NUL\n", i);
		}
		else
		{
			printf("slot%-2d: a=%-4db=%-4dm=%-4dVALUE:",i, *T[i], *(T[i]+1), *(T[i]+2));
			for(j=0; j<*(T[i]+2); j++)
			{
				printf("<%-4d>", *(T[i]+3+j));
			}
			printf("\n");
		}
	}
	printf("\n\n");
}

int main()
{
	int keys[N] = {10, 22, 37, 40, 52, 60, 70, 72, 75};

	srand((unsigned int)(time(NULL)));
	init_hash_table(T,keys);
	print_hash_table(T);
	insert_keys_to_hash(T, keys);
	print_hash_table(T);
	printf("The search 22's key is:%d\n", search_hash_key(T, 22));
	return 0;
}