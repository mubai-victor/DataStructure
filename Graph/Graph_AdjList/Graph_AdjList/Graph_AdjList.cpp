// Graph_AdjList.cpp : 定义控制台应用程序的入口点。
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
	for (i = 0; i<4; i++) // 验证4种情况
	{
		g.CreateGraph();
		g.Display();
		printf("插入新顶点，请输入顶点的值: ");
		cin >> v1;
		g.InsertVex(v1);
		printf("插入与新顶点有关的弧或边，请输入弧或边数: ");
		cin >> n;
		for (k = 0; k<n; k++)
		{
			printf("请输入另一顶点的值: ");
			cin >> v2;
			if (g.GetKind() == DN ||g.GetKind() == DG) // 有向
			{
				printf("对于有向图或网，请输入另一顶点的方向(0:弧头 1:弧尾): ");
				cin >> j;
				if (!j)
					g.InsertArc(v2, v1);
				else
					g.InsertArc(v1, v2);
			}
			else // 无向
				g.InsertArc(v1, v2);
		}
		g.Display();
		if (i == 3)
		{
			printf("删除一条边或弧，请输入待删除边或弧的弧尾 弧头：");
			cin >> v1 >> v2;
			g.DeleteArc(v1, v2);
			printf("修改顶点的值，请输入原值 新值: ");
			cin >> v1 >> v2;
			g.PutVex(v1, v2);
		}
		printf("删除顶点及相关的弧或边，请输入顶点的值: ");
		cin >> v1;
		g.DeleteVex(v1);
		g.Display();
		g.DestroyGraph();
	}
    return 0;
}

