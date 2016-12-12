#include <iostream>  
#include "BFS.h"  
using namespace std;  
/* 
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
    Link_Graph *G = new Link_Graph(8);  
    int i = 0, a, b;  
    for(i = 1; i <= 10; i++)  
    {  
		cout << "Please Input a, b: ";
        cin>>a>>b;  
        G->AddDoubleEdge(a,b);  
    }  
    G->BFS(2);  
    for(i = 1; i <= 8; i++)  
        cout<<G->V[i].d<<' ';  
    cout<<endl;  
    int s, v;  
    while(cin>>s>>v)  
    {  
        G->Print(s, v);  
        cout<<endl;  
    }  
    return 0;  
}