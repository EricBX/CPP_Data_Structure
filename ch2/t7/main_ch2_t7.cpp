#include "seqList.h"
#include "stdlib.h"

int main()
{
	//定义两个存储整型数的线性表并赋值
	seqList<int> seq1, seq2;
	for (int i = 0; i < 8; i++)
	{
		seq1.insert(i, i);
		seq2.insert(i, i + 1);
	}
	cout << "seq1 = ";
	seq1.traverse();
	cout << "seq2 = ";
	seq2.traverse();

	//合并
	seqList<int> seq3;
	seq3 = seq1 + seq2;//已经写好了‘=’与‘+’的重载函数
	cout << "seq3 = seq1 + seq2 = ";
	seq3.traverse();

	system("pause");
	return 0;
}