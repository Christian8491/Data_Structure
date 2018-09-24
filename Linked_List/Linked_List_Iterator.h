/* This code implements a forward iterator for a Linked List */

#ifndef LINKEDLISTITERATOR_H_INCLUDED
#define LINKEDLISTITERATOR_H_INCLUDED

#include "Node.h"

template<class T>
class LinkedListIterator
{
public:
	Node<T>* ptrNode;
	
	LinkedListIterator(){}
	LinkedListIterator(Node<T>* p){ ptrNode = p; }

	// Overloads
	inline bool operator!=(LinkedListIterator<T> iter_){ return ptrNode != iter_.ptrNode; }
	inline T operator*(){ return ptrNode->data; }
	LinkedListIterator<T>& operator++() 
	{
		if (ptrNode) ptrNode = ptrNode->next;
		return *this;
	}
};

#endif // LINKEDLISTITERATOR_H_INCLUDED