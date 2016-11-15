#include<stdio.h>
#include<stdlib.h>

struct Bucket_s{
	double key;
	struct Bucket_s *next;
};

struct Bucket_s * InitBucket(struct Bucket_s *Bucket);
void InsertBucket(struct Bucket_s *Bucket, double key);
void PrintBucketList(struct Bucket_s *Bucket);
void PrintBucketSort(struct Bucket_s *Bucket);
struct Bucket_s * InitBucket()
{
	struct Bucket_s *Bucket; 
	Bucket = (struct Bucket_s *)malloc(sizeof(struct Bucket_s));
	Bucket -> key = NULL;
	Bucket -> next = NULL;

	return Bucket;
}

void InsertBucket(struct Bucket_s *Bucket, double key)
{
	struct Bucket_s *temp, *p;
	temp = (struct Bucket_s *)malloc(sizeof(struct Bucket_s));
	temp -> key = key;
	temp -> next = NULL;
	p = Bucket;
	if(p -> next == NULL)//插入到链表头
	{
		temp -> next = p -> next;
		p -> next = temp;
	}
	else 
	{
		if(temp -> key < p -> next -> key)//插入到链表头
		{
			temp -> next = p -> next;
			p -> next = temp;
		}
		else 
		{
			while(temp -> key >= p -> next ->key && p ->next ->next != NULL)//查找节点
				p = p -> next;
			if(temp -> key < p -> next ->key)//插入到中间第一个小于节点关键字前
			{
				temp -> next = p -> next;
				p ->next = temp;
			}
			else
			{
				if(p -> next -> next == NULL)//插入到末尾
					p -> next -> next = temp;
			}
		}
	}
	//free(temp);
}

void PrintBucketList(struct Bucket_s *Bucket)
{
	struct Bucket_s *p;
    p = Bucket;
    if(Bucket -> next != NULL)
    {
        do{
            printf("-> %-.2f ",p -> next -> key);
            p = p -> next;
        }while(p -> next != NULL);
     }
}

void PrintBucketSort(struct Bucket_s *Bucket)
{
	struct Bucket_s *p;
    p = Bucket;
    if(Bucket -> next != NULL)
    {
        do{
            printf(" %.2f ",p -> next -> key);
            p = p -> next;
        }while(p -> next != NULL);
     }
}
int main()
{
	int i;
	double A[10] = {0.78, 0.17, 0.39, 0.26, 0.72,
					0.94, 0.21, 0.12, 0.23, 0.68};
	struct Bucket_s *B[10];

	for(i = 0; i < 10; i++)
		B[i] = InitBucket();

	for(i = 0; i < 10; i++)
		InsertBucket(B[int(10*A[i])], A[i]);
	printf("桶中的排序情况：\n");
	for(i = 0; i < 10; i++)
	{
		printf("%d",i);
		PrintBucketList(B[i]);
		printf("\n");
	}
	printf("排序后:\n");
	for(i = 0; i < 10; i++)
	{
		PrintBucketSort(B[i]);
	}
	printf("\n");
	return 0;
}
