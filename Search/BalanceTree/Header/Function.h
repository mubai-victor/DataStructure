#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"

#define N 5

enum BS { LH = -1, EH = 0, RH = 1 };

typedef int KeyType;
struct ElemType {
	KeyType key;
	int others;
};

typedef struct Tree {
	ElemType data;
	BS bf;
	Tree *lchild, *rchild;
	Tree();
}*BiTree;

class BalanceTree {
private:
	BiTree root;
	void _R_Rotate(BiTree &T);
	void _L_Rotate(BiTree &T);
	void _LeftBalance(BiTree &T);
	void _RightBalance(BiTree &T);
	void _DestroyBST(BiTree &T);
	void _Traverse(BiTree &T, void(*Func)(ElemType elem));
	Status _InsertAVL(BiTree &T, ElemType elem, Status &taller);
	BiTree _SearchBST(BiTree &T, KeyType key);
public:
	BalanceTree();
	~BalanceTree();
	Status InsertAVL(ElemType elem);
	void TraverseBST(void(*Func)(ElemType elem));
	BiTree SearchBST(KeyType key);
};

void print(ElemType elem);
#endif