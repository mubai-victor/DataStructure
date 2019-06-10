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
public:
	SqList(SqList&);
	SqList();
	void Assign(RedType *p);
	void InsertSort();
	void BInsertSort();
	void P2InsertSort();
	void Print();
};

#endif