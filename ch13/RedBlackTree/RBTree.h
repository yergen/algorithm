#ifndef RBTREE_H
#define RBTREE_H
#include<iostream>
#include"TreeNode.h"

template <typename T>
class RBTree
{
public:
	void LeftRotate(RBTree<T> *r, TreeNode<T> *x);  //结点左旋
	void RightRotate(RBTree<T> *r, TreeNode<T> *y); //结点右旋
	void RBInsert(RBTree<T> *r, T key);      //插入关键字
	TreeNode<T> *RBSearch(RBTree<T> *r, T key);//查找关键字
	TreeNode<T> *RBMinimum(RBTree<T> *r);//最小值
	TreeNode<T> *RBMaximum(RBTree<T> *r);//最大值
	void RBInsertFixup(RBTree<T> *r, TreeNode<T> *z);//保持红黑性质
	void RBTransplant(RBTree<T> *r, TreeNode<T> *u, TreeNode<T> *v);
	void RBDelete(RBTree<T> *r, T key);    //删除关键字
	void RBDeleteFixup(RBTree<T> *r, TreeNode<T> *x);
	RBTree(){ };
	~RBTree(){ };
private:

	TreeNode<T> *root;
	TreeNode<T> *NIL;
};

template <typename T>
void RBTree<T>::LeftRotate(RBTree<T> *r, TreeNode<T> *x)  //结点左旋
{
	TreeNode<T> *y;
	if(x -> right == r -> NIL)
	{
		cout << "不能左旋!" << endl;
		return ;
	}

	y = x -> right;//set y
	x -> right = y -> left; //turn y's left subtree into x's right subtree
	if(y -> left != r -> NIL)
		y -> left -> parent = x;
	y -> parent = x -> parent;//link x's parent to y
	if(x -> parent == r -> NIL)
		r -> root = y;
	else if(x == x -> parent -> left)
		x -> parent -> left = y;
	else if(x = x -> parent -> right)
		x -> parent -> right = y;
	y -> left = x;     //put x on y's left
	x -> parent = y;

}

template <typename T>
void RBTree<T>::RightRotate(RBTree<T> *r, TreeNode<T> *y) //结点右旋
{
	TreeNode<T> *x;
	if(y -> left == r -> NIL)
	{
		cout << "不能右旋!" << endl;
		return ;
	}
	x = y -> left;//set x
	y -> left = x -> right; //turn x's righ subtree into y's left subtree
	if(x -> right != r -> NIL)
		x -> right -> parent = y;
	x -> parent = y -> parent;//link y's parent to x
	if(y -> parent == r -> NIL)
		r -> root = x;
	else if(y == y -> parent -> left)
		y -> parent -> left = x;
	else if(y = y -> parent -> right)
		y -> parent -> right = x;
	x -> right = y;     //put y on x's right
	y -> parent = x;

}

template <typename T>
void RBTree<T>::RBInsert(RBTree<T> *r, T key)      //插入关键字
{
	TreeNode<T> *q = new TreeNode<T>(key);
	TreeNode<T> *p = r -> root;
	TreeNode<T> *y = r -> NIL;

	while(p != NIL)
	{
		y = p;
		if(q -> key < p -> key)
			p = p -> left;
		else
			p = p -> right;
	}
	q -> parent = y;
	if(y == r -> NIL)
		r -> root = q;
	else if(q -> key < y -> key)
		y -> left = q;
	else 
		y -> right = q;
	q -> left = r -> NIL;
	q -> right = r -> NIL;
	q -> color = RED;

	RBInsertFixup(r, q);
}

template <typename T>
TreeNode<T> *RBTree<T>::RBSearch(RBTree<T> *r, T key)          //查找关键字
{
	TreeNode<T> *p = r -> root;
	while(p != r -> NIL && p -> key != key)
	{
		if(key < p -> key)
			p = p -> left;
		else
			p = p -> right;
	}

	return p;
}

template <typename T>
TreeNode<T> *RBTree<T>::RBMinimum(RBTree<T> *r)             //最小值
{
	TreeNode<T> *p = r -> root;
	while(p -> left != r -> NIL)
		p = p -> left;

	return p;
}

template <typename T>
TreeNode<T> *RBTree<T>::RBMaximum(RBTree<T> *r)             //最大值
{
	TreeNode<T> *p = r -> root;
	while(p -> right != r -> NIL)
		p = p -> right;

	return p;
}

