// InsertSort.cpp : �������̨Ӧ�ó������ڵ㡣
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
	l2 = l3 = l1; // ����˳���l2��l3��l1��ͬ
	printf("����ǰ:\n");
	l1.Print();
	l1.InsertSort();
	printf("ֱ�Ӳ��������:\n");
	l1.Print();
	l2.BInsertSort();
	printf("�۰���������:\n");
	l2.Print();
	l3.P2InsertSort();
	printf("2_·���������:\n");
	l3.Print();
    return 0;
}

