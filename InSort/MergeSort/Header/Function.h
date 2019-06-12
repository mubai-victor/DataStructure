#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"

#define N 7
#define MAX_SIZE 30
typedef int KeyType;
typedef int InfoType;
struct RedType {
	KeyType key;
	InfoType otherinfo;
};

class SqList {
private:
	RedType r[MAX_SIZE + 1];
	int lenght;
	void _Merge(RedType TR[], RedType SR[], int start, int mid, int end);
	void _MSort(RedType TR[], RedType SR[], int start, int end);
public:
	SqList(SqList&);
	SqList();
	void MergeSort();
	void Assign(RedType *p);
	void Print();
};

#endif