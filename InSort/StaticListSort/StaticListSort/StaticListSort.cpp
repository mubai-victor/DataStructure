// StaticListSort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	RedType d[N] = { { 49,1 },{ 38,2 },{ 65,3 },{ 97,4 },{ 76,5 },{ 13,6 },{ 27,7 },{ 49,8 } };
	SLinkListType l1, l2;
	int *adr, i;
	l1.TableInsert(d, N);
	l2 = l1; // ���ƾ�̬����l2��l1��ͬ
	printf("����ǰ:\n");
	l1.Print();
	l1.Arrange();
	printf("l1�����:\n");
	l1.Print();
	l2.Sort();
	l2.Rearrange();
	printf("l2�����:\n");
	l2.Print();
    return 0;
}

