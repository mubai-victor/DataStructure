// LInerList_chain.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "Test.h"
#include "Function.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//LinkList L; // 与main2-1.cpp不同
	//ElemType e, e0;
	//Status i;
	//int j, k;
	//InitList(L);
	//for (j = 1; j <= 5; j++)
	//	i = ListInsert(L, 1, j);
	//printf("在L的表头依次插入1～5后： L=");
	//ListTraverse(L, print); // 依次对元素调用print()，输出元素的值
	//i = ListEmpty(L);
	//printf("L是否空： i=%d(1:是 0:否)\n", i);
	//ClearList(L);
	//printf("清空L后： L=");
	//ListTraverse(L, print);
	//i = ListEmpty(L);
	//printf("L是否空： i=%d(1:是 0:否)\n", i);
	//for (j = 1; j <= 10; j++)
	//	ListInsert(L, j, j);
	//printf("在L的表尾依次插入1～10后： L=");
	//ListTraverse(L, print);
	//GetElem(L, 5, e);
	//printf("第5个元素的值为%d\n", e);
	//for (j = 0; j <= 1; j++)
	//{
	//	k = LocateElem(L, j, equal);
	//	if (k)
	//		printf("第%d个元素的值为%d\n", k, j);
	//	else
	//		printf("没有值为%d的元素\n", j);
	//}
	//for (j = 1; j <= 2; j++) // 测试头两个数据
	//{
	//	GetElem(L, j, e0); // 把第j个数据赋给e0
	//	i = PriorElem(L, e0, e); // 求e0的前驱
	//	if (i == INFEASIBLE)
	//		printf("元素%d无前驱\n", e0);
	//	else
	//		printf("元素%d的前驱为%d\n", e0, e);
	//}
	//for (j = ListLength(L) - 1; j <= ListLength(L); j++) // 最后两个数据
	//{
	//	GetElem(L, j, e0); // 把第j个数据赋给e0
	//	i = NextElem(L, e0, e); // 求e0的后继
	//	if (i == INFEASIBLE)
	//		printf("元素%d无后继\n", e0);
	//	else
	//		printf("元素%d的后继为%d\n", e0, e);
	//}
	//k = ListLength(L); // k为表长
	//for (j = k + 1; j >= k; j--)
	//{
	//	i = ListDelete(L, j, e); // 删除第j个数据
	//	if (i == ERROR)
	//		printf("删除第%d个元素失败\n", j);
	//	else
	//		printf("删除第%d个元素成功，其值为%d\n", j, e);
	//}
	//printf("依次输出L的元素： ");
	//ListTraverse(L, print);
	//DestroyList(L);
	//printf("销毁L后： L=%u\n", L);
	//getchar();
	//return 0;
	//LinkList La, Lb; // 此句与algo2-1.cpp不同(因为采用不同的结构)
	//int j;
	//InitList(La);
	//for (j = 1; j <= 5; j++) // 在表La中插入5个元素
	//	ListInsert(La, j, j);
	//printf("La= "); // 输出表La的内容
	//ListTraverse(La, print);
	//InitList(Lb); // 也可不判断是否创建成功
	//for (j = 1; j <= 5; j++) // 在表Lb中插入5个元素
	//	ListInsert(Lb, j, 2 * j);
	//printf("Lb= "); // 输出表Lb的内容
	//ListTraverse(Lb, print);
	//Union(La, Lb);
	//printf("new La= "); // 输出新表La的内容
	//ListTraverse(La, print);
	//getchar();


	LinkList La, Lb, Lc; // 此句与algo2-2.cpp不同
	int j, a[4] = { 3, 5, 8, 11 }, b[7] = { 2, 6, 8, 9, 11, 15, 20 }; // 教科书例22的数据
	InitList(La); // 创建空表La
	for (j = 1; j <= 4; j++) // 在表La中插入4个元素
		ListInsert(La, j, a[j - 1]);
	printf("La= "); // 输出表La的内容
	ListTraverse(La, print);
	InitList(Lb); // 创建空表Lb
	for (j = 1; j <= 7; j++) // 在表Lb中插入7个元素
		ListInsert(Lb, j, b[j - 1]);
	printf("Lb= "); // 输出表Lb的内容
	ListTraverse(Lb, print);
	MergeList(La, Lb, Lc);
	printf("Lc= "); // 输出表Lc的内容
	ListTraverse(Lc, print);
	printf("length of Lc= %d",ListLength(Lc));
	getchar();
	return 0;
}

