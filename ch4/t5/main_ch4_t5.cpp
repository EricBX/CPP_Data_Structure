//题目要求:设计并实现一个用带头结点的单链表实现的队列类

#include "headLinkQueue.h"

int main()
{
	headLinkQueue<int> queue;
	int num;
	cout << "enqueue:";
	for (int i = 0; i < 10; i++) {
		queue.enQueue(i);
		cout << i<<' ';
	}
	cout << endl;
	cout << "dequeue:";
	for (int i = 0; i < 3; i++) {
		num = queue.deQueue();
		cout << num << ' ';
	}
	cout << "\nafter 3 dequeue, front=" << queue.getHead() << endl;
	system("Pause");

	return 0;
}