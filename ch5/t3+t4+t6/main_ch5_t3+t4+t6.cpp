//��Ŀ3Ҫ��:�ڶ�������BinaryTree������һ�����ܣ�ʵ�ֲ�α�����
//��Ŀ4Ҫ��:�ڶ�������BinaryTree������һ�����ܣ��ж϶������Ƿ�����ȫ��������
//��Ŀ6Ҫ��:���һ���㷨�ж����ζ������Ƿ�Գƣ������ö�������Ϊ����
//�������

#include "BinaryTree.h"

int main()
{
	BinaryTree<char> tree;
	cout << "�밴������ʾ����һ��char���͵Ķ���������@��ʾ�ս�㣩" << endl;
	tree.creatTree('@');

	//�������ԣ�
	tree.preOrder();
	cout << endl;
	tree.postOrder();
	cout << endl;
	tree.midOrder();
	cout << endl;
	tree.hieOrder();
	cout << endl;

	//��ȫ��������⣺
	if (tree.isComplete()) cout << "�⡾�ǡ�һ����ȫ��������" << endl;
	else cout << "�⡾���ǡ�һ����ȫ����������" << endl;
	//==================================================
	BinaryTree<char> tree2;
	cout << "\n�밴������ʾ�ٴι���һ��char���͵Ķ���������@��ʾ�ս�㣩" << endl;
	tree2.creatTree('@');

	//�������ԣ�
	tree2.preOrder();
	cout << endl;
	tree2.postOrder();
	cout << endl;
	tree2.midOrder();
	cout << endl;
	tree2.hieOrder();
	cout << endl;

	//��ȫ��������⣺
	if (tree2.isComplete()) cout << "�⡾�ǡ�һ����ȫ��������" << endl;
	else cout << "�⡾���ǡ�һ����ȫ����������" << endl;
	//==================================================
	//������ö������Ƿ�Գƣ�
	if (tree.isMirror(tree2)) cout << "���ö���������Ϊ���񡿣�" << endl;
	else cout << "���ö������������Գơ�����" << endl;

	system("Pause");
	return 0;
}