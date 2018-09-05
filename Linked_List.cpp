/* This code implements a Linked List */

#include <iostream>


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

	CNode(T x) { data = x; next = nullptr; }
};
/* ========== end CNode ========== */


/* =========== Linked List  =========== */
template<class T, class C>
class CList
{
public:
	CNode<T>* head;
	C comparator;

	CList(){ head = nullptr; }
	bool find(T value, CNode<T>** &p);
	bool insert(T value);
	bool remove(T value);
	void printList();
};

template<class T, class C>
bool CList<T, C>::find(T value, CNode<T>** &p)
{	
	p = &head;
	while (*p && comparator((*p)->data, value)) {
		p = &((*p)->next);
	}
	return *p && (*p)->data == value;
}


template<class T, class C>
bool CList<T, C>::insert(T value)
{
	CNode<T>** p;
	if (find(value, p)) return 0;
	CNode<T>* newNode = new CNode<T>(value);
	newNode->next = *p;
	*p = newNode;
	return 1;
}

template<class T, class C>
bool CList<T, C>::remove(T value)
{
	CNode<T>** p;
	if (!find(value, p)) return 0;
	CNode<T>* temp = *p;
	*p = temp->next;
	delete temp;
	return 1;
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
/* =========== end Linked List  =========== */


int main()
{
	CList<int, CLess<int>> linkedList;

	for (int i = 0; i < 10; ++i) linkedList.insert(i);
	
	linkedList.printList();

	linkedList.remove(5);

	std::cout << "\n";
	linkedList.printList();

	return 0;
}