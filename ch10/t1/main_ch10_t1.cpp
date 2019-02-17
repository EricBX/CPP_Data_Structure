//��Ŀ1Ҫ��:���һ��������ɾ��һ����N��Ԫ�ص�����A�����е��ظ�Ԫ�أ���������������A�е�Ԫ�ظ�����
			//������ʱ�临�Ӷȱ���ΪO(NlogN)

#include <iostream>
#include <stdlib.h>
using namespace std;

//==============================
//���������ʵ�����£�
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
//��ĿҪ��ĺ���������£�
template<class T>
int delRepetitiveElem(T a[], int size)
{
	if (size <= 1)return size;
	//Ԥ����
	quickSort(a, size);
	//ɾ���ظ�Ԫ��
	int p = 1, q = 0;//p���� q����
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
//�������£�
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


