//��Ŀ7Ҫ��:���һ����������һ����ģΪN�������������ҳ���K���Ԫ��
//��1��������ʱ�临�Ӷ�ΪO(N+KlogN)
//��2��������ʱ�临�Ӷ�ΪO(NlogK)

#include "priorityQueue.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>
T getMaxK1(T a[], int N, int K)
{
	priorityQueue<T, greater<T>> priQue(a, N);

	T res;
	for (int i = 0; i < K; i++) res = priQue.deQueue();
	return res;
}

template <class T>
T getMaxK2(T a[], int N, int K)
{
	priorityQueue<T> priQue(a, K);

	for (int i = K; i < N; i++) {
		if (a[i] > priQue.getHead()) {
			priQue.deQueue();
			priQue.enQueue(a[i]);
		}
	}
	return priQue.getHead();
}

int main()
{
	int a[] = { 1,5,4,6,3,7,2,8,9,0 };
	int K = 4, N = 10;
	int num1 = getMaxK1<int>(a, N, K);
	int num2 = getMaxK2<int>(a, N, K);

	cout << "a = ";
	for (int i = 0; i < N; i++) cout << a[i] << ' ';
	cout << "\n�ҳ�a�е�" << K << "���Ԫ�أ�" << endl;
	cout << "����һ��" << num1 << endl;
	cout << "��������" << num2 << endl;
	

	system("Pause");
	return 0;
}