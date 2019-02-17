#ifndef headLinkQueue_h
#define headLinkQueue_h

#include <stdlib.h>
#include <iostream>
using namespace std;

template <class elemType>
class headLinkQueue
{
private:
	struct node {
		elemType data;
		node* next;
		node(const elemType &x, node* N = NULL) {
			data = x;
			next = N;
		}
		node() :next(NULL) {}
		~node() {}
	};
	node *rear;
	node *head;
public:
	headLinkQueue() { head = new node(); head->next = rear = NULL; }
	~headLinkQueue();
	bool isEmpty() { return head->next == NULL; }
	void enQueue(const elemType &x);
	elemType deQueue();
	elemType getHead() { return head->next->data; }
};

template <class elemType>
headLinkQueue<elemType>::~headLinkQueue()
{
	node* tmp;
	while (head->next != NULL) {
		tmp = head->next;
		head->next = tmp->next;
		delete tmp;
	}
	delete head;
}

template <class elemType>
void headLinkQueue<elemType>::enQueue(const elemType &x)
{
	if (rear == NULL) {
		head->next = rear = new node(x);
	} 
	else{
		rear->next = new node(x);
		rear = rear->next;
	}
}

template <class elemType>
elemType headLinkQueue<elemType>::deQueue()
{
	node* tmp;
	elemType value;
	tmp = head->next;
	value = tmp->data;
	if (rear == tmp) head->next = rear = NULL;
	else	head->next = tmp->next;
	delete tmp;
	return value;
}

#endif