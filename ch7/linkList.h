#ifndef linkList_h
#define linkList_h

#include <stdlib.h>
#include <iostream>
using namespace std;

template<class T>
class linkList
{
private:
	struct node {												//��Ƕ�ڵ���**
		T value;
		node* next;

		node() :next(NULL) {}									//�ڵ���Ĭ�Ϲ��캯��**
		node(const T &v, node *n = NULL) :value(v), next(n) {}
	};

	node *head;													//����ͷ���**
	int size;													//������**

protected:							
	node *get(int i)const										//���iλ�ý��ָ��**
	{
		if (i >= size) { cerr << "out of bound!" << endl; return head; }
		if (i < 0) return head;
		node *p = head->next;
		for (int j = 0; j < i; ++j) p = p->next;

		return p;
	}

public:
	linkList() :size(0)										//����Ĭ�Ϲ��캯��**
	{
		head = new node;
	}

	~linkList() {												//��������**
		clear();
		delete head;
	}

	void clear()												//�������**
	{
		while (length() > 0)remove(0);
	}

	int length()const											//����������**
	{
		return size;
	}

	void insert(int i, const T &x)								//�ڵ�iλ�ò�������Ϊx�Ľ��**
	{
		node *p = get(i - 1);
		p->next = new node(x, p->next);
		++size;
	}

	void remove(int i)											//ɾ����iλ�õĽ��**
	{
		node *p = get(i - 1);
		node *q = p->next;
		p->next = q->next;
		delete q;
		--size;
	}

	int search(const T &x)const									//��������x�Ƿ��������г���**
	{
		node *p = head->next;
		for (int i = 0; p!=NULL; ++i) {
			if (x==p->value)return i;
			p = p->next;
		}
		return -1;
	}

	T visit(int i)const											//���ʵ�i��Ԫ��**
	{
		return get(i)->value;
	}

	void traverse()const										//�������㲢���**
	{
		node *p = head->next;
		while (p!=NULL) {
			cout << p->value << ' ';
			p = p->next;
		}
	}
};


#endif // !linkList_h
