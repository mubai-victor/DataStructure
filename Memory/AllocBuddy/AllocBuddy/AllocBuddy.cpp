// AllocBuddy.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	int i, n;
	cAlloc a;
	a.Init();
	Space q[SIZE + 1] = { NULL }; // q����Ϊռ�ÿ���׵�ַ
	printf("sizeof(WORD_b)=%u size=%u int(pow(2,size))=%u\n", sizeof(WORD_b), SIZE, int(pow(2, SIZE)));
	a.Print();
	n = 100;
	q[0] = a.AllocBuddy(n);
	// ��a����100��WORD_b���ڴ�(ʵ�ʻ��128��WORD_b)
	printf("����%d���ֺ󣬿����ÿռ�Ϊ\n", n);
	a.Print();
	a.PrintUser(q);
	n = 200;
	q[1] = a.AllocBuddy(n); // ��a����200��WORD_b���ڴ�(ʵ�ʻ��256��WORD_b)
	printf("����%d���ֺ󣬿����ÿռ�Ϊ\n", n);
	a.Print();
	a.PrintUser(q);
	n = 220;
	q[2] = a.AllocBuddy(n); // ��a����220��WORD_b���ڴ�(ʵ�ʻ��256��WORD_b)
	printf("����%d���ֺ󣬿����ÿռ�Ϊ\n", n);
	a.Print();
	a.PrintUser(q);
	a.Reclaim(q[1]); // ����q[1]����鲻����
	printf("����q[1]�󣬿����ÿռ�Ϊ\n");
	a.Print();
	a.PrintUser(q);
	a.Reclaim(q[0]); // ����q[0]��������
	printf("����q[0]�󣬿����ÿռ�Ϊ\n");
	a.Print();
	a.PrintUser(q);
	a.Reclaim(q[2]); // ����q[2]�������У�����һ������
	printf("����q[2]�󣬿����ÿռ�Ϊ\n");
	a.Print();
	a.PrintUser(q);

    return 0;
}

