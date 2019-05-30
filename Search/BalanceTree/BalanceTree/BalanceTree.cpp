// BalanceTree.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	BalanceTree dt;
	BiTree p;
	Status k;
	int i;
	KeyType j;
	ElemType r[N] = { { 13,1 },{ 24,2 },{ 37,3 },{ 90,4 },{ 53,5 } };
	for (i = 0; i<N; i++)
		dt.InsertAVL(r[i]); // ��ƽ�������
	dt.TraverseBST(print); // �������ƽ�������
	printf("�������ƽ�������\n");
	printf("\n����������ҵĹؼ���: ");
	cin >> j;
	p = dt.SearchBST(j); // ���Ҹ����ؼ��ֵļ�¼
	if (p)
		print(p->data);
	else
		printf("���в����ڴ�ֵ");
	printf("\n");
    return 0;
}

