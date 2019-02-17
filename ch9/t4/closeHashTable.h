#ifndef closeHashTable_h
#define closeHashTable_h


template <class Type>
class hashTable
{
public:
	virtual bool find(const Type &x)const = 0;
	virtual bool insert(const Type &x) = 0;
	virtual bool remove(const Type &x) = 0;
protected:
	int(*key)(const Type &x);	//取出元素x的键，并转换成整型
	static int defaultKey(const int &k) { return k; } //缺省的转换函数
};

template <class Type>
class closeHashTable: public hashTable<Type>
{
private:
	struct node {
		Type data;
		int state;	//0--empty, 1--active, 2--deleted
		node() { state = 0; }
	};
	node *array;
	int size;
public:
	closeHashTable(int length=101,int(*f)(const Type &x)=defaultKey);
	~closeHashTable() { delete[]array; };
	bool find(const Type &x)const;
	bool insert(const Type &x);
	bool remove(const Type &x);
	void rehash();//整理散列表
};

template<class Type>
closeHashTable<Type>::closeHashTable(int length, int(*f)(const Type &x))
{
	size = length;
	array = new node[size];
	key = f;
}

template<class Type>
bool closeHashTable<Type>::find(const Type & x) const
{
	int initPos, pos;
	initPos = pos = key(x) % size;
	do {
		if (array[pos].state == 0)return false;
		if (array[pos].state == 1 && array[pos].data == x) {
			return true;
		}
		pos = (pos + 1) % size;
	} while (pos != initPos);
	return false;
}

template<class Type>
bool closeHashTable<Type>::insert(const Type & x)
{
	int initPos, pos;
	initPos = pos = key(x) % size;
	do {
		if (array[pos].state != 1) {
			array[pos].data = x;
			array[pos].state = 1;
			return true;
		}
		if (array[pos].state == 1 && array[pos].data == x) return true;
		pos = (pos + 1) % size;//线性探测法
	} while (pos != initPos);
	return false;
}

template<class Type>
bool closeHashTable<Type>::remove(const Type & x)
{
	int initPos, pos;
	initPos = pos = key(x) % size;
	do {
		if (array[pos].state == 0)return false;
		if (array[pos].state == 1 && array[pos].data == x) {
			array[pos].state = 2;
			return true;
		}
		pos = (pos + 1) % size;
	}while(pos != initPos);
	return false;
}

template<class Type>
void closeHashTable<Type>::rehash()
{
	node *tmp = array;
	array = new node[size];
	for (int i = 0; i < size; i++) {
		if (tmp[i] == 1)insert(tmp[i].data);
	}
	delete[] tmp;
}

//散列表元素类型定义：

template <class T>
class matrix_entry;

template <class T>
int getKey(const matrix_entry<T>& entry) {
	return entry.row * 100 + entry.column;
}

template <class T>
class matrix_entry {
	friend int getKey(const matrix_entry<T> &entry);
	friend bool operator==(const matrix_entry<T> &a, const matrix_entry<T> &b) {
		if (a.row == b.row && a.column == b.column) return true;
		else return false;
	}
public:
	matrix_entry(int r, int c, T value) :row(r), column(c), data(value) {}
	matrix_entry() {}

	int row, column;
private:
	T data;
};

#endif // !closeHashTable_h