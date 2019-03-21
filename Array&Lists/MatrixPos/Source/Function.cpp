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


TSMatrix::TSMatrix()//初始化类
{
	row = 0;
	column = 0;
	num = 0;
}
Status TSMatrix::CreateSMatrix(char *FileName)//从文件FileName中读取内容来创建矩阵
{
	int iPos = 1;
	ElemType etemp;
	FILE*pF = NULL;
	errno_t status;
	status = fopen_s(&pF, FileName,"r");
	if (status != 0) {
		cout << "无法打开文件" << FileName << endl;
		return ERROR;
	}
	fgets(buf, MAX_SIZE, pF);
	row = atoi(buf);
	column = atoi(buf + 2);
	num = 0;
	for (int i = 0; i < row; i++) {
		fgets(buf, MAX_SIZE, pF);
		for (int j = 0; j < column; j++) {
			etemp = atoi(buf + 2 * j);
			if (0 != etemp) {
				data[iPos].elem = etemp;
				data[iPos].i = i + 1;
				data[iPos].j = j + 1;
				num++;
				++iPos;
			}				
		}
	}
	fclose(pF);
	return OK;
}
void TSMatrix::DestroySMatrix()//销毁矩阵
{
	row = 0;
	column = 0;
	num = 0;
}
void TSMatrix::PrintSMatrix1()//用矩阵的形式打印出来矩阵
{
	Triple *pT = NULL;
	int inum = 1;
	pT = data + 1;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= column; j++) {
			if (pT->i == i&&pT->j == j&&inum <= num) {
				cout << pT->elem << ends;
				inum++;
				pT++;
			}
			else {
				cout << '0' << ends;
			}
		}
		cout << endl;
	}
}
void TSMatrix::PrintSMatrix()//按原样打印出来矩阵
{
	cout << row << "行" << column << "列" << num << "个元素值" << endl;
	for (int iPos = 1; iPos <= num; iPos++) {
		cout << '(' << data[iPos].i << ',' << ends;
		cout << data[iPos].j << ')' << ends;
		cout << '=' << data[iPos].elem << endl;
	}
}
void TSMatrix::CopySMatrix(TSMatrix&M)//将当前矩阵的内容复制到矩阵M中
{
	memcpy(M.data, data, (num+1)*sizeof(Triple)); 
	M.row = row;
	M.column = column;
	M.num = num;
}
Status TSMatrix::AddSMatrix(TSMatrix M, TSMatrix&R)//矩阵R返回矩阵M和本矩阵的相加之和
{
	int iPosT = 1, iPosR = 1, iPosM = 1;
	if (M.row != row || M.column != column)
		return ERROR;
	while(iPosT<=num&&iPosM<=M.num){
		switch (compare(data[iPosT].i, M.data[iPosM].i)) {
		case 0: 
			switch (compare(data[iPosT].j, M.data[iPosM].j)) {
			case 0:
				R.data[iPosR].i = data[iPosT].i;
				R.data[iPosR].j = data[iPosT].j;
				R.data[iPosR].elem = data[iPosT].elem + M.data[iPosM].elem;
				if (0 == R.data[iPosR].elem) {
					iPosR--;
				}
				iPosT++;
				iPosM++;
				iPosR++;
				break;
			case -1:
				R.data[iPosR++] = M.data[iPosM++];
				break;
			case 1:
				R.data[iPosR++] = M.data[iPosT++];
			}			
			break;
		case -1:
			R.data[iPosR++] = M.data[iPosM++];
			break;
		case 1:
			R.data[iPosR++] = M.data[iPosT++];		
		}
	}
	while (iPosT <= num) {
		R.data[iPosR++] = data[iPosT++];
	}
	while (iPosM <= M.num) {
		R.data[iPosR++] = M.data[iPosM++];
	}
	R.num = iPosR - 1;
	R.row = row;
	R.column = column;
	if (iPosR > MAX_SIZE)
		return ERROR;
	return OK;
}
Status TSMatrix::SubSMatrix(TSMatrix M, TSMatrix&R)//R矩阵返回当前矩阵减M矩阵的差
{
	for (int iPos = 1; iPos <= M.num; iPos++) {
		M.data[iPos].elem *= -1;
		AddSMatrix(M, R);
	}
	return AddSMatrix(M, R);
}
Status TSMatrix::MultSMatrix(TSMatrix M, TSMatrix &R)//R矩阵返回当前矩阵和M矩阵的乘积
{
	if (column != M.row)
		return ERROR;
	R.row = row;
	R.column = M.column;
	R.num = 0;
	ElemType *epResult = new ElemType[R.column + 1];
	ElemType *epRow = new ElemType[column + 1];
	for (int iPos = 1; iPos <= R.column; iPos++) {
		for (int iTemp = 0; iTemp <= R.column; iTemp++) {
			epResult[iTemp] = 0;
		}
		for (int iTemp = 0; iTemp <= column; iTemp++) {
			epRow[iTemp] = 0;
		}
		epResult[0]; epResult[1]; epResult[2]; epResult[3];
		epRow[0]; epRow[1]; epRow[2]; epRow[3];
		for (int iTemp = 1; iTemp <= num; iTemp++) {
			if (data[iTemp].i == iPos)
				epRow[data[iTemp].j] = data[iTemp].elem;
		}
		for (int iTemp = 1; iTemp <= M.num; iTemp++) {
			epResult[M.data[iTemp].j] = epRow[M.data[iTemp].i] * M.data[iTemp].elem;
		}
		for (int iTemp = 1; iTemp <= R.column; iTemp++) {
			if (epResult[iTemp]) {
				R.num++;
				R.data[R.num].elem = epResult[iTemp];
				R.data[R.num].i = iPos;
				R.data[R.num].j = iTemp;
				
			}
		}
	}
	delete[] epResult;
	delete[] epRow;
	if (R.num > MAX_SIZE)
		return ERROR;
	return OK;
}
void TSMatrix::TransposeSMatrix(TSMatrix &R)//当前矩阵转置得到矩阵R
{
	R.num = num;
	R.column = row;
	R.row = column;
	int iTotal = 1;
	for (int iPos = 1; iPos <= R.row; iPos++) {
		for (int iTemp = 1; iTemp <= num;iTemp++) {
			if (data[iTemp].j == iPos) {
				R.data[iTotal].elem = data[iTemp].elem;
				R.data[iTotal].i = data[iTemp].j;
				R.data[iTotal].j = data[iTemp].i;
				iTotal++;
			}
		}
	}
}
void TSMatrix::FastTransposeSMatrix(TSMatrix &R)//快速转置矩阵
{
	ElemType *eCpot = NULL, *eColumn = NULL;
	int iColumn = 0, iCur = 0;
	R.num = num;
	R.column = row;
	R.row = column;
	eCpot = new ElemType[column + 1];
	eColumn = new ElemType[column + 1];
	if (!eCpot || !eColumn)
		exit(0);
	for (int iPos = 1; iPos <= column; iPos++) {
		eCpot[iPos] = 0;
		eColumn[iPos] = 0;
	}
	for (int iPos = 1; iPos <= num; iPos++) {
		++eColumn[data[iPos].j];
	}
	eCpot[1] = 1;
	for (int iPos = 2; iPos <= column; iPos++) {
		eCpot[iPos] = eCpot[iPos - 1] + eColumn[iPos - 1];
	}
	for (int iPos = 1; iPos <= num; iPos++) {
		iColumn = data[iPos].j;
		iCur = eCpot[iColumn];
		R.data[iCur].elem = data[iPos].elem;
		R.data[iCur].i = data[iPos].j;
		R.data[iCur].j = data[iPos].i;
		++eCpot[iColumn];
	}
	delete[] eCpot;
	delete[] eColumn;
}


int compare(int iR, int iL) {
	return (iR - iL) == 0 ? 0 : ((iR - iL) > 0 ? 1 : -1);
}
