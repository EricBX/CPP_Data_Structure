//��ĿҪ��:��Ʋ�ʵ��һ���ô�ͷ���ĵ�����ʵ�ֵĶ�����

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