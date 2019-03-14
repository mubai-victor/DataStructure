// Stack.cpp : 定义控制台应用程序的入口点。
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
	printf("栈中元素依次为");
	StackTraverse(s, print);
	Pop(s, e);
	printf("弹出的栈顶元素 e=%d\n", e);
	printf("栈空否： %d(1:空 0:否)\n", StackEmpty(s));
	GetTop(s, e);
	printf("栈顶元素 e=%d 栈的长度为%d\n", e, StackLength(s));
	ClearStack(s);
	printf("清空栈后，栈空否： %d(1:空 0:否)\n", StackEmpty(s));
	DestroyStack(s);
	printf("销毁栈后， s.top=%u s.base=%u s.stacksize=%d\n", s.top, s.base, s.stacksize);
	return 0;
}

