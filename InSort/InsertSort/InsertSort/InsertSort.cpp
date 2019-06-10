// InsertSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;


int main()
{
	RedType d[N] = { { 49,1 },{ 38,2 },{ 65,3 },{ 97,4 },{ 76,5 },{ 13,6 },{ 27,7 },{ 49,8 } };
	SqList l1, l2, l3;
	int i;
	l1.Assign(d);
	l2 = l3 = l1; // 复制顺序表l2、l3与l1相同
	printf("排序前:\n");
	l1.Print();
	l1.InsertSort();
	printf("直接插入排序后:\n");
	l1.Print();
	l2.BInsertSort();
	printf("折半插入排序后:\n");
	l2.Print();
	l3.P2InsertSort();
	printf("2_路插入排序后:\n");
	l3.Print();
    return 0;
}

