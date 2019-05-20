// ShortestPath_DIJ.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	MGraph g;
	g.CreateDN(FILEDN); // 构造有向网g
	g.Display(); // 输出有向网g
	g.ShortestPath_DIJ(0);
    return 0;
}

