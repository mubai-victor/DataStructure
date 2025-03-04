// Stack_List.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "Test.h"
#include "Function.h"
int main()
{
	int j;
	LinkStack s;
	SElemType e;
	InitStack(s); // 初始化栈s
	for (j = 1; j <= 5; j++) // 将2,4,6,8,10入栈
		Push(s, 2 * j);
	printf("栈中的元素从栈底到栈顶依次为");
	StackTraverse(s, print);
	Pop(s, e);
	printf("弹出的栈顶元素为%d\n", e);
	printf("栈空否: %d(1:空 0:否)\n", StackEmpty(s));
	GetTop(s, e);
	printf("当前栈顶元素为%d，栈的长度为%d\n", e, StackLength(s));
	ClearStack(s);
	printf("清空栈后，栈空否: %d(1:空 0:否)，栈的长度为%d\n", StackEmpty(s), StackLength(s));
	DestroyStack(s);
	return 0;
}

