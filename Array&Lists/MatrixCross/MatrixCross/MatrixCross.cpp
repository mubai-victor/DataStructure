// MatrixCross.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Function.h"
#include "Test.h"
#include "iostream"

using namespace std;

int main()
{
	CrossList A, B, C;
	printf("��������A: \n");
	A.CreateSMatrix("MatrixA.txt");
	A.PrintSMatrix1();
	printf("�ɾ���A���ƾ���B: \n");
	A.CopySMatrix(B);
	B.PrintSMatrix1();
	B.DestroySMatrix(); // CrossList���͵ı������ٴ�ʹ��֮ǰ����������
	printf("���پ���B��,����BΪ\n");
	B.PrintSMatrix1();
	printf("��������B2:(�����A���С�������ͬ)\n");
	B.CreateSMatrix("MatrixB2.txt");
	B.PrintSMatrix1();
	printf("����C1(A+B):\n");
	A.AddSMatrix(B, C);
	C.PrintSMatrix1();
	C.DestroySMatrix();
	printf("����C2(A-B):\n");
	A.SubtSMatrix(B, C);
	C.PrintSMatrix1();
	C.DestroySMatrix();
	printf("����C3(A��ת��):\n");
	A.TransposeSMatrix(C);
	C.PrintSMatrix1();
	A.DestroySMatrix();
	B.DestroySMatrix();
	C.DestroySMatrix();
	printf("��������A2: \n");
	A.CreateSMatrix("MatrixA2.txt");
	A.PrintSMatrix1();
	printf("��������B3:(����Ӧ�����A2��������ͬ)\n");
	B.CreateSMatrix("MatrixB3.txt");
	B.PrintSMatrix1();
	printf("����C5(A��B):\n");
	A.MultSMatrix(B, C);
	C.PrintSMatrix1();
	A.DestroySMatrix();
	B.DestroySMatrix();
	C.DestroySMatrix();
	return 0;
}

