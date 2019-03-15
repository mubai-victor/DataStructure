// Polynomial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"

int main(int argc, _TCHAR* argv[])
{
	polynomial p, q;
	int m;
	printf("请输入第1个一元多项式的非零项的个数： ");
	scanf("%d", &m);
	CreatPolyn(p, m);
	printf("请输入第2个一元多项式的非零项的个数： ");
	
//	scanf("%d", &m);
//	CreatPolyn(q, m);


//	AddPolyn1(p, q);
//	printf("2个一元多项式相加的结果： \n");
//	PrintPolyn(p);
//	printf("请输入第3个一元多项式的非零项的个数： ");
//	scanf("%d", &m);
//	CreatPolyn(q, m);
//	AddPolyn1(p, q);
//	printf("2个一元多项式相加的结果(另一种方法)： \n");
//		PrintPolyn(p);
//	printf("请输入第4个一元多项式的非零项的个数： ");
//	scanf("%d", &m);
//	CreatPolyn(q, m);
//	SubtractPolyn(p, q);
//	printf("2个一元多项式相减的结果： \n");
//	PrintPolyn(p);
////	printf("请输入第5个一元多项式的非零项的个数： ");
	scanf("%d", &m);
	CreatPolyn(q, m);
	MultiplyPolyn(p, q);
	PrintPolyn(p);
	DestroyPolyn(p);
	return 0;
}

