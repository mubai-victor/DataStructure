#ifndef _FUNCTION_QUEUE_
#define _FUNCTION_QUEUE_
#include "Test.h"
typedef struct {
	int ArrivalTime;
	int Duration;
}QElemType;
typedef struct QNode {
	QElemType data;
	QNode*next;
}*QueuePtr;
struct LinkQueue {
	QueuePtr rear, front;
};
void print(QElemType i);
void InitQueue(LinkQueue &q);
void DestroyQueue(LinkQueue &q);
void ClearQueue(LinkQueue &q);
Status QueueEmpty(LinkQueue &q);
int QueueLength(LinkQueue q);
Status GetHead(LinkQueue q, QElemType &elem);
void EnQueue(LinkQueue &q, QElemType elem);
Status DeQueue(LinkQueue &q,QElemType &elem);
void QueueTraverse(LinkQueue q, void(*func)(QElemType elem));


#endif