//题目1要求:设计一个方法，删除一个有N个元素的数组A中所有的重复元素，返回仍留在数组A中的元素个数。
			//函数的时间复杂度必须为O(NlogN)

#include <iostream>
#include <stdlib.h>
using namespace std;

//==============================
//快速排序的实现如下：
template <class T>
int divide(T a[], int low, int high)
{
	T k = a[low];
	do {
		while (low < high&&a[high] >= k) high--;
		if (low < high) { a[low] = a[high]; low++; }
		while (low < high&&a[low] <= k) low++;
		if (low < high) { a[high] = a[low]; high--; }
	} while (low != high);
	a[low] = k;
	return low;
}

template <class T>
void quickSort(T a[], int low, int high)
{
	int mid;
	if (low >= high) return;
	mid = divide(a, low, high);
	quickSort(a, low, mid - 1);
	quickSort(a, mid + 1, high);
}

template <class T>
void quickSort(T a[], int size)
{
	quickSort(a, 0, size - 1);
}
//==============================
//题目要求的函数设计如下：
template<class T>
int delRepetitiveElem(T a[], int size)
{
	if (size <= 1)return size;
	//预处理
	quickSort(a, size);
	//删除重复元素
	int p = 1, q = 0;//p在右 q在左
	while (p < size) {
		if (a[q] != a[p] && (p - q) == 1) {
			q++;
		}
		else if (a[q] != a[p] && (p - q) > 1) {
			q++;
			a[q] = a[p];
		}
		p++;
	}

	return ++q;
}
//========================
//测试如下：
int main()
{
	int a[10] = { 3,5,4,2,3,3,6,9,8,5 };
	cout << "a = ";
	for (int i = 0; i < 10; i++) {
		cout << a[i] << ' ';
	}

	quickSort(a, 10);
	cout << "\nafter quickSort, a = ";
	for (int i = 0; i < 10; i++) {
		cout << a[i] << ' ';
	}

	int currentSize = delRepetitiveElem(a, 10);
	cout << "\nafter deleting the repeatitive elements, a = ";
	for (int i = 0; i < currentSize; i++) {
		cout << a[i] << ' ';
	}

	cout << endl;
	system("Pause");
	return 0;
}


