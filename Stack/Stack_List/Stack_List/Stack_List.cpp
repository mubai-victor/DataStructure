// Stack_List.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include "Test.h"
#include "Function.h"
int main()
{
	int j;
	LinkStack s;
	SElemType e;
	InitStack(s); // ��ʼ��ջs
	for (j = 1; j <= 5; j++) // ��2,4,6,8,10��ջ
		Push(s, 2 * j);
	printf("ջ�е�Ԫ�ش�ջ�׵�ջ������Ϊ");
	StackTraverse(s, print);
	Pop(s, e);
	printf("������ջ��Ԫ��Ϊ%d\n", e);
	printf("ջ�շ�: %d(1:�� 0:��)\n", StackEmpty(s));
	GetTop(s, e);
	printf("��ǰջ��Ԫ��Ϊ%d��ջ�ĳ���Ϊ%d\n", e, StackLength(s));
	ClearStack(s);
	printf("���ջ��ջ�շ�: %d(1:�� 0:��)��ջ�ĳ���Ϊ%d\n", StackEmpty(s), StackLength(s));
	DestroyStack(s);
	return 0;
}

