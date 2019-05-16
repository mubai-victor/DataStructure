// MultAdjList.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	int k, n;
	AMLGraph g;
	VertexType v1, v2;
	g.CreateGraph("Graph.txt");
	g.Display();
	//printf("�޸Ķ����ֵ��������ԭֵ ��ֵ: ");
	//cin >> v1 >> v2;
	//g.PutVex(v1, v2);
	//printf("�����¶��㣬�����붥���ֵ: ");
	//cin >> v1;
	//g.InsertVex(v1);
	//printf("�������¶����йصıߣ����������: ");
	//cin >> n;
	//for (k = 0; k<n; k++)
	//{
	//	printf("��������һ�����ֵ: ");
	//	cin >> v2;
	//	g.InsertArc(v1, v2);
	//}
	//g.Display();
	printf("ɾ��һ���ߣ��������ɾ���ߵ�������(�Կո���Ϊ���)��");
	cin >> v1 >> v2;
	g.DeleteArc(v1, v2);
	g.Display();
	printf("ɾ�����㼰��صıߣ������붥���ֵ: ");
	cin >> v1;
	g.DeleteVex(v1);
	g.Display();
	printf("������������Ľ��:\n");
	g.DFSTraverse(visit);
	printf("������������Ľ��:\n");
	g.BFSTraverse(visit);
	g.DestroyGraph();

    return 0;
}

