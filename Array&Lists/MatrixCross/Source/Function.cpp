#include "stdafx.h"
#include "stdarg.h"
#include "Function.h"
#include "Test.h"
using namespace std;

char buf[MAX_SIZE];

OLNode::OLNode()
{
	i = j = elem = 0;
	right = down = NULL;
}

CrossList::CrossList()
{
	OLcolumn = OLrow = NULL;
	row = column = num = 0;
}
void CrossList::InsertAscend(OLink p)
{
	int iRow = p->i;
	int iColumn = p->j;
	OLink OLtemp = NULL;

	for (int iPos = 1; iPos <= row; iPos++) {
		OLtemp = OLrow[iPos];
		while (OLtemp != NULL) {
			if (OLtemp->i == p->i&&OLtemp->j == p->j) {
				cout << "输入的值有误,矩阵此位置已经有元素。" << endl;
				exit(0);
			}
			OLtemp = OLtemp->right;
		}
	}
	OLtemp = OLcolumn[iColumn];
	if (OLtemp == NULL || OLtemp->j > iColumn) {
		p->down = OLcolumn[iColumn];
		OLcolumn[iColumn] = p;
	}
	else {
		while (OLtemp->down != NULL && OLtemp->down->j > iColumn) {
			OLtemp = OLtemp->down;
		}
		p->down = OLtemp->down;
		OLtemp->down = p;
	}
	OLtemp = OLrow[iRow];
	if (OLtemp == NULL || OLtemp->i > iRow) {
		p->right = OLrow[iRow];
		OLrow[iRow] = p;
	}
	else {
		while (OLtemp->right != NULL && OLtemp->right->i > iRow) {
			OLtemp = OLtemp->right;
		}
		p->right = OLtemp->right;
		OLtemp->right = p;
	}
	num++;
}
void CrossList::InitSMatrixList()
{
	OLrow = new OLink[row + 1];
	OLcolumn = new OLink[column + 1];
	for (int iPos = 0; iPos <= row; iPos++) {
		OLrow[iPos] = NULL;
	}
	for (int iPos = 0; iPos <= column; iPos++) {
		OLcolumn[iPos] = NULL;
	}
}
void CrossList::DestroySMatrix()
{
	OLink OLtemp = NULL, OLdel = NULL;
	for (int iPos = 1; iPos <= row; iPos++) {
		OLtemp = OLrow[iPos];
		while (OLtemp != NULL) {
			OLdel = OLtemp;
			OLtemp = OLtemp->right;
			delete[] OLdel;
		}
	}
	delete[] OLrow;
	OLrow = NULL;
	delete[] OLcolumn;
	OLcolumn = NULL;
	column = row = num = 0;
}
void CrossList::CreateSMatrix(char *FileName)
{
	OLink OLtemp = NULL;
	ElemType etemp;
	FILE*pF = NULL;
	errno_t status;
	status = fopen_s(&pF, FileName, "r");
	if (status != 0) {
		cout << "无法打开文件" << FileName << endl;
		exit(0);
	}
	fgets(buf, MAX_SIZE, pF);
	row = atoi(buf);
	column = atoi(buf + 2);
	InitSMatrixList();
	num = 0;
	for (int i = 0; i < row; i++) {
		fgets(buf, MAX_SIZE, pF);
		for (int j = 0; j < column; j++) {
			etemp = atoi(buf + 2 * j);
			if (0 != etemp) {
				OLtemp = new OLNode;
				OLtemp->elem = etemp;
				OLtemp->i = i + 1;
				OLtemp->j = j + 1;
				InsertAscend(OLtemp);
				OLtemp = NULL;
			}
		}
	}
	fclose(pF);
}
void CrossList::PrintSMatrix()
{
	char status;
	OLink OLtemp = NULL;
	cout << "请选择按行输出(r)或者按列输出(c)：" << endl;
	cin >> status;
	switch (status) {
		cout << row << "行" << column << "列" << num << "元素" << endl;
	case 'r':
		for (int iPos = 1; iPos <= row; iPos++) {
			OLtemp = OLrow[iPos];
			while (OLtemp != NULL) {
				cout << OLtemp->i << ends << OLtemp->j << ends << OLtemp->elem << endl;
				OLtemp = OLtemp->right;
			}
		}
		break;
	case 'c':
		for (int iPos = 1; iPos <= column; iPos++) {
			OLtemp = OLcolumn[iPos];
			while (OLtemp != NULL) {
				cout << OLtemp->i << ends << OLtemp->j << ends << OLtemp->elem << endl;
				OLtemp = OLtemp->down;
			}
		}		
		break;
	default:
		cout << "输入有误" << endl;
	}
}
void CrossList::PrintSMatrix1()
{
	OLink OLtemp = NULL;
	for (int iRow = 1; iRow <= row; iRow++) {
		OLtemp = OLrow[iRow];
		for (int iColumn = 1; iColumn <= column; iColumn++) {
			if (OLtemp != NULL && OLtemp->j == iColumn) {
				cout << OLtemp->elem << ends;
				OLtemp = OLtemp->right;
			}
			else {
				cout << '0' << ends;
			}
		}
		cout << endl;
	}
}
void CrossList::CopySMatrix(CrossList &R)
{
	OLink OLtemp = NULL, OLinsert = NULL;
	R.column = column;
	R.row = row;
	R.num = num;
	R.InitSMatrixList();
	for (int iPos = 1; iPos <= row; iPos++) {
		OLtemp = OLrow[iPos];
		while (OLtemp != NULL) {
			OLinsert = new OLNode;
			*OLinsert = *OLtemp;
			R.InsertAscend(OLinsert);
			OLtemp = OLtemp->right;
			OLinsert = NULL;
		}
	}
}
void CrossList::AddSMatrix(CrossList N, CrossList &R)
{
	if (row != N.row || column != N.column) {
		cout << "两个矩阵形式不一致，不能进行加减运算。" << endl;
		exit(0);
	}
	OLink OLn = NULL, OLt = NULL, OLinsert = NULL;
	R.column = column;
	R.row = row;
	R.num = 0;
	R.InitSMatrixList();
	for (int iPos = 1; iPos <= row; iPos++) {
		OLn = N.OLrow[iPos];
		OLt = OLrow[iPos];
		while (OLn != NULL&&OLt != NULL) {
			OLinsert = new OLNode;
			switch (compare(OLt->j, OLn->j)) {				
			case 1:
				*OLinsert = *OLn;
				R.InsertAscend(OLinsert);
				OLn = OLn->right;
				OLinsert = NULL;
				break;
			case 0:
				*OLinsert = *OLn;
				OLinsert->elem += OLt->elem;
				if (OLinsert->elem != 0) {
					R.InsertAscend(OLinsert);
				}
				else {
					delete OLinsert;
				}
				OLn = OLn->right;
				OLt = OLt->right;
				OLinsert = NULL;
				break;
			case -1:
				*OLinsert = *OLt;
				R.InsertAscend(OLinsert);
				OLt = OLt->right;
				OLinsert = NULL;
				break;
			}
		}
		while (OLn != NULL) {
			OLinsert = new OLNode;
			*OLinsert = *OLn;
			R.InsertAscend(OLinsert);
			OLinsert = NULL;
			OLn = OLn->right;
		}
		while (OLt != NULL) {
			OLinsert = new OLNode;
			*OLinsert = *OLt;
			R.InsertAscend(OLinsert);
			OLinsert = NULL;
			OLt = OLt->right;
		}
	}
}
void CrossList::SubtSMatrix(CrossList N, CrossList &R)
{
	OLink OLtemp = NULL;
	for (int iPos = 1; iPos <= row; iPos++) {
		OLtemp = N.OLrow[iPos];
		while (OLtemp != NULL) {
			OLtemp->elem *= (-1);
			OLtemp = OLtemp->right;
		}
	}
	AddSMatrix(N, R);
	for (int iPos = 1; iPos <= row; iPos++) {
		OLtemp = N.OLrow[iPos];
		while (OLtemp != NULL) {
			OLtemp->elem *= (-1);
			OLtemp = OLtemp->right;
		}
	}
}
void CrossList::MultSMatrix(CrossList N, CrossList &R)
{
	if (column != N.row) {
		cout << "矩阵的形式不正确，不能相乘。" << endl;
		exit(0);
	}
	R.column = N.column;
	R.row = row;
	R.num = 0;
	R.InitSMatrixList();
	OLink OLt = NULL, OLn = NULL, OLtemp = NULL;
	for (int iRow = 1; iRow <= R.row; iRow++) {
		OLt = OLrow[iRow];
		for (int iColumn = 1; iColumn <= R.column; iColumn++) {
			int result = 0;
			OLn = N.OLcolumn[iColumn];		
			while (OLt != NULL&&OLn != NULL) {
				switch (compare(OLt->j, OLn->i)) {
				case -1:
					OLt = OLt->right;
					break;
				case 0:
					result += (OLt->elem)*(OLn->elem);
					OLt = OLt->right;
					OLn = OLn->down;
					break;
				case 1:
					OLn = OLn->down;
					break;
				}
			}
			if (result != 0) {
				OLtemp = new OLNode;
				OLtemp->elem = result;
				OLtemp->i = iRow;
				OLtemp->j = iColumn;
				R.InsertAscend(OLtemp);
				OLtemp = NULL;
			}
		}
	}
}
void CrossList::TransposeSMatrix(CrossList &R)
{
	OLink OLswap = NULL, OLtemp = NULL;
	R.column = row;
	R.row = column;
	R.num = 0;
	R.InitSMatrixList();
	for (int iPos = 1; iPos <= row; iPos++) {
		OLtemp = OLrow[iPos];
		while (OLtemp != NULL) {
			OLswap = new OLNode;
			*OLswap = *OLtemp;
			OLswap->i = OLtemp->j;
			OLswap->j = OLtemp->i;
			R.InsertAscend(OLswap);
			OLtemp = OLtemp->right;
		}
	}
}

int compare(int iR, int iL) {
	return (iR - iL) == 0 ? 0 : ((iR - iL) > 0 ? 1 : -1);
}
