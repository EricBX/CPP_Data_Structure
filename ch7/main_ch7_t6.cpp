//��Ŀ6Ҫ��:ʵ��һ�����Һ���

#include "linkList.h"

template <class Type>
int linkSearchAndTop(linkList<Type> &list, const Type &x)
{
	int i;
	i = list.search(x);
	if (i == -1)return i;
	if (i != 0) {
		list.insert(0, x);
		list.remove(i);
	}
	return i;
}

int main()
{
	int num,pos;//�����ҵ����ּ���λ��
	//����һ������
	linkList<int> list;
	for (int i = 0; i < 10; i++) {
		list.insert(i, 10 - i);
	}
	cout << "����=��";
	list.traverse();
	cout << "��\n������Ҫ���ҵ�Ԫ��(-1Ϊ��������)��";
	cin >> num;
	while (num != -1) {
		pos = linkSearchAndTop(list, num);
		if (pos != -1)
			cout << "Ԫ��" << num << "��λ����" << pos << endl;
		else
			cout << "δ�ҵ�Ԫ��" << num << endl;
		cout << "����=��";
		list.traverse();
		cout << "��\n������Ҫ���ҵ�Ԫ��(-1Ϊ��������)��";
		cin >> num;
	}

	system("Pause");
	return 0;
}