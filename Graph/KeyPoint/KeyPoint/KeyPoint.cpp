// KeyPoint.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	MGraph graph;
	graph.CreateFUDG("UDG.txt");
	graph.Display();
	cout << "Output the key point:" << endl;
	graph.FindArticul();
	cout << "i" << ends << "vexs[i]" << ends << "visited[i]" << ends << "low[i]" << ends << "LowOrder[i]" << endl;
	graph.DisplayInfo();
    return 0;
}

