// B-Tree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	Record r[N] = { { 24,"1" },{ 45,"2" },{ 53,"3" },{ 12,"4" },{ 37,"5" },{ 50,"6" },{ 61,"7" },{ 90,"8" },
	{ 100,"9" },{ 70,"10" },{ 3,"11" },{ 30,"12" },{ 26,"13" },{ 85,"14" },{ 3,"15" },
	{ 7,"16" } }; // (以教科书中图9.16为例)
	DSTree t;
	Result s;
	int i;
	for (i = 0; i<N; i++)
	{
		s = t.SearchDSTree(r[i].key);
		if (!s.tag)
			t.InsertDSTree(&r[i], s.pt, s.i);
	}
	printf("按关键字的顺序遍历B_树:\n");
	t.TraverseDSTree(print);
	printf("\n请输入待查找记录的关键字: ");
	cin >> i;
	s = t.SearchDSTree(i);
	if (s.tag)
		print(*(s.pt), s.i);
	else
		printf("没找到");
	printf("\n");
    return 0;
}

