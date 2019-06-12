#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"

#define N 8
#define T 3
#define SIZE 20

typedef int KeyType;
typedef int InfoType;

enum IsInf{INF,UNINF};

struct RedType {
	KeyType key;
	InfoType otherinfo;
};


class SLinkListType {
private:
	RedType r[SIZE];
	RedType *p;
	int length;
public:
	SLinkListType(SLinkListType &L);
	SLinkListType();
	~SLinkListType();
	int SelectMinKey(int i);
	void SelectSort();
	void TreeSort();
	void HeapAdjust(int start,int end);
	void HeapSort();
	void Assign(RedType D[], int n);
	void Print();
};

#endif