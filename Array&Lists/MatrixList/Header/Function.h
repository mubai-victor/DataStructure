#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"
#include "stdarg.h"

#define MAX_SIZE	100

struct Triple {
	int i, j;
	ElemType elem;
	Triple();
};

class TSMatrix{
private:
	Triple data[MAX_SIZE + 1];
	int row, column, num;
public:
	TSMatrix();
	Status CreateSMatrix(char *FileName);
	void DestroySMatrix();
	void PrintSMatrixl();
	void PrintSMatrix();
	void CopySMatrix();
	Status AddSMatrix(TSMatrix&M);
	Status SubSMatrix(TSMatrix&M);
	Status MultSMatrix(TSMatrix M, TSMatrix &R);
	Status TransposeSMatrix(TSMatrix &R);
	friend int compare(int iR, int iL);
};

int compare(int iR, int iL);


#endif