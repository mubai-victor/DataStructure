#include "stdafx.h"
#include "Function.h"
#include "Test.h"
PosType start, end;
int curstep = 0;
int maze[10][10] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 1, 1, 0, 1, 1, 1, 0, 1, 0,
	0, 1, 1, 0, 1, 1, 1, 0, 1, 0,
	0, 1, 1, 1, 1, 0, 0, 1, 1, 0,
	0, 1, 0, 0, 0, 1, 1, 1, 1, 0,
	0, 1, 1, 1, 0, 1, 1, 1, 1, 0,
	0, 1, 0, 1, 1, 1, 0, 1, 1, 0,
	0, 1, 0, 0, 0, 1, 0, 0, 1, 0,
	0, 0, 1, 1, 1, 1, 1, 1, 1, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};
PosType curpos;
PosType direction[4] = {
	{0,1},
	{1,0},
	{0,-1},
	{-1,0}
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
void Print()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%d\t", maze[i][j]);
		}
		printf("\n");
	}
}
void Init(int k) {
	start = { 1,1 };
	end = { 8,8 };
	printf("迷宫的结构如下所示：\n");
	Print();
}
Status Pass(PosType pos)
{
	if (maze[pos.x][pos.y] == 1)
		return OK;
	else
		return ERROR;
}
void FootPrint(PosType&pos)
{
	maze[pos.x][pos.y] = curstep;
}
void NextPos(PosType&pos, int dir) {
	pos.x += direction[dir].x;
	pos.y += direction[dir].y;
}
void MarkPrint(PosType pos)
{
	maze[pos.x][pos.y] = -1;
}
Status MazePath(PosType start, PosType end)
{
	SqStack s;
	InitStack(s);
	PosType curpos;
	SElemType elem;
	curpos = start;
	do {
		if (Pass(curpos)==OK) {
			elem.di = 0;
			elem.ord = curstep;
			elem.seat = curpos;
			Push(s,elem);
			curstep++;
			FootPrint(curpos);
			if (curpos.x == end.x&&curpos.y == end.y)
				return TRUE;
			NextPos(curpos,0);
		}
		else {
			if (!StackEmpty(s)) {
				Pop(s,elem);
				curstep--;
				while (elem.di == 3 && !StackEmpty(s)) {
					MarkPrint(elem.seat);
					Pop(s,elem);
					curstep--;
				}
				if (elem.di < 3) {
					elem.di++;
					Push(s,elem);
					curstep++;
					curpos = elem.seat;
					NextPos(curpos,elem.di);
				}
			}
		}		
	} while (!StackEmpty(s));
	return FALSE;
}
//Status MazePath(PosType start, PosType end)
//{
//	SqStack s;
//	InitStack(s);
//	PosType curpos;
//	SElemType elem;
//	curpos = start;
//	do {
//		if (Pass(curpos) == OK) {
//			elem.seat = curpos;
//			elem.di = 0;
//			elem.ord = curstep;
//			Push(s, elem);
//			curstep++;
//			FootPrint(curpos);
//			if (curpos.x == end.x&&curpos.y == end.y)
//				return OK;
//			NextPos(curpos,0);
//		}
//		else {
//			if (!StackEmpty(s)) {
//				Pop(s,elem);
//				curstep--;
//				if (elem.di == 3 && !StackEmpty(s)) {
//					MarkPrint(elem.seat);
//					Pop(s, elem);
//					curstep--;
//				}
//				if (elem.di < 3) {
//					curpos = elem.seat;
//					elem.di++;
//					Push(s,elem);
//					curstep++;
//					NextPos(curpos,elem.di);
//				}
//			}
//		}
//	} while (!StackEmpty(s));
//	return FALSE;
//}