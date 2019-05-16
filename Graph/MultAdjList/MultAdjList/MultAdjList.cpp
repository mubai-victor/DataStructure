// MultAdjList.cpp : 定义控制台应用程序的入口点。
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
	//printf("修改顶点的值，请输入原值 新值: ");
	//cin >> v1 >> v2;
	//g.PutVex(v1, v2);
	//printf("插入新顶点，请输入顶点的值: ");
	//cin >> v1;
	//g.InsertVex(v1);
	//printf("插入与新顶点有关的边，请输入边数: ");
	//cin >> n;
	//for (k = 0; k<n; k++)
	//{
	//	printf("请输入另一顶点的值: ");
	//	cin >> v2;
	//	g.InsertArc(v1, v2);
	//}
	//g.Display();
	printf("删除一条边，请输入待删除边的两顶点(以空格作为间隔)：");
	cin >> v1 >> v2;
	g.DeleteArc(v1, v2);
	g.Display();
	printf("删除顶点及相关的边，请输入顶点的值: ");
	cin >> v1;
	g.DeleteVex(v1);
	g.Display();
	printf("深度优先搜索的结果:\n");
	g.DFSTraverse(visit);
	printf("广度优先搜索的结果:\n");
	g.BFSTraverse(visit);
	g.DestroyGraph();

    return 0;
}

