// Tree_Array.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Test.h"
#include "Function.h"
using namespace std;

int main()
{
	Status i;
	int j;
	position p;
	TElemType e;
	Tree T, s;
	T.CreateBiTree("Tree_Array.txt");
	cout << "建立二叉树后,树空否？ " << T.BiTreeEmpty() << "(1:是 0:否) 树的深度=" << T.BiTreeDepth()
		<< endl;
	i = T.Root(e);
	if (i)
		cout << "二叉树的根为" << e << endl;
	else
		cout << "树空，无根" << endl;
	cout << "层序遍历二叉树:" << endl;
	T.LevelOrderTraverse(visit);
	cout << "中序遍历二叉树:" << endl;
	T.InOrderTraverse(visit);
	cout << "后序遍历二叉树:" << endl;
	T.PostOrderTraverse(visit);
	cout << "请输入待修改结点的层号 本层序号: ";
	cin >> p.level >> p.order;
	e = T.Value(p);
	cout << "待修改结点的原值为" << e << "请输入新值: ";
	cin >> e;
	T.Assign(p, e);
	cout << "先序遍历二叉树:" << endl;
	T.PreOrderTraverse(visit);
	cout << "结点" << e << "的双亲为" << T.Parent(e) << ",左右孩子分别为";
	cout << T.LeftChild(e) << "," << T.RightChild(e) << ",左右兄弟分别为";
	cout << T.LeftSibling(e) << "," << T.RightSibling(e) << endl;
	cout << "建立右子树为空的树s:" << endl;
	s.CreateBiTree("Tree_Array1.txt");
	cout << "树s插到树T中,请输入树T中树s的双亲结点 s为左(0)或右(1)子树: ";
	cin >> e >> j;
	T.InsertChild(e, j, s);
	T.Print();
	cout << "删除子树,请输入待删除子树根结点的层号 本层序号 左(0)或右(1)子树: ";
	cin >> p.level >> p.order >> j;
	T.DeleteChild(p, j);
	T.Print();
	T.ClearBiTree();
	cout << "清除二叉树后,树空否？ " << T.BiTreeEmpty() << "(1:是 0:否) 树的深度=" << T.BiTreeDepth()
		<< endl;
	i = T.Root(e);
	if (i)
		cout << "二叉树的根为" << e << endl;
	else
		cout << "树空，无根" << endl;
    return 0;
}

