// Linerlist_order.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

#include "Header\Test.h"
#include "Header\Function.h"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	SqList La, Lb, Lc;
	int j, a[4] = { 3, 5, 8, 11 }, b[7] = { 2, 6, 8, 9, 11, 15, 20 };
	InitList(La); // 创建空表La
	for (j = 1; j <= 4; j++) // 在表La中插入4个元素
		ListInsert(La, j, a[j - 1]);
	printf("La= "); // 输出表La的内容
	ListTraverse(La, print1);
	InitList(Lb); // 创建空表Lb
	for (j = 1; j <= 7; j++) // 在表Lb中插入7个元素
		ListInsert(Lb, j, b[j - 1]);
	printf("Lb= "); // 输出表Lb的内容
	ListTraverse(Lb, print1);
	MergeList(La, Lb, Lc);
	printf("Lc= "); // 输出表Lc的内容
	ListTraverse(Lc, print1);
	//***********************************************
	//SqList La, Lb;
	//int j;
	//InitList(La); // 创建空表La。如不成功，则会退出程序的运行
	//for (j = 1; j <= 5; j++) // 在表La中插入5个元素，依次为1、 2、 3、 4、 5
	//	ListInsert(La, j, j);
	//printf("La= "); // 输出表La的内容
	//ListTraverse(La, print1);
	//InitList(Lb); // 创建空表Lb
	//for (j = 1; j <= 5; j++) // 在表Lb中插入5个元素，依次为2、 4、 6、 8、 10
	//	ListInsert(Lb, j, 2 * j);
	//printf("Lb= "); // 输出表Lb的内容
	//ListTraverse(Lb, print1);
	//Union(Lb, La); // 调用Union()，将Lb中满足条件的元素插入La
	//printf("new La= "); // 输出新表La的内容
	//ListTraverse(La, print1);
	//**************************************
	//SqList L;
	//ElemType e, e0;
	//Status i;
	//int j, k;
	//InitList(L);
	//printf("初始化L后： L.elem=%u L.length=%d L.listsize=%d\n", L.elembase, L.length, L.listsize);
	//for (j = 1; j <= 5; j++)
	//	i = ListInsert(L, 1, j);
	//printf("在L的表头依次插入1～5后： *L.elem=");
	//for (j = 1; j <= 5; j++)
	//	cout << *(L.elembase + j - 1) <<' ';
	//cout << endl;
	//printf("L.elem=%u L.length=%d L.listsize=%d ", L.elembase, L.length, L.listsize);
	//i = ListEmpty(L);
	//printf("L是否空： i=%d(1:是 0:否)\n", abs(i)-4);
	//ClearList(L);
	//printf("清空L后： L.elem=%u L.length=%d L.listsize=%d ", L.elembase, L.length, L.listsize);
	//i = ListEmpty(L);
	//printf("L是否空： i=%d(1:是 0:否)\n", abs(i) - 4);
	//for (j = 1; j <= 10; j++)
	//	ListInsert(L, j, j);
	//printf("在L的表尾依次插入1～10后： *L.elem=");
	//for (j = 1; j <= 10; j++)
	//	cout << *(L.elembase + j - 1) <<' ';
	//cout << endl;
	//printf("L.elem=%u L.length=%d L.listsize=%d\n", L.elembase, L.length, L.listsize);
	//ListInsert(L, 1, 0);
	//printf("在L的表头插入0后： *L.elem=");
	//for (j = 1; j <= ListLength(L); j++) // ListLength(L)为元素个数
	//	cout << *(L.elembase + j - 1) << ' ';
	//cout << endl;
	//printf("L.elem=%u(有可能改变) L.length=%d(改变) L.listsize=%d(改变)\n", L.elembase, L.length,
	//	L.listsize);
	//GetElem(L, 5, e);
	//printf("第5个元素的值为%d\n", e);
	//for (j = 10; j <= 11; j++)
	//{
	//	k = LocateElem(L, j, equal);
	//	if (k != INFEASIBLE) // k不为0，表明有符合条件的元素，且其位序为k
	//		printf("第%d个元素的值为%d\n", k, j);
	//	else
	//		printf("没有值为%d的元素\n", j);
	//}
	//for (j = 3; j <= 4; j++)
	//{
	//	k = LocateElem(L, j, sq);
	//	if (k != INFEASIBLE) // k不为0，表明有符合条件的元素，且其位序为k
	//		printf("第%d个元素的值为%d的平方\n", k, j);
	//	else
	//		printf("没有值为%d的平方的元素\n", j);
	//}
	//for (j = 1; j <= 2; j++) // 测试头两个数据
	//{
	//	GetElem(L, j, e0); // 把第j个数据赋给e0
	//	i = PriorElem(L, e0, e); // 求e0的前驱
	//	if (i == ERROR)
	//		printf("元素%d无前驱\n", e0);
	//	else
	//		printf("元素%d的前驱为%d\n", e0, e);
	//}
	//for (j = ListLength(L) - 1; j <= ListLength(L); j++) // 最后两个数据
	//{
	//	GetElem(L, j, e0); // 把第j个数据赋给e0
	//	i = NextElem(L, e0, e); // 求e0的后继
	//	if (i == ERROR)
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
	//ListTraverse(L, print1); // 依次对元素调用print1()，输出元素的值
	//printf("L的元素值加倍后： ");
	//ListTraverse(L, dbl); // 依次对元素调用dbl()，元素值乘2
	//ListTraverse(L, print1);
	//DestroyList(L);
	//printf("销毁L后： L.elem=%u L.length=%d L.listsize=%d\n", L.elembase, L.length, L.listsize);
	getchar();
	return 0;
}

