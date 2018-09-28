/* This code implements a reverse iterator for a Vector */

#ifndef VECTORREVERSEITERATOR_H_INCLUDED
#define VECTORREVERSEITERATOR_H_INCLUDED

template<class T>
class VectorReverseIterator
{
public:
	VectorReverseIterator(){}
	inline VectorReverseIterator(T* p, const int index_);

	// Overloads
	inline bool operator!=(VectorReverseIterator<T> iter_);
	inline T operator*();
	inline VectorReverseIterator<T>& operator++();

	// variables
	int indice;
	T* ptrCurrent;
};

template<class T>
inline VectorReverseIterator<T>::VectorReverseIterator(T* p, const int index_)
{
	ptrCurrent = p;
	indice = index_;
}

template<class T>
inline bool VectorReverseIterator<T>::operator!=(VectorReverseIterator<T> iter_)
{
	return indice != iter_.indice;
}

template<class T>
inline T VectorReverseIterator<T>::operator*()
{
	return ptrCurrent[indice];
}

template<class T>
inline VectorReverseIterator<T>& VectorReverseIterator<T>::operator++()
{
	if (ptrCurrent) indice--;
	return *this;
}

#endif // VECTORREVERSEITERATOR_H_INCLUDED