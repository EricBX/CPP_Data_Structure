#ifndef bigInteger_h
#define bigInteger_h

#include <iostream>
#include <string>
using namespace std;

//异常处理
class OutOfBound {};
class IllegalSize {};
class IllegalInput //非法输入报错
{
public:
	IllegalInput()
	{
		cout << "Your input is illegal!!" << endl;
	}
};

//大整数单链表类声明
class BigIntegerList;
//加运算符重载声明
BigIntegerList operator+(const BigIntegerList &l, const BigIntegerList &r);
//大整数单链表类定义
class BigIntegerList 
{
	friend ostream &operator<<(ostream &os, const BigIntegerList &x);
	friend istream &operator >> (istream &is, BigIntegerList &x);
	friend BigIntegerList operator+(const BigIntegerList &, const BigIntegerList &);//加运算符重载函数作为友元函数的声明//加法
private:
	struct node
	{
		int data;
		node* next;
		node(const int &x, node* p=NULL)
		{
			data = x; next = p;
		}
		node() :next(NULL) {}
		//~node() {}
	};
	node* head;
	void clear();
public:
	BigIntegerList() { head = new node(); }
	BigIntegerList(const BigIntegerList &);//复制构造函数
	~BigIntegerList() { clear();}
	BigIntegerList & operator=(const BigIntegerList &);//赋值运算符重载声明//赋值
};

BigIntegerList::BigIntegerList(const BigIntegerList &src)
{
	head = new node(src.head->data);
	node* q = src.head;
	node* p = head;
	while (q->next != NULL) {
		p->next = new node(q->next->data);
		q = q->next;
		p = p->next;
	}
}

void BigIntegerList::clear()
{
	node *p, *q;
	p = head;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		delete q;
	}
	head = NULL;
}

BigIntegerList operator+(const BigIntegerList &l, const BigIntegerList &r)
{
	int carry = 0;
	BigIntegerList::node *p, *pl, *pr;
	BigIntegerList res;
	pl = l.head;
	pr = r.head;
	res.head = new BigIntegerList::node();
	p = res.head;
	while (pl->next != NULL && pr->next != NULL) {
		pl = pl->next;
		pr = pr->next;
		p->next = new BigIntegerList::node((pl->data + pr->data + carry) % 10);
		carry = (pl->data + pr->data + carry) / 10;
		p = p->next;
	}
	if (pl->next == NULL)pl = pr;
	while (pl->next != NULL) {
		pl = pl->next;
		p->next = new BigIntegerList::node((pl->data + carry) % 10);
		carry = (pl->data + carry) / 10;
		p = p->next;
	}
	if (carry == 1) {
		p->next = new BigIntegerList::node(1);
	}
	return res;
}

BigIntegerList& BigIntegerList::operator=(const BigIntegerList &x)
{
	if (&x == this) return *this;
	clear();

	head = new node(x.head->data);
	node* q = x.head;
	node* p = head;
	while (q->next != NULL) {
		p->next = new node(q->next->data);
		q = q->next;
		p = p->next;
	}
	return *this;
}

ostream &operator<<(ostream &os, const BigIntegerList &x)
{
	string s;
	BigIntegerList::node *p = x.head;
	while (p->next != NULL)
	{
		p = p->next;
		s = char(p->data + '0') + s;			
	}
	//os << s;
	for (int i = 0; i < s.size(); ++i) os << s[i];
	return os;
}

istream &operator >> (istream &is, BigIntegerList &x)
{
	char ch;
	x.clear();
	//读取第一位
	if ((ch = is.get()) != '\n') {
		if (ch<'0' || ch>'9') throw IllegalInput();
		x.head = new BigIntegerList::node(ch - '0');
	}
	//读取之后的
	while ((ch = is.get()) != '\n')
	{
		if (ch<'0' || ch>'9') throw IllegalInput();
		x.head = new BigIntegerList::node(ch - '0', x.head);
	}
	x.head = new BigIntegerList::node(-1,x.head);
	return is;
}

#endif