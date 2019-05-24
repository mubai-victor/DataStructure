// MarkList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	GList l;
	l.CreateGList("MarkList.txt"); // 在bo5-5.cpp中
	l.Traverse_GL(print);
	cout << endl;
	l.MarkList(); // 加标志
	l.Traverse_GL(print);
    return 0;
}

