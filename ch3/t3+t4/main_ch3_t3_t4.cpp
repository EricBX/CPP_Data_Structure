//��ĿҪ��1����дһ������׺���ʽת���ɺ�׺���ʽ�ĺ���
//��ĿҪ��2����дһ�������׺���ʽ�ĺ���
//���ƣ���������������

#include "seqStack.h"
#include <iostream>
#include <string>

using namespace std;

class IllegalInput //�Ƿ����뱨��
{
public:
	IllegalInput()
	{
		cout << "Your input is illegal!!" << endl;
	}
};

string Infix_to_Postfix(const string& x)
{
	string result;
	int size = x.size();
	seqStack<char> exp(size);
	for (int i = 0; i < size; i++) {
		if (x[i] == ' ') {
			continue;
		}
		else if (x[i] >= '0'&&x[i] <= '9') {
			result = result + x[i];
		}
		else if (x[i] == '(') {
			exp.push(x[i]);
		}
		else if (x[i] == ')') {
			while (exp.top() != '(' ) {
				result = result + exp.pop();
				if (exp.isEmpty()) {
					cout << "ȱ�����ţ�" << endl;
					throw IllegalInput();
				}
			}
			exp.pop();
		}
		else if (x[i] == '^') {
			exp.push(x[i]);
		}
		else if (x[i] == '*' || x[i] == '/') {
			while (exp.top() == '^'||exp.top()=='*'|| exp.top() == '/') {
				result = result + exp.pop();
			}
			exp.push(x[i]);
		}
		else if (x[i] == '+' || x[i] == '-') {
			while (exp.top() == '^'|| exp.top() == '*'|| exp.top() == '/'||exp.top() == '+' || exp.top() == '-') {
				result = result + exp.pop();
			}
			exp.push(x[i]);
		}
		else {
			throw IllegalInput();
		}
	}
	while (!exp.isEmpty()) {
		result = result + exp.pop();
	}
	return result;
}

double calc_Postfix(const string& x)
{
	double left = 0, right = 0;
	int size = x.size();
	seqStack<double> operand(size);
	for (int i = 0; i < size; i++) {
		if (x[i] == ' ') {
			continue;
		}
		else if (x[i] >= '0'&&x[i] <= '9') {
			operand.push(x[i]-'0');
		}
		else if (x[i] == '+') {
			operand.push(operand.pop() + operand.pop());
		}
		else if (x[i] == '-') {
			right = operand.pop();
			left = operand.pop();
			operand.push(left-right);
		}
		else if (x[i] == '*') {
			operand.push(operand.pop() * operand.pop());
		}
		else if (x[i] == '/') {
			right = operand.pop();
			left = operand.pop();
			operand.push(left / right);
		}
		else {
			throw IllegalInput();
		}
	}
	return operand.pop();
}

int main()
{
	string infix = "(5+6*(7+3)/3)/4+5";
	string postfix = Infix_to_Postfix(infix);

	cout << "��׺���ʽΪ��" << infix << endl;
	cout << "��׺���ʽΪ��" << postfix << endl;

	double result = calc_Postfix(postfix);
	cout << "��׺���ʽ������Ϊ��" << result << endl;
	system("pause");
	return 0;
}