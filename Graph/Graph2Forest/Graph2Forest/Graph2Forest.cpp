// Graph2Forest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	AMLGraph g;
	CSTree t;
	printf("��ѡ������ͼ\n");
	g.CreateGraph("Graph.txt"); // ��������ͼg
	g.Display(); // �������ͼg
	t.DFSForest(g); // ��������ͼg�������������ɭ�ֵĺ��ӡ��ֵ�����t
	printf("�����������ɭ�֣�\n");
	t.PreOrderTraverse(visit); // �����������ɭ�ֵĺ��ӡ��ֵ�����t
	printf("\n");
    return 0;
}

