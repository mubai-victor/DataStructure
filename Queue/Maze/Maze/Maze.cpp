// Maze.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

int main()
{
	Init(1); // 初始化迷宫，通道值为1
	Path(); // 求一条迷宫路径
	return 0;
}

