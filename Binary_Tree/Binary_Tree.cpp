/* This code implements a BINARY TREE without repetitions */

#include <iostream>
#include "BinaryTreeIterator.h"
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


/* =========== Binary Tree =========== */
template<class T, class C>
class BTree
{
public:
	BTNode<T>* root;
	C comparator;

	BTree(){ root = nullptr; }
	bool find(T value, BTNode<T>** &p);
	bool insert(T value);
	bool remove(T value);
	BTNode<T>** rep(BTNode<T>** &p);

	// Iterators
	typedef BinaryTreeIterator<T> inorder_iterator;
	inorder_iterator begin();
	inorder_iterator end();

};

template<class T, class C>
bool BTree<T, C>::find(T value, BTNode<T>** &p)
{
	p = &root;
	while (*p && ((*p)->data != value)) {
		p = &((*p)->son[comparator((*p)->data, value)]);
	}
	return !!*p;					// !!*p: depends of compiler
}

template<class T, class C>
bool BTree<T, C>::insert(T value)
{
	BTNode<T>** p;
	if (find(value, p)) return 0;
	*p = new BTNode<T>(value);
	return 1;
}

template<class T, class C>
BTNode<T>** BTree<T, C>::rep(BTNode<T>**& p)
{
	BTNode<T>** t = &((*p)->son[1]);
	while ((*t)->son[0]) {
		t = &((*t)->son[0]);
	}
	return t;
}

template<class T, class C>
bool BTree<T, C>::remove(T value)
{
	BTNode<T>** p;
	if (!find(value, p)) return 0;
	if ((*p)->son[0] && (*p)->son[1]) {
		BTNode<T>** q = rep(p);
		(*p)->data = (*q)->data;
		p = q;
	}
	BTNode<T>* t = *p;
	*p = (*p)->son[!(*p)->son[0]];
	delete t;
	return 1;
}

template<class T, class C>
BinaryTreeIterator<T> BTree<T, C>::begin()
{
	BinaryTreeIterator<T> inIterator;
	inIterator.next(root);
	return inIterator;
}

template<class T, class C>
BinaryTreeIterator<T> BTree<T, C>::end()
{
	BinaryTreeIterator<T> inIterator;
	inIterator.next(nullptr);
	return inIterator;
}

int main()
{
	BTree<int, Less<int>> binaryTree;

	// Simple insertions
	int values[7] = { 8, 4, 15, 2, 6, 11, 18 };
	for (int i = 0; i < 7; ++i) binaryTree.insert(values[i]);

	// Iterator example
	BTree<int, Less<int>>::inorder_iterator i;
	for (i = binaryTree.begin(); i != binaryTree.end(); ++i)
		cout << (*i)->data << " ";

	return 0;
}