// ForestChain.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

#define FILENAME "ForestChain.txt"
#define FILENAME1 "ForestChain1.txt"
using namespace std;

int main()
{
	int i;
	CSTree T, p;
	Node*q = NULL;
	TElemType e, e1;
	printf("构造空树后,树空否? %d(1:是 0:否) 树根为%c树的深度为%d\n", T.TreeEmpty(), T.Root(),T.TreeDepth());
	T.CreateTree(FILENAME);
	printf("构造树T后,树空否? %d(1:是 0:否) 树根为%c树的深度为%d\n", T.TreeEmpty(), T.Root(), T.TreeDepth());
	printf("先根遍历树T:\n");
	T.PreOrderTraverse(visit);
	printf("\n请输入待修改的结点的值,新值: ");
	cin >> e >> e1;
	T.Assign(e, e1);
	printf("后根遍历修改后的树T:\n");
	T.PostOrderTraverse(visit);
	printf("\n%c的双亲是%c,长子是%c,下一个兄弟是%c\n", e1, T.Parent(e1), T.LeftChild(e1), T.RightSibling(e1));
	printf("建立树p:\n");
	p.CreateTree(FILENAME1);
	printf("层序遍历树p:\n");
	p.LevelOrderTraverse(visit);
	printf("\n将树p插到树T中，请输入T中p的双亲结点 子树序号: ");
	cin >> e >> i;
	q = T.Point(e);
	T.InsertChild(q, i, p);
	printf("层序遍历树T:\n");
	T.LevelOrderTraverse(visit);
	printf("\n删除树T中结点e的第i棵子树，请输入e i: ");
	cin >> e >> i;
	q = T.Point(e);
	T.DeleteChild(q, i);
	printf("层序遍历树T:\n", e, i);
	T.LevelOrderTraverse(visit);
	printf("\n");
	T.DestroyTree();
	return 0;
}

