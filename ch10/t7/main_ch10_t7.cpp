//题目7要求:设计一个函数，在一个规模为N的无序数组中找出第K大的元素
//（1）函数的时间复杂度为O(N+KlogN)
//（2）函数的时间复杂度为O(NlogK)

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
	cout << "\n找出a中第" << K << "大的元素：" << endl;
	cout << "方法一：" << num1 << endl;
	cout << "方法二：" << num2 << endl;
	

	system("Pause");
	return 0;
}