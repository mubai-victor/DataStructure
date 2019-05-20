// CriticalPath.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	cALGraph h;
	printf("请选择有向网\n");
	h.CreateGraph(); // 构造有向网h，在bo7-2.cpp中
	h.Display(); // 输出有向网h，在bo7-2.cpp中
	h.CriticalPath(); // 求h的关键路径
    return 0;
}

