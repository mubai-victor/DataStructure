// MarkList.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	GList l;
	l.CreateGList("MarkList.txt"); // ��bo5-5.cpp��
	l.Traverse_GL(print);
	cout << endl;
	l.MarkList(); // �ӱ�־
	l.Traverse_GL(print);
    return 0;
}

