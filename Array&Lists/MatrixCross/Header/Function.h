#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"
#include "stdarg.h"

#define MAX_SIZE	100

class OLNode {
public:
	int i, j;
	ElemType elem;
	OLNode *right, *down;
public:
	OLNode();
};
typedef OLNode *OLink;

class CrossList {
private:
	OLink *OLrow, *OLcolumn;
	int row, column, num;
public:
	CrossList();
	void InsertAscend(OLink p);
	void DestroySMatrix();
	void CreateSMatrix(char *FileName);
	void InitSMatrixList();
	void PrintSMatrix();
	void PrintSMatrix1();
	void CopySMatrix(CrossList &R);
	void AddSMatrix(CrossList N, CrossList &R);
	void SubtSMatrix(CrossList N, CrossList &R);
	void MultSMatrix(CrossList N, CrossList &R);
	void TransposeSMatrix(CrossList &R);
};

int compare(int iR, int iL);


#endif