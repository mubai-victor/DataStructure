// LInerList_chain.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "Test.h"
#include "Function.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//LinkList L; // ��main2-1.cpp��ͬ
	//ElemType e, e0;
	//Status i;
	//int j, k;
	//InitList(L);
	//for (j = 1; j <= 5; j++)
	//	i = ListInsert(L, 1, j);
	//printf("��L�ı�ͷ���β���1��5�� L=");
	//ListTraverse(L, print); // ���ζ�Ԫ�ص���print()�����Ԫ�ص�ֵ
	//i = ListEmpty(L);
	//printf("L�Ƿ�գ� i=%d(1:�� 0:��)\n", i);
	//ClearList(L);
	//printf("���L�� L=");
	//ListTraverse(L, print);
	//i = ListEmpty(L);
	//printf("L�Ƿ�գ� i=%d(1:�� 0:��)\n", i);
	//for (j = 1; j <= 10; j++)
	//	ListInsert(L, j, j);
	//printf("��L�ı�β���β���1��10�� L=");
	//ListTraverse(L, print);
	//GetElem(L, 5, e);
	//printf("��5��Ԫ�ص�ֵΪ%d\n", e);
	//for (j = 0; j <= 1; j++)
	//{
	//	k = LocateElem(L, j, equal);
	//	if (k)
	//		printf("��%d��Ԫ�ص�ֵΪ%d\n", k, j);
	//	else
	//		printf("û��ֵΪ%d��Ԫ��\n", j);
	//}
	//for (j = 1; j <= 2; j++) // ����ͷ��������
	//{
	//	GetElem(L, j, e0); // �ѵ�j�����ݸ���e0
	//	i = PriorElem(L, e0, e); // ��e0��ǰ��
	//	if (i == INFEASIBLE)
	//		printf("Ԫ��%d��ǰ��\n", e0);
	//	else
	//		printf("Ԫ��%d��ǰ��Ϊ%d\n", e0, e);
	//}
	//for (j = ListLength(L) - 1; j <= ListLength(L); j++) // �����������
	//{
	//	GetElem(L, j, e0); // �ѵ�j�����ݸ���e0
	//	i = NextElem(L, e0, e); // ��e0�ĺ��
	//	if (i == INFEASIBLE)
	//		printf("Ԫ��%d�޺��\n", e0);
	//	else
	//		printf("Ԫ��%d�ĺ��Ϊ%d\n", e0, e);
	//}
	//k = ListLength(L); // kΪ��
	//for (j = k + 1; j >= k; j--)
	//{
	//	i = ListDelete(L, j, e); // ɾ����j������
	//	if (i == ERROR)
	//		printf("ɾ����%d��Ԫ��ʧ��\n", j);
	//	else
	//		printf("ɾ����%d��Ԫ�سɹ�����ֵΪ%d\n", j, e);
	//}
	//printf("�������L��Ԫ�أ� ");
	//ListTraverse(L, print);
	//DestroyList(L);
	//printf("����L�� L=%u\n", L);
	//getchar();
	//return 0;
	//LinkList La, Lb; // �˾���algo2-1.cpp��ͬ(��Ϊ���ò�ͬ�Ľṹ)
	//int j;
	//InitList(La);
	//for (j = 1; j <= 5; j++) // �ڱ�La�в���5��Ԫ��
	//	ListInsert(La, j, j);
	//printf("La= "); // �����La������
	//ListTraverse(La, print);
	//InitList(Lb); // Ҳ�ɲ��ж��Ƿ񴴽��ɹ�
	//for (j = 1; j <= 5; j++) // �ڱ�Lb�в���5��Ԫ��
	//	ListInsert(Lb, j, 2 * j);
	//printf("Lb= "); // �����Lb������
	//ListTraverse(Lb, print);
	//Union(La, Lb);
	//printf("new La= "); // ����±�La������
	//ListTraverse(La, print);
	//getchar();


	LinkList La, Lb, Lc; // �˾���algo2-2.cpp��ͬ
	int j, a[4] = { 3, 5, 8, 11 }, b[7] = { 2, 6, 8, 9, 11, 15, 20 }; // �̿�����22������
	InitList(La); // �����ձ�La
	for (j = 1; j <= 4; j++) // �ڱ�La�в���4��Ԫ��
		ListInsert(La, j, a[j - 1]);
	printf("La= "); // �����La������
	ListTraverse(La, print);
	InitList(Lb); // �����ձ�Lb
	for (j = 1; j <= 7; j++) // �ڱ�Lb�в���7��Ԫ��
		ListInsert(Lb, j, b[j - 1]);
	printf("Lb= "); // �����Lb������
	ListTraverse(Lb, print);
	MergeList(La, Lb, Lc);
	printf("Lc= "); // �����Lc������
	ListTraverse(Lc, print);
	printf("length of Lc= %d",ListLength(Lc));
	getchar();
	return 0;
}

