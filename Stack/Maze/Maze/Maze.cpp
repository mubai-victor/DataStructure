// Maze.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"
extern PosType start, end;
extern PosType maze[10][10];
extern int curstep;
int main()
{
	Init(1); // ��ʼ���Թ���ͨ��ֵΪ1
	if (MazePath(start, end)) // ��ͨ·
	{
		printf("���Թ�����ڵ����ڵ�һ��·������:\n");
		Print(); // �����ͨ·
	}
	else
		printf("���Թ�û�д���ڵ����ڵ�·��\n");
	return 0;
}

