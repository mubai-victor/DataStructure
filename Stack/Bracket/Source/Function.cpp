#include "stdafx.h"
#include "Function.h"
#include "Test.h"
#include "stdio.h"
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
void check()
{
	SElemType ch[40],* pcha,cha;
	SqStack s;
	InitStack(s);
	printf("«Î ‰»Î¥¯¿®∫≈µƒ◊÷∑˚¥Æ£∫\n");
//	scanf_s("%s", ch);
	gets_s(ch);
	pcha = ch;
	while (*pcha) {
		switch (*pcha) {
		case '(':
		case '[':
		case '{':
			Push(s, *pcha); break;
		case ')':
		case ']':
		case '}':			
			if (!StackEmpty(s)) {
				Pop(s, cha);
				if (!(((*pcha == ')') && (cha == '(')) || ((*pcha == ']') && (cha == '[')) || ((*pcha == '}') && (cha == '{')))){
					printf("¿®∫≈≤ª∆•≈‰°£\n");
					exit(0);
				}				
			}
			else {
				printf("»±…Ÿ”“¿®∫≈°£\n");
				exit(0);
			}
		}
		pcha++;
	}
	if (StackEmpty(s))
		printf("¿®∫≈∆•≈‰°£\n");
	else
		printf("»±…Ÿ◊Û¿®∫≈°£\n");
}