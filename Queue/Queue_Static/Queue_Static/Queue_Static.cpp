// Queue_Static.cpp : �������̨Ӧ�ó������ڵ㡣
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
	printf("��ʼ�����к󣬶��пշ� %u(1:�� 0:��)\n", QueueEmpty(Q));
	for (i = 1; i <= k; i++)
		EnQueue(Q, i); // �������k��Ԫ��
	printf("�������%d��Ԫ�غ󣬶����е�Ԫ��Ϊ", k);
	QueueTraverse(Q, print);
	printf("���г���Ϊ%d�����пշ� %u(1:�� 0:��)\n", QueueLength(Q), QueueEmpty(Q));
	DeQueue(Q, d);
	printf("����һ��Ԫ�أ���ֵ��%d\n", d);
	j = GetHead(Q, d);
	if (j)
		printf("���ڶ�ͷԪ����%d\n", d);
	ClearQueue(Q);
	printf("��ն��к�, ���пշ� %u(1:�� 0:��)\n", QueueEmpty(Q));
	DestroyQueue(Q);
	getchar();
	return 0;
}

