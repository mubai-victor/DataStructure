#include "stdafx.h"
#include "Function.h"
#include "Test.h"


void InitQueue(SqQueue &q)
{
	q.base = (QElemType*)malloc(QUEUE_INIT_SIZE * sizeof(QElemType));
	if (!q.base)
		exit(0);
	q.queuesize = QUEUE_INIT_SIZE;
	q.rear = 0;
}
void DestroyQueue(SqQueue &q)
{
	free(q.base);
	q.base = NULL;
	q.queuesize = 0;
	q.rear = 0;
}
void ClearQueue(SqQueue &q)
{
	q.rear = 0;
}
Status QueueEmpty(SqQueue q)
{
	if (q.rear == 0)
		return TRUE;
	else
		return FALSE;
		
}
int QueueLength(SqQueue q)
{
	return q.rear;
}
Status GetHead(SqQueue q, QElemType &elem)
{
	if (QueueEmpty(q))
		return q.queuesize;
	elem = q.base[0];
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
	elem = q.base[0];
	for (int i = 1; i < q.rear; i++) {
		q.base[i - 1] = q.base[i];
	}
	q.rear--;
	return OK;
}
void QueueTraverse(SqQueue q, void(*func)(QElemType elem))
{
	for (int i = 0; i < q.rear; i++) {
		func(q.base[i]);
	}
}
void print(QElemType i)
{
	printf("%d\n", i);
}

