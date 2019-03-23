#include "stdafx.h"
#include "stdarg.h"
#include "Function.h"
#include "Test.h"
using namespace std;

//Status TSMatrix::CreateSMatrix(char *FileName)//从文件FileName中读取内容来创建矩阵
//{
//	int iPos = 1;
//	ElemType etemp;
//	FILE*pF = NULL;
//	errno_t status;
//	status = fopen_s(&pF, FileName,"r");
//	if (status != 0) {
//		cout << "无法打开文件" << FileName << endl;
//		return ERROR;
//	}
//	fgets(buf, MAX_SIZE, pF);
//	row = atoi(buf);
//	column = atoi(buf + 2);
//	num = 0;
//	for (int i = 0; i < row; i++) {
//		fgets(buf, MAX_SIZE, pF);
//		for (int j = 0; j < column; j++) {
//			etemp = atoi(buf + 2 * j);
//			if (0 != etemp) {
//				data[iPos].elem = etemp;
//				data[iPos].i = i + 1;
//				data[iPos].j = j + 1;
//				num++;
//				++iPos;
//			}				
//		}
//	}
//	fclose(pF);
//	for (int iPos = 0; iPos <= row; iPos++) {
//		rpos[iPos] = 0;
//	}
//	for(int iRow=1;iRow<=row;iRow++){
//		for (int iPos = 0; iPos <= num; iPos++) {
//			if (data[iPos].i == iRow) {
//				rpos[iRow]++;
//			}
//		}
//	}
//	
//	for (int iRow = row; iRow >= 1; iRow--) {	
//		rpos[iRow] = 1;
//		for (int iPos = 1; iPos < iRow; iPos++) {
//			rpos[iRow] += rpos[iPos];
//		}
//	}
//	return OK;
//}



