// DynamicTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	BiTree  p;
	BSTree dt;
	int i;
	KeyType j;
	ElemType r[N] = { { 45,1 },{ 12,2 },{ 53,3 },{ 3,4 },{ 37,5 },{ 24,6 },{ 100,7 },{ 61,8 },{ 90,9 },{ 78,10 } };
	// 以教科书图9.7(a)为例，另加除关键字之外的其他信息
	for (i = 0; i<N; i++)
		dt.InsertBST(r[i]); // 依次插入数据元素
	dt.TraverseBSTree(print);
	printf("\n请输入待查找的值: ");
	cin >> j;
	p = dt.SearchBST(j);
	if (p)
	{
		printf("表中存在此值。");
		dt.DeleteBST(j);
		printf("删除此值后:\n");
		dt.TraverseBSTree(print);
		printf("\n");
	}
	else
		printf("表中不存在此值\n");
    return 0;
}

