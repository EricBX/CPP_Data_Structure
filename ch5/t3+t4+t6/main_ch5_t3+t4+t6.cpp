//题目3要求:在二叉树类BinaryTree中增加一个功能：实现层次遍历。
//题目4要求:在二叉树类BinaryTree中增加一个功能：判断二叉树是否是完全二叉树。
//题目6要求:设计一个算法判断两课二叉树是否对称，即两棵二叉树互为镜像。
//检测如下

#include "BinaryTree.h"

int main()
{
	BinaryTree<char> tree;
	cout << "请按如下提示构建一个char类型的二叉树（以@表示空结点）" << endl;
	tree.creatTree('@');

	//遍历测试：
	tree.preOrder();
	cout << endl;
	tree.postOrder();
	cout << endl;
	tree.midOrder();
	cout << endl;
	tree.hieOrder();
	cout << endl;

	//完全二叉树检测：
	if (tree.isComplete()) cout << "这【是】一个完全二叉树！" << endl;
	else cout << "这【不是】一个完全二叉树……" << endl;
	//==================================================
	BinaryTree<char> tree2;
	cout << "\n请按如下提示再次构建一个char类型的二叉树（以@表示空结点）" << endl;
	tree2.creatTree('@');

	//遍历测试：
	tree2.preOrder();
	cout << endl;
	tree2.postOrder();
	cout << endl;
	tree2.midOrder();
	cout << endl;
	tree2.hieOrder();
	cout << endl;

	//完全二叉树检测：
	if (tree2.isComplete()) cout << "这【是】一个完全二叉树！" << endl;
	else cout << "这【不是】一个完全二叉树……" << endl;
	//==================================================
	//检测两棵二叉树是否对称：
	if (tree.isMirror(tree2)) cout << "两棵二叉树【互为镜像】！" << endl;
	else cout << "两棵二叉树【并不对称】……" << endl;

	system("Pause");
	return 0;
}