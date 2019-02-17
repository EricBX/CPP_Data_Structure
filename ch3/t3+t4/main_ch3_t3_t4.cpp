//题目要求1：编写一个将中缀表达式转换成后缀表达式的函数
//题目要求2：编写一个计算后缀表达式的函数
//限制：仅适用于整型数

#include "seqStack.h"
#include <iostream>
#include <string>

using namespace std;

class IllegalInput //非法输入报错
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
					cout << "缺左括号！" << endl;
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

	cout << "中缀表达式为：" << infix << endl;
	cout << "后缀表达式为：" << postfix << endl;

	double result = calc_Postfix(postfix);
	cout << "后缀表达式运算结果为：" << result << endl;
	system("pause");
	return 0;
}