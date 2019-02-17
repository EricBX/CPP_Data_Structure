//题目6要求:实现一个查找函数

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
	int num,pos;//待查找的数字及其位置
	//创建一个集合
	linkList<int> list;
	for (int i = 0; i < 10; i++) {
		list.insert(i, 10 - i);
	}
	cout << "集合=（";
	list.traverse();
	cout << "）\n请输入要查找的元素(-1为结束查找)：";
	cin >> num;
	while (num != -1) {
		pos = linkSearchAndTop(list, num);
		if (pos != -1)
			cout << "元素" << num << "的位置在" << pos << endl;
		else
			cout << "未找到元素" << num << endl;
		cout << "集合=（";
		list.traverse();
		cout << "）\n请输入要查找的元素(-1为结束查找)：";
		cin >> num;
	}

	system("Pause");
	return 0;
}