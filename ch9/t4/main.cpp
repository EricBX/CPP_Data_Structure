//题目4要求:利用随机函数按1%的非零元素的概率生成一个元素值1~1000的100×100稀疏矩阵
		  //并将矩阵存入闭散列表中
		  //检验最后生成的非零元素的个数是否为1%


#include "closeHashTable.h"
#include <iostream>
#include <stdlib.h> 
#include <time.h>  
using namespace std;

int main()
{
	//生成稀疏矩阵并存入闭散列表：
	closeHashTable<matrix_entry<int>> matrixHash(131, getKey);
	int num, cnt=0;//num=生成的数，cnt=非零元素计数
	double a;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			a = rand() / (double)RAND_MAX;
			if (a >= 0.01) num = 0;//零
			else num = rand() % 1000 + 1;//非零
			if (num != 0) {
				matrix_entry<int> p(i, j, num);
				matrixHash.insert(p);
				cnt++;
			}
		}
	}
	//检验最后生成的非零元素的个数
	cout << "非零元素个数 = " << cnt << endl;
	cout << "百分比 = " << (double)cnt / 100. << "%" << endl;
	
	system("Pause");
	return 0;
}