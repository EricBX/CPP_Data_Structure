#ifndef linkList_h
#define linkList_h

#include <stdlib.h>
#include <iostream>
using namespace std;

template<class T>
class linkList
{
private:
	struct node {												//内嵌节点类**
		T value;
		node* next;

		node() :next(NULL) {}									//节点类默认构造函数**
		node(const T &v, node *n = NULL) :value(v), next(n) {}
	};

	node *head;													//链表头结点**
	int size;													//链表长度**

protected:							
	node *get(int i)const										//获得i位置结点指针**
	{
		if (i >= size) { cerr << "out of bound!" << endl; return head; }
		if (i < 0) return head;
		node *p = head->next;
		for (int j = 0; j < i; ++j) p = p->next;

		return p;
	}

public:
	linkList() :size(0)										//链表默认构造函数**
	{
		head = new node;
	}

	~linkList() {												//析构函数**
		clear();
		delete head;
	}

	void clear()												//清空链表**
	{
		while (length() > 0)remove(0);
	}

	int length()const											//返回链表长度**
	{
		return size;
	}

	void insert(int i, const T &x)								//在第i位置插入数据为x的结点**
	{
		node *p = get(i - 1);
		p->next = new node(x, p->next);
		++size;
	}

	void remove(int i)											//删除第i位置的结点**
	{
		node *p = get(i - 1);
		node *q = p->next;
		p->next = q->next;
		delete q;
		--size;
	}

	int search(const T &x)const									//搜索数据x是否在链表中出现**
	{
		node *p = head->next;
		for (int i = 0; p!=NULL; ++i) {
			if (x==p->value)return i;
			p = p->next;
		}
		return -1;
	}

	T visit(int i)const											//访问第i个元素**
	{
		return get(i)->value;
	}

	void traverse()const										//遍历运算并输出**
	{
		node *p = head->next;
		while (p!=NULL) {
			cout << p->value << ' ';
			p = p->next;
		}
	}
};


#endif // !linkList_h
