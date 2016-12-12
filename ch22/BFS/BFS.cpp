#include"BFS.h"
/* 
Input Data
1 2 
1 5 
2 6 
6 7 
6 3 
3 7 
3 4 
7 8 
7 4 
4 8 
*/
int main()
{
	int i, a, b;
	Graph *G = new Graph(8);
	for(i = 1; i <= 10; i++)
	{
		cin >> a >> b;
		G -> AddDoubleEdge(a, b);
	}

	G -> BFS(2);
	for(i = 1; i <= 8; i++)
	{
		cout << G->d[i] << ' ';
	}
	cout << endl;

	int s, v;  
    while(cin>>s>>v)  
    {  
        G->GPrint(s, v);  
        cout<<endl;  
    }  
    delete G; 

	return 0;
}