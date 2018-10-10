/* This code implements a Node for Binary Tree */

#ifndef BTNODE_H_INCLUDED
#define BTNODE_H_INCLUDED

template<class T>
struct BTNode
{
	T data;
	BTNode<T>* son[2];
	BTNode(){};
	BTNode(T x) { data = x, son[0] = son[1] = nullptr; }
};

#endif // BTNODE_H_INCLUDED