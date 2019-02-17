//多项式求和
//功能：降幂排列、合并同类项、多项式相加减
//说明：系数和指数可以是小数，但指数不支持负数，输入样式示例：x^5+2x^4+5x^2+1
#include "stdlib.h"
#include <iostream>
#include <string>
using namespace std;

struct Node {
	double coeff, index;//系数 指数
	Node* next;
	Node() { coeff = 0; index = 0; next = NULL; }//默认构造函数
	Node(double c, double i, Node* p = NULL) :coeff(c), index(i), next(p) {}//构造函数
	~Node() {}
};	

Node* add(Node* exp1, Node* exp2);

//辅助项
class IllegalInput //非法输入则报错
{
public:
	string what() const throw()
	{
		return "Your input is illegal!!";
	}
}ill;
void BubbleSort(Node*);//冒泡排序函数,把指数从高到低排序，同时合并同类项
void swap(Node*, Node*);//冒泡排序中要用到的交换函数
bool isRight(char input, char x);//判断正确输入
Node* readPoly(string s, char x);//从字符串读取多项式
double transStringToDouble(string s);//数字转换string->double
void printPoly(Node *poly, char x);//将多项式输出

int main()
{
	while (1) {
		try {
			//测试一：
			/*string exp1 = "3.5+x+1.1x+1+3x^3.2";
			string exp2 = "2+2x^3.2+2x^2+0.8";
			cout << "As strings:\n";
			cout <<"A = "<< exp1<<endl;//
			cout <<"B = "<< exp2<<endl;//
			char x = 'x';*/

			//测试二：
			string exp1, exp2;
			char x;
			cout << "Please input the signal, such as 'x':";
			cin >> x;
			if (cin.get() != '\n') { while (cin.get() != '\n'); throw ill; }
			cout << "Please input two Polynomials with your signal, such as '3.5+x+1.1x+1+3x^3.2' :\nA = ";
			cin >> exp1;
			cout << "B = ";
			cin >> exp2;

			//存储与计算
			Node* poly1 = readPoly(exp1, x);
			Node* poly2 = readPoly(exp2, x);
			cout << "The tow Polynomials as Nodes:\n";
			cout << "A = ";	printPoly(poly1, x);	cout << endl;
			cout << "B = ";	printPoly(poly2, x);	cout << endl;

			Node* poly3 = add(poly1, poly2);
			cout << "After combining the similar terms:\n";
			cout << "A = ";	printPoly(poly1, x); cout << endl;
			cout << "B = "; printPoly(poly2, x); cout << endl;
			cout << "Finally, C = A + B = ";
			printPoly(poly3, x);
			cout << endl;
			break;
		}
		catch (IllegalInput& il)
		{
			cout << il.what() << endl;
		}
	}
	system("pause");
	return 0;
}


Node* add(Node* exp1, Node* exp2)
{
	BubbleSort(exp1);
	BubbleSort(exp2);
	Node *p = exp1, *q = exp2;//左右加数
	Node *res = NULL;//临时加和结果
	while (p != NULL || q != NULL)
	{
		if (p == NULL&&q != NULL)
		{
			while (q != NULL)
			{
				res = new Node(q->coeff, q->index, res);
				q = q->next;
			}
		}
		else if (q == NULL&&p != NULL)
		{
			while (p != NULL)
			{
				res = new Node(p->coeff, p->index, res);
				p = p->next;
			}
		}
		else if (p->index == q->index)
		{
			res = new Node(p->coeff + q->coeff, p->index, res);
			p = p->next;
			q = q->next;
		}
		else if (p->index > q->index)
		{
			res = new Node(p->coeff, p->index, res);
			p = p->next;
		}
		else if (p->index < q->index)
		{
			res = new Node(q->coeff, q->index, res);
			q = q->next;
		}
	}
	BubbleSort(res);
	return res;
}

void BubbleSort(Node *exp)
{
	if (exp->next == NULL)return;//exp只有一项的时候
	
	Node *p, *q,*head;
	head= exp;
	p = head;
	q = head->next;
	
	while (1)
	{
		p = head;
		q = head->next;
		bool flag = 0;
		while (q != NULL)
		{
			if (p->index < q->index) 
			{ 
				swap(p, q); 
				p = q; 
				q = q->next;
				flag = 1;
			}
			else if (p->index == q->index)
			{
				Node *tmp;
				tmp = q;
				p->next = q->next;
				p->coeff += q->coeff;
				q = q->next;
				delete tmp;
				flag = 1;
			}
			else {
				p = q;
				q = q->next;
			}
				//cout << "at this time, the sequence is:";
			//printPoly(exp, 'X');
			//printf("\n");
		}
		if (!flag) break;
	}
	//cout << "After this bubblesort:";
	//printPoly(exp, 'X');
	//cout << endl;
}

