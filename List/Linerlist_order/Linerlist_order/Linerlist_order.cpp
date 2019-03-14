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
	InitList(La); // �����ձ�La
	for (j = 1; j <= 4; j++) // �ڱ�La�в���4��Ԫ��
		ListInsert(La, j, a[j - 1]);
	printf("La= "); // �����La������
	ListTraverse(La, print1);
	InitList(Lb); // �����ձ�Lb
	for (j = 1; j <= 7; j++) // �ڱ�Lb�в���7��Ԫ��
		ListInsert(Lb, j, b[j - 1]);
	printf("Lb= "); // �����Lb������
	ListTraverse(Lb, print1);
	MergeList(La, Lb, Lc);
	printf("Lc= "); // �����Lc������
	ListTraverse(Lc, print1);
	//***********************************************
	//SqList La, Lb;
	//int j;
	//InitList(La); // �����ձ�La���粻�ɹ�������˳����������
	//for (j = 1; j <= 5; j++) // �ڱ�La�в���5��Ԫ�أ�����Ϊ1�� 2�� 3�� 4�� 5
	//	ListInsert(La, j, j);
	//printf("La= "); // �����La������
	//ListTraverse(La, print1);
	//InitList(Lb); // �����ձ�Lb
	//for (j = 1; j <= 5; j++) // �ڱ�Lb�в���5��Ԫ�أ�����Ϊ2�� 4�� 6�� 8�� 10
	//	ListInsert(Lb, j, 2 * j);
	//printf("Lb= "); // �����Lb������
	//ListTraverse(Lb, print1);
	//Union(Lb, La); // ����Union()����Lb������������Ԫ�ز���La
	//printf("new La= "); // ����±�La������
	//ListTraverse(La, print1);
	//**************************************
	//SqList L;
	//ElemType e, e0;
	//Status i;
	//int j, k;
	//InitList(L);
	//printf("��ʼ��L�� L.elem=%u L.length=%d L.listsize=%d\n", L.elembase, L.length, L.listsize);
	//for (j = 1; j <= 5; j++)
	//	i = ListInsert(L, 1, j);
	//printf("��L�ı�ͷ���β���1��5�� *L.elem=");
	//for (j = 1; j <= 5; j++)
	//	cout << *(L.elembase + j - 1) <<' ';
	//cout << endl;
	//printf("L.elem=%u L.length=%d L.listsize=%d ", L.elembase, L.length, L.listsize);
	//i = ListEmpty(L);
	//printf("L�Ƿ�գ� i=%d(1:�� 0:��)\n", abs(i)-4);
	//ClearList(L);
	//printf("���L�� L.elem=%u L.length=%d L.listsize=%d ", L.elembase, L.length, L.listsize);
	//i = ListEmpty(L);
	//printf("L�Ƿ�գ� i=%d(1:�� 0:��)\n", abs(i) - 4);
	//for (j = 1; j <= 10; j++)
	//	ListInsert(L, j, j);
	//printf("��L�ı�β���β���1��10�� *L.elem=");
	//for (j = 1; j <= 10; j++)
	//	cout << *(L.elembase + j - 1) <<' ';
	//cout << endl;
	//printf("L.elem=%u L.length=%d L.listsize=%d\n", L.elembase, L.length, L.listsize);
	//ListInsert(L, 1, 0);
	//printf("��L�ı�ͷ����0�� *L.elem=");
	//for (j = 1; j <= ListLength(L); j++) // ListLength(L)ΪԪ�ظ���
	//	cout << *(L.elembase + j - 1) << ' ';
	//cout << endl;
	//printf("L.elem=%u(�п��ܸı�) L.length=%d(�ı�) L.listsize=%d(�ı�)\n", L.elembase, L.length,
	//	L.listsize);
	//GetElem(L, 5, e);
	//printf("��5��Ԫ�ص�ֵΪ%d\n", e);
	//for (j = 10; j <= 11; j++)
	//{
	//	k = LocateElem(L, j, equal);
	//	if (k != INFEASIBLE) // k��Ϊ0�������з���������Ԫ�أ�����λ��Ϊk
	//		printf("��%d��Ԫ�ص�ֵΪ%d\n", k, j);
	//	else
	//		printf("û��ֵΪ%d��Ԫ��\n", j);
	//}
	//for (j = 3; j <= 4; j++)
	//{
	//	k = LocateElem(L, j, sq);
	//	if (k != INFEASIBLE) // k��Ϊ0�������з���������Ԫ�أ�����λ��Ϊk
	//		printf("��%d��Ԫ�ص�ֵΪ%d��ƽ��\n", k, j);
	//	else
	//		printf("û��ֵΪ%d��ƽ����Ԫ��\n", j);
	//}
	//for (j = 1; j <= 2; j++) // ����ͷ��������
	//{
	//	GetElem(L, j, e0); // �ѵ�j�����ݸ���e0
	//	i = PriorElem(L, e0, e); // ��e0��ǰ��
	//	if (i == ERROR)
	//		printf("Ԫ��%d��ǰ��\n", e0);
	//	else
	//		printf("Ԫ��%d��ǰ��Ϊ%d\n", e0, e);
	//}
	//for (j = ListLength(L) - 1; j <= ListLength(L); j++) // �����������
	//{
	//	GetElem(L, j, e0); // �ѵ�j�����ݸ���e0
	//	i = NextElem(L, e0, e); // ��e0�ĺ��
	//	if (i == ERROR)
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
	//ListTraverse(L, print1); // ���ζ�Ԫ�ص���print1()�����Ԫ�ص�ֵ
	//printf("L��Ԫ��ֵ�ӱ��� ");
	//ListTraverse(L, dbl); // ���ζ�Ԫ�ص���dbl()��Ԫ��ֵ��2
	//ListTraverse(L, print1);
	//DestroyList(L);
	//printf("����L�� L.elem=%u L.length=%d L.listsize=%d\n", L.elembase, L.length, L.listsize);
	getchar();
	return 0;
}

