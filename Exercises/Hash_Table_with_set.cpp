/* This code implemente a hash table with set */
#include <iostream>
#include <set>
#include <vector>

#define BUCKET 991
#define N 5000

using namespace std;

template <class T>
struct Person
{
	T name, ap_pat, ap_mat;
	int index;

	Person(){}
	Person(T nam_, T pat_, T mat_) { name = nam_, ap_pat = pat_, ap_mat = mat_; }
};

template <class T>
struct Distribution
{
	Distribution(){}
	int operator()(T total_name){
		int sum_by_name = 0;
		for (size_t i = 0; i < total_name.length(); ++i) sum_by_name += total_name.c_str()[i];
		return sum_by_name % BUCKET;
	}
};

template <class T, class Function, class Structure>
class CHashTable
{
public:
	CHashTable();
	~CHashTable();
	void insert_item(Structure s);
	int hash_map(Structure s);

private:
	int bucket;
	Function dist_func;
	vector<set<T>> table;

};

template <class T, class Function, class Structure>
CHashTable<T, Function, Structure>::CHashTable()
{
	bucket = BUCKET;
	table.resize(BUCKET);
}

template <class T, class Function, class Structure>
int CHashTable<T, Function, Structure>::hash_map(Structure s)
{
	string total_name = s.name + s.ap_pat + s.ap_mat;
	int sum_by_name = 0;
	for (size_t i = 0; i < total_name.length(); ++i) sum_by_name += total_name.c_str()[i];
	return sum_by_name % BUCKET;
}

template <class T, class Function, class Structure>
void CHashTable<T, Function, Structure>::insert_item(Structure s)
{
	T total_name = s.name + s.ap_pat + s.ap_mat;
	int index = dist_func(total_name);
	set<T>::iterator it = table[index].begin();

	table[index].insert(it, total_name);
}

template <class T, class Function, class Structure>
CHashTable<T, Function, Structure>::~CHashTable()
{
	for (int i = 0; i < BUCKET; ++i) {
		if (table[i].size() > 0) {
			table[i].erase(table[i].begin(), table[i].end());
		}
	}

	table.erase(table.begin(), table.begin() + BUCKET);
}

int main()
{
	vector<Person<string>> persons(N);
	persons[0].name = "Marcos", persons[0].ap_pat = "Rodriguez", persons[0].ap_mat = "Lopez";
	persons[1].name = "Julian", persons[1].ap_pat = "Estrada", persons[1].ap_mat = "Sanchez";

	CHashTable<string, Distribution<string>, Person<string>> hash_table;
	hash_table.insert_item(persons[0]);
	hash_table.insert_item(persons[1]);

	return 0;
}