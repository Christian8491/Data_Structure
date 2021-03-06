/* This code implements a double LINKED LIST ordered with repetitions */

#include <iostream>
using namespace std;

/* ========== Comparators ========== */
template<class T>
struct CLess
{
	inline bool operator()(T a, T b) { return a < b; }
};

template<class T>
struct CGreater
{
	inline bool operator()(T a, T b) { return a > b; }
};
/* ========== end Comparators ========== */


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
template<class T, class C>
class CList
{
public:
	CNode<T>* head;
	CNode<T>* tail;
	C comparator;

	CList(){ head = nullptr;  tail = nullptr; }
	bool find(T value, CNode<T>** &p, CNode<T>** &t);
	void insert(T value);
	void remove(T value);
	void printList();
	void printListReverse();
};

template<class T, class C>
bool CList<T, C>::find(T value, CNode<T>** &p, CNode<T>** &t)
{
	p = &head;
	t = &tail;
	while (*p && ((*p)->data < value)) {
		p = &((*p)->next);
	}

	while (*t && ((*t)->data > value)) {
		t = &((*t)->previous);
	}

	return (*p) && (*t) && (*p)->data == value;
}


template<class T, class C>
void CList<T, C>::insert(T value)
{
	CNode<T>** p;
	CNode<T>** t;
	find(value, p, t);

	CNode<T>* newNode = new CNode<T>(value);
	newNode->next = *p;
	newNode->previous = *t;

	*p = newNode;
	*t = newNode;
}

template<class T, class C>
void CList<T, C>::remove(T value)
{
	CNode<T>** p;
	CNode<T>** t;
	if (!find(value, p, t)) return;

	CNode<T>* temp = *p;
	*p = temp->next;
	*t = temp->previous;
	delete temp;
}

template<class T, class C>
void CList<T, C>::printList()
{
	CNode<T>** p = &head;
	while (*p) {
		std::cout << (*p)->data << " --> ";
		p = &((*p)->next);
	}
}

template<class T, class C>
void CList<T, C>::printListReverse()
{
	CNode<T>** t = &tail;
	while (*t) {
		std::cout << (*t)->data << " --> ";
		t = &((*t)->previous);
	}
}
/* =========== end Linked List  =========== */


int main()
{
	CList<int, CLess<int>> linkedList;

	for (int i = 0; i < 10; ++i) linkedList.insert(i);

	linkedList.printList();
	cout << "\n";
	linkedList.printListReverse();

	return 0;
}