/* This code implements a VECTOR */

#include <iostream>
#include "VectorIterator.h"
#include "VectorReverseITerator.h"

/* =========== Linked List  =========== */
template<class T>
class Vector
{
public:
	int size;
	T* ptr;

	inline Vector();
	inline Vector(const int n);
	inline ~Vector();

	inline T& operator[](const int index);

	typedef VectorIterator<T> iterator;
	inline iterator begin();
	inline iterator end();

	typedef VectorReverseIterator<T> reverse_iterator;
	inline reverse_iterator rbegin();
	inline reverse_iterator rend();
};

template<class T>
inline Vector<T>::Vector()
{
	size = 0;
	ptr = nullptr;
}

template<class T>
inline Vector<T>::Vector(const int n)
{
	size = n;
	ptr = new T[size];
}

template<class T>
inline Vector<T>::~Vector()
{
	delete[] ptr;
}

template<class T>
inline T& Vector<T>::operator[](const int index)
{
	return ptr[index];
}

template<class T>
inline VectorIterator<T> Vector<T>::begin()
{
	return VectorIterator<T>(ptr, 0);
}

template<class T>
inline VectorIterator<T> Vector<T>::end()
{
	return VectorIterator<T>(ptr, size);
}

template<class T>
inline VectorReverseIterator<T> Vector<T>::rbegin()
{
	return VectorReverseIterator<T>(ptr, size - 1);
}

template<class T>
inline VectorReverseIterator<T> Vector<T>::rend()
{
	return VectorReverseIterator<T>(ptr, -1);
}
/* =========== end Vector =========== */


int main()
{
	// Insert values
	Vector<int> myVector(10);
	for (int i = 0; i < 10; ++i) myVector[i] = i;

	// Iterator example
	Vector<int>::iterator i;
	for (i = myVector.begin(); i != myVector.end(); ++i)
		std::cout << *i << std::endl;

	std::cout << std::endl;

	// Reverse Iterator example
	Vector<int>::reverse_iterator r;
	for (r = myVector.rbegin(); r != myVector.rend(); ++r)
		std::cout << *r << std::endl;

	return 0;
}