// MemoAllocation.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	cAlloc pav, p; // ���п�ָ��
	Space v[MAX / MIN] = { NULL }; // ռ�ÿ�ָ������(��ʼ��Ϊ��)
	int n;
	printf("�ṹ��WORDΪ%d���ֽ�\n", sizeof(WORD));
	printf("��ʼ���󣬿����ÿռ��Ϊ\n");
	pav.Init();
	pav.Print();
	n = 300;
	v[0] = pav.AllocBoundTag(n);
	printf("����%u���洢�ռ�󣬿����ÿռ��Ϊ\n", n);
	pav.Print();
	pav.PrintUser(v);
	n = 450;
	v[1] = pav.AllocBoundTag(n);
	printf("����%u���洢�ռ��pavΪ\n", n);
	pav.Print();
	pav.PrintUser(v);
	n = 300; // ���䲻�ɹ�
	v[2] = pav.AllocBoundTag(n);
	printf("����%u���洢�ռ��(���ɹ�)��pavΪ\n", n);
	pav.Print();
	pav.PrintUser(v);
	n = 240; // ����������(250)
	v[2] = pav.AllocBoundTag(n);
	printf("����%u���洢�ռ��(�������)��pavΪ\n", n);
	pav.Print();
	pav.PrintUser(v);
	printf("����v[0](%d)��(��pav��ʱ����)��pavΪ\n", v[0]->size);
	pav.Reclaim(v[0]); // pavΪ��
	pav.Print();
	pav.PrintUser(v);
	printf("1���س�������");
	getchar();
	printf("����v[2](%d)��(����������Ϊռ�ÿ�),pavΪ\n", v[2]->size);
	pav.Reclaim(v[2]); // ����������Ϊռ�ÿ�
	pav.Print();
	pav.PrintUser(v);
	n = 270; // ���ҿռ��㹻��Ŀ�

	v[0] = pav.AllocBoundTag(n);
	printf("����%u���洢�ռ��(���ҿռ��㹻��Ŀ�)��pavΪ\n", n);
	pav.Print();
	pav.PrintUser(v);
	n = 30; // �ڵ�ǰ���Ϸ���
	v[2] = pav.AllocBoundTag(n);
	printf("����%u���洢�ռ��(�ڵ�ǰ���Ϸ���)��pavΪ\n", n);
	pav.Print();
	pav.PrintUser(v);
	printf("����v[1](%d)��(������Ϊ���п�,������Ϊռ�ÿ�)��pavΪ\n", v[1]->size);
	pav.Reclaim(v[1]); // ������Ϊ���п飬������Ϊռ�ÿ�
	Space temp = v[0];
	pav.Print();
	pav.PrintUser(v);
	printf("2���س�������");
	getchar();
	printf("����v[0](%d)��(������Ϊ���п�,������Ϊռ�ÿ�)��pavΪ\n", v[0]->size);
	pav.Reclaim(v[0]); // ������Ϊ���п飬������Ϊռ�ÿ�
	pav.Print();
	pav.PrintUser(v);
	printf("����v[2](%d)��(����������Ϊ���п�),pavΪ\n", v[2]->size);
	pav.Reclaim(v[2]); // ����������Ϊ���п�
	pav.Print();
	pav.PrintUser(v);
    return 0;
}

