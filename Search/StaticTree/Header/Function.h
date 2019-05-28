#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"

#define N 9

typedef char KeyType;

struct ElemType{
	KeyType key;
	int weight;
};

struct BiTree {
	BiTree *lchild,*rchild;
	ElemType data;
	BiTree();
};

class SOSTree {
private:
	BiTree *root;
	int sw[N + 1];
	Status _SecondOptimal(BiTree *&T, ElemType R[], int low, int high);
	void _Traverse(BiTree *elem, void(*Func)(ElemType elem));
public:
	SOSTree();
	Status SecondOptimal(ElemType R[]);
	void FindSW(ElemType R[]);
	void CreateSOSTree(ElemType R[]);
	void Traverse(void(*Func)(ElemType elem));
	Status Search_SOSTree(KeyType key);
};
void print(ElemType elem);
#endif