// ShellAndBubbleSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	RedType d[N] = { { 49,1 },{ 38,2 },{ 65,3 },{ 97,4 },{ 76,5 },{ 13,6 },{ 27,7 },{ 49,8 },{ 55,9 },{ 4,10 } };
	SLinkListType l,j;
	int dt[T] = { 5,3,1 }; // 增量序列数组
	l.Assign(d, N);
	j = l;
	printf("排序前: ");
	l.Print();
	l.ShellSort();
	printf("排序后: ");
	l.Print();	printf("排序前: ");
	j.Print();
	j.BubbleSort();
	printf("排序后: ");
	j.Print();	
    return 0;
}

