// MatrixPos.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include "Test.h"
#include "Function.h"

using namespace std;
int main()
{
	TSMatrix A, B, C;
	printf("��������A:\n");
	A.CreateSMatrix("MatrixA.txt");
	A.PrintSMatrix();
	printf("�ɾ���A���ƾ���B:\n");
	A.CopySMatrix(B);
	B.PrintSMatrix1();
	B.DestroySMatrix();
	printf("���پ���B��:\n");
	B.PrintSMatrix1();
	printf("��������B2:(�����A���С�������ͬ.\n");
	B.CreateSMatrix("MatrixB2.txt");
	B.PrintSMatrix1();
	B.AddSMatrix(A, C);
	printf("����C1(A+B):\n");
	C.PrintSMatrix1();
	C.DestroySMatrix();
	A.SubSMatrix(B, C);
	printf("����C2(A-B):\n");
	C.PrintSMatrix1();
	A.TransposeSMatrix(C);
	printf("����C3(A��ת��):\n");
	C.PrintSMatrix1();
	printf("��������A2:\n");
	A.CreateSMatrix("MatrixA2.txt");
	A.PrintSMatrix1();
	printf("��������B3:(����Ӧ�����A2��������ͬ.\n");
	B.CreateSMatrix("MatrixB3.txt");
	B.PrintSMatrix1();
	A.MultSMatrix(B, C);
	printf("����C5(A��B):\n");
	C.PrintSMatrix1();
	A.DestroySMatrix();
	return 0;
}


