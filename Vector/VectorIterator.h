/* This code implements a forward iterator for a Vector */

#ifndef VECTORITERATOR_H_INCLUDED
#define VECTORITERATOR_H_INCLUDED

template<class T>
class VectorIterator
{
public:
	VectorIterator(){}
	inline VectorIterator(T* p, const int index_);

	// Overloads
	inline bool operator!=(VectorIterator<T> iter_);
	inline T operator*();
	inline VectorIterator<T>& operator++();

	// variables
	int indice;
	T* ptrCurrent;
};

template<class T>
inline VectorIterator<T>::VectorIterator(T* p, const int index_)
{
	ptrCurrent = p;
	indice = index_;
}

template<class T>
inline bool VectorIterator<T>::operator!=(VectorIterator<T> iter_)
{
	return indice != iter_.indice;
}

template<class T>
inline T VectorIterator<T>::operator*()
{
	return ptrCurrent[indice];
}

template<class T>
inline VectorIterator<T>& VectorIterator<T>::operator++()
{
	if (ptrCurrent) indice++;
	return *this;
}

#endif // VECTORITERATOR_H_INCLUDED