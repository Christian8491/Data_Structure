/* This code implements a increasing LINKED LIST with different values */

#include <iostream>
#include "Node.h"
#include "LinkedListIterator.h"


/* ========== Comparators ========== */
template<class T>
struct Less
{
	inline bool operator()(T a, T b) { return a < b; }
};

template<class T>
struct Greater
{
	inline bool operator()(T a, T b) { return a > b; }
};
/* ========== end Comparators ========== */


/* =========== Linked List  =========== */
template<class T, class C>
class LinkedList
{
public:
	Node<T>* head;
	C comparator;

	LinkedList(){ head = nullptr; }
	bool find(T value, Node<T>** &p);
	bool insert(T value);
	bool remove(T value);
	void printList();

	// Iterator
	typedef LinkedListIterator<T> Iterator;
	Iterator begin();
	Iterator end();
};

template<class T, class C>
bool LinkedList<T, C>::find(T value, Node<T>** &p)
{
	p = &head;
	while (*p && comparator((*p)->data, value)) {
		p = &((*p)->next);
	}
	return *p && (*p)->data == value;
}

template<class T, class C>
bool LinkedList<T, C>::insert(T value)
{
	Node<T>** p;
	if (find(value, p)) return 0;
	Node<T>* newNode = new Node<T>(value);
	newNode->next = *p;
	*p = newNode;
	return 1;
}

template<class T, class C>
bool LinkedList<T, C>::remove(T value)
{
	Node<T>** p;
	if (!find(value, p)) return 0;
	Node<T>* temp = *p;
	*p = temp->next;
	delete temp;
	return 1;
}

template<class T, class C>
void LinkedList<T, C>::printList()
{
	Node<T>** p = &head;
	while (*p) {
		std::cout << (*p)->data << " --> ";
		p = &((*p)->next);
	}
}

template<class T, class C>
LinkedListIterator<T> LinkedList<T, C>::begin()
{
	return LinkedListIterator<T>(head);
}

template<class T, class C>
LinkedListIterator<T> LinkedList<T, C>::end()
{
	return LinkedListIterator<T>(nullptr);
}

/* =========== end Linked List  =========== */


int main()
{
	// Insert values
	LinkedList<int, Less<int>> linkedList;
	for (int i = 0; i < 10; ++i) linkedList.insert(i);
	linkedList.printList();

	// Iterator example
	LinkedList<int, Less<int>>::Iterator i;
	for (i = linkedList.begin(); i != linkedList.end(); ++i)
		std::cout << *i << std::endl;

	return 0;
}