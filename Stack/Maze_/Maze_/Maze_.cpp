// Maze_.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"
extern PosType start, end;
extern int maze[10][10];
int main()
{
	Init(-1); // ��ʼ���Թ���ͨ��ֵΪ-1
	printf("���Թ�����ڵ����ڵ�·������:\n");
	maze[start.x][start.y] = 1; // ��ڵ��㼣Ϊ1
	Try(start, 1); // �ɵ�1�������̽�� 
	return 0;
}

