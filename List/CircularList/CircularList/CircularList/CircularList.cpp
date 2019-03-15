// CircularList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Test.h"
#include "Function.h"
void MergeList(LinkList &La, LinkList Lb)
{ // 将Lb合并到La的表尾，由La指示新表
	LinkList p = Lb->next;
	Lb->next = La->next;
	La->next = p->next;
	free(p);
	La = Lb;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n = 5, i;
	LinkList La, Lb;
	InitList(La);
	for (i = 1; i <= n; i++)
		ListInsert(La, i, i);
	printf("La="); // 输出链表La的内容
	ListTraverse(La, print);
	InitList(Lb);
	for (i = 1; i <= n; i++)
		ListInsert(Lb, 1, i * 2);
	printf("Lb="); // 输出链表Lb的内容
	ListTraverse(Lb, print);
	MergeList(La, Lb);
	printf("La+Lb="); // 输出合并后的链表的内容
	ListTraverse(La, print);

	//LinkList L;
	//ElemType e;
	//int j;
	//Status i;
	//InitList(L); // 初始化单循环链表L
	//i = ListEmpty(L);
	//printf("L是否空 i=%d(1:空 0:否)\n", i);
	//ListInsert(L, 1, 3); // 在L中依次插入3,5
	//ListInsert(L, 2, 5);
	//i = GetElem(L, 1, e);
	//j = ListLength(L);
	//printf("L中数据元素个数=%d,第1个元素的值为%d。 \n", j, e);
	//printf("L中的数据元素依次为");
	//ListTraverse(L, print);
	//PriorElem(L, 5, e); // 求元素5的前驱
	//printf("5前面的元素的值为%d。 \n", e);
	//NextElem(L, 3, e); // 求元素3的后继
	//printf("3后面的元素的值为%d。 \n", e);
	//printf("L是否空 %d(1:空 0:否)\n", ListEmpty(L));
	//j = LocateElem(L, 5, equal);
	//if (j)
	//	printf("L的第%d个元素为5。 \n", j);
	//else
	//	printf("不存在值为5的元素\n");
	//i = ListDelete(L, 2, e);
	//printf("删除L的第2个元素： \n");
	//if (i)
	//{
	//	printf("删除的元素值为%d,现在L中的数据元素依次为", e);
	//	ListTraverse(L, print);
	//}
	//else
	//	printf("删除不成功！ \n");
	//ClearList(L);
	//printf("清空L后， L是否空： %d(1:空 0:否)\n", ListEmpty(L));
	//DestroyList(L);
	system("PAUSE");
	return 0;
}

