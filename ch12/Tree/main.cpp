#include<iostream>
#include"Tree.h"

using namespace std;

int main()
{
	int i;
	int A[11] ={3,2,4,13,9,7,6,15,18,20,17};
	BinaryTree<int> r;
	for(i = 0; i < 11; i++)
		r.root = r.TreeInsert(r.root, A[i]);
	r.InorderTreeWalk(r.root);
	r.root = r.TreeDelete(r.root,7);
	cout << endl;
	cout << "查找关键字：15" << " " << r.TreeSearch(r.root,15) -> key << endl;
	if(r.TreeSearch(r.root,7) != NULL)
		cout << "查找关键字：7" << " " << r.TreeSearch(r.root,7)-> key << endl;
	else
		cout << "没有该关键字"<< endl;
	cout << "先序遍历："<< endl;
	r.PreorderTreeWalk(r.root);
	cout << endl;
	cout << "中序遍历："<< endl;
	r.InorderTreeWalk(r.root);
	cout << endl;
	cout << "后序遍历："<< endl;
	r.PostorderTreeWalk(r.root);
	cout << endl;
	system("pause");

	return 0;
}