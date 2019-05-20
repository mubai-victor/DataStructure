// ShortestPath_FLOYD.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	MGraph g;
	g.CreateDN(FILEDN);
	g.Display();
	g.ShortestPath_FLOYD();
	g.PrintInfo();
    return 0;
}

