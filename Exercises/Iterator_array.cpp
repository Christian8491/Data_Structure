/* This code implement an iterator for an array. Only print numbers multiples of 4  */

#include <iostream>
using namespace std;

#define MAX_RANDOM 45

/* ========== ITERATOR FOR CMATRIX ========== */
template<typename T>
struct MatrixIterator
{
	MatrixIterator(){}
	inline MatrixIterator(T* p, const int index_, const int width);

	// Overloads
	inline bool operator!=(MatrixIterator<T> iter_);
	inline T operator*();
	inline MatrixIterator<T>& operator++();

	// variables
	int index, size;
	T* ptrCurrent;
};

template<typename T>
inline MatrixIterator<T>::MatrixIterator(T* p, const int index_, const int width)
{
	ptrCurrent = p;
	index = index_;
	size = width;
}

template<typename T>
inline bool MatrixIterator<T>::operator!=(MatrixIterator<T> iter_)
{
	return index != iter_.index;
}

template<typename T>
inline T MatrixIterator<T>::operator*()
{
	return ptrCurrent[index];
}

template<typename T>
inline MatrixIterator<T>& MatrixIterator<T>::operator++()
{
	if (ptrCurrent) {
		index++;
		while (ptrCurrent[index] % 4 != 0 && index < size) index++;
		if (ptrCurrent[index] % 4 == 0) return *this;
	}
}

/* ========== CMATRIX ========== */
template<typename T>
struct CMatrix
{
	int rows, cols;
	T* ptr;

	CMatrix(int num_rows, int num_cols);
	void fillRandom();

	// Iterator
	typedef MatrixIterator<T> iterator;
	inline iterator begin();
	inline iterator end();
};

template<typename T>
inline CMatrix<T>::CMatrix(int num_rows, int num_cols)
{
	rows = num_rows;
	cols = num_cols;
	ptr = new T[rows * cols];
}

template<typename T>
inline void CMatrix<T>::fillRandom()
{
	for (int i = 0; i < rows * cols; ++i) {
		ptr[i] = rand() % MAX_RANDOM;
	}
}

template<typename T>
inline MatrixIterator<T> CMatrix<T>::begin()
{
	int count = 0;
	while (ptr[count] % 4 != 0) count++;
	if (count >= rows * cols) {
		cout << "There is no multiples of 4 " << endl;
		return MatrixIterator<T>(ptr, rows * cols, rows * cols);
	}

	return MatrixIterator<T>(ptr, count, rows * cols);
}

template<typename T>
inline MatrixIterator<T> CMatrix<T>::end()
{
	return MatrixIterator<T>(ptr, rows * cols, rows * cols);
}


int main()
{
	CMatrix<int> m(6, 4);
	m.fillRandom();

	// Iterator
	CMatrix<int>::iterator i;
	for (i = m.begin(); i != m.end(); ++i)
		std::cout << *i << std::endl;

	return 0;
}