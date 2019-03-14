// Stack.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"
void print(SElemType c)
{
	printf("%d ", c);
}
int main()
{
	int j;
	SqStack s;
	SElemType e;
	InitStack(s);
	for (j = 1; j <= 12; j++)
		Push(s, j);
	printf("ջ��Ԫ������Ϊ");
	StackTraverse(s, print);
	Pop(s, e);
	printf("������ջ��Ԫ�� e=%d\n", e);
	printf("ջ�շ� %d(1:�� 0:��)\n", StackEmpty(s));
	GetTop(s, e);
	printf("ջ��Ԫ�� e=%d ջ�ĳ���Ϊ%d\n", e, StackLength(s));
	ClearStack(s);
	printf("���ջ��ջ�շ� %d(1:�� 0:��)\n", StackEmpty(s));
	DestroyStack(s);
	printf("����ջ�� s.top=%u s.base=%u s.stacksize=%d\n", s.top, s.base, s.stacksize);
	return 0;
}

