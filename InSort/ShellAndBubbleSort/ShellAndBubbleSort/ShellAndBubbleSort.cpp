// ShellAndBubbleSort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	RedType d[N] = { { 49,1 },{ 38,2 },{ 65,3 },{ 97,4 },{ 76,5 },{ 13,6 },{ 27,7 },{ 49,8 },{ 55,9 },{ 4,10 } };
	SLinkListType l,j;
	int dt[T] = { 5,3,1 }; // ������������
	l.Assign(d, N);
	j = l;
	printf("����ǰ: ");
	l.Print();
	l.ShellSort();
	printf("�����: ");
	l.Print();	printf("����ǰ: ");
	j.Print();
	j.BubbleSort();
	printf("�����: ");
	j.Print();	
    return 0;
}

