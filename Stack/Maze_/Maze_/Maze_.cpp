// Maze_.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"
extern PosType start, end;
extern int maze[10][10];
int main()
{
	Init(-1); // 初始化迷宫，通道值为-1
	printf("此迷宫从入口到出口的路径如下:\n");
	maze[start.x][start.y] = 1; // 入口的足迹为1
	Try(start, 1); // 由第1步入口试探起 
	return 0;
}

