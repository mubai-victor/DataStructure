#include "stdafx.h"
#include "Function.h"
#include "Test.h"

void InitStack(SqStack&S)
{
	S.base = (SElemType*)(malloc(sizeof(SElemType)*STACK_INIT_SIZE));
	if (!S.base)
		exit(1);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}
void DestroyStack(SqStack&S)
{
	free(S.base);
	S.base = S.top = NULL;
	S.stacksize = 0;
}
void ClearStack(SqStack&S)
{
	S.top = S.base;
}
Status StackEmpty(SqStack&S)
{
	return (S.base == S.top);
}
int StackLength(SqStack&S)
{
	return (S.top - S.base);
}
Status GetTop(SqStack&S,SElemType&selem)
{
	if (S.top == S.base)
		return ERROR;
	selem = *(S.top - 1);
	return OK;
}
void Push(SqStack&S, SElemType selem)
{
	if (S.top - S.base >= S.stacksize) {
		S.base = (SElemType*)(realloc(S.base,sizeof(SElemType)*(S.stacksize + STACK_INCREMENT)));
		if (!S.base)
			exit(1);
		S.top = S.base + S.stacksize;
		S.stacksize += STACK_INCREMENT;
	}
	*S.top = selem;
	S.top++;
}
Status Pop(SqStack&S, SElemType&selem)
{
	if (S.base == S.top)
		return ERROR;
	else {
		selem = *(--S.top);
		return OK;
	}
}
void StackTraverse(SqStack&S, void(*func)(SElemType selem))
{
	SElemType*cur;
	cur = S.base;
	while (S.top > cur) {
		func(*cur++);
	}
	printf("\n");
}
void LineEdit()
{
	SElemType  cha;
	printf("请输入一个文本文件，以^Z结束：\n");
	SqStack s;
	InitStack(s);
	cha = getchar();
	while (cha != EOF) {
		while (cha != EOF&&cha != '\n'){
			switch (cha) {
			case '#':
				if (!StackEmpty(s)) {
					Pop(s, cha);
				}
				break;
			case '@':
				ClearStack(s);
				break;
			default:
				Push(s, cha);
			}
			cha=getchar();
		}
		StackTraverse(s, copy);
		_fputchar('\n');
		if (cha != EOF)
			cha = getchar();
		ClearStack(s);
	}
	DestroyStack(s);
}
void copy(SElemType selem)
{
	_fputchar(selem);
}