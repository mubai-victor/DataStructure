#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"
#include "stdarg.h"

#define MAX_ARRAY_DIM	8

class Array {
public:
	ElemType *base;
	int dim;
	int *bounds;
	int *constants;
public:
	Array();
	Status InitArray(int dim,...);
	void DestroyArray();
	Status Locate(va_list ap, int &offset);
	Status Value(ElemType *elem, ...);
	Status Assign(ElemType elem,...);
};




#endif