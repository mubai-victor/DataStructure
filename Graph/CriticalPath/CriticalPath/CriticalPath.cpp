// CriticalPath.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	cALGraph h;
	printf("��ѡ��������\n");
	h.CreateGraph(); // ����������h����bo7-2.cpp��
	h.Display(); // ���������h����bo7-2.cpp��
	h.CriticalPath(); // ��h�Ĺؼ�·��
    return 0;
}

