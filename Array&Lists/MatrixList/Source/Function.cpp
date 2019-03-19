#include "stdafx.h"
#include "stdarg.h"
#include "Function.h"
#include "Test.h"
using namespace std;

char buf[MAX_SIZE];

Triple::Triple() {
	i = 0;
	j = 0;
	elem = 0;
}


TSMatrix::TSMatrix()
{
	row = 0;
	column = 0;
	num = 0;
}
Status TSMatrix::CreateSMatrix(char *FileName)
{
	int iPos = 0;
	ElemType etemp;
	FILE*pF = NULL;
	errno_t status;
	fopen_s(&pF, FileName,"r");
	if (status == 0) {
		cout << "无法打开文件‘MatrixList.txt’。" << endl;
	}
	fgets(buf, MAX_SIZE, pF);
	row = atoi(buf);
	column = atoi(buf + 2);
	for (int i = 0; i < row; i++) {
		fgets(buf, MAX_SIZE, pF);
		for (int j = 0; j < column; j++) {
			etemp = *(buf + 2 * j);
			if (0 != etemp) {
				data[++iPos].elem = etemp;
				data[++iPos].i = i;
				data[++iPos].j = j;
				num++;
			}				
		}
	}
	fclose(pF);
}
void TSMatrix::DestroySMatrix()
{
	row = 0;
	column = 0;
	num = 0;
}
void TSMatrix::PrintSMatrixl()
{
	Triple *pT = NULL;
	int inum = 1;
	pT = data + 1;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (pT->i == i&&pT->j == j&&inum < num) {
				cout << pT->elem << ends;
				num++;
			}
			else {
				cout << '0' << ends;
			}
		}
		cout << endl;
	}
}
void TSMatrix::PrintSMatrix() {
	int iPos = 0;
	cout << row << "行" << column << "列" << num << "个元素值" << endl;
	for(int iPos = 0;)
}
void TSMatrix::CopySMatrix();
Status TSMatrix::AddSMatrix(TSMatrix&M);
Status TSMatrix::SubSMatrix(TSMatrix&M);
Status TSMatrix::MultSMatrix(TSMatrix M, TSMatrix &R);
Status TSMatrix::TransposeSMatrix(TSMatrix &R);
int compare(int iR, int iL);
