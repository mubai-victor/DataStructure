#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"

#define N 10
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
	int length;
public:
	SLinkListType(SLinkListType &L);
	SLinkListType();
	void ShellSort();
	void Assign(RedType D[], int n);
	void ShellInsert(int pos);
	void BubbleSort();
	void Print();
};

#endif