#ifndef seqList_h
#define seqList_h

#include <iostream>
using namespace std;

//线性表抽象类
template <class elemType>
class list
{
public:
	virtual void clear() = 0;
	virtual int length()const = 0;
	virtual void insert(int i, const elemType &x) = 0;
	virtual void remove(int i) = 0;
	virtual int search(const elemType &x)const = 0;
	virtual elemType visit(int i)const = 0;
	virtual void traverse()const = 0;
	virtual ~list() {};
};

class OutOfBound {};
class IllegalSize {};

//顺序表类声明
template <class elemType>class seqList;
//加运算符重载声明
template <class elemType>
seqList<elemType> operator+(const seqList<elemType> &l, const seqList<elemType> &r);
//顺序表类定义
template <class elemType>
class seqList:public list<elemType>
{
	friend seqList<elemType> operator+<>(const seqList<elemType> &, const seqList<elemType> &);//加运算符重载函数作为友元函数的声明
private:
	elemType* data;
	int currentLength;
	int maxSize;
	void doubleSpace();
public:
	seqList(int initSize = 10);
	seqList(const seqList<elemType> &src);//复制构造函数
	~seqList() { delete[] data; }
	void clear() { currentLength = 0; }
	int length()const { return currentLength; }
	void insert(int i, const elemType &x);
	void remove(int i);
	int search(const elemType &x)const;
	elemType visit(int i)const;
	void traverse()const;
	seqList<elemType> & operator=(const seqList<elemType> &);//赋值运算符重载声明
};

template<class elemType>
void seqList<elemType>::doubleSpace()
{
	elemType* tmp = data;
	maxSize *= 2;
	data = new elemType[maxSize];
	for (int i = 0; i < currentLength; i++) { data[i] = tmp[i]; }
	delete[]tmp;
}

template<class elemType>
seqList<elemType>::seqList(int initSize)
{
	if (initSize < 0)throw IllegalSize();
	data = new elemType[initSize];
	maxSize = initSize;
	currentLength = 0;
}

//复制构造函数的定义
template <class elemType>
seqList<elemType>::seqList(const seqList<elemType> &src)
{
	data = new elemType[src.maxSize];
	for (int i = 0; i < src.currentLength; i++) { data[i] = src.data[i]; }
	currentLength = src.currentLength;
	maxSize = src.maxSize;
}

template<class elemType>
void seqList<elemType>::insert(int i, const elemType &x)
{
	if (i<0 || i>currentLength) { throw OutOfBound(); }
	if (currentLength == maxSize) { doubleSpace(); }
	for (int j = currentLength; j > i; j--) { data[j] = data[j - 1]; }
	data[i] = x;
	currentLength++;
}

template<class elemType>
void seqList<elemType>::remove(int i)
{
	if (i < 0 || i >= currentLength) { throw OutOfBound(); }
	for (int j = i; j < currentLength - 1; j++) { data[j] = data[j + 1]; }
	currentLength--;
}

template<class elemType>
int seqList<elemType>::search(const elemType &x) const
{
	for(int i=0;i<currentLength;i++)
	{
		if (data[i] == x)return i;
	}
	return -1;
}

template<class elemType>
elemType seqList<elemType>::visit(int i) const
{
	if (i < 0 || i >= currentLength) { throw OutOfBound(); }
	return data[i];
}

template <class elemType>
void seqList<elemType>::traverse()const
{
	for (int i = 0; i < currentLength; i++) { cout << data[i] << ' '; }
	cout << endl;
}

//加运算符重载函数的定义
template <class elemType>
seqList<elemType> operator+(const seqList<elemType> &l, const seqList<elemType> &r)
{
	seqList<elemType> result(l.maxSize + r.maxSize);
	for (int i = 0; i < l.currentLength; i++) { result.data[i] = l.data[i]; }
	for (int j = 0; j < r.currentLength; j++) { result.data[j + l.currentLength] = r.data[j]; }
	result.currentLength = l.currentLength + r.currentLength;
	return result;
}

//赋值运算符重载函数的定义
template <class elemType>
seqList<elemType>& seqList<elemType>::operator=(const seqList<elemType> &src)
{
	if (this == &src)return *this;

	delete[] data;
	data = new elemType[src.maxSize];
	for (int i = 0; i < src.currentLength; i++) { data[i] = src.data[i]; }
	currentLength = src.currentLength;
	maxSize = src.maxSize;
	return *this;
}
#endif // seqList_h


