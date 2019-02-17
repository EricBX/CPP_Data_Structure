#include <iostream>
using namespace std;

bool isPrimeNum(int x);//判断素数//该函数在最坏情况下的时间复杂度是O(N)
int sumOscillate(int n);//计算和//时间复杂度O(1)

int main()
{
	int num,N;
				//用int存储数字的局限性：数值太大(大概10^9多)的时候会溢出！！所以不能该算法用来检测太大的素数。

	//test1_判断一个正整数是否素数
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

	//test2_计算摆动数列形如S=1-2+3-4...+/-N的值
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
	cin >> N;	//便于观察结果,避免程序运行完直接退出
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