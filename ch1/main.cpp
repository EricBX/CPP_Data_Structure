#include <iostream>
using namespace std;

bool isPrimeNum(int x);//�ж�����//�ú����������µ�ʱ�临�Ӷ���O(N)
int sumOscillate(int n);//�����//ʱ�临�Ӷ�O(1)

int main()
{
	int num,N;
				//��int�洢���ֵľ����ԣ���ֵ̫��(���10^9��)��ʱ�������������Բ��ܸ��㷨�������̫���������

	//test1_�ж�һ���������Ƿ�����
	cout << "Please enter a positive interger, I will determine whether it is a prime number:";

	while ((!(cin >> num)) || num <= 0)
	{
		cout << "Wrong input!!  Please input a positive integer again:";
		cin.sync();
		cin.clear();
	}
	if (isPrimeNum(num))
		cout << "It's a prime number;\n";
	else cout << "It's not a prime number;\n";

	//test2_����ڶ���������S=1-2+3-4...+/-N��ֵ
	cout<<"Assuming that S=1-2+3-4...+/-N , Please enter the size of the Oscillate Series, N = ";
	cin >> N;
	while (cin.fail() || N <= 0)
	{
		cout << "Wrong input!!  Please input a number again:";
		cin.sync();
		cin.clear();
		cin >> N;
	}
	cout << "S = " << sumOscillate(N) << endl;
	cout << "Please enter something to quit!\n";
	cin >> N;	//���ڹ۲���,�������������ֱ���˳�
	return 0;
}


bool isPrimeNum(int x)
{
	if (x <= 1) return false;
	if (x==2) return true;
	if ((x % 2) == 0) return false;
	for (int i = 3; i < (x / 2); i += 2)
	{
		if ((x % i) == 0) return false;
	}
	return true;
}

int sumOscillate(int n)
{
	if (n % 2 == 0)		return -n / 2;
	else	return n - (n - 1) / 2;
}