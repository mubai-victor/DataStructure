// TreeDoubleChain.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"
using namespace std;

int main()
{
	int i;
	Tree T, c;
	BiTNode*p = NULL;
	TElemType e1, e2;
	printf("构造空二叉树后,树空否？ %d(1:是 0:否)树的深度=%d\n", T.BiTreeEmpty(), T.BiTreeDepth());
	e1 = T.Root();
	if (e1 != Nil)
		printf("二叉树的根为:%c\n", e1);
	else
		printf("树空，无根\n");
	T.CreateBiTree("TreeDoubleChain.txt");
	printf("建立二叉树后,树空否？ %d(1:是 0:否) 树的深度=%d\n", T.BiTreeEmpty(), T.BiTreeDepth());
	e1 = T.Root();
	if (e1 != Nil)
		printf("二叉树的根为%c\n", e1);
	else
		printf("树空，无根\n");
	printf("中序递归遍历二叉树:\n");
	T.InOrderTraverse(visit);
	printf("\n后序递归遍历二叉树:\n");
	T.PostOrderTraverse(visit);
	//printf("\n层序遍历二叉树:\n");
	//T.LevelOrderTraverse(visit);
	printf("\n请输入一个结点的值: ");
	cin >> e1;
	p = T.Point(e1); // p为e1的指针
	printf("结点的值为%c\n", T.Value(p));
	printf("欲改变此结点的值，请输入新值: ");
	cin >> e2; // 后一个%*c吃掉回车符，为调用CreateBiTree()做准备
	T.Assign(p, e2);
	printf("层序遍历二叉树:\n");
	T.LevelOrderTraverse(visit);
	e1 = T.Parent(e2);
	if (e1 != Nil)
		printf("%c的双亲是%c\n", e2, e1);
	else
		printf("%c没有双亲\n", e2);
	e1 = T.LeftChild(e2);
	if (e1 != Nil)
		printf("%c的左孩子是%c\n", e2, e1);
	else
		printf("%c没有左孩子\n", e2);
	e1 = T.RightChild(e2);
	if (e1 != Nil)
		printf("%c的右孩子是%c\n", e2, e1);
	else
		printf("%c没有右孩子\n", e2);
	e1 = T.LeftSibling(e2);
	if (e1 != Nil)
		printf("%c的左兄弟是%c\n", e2, e1);
	else
		printf("%c没有左兄弟\n", e2);
	e1 = T.RightSibling(e2);
	if (e1 != Nil)
		printf("%c的右兄弟是%c\n", e2, e1);
	else
		printf("%c没有右兄弟\n", e2);
	printf("构造一个右子树为空的二叉树c:\n");
	c.CreateBiTree("TreeDoubleChain1.txt");
	printf("先序递归遍历二叉树c:\n");
	c.PreOrderTraverse(visit);
	printf("\n层序遍历二叉树c:\n");
	c.LevelOrderTraverse(visit);
	printf("树c插到树T中,请输入树T中树c的双亲结点 c为左(0)或右(1)子树: ");
	cin >> e1 >> i;
	p = T.Point(e1); // p是T中树c的双亲结点指针
	T.InsertChild(p, i, c.Point(c.Root()));
	printf("先序递归遍历二叉树:\n");
	T.PreOrderTraverse(visit);
	printf("\n中序非递归遍历二叉树:\n");
	T.InOrderTraverse1(visit);
	printf("删除子树,请输入待删除子树的双亲结点 左(0)或右(1)子树: ");
	cin >> e1 >> i;
	p = T.Point(e1);
	T.DeleteChild(p, i);
	printf("先序递归遍历二叉树:\n");
	T.PreOrderTraverse(visit);
	printf("\n中序非递归遍历二叉树(另一种方法):\n");
	T.InOrderTraverse2(visit);
	T.DestroyBiTree();
	return 0;
}

