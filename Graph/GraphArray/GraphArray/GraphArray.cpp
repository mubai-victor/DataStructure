// GraphArray.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Test.h"
#include "Function.h"

using namespace std;

int main()
{
	int i, j, k, n;
	MGraph g;
	VertexType v1, v2;
	for (i = 0; i<4; i++) // ��֤4�����
	{
		g.CreateGraph(); // ����ͼg
		//g.Display(); // ���ͼg
		//printf("�����¶��㣬�����붥���ֵ: ");
		//cin >> v1;
		//g.InsertVex(v1);
		//printf("�������¶����йصĻ���ߣ������뻡�����: ");
		//cin >> n;
		//for (k = 0; k<n; k++)
		//{
		//	printf("��������һ�����ֵ: ");
		//	cin >> v2;
		//	if (g.GetType() == DG || g.GetType() == DN) // ����
		//	{
		//		printf("��������ͼ��������������һ����ķ���(0:��ͷ 1:��β): ");
		//		cin >> j;
		//		if (j) // v2�ǻ�β
		//			g.InsertArc(v2, v1);
		//		else // v2�ǻ�ͷ
		//			g.InsertArc(v1, v2);
		//	}
		//	else // ����
		//		g.InsertArc(v1, v2);
		//}
		//g.Display(); // ���ͼg
		//printf("ɾ�����㼰��صĻ���ߣ������붥���ֵ: ");
		//cin >> v1;
		//g.DeleteVex(v1);
		//g.Display(); // ���ͼg
		g.DFSTraverse(visit);
		g.BFSTraverse(visit);
	}
	g.DestroyGraph(); // ����ͼg
    return 0;
}

