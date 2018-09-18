/* This code implements a BINARY TREE without repetitions */

#include <iostream>
using namespace std;

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


/* ============ Node ============ */
template<class T>
struct Node
{
	T data;
	Node<T>* son[2];
	Node(){};
	Node(T x) { data = x, son[0] = son[1] = nullptr; }
};
/* ========== end Node ========== */


/* =========== Binary Tree =========== */
template<class T, class C>
class BTree
{
public:
	Node<T>* root;
	C comparator;

	BTree(){ root = nullptr; }
	bool find(T value, Node<T>** &p);
	bool insert(T value);
	bool remove(T value);
	Node<T>** rep(Node<T>** &p);
};

template<class T, class C>
bool BTree<T, C>::find(T value, Node<T>** &p)
{
	p = &root;
	while (*p && ((*p)->data != value)) {
		p = &((*p)->son[comparator((*p)->data, value)]);
	}
	return !!*p;					// !!*p: dependes of compiler
}

template<class T, class C>
bool BTree<T, C>::insert(T value)
{
	Node<T>** p;
	if (find(value, p)) return 0;
	*p = new Node<T>(value);
	return 1;
}


template<class T, class C>
Node<T>** BTree<T, C>::rep(Node<T>**& p)
{
	Node<T>** t = &((*p)->son[1]);
	while ((*t)->son[0]) {
		t = &((*t)->son[0]);
	}

	return t;
}

template<class T, class C>
bool BTree<T, C>::remove(T value)
{
	Node<T>** p;
	if (!find(value, p)) return 0;
	if ((*p)->son[0] && (*p)->son[1]) {
		Node<T>** q = rep(p);
		(*p)->data = (*q)->data;
		p = q;
	}
	Node<T>* t = *p;
	*p = (*p)->son[!(*p)->son[0]];
	delete t;
	return 1;
}

int main()
{
	BTree<int, Less<int>> binaryTree;

	// Simple insertions
	binaryTree.insert(8);
	binaryTree.insert(4); binaryTree.insert(15);
	binaryTree.insert(2); binaryTree.insert(6); binaryTree.insert(11); binaryTree.insert(18);
	return 0;
}