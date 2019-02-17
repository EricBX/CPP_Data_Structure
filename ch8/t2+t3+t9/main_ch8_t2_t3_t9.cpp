//题目2要求:在二叉查找树类中增加3个成员函数：删除小于某个指定值的所有元素（不包括边界）
										   //删除大于某个指定值的所有元素（不包括边界）
										   //删除某一指定范围中的所有元素（包括边界）
//题目3要求:将二叉查找树类中的插入、删除和查找函数改成非递归函数。
//题目9要求:在二叉查找树中增加一个成员函数：找出集合中第i大的元素。

#include "BinarySearchTree.h"
#include <iostream>
using namespace std;


int main()
{
	int a[] = { 10,8,6,21,87,56,4,0,11,3,22,7,5,34,1,2,9 };
	//=================================//测试题目3：
	BinarySearchTree<int> tree;
	for (int i = 0; i < 17; i++) tree.insert(a[i]);
	cout << "测试题目【3】：" << endl;
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
	//==================================//测试题目2：
	BinarySearchTree<int> tree2;
	for (int i = 0; i < 17; i++) tree2.insert(a[i]);
	cout << "\n测试题目【2】：\n(1)删除小于5的元素后：" << endl;
	tree2.delSmaller(5);
	for (int i = 0; i < 17; i++) {
		cout << "find " << a[i] << " is " << (tree2.find(a[i]) ? "true" : "false") << endl;
	}
	cout << "(2)删除大于22的元素后：" << endl;
	tree2.delBigger(22);
	for (int i = 0; i < 17; i++) {
		cout << "find " << a[i] << " is " << (tree2.find(a[i]) ? "true" : "false") << endl;
	}
	cout<<"(3)删除大于等于9小于等于20的元素后：" << endl;
	tree2.delRange(9, 20);
	for (int i = 0; i < 17; i++) {
		cout << "find " << a[i] << " is " << (tree2.find(a[i]) ? "true" : "false") << endl;
	}
	//==================================//测试题目9：
	BinarySearchTree<int> tree3;
	for (int i = 0; i < 17; i++) tree3.insert(a[i]);
	cout << "\n测试题目【9】：" << endl;
	int num;
	for (int i = -2; i <= 20; i++) {
		if (tree3.findMaxI(i, num)) {
			cout << "集合中第" << i << "大的元素 = " << num << endl;
		}
		else cout << "集合中没有第" << i << "大的元素" << endl;
	}
	cout << endl;
	
	/*//简答题3的测试：
	int b[] = { 4,7,2,0,9,8,1,3,5,6 };
	BinarySearchTree<int> tree4;
	for (int i = 0; i < 10; i++) tree4.insert(b[i]);
	cout << "\n测试简答题：" << endl;
	tree4.remove(4);*/
	system("Pause");
	return 0;
}