void swap(Node* left, Node* right)
{
	double tmp;
	tmp = right->coeff;
	right->coeff = left->coeff;
	left->coeff = tmp;
	tmp = right->index;
	right->index = left->index;
	left->index = tmp;
}

bool isRight(char input, char x)
{
	if (input >= '0'&&input <= '9')return true;
	else if (input == x || input == '^' || input == '.' || input == '+' || input == '-')return true;
	else return false;
}

Node* readPoly(string s, char x)
{
	Node* head = NULL, *p = NULL;
	double coeff, index;//coeff:系数 index:指数
	int j = 0;

	if ((s[0] > '9' || s[0] < '0') && s[0] != x&&s[0] != '+'&&s[0] != '-')	throw ill;


	while (j < s.length())
	{
		//cout << "j=" << j << '\t' << "s.length=" << s.length() << endl;
		bool sig = 0;//sig=0计系数	sig=1计指数
		static int sign = 1;//记录系数的正负
		string numC , numI ;

		if (s[j] == '+')
		{
			sign = 1;
			j++;
		}
		else if (s[j] == '-')
		{
			sign = -1;
			j++;
		}
		while (s[j] != '+'&&s[j] != '-')//???
		{
			if ((s[j] >= '0'&&s[j] <= '9') || s[j] == '.')
			{
				if (!sig) numC += s[j];
				else numI += s[j];
				j++;
			}
			else if (sig == 0 && s[j] == x && (j + 1) < s.length() && s[j + 1] == '^')
			{
				sig = 1;
				j = j + 2;
			}//以下是特例
			else if (sig == 0 && s[j] == x && ((j + 1) == s.length() || s[j + 1] == '+' || s[j + 1] == '-'))//x指数为1，即没有‘^’
			{
				numI = '1';
				sig = 1;
				j++;
			}
			else if (sig == 0 && ((j + 1) == s.length() || s[j + 1] == '+' || s[j + 1] == '-'))//x指数为0，即没有‘x’
			{
				numI = '0';
				j++;
			}
			else throw ill;
			if (j == s.length())break;
		}
		

		if (numC.empty())
			if(numI.empty())numC = '0';
			else numC = '1';
		if (numI.empty())numI = '0';

		coeff = sign*transStringToDouble(numC);
		index = transStringToDouble(numI);
		p = new Node(coeff, index, head);
		head = p;
	}
	return head;
}

double transStringToDouble(string s)
{
	//cout << "translating:" << s << endl;
	int dot = 0, i = 0;
	double num=0;
	string s1, s2;
	while (i < s.length())
	{
		if (s[i] == '.') { dot++; i++; }
		if (dot == 0 && s[i] >= '0'&&s[i] <= '9') { s1 += s[i]; i++; }
		if (dot == 1 && s[i] >= '0'&&s[i] <= '9') { s2 += s[i]; i++; }
		if (dot > 1) break;
	}
	if (dot > 1 || s1.empty() || (dot == 1 && s2.empty())) throw ill;
	for (int j = s1.length() - 1; j >= 0; j--)num += (s1[j] - '0') *pow(10, s1.length() - j-1);
	for (int k = 0; k < s2.length(); k++)num += (s2[k] - '0') *pow(10, -k - 1);
	return num;
}

void printPoly(Node *poly, char x)
{
	Node *p=poly;
	if (p != NULL)
	{
		if (p->coeff == 0) {
			cout << p->coeff;
		}
		else if (p->coeff == 1 && p->index != 0) {
			if (p->index == 1)cout << x;
			else cout << x << '^' << p->index;
		}
		else{
			cout << p->coeff;
			if (p->index != 0 && p->coeff != 1) {
				if (p->index == 1)cout << x;
				else cout << x<<'^' << p->index;
			}
		}
		p = p->next;
	}
	while (p != NULL)
	{
		if (p->coeff != 0) {
			if (p->coeff == 1 && p->index != 0) {
				cout << '+';
				if (p->index == 1)cout << x;
				else cout << x << '^' << p->index;
			}
			else if (p->coeff > 0) {
				cout << "+" << p->coeff;
			}
			else if (p->coeff < 0) {
				cout << p->coeff;
			}
			if (p->index != 0 && p->coeff != 1) {
				if (p->index == 1)cout << x;
				else cout << x << '^' << p->index;
			}
		}
		else if (p->next != NULL)	cout << "+0";
		p = p->next;
	}
}