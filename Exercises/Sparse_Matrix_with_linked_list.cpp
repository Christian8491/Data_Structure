/* This code implement an sparse matrix with linked list */
#include <iostream>
#include <vector>

using namespace std;

template<class T>
struct Node
{
	T value;
	int x_pos, y_pos;
	Node<T>* right_ptr, *bottom_ptr;

	Node(int x, int y, T val) { value = val; right_ptr = bottom_ptr = nullptr; x_pos = x; y_pos = y; }
};

template<class T>
struct LinkedList
{
	Node<T>* head;

	LinkedList(){ head = nullptr; }
	bool find(T value, Node<T>** &p);
	bool insert(T value);
	bool remove(T value);
};

template <class T>
struct CSMatrix
{
	vector<LinkedList<T>> vector_horizontal, vector_vertical;

	CSMatrix() {}
	CSMatrix(int rows, int cols)
	{
		vector_horizontal.resize(rows);
		vector_vertical.resize(cols);

		for (int i = 0; i < rows; ++i) vector_horizontal[i].head = nullptr;
		for (int i = 0; i < cols; ++i) vector_vertical[i].head = nullptr;
	}

	bool find(int x, int y, Node<T>**&p, Node<T>**& q);
	bool insert(int pos_row, int pos_col, T val);
	bool remove(int pos_row, int pos_col);
	void print_sparse_matrix();
};

template <class T>
bool CSMatrix<T>::find(int x, int y, Node<T>**&x_head, Node<T>**& y_head)
{
	while (*x_head && (*x_head)->y_pos < y) x_head = &((*x_head)->bottom_ptr);
	while (*y_head && (*y_head)->x_pos < x) y_head = &((*y_head)->right_ptr);

	return *x_head && (*x_head)->y_pos == y;
}

template <class T>
bool CSMatrix<T>::insert(int x, int y, T val)
{
	if (vector_horizontal.size() < x || vector_vertical.size() < y) return 0;

	Node<T>** x_head = &(vector_horizontal[x].head);
	Node<T>** y_head = &(vector_vertical[y].head);

	if (find(x, y, x_head, y_head)) {
		(*x_head)->value = val;			// set
		return 1;
	}

	Node<T>* newNode = new Node<T>(x, y, val);

	newNode->bottom_ptr = *x_head;
	*x_head = newNode;

	newNode->right_ptr = *y_head;
	*y_head = newNode;

	return 1;
}

template <class T>
bool CSMatrix<T>::remove(int x, int y)
{
	Node<T>** x_head = &(vector_horizontal[x].head);
	Node<T>** y_head = &(vector_vertical[y].head);

	if (!find(x, y, x_head, y_head)) return 0;

	Node<T>* temp = *x_head;
	*x_head = temp->bottom_ptr;
	*y_head = temp->right_ptr;

	delete temp;
	return 1;
}

template <class T>
void CSMatrix<T>::print_sparse_matrix()
{
	Node<T>* y_head;
	for (size_t j = 0; j < vector_horizontal.size(); ++j) {
		y_head = vector_vertical[j].head;
		if (y_head) {
			for (size_t i = 0; i < vector_horizontal.size(); ++i) {
				if (y_head && y_head->x_pos == i) {
					cout << y_head->value << "\t";
					y_head = y_head->right_ptr;
				}
				else cout << "--\t";
			}
		}
		cout << endl;
	}
}

int main()
{
	CSMatrix<int> matrix(4, 4);

	matrix.insert(0, 0, 2), matrix.insert(0, 3, 8), matrix.insert(3, 3, 4);
	matrix.insert(0, 2, 4), matrix.insert(1, 2, 6), matrix.insert(2, 1, 0);
	matrix.insert(2, 2, -2), matrix.insert(2, 0, -5), matrix.insert(0, 0, 90);
	matrix.insert(6, 2, -2);
	matrix.remove(0, 3), matrix.remove(0, 0);

	matrix.print_sparse_matrix();

	return 0;
}