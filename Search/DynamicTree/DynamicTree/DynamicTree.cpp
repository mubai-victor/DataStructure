// DynamicTree.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	BiTree  p;
	BSTree dt;
	int i;
	KeyType j;
	ElemType r[N] = { { 45,1 },{ 12,2 },{ 53,3 },{ 3,4 },{ 37,5 },{ 24,6 },{ 100,7 },{ 61,8 },{ 90,9 },{ 78,10 } };
	// �Խ̿���ͼ9.7(a)Ϊ������ӳ��ؼ���֮���������Ϣ
	for (i = 0; i<N; i++)
		dt.InsertBST(r[i]); // ���β�������Ԫ��
	dt.TraverseBSTree(print);
	printf("\n����������ҵ�ֵ: ");
	cin >> j;
	p = dt.SearchBST(j);
	if (p)
	{
		printf("���д��ڴ�ֵ��");
		dt.DeleteBST(j);
		printf("ɾ����ֵ��:\n");
		dt.TraverseBSTree(print);
		printf("\n");
	}
	else
		printf("���в����ڴ�ֵ\n");
    return 0;
}

