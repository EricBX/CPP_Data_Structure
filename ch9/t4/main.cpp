//��Ŀ4Ҫ��:�������������1%�ķ���Ԫ�صĸ�������һ��Ԫ��ֵ1~1000��100��100ϡ�����
		  //������������ɢ�б���
		  //����������ɵķ���Ԫ�صĸ����Ƿ�Ϊ1%


#include "closeHashTable.h"
#include <iostream>
#include <stdlib.h> 
#include <time.h>  
using namespace std;

int main()
{
	//����ϡ����󲢴����ɢ�б�
	closeHashTable<matrix_entry<int>> matrixHash(131, getKey);
	int num, cnt=0;//num=���ɵ�����cnt=����Ԫ�ؼ���
	double a;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			a = rand() / (double)RAND_MAX;
			if (a >= 0.01) num = 0;//��
			else num = rand() % 1000 + 1;//����
			if (num != 0) {
				matrix_entry<int> p(i, j, num);
				matrixHash.insert(p);
				cnt++;
			}
		}
	}
	//����������ɵķ���Ԫ�صĸ���
	cout << "����Ԫ�ظ��� = " << cnt << endl;
	cout << "�ٷֱ� = " << (double)cnt / 100. << "%" << endl;
	
	system("Pause");
	return 0;
}