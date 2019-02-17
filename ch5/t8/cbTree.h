//˵�����Զ����ֵ����洢��
//��Ҫʵ�ֵĹ��ܣ�ǰ�����preOrder()���������postOrder()����α���hieOrder()
#ifndef cbTree_h
#define cbTree_h

#include "linkQueue.h"


template <class Type>
class cbTree
{
private:
	struct Node {
		Node *child, *brother;
		Type data;
		Node() :child(NULL), brother(NULL) {}
		Node(Type item, Node *L = NULL, Node *R = NULL) :
			data(item), child(L), brother(R) {}
		~Node() {}
	};
	Node *root;
public:
	cbTree() :root(NULL) {}
	cbTree(const Type &value) { root = new Node(value); }
	cbTree(const Node *p) { root = p; }
	~cbTree() { clear(); }
	Type getRoot()const { return root->data; }
	Type getchild()const { return root->child->data; }
	Type getbrother()const { return root->brother->data; }
	void makeTree(const Type &x, cbTree &lt, cbTree &rt)
	{
		root = new Node(x, lt.root, rt.root);
		lt.root = NULL;
		rt.root = NULL;
	}
	void delchild()
	{
		cbTree tmp = root->child;
		root->child = NULL;
		tmp.clear();
	}
	void delbrother()
	{
		cbTree tmp = root->brother;
		root->brother = NULL;
		tmp.clear();
	}
	bool isEmpty()const { return root == NULL; }
	void clear()
	{
		if (root != NULL)clear(root);
		root = NULL;
	}
	int size()const { return size(root); }
	int height()const { return height(root); }
	void preOrder()const
	{
		if (root != NULL) {
			cout << "ǰ�������";
			preOrder(root);
		}
	}
	void postOrder()const
	{
		if (root != NULL) {
			cout << "���������";
			postOrder(root);
		}
	}
	void hieOrder()const//��α�����hierarchy��
	{
		if (root != NULL) {
			cout << "��α�����";
			hieOrder(root);
		}
	}
	void creatTree(Type flag);
private:
	int height(Node *t)const
	{
		if (t == NULL)return 0;
		else {
			int lth = height(t->child);
			int rth = height(t->brother);
			return 1 + ((lth > rth) ? lth : rth);
		}
	}
	void clear(Node *t)
	{
		if (t->child != NULL)clear(t->child);
		if (t->brother != NULL)clear(t->brother);
		delete t;
	}
	int size(Node *t)const
	{
		if (t == NULL)return 0;
		return 1 + size(t->child) + size(t->brother);
	}
	void preOrder(Node *t)const
	{
		if (t != NULL) {
			cout << t->data << ' ';
			preOrder(t->child);
			preOrder(t->brother);
		}
	}
	void postOrder(Node *t)const
	{
		if (t != NULL) {
			postOrder(t->child);
			cout << t->data << ' ';
			postOrder(t->brother);
		}
	}

	void hieOrder(Node *t)const;
};

template <class Type>
void cbTree<Type>::creatTree(Type flag)
{
	linkQueue<Node*> que;
	Node *tmp;
	Type x, ldata, rdata;

	//������������flag��ʾ�ս��
	cout << "�������㣺";
	cin >> x;
	root = new Node(x);
	que.enQueue(root);

	while (!que.isEmpty()) {
		tmp = que.deQueue();
		cout << "����" << tmp->data << "�Ķ��Ӻ��ֵܣ�" << flag << "��ʾ�ս�㣩��";
		cin >> ldata >> rdata;
		if (ldata != flag) que.enQueue(tmp->child = new Node(ldata));
		if (rdata != flag) que.enQueue(tmp->brother = new Node(rdata));
	}
	cout << "������ɣ�" << endl;
}

template<class Type>
void cbTree<Type>::hieOrder(Node * t) const
{
	linkQueue<Node*> que1, que2;
	if (t == NULL) return;
	Node *tmp;
	que1.enQueue(t);
	while (!que1.isEmpty() || !que2.isEmpty()) {
		while (!que1.isEmpty()) {
			tmp = que1.deQueue();
			if (tmp->child != NULL) que2.enQueue(tmp->child);
			cout << tmp->data << ' ';
			while (tmp->brother != NULL) {
				tmp = tmp->brother;
				if (tmp->child != NULL) que2.enQueue(tmp->child);
				cout << tmp->data << ' ';
			}
		}
		while (!que2.isEmpty()) {
			tmp = que2.deQueue();
			if (tmp->child != NULL) que1.enQueue(tmp->child);
			cout << tmp->data << ' ';
			while (tmp->brother != NULL) {
				tmp = tmp->brother;
				if (tmp->child != NULL) que1.enQueue(tmp->child);
				cout << tmp->data << ' ';
			}
		}
	}
}

#endif // cbTree_h


