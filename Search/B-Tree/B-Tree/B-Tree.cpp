// B-Tree.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	Record r[N] = { { 24,"1" },{ 45,"2" },{ 53,"3" },{ 12,"4" },{ 37,"5" },{ 50,"6" },{ 61,"7" },{ 90,"8" },
	{ 100,"9" },{ 70,"10" },{ 3,"11" },{ 30,"12" },{ 26,"13" },{ 85,"14" },{ 3,"15" },
	{ 7,"16" } }; // (�Խ̿�����ͼ9.16Ϊ��)
	DSTree t;
	Result s;
	int i;
	for (i = 0; i<N; i++)
	{
		s = t.SearchDSTree(r[i].key);
		if (!s.tag)
			t.InsertDSTree(&r[i], s.pt, s.i);
	}
	printf("���ؼ��ֵ�˳�����B_��:\n");
	t.TraverseDSTree(print);
	printf("\n����������Ҽ�¼�Ĺؼ���: ");
	cin >> i;
	s = t.SearchDSTree(i);
	if (s.tag)
		print(*(s.pt), s.i);
	else
		printf("û�ҵ�");
	printf("\n");
    return 0;
}

