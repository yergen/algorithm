#include<iostream>
#include<vector>

using namespace std;

class UF{
	
private:
	vector<int> parent;
	vector<int> rank;
	int count;
	int N;

	bool validate(int p){
		return (p > 0 && p <= N);
	}

public:
	UF(int N) : parent(N), rank(N, 0), N(N), count(N)
	{
		for(int i = 0; i < N; i++)
			parent[i] = i;
	}

	int find(int p)
	{
		if(!validate(p))
			return -1;
		while(p != parent[p])
		{
			parent[p] = parent[parent[p]];
			p = parent[p];
		}
		return p;
	}

	int GetCount() const
	{
		return count;
	}

	bool Connected(int p, int q)
	{
		return find(p) == find(q);
	}

	void Union(int p, int q)
	{
		int temp_p = find(p);
		int temp_q = find(q);
		if(temp_p == temp_q) return;

		if(rank[p] < rank[q])
			parent[temp_p] = temp_q;
		else if(rank[p] > rank[q])
			parent[temp_q] = temp_p;
		else
		{
			parent[temp_q] = temp_p;
			rank[temp_p]++;
		}
		count--;
	}

	~UF(){ }
};

int main()
{
	UF uf(5);
	cout << uf.GetCount() << endl;
	cout << uf.Connected(2, 4) << endl;

	uf.Union(1, 2);
	uf.Union(3, 4);
	
	cout << uf.GetCount() << endl;
	uf.Union(1, 3);
	cout << uf.Connected(2, 4) << endl;

	return 0;
}