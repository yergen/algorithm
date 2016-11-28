#include<iostream>
#include<stack>
#include<queue>

#define TRUE 1
#define FALSE 0

using namespace std;

template<class T>
class BTree//
{
private:
	static const int t = 3;

	struct node{
		bool IsLeaf;
		int n;
		T key[2*t-1];
		node *child[2*t+1];

		node(bool b=TRUE,int _n=0) : IsLeaf(b), n(_n){ }
	};

	node *root;
	int nodenum;

public:
	BTree()
	{
		nodenum = 0;
		BTreeCreate();
	}
	void NodeNum()
	{
		cout << "nodenum: " << nodenum << endl;
	}
	void BTreeInsert(T key)
	{
		node *r = root;
		if(r->n == 2*t -1)
		{
			node *s = AllocateNode();
			root = s;
			s->IsLeaf = FALSE;
			s->n = 0;
			s->child[1] = r;
			BTreeSplitChild(s,1,r);
			BTreeInsertNonfull(s, key);
		}
		else
			BTreeInsertNonfull(r, key);
	}

	void PrintBTree(int kind = 1) const
	{
		queue<node*> myqueue;
		myqueue.push(root);
		int depth = 0;

		while(!myqueue.empty())
		{
			queue<node*> nextlevel;
			cout << "depth :" << depth << endl;
			
			while(!myqueue.empty())
			{
				node *temp = myqueue.front();
				myqueue.pop();

				cout << "[";
				for(int i = 1; i <= temp -> n; i++)
				{
					if(kind == 2)
						cout << (char) temp->key[i] << " ";
					else
						cout << temp->key[i] << " ";
				}
				cout << "]";

				if(!temp->IsLeaf)
					for(int i = 1; i <= temp->n+1; i++)
						nextlevel.push(temp->child[i]);
			}
			cout << endl;
			depth ++;
			myqueue = nextlevel;
		}
	}

	T GetMinimum() const
	{
		return BTreeFindMinimum(root);
	}

	T GetMaximum() const
	{
		return BTreeFindMaximum(root);
	}

	bool search(T key)
	{
		int index = 0;
		node *temp = BTreeSearch(root, key, &index);
		if(temp != nullptr)
			return TRUE;
		else
			return FALSE;
	}

	bool remove(const T &key)
	{
		if(!search(key))
			return FALSE;
		if(root->n == 1 && root->IsLeaf)
		{
			clear();
			return TRUE;
		}

		RecursicveDelete(root, key);
		return TRUE;
	}

	void clear()
	{
		RecursiveClear(root);
		root = nullptr;
	}

	void deletenode(node *node)
	{
		if(node != nullptr)
		{
			delete node;
			node = nullptr;
		}
	}

private:
	node *AllocateNode()
	{
		node *Node = new node();
		nodenum++;

#ifdef DEBUG
		cout << "allocate a new node" << endl;
#endif
		return Node;
	}

	void DiskWrite(node *node) const
	{
#ifdef DEBUG
		cout << "write disk..." << endl;
#endif
	}

	void DiskRead(node *node) const
	{
#ifdef DEBUG
		cout << "read disk..." << endl;
#endif
	}

	void BTreeCreate() 
	{
		root = AllocateNode();
		DiskWrite(root);
	}

	void BTreeSplitChild(node *x, int i, node *y)
	{
		node *z = AllocateNode();
		z->IsLeaf = y->IsLeaf;
		z->n = t -1;

		for(int j = 1; j <= t - 1; j++)
			z->key[j] = y->key[j+t];

		if(!y->IsLeaf)
			for(int j = 1; j <= t; j++)
				z->child[j] = y->child[j+t];
		
		y->n = t -1;

		for(int j=x->n+1; j>=i+1; j--)
			x->child[j+1] = x->child[j];
		x->child[i+1] = z;

		for(int j=x->n; j>=i; j--)
			x->key[j+1] = x->key[j];
		x->key[i] = y->key[t];
		x->n++;

		DiskWrite(y);
		DiskWrite(z);
		DiskWrite(x);
	}

	void BTreeInsertNonfull(node *x, T k)
	{
		int i = x -> n;
		if(x->IsLeaf)
		{
			while(i >= 1 && k < x->key[i])
			{
				x->key[i+1] = x->key[i];
				i--;
			}
			x->key[i+1] = k;
			x->n++;
			DiskWrite(x);
		}
		else
		{
			while(i>=1 && k < x->key[i])
				i--;
			i++;
			DiskRead(x->child[i]);
			if(x->child[i]->n == 2*t - 1)
			{
				BTreeSplitChild(x, i, x->child[i]);
				if(k > x->key[i])
					i++;
			}
			BTreeInsertNonfull(x->child[i], k);
		}
	}

	T BTreeFindMinimum(node *x) const
	{
		if(x == nullptr)
		{
			cerr << "The tree is empty" << endl;
			return -1;
		}
		else if(x->IsLeaf)
		{
			return x->key[1];
		}
		else
		{
			DiskRead(x->child[1]);
			return BTreeFindMinimum(x->child[1]);
		}
	}

	T BTreeFindMaximum(node *x) const
	{
		if(x == nullptr)
		{
			cerr << "The tree is empty" << endl;
			return -1;
		}
		else if(x->IsLeaf)
		{
			return x->key[x->n];
		}
		else
		{
			DiskRead(x->child[x->n+1]);
			return BTreeFindMaximum(x->child[x->n+1]);
		}
	}

	T BTreeFindPredecessor(node *x, int i) 
	{
		if(!x->IsLeaf)
		{
			DiskRead(x->child[i]);
			return BTreeFindMaximum(x->child[i]);
		}
		else if(i > 1)
		{
			return x->key[i-1];
		}
		else//x既是叶子结点，又是第一个关键字
		{
			node *z = x;
			stack<node *> mystack;
			buildpath(root, x->key[i], mystack);

			while(1)
			{
				if(mystack.empty())
				{
					cerr << "NO Predecessor" << endl;
					return -1;
				}

				node *y = mystack.top();
				mystack.pop();
				int j = 1;
				DiskRead(y->child[1]);

				while(y->child[j] != x)
				{
					j++;
					DiskRead(y->child[j]);
				}

				if(j == 1) 
					z = y;
				else 
					return y->key[j-1];
			}
		}
	}

	void buildPath(node *x, T k, stack<node*>& mystack)
	{
		int i = 1;
		while(i <= x->n && k > x->key[i])
			i++;
		if(i <= x->n && k == x -> key[i]) 
			return ;
		if(x->IsLeaf)
			return;
		else
		{
			DiskRead(x->child[i]);
			mystack.push(x);
			buildPath(x->child[i], k, mystack);
		}
	}

	node *BTreeSearch(node *x, T k, int *index)
	{
		int i = 1;
		while(i<=x->n && k > x->key[i])
			i++;
		if(i<=x->n && k == x->key[i])
		{
			*index = i;
			return x;
		}
		else if(x->IsLeaf)
			return nullptr;
		else
		{
			DiskRead(x->child[i]);
			return BTreeSearch(x->child[i], k, index);
		}
	}

	void RecursiveClear(node *node)
	{
		if(node != nullptr)
		{
			if(!node->IsLeaf)
			{
				for(int i = 1; i <=node->n+1;i++)
					RecursiveClear(node->child[i]);
			}
			deletenode(node);
		}
	}

	void RecursicveDelete(node *Node, const T &key)
	{
		int i = 1;
		while(i<=Node->n && key >Node->key[i])
			++i;
		if(i<=Node->n && key == Node->key[i])
		{
			if(Node->IsLeaf)
			{
				Node->n--;
				for(; i<=Node->n; i++)
					Node->key[i] = Node->key[i+1];
				return ;
			}
			else
			{
				node *childPrev = Node->child[i];
				node *childNext = Node->child[i+1];
				if(childPrev->n >= t)
				{
					T PrevKey = GetPredecessor(childPrev);
					RecursicveDelete(childPrev,PrevKey);
					Node->key[i] = PrevKey;
					return ;
				}
				else if(childNext->n >= t)
				{
					T NextKey = GetSuccessor(childNext);
					RecursicveDelete(childNext,NextKey);
					Node->key[i] = NextKey;
					return ;
				}
				else
				{
					MergeChild(Node,i);
					RecursicveDelete(childPrev, key);
				}
			}
		}
		else
		{
			node *childNode = Node->child[i];
			if(childNode->n == t-1)
			{
				node *Left = i > 1 ? Node->child[i-1] : NULL;  //左兄弟节点
                node *Right = i <= Node->n ? Node->child[i+1] : NULL;//右兄弟节点
				int j;
				if(Left && Left->n >= t)
				{
					for(j=childNode->n;j>=1;j--)
						childNode->key[j+1] = childNode->key[j];
					childNode->key[1] = Node->key[i-1];
					
					if(!Left->IsLeaf)
					{
						for(j=childNode->n+1;j>=1;j--)
							childNode->child[j+1] = childNode->child[j];
						childNode->child[1] = Left->child[Left->n+1];//与原程序有区别
					}
					childNode->n++;
					Node->key[i] = Left->key[Left->n];
					Left->n--;
				}
				else if(Right && Right->n >= t)
				{
					childNode->key[childNode->n+1] = Node->key[i];
					childNode->n++;
					Node->key[i] = Right->key[1];
					Right->n--;

					for(j = 1; j <= Right->n; j++)
						Right->key[j] = Right->key[j+1];
					if(!Right->IsLeaf)
					{
						childNode->child[childNode->n+1] = Right->child[1];
						for(j = 1; j <= Right->n+1; j++)
							Right->child[j] = Right->child[j+1];
					}
				}
				else if(Left)
				{
					MergeChild(Node,i-1);
					childNode = Left;
				}
				else if(Right)
					MergeChild(Node,i);
			}
			RecursicveDelete(childNode, key);
		}	
	}

	void MergeChild(node *parent, int index)
	{
		node *child1 = parent -> child[index];
		node *child2 = parent -> child[index+1];

		child1->n = 2*t - 1;
		child1->key[t] = parent->key[index];
		for(int i = 1; i <= t-1; ++i)
			child1->key[t+i] = child2->key[i];
		if(!child1->IsLeaf)
			for(int i = 1; i <= t; ++i)
				child1->child[t+i] = child2->child[i];

		for(int i = index; i < parent->n;++i)
		{
			parent->key[i] = parent->key[i+1];
			parent->child[i+1] = parent->child[i+2]; 
		}
		parent ->n--;
		deletenode(child2);
		if(parent -> n == 0)
			deletenode(parent);

	}

	T GetPredecessor(node *node)
	{
		while(!node->IsLeaf)
			node = node->child[node->n+1];
		return node->key[node->n];
	}

	T GetSuccessor(node *node)
	{
		while(!node->IsLeaf)
			node = node->child[1];
		return node->key[1];
	}

};
int main()
{
	BTree<int> tree;
    
    for(int i = 1;i < 20;i++)
    {
        tree.BTreeInsert(i);
		tree.PrintBTree();
    }

    tree.NodeNum();

    tree.remove(19);
    tree.PrintBTree();
    
	return 0;
}
