// MatrixPos.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "Test.h"
#include "Function.h"

using namespace std;
int main()
{
	TSMatrix A, B, C;
	printf("创建矩阵A:\n");
	A.CreateSMatrix("MatrixA.txt");
	A.PrintSMatrix();
	printf("由矩阵A复制矩阵B:\n");
	A.CopySMatrix(B);
	B.PrintSMatrix1();
	B.DestroySMatrix();
	printf("销毁矩阵B后:\n");
	B.PrintSMatrix1();
	printf("创建矩阵B2:(与矩阵A的行、列数相同.\n");
	B.CreateSMatrix("MatrixB2.txt");
	B.PrintSMatrix1();
	B.AddSMatrix(A, C);
	printf("矩阵C1(A+B):\n");
	C.PrintSMatrix1();
	C.DestroySMatrix();
	A.SubSMatrix(B, C);
	printf("矩阵C2(A-B):\n");
	C.PrintSMatrix1();
	A.TransposeSMatrix(C);
	printf("矩阵C3(A的转置):\n");
	C.PrintSMatrix1();
	printf("创建矩阵A2:\n");
	A.CreateSMatrix("MatrixA2.txt");
	A.PrintSMatrix1();
	printf("创建矩阵B3:(行数应与矩阵A2的列数相同.\n");
	B.CreateSMatrix("MatrixB3.txt");
	B.PrintSMatrix1();
	A.MultSMatrix(B, C);
	printf("矩阵C5(A×B):\n");
	C.PrintSMatrix1();
	A.DestroySMatrix();
	return 0;
}


