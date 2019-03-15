#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"

#define MAX_QSIZE q.queuesize
#define	QUEUE_INIT_SIZE 5
#define	QUEUE_INCREMENT 2
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
Status EnQueue(SqQueue &q, QElemType elem);
Status DeQueue(SqQueue &q, QElemType &elem);
void QueueTraverse(SqQueue q, void(*func)(QElemType elem));
void print(QElemType i);


#endif