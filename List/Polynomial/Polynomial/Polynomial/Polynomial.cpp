// Polynomial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

int main(int argc, _TCHAR* argv[])
{
	polynomial p, q;
	int m;
	printf("�������1��һԪ����ʽ�ķ�����ĸ����� ");
	scanf("%d", &m);
	CreatPolyn(p, m);
	printf("�������2��һԪ����ʽ�ķ�����ĸ����� ");
	
//	scanf("%d", &m);
//	CreatPolyn(q, m);


//	AddPolyn1(p, q);
//	printf("2��һԪ����ʽ��ӵĽ���� \n");
//	PrintPolyn(p);
//	printf("�������3��һԪ����ʽ�ķ�����ĸ����� ");
//	scanf("%d", &m);
//	CreatPolyn(q, m);
//	AddPolyn1(p, q);
//	printf("2��һԪ����ʽ��ӵĽ��(��һ�ַ���)�� \n");
//		PrintPolyn(p);
//	printf("�������4��һԪ����ʽ�ķ�����ĸ����� ");
//	scanf("%d", &m);
//	CreatPolyn(q, m);
//	SubtractPolyn(p, q);
//	printf("2��һԪ����ʽ����Ľ���� \n");
//	PrintPolyn(p);
////	printf("�������5��һԪ����ʽ�ķ�����ĸ����� ");
	scanf("%d", &m);
	CreatPolyn(q, m);
	MultiplyPolyn(p, q);
	PrintPolyn(p);
	DestroyPolyn(p);
	return 0;
}

