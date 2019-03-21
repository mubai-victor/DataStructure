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
	for (int iPos = 0; iPos <= row; iPos++) {
		rpos[iPos] = 0;
	}
	for(int iRow=1;iRow<=row;iRow++){
		for (int iPos = 0; iPos <= num; iPos++) {
			if (data[iPos].i == iRow) {
				rpos[iRow]++;
			}
		}
	}
	
	for (int iRow = row; iRow >= 1; iRow--) {	
		rpos[iRow] = 1;
		for (int iPos = 1; iPos < iRow; iPos++) {
			rpos[iRow] += rpos[iPos];
		}
	}
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
	memcpy(M.rpos, rpos, (row+1)*sizeof(int)); 
	M.row = row;
	M.column = column;
	M.num = num;
}
Status TSMatrix::AddSMatrix(TSMatrix M, TSMatrix&R)//矩阵R返回矩阵M和本矩阵的相加之和
{
	int iPosR = 1;
	if (M.row != row || M.column != column)
		return ERROR;
	for (int iRow = 1; iRow <= row; iRow++) {
		int iStartT = rpos[iRow], iStartM = M.rpos[iRow];
		int iEndT = 0, iEndM = 0;
		R.rpos[iRow] = iPosR;
		if (iRow == row) {
			iEndT = num + 1;
			iEndM = M.num + 1;
		}
		else {
			iEndT = rpos[iRow + 1];
			iEndM = M.rpos[iRow + 1];
		}
		while(iStartT < iEndT && iStartM < iEndM){
			if (data[iStartT].j == M.data[iStartM].j) {
				if (0 != data[iStartT].elem + M.data[iStartM].elem) {
					R.data[iPosR].elem = data[iStartT].elem + M.data[iStartM].elem;
					R.data[iPosR].i = data[iStartT].i;
					R.data[iPosR].j = data[iStartT].j;
					iPosR++;
				}
				iStartT++;
				iStartM++;
			}
			else if (data[iStartT].j < M.data[iStartM].j) {
				R.data[iPosR++] = data[iStartT++];
			}
			else {
				R.data[iPosR++] = M.data[iStartM++];
			}
		}
		while (iStartT < iEndT) {
			R.data[iPosR++] = data[iStartT++];
		}
		while (iStartM < iEndM) {
			R.data[iPosR++] = M.data[iStartM++];
		}
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
	int iStartT = 0, iStartM = 0; 
	int iEndT = 0, iEndM = 0;
	int iPosR = 1;
	ElemType *epResult = new ElemType[R.column + 1];
	for (int iRow = 1; iRow <= row; iRow++) {		
		for (int iPos = 0; iPos <= M.column; iPos++) {
			epResult[iPos] = 0;
		}
		iStartT = rpos[iRow];
		if (iRow == row) {
			iEndT = num + 1;
		}
		else {
			iEndT = rpos[iRow + 1];
		}
		while (iStartT < iEndT) {
			int iCol = data[iStartT].j;
			iStartM = M.rpos[iCol];
			if (iCol == M.row) {
				iEndM = M.num + 1;
			}
			else {
				iEndM = M.rpos[iCol + 1];
			}
			while (iStartM < iEndM) {
				epResult[M.data[iStartM].j] += data[iStartT].elem * M.data[iStartM].elem;
				iStartM++;
			}
			iStartT++;
		}
		R.rpos[iRow] = iPosR;
		for (int iPos = 0; iPos < row; iPos++) {
			if (epResult[iPos] != 0) {
				R.data[iPosR].elem = epResult[iPos];
				R.data[iPosR].i = iRow;
				R.data[iPosR].j = iPos;
				iPosR++;
			}
		}
	}
	R.num = iPosR - 1;
	delete[] epResult;
	if (R.num > MAX_SIZE)
		return ERROR;
	return OK;
}
void TSMatrix::TransposeSMatrix(TSMatrix &R)//当前矩阵转置得到矩阵R
{
	R.num = num;
	R.column = row;
	R.row = column;
	int iTotal = 1, iRow = 1;
	int *ipTemp = new int[R.row];
	for (int iPos = 0; iPos <= R.row;iPos++) {
		R.rpos[iPos] = 0;
	}
	for (int iPos = 1; iPos <= num; iPos++) {
		R.rpos[data[iPos].j]++;
	}

	for (int iRow = R.row; iRow >= 1; iRow--) {
		R.rpos[iRow] = 1;
		for (int iPos = 1; iPos < iRow; iPos++) {
			R.rpos[iRow] += R.rpos[iPos];
		}
	}
	for (int iPos = 1; iPos <= R.row; iPos++) {
		ipTemp[iPos] = R.rpos[iPos];
	}
	for (int iPos = 1; iPos <= num; iPos++) { 
		R.data[ipTemp[data[iPos].j]].elem = data[iPos].elem;
		R.data[ipTemp[data[iPos].j]].i = data[iPos].j;
		R.data[ipTemp[data[iPos].j]].j = data[iPos].i;
		++ipTemp[data[iPos].j];
	}
}


