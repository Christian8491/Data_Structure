/* This code implements a VECTOR and use a vector iterator */

#include <iostream>
#include "VectorIterator.h"

/* =========== Vector  =========== */
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

	typedef VectorIterator<T> Iterator;
	inline Iterator begin();
	inline Iterator end();

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
/* =========== end Vector =========== */


int main()
{
	// Insert values
	Vector<int> myVector(10);
	for (int i = 0; i < 10; ++i) myVector[i] = i;

	// Iterator example
	Vector<int>::Iterator i;
	for (i = myVector.begin(); i != myVector.end(); ++i)
		std::cout << *i << std::endl;
	return 0;
}