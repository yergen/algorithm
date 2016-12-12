#include<iostream>
#include<stack>
using namespace std;

#define N 10
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INFINITY 0x7FFFFFFF

class Edge{
public:
	int start;
	int end;
	Edge *next;//邻接链表的下一个
	int type;
	Edge(int s, int e):start(s), end(e), next(NULL){ }
};

class Vertex{
public:
	int id;
	Edge *head;//以该顶点为起始的下一条边
	Vertex *p;//遍历结果的父结点
	int color;
	int d, f;
	Vertex(int i):head(NULL), p(NULL), color(WHITE), d(INFINITY), id(i){ }
};

stack<Edge*> S;
int time;

class Graph{
public:
	Vertex *V[N+1];
	Graph()
	{
		for(int i=1; i<=N; i++)
			V[i] = new Vertex(i);
	}

	~Graph()
	{
		for(int i=1; i<=N; i++)
			delete V[i];
	}
	void InsertEdge(Graph *G, Edge *E)
	{
		if(G -> V[E->start] -> head == NULL)
			G -> V[E->start] -> head = E;
		else
		{
			Edge *e1 = G -> V[E->start] -> head;
			Edge *e2 = e1;
			while(e1 && e1->end < E->end)
			{
				e2 = e1;
				e1 = e1 -> next;
			}
			if(e1 && e1->end == E->end)//存在此边，返回
				return ;
			if(e1 == e2)
			{
				E -> next = e1;
				G -> V[E->start] -> head = E;
			}
			else
			{
				e2->next = E;
				E ->next = e1;
			}
		}
	}
	void DFS(Graph *G)
	{
		int i;
		for(i=1; i<=N; i++)
		{
			G->V[i]->color = WHITE;
			G->V[i]->p = NULL;
		}
		time = 0;
		for(i=1; i<=N; i++)
		{
			if(G->V[i]->color == WHITE)
				DFSVisit(G, G->V[i]);
		}
	}

	void DFSVisit(Graph *G, Vertex *u)
	{
		time = time + 1;
		u->d = time;
		u->color = GRAY;
		Edge *E = u->head;
		if(E) 
			S.push(E);
		while(!S.empty())
		{
			Edge *e = S.top();
			Vertex *v = G->V[e->end];
			if(v->color == WHITE)
			{
				v->color = GRAY;
				time = time + 1;
				v -> d = time;
				v-> p = u;
				e->type = 1;//???
				if(v->head)
					S.push(v->head);
				else
				{
					while(e && e->next == NULL)
					{
						time++;
						G->V[e->end]->f = time;
						G->V[e->end]->color = BLACK;
						S.pop();
						if(S.empty()) 
							e = NULL;
						else 
							e = S.top();
					}
					if(e && e->next)
						S.push(e->next);
				}
			}
			else
			{
				if(v->color == BLACK)
				{
					if(u->d < v->d)
						e->type = 3;
					else
						e->type = 4;
				}
				else if(v->color == GRAY)
					e->type = 2;

				while(e && e->next == NULL)
				{
					time++;
					G->V[e->start]->f = time;
					G->V[e->start]->color = BLACK;
					S.pop();
					if(S.empty()) 
						e = NULL;
					else 
						e = S.top();
				}
				if(e && e->next)
				{
					S.pop();
					S.push(e->next);
				}
			}
		}
	}

	void Print(Graph *G) const
	{
		for(int i=1; i<=N; i++)
		{
			cout << i << ':';
			Edge *e = G->V[i]->head;
			while(e)
			{
				cout << e->end << ' ';
				e = e -> next;
			}
			cout << endl;
		}
		cout << endl;
	}
};

int main()
{

	return 0;
}