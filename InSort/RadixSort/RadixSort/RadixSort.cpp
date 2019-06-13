// RadixSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Test.h"
#include "Function.h"

using namespace std;

int main()
{
	RedType d[N] = { { 278,1 },{ 109,2 },{ 63,3 },{ 930,4 },{ 589,5 },{ 184,6 },{ 505,7 },{ 269,8 },{ 8,9 },
	{ 83,10 } };
	SLinkListType l;
	int *adr;
	l.Assign(d, N);
	printf("排序前(next域还没赋值):\n");
	l.PrintPos();
	l.RadixSort();
	printf("排序后(静态链表):\n");
	l.PrintPos();
	l.Sort();
	l.Rearrange();
	printf("排序后(重排记录):\n");
	l.PrintPos();
    return 0;
}

