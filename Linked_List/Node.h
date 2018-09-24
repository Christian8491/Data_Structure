/* This code implements a single Node for a Linked List */

#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

template<class T>
struct Node
{
	T data;
	Node<T>* next;

	Node(T x) { data = x; next = nullptr; }
};

#endif // NODE_H_INCLUDED