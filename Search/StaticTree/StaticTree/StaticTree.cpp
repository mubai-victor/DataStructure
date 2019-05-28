// StaticTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	SOSTree t;
	Status i;
	KeyType s; // 以教科书例91的数据为例
	ElemType r[N] = { { 'A',1 },{ 'B',1 },{ 'C',2 },{ 'D',5 },{ 'E',3 },{ 'F',4 },{ 'G',4 },{ 'H',3 },{ 'I',5 } };
	t.CreateSOSTree(r); // 由有序表构造一棵次优查找树
	t.Traverse(print);
	printf("\n请输入待查找的字符: ");
	cin >> s;
	i = t.Search_SOSTree(s);
	if (i==ERROR)
		printf("表中不存在此字符\n");
    return 0;
}

