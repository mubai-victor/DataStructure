// GraphCrossList.cpp : 定义控制台应用程序的入口点。
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
	//printf("修改顶点的值，请输入原值 新值: ");
	//cin >> v1 >> v2;
	//g.PutVex(v1, v2);
	//g.Display();
	//printf("插入新顶点，请输入顶点的值: ");
	//cin >> v1;
	//g.InsertVex(v1);
	//printf("插入与新顶点有关的弧，请输入弧数: ");
	//cin >> n;
	//for (k = 0; k<n; k++)
	//{
	//	printf("请输入另一顶点的值 另一顶点的方向(0:弧头 1:弧尾): ");
	//	cin >> v2 >> j;
	//	if (j==0)
	//		g.InsertArc(v2, v1);
	//	else
	//		g.InsertArc(v1, v2);
	//}
	//g.Display();
	printf("删除一条弧，请输入待删除弧的弧尾 弧头：");
	cin >> v1 >> v2;
	g.DeleteArc(v2, v1);
	g.Display();
	printf("删除顶点及相关的弧，请输入顶点的值: ");
	cin >> v1;
	g.DeleteVex(v1);
	g.Display();
	g.DestroyGraph();
    return 0;
}

