// ShortestPath_DIJ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	MGraph g;
	g.CreateDN(FILEDN); // ����������g
	g.Display(); // ���������g
	g.ShortestPath_DIJ(0);
    return 0;
}

