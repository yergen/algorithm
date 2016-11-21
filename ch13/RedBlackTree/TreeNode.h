#ifndef TREENODE_H
#define TREENODE_H
#include<iostream>
#include"RBTree.h"

#define RED 0
#define BLACK 1

template <typename T>
class RBTree;

template <typename T>
class TreeNode
{
public:
	TreeNode(T key):key(key), color(RED), parent(NULL), left(NULL), right(NULL){ }
	TreeNode():key(-1), color(BLACK), parent(NULL), left(NULL), right(NULL){ }
	~TreeNode(){ }

private:
	friend class RBTree<T>;
	T key;
	bool color;
	TreeNode *parent;
	TreeNode *left;
	TreeNode *right;
};
#endif