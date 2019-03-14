// CircularList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Test.h"
#include "Function.h"
void MergeList(LinkList &La, LinkList Lb)
{ // ��Lb�ϲ���La�ı�β����Laָʾ�±�
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
	printf("La="); // �������La������
	ListTraverse(La, print);
	InitList(Lb);
	for (i = 1; i <= n; i++)
		ListInsert(Lb, 1, i * 2);
	printf("Lb="); // �������Lb������
	ListTraverse(Lb, print);
	MergeList(La, Lb);
	printf("La+Lb="); // ����ϲ�������������
	ListTraverse(La, print);

	//LinkList L;
	//ElemType e;
	//int j;
	//Status i;
	//InitList(L); // ��ʼ����ѭ������L
	//i = ListEmpty(L);
	//printf("L�Ƿ�� i=%d(1:�� 0:��)\n", i);
	//ListInsert(L, 1, 3); // ��L�����β���3,5
	//ListInsert(L, 2, 5);
	//i = GetElem(L, 1, e);
	//j = ListLength(L);
	//printf("L������Ԫ�ظ���=%d,��1��Ԫ�ص�ֵΪ%d�� \n", j, e);
	//printf("L�е�����Ԫ������Ϊ");
	//ListTraverse(L, print);
	//PriorElem(L, 5, e); // ��Ԫ��5��ǰ��
	//printf("5ǰ���Ԫ�ص�ֵΪ%d�� \n", e);
	//NextElem(L, 3, e); // ��Ԫ��3�ĺ��
	//printf("3�����Ԫ�ص�ֵΪ%d�� \n", e);
	//printf("L�Ƿ�� %d(1:�� 0:��)\n", ListEmpty(L));
	//j = LocateElem(L, 5, equal);
	//if (j)
	//	printf("L�ĵ�%d��Ԫ��Ϊ5�� \n", j);
	//else
	//	printf("������ֵΪ5��Ԫ��\n");
	//i = ListDelete(L, 2, e);
	//printf("ɾ��L�ĵ�2��Ԫ�أ� \n");
	//if (i)
	//{
	//	printf("ɾ����Ԫ��ֵΪ%d,����L�е�����Ԫ������Ϊ", e);
	//	ListTraverse(L, print);
	//}
	//else
	//	printf("ɾ�����ɹ��� \n");
	//ClearList(L);
	//printf("���L�� L�Ƿ�գ� %d(1:�� 0:��)\n", ListEmpty(L));
	//DestroyList(L);
	system("PAUSE");
	return 0;
}

