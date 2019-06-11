#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"

#define N 8
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
	int _Partition(int low, int high);
	int _Partition_(int low, int high);
	void _QSort(int low, int high);
public:
	SqList(SqList&);
	SqList();
	void Assign(RedType *p);
	void QuickSort();
	void Print();
};

#endif