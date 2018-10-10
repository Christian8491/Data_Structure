/* This code implements a forward iterator for a Linked List */

#ifndef BINARYTREEITERATOR_H_INCLUDED
#define BINARYTREEITERATOR_H_INCLUDED

#include "BTNode.h"
#include <stack>
using namespace std;

struct InorderSwitch
{
	int pause, left, right, up;
	InorderSwitch() { pause = 1, left = 0, right = 2, up = 3; }
};

template<class T>
class BinaryTreeIterator
{
public:
	stack< pair<BTNode<T>*, int > > stackPair;

	BinaryTreeIterator(){}
	void next(BTNode<T>* ptrNode);

	// Overloads
	inline bool operator!=(BinaryTreeIterator<T> iterator);
	inline BTNode<T>* operator*();
	inline BinaryTreeIterator<T>& operator++();
};

template<class T>
inline bool BinaryTreeIterator<T>::operator!=(BinaryTreeIterator<T> iterator)
{
	return stackPair != iterator.stackPair;
}

template<class T>
inline BTNode<T>* BinaryTreeIterator<T>::operator*()
{
	return stackPair.top().first;
}

template<class T>
inline BinaryTreeIterator<T>& BinaryTreeIterator<T>::operator++()
{
	next(nullptr); 
	return *this;
}

template<class T>
void BinaryTreeIterator<T>::next(BTNode<T>* ptrNode) {
	InorderSwitch inOrder;
	if (ptrNode != nullptr) stackPair.push(make_pair(ptrNode, 0));

	pair<BTNode<T>*, int> pairTemp;

	while (!stackPair.empty()) {
		pairTemp = stackPair.top();

		if (pairTemp.second == 0) {
			if (pairTemp.first->son[0]) {
				stackPair.push(make_pair(pairTemp.first->son[0], 0));
				continue;
			}
			stackPair.top().second++;
			continue;
		}

		if (pairTemp.second == 1) {
			stackPair.top().second++;
			return;
		}

		if (pairTemp.second == 2) {
			if (pairTemp.first->son[1]) {
				stackPair.push(make_pair(pairTemp.first->son[1], 0));
				continue;
			}
			stackPair.top().second++;
			continue;
		}

		if (pairTemp.second == 3) {
			stackPair.pop();
			if (stackPair.empty()) {
				return;
			}
			stackPair.top().second++;
			continue;
		}
	}
}

#endif // BINARYTREEITERATOR_H_INCLUDED