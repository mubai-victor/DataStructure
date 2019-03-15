#include "stdafx.h"
#include "Function.h"
#include "Test.h"
PosType begin, end;
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
PosType dir[4] = {
	{ 0,1 },
	{ 1,0 },
	{ 0,-1 },
	{ -1,0 }
};
void InitQueue(SqQueue &q)
{
	q.base = (QElemType*)malloc(QUEUE_INIT_SIZE * sizeof(QElemType));
	if (!q.base)
		exit(0);
	q.queuesize = QUEUE_INIT_SIZE;
	q.rear = q.front = 0;
}
void DestroyQueue(SqQueue &q)
{
	free(q.base);
	q.base = NULL;
	q.queuesize = 0;
	q.rear = q.front = 0;
}
void ClearQueue(SqQueue &q)
{
	q.rear = q.front = 0;
}
Status QueueEmpty(SqQueue q)
{
	if (q.rear == q.front)
		return TRUE;
	else
		return FALSE;
		
}
int QueueLength(SqQueue q)
{
	return q.rear - q.front;
}
Status GetHead(SqQueue q, QElemType &elem)
{
	if (QueueEmpty(q))
		return ERROR;
	elem = q.base[q.front];
	return OK;
}
void EnQueue(SqQueue &q, QElemType elem)
{
	if (q.queuesize == q.rear) {
		q.base = (QElemType*)realloc(q.base, (q.queuesize + QUEUE_INCREMENT) * sizeof(QElemType));
		if (!q.base)
			exit(0);
		q.queuesize += QUEUE_INCREMENT;
	}
	q.base[q.rear++] = elem;

}
Status DeQueue(SqQueue &q, QElemType &elem)
{
	if (QueueEmpty(q))
		return ERROR;
	elem = q.base[q.front++];
	return OK;
}
void QueueTraverse(SqQueue q, void(*func)(QElemType elem))
{
	for (int i = q.front; i < q.rear; i++) {
		func(q.base[i]);
	}
}
void print(QElemType i)
{
	printf("%d\n", i);
}

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
Status GetTop(SqStack&S, SElemType&selem)
{
	if (S.top == S.base)
		return ERROR;
	selem = *(S.top - 1);
	return OK;
}
void Push(SqStack&S, SElemType selem)
{
	if (S.top - S.base >= S.stacksize) {
		S.base = (SElemType*)(realloc(S.base, sizeof(SElemType)*(S.stacksize + STACK_INCREMENT)));
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

void Path()
{
	SqQueue q;
	SqStack s;
	SElemType pre, next;
	int flag = 0;
	pre.pre = -1;
	pre.seat.x = begin.x;
	pre.seat.y = begin.y;
	InitQueue(q);
	InitStack(s);
	EnQueue(q, pre);
	while (!flag && !QueueEmpty(q)) {
		DeQueue(q, pre);
		for (int i = 0; i < 4; i++) {
			next.seat.x = pre.seat.x + dir[i].x;
			next.seat.y = pre.seat.y + dir[i].y;		
			if (maze[next.seat.x][next.seat.y] == 1) {
				next.pre = q.front - 1;
				EnQueue(q, next);
				maze[next.seat.x][next.seat.y] = -1;
				if (next.seat.x == end.x&&next.seat.y==end.y) {
					flag = 1;
					break;
				}
			}
		}
	}
	if (!flag)
		printf("该迷宫没有通路。\n");
	else {
		int i = q.rear - 1;
		while (pre.pre != -1) {
			pre = q.base[i];
			Push(s, pre);
			i = pre.pre;			
		}
		i = 0;
		while (!StackEmpty(s)) {
			Pop(s, pre);
			++i;
			maze[pre.seat.x][pre.seat.y] = i;
		}
		printf("找到一条迷宫的通路：\n");
		Print();
	}
}
void Init(int a) {
	begin = { 1,1 };
	end = { 8,8 };
	printf("当前迷宫的结构是：\n");
	Print();
}