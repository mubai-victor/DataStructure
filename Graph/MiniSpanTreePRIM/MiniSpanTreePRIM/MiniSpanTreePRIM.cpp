// MiniSpanTreePRIM.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"
using namespace std;

int main()
{
	MGraph graph;
	graph.CreateFUDN(FILEUDN);
	graph.Display();
	graph.MiniSpanTreePrim();
	cout << endl << endl;
	graph.Kruskal();
    return 0;
}

