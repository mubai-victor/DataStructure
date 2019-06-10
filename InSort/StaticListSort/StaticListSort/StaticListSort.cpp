// StaticListSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	RedType d[N] = { { 49,1 },{ 38,2 },{ 65,3 },{ 97,4 },{ 76,5 },{ 13,6 },{ 27,7 },{ 49,8 } };
	SLinkListType l1, l2;
	int *adr, i;
	l1.TableInsert(d, N);
	l2 = l1; // 复制静态链表l2与l1相同
	printf("排序前:\n");
	l1.Print();
	l1.Arrange();
	printf("l1排序后:\n");
	l1.Print();
	l2.Sort();
	l2.Rearrange();
	printf("l2排序后:\n");
	l2.Print();
    return 0;
}

