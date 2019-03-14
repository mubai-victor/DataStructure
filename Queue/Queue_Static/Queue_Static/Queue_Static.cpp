// Queue_Static.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"
#define SqQueue1 SqQueue
int main()
{
	Status j;
	int i, k = 5;
	QElemType d;
	SqQueue1 Q;
	InitQueue(Q);
	printf("初始化队列后，队列空否？ %u(1:空 0:否)\n", QueueEmpty(Q));
	for (i = 1; i <= k; i++)
		EnQueue(Q, i); // 依次入队k个元素
	printf("依次入队%d个元素后，队列中的元素为", k);
	QueueTraverse(Q, print);
	printf("队列长度为%d，队列空否？ %u(1:空 0:否)\n", QueueLength(Q), QueueEmpty(Q));
	DeQueue(Q, d);
	printf("出队一个元素，其值是%d\n", d);
	j = GetHead(Q, d);
	if (j)
		printf("现在队头元素是%d\n", d);
	ClearQueue(Q);
	printf("清空队列后, 队列空否？ %u(1:空 0:否)\n", QueueEmpty(Q));
	DestroyQueue(Q);
	getchar();
	return 0;
}

