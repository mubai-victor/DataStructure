// UsualList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Test.h"
#include "Function.h"
int _tmain(int argc, _TCHAR* argv[])
{
	//Link p, h;
	//LinkList L;
	//Status i;
	//int j, k; 
	//InitList(L); // ��ʼ���յ����Ա�L
	//for (j = 1; j <= 2; j++)
	//{
	//	MakeNode(p, j); // ������pָ��ֵΪj�Ľ��
	//	InsFirst(L, L.tail, p); // ���ڱ�β
	//}
	//OrderInsert(L, 0, comp); // ��������������ͷ
	//for (j = 0; j <= 3; j++)
	//{
	//	i = LocateElem(L, j, p, comp);
	//	if (i)
	//		printf("��������ֵΪ%d��Ԫ�ء� \n", p->data);
	//	else
	//		printf("������û��ֵΪ%d��Ԫ�ء� \n", j);
	//}
	//printf("������� ");
	//ListTraverse(L, print); // ���L
	//for (j = 1; j <= 4; j++)
	//{
	//	printf("ɾ����ͷ��㣺 ");
	//	DelFirst(L, L.head, p); // ɾ��L���׽�㣬����p����
	//	if (p)
	//		printf("%d\n", GetCurElem(p));
	//	else
	//		printf("��գ��޷�ɾ�� p=%u\n", p);
	//}
	//printf("L�н�����=%d L�Ƿ�� %d(1:�� 0:��)\n", ListLength(L), ListEmpty(L));
	//MakeNode(p, 10);
	//p->next = NULL; // β���
	//for (j = 4; j >= 1; j--)
	//{
	//	MakeNode(h, j * 2);
	//	h->next = p;
	//	p = h;
	//} // hָ��һ��5����㣬��ֵ������2 4 6 8 10
	//Append(L, h); // �ѽ��h��������������L�����һ�����֮��
	//OrderInsert(L, 12, comp); // ��������������βͷ
	//OrderInsert(L, 7, comp); // ���������������м�
	//printf("������� ");
	//ListTraverse(L, print); // ���L
	//for (j = 1; j <= 2; j++)
	//{
	//	p = LocateElem(L, j * 5, equal);
	//	if (p)
	//		printf("L�д���ֵΪ%d�Ľ�㡣 \n", j * 5);
	//	else
	//		printf("L�в�����ֵΪ%d�Ľ�㡣 \n", j * 5);
	//}
	//for (j = 1; j <= 2; j++)
	//{
	//	LocatePos(L, j, p); // pָ��L�ĵ�j�����
	//	h = PriorPos(L, p); // hָ��p��ǰ��
	//	if (h)
	//		printf("%d��ǰ����%d�� \n", p->data, h->data);
	//	else
	//		printf("%dûǰ���� \n", p->data);
	//}
	//k = ListLength(L);
	//for (j = k - 1; j <= k; j++)
	//{
	//	LocatePos(L, j, p); // pָ��L�ĵ�j�����
	//	h = NextPos(p); // hָ��p�ĺ��
	//	if (h)
	//		printf("%d�ĺ����%d�� \n", p->data, h->data);
	//	else
	//		printf("%dû��̡� \n", p->data);
	//}
	//printf("L�н�����=%d L�Ƿ�� %d(1:�� 0:��)\n", ListLength(L), ListEmpty(L));
	//p = GetLast(L); // pָ�����һ�����
	//SetCurElem(p, 15); // �����һ������ֵ��Ϊ15
	//printf("��1��Ԫ��Ϊ%d ���1��Ԫ��Ϊ%d\n", GetCurElem(GetHead(L)->next), GetCurElem(p));
	//MakeNode(h, 10);
	//InsBefore(L, p, h); // ��10�嵽β���֮ǰ�� pָ���½��
	//p = p->next; // p�ָ�Ϊβ���
	//MakeNode(h, 20);
	//InsAfter(L, p, h); // ��20�嵽β���֮��
	//k = ListLength(L);
	//printf("����ɾ����β��㲢�����ֵ�� ");
	//for (j = 0; j <= k; j++)
	//if (!(i = Remove(L, p))) // ɾ�����ɹ�
	//	printf("ɾ�����ɹ� p=%u\n", p);
	//else
	//	printf("%d ", p->data);
	//MakeNode(p, 29); // �ؽ�����1�����(29)������
	//InsFirst(L, L.head, p);
	//DestroyList(L); // ������������L
	//printf("������������L֮��: L.head=%u L.tail=%u L.len=%d\n", L.head, L.tail, L.length);
	LinkList La, Lb, Lc;
	int j;
	InitList(La);
	for (j = 1; j <= 5; j++)
		ListInsert_L(La, j, j); // ˳����� 1�� 2�� 3�� 4�� 5
	printf("La=");
	ListTraverse(La, print);
	InitList(Lb);
	for (j = 1; j <= 5; j++)
		ListInsert_L(Lb, j, 2 * j); // ˳����� 2�� 4�� 6�� 8�� 10
	printf("Lb=");
	ListTraverse(Lb, print);
	MergeList_L(La, Lb, Lc, diff); // �鲢La��Lb������Lc
	printf("Lc=");
	ListTraverse(Lc, print);
	DestroyList(Lc);
	getchar();
	system("PUASE");
	return 0;
}

