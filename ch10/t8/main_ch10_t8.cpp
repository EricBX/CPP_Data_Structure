//��Ŀ8Ҫ��:�޸Ŀ�����������ʹ֮������ֵ��Ϊ��׼Ԫ�ء�
			//�����ķ�����ȡ������Ԫ���еĵ�һ�������һ�����м�һ����Ϊ������

#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>
int divide(T a[], int low, int high)
{
	//==================
	//�޸����ݣ�
	T tmp;
	int mid = (low + high) / 2;
	if (a[low] < a[mid]) {
		tmp = a[low];
		a[low] = a[mid];
		a[mid] = tmp;
	}
	if (a[mid] > a[high]) {
		tmp = a[mid];
		a[mid] = a[high];
		a[high] = tmp;
	}
	if (a[low] > a[high]) {
		tmp = a[low];
		a[low] = a[high];
		a[high] = tmp;
	}
	//====================
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

//�������£�
int main()
{
	int a[10] = { 5,3,6,2,7,4,8,1,9,0 };
	cout << "a = ";
	for (int i = 0; i < 10; i++) {
		cout << a[i] << ' ';
	}

	quickSort(a, 10);
	cout << "\nafter quickSort, a = ";
	for (int i = 0; i < 10; i++) {
		cout << a[i] << ' ';
	}

	cout << endl;
	system("Pause");
	return 0;
}
