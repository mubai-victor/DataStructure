// TopologicalSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

int main()
{
	cALGraph f;
	f.CreateGraph(); // 构造有向图f，在bo7-2.cpp中
	f.Display(); // 输出有向图f，在bo7-2.cpp中
	f.TopologicalSort(); // 输出有向图f的1个拓扑序列
    return 0;
}

