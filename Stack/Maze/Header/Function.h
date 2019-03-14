#ifndef FUNCTION_H
#define FUNCTION_H

#include "Test.h"
struct PosType {
	int x;
	int y;
};
struct SElemType {
	int ord;
	PosType seat;
	int di;
};
#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 2
struct SqStack {
	SElemType *base;
	SElemType *top;
	int stacksize;
};
void InitStack(SqStack&S);
void DestroyStack(SqStack&S);
void ClearStack(SqStack&S);
Status StackEmpty(SqStack&S);
int StackLength(SqStack&S);
Status GetTop(SqStack&S, SElemType&selem);
void Push(SqStack&S, SElemType selem);
Status Pop(SqStack&s, SElemType&selem);
void StackTraverse(SqStack&S, void(*func)(SElemType selem));
void Print();
void Init(int k);
Status Pass(PosType pos);
void FootPrint(PosType&pos);
void NextPos(PosType&pos,int dir);
void MarkPrint(PosType pos);
Status MazePath(PosType start, PosType end);
#endif
