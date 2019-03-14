// Hanoi.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
void Hanoi(int n, char a, char b, char c);
void Move(char a, char b);
long long unsigned int count=0;
int main()
{
	printf("���������ֱ���a,b,c,������Բ�̵�������\n");
	int d;
	scanf_s("%d", &d);
	Hanoi(d, 'a', 'b', 'c');
	printf("total:%d", count);
	return 0;
}
void Hanoi(int n, char a, char b, char c)
{
	if (n == 1)
		Move(a,c);
	else {
		Hanoi(n - 1, a, c, b);
		Move(a, c);
		Hanoi(n - 1, b, a, c);
	}
}
void Move(char a, char b)
{
	printf("%c -> %c\n", a, b);
	count++;
}
