// Array.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Test.h"
#include "Function.h"
#include "iostream"
#include "stdarg.h"

using namespace std;

int main()
{
	Array A;
	int i, j, k, *p, dim = 3, bound1 = 3, bound2 = 4, bound3 = 2; // A[3][4][2]数组
	ElemType e, *p1;
	A.InitArray(dim, bound1, bound2, bound3); // 构造3×4×2的3维数组A(见图52)
	p = A.bounds;
	printf("A.bounds=");
	for (i = 0; i<dim; i++) // 顺序输出A.bounds
		printf("%d ", *(p + i));
	p = A.constants;
	printf("\nA.constants=");
	for (i = 0; i<dim; i++) // 顺序输出A.constants
		printf("%d ", *(p + i));
	printf("\n%d页%d行%d列矩阵元素如下:\n", bound1, bound2, bound3);
	for (i = 0; i<bound1; i++)
	{
		for (j = 0; j<bound2; j++)
		{
			for (k = 0; k<bound3; k++)
			{
				A.Assign(i * 100 + j * 10 + k, i, j, k); // 将i×100+j×10+k赋值给A[i][j][k]
				A.Value(&e,i, j, k); // 将A[i][j][k]的值赋给e
				printf("A[%d][%d][%d]=%2d ", i, j, k, e); // 输出A[i][j][k]
			}
			printf("\n");
		}
		printf("\n");
	}
	p1 = A.base;
	printf("A.base=\n");
	for (i = 0; i<bound1*bound2*bound3; i++) // 顺序输出A.base
	{
		printf("%4d", *(p1 + i));
		if (i % (bound2*bound3) == bound2*bound3 - 1)
			printf("\n");
	}
	printf("A.dim=%d\n", A.dim);
	A.DestroyArray();
	
	return 0;
}


