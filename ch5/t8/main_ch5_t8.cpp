//题目8要求:假设树以儿子兄弟链表的方法存储，试分别设计实现他的前序、后序和层次遍历的算法

#include "cbTree.h"

int main()
{
	cbTree<char> tree;
	cout << "请按如下提示构建一个char类型的以儿子兄弟链表示的树（以@表示空结点）" << endl;
	tree.creatTree('@');

	//遍历测试：
	tree.preOrder();
	cout << endl;
	tree.postOrder();
	cout << endl;
	tree.hieOrder();
	cout << endl;
		
	system("Pause");
	return 0;
}