// GraphArray.cpp : 定义控制台应用程序的入口点。
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
	for (i = 0; i<4; i++) // 验证4种情况
	{
		g.CreateGraph(); // 构造图g
		//g.Display(); // 输出图g
		//printf("插入新顶点，请输入顶点的值: ");
		//cin >> v1;
		//g.InsertVex(v1);
		//printf("插入与新顶点有关的弧或边，请输入弧或边数: ");
		//cin >> n;
		//for (k = 0; k<n; k++)
		//{
		//	printf("请输入另一顶点的值: ");
		//	cin >> v2;
		//	if (g.GetType() == DG || g.GetType() == DN) // 有向
		//	{
		//		printf("对于有向图或网，请输入另一顶点的方向(0:弧头 1:弧尾): ");
		//		cin >> j;
		//		if (j) // v2是弧尾
		//			g.InsertArc(v2, v1);
		//		else // v2是弧头
		//			g.InsertArc(v1, v2);
		//	}
		//	else // 无向
		//		g.InsertArc(v1, v2);
		//}
		//g.Display(); // 输出图g
		//printf("删除顶点及相关的弧或边，请输入顶点的值: ");
		//cin >> v1;
		//g.DeleteVex(v1);
		//g.Display(); // 输出图g
		g.DFSTraverse(visit);
		g.BFSTraverse(visit);
	}
	g.DestroyGraph(); // 销毁图g
    return 0;
}

