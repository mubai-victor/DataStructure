// MatrixCross.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"
#include "iostream"

using namespace std;

int main()
{
	CrossList A, B, C;
	printf("创建矩阵A: \n");
	A.CreateSMatrix("MatrixA.txt");
	A.PrintSMatrix1();
	printf("由矩阵A复制矩阵B: \n");
	A.CopySMatrix(B);
	B.PrintSMatrix1();
	B.DestroySMatrix(); // CrossList类型的变量在再次使用之前必须先销毁
	printf("销毁矩阵B后,矩阵B为\n");
	B.PrintSMatrix1();
	printf("创建矩阵B2:(与矩阵A的行、列数相同)\n");
	B.CreateSMatrix("MatrixB2.txt");
	B.PrintSMatrix1();
	printf("矩阵C1(A+B):\n");
	A.AddSMatrix(B, C);
	C.PrintSMatrix1();
	C.DestroySMatrix();
	printf("矩阵C2(A-B):\n");
	A.SubtSMatrix(B, C);
	C.PrintSMatrix1();
	C.DestroySMatrix();
	printf("矩阵C3(A的转置):\n");
	A.TransposeSMatrix(C);
	C.PrintSMatrix1();
	A.DestroySMatrix();
	B.DestroySMatrix();
	C.DestroySMatrix();
	printf("创建矩阵A2: \n");
	A.CreateSMatrix("MatrixA2.txt");
	A.PrintSMatrix1();
	printf("创建矩阵B3:(行数应与矩阵A2的列数相同)\n");
	B.CreateSMatrix("MatrixB3.txt");
	B.PrintSMatrix1();
	printf("矩阵C5(A×B):\n");
	A.MultSMatrix(B, C);
	C.PrintSMatrix1();
	A.DestroySMatrix();
	B.DestroySMatrix();
	C.DestroySMatrix();
	return 0;
}

