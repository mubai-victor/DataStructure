// RadixSort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Test.h"
#include "Function.h"

using namespace std;

int main()
{
	RedType d[N] = { { 278,1 },{ 109,2 },{ 63,3 },{ 930,4 },{ 589,5 },{ 184,6 },{ 505,7 },{ 269,8 },{ 8,9 },
	{ 83,10 } };
	SLinkListType l;
	int *adr;
	l.Assign(d, N);
	printf("����ǰ(next��û��ֵ):\n");
	l.PrintPos();
	l.RadixSort();
	printf("�����(��̬����):\n");
	l.PrintPos();
	l.Sort();
	l.Rearrange();
	printf("�����(���ż�¼):\n");
	l.PrintPos();
    return 0;
}

