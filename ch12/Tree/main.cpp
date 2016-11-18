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
	cout << "���ҹؼ��֣�15" << " " << r.TreeSearch(r.root,15) -> key << endl;
	if(r.TreeSearch(r.root,7) != NULL)
		cout << "���ҹؼ��֣�7" << " " << r.TreeSearch(r.root,7)-> key << endl;
	else
		cout << "û�иùؼ���"<< endl;
	cout << "���������"<< endl;
	r.PreorderTreeWalk(r.root);
	cout << endl;
	cout << "���������"<< endl;
	r.InorderTreeWalk(r.root);
	cout << endl;
	cout << "���������"<< endl;
	r.PostorderTreeWalk(r.root);
	cout << endl;
	system("pause");

	return 0;
}