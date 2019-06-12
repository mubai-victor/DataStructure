// MergeSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	RedType d[N] = { { 49,1 },{ 38,2 },{ 65,3 },{ 97,4 },{ 76,5 },{ 13,6 },{ 27,7 } };
	SqList l;
	int i;
	l.Assign(d);
	printf("排序前:\n");
	l.Print();
	l.MergeSort();
	printf("排序后:\n");
	l.Print();
    return 0;
}

