#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"

#define QUEUE_INIT_SIZE 10
#define QUEUE_INCREMENT 2
struct SqQueue {
	QElemType *base;
	int rear;
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


#endif