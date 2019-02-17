//题目要求：设计一个类，处理任意大整数
//实现功能：输入、输出、加法、赋值

#include "BigInteger.h"

int main()
{
	BigIntegerList num1,num2,num3;
	cout << "please input a number:" << endl;
	cin >> num1;//测试输入
	cout << "please input another number:" << endl;
	cin >> num2;

	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;
	num3 = num1 + num2;//测试加法与赋值
	cout << "num3 = num1 + num2 = " << num3 << endl;//测试输出
	system("pause");

	return 0;
}