// TopologicalSort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	cALGraph f;
	f.CreateGraph(); // ��������ͼf����bo7-2.cpp��
	f.Display(); // �������ͼf����bo7-2.cpp��
	f.TopologicalSort(); // �������ͼf��1����������
    return 0;
}

