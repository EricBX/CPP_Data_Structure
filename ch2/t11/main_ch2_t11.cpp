//��ĿҪ�����һ���࣬�������������
//ʵ�ֹ��ܣ����롢������ӷ�����ֵ

#include "BigInteger.h"

int main()
{
	BigIntegerList num1,num2,num3;
	cout << "please input a number:" << endl;
	cin >> num1;//��������
	cout << "please input another number:" << endl;
	cin >> num2;

	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;
	num3 = num1 + num2;//���Լӷ��븳ֵ
	cout << "num3 = num1 + num2 = " << num3 << endl;//�������
	system("pause");

	return 0;
}