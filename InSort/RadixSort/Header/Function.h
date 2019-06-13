#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"

#define N 10
#define T 3
#define SIZE 20
#define MAX_NUM_OF_KEY 8
#define RADIX 10
#define MAX_SPACE 100 

typedef char KeysType;
typedef int KeyType;
typedef int InfoType;
typedef int ArrType[RADIX];

//struct RedType {
//	KeyType key;
//	InfoType otherinfo;
//};
struct SLCell {
	KeysType r[MAX_NUM_OF_KEY];
	InfoType otheritems;
	int next;
};
struct RedType {
	KeyType key;
	InfoType otheritems;
};


class SLinkListType {
private:
	SLCell r[MAX_SPACE];
	ArrType head, tail;
	int keynum;
	int length;
	int *addr;
public:
	SLinkListType(SLinkListType &L);
	SLinkListType();
	~SLinkListType();
	void Distribute(int i);
	void Collect();
	void RadixSort();
	void Sort();
	void Rearrange();
	void Assign(RedType D[], int n);
	void PrintPos();
	void PrintLink();
};
int ord(char c);
#endif