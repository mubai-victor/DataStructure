#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"

#define k 5
#define N 3
#define M 3
#define MAX_SIZE 30
typedef int KeyType;
typedef int InfoType;
struct RedType {
	KeyType key;
	InfoType otherinfo;
};
struct SqList {
	int length;
	RedType r[MAX_SIZE];
};

typedef int LoserTree[k];
typedef RedType ExNode, External[k + 1];

void input(int i,RedType &a);
void output(int i);
void Adjust(LoserTree ls, int s);
void CreateLoserTree(LoserTree ls);
void K_Merge(LoserTree ls, External b);
void InsertSort(SqList &l);
void print(RedType);




#endif