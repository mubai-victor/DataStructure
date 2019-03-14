// Queue_circular.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

int main()
{
	//Status j;
	//int i = 0, l;
	//QElemType d;
	//SqQueue Q;
	//InitQueue(Q);
	//printf("初始化队列后，队列空否？ %u(1:空 0:否)\n", QueueEmpty(Q));
	//printf("请输入整型队列元素(不超过%d个),-1为提前结束符: ", QUEUE_INIT_SIZE - 1);
	//do
	//{
	//	scanf_s("%d", &d);
	//	if (d == -1)
	//		break;
	//	i++;
	//	EnQueue(Q, d);
	//} while (i<QUEUE_INIT_SIZE - 1);
	//printf("队列长度为%d\n", QueueLength(Q));
	//printf("现在队列空否？ %u(1:空 0:否)\n", QueueEmpty(Q));
	//printf("连续%d次由队头删除元素,队尾插入元素:\n", QUEUE_INIT_SIZE);
	//for (l = 1; l <= QUEUE_INIT_SIZE; l++)
	//{
	//	DeQueue(Q, d);
	//	printf("删除的元素是%d,请输入待插入的元素: ", d);
	//	scanf_s("%d", &d);
	//	EnQueue(Q, d);
	//}
	//l = QueueLength(Q);
	//printf("现在队列中的元素为\n");
	//QueueTraverse(Q, print);
	//printf("共向队尾插入了%d个元素\n", i + QUEUE_INIT_SIZE);
	//if (l - 2>0)
	//	printf("现在由队头删除%d个元素: \n", l - 2);
	//while (QueueLength(Q)>2)
	//{
	//	DeQueue(Q, d);
	//	printf("删除的元素值为%d\n", d);
	//}
	//j = GetHead(Q, d);
	//if (j)
	//	printf("现在队头元素为%d\n", d);
	//ClearQueue(Q);
	//printf("清空队列后, 队列空否？ %u(1:空 0:否)\n", QueueEmpty(Q));
	//DestroyQueue(Q);
	Status j;
	int i, n = 11;
	QElemType d;
	SqQueue Q;
	InitQueue(Q);
	printf("初始化队列后，队列空否？ %u(1:空 0:否)\n", QueueEmpty(Q));
	printf("队列长度为%d\n", QueueLength(Q));
	printf("请输入%d个整型队列元素:\n", n);
	for (i = 0; i<n; i++)
	{
		scanf_s("%d", &d);
		EnQueue(Q, d);
	}
	printf("队列长度为%d\n", QueueLength(Q));
	printf("现在队列空否？ %u(1:空 0:否)\n", QueueEmpty(Q));
	printf("现在队列中的元素为 \n");
	QueueTraverse(Q, print);
	for (i = 1; i <= 3; i++)
		DeQueue(Q, d);
	printf("由队头删除3个元素，最后删除的元素为%d\n", d);
	printf("现在队列中的元素为 \n");
	QueueTraverse(Q, print);
	j = GetHead(Q, d);
	if (j)
		printf("队头元素为%d\n", d);
	else
		printf("无队头元素(空队列)\n");
	for (i = 1; i <= 5; i++)
		EnQueue(Q, i);
	printf("依次向队尾插入1～5，现在队列中的元素为\n");
	QueueTraverse(Q, print);
	ClearQueue(Q);
	printf("清空队列后, 队列空否？ %u(1:空 0:否)\n", QueueEmpty(Q));
	j = GetHead(Q, d);
	if (j)
		printf("队头元素为 %d\n", d);
	else
		printf("无队头元素(空队列)\n");
	DestroyQueue(Q);
	return 0;
}

