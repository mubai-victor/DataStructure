// Graph_AdjList.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Test.h"
#include "Function.h"

using namespace std;

int main()
{
	int i, j, k, n;
	cALGraph g;
	VertexType v1, v2;
	for (i = 0; i<4; i++) // ��֤4�����
	{
		g.CreateGraph();
		g.Display();
		printf("�����¶��㣬�����붥���ֵ: ");
		cin >> v1;
		g.InsertVex(v1);
		printf("�������¶����йصĻ���ߣ������뻡�����: ");
		cin >> n;
		for (k = 0; k<n; k++)
		{
			printf("��������һ�����ֵ: ");
			cin >> v2;
			if (g.GetKind() == DN ||g.GetKind() == DG) // ����
			{
				printf("��������ͼ��������������һ����ķ���(0:��ͷ 1:��β): ");
				cin >> j;
				if (!j)
					g.InsertArc(v2, v1);
				else
					g.InsertArc(v1, v2);
			}
			else // ����
				g.InsertArc(v1, v2);
		}
		g.Display();
		if (i == 3)
		{
			printf("ɾ��һ���߻򻡣��������ɾ���߻򻡵Ļ�β ��ͷ��");
			cin >> v1 >> v2;
			g.DeleteArc(v1, v2);
			printf("�޸Ķ����ֵ��������ԭֵ ��ֵ: ");
			cin >> v1 >> v2;
			g.PutVex(v1, v2);
		}
		printf("ɾ�����㼰��صĻ���ߣ������붥���ֵ: ");
		cin >> v1;
		g.DeleteVex(v1);
		g.Display();
		g.DestroyGraph();
	}
    return 0;
}

