#include "seqList.h"
#include "stdlib.h"

int main()
{
	//���������洢�����������Ա���ֵ
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

	//�ϲ�
	seqList<int> seq3;
	seq3 = seq1 + seq2;//�Ѿ�д���ˡ�=���롮+�������غ���
	cout << "seq3 = seq1 + seq2 = ";
	seq3.traverse();

	system("pause");
	return 0;
}