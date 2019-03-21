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
	void PrintSMatrix1();
	void PrintSMatrix();
	void CopySMatrix(TSMatrix&M);
	Status AddSMatrix(TSMatrix M, TSMatrix&R);
	Status SubSMatrix(TSMatrix M, TSMatrix&R);
	Status MultSMatrix(TSMatrix M, TSMatrix &R);
	void TransposeSMatrix(TSMatrix &R);
	void FastTransposeSMatrix(TSMatrix &R);
	friend int compare(int iR, int iL);
};

int compare(int iR, int iL);


#endif