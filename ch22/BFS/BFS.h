#ifndef BFS_H
#define BFS_H

#include<iostream>
#include<queue>

#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INFINITY 0xFFFF

using namespace std;

queue<int> Q;
//图的数组表示
class Graph{
public:
	int n;
	int color[N+1];
	int d[N+1];
	int pie[N+1];
	int Map[N+1][N+1];

	Graph(int num): n(num)
	{
		memset(Map, 0, sizeof(Map));
	}

	void AddDoubleEdge(int a, int b, int value = 1)
	{
		AddSingleEdge(a, b, value);
		AddSingleEdge(b, a, value);
	}

	void AddSingleEdge(int a, int b, int value = 1)
	{
		Map[a][b] = value;
	}

	void DeleteDoubleEdge(int a, int b)
	{
		DeleteSingleEdge(a, b);
		DeleteSingleEdge(b, a);
	}

	void DeleteSingleEdge(int a, int b)
	{
		Map[a][b] = 0;
	}

	void BFS(int s)
	{
		int u, v;
		for(u = 1; u <= n; u++)
		{
			color[u] = WHITE;
			d[u] = INFINITY;
			pie[u] = NULL;
		}
		color[s] = GRAY;
		d[s] = 0;
		pie[s] = NULL;
		
		while(!Q.empty())
			Q.pop();

		Q.push(s);
		while(!Q.empty())
		{
			u = Q.front();
			Q.pop();
			for(v = 1; v <= n; v++)
			{
				if(Map[u][v] == 0) continue;
				if(color[v] == WHITE)
				{
					color[v] = GRAY;
					d[v] = d[u] + 1;
					pie[v] = u;
					Q.push(v);
				}
			}
			color[u] = BLACK;
		}
	}

	void GPrint(int s, int v) 
	{
		BFS(s);
		if(s == v) 
			cout << s << ' ';
		else
		{
			if(pie[v] == 0)
				cout << "No path from " << s << "to " << v << "exist" << endl;
			else
			{
				GPrint(s, pie[v]);
				cout << v << ' ';
			}
		}
	}
};

#endif