#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"

#define N 8
#define SIZE 100
typedef int KeyType;
typedef int InfoType;

struct RedType {
	KeyType key;
	InfoType otherinfo;
};
struct SLNode {
	RedType rc;
	int next;
};

class SLinkListType {
private:
	SLNode r[SIZE];
	int addr[SIZE];
	int length;
public:
	SLinkListType(SLinkListType &L);
	SLinkListType();
	void TableInsert(RedType D[], int n);
	void Arrange();
	void Sort();
	void Rearrange();
	void Print();
};

#endif