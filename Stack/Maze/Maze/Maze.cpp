// Maze.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"
extern PosType start, end;
extern PosType maze[10][10];
extern int curstep;
int main()
{
	Init(1); // 初始化迷宫，通道值为1
	if (MazePath(start, end)) // 有通路
	{
		printf("此迷宫从入口到出口的一条路径如下:\n");
		Print(); // 输出此通路
	}
	else
		printf("此迷宫没有从入口到出口的路径\n");
	return 0;
}

