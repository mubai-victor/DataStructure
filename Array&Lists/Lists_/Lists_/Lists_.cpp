// Lists_.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"
#include "iostream"
using namespace std;

int main()
{
	char p[80];
	SString t;
	GList l, m;
	printf("�չ����l�����=%d l�Ƿ�գ� %d(1:�� 0:��)\n", l.GListDepth(), l.GListEmpty());
	printf("����������l(��д��ʽ���ձ�:(),��ԭ��:(a),����:(a,(b),c)):\n");
	l.CreateGList("List.txt");
	printf("�����l�ĳ���=%d\n", l.GListLength());
	printf("�����l�����=%d l�Ƿ�գ� %d(1:�� 0:��)\n", l.GListDepth(), l.GListEmpty());
	printf("���������l�� \n");
	l.Traverse_GL(visit);
	printf("\n���ƹ����m=l\n");
	l.CopyGList(m);
	printf("�����m�ĳ���=%d\n", m.GListLength());
	printf("�����m�����=%d\n", m.GListDepth());
	printf("���������m�� \n");
	m.Traverse_GL(visit);
	m.DestroyGList();
	m = l.GetHead();
	printf("\nm��l�ı�ͷԪ�أ�����m�� \n");
	m.Traverse_GL(visit);
	m.DestroyGList();
	m = l.GetTail();
	printf("\nm����l�ı�β�γɵĹ�������������m�� \n");
	m.Traverse_GL(visit);
	m.InsertFirst_GL(l);
	printf("\n��������lΪm�ı�ͷ�����������m�� \n");
	m.Traverse_GL(visit);
	printf("\nɾ��m�ı�ͷ�����������m�� \n");
	l.DestroyGList();
	m.DeleteFirst_GL(l);
	m.Traverse_GL(visit);
	printf("\n");
	m.DestroyGList();
	int i;
	return 0;
}

