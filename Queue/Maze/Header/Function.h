#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"

#define QUEUE_INIT_SIZE 10
#define QUEUE_INCREMENT 2
struct SqQueue {
	QElemType *base;
	int rear;
	int front;
	int queuesize;
};
void InitQueue(SqQueue &q);
void DestroyQueue(SqQueue &q);
void ClearQueue(SqQueue &q);
Status QueueEmpty(SqQueue q);
int QueueLength(SqQueue q);
Status GetHead(SqQueue q, QElemType &elem);
void EnQueue(SqQueue &q, QElemType elem);
Status DeQueue(SqQueue &q, QElemType &elem);
void QueueTraverse(SqQueue q, void(*func)(QElemType elem));
void print(QElemType i);

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
void Path();
void Init(int a);
void Print();
#endif