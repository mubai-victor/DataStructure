// GraphCrossList.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	int j, k, n;
	OLGraph g;
	VertexType v1, v2;
	g.CreateDG("Graph.txt");
	g.Display();
	//printf("�޸Ķ����ֵ��������ԭֵ ��ֵ: ");
	//cin >> v1 >> v2;
	//g.PutVex(v1, v2);
	//g.Display();
	//printf("�����¶��㣬�����붥���ֵ: ");
	//cin >> v1;
	//g.InsertVex(v1);
	//printf("�������¶����йصĻ��������뻡��: ");
	//cin >> n;
	//for (k = 0; k<n; k++)
	//{
	//	printf("��������һ�����ֵ ��һ����ķ���(0:��ͷ 1:��β): ");
	//	cin >> v2 >> j;
	//	if (j==0)
	//		g.InsertArc(v2, v1);
	//	else
	//		g.InsertArc(v1, v2);
	//}
	//g.Display();
	printf("ɾ��һ�������������ɾ�����Ļ�β ��ͷ��");
	cin >> v1 >> v2;
	g.DeleteArc(v2, v1);
	g.Display();
	printf("ɾ�����㼰��صĻ��������붥���ֵ: ");
	cin >> v1;
	g.DeleteVex(v1);
	g.Display();
	g.DestroyGraph();
    return 0;
}

