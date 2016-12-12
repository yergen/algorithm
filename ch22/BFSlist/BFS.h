#ifndef BFS_H
#define BFS_H
#include<iostream>
#include<queue>
using namespace std;

#define N 100  
#define WHITE 0  
#define GRAY 1  
#define BLACK 2 

queue<int> Q;
struct Edge{
	int start;
	int end;
	int value;
	Edge *next;
	Edge(int s, int e, int v) : start(s), end(e), value(v), next(NULL){ }
};
struct Vertex{
	int color;
	int d;
	int pie;
	Edge *head;
	Vertex() : color(WHITE), d(0xffff), pie(NULL), head(NULL){ }
};
class Link_Graph{
public:
	int n;
	Vertex *V;
	Link_Graph(int num):n(num)
	{
		V = new Vertex[n+1];
	}
	~Link_Graph(){delete []V;}

	void AddSingleEdge(int a, int b, int value = 1)
	{
		Edge *NewEdge = new Edge(a, b, value);
		if(V[a].head == NULL || V[a].head -> end > b)//没有任何边
		{
			NewEdge->next = V[a].head;
			V[a].head = NewEdge;
		}
		else
		{
			Edge *e = V[a].head, *pre = e;//e, pre指针都指向邻接链表的开头
			while(e != NULL && e->end < b)//找到新边要插入的位置
			{
				pre = e;
				e = e -> next;
			}
			if(e && e->end == b)//如果含有此边
			{
				delete NewEdge;
				return;
			}
			NewEdge->next = e;//按结束点大小排序
			pre -> next = NewEdge;	
		}
	}

	void AddDoubleEdge(int a, int b, int value = 1)
	{
		AddSingleEdge(a, b, value);
		AddSingleEdge(b, a, value);
	}

	void DeleteSingleEdge(int a, int b)
	{
		Edge *e = V[a].head, *pre = e;
		while(e && e->end < b)
		{
			pre = e;
			e = e -> next;
		}
		if(e == NULL || e -> end > b) return;
		if(e == V[a].head)
			V[a].head = e -> next;
		else
			pre -> next = e -> next;
	}

	void DeleteDoubleEdge(int a, int b)
	{
		DeleteSingleEdge(a, b);
		DeleteSingleEdge(b, a);
	}

	void BFS(int s)
	{
		int i;
		for(i=1; i<=n; i++)
		{
			V[i].color = WHITE;
			V[i].d = 0x7fffffff;
			V[i].pie = NULL;
		}
		V[s].color = GRAY;
		V[s].d = 0;
		V[s].pie = NULL;
		while(!Q.empty()) Q.pop();
		Q.push(s);
		while(!Q.empty())
		{
			int u, v;
			u = Q.front();
			Q.pop();
			Edge *e = V[u].head; 
			while(e)
			{
				v = e -> end;
				if(V[v].color == WHITE)
				{
					V[v].color = GRAY;
					V[v].d = V[u].d + 1;
					V[v].pie = u;
					Q.push(v);
				}
				e = e -> next;
			}
			V[u].color = BLACK;
		}
	}

	void Print(int s, int v)
	{
		BFS(s);
		if(v == s)
			cout << s << ' ';
		else
		{
			if(V[v].pie == NULL)
				cout << "No path from" << s << "to" << v << "exist" << endl;
			else
			{
				Print(s, V[v].pie);
				cout << v << ' ';
			}
		}
	}
};
#endif