// StaticTree.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	SOSTree t;
	Status i;
	KeyType s; // �Խ̿�����91������Ϊ��
	ElemType r[N] = { { 'A',1 },{ 'B',1 },{ 'C',2 },{ 'D',5 },{ 'E',3 },{ 'F',4 },{ 'G',4 },{ 'H',3 },{ 'I',5 } };
	t.CreateSOSTree(r); // ���������һ�ô��Ų�����
	t.Traverse(print);
	printf("\n����������ҵ��ַ�: ");
	cin >> s;
	i = t.Search_SOSTree(s);
	if (i==ERROR)
		printf("���в����ڴ��ַ�\n");
    return 0;
}

