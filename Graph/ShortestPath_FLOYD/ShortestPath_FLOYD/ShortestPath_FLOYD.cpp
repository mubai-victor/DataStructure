// ShortestPath_FLOYD.cpp : �������̨Ӧ�ó������ڵ㡣
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

