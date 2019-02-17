#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include <stdlib.h>

template <class Type>
class BinarySearchTree
{
private:
	struct BinaryNode {
		Type data;
		BinaryNode *left;
		BinaryNode *right;
		BinaryNode(const Type &thedata, BinaryNode *lt, BinaryNode *rt)
			:data(thedata), left(lt), right(rt) {}
	};
	BinaryNode *root;
public:
	BinarySearchTree(BinaryNode *t = NULL) { root = t; }
	~BinarySearchTree();
	bool find(const Type &x)const;
	void insert(const Type &x);
	void remove(const Type &x);
	void delSmaller(const Type &max);//删除小于某个指定值的所有元素
	void delBigger(const Type &min);//删除大于某个指定值的所有元素
	void delRange(const Type &min, const Type &max);
	//删除某一指定范围中的所有元素
	bool findMaxI(int i, Type & x);//找出集合中第i大的元素
private:
	void clear(BinaryNode *t);
	void delSmaller(const Type &max, BinaryNode *&t);
	void delBigger(const Type &min, BinaryNode *&t);
	void delRange(const Type &min, const Type &max, BinaryNode *&t);
	void findMaxI(int i, int &current, Type &x, BinaryNode *t, bool &flag);
};

template<class Type>
BinarySearchTree<Type>::~BinarySearchTree()
{
	if(root!=NULL) clear(root);
	root = NULL;
}
//=======================================================================
//非递归实现以下三个函数
template<class Type>
bool BinarySearchTree<Type>::find(const Type & x) const
{
	BinaryNode *tmp = root;
	if (root == NULL) return false;
	while (tmp != NULL) {
		if (tmp->data > x) tmp = tmp->left;
		else if (tmp->data < x) tmp = tmp->right;
		else return true;
	}
	return false;
}

template<class Type>
void BinarySearchTree<Type>::insert(const Type & x)
{
	BinaryNode *tmp = root, *tmp2;//tmp2存储tmp的父结点
	bool dir = 0;//记录左右
	if (root == NULL) {
		root = new BinaryNode(x, NULL, NULL);
		return;
	}
	while (tmp != NULL) {
		tmp2 = tmp;
		if (x < tmp->data) {
			tmp = tmp->left;
			dir = 0;
		}
		else if (tmp->data < x) {
			tmp = tmp->right;
			dir = 1;
		}
		else return;
	}
	if (dir == 0) tmp2->left = new BinaryNode(x, NULL, NULL);
	else tmp2->right = new BinaryNode(x, NULL, NULL);
}

template<class Type>
void BinarySearchTree<Type>::remove(const Type & x)
{
	BinaryNode *tmp = root;//tmp用来寻找并存储x的结点
	BinaryNode *tmp3; //tmp3存tmp的父结点
	bool dir = 0;//存储tmp3与tmp的关系
	if (tmp == NULL) return;
	while (tmp != NULL) {
		if (x < tmp->data) {
			tmp3 = tmp;
			tmp = tmp->left;
			dir = 0;
		}
		else if (tmp->data < x) {
			tmp3 = tmp;
			tmp = tmp->right;
			dir = 1;
		}
		else {//tmp找到x，开始删除
			if (tmp->left != NULL && tmp->right != NULL) {//两个子结点
				BinaryNode *tmp2 = tmp->right;//tmp2用来寻找tmp右子树中的最小值
				tmp3 = tmp;			  //tmp3存tmp2的父结点
				if (tmp2->left == NULL) {
					tmp->data = tmp2->data;
					tmp3->right = tmp2->right;
					delete tmp2;
					tmp = NULL;
					return;
				}
				else {
					tmp3 = tmp2;
					tmp2 = tmp2->left;
				}
				while (tmp2->left != NULL) {
					tmp3 = tmp2;
					tmp2 = tmp2->left;
				}
				tmp->data = tmp2->data;
				tmp3->left = tmp2->right;
				delete tmp2;
				tmp = NULL;
				return;
			}
			else {//一个子结点或没有子结点
				BinaryNode *tmp2 = tmp;
				if (dir == 0) tmp3->left = (tmp->left != NULL) ? tmp->left : tmp->right;
				else tmp3->right = (tmp->left != NULL) ? tmp->left : tmp->right;
				delete tmp2;
				tmp = NULL;
			}
		}
	}

}

template<class Type>
void BinarySearchTree<Type>::delSmaller(const Type & max)
{
	delSmaller(max,root);
}

template<class Type>
void BinarySearchTree<Type>::delBigger(const Type & min)
{
	delBigger(min, root);
}

template<class Type>
void BinarySearchTree<Type>::delRange(const Type & min, const Type & max)
{
	if (min <= max) delRange(min, max, root);
}

template<class Type>
void BinarySearchTree<Type>::clear(BinaryNode * t)
{
	if (t == NULL) return;//判空
	if (t->left != NULL) clear(t->left);
	if (t->right != NULL) clear(t->right);
	delete t;
}

//=================================================================================
template<class Type>
void BinarySearchTree<Type>::delSmaller(const Type & max, BinaryNode *& t)
{
	if (t == NULL) return;
	if (t->data < max) {
		clear(t->left);
		t->left = NULL;
		delSmaller(max, t->right);
		remove(t->data);
	}
	else if (t->data == max) {
		clear(t->left);
		t->left = NULL;
		delSmaller(max, t->right);
	}
	else delSmaller(max, t->left);
}

template<class Type>
void BinarySearchTree<Type>::delBigger(const Type & min, BinaryNode *& t)
{
	if (t == NULL) return;
	if (t->data > min) {
		clear(t->right);
		t->right = NULL;
		delBigger(min, t->left);
		remove(t->data);
	}
	else if (t->data == min) {
		clear(t->right);
		t->right = NULL;
		delBigger(min, t->left);
	}
	else delBigger(min, t->right);
}

template<class Type>
void BinarySearchTree<Type>::delRange(const Type & min, const Type & max, BinaryNode *& t)
{
	if (t == NULL) return;
	if (t->data < min) delRange(min, max, t->right);
	else if (t->data > max) delRange(min, max, t->left);
	else {
		remove(t->data);
		delRange(min, max, t);
	}
}



//=================================================================================
template<class Type>
bool BinarySearchTree<Type>::findMaxI(int i, Type &x)
{
	int current = 0;
	if (root == NULL || i <= 0) {
		return false;
	}
	bool flag = false;
	findMaxI(i, current, x, root, flag);
	return flag;
}

template<class Type>
void BinarySearchTree<Type>::findMaxI(int i, int & current, Type & x, BinaryNode * t, bool & flag)
{
	if (t == NULL) 	return;
	if (t->right != NULL) findMaxI(i, current, x, t->right, flag);
	current++;
	if (current == i) {
		x = t->data;
		flag = true;
	}
	if (t->left != NULL)findMaxI(i, current, x, t->left, flag);
}

#endif // !BinarySearchTree_h