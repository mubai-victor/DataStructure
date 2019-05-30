// BalanceTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	BalanceTree dt;
	BiTree p;
	Status k;
	int i;
	KeyType j;
	ElemType r[N] = { { 13,1 },{ 24,2 },{ 37,3 },{ 90,4 },{ 53,5 } };
	for (i = 0; i<N; i++)
		dt.InsertAVL(r[i]); // 建平衡二叉树
	dt.TraverseBST(print); // 先序遍历平衡二叉树
	printf("先序遍历平衡二叉树\n");
	printf("\n请输入待查找的关键字: ");
	cin >> j;
	p = dt.SearchBST(j); // 查找给定关键字的记录
	if (p)
		print(p->data);
	else
		printf("表中不存在此值");
	printf("\n");
    return 0;
}

