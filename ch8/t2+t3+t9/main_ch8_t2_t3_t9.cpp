//��Ŀ2Ҫ��:�ڶ����������������3����Ա������ɾ��С��ĳ��ָ��ֵ������Ԫ�أ��������߽磩
										   //ɾ������ĳ��ָ��ֵ������Ԫ�أ��������߽磩
										   //ɾ��ĳһָ����Χ�е�����Ԫ�أ������߽磩
//��Ŀ3Ҫ��:��������������еĲ��롢ɾ���Ͳ��Һ����ĳɷǵݹ麯����
//��Ŀ9Ҫ��:�ڶ��������������һ����Ա�������ҳ������е�i���Ԫ�ء�

#include "BinarySearchTree.h"
#include <iostream>
using namespace std;


int main()
{
	int a[] = { 10,8,6,21,87,56,4,0,11,3,22,7,5,34,1,2,9 };
	//=================================//������Ŀ3��
	BinarySearchTree<int> tree;
	for (int i = 0; i < 17; i++) tree.insert(a[i]);
	cout << "������Ŀ��3����" << endl;
	cout << "find 2 is " << (tree.find(2) ? "true" : "false") << endl;
	tree.remove(2);
	cout << "after delete 2, find 2 is " << (tree.find(2) ? "true" : "false") << endl;

	cout << "find 3 is " << (tree.find(3) ? "true" : "false") << endl;
	tree.remove(3);
	cout << "after delete 3, find 3 is " << (tree.find(3) ? "true" : "false") << endl;

	cout << "find 21 is " << (tree.find(21) ? "true" : "false") << endl;
	tree.remove(21);
	cout << "after delete 21, find 21 is " << (tree.find(21) ? "true" : "false") << endl;

	cout << "find 1 is " << (tree.find(1) ? "true" : "false") << endl;
	cout << "find 22 is " << (tree.find(22) ? "true" : "false") << endl;
	cout << "find 57 is " << (tree.find(57) ? "true" : "false") << endl;
	//==================================//������Ŀ2��
	BinarySearchTree<int> tree2;
	for (int i = 0; i < 17; i++) tree2.insert(a[i]);
	cout << "\n������Ŀ��2����\n(1)ɾ��С��5��Ԫ�غ�" << endl;
	tree2.delSmaller(5);
	for (int i = 0; i < 17; i++) {
		cout << "find " << a[i] << " is " << (tree2.find(a[i]) ? "true" : "false") << endl;
	}
	cout << "(2)ɾ������22��Ԫ�غ�" << endl;
	tree2.delBigger(22);
	for (int i = 0; i < 17; i++) {
		cout << "find " << a[i] << " is " << (tree2.find(a[i]) ? "true" : "false") << endl;
	}
	cout<<"(3)ɾ�����ڵ���9С�ڵ���20��Ԫ�غ�" << endl;
	tree2.delRange(9, 20);
	for (int i = 0; i < 17; i++) {
		cout << "find " << a[i] << " is " << (tree2.find(a[i]) ? "true" : "false") << endl;
	}
	//==================================//������Ŀ9��
	BinarySearchTree<int> tree3;
	for (int i = 0; i < 17; i++) tree3.insert(a[i]);
	cout << "\n������Ŀ��9����" << endl;
	int num;
	for (int i = -2; i <= 20; i++) {
		if (tree3.findMaxI(i, num)) {
			cout << "�����е�" << i << "���Ԫ�� = " << num << endl;
		}
		else cout << "������û�е�" << i << "���Ԫ��" << endl;
	}
	cout << endl;
	
	/*//�����3�Ĳ��ԣ�
	int b[] = { 4,7,2,0,9,8,1,3,5,6 };
	BinarySearchTree<int> tree4;
	for (int i = 0; i < 10; i++) tree4.insert(b[i]);
	cout << "\n���Լ���⣺" << endl;
	tree4.remove(4);*/
	system("Pause");
	return 0;
}

