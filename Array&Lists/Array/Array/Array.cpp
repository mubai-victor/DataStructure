// Array.cpp : �������̨Ӧ�ó������ڵ㡣
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
	int i, j, k, *p, dim = 3, bound1 = 3, bound2 = 4, bound3 = 2; // A[3][4][2]����
	ElemType e, *p1;
	A.InitArray(dim, bound1, bound2, bound3); // ����3��4��2��3ά����A(��ͼ52)
	p = A.bounds;
	printf("A.bounds=");
	for (i = 0; i<dim; i++) // ˳�����A.bounds
		printf("%d ", *(p + i));
	p = A.constants;
	printf("\nA.constants=");
	for (i = 0; i<dim; i++) // ˳�����A.constants
		printf("%d ", *(p + i));
	printf("\n%dҳ%d��%d�о���Ԫ������:\n", bound1, bound2, bound3);
	for (i = 0; i<bound1; i++)
	{
		for (j = 0; j<bound2; j++)
		{
			for (k = 0; k<bound3; k++)
			{
				A.Assign(i * 100 + j * 10 + k, i, j, k); // ��i��100+j��10+k��ֵ��A[i][j][k]
				A.Value(&e,i, j, k); // ��A[i][j][k]��ֵ����e
				printf("A[%d][%d][%d]=%2d ", i, j, k, e); // ���A[i][j][k]
			}
			printf("\n");
		}
		printf("\n");
	}
	p1 = A.base;
	printf("A.base=\n");
	for (i = 0; i<bound1*bound2*bound3; i++) // ˳�����A.base
	{
		printf("%4d", *(p1 + i));
		if (i % (bound2*bound3) == bound2*bound3 - 1)
			printf("\n");
	}
	printf("A.dim=%d\n", A.dim);
	A.DestroyArray();
	
	return 0;
}


