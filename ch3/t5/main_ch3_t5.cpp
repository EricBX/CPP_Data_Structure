//题目要求1：Pascal语句配对检测——begin…end，if…then…else。
//实现功能：读取Pascal.txt文件，检查关键字配对情况，一旦遇到不配对的情况便返回该行数（第一步未实现）。
//注释：仅支持小写字母的关键字
//检测方法：修改"Pascal.txt"里面的关键字，运行该程序，检测语句配对情况

#include <iostream>
#include <fstream>
#include <string>
#include "seqStack.h"
#include <stdlib.h>

using namespace std;

int checkSyntax(char* filename)
{
	int line = 0;
	char a;//用来检测换行符
	seqStack<string> words;
	string word;
	string preword = "none";//存储最近一次pop
	//读文件
	ifstream in;
	in.open(filename);
	if (!in) {
		cerr << "打不开文件" << filename << endl;
		return -1;
	}
	while (!in.eof()) {
		in >> word;//从文件中读取一组字符串
		//cout << "word=" << word;
		//忽略end后面的标点（but如果写编译器则需要检测）
		if (word == "end." || word == "end;") {
			word = "end";
		}
		//检测换行符，读取行数
		if (!in.eof()) a = in.get();
		while (a == ' ') {
			a = in.get();
		}
		//如果没有换行符，则回退一下，保证下一个字符串的完整
		if (a != ' '&&a != '\n') {
			in.seekg(-1, ios::cur);
		}
		//完成一行的检测
		if (a == '\n')
		{
			line++;
			cout << "第" << line << "行检测完成" << endl;//,最后一个单词：" << word << endl;
		}

		if (words.isEmpty()) {
			if (word == "end" || word == "if" || word == "then" || word == "else") {
				cerr << "错误：未检测到begin" << endl;
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
			else {//以下全是错误，分类标记
				cerr << "中途退出.\n错误：";
				if (words.top() == "if"&&word != "then") {
					cerr << "检测到if,但其之后未检测到then";
				}
				else if (word == "then"&&words.top() != "if") {
					cerr << "检测到then,但其之前未检测到if";
				}
				else if (word == "else"&&preword != "if") {
					cerr << "检测到else,但其之前未检测到then";
				}
				
				cerr << endl;
				return line;
			}
		}

	}
	if (!words.isEmpty()) {
		if (words.top() == "begin") {
			cerr << "检测结束.\n错误：begin之后未检测到end" << endl;
			return 0;
		}
		else if (words.top() == "if") {
			cerr << "检测结束.\n错误：if之后未检测到then" << endl;
			return 0;
		}
	}
	cout << "语法检测完成,未发现配对问题!\nO(∩_∩)O~~" << endl;
	line = 0;
	return line;//if line==-1,error
}

int main()
{
	int error_line;
	error_line=checkSyntax("Pascal.txt");
	if (error_line > 0) {
		cout << "在第" << error_line << "行检测到该错误" << endl;
	}
	system("Pause");

	return 0;
}