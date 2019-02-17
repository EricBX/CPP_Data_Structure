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
	void delSmaller(const Type &max);//ɾ��С��ĳ��ָ��ֵ������Ԫ��
	void delBigger(const Type &min);//ɾ������ĳ��ָ��ֵ������Ԫ��
	void delRange(const Type &min, const Type &max);
	//ɾ��ĳһָ����Χ�е�����Ԫ��
	bool findMaxI(int i, Type & x);//�ҳ������е�i���Ԫ��
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
//�ǵݹ�ʵ��������������
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
	BinaryNode *tmp = root, *tmp2;//tmp2�洢tmp�ĸ����
	bool dir = 0;//��¼����
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
	BinaryNode *tmp = root;//tmp����Ѱ�Ҳ��洢x�Ľ��
	BinaryNode *tmp3; //tmp3��tmp�ĸ����
	bool dir = 0;//�洢tmp3��tmp�Ĺ�ϵ
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
		else {//tmp�ҵ�x����ʼɾ��
			if (tmp->left != NULL && tmp->right != NULL) {//�����ӽ��
				BinaryNode *tmp2 = tmp->right;//tmp2����Ѱ��tmp�������е���Сֵ
				tmp3 = tmp;			  //tmp3��tmp2�ĸ����
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
			else {//һ���ӽ���û���ӽ��
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
	if (t == NULL) return;//�п�
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