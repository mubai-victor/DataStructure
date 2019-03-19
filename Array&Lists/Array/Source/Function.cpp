#include "stdafx.h"
#include "stdarg.h"
#include "Function.h"
#include "Test.h"

Array::Array()
{
	base = NULL;
	dim = 0;
	bounds = NULL;
	constants = NULL;
}
Status Array::InitArray(int dim, ...)
{
	va_list ap;
	va_start(ap, dim);
	bounds = new int[dim];
	long unsigned TotalElem = 1;
	if (!bounds)
		exit(0);
	this->dim = dim;
	for (int i = 0; i < dim; i++) {
		bounds[i] = va_arg(ap, ElemType);
		if (bounds[i] < 0)
			return ERROR;
		TotalElem *= bounds[i];
	}
	constants = new int[dim];	
	if (!constants)
		exit(0);
	constants[dim - 1] = 1;
	for (int i = dim - 2; i >= 0; i--) {
		constants[i] = constants[i + 1] * bounds[i + 1];
	}
	base = new ElemType[TotalElem];
	if (!base)
		exit(0);
	return OK;
}
void Array::DestroyArray()
{
	delete[] base;
	delete[] constants;
	delete[] bounds;
	base = constants = bounds = NULL;
}
Status Array::Locate(va_list ap, int &offset)
{
	offset = 0;
	int iDims = 0;
	for (int i = 0; i < dim; i++) {
		iDims = va_arg(ap, int);
		if (iDims<0 || iDims>bounds[i])
			return ERROR;
		offset += iDims*constants[i];
	}
	return OK;
}
Status Array::Value(ElemType *elem, ...)
{
	va_list vaP;
	va_start(vaP, elem);
	int offset = 0;
	if (Locate(vaP, offset) == OK) {
		*elem = *(base + offset);//错误的写法：elem=(base+offset),这样只是将形参elem的地址改变了，但是实参elem的地址并没有改变。
		va_end(vaP);
		return OK;
	}
	va_end(vaP);
	return ERROR;
}
Status Array::Assign(ElemType elem, ...)
{
	va_list vaP;
	va_start(vaP, elem);
	int offset = 0;
	if (Locate(vaP, offset) == OK) {
		*(base + offset) = elem;
		va_end(vaP);
		return OK;
	}
	va_end(vaP);
	return ERROR;
}