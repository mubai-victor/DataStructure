// Graph2Forest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	AMLGraph g;
	CSTree t;
	printf("请选择无向图\n");
	g.CreateGraph("Graph.txt"); // 构造无向图g
	g.Display(); // 输出无向图g
	t.DFSForest(g); // 建立无向图g的深度优先生成森林的孩子—兄弟链表t
	printf("先序遍历生成森林：\n");
	t.PreOrderTraverse(visit); // 先序遍历生成森林的孩子—兄弟链表t
	printf("\n");
    return 0;
}

