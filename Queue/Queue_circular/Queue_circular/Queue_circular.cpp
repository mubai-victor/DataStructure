// Queue_circular.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//printf("��ʼ�����к󣬶��пշ� %u(1:�� 0:��)\n", QueueEmpty(Q));
	//printf("���������Ͷ���Ԫ��(������%d��),-1Ϊ��ǰ������: ", QUEUE_INIT_SIZE - 1);
	//do
	//{
	//	scanf_s("%d", &d);
	//	if (d == -1)
	//		break;
	//	i++;
	//	EnQueue(Q, d);
	//} while (i<QUEUE_INIT_SIZE - 1);
	//printf("���г���Ϊ%d\n", QueueLength(Q));
	//printf("���ڶ��пշ� %u(1:�� 0:��)\n", QueueEmpty(Q));
	//printf("����%d���ɶ�ͷɾ��Ԫ��,��β����Ԫ��:\n", QUEUE_INIT_SIZE);
	//for (l = 1; l <= QUEUE_INIT_SIZE; l++)
	//{
	//	DeQueue(Q, d);
	//	printf("ɾ����Ԫ����%d,������������Ԫ��: ", d);
	//	scanf_s("%d", &d);
	//	EnQueue(Q, d);
	//}
	//l = QueueLength(Q);
	//printf("���ڶ����е�Ԫ��Ϊ\n");
	//QueueTraverse(Q, print);
	//printf("�����β������%d��Ԫ��\n", i + QUEUE_INIT_SIZE);
	//if (l - 2>0)
	//	printf("�����ɶ�ͷɾ��%d��Ԫ��: \n", l - 2);
	//while (QueueLength(Q)>2)
	//{
	//	DeQueue(Q, d);
	//	printf("ɾ����Ԫ��ֵΪ%d\n", d);
	//}
	//j = GetHead(Q, d);
	//if (j)
	//	printf("���ڶ�ͷԪ��Ϊ%d\n", d);
	//ClearQueue(Q);
	//printf("��ն��к�, ���пշ� %u(1:�� 0:��)\n", QueueEmpty(Q));
	//DestroyQueue(Q);
	Status j;
	int i, n = 11;
	QElemType d;
	SqQueue Q;
	InitQueue(Q);
	printf("��ʼ�����к󣬶��пշ� %u(1:�� 0:��)\n", QueueEmpty(Q));
	printf("���г���Ϊ%d\n", QueueLength(Q));
	printf("������%d�����Ͷ���Ԫ��:\n", n);
	for (i = 0; i<n; i++)
	{
		scanf_s("%d", &d);
		EnQueue(Q, d);
	}
	printf("���г���Ϊ%d\n", QueueLength(Q));
	printf("���ڶ��пշ� %u(1:�� 0:��)\n", QueueEmpty(Q));
	printf("���ڶ����е�Ԫ��Ϊ \n");
	QueueTraverse(Q, print);
	for (i = 1; i <= 3; i++)
		DeQueue(Q, d);
	printf("�ɶ�ͷɾ��3��Ԫ�أ����ɾ����Ԫ��Ϊ%d\n", d);
	printf("���ڶ����е�Ԫ��Ϊ \n");
	QueueTraverse(Q, print);
	j = GetHead(Q, d);
	if (j)
		printf("��ͷԪ��Ϊ%d\n", d);
	else
		printf("�޶�ͷԪ��(�ն���)\n");
	for (i = 1; i <= 5; i++)
		EnQueue(Q, i);
	printf("�������β����1��5�����ڶ����е�Ԫ��Ϊ\n");
	QueueTraverse(Q, print);
	ClearQueue(Q);
	printf("��ն��к�, ���пշ� %u(1:�� 0:��)\n", QueueEmpty(Q));
	j = GetHead(Q, d);
	if (j)
		printf("��ͷԪ��Ϊ %d\n", d);
	else
		printf("�޶�ͷԪ��(�ն���)\n");
	DestroyQueue(Q);
	return 0;
}

