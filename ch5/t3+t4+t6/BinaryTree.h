//添加功能：层次遍历hieOrder();	判断是否完全二叉树isComplete();
//添加功能：判断与另一棵二叉树是否对称
#ifndef BinaryTree_h
#define BinaryTree_h

#include "linkQueue.h"


template <class Type>
class BinaryTree
{
private:
	struct Node {
		Node *left, *right;
		Type data;
		Node() :left(NULL), right(NULL) {}
		Node(Type item, Node *L = NULL, Node *R = NULL) :
			data(item), left(L), right(R) {}
		~Node() {}
	};
	Node *root;
public:
	BinaryTree() :root(NULL) {}
	BinaryTree(const Type &value) { root = new Node(value); }
	BinaryTree(const Node *p) { root = p; }
	~BinaryTree() { clear(); }
	Type getRoot()const { return root->data; }
	Type getLeft()const { return root->left->data; }
	Type getRight()const { return root->right->data; }
	void makeTree(const Type &x, BinaryTree &lt, BinaryTree &rt)
	{
		root = new Node(x, lt.root, rt.root);
		lt.root = NULL;
		rt.root = NULL;
	}
	void delLeft()
	{
		BinaryTree tmp = root->left;
		root->left = NULL;
		tmp.clear();
	}
	void delRight()
	{
		BinaryTree tmp = root->right;
		root->right = NULL;
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
			cout << "前序遍历：";
			preOrder(root);
		}
	}
	void postOrder()const
	{
		if (root != NULL) {
			cout << "后序遍历：";
			postOrder(root);
		}
	}
	void midOrder()const
	{
		if (root != NULL) {
			cout << "中序遍历：";
			midOrder(root);
		}
	}
	void hieOrder()const//层次遍历（hierarchy）
	{
		if (root != NULL) {
			cout << "层次遍历：";
			hieOrder(root);
		}
	}
	bool isComplete()const;//判断该二叉树是否是满二叉树
	void creatTree(Type flag);
	bool isMirror(const BinaryTree &y)const;
private:
	int height(Node *t)const
	{
		if (t == NULL)return 0;
		else{
			int lth = height(t->left);
			int rth = height(t->right);
			return 1 + ((lth > rth) ? lth : rth);
		}
	}
	void clear(Node *t)
	{
		if (t->left != NULL)clear(t->left);
		if (t->right != NULL)clear(t->right);
		delete t;
	}
	int size(Node *t)const
	{
		if (t == NULL)return 0;
		return 1 + size(t->left) + size(t->right);
	}
	void preOrder(Node *t)const
	{
		if (t != NULL) {
			cout << t->data << ' ';
			preOrder(t->left);
			preOrder(t->right);
		}
	}
	void postOrder(Node *t)const
	{
		if (t != NULL) {
			postOrder(t->left);
			postOrder(t->right);
			cout << t->data << ' ';
		}
	}
	void midOrder(Node *t)const
	{
		if (t != NULL) {
			midOrder(t->left);
			cout << t->data << ' ';
			midOrder(t->right);
		}
	}
	void hieOrder(Node *t)const;
};

template<class Type>
bool BinaryTree<Type>::isComplete() const
{
	linkQueue<Node*> que;
	Node *tmp;
	int check = 0;
	if (root == NULL) return false;
	que.enQueue(root);
	while (!que.isEmpty()) {
		tmp = que.deQueue();
		if (tmp->left != NULL) {
			if (check == 1) return false;
			que.enQueue(tmp->left);  
		}
		else check = 1;
		if (tmp->right != NULL) {
			if (check == 1) return false;
			que.enQueue(tmp->right);
		}
		else check = 1;
	}
	return true;
}

template <class Type>
void BinaryTree<Type>::creatTree(Type flag)
{
	linkQueue<Node*> que;
	Node *tmp;
	Type x, ldata, rdata;

	//创建树，输入flag表示空结点
	cout << "输入根结点：";
	cin >> x;
	root = new Node(x);
	que.enQueue(root);

	while (!que.isEmpty()) {
		tmp = que.deQueue();
		cout << "输入" << tmp->data << "的两个儿子（" << flag << "表示空结点）：";
		cin >> ldata >> rdata;
		if (ldata != flag) que.enQueue(tmp->left = new Node(ldata));
		if (rdata != flag) que.enQueue(tmp->right = new Node(rdata));
	}
	cout << "创建完成！" << endl;
}

template<class Type>
bool BinaryTree<Type>::isMirror(const BinaryTree & tree2) const
{
	linkQueue<Node*> que1, que2;
	if (root == NULL && tree2.root == NULL) return true;
	else if ((root == NULL && tree2.root != NULL) || root != NULL && tree2.root == NULL) return false;
	Node *t1, *t2;
	que1.enQueue(root);
	que2.enQueue(tree2.root);
	while (!que1.isEmpty() && !que2.isEmpty()) {
		t1 = que1.deQueue();
		t2 = que2.deQueue();
		if (t1->data != t2->data) return false;
		if (t1->left != NULL && t2->right != NULL) {
			que1.enQueue(t1->left);
			que2.enQueue(t2->right);
		}
		else if ((t1->left == NULL && t2->right != NULL) || t1->left != NULL && t2->right == NULL) return false;
		if (t1->right != NULL && t2->left != NULL) {
			que1.enQueue(t1->right);
			que2.enQueue(t2->left);
		}
		else if ((t1->right == NULL && t2->left != NULL) || t1->right != NULL && t2->left == NULL) return false;
	}
	if (!que1.isEmpty() || !que2.isEmpty()) return false;
	return true;
}

template<class Type>
void BinaryTree<Type>::hieOrder(Node * t) const
{
	linkQueue<Node*> que;
	if (t == NULL) return;
	Node *tmp = t;
	que.enQueue(t);
	while (!que.isEmpty()) {
		tmp = que.deQueue();
		if (tmp->left != NULL) que.enQueue(tmp->left);
		if (tmp->right != NULL) que.enQueue(tmp->right);
		cout << tmp->data << ' ';
	}
}

#endif // BinaryTree_h