template <typename T>
void RBTree<T>::RBInsertFixup(RBTree<T> *r, TreeNode<T> *z)//保持红黑性质
{
	TreeNode<T> *y;
	while(z -> parent -> color == RED)
	{
		if(z ->	parent == z -> parent -> parent -> left)
		{
			y = z -> parent -> parent -> right;
			if(y -> color == RED)
			{
				z -> parent -> color = BLACK;
				y -> color = BLACK;
				z -> parent -> parent = RED;
				z = z -> parent -> parent;
			}
			else if(z == z -> parent -> right)
			{
				z = z -> parent;
				LeftRotate(r, z);
			}
			z -> parent -> color = BLACK;
			z -> parent -> parent = RED;
			RightRotate(r, z -> parent -> parent);
		}
		else
		{
			y = z -> parent -> parent -> left;
			if(y -> color == RED)
			{
				z -> parent -> color = BLACK;
				y -> color = BLACK;
				z -> parent -> parent = RED;
				z = z -> parent -> parent;
			}
			else if(z == z -> parent -> left)
			{
				z = z -> parent;
				RightRotate(r, z);
			}
			z -> parent -> color = BLACK;
			z -> parent -> parent = RED;
			LeftRotate(r, z -> parent -> parent);
		}
	}
	r -> root -> color = BLACK;
}

template <typename T>
void RBTree<T>::RBTransplant(RBTree<T> *r, TreeNode<T> *u, TreeNode<T> *v)
{
	if(u -> parent == r -> NIL) 
		r -> root = v;
	else if(u == u -> parent -> left)
		u -> parent -> left = v;
	else
		u -> parent -> right = v;
	v -> parent = u -> parent;
}

template <typename T>
void RBTree<T>::RBDelete(RBTree<T> *r, T key)    //删除关键字
{
	TreeNode<T> *x;
	TreeNode<T> *z = RBSearch(r, key);
	if(z == r -> NIL)
	{
		cout << "没有要删除的关键字：" << key << endl;
		return ;
	}
	TreeNode<T> *y = z;//其实没必要再声明y，可以直接用z.
	bool y_original_color = y -> color;
	if(z -> left == r -> NIL)
	{
		x = z -> right;
		RBTransplant(r, z, z -> right);
	}
	else if(z -> right == r -> NIL)
	{
		x = z -> left;
		RBTransplant(r, z, z -> left);
	}
	else
	{
		y = RBMinimum(r, z -> right);
		y_original_color = y -> color;
		x = y -> right;
		if(y -> parent == z)
			x -> parent = y;
		else
		{
			RBTransplant(r, y, y -> right);
			y -> right = z -> right;
			y -> right -> parent = y;
		}
		RBTransplant(r, z, y);
		y -> left = z -> left;
		y -> left -> parent = y;
		y -> color = z -> color;
	}
	if(y_original_color == BLACK)
		RBDeleteFixup(r, x);
}

template <typename T>
void RBTree<T>::RBDeleteFixup(RBTree<T> *r, TreeNode<T> *x)
{
	TreeNode<T> *w;
	while(x != r -> root && x -> color == BLACK)
	{
		if(x == x -> parent -> left)
		{
			w = x -> parent -> right;
			if(w -> color == RED)
			{
				w -> color = BLACK;
				x -> parent -> color = RED;
				LeftRotate(r, x -> parent);
				w = x -> parent -> right;
			}
			if(w -> left -> color == BLACK && w -> right -> color == BLACK)
			{
				w -> color = RED;
				x = x -> parent;
			}
			else
			{
				if(w ->right -> color == BLACK)
				{
					w -> left -> color = BLACK;
					w -> color = RED;
					RightRotate(r, w);
					w = x -> parent -> right; 
				}
				w -> color = x -> parent -> color;
				x -> parent -> color = BLACK;
				w -> right -> color = BLACK;
				LeftRotate(r, x -> parent);
				x = r -> root;
			}
		}
		else
		{
			w = x -> parent -> left;
			if(w -> color == RED)
			{
				w -> color = BLACK;
				x -> parent -> color = RED;
				RightRotate(r, x -> parent);
				w = x -> parent -> left;
			}
			if(w -> left -> color == BLACK && w -> right -> color == BLACK)
			{
				w -> color = RED;
				x = x -> parent;
			}
			else
			{
				if(w ->left -> color == BLACK)
				{
					w -> right -> color = BLACK;
					w -> color = RED;
					LeftRotate(r, w);
					w = x -> parent -> left; 
				}
				w -> color = x -> parent -> color;
				x -> parent -> color = BLACK;
				w -> left -> color = BLACK;
				RightRotate(r, x -> parent);
				x = r -> root;
			}
		}
	}
	x -> color = BLACK;
}

template <typename T>
RBTree<T>::RBTree()
{ 
	TreeNode<T> *x = new TreeNode<T>();
	NIL = x;
	root = NIL;
}

#endif