// Lists_.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"
#include "iostream"
using namespace std;

int main()
{
	char p[80];
	SString t;
	GList l, m;
	printf("空广义表l的深度=%d l是否空？ %d(1:是 0:否)\n", l.GListDepth(), l.GListEmpty());
	printf("请输入广义表l(书写形式：空表:(),单原子:(a),其它:(a,(b),c)):\n");
	l.CreateGList("List.txt");
	printf("广义表l的长度=%d\n", l.GListLength());
	printf("广义表l的深度=%d l是否空？ %d(1:是 0:否)\n", l.GListDepth(), l.GListEmpty());
	printf("遍历广义表l： \n");
	l.Traverse_GL(visit);
	printf("\n复制广义表m=l\n");
	l.CopyGList(m);
	printf("广义表m的长度=%d\n", m.GListLength());
	printf("广义表m的深度=%d\n", m.GListDepth());
	printf("遍历广义表m： \n");
	m.Traverse_GL(visit);
	m.DestroyGList();
	m = l.GetHead();
	printf("\nm是l的表头元素，遍历m： \n");
	m.Traverse_GL(visit);
	m.DestroyGList();
	m = l.GetTail();
	printf("\nm是由l的表尾形成的广义表，遍历广义表m： \n");
	m.Traverse_GL(visit);
	m.InsertFirst_GL(l);
	printf("\n插入广义表l为m的表头，遍历广义表m： \n");
	m.Traverse_GL(visit);
	printf("\n删除m的表头，遍历广义表m： \n");
	l.DestroyGList();
	m.DeleteFirst_GL(l);
	m.Traverse_GL(visit);
	printf("\n");
	m.DestroyGList();
	int i;
	return 0;
}

