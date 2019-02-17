//��ĿҪ��1��Pascal�����Լ�⡪��begin��end��if��then��else��
//ʵ�ֹ��ܣ���ȡPascal.txt�ļ������ؼ�����������һ����������Ե�����㷵�ظ���������һ��δʵ�֣���
//ע�ͣ���֧��Сд��ĸ�Ĺؼ���
//��ⷽ�����޸�"Pascal.txt"����Ĺؼ��֣����иó��򣬼�����������

#include <iostream>
#include <fstream>
#include <string>
#include "seqStack.h"
#include <stdlib.h>

using namespace std;

int checkSyntax(char* filename)
{
	int line = 0;
	char a;//������⻻�з�
	seqStack<string> words;
	string word;
	string preword = "none";//�洢���һ��pop
	//���ļ�
	ifstream in;
	in.open(filename);
	if (!in) {
		cerr << "�򲻿��ļ�" << filename << endl;
		return -1;
	}
	while (!in.eof()) {
		in >> word;//���ļ��ж�ȡһ���ַ���
		//cout << "word=" << word;
		//����end����ı�㣨but���д����������Ҫ��⣩
		if (word == "end." || word == "end;") {
			word = "end";
		}
		//��⻻�з�����ȡ����
		if (!in.eof()) a = in.get();
		while (a == ' ') {
			a = in.get();
		}
		//���û�л��з��������һ�£���֤��һ���ַ���������
		if (a != ' '&&a != '\n') {
			in.seekg(-1, ios::cur);
		}
		//���һ�еļ��
		if (a == '\n')
		{
			line++;
			cout << "��" << line << "�м�����" << endl;//,���һ�����ʣ�" << word << endl;
		}

		if (words.isEmpty()) {
			if (word == "end" || word == "if" || word == "then" || word == "else") {
				cerr << "����δ��⵽begin" << endl;
				return line;
			}
			else if (word == "begin") {
				words.push(word);
				//cout << word;
			}
		}
		else {
			if (word == "if"&&words.top() != "if") {
				words.push(word);
				//cout << word;
			}
			else if (word == "then"&&words.top() == "if") {
				preword = words.pop();
				//cout << "pop="<<preword;
			}
			else if (word == "else"&&preword == "if"&&words.top() != "if") {
				preword = "none";
				//cout << word;
			}
			else if (word == "end"&&words.top() == "begin") {
				words.pop();
				//cout << word;
			}
			else if (word == "begin"&&words.top() != "if") {
				words.push(word);
				//cout<<word;
			}
			else if (word != "begin"&&word != "end"&&word != "if"&&word != "then"&&word != "else") {
				continue;
			}
			else {//����ȫ�Ǵ��󣬷�����
				cerr << "��;�˳�.\n����";
				if (words.top() == "if"&&word != "then") {
					cerr << "��⵽if,����֮��δ��⵽then";
				}
				else if (word == "then"&&words.top() != "if") {
					cerr << "��⵽then,����֮ǰδ��⵽if";
				}
				else if (word == "else"&&preword != "if") {
					cerr << "��⵽else,����֮ǰδ��⵽then";
				}
				
				cerr << endl;
				return line;
			}
		}

	}
	if (!words.isEmpty()) {
		if (words.top() == "begin") {
			cerr << "������.\n����begin֮��δ��⵽end" << endl;
			return 0;
		}
		else if (words.top() == "if") {
			cerr << "������.\n����if֮��δ��⵽then" << endl;
			return 0;
		}
	}
	cout << "�﷨������,δ�����������!\nO(��_��)O~~" << endl;
	line = 0;
	return line;//if line==-1,error
}

int main()
{
	int error_line;
	error_line=checkSyntax("Pascal.txt");
	if (error_line > 0) {
		cout << "�ڵ�" << error_line << "�м�⵽�ô���" << endl;
	}
	system("Pause");

	return 0;
}