#include "stdafx.h"
#include "Function.h"
#include "Test.h"

int precede[7][7] = {
	1,1,-1,-1,-1,1,1,
	1,1,-1,-1,-1,1,1,
	1,1,1,1,-1,1,1,
	1,1,1,1,-1,1,1,
	-1,-1,-1,-1,-1,0,2,
	1,1,1,1,2,1,1
	-1,-1,-1,-1,-1,2,0
};

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

int Getcur(SElemType optr)
{
	switch (optr) {
	case '+':return 0;
	case '-':return 1;
	case '*':return 2;
	case '/':return 3;
	case '(':return 4;
	case ')':return 5;
	case '\n':return 6;
	}
}
int Precede(SElemType optr1, SElemType optr2)
{
	int x, y;
	x = Getcur(optr1);
	y = Getcur(optr2);
	return precede[x][y];
}
Status In(SElemType optr)
{
	switch (optr) {
	case '+':
	case '-':
	case '*':
	case '/':
	case ')':
	case '(':
	case '\n':
		return TRUE;
	default:return FALSE;
	}
}
SElemType Operate(SElemType a, SElemType theta, SElemType b)
{
	switch (theta) {
	case '+':return a + b;
	case '-':return a - b;
	case '*':return a * b;
	case '/':return a / b;
	}
}
SElemType EvaluateExpression()
{
	SqStack optr, opnd;
	InitStack(optr);
	InitStack(opnd);
	Push(optr, '\n');
	SElemType a, b, c, d;
	c = getchar();
	SElemType num[10];
	GetTop(optr, d);
	while(d!='\n'||c!='\n')
		if (In(c)) {
			switch (Precede(d, c)) {
			case -1:
				Push(optr, c);
				c = getchar();
				break;
			case 0 :
				Pop(optr, c);
				c = getchar();
				break;
			case 1:
				if (Pop(opnd, b) == 2 && (Pop(opnd, a) == 2))
				{
					Pop(optr, d);
					Push(opnd, Operate(a, d, b));
				}
				else {
					printf("表达式不正确1。\n");
					exit(0);
				}
			}
			GetTop(optr, d);
		}
		else if (c >= '0'&&c <= '9') {
			int i = 0;
			while (c >= '0'&&c <= '9') {
				num[i++] = c;
				c = getchar();
			}
			num[i] = '\0';
			Push(opnd,atoi(num));
		}
		else {
			printf("非法字符。\n");
			exit(1);
		}
	Pop(opnd, d);
	if (!StackEmpty(opnd)) {
		printf("表达式不正确2。\n");
		exit(0);
	}
	return d;
}