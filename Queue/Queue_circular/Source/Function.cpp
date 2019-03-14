#include "stdafx.h"
#include "Function.h"
#include "Test.h"

void InitQueue(SqQueue &q)
{
	q.base = (QElemType*)malloc(QUEUE_INIT_SIZE *sizeof(QElemType));
	q.front = q.rear = 0;
	q.queuesize = QUEUE_INIT_SIZE;
}
void DestroyQueue(SqQueue &q)
{
	free(q.base);
	q.base = NULL;
	q.front = 0;
	q.rear = 0;
}
void ClearQueue(SqQueue &q)
{
	q.rear = 0;
	q.front = 0;
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
	return (q.rear-q.front+MAX_QSIZE)%MAX_QSIZE;
}
Status GetHead(SqQueue q, QElemType &elem)
{
	if (QueueEmpty(q))
		return ERROR;
	elem = q.base[q.front];
	return OK;
}
Status EnQueue(SqQueue &q, QElemType elem)
{
	if (q.front == ((q.rear + 1) % q.queuesize)) {
		//QueueTraverse(q, print);//0 1 2 3 4 5 6 7 8 9 10
		q.base = (QElemType*)realloc(q.base,(q.queuesize + QUEUE_INCREMENT) * sizeof(QElemType));
		if (!q.base)
			exit(0);
		if (q.front > q.rear) {
			for (int p = q.queuesize - 1; p >= q.front; p--) {
				q.base[p + QUEUE_INCREMENT] = q.base[p];
			}
			q.front += QUEUE_INCREMENT;			
		}
		q.queuesize += QUEUE_INCREMENT;
	}		
	q.base[q.rear] = elem;
	q.rear = (q.rear + 1) % q.queuesize;q.base[2];q.base[3];q.base[4];
	return OK;
}
Status DeQueue(SqQueue &q, QElemType &elem)
{
	if (QueueEmpty(q))
		return ERROR;
	elem = q.base[q.front];
	q.front = (q.front + 1) % MAX_QSIZE;
	return OK;
}
void QueueTraverse(SqQueue q, void(*func)(QElemType elem))
{
	q.base[2];q.base[3];q.base[4];
	for (int i =q.front; i != q.rear;) {
		func(q.base[i]);
		i = (i + 1) % MAX_QSIZE;
	}
}
void print(QElemType i)
{
	printf("%d\n", i);
}

