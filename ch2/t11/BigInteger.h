#ifndef bigInteger_h
#define bigInteger_h

#include <iostream>
#include <string>
using namespace std;

//�쳣����
class OutOfBound {};
class IllegalSize {};
class IllegalInput //�Ƿ����뱨��
{
public:
	IllegalInput()
	{
		cout << "Your input is illegal!!" << endl;
	}
};

//������������������
class BigIntegerList;
//���������������
BigIntegerList operator+(const BigIntegerList &l, const BigIntegerList &r);
//�������������ඨ��
class BigIntegerList 
{
	friend ostream &operator<<(ostream &os, const BigIntegerList &x);
	friend istream &operator >> (istream &is, BigIntegerList &x);
	friend BigIntegerList operator+(const BigIntegerList &, const BigIntegerList &);//����������غ�����Ϊ��Ԫ����������//�ӷ�
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
	BigIntegerList(const BigIntegerList &);//���ƹ��캯��
	~BigIntegerList() { clear();}
	BigIntegerList & operator=(const BigIntegerList &);//��ֵ�������������//��ֵ
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
	//��ȡ��һλ
	if ((ch = is.get()) != '\n') {
		if (ch<'0' || ch>'9') throw IllegalInput();
		x.head = new BigIntegerList::node(ch - '0');
	}
	//��ȡ֮���
	while ((ch = is.get()) != '\n')
	{
		if (ch<'0' || ch>'9') throw IllegalInput();
		x.head = new BigIntegerList::node(ch - '0', x.head);
	}
	x.head = new BigIntegerList::node(-1,x.head);
	return is;
}

#endif