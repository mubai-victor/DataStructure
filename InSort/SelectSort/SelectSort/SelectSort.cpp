// SelectSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	RedType d[N] = { { 49,1 },{ 38,2 },{ 65,3 },{ 97,4 },{ 76,5 },{ 13,6 },{ 27,7 },{ 49,8 } };
	SLinkListType l1,l2,l3;
	int i;
	l1.Assign(d, N);
	l2 = l3 = l1;
	printf("l1排序前:\n");
	l1.Print();
	l1.TreeSort();
	printf("l1排序后:\n");
	l1.Print();
	printf("l2排序前:\n");
	l2.Print();
	l2.SelectSort();
	printf("l2排序后:\n");
	l2.Print();
	printf("l3排序前:\n");
	l3.Print();
	l3.HeapSort();
	printf("l3排序后:\n");
	l3.Print();
    return 0;
}

