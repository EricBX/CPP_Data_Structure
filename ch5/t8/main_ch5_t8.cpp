//��Ŀ8Ҫ��:�������Զ����ֵ�����ķ����洢���Էֱ����ʵ������ǰ�򡢺���Ͳ�α������㷨

#include "cbTree.h"

int main()
{
	cbTree<char> tree;
	cout << "�밴������ʾ����һ��char���͵��Զ����ֵ�����ʾ��������@��ʾ�ս�㣩" << endl;
	tree.creatTree('@');

	//�������ԣ�
	tree.preOrder();
	cout << endl;
	tree.postOrder();
	cout << endl;
	tree.hieOrder();
	cout << endl;
		
	system("Pause");
	return 0;
}