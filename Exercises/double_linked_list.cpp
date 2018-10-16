/* This code implements a double LINKED LIST with random values and with repetitions */

#include <iostream>
#include <stdlib.h>
using namespace std;

/* ========== CNode ========== */
template<class T>
struct CNode
{
	T data;
	CNode<T>* next;
	CNode<T>* previous;
	CNode(){};
	CNode(T x) { data = x; next = nullptr; previous = nullptr; }
};
/* ========== end CNode ========== */

/* =========== Linked List  =========== */
template<class T>
class CList
{
public:
	CNode<T>* head;
	CNode<T>* tail;

	CList(){ head = nullptr;  tail = nullptr; }
	bool find(T value, CNode<T>** &p);
	void insert(T value);
	void remove(T value);
	void printList();
};

template<class T>
void CList<T>::insert(T value)
{
	CNode<T>** p = &head;
	CNode<T>** t = &tail;

	while (*p) p = &((*p)->next);
	if (*p && (*p)->data == value) return;

	CNode<T>* newNode = new CNode<T>(value);
	newNode->next = *p;
	newNode->previous = *t;

	*p = newNode;
	*t = newNode;
}

template<class T>
bool CList<T>::find(T value, CNode<T>** &p)
{
	p = &head;
	while (*p && ((*p)->data != value)) p = &((*p)->next);
	return (*p) && (*p)->data == value;
}

template<class T>
void CList<T>::remove(T value)
{
	CNode<T>** p;
	if (!find(value, p)) return;

	while (find(value, p)) {
		CNode<T>* temp = *p;
		CNode<T>* temp_next = (*p)->next;
		*p = temp->next;
		if (temp->next == nullptr) tail = temp->previous;
		else temp_next->previous = temp->previous;
		delete temp;
	}
}

template<class T>
void CList<T>::printList()
{
	CNode<T>** p = &head;
	while (*p) {
		std::cout << (*p)->data << " --> ";
		p = &((*p)->next);
	}
}
/* =========== end Linked List  =========== */


int main()
{
	// Create a linked list with random values
	CList<int> linkedList;
	for (int i = 0; i < 12; ++i) linkedList.insert(rand() % 8);
	linkedList.printList();

	// Delete some nodes
	std::cout << std::endl;
	linkedList.remove(6); linkedList.remove(1); linkedList.remove(0);
	linkedList.printList();

	return 0;
}