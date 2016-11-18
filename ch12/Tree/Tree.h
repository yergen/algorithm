#ifndef TREE_H
#define TREE_H
#include<iostream>

using namespace std;

template <typename T>
class TreeNode
{
public:
	T key;
	TreeNode<T> *parent;
	TreeNode<T> *left;
	TreeNode<T> *right;
	TreeNode(T value):key(value), parent(NULL), left(NULL), right(NULL){ }
	~TreeNode(){parent = NULL; left = NULL; right = NULL};
};

template <typename T>
class BinaryTree
{
public:
	TreeNode<T> *root;

	bool TreeIsEmpty();											//�������Ƿ�Ϊ��
	void PreorderTreeWalk(TreeNode<T> *root);					//�������
	void InorderTreeWalk(TreeNode<T> *root);					//�������
	void PostorderTreeWalk(TreeNode<T> *root);					//�������
	TreeNode<T> *TreeMinimum(TreeNode<T> *root);					//��С�ؼ���
	TreeNode<T> *TreeMaximum(TreeNode<T> *root);					//���ؼ���
	TreeNode<T> *TreePredecessor(TreeNode<T> *node);			//Ԫ��ǰ��
	TreeNode<T> *TreeSuccessor(TreeNode<T> *node);				//Ԫ�غ��
	TreeNode<T> *TreeSearch(TreeNode<T> *root, T key);			//����
	TreeNode<T> *TreeInsert(TreeNode<T> *root, T key);			//����
	TreeNode<T> *Transplant(TreeNode<T> *root, TreeNode<T> *u, TreeNode<T> *v);//
	TreeNode<T> *TreeDelete(TreeNode<T> *root, T key);//ɾ��
	BinaryTree();
	~BinaryTree();
};

template <typename T>
bool BinaryTree<T>::TreeIsEmpty()										//�������Ƿ�Ϊ��
{
	return root == NULL;
}

template <typename T>
void BinaryTree<T>::PreorderTreeWalk(TreeNode<T> *root)				//�������
{
	if(root != NULL)
	{		
		cout << root-> key << " ";
		PreorderTreeWalk(root -> left);
		PreorderTreeWalk(root -> right);
	}
}

template <typename T>
void BinaryTree<T>::InorderTreeWalk(TreeNode<T> *root)					//�������
{
	if(root != NULL)
	{
		InorderTreeWalk(root -> left);
		cout << root-> key << " ";
		InorderTreeWalk(root -> right);
	}
}

template <typename T>
void BinaryTree<T>::PostorderTreeWalk(TreeNode<T> *root)				//�������
{
	if(root != NULL)
	{
		PostorderTreeWalk(root -> left);
		PostorderTreeWalk(root -> right);
		cout << root-> key << " ";
	}
}

template <typename T>
TreeNode<T> *BinaryTree<T>::TreeMinimum(TreeNode<T> *root)				//��С�ؼ���
{
	TreeNode<T> *p = root;
	while(p -> left != NULL)
		p = p -> left;
	
	return p;
}

template <typename T>
TreeNode<T> *BinaryTree<T>::TreeMaximum(TreeNode<T> *root)				//���ؼ���
{
	TreeNode<T> *p = root;
	while(p -> right != NULL)
		p = p -> right;
	
	return p;
}

template <typename T>
TreeNode<T> *BinaryTree<T>::TreePredecessor(TreeNode<T> *node)			//Ԫ��ǰ��
{
	TreeNode<T> *x, *y;

	if(node -> left != NULL)
		return TreeMaximum(node -> left);

	x = node;
	y = node -> parent;

	while(y != NULL && x == y -> left)
	{
		x = y;
		y = y -> parent;
	}

	return y;
}

template <typename T>
TreeNode<T> *BinaryTree<T>::TreeSuccessor(TreeNode<T> *node)			//Ԫ�غ��
{
	TreeNode<T> *x, *y;

	if(node -> right != NULL)
		return TreeMinimum(node -> right);

	x = node;
	y = node -> parent;

	while(y != NULL && x == y -> right)
	{
		x = y;
		y = y -> parent;
	}

	return y;
}

template <typename T>
TreeNode<T> *BinaryTree<T>::TreeSearch(TreeNode<T> *root, T key)		//����
{
	TreeNode<T> *p = root;
	while(p != NULL && p -> key != key)
	{
		if(key < p -> key)
			p = p -> left;
		else
			p = p -> right;
	}

	return p;
}

template <typename T>
TreeNode<T> *BinaryTree<T>::TreeInsert(TreeNode<T> *root, T key)									 //����
{
	TreeNode<T> *q = new TreeNode<T>(key);
	TreeNode<T> *p = root;
	TreeNode<T> *y = NULL;
	while(p != NULL)
	{
		y = p;
		if(key < p -> key)
			p = p -> left;
		else
			p = p -> right;
	}
	q -> parent = y;
	if(y == NULL)
		root = q;
	else if(key < y -> key)
		y -> left = q;
	else
		y -> right = q;

	return root;
}

template <typename T>
TreeNode<T> *BinaryTree<T>::Transplant(TreeNode<T> *root, TreeNode<T> *u, TreeNode<T> *v)    //
{
	if(u -> parent == NULL)
		root = v;
	else if(u == u -> parent -> left)
		u -> parent -> left = v;
	else
		u -> parent -> right = v;
	if(v != NULL)
		v -> parent = u -> parent;

	return root;
}

template <typename T>
TreeNode<T> *BinaryTree<T>::TreeDelete(TreeNode<T> *root, T key)				//ɾ��
{
	TreeNode<T> *r = root;
	TreeNode<T> *p = TreeSearch(root, key);
	TreeNode<T> *y = NULL;

	if(p == NULL)
		cout << "�����ڹؼ��֣�" << key << endl;
	else if(p -> left == NULL)
		r = Transplant(root, p, p -> right);
	else if(p -> right == NULL)
		r = Transplant(root, p, p -> left);
	else
		{
			y = TreeMinimum(p -> right);
			if(y -> parent != p)
			{
				r = Transplant(root, y, y -> right);
				y -> right = p -> right;
				y -> right -> parent = y;
			}
			Transplant(root, p, y);
			y -> left = p -> left;
			y -> left -> parent = y;
		}

	return r;
}

template <typename T>
BinaryTree<T>::BinaryTree()
{
	root = NULL;
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
	root = NULL;
}
#endif