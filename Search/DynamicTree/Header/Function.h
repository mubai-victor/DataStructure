#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"

#define N 10

typedef int KeyType;
struct ElemType {
	KeyType key;
	int others;
};

typedef struct Tree {
	ElemType data;
	Tree *lchild, *rchild;
	Tree();
}*BiTree;

class BSTree {
private:
	BiTree root;
	BiTree _SearchBST(BiTree T,KeyType key);
	Status _SearchBST(BiTree T,KeyType key, BiTree f, BiTree &b);
	Status _DeleteBST(BiTree &T,KeyType key);
	void _TraverseBSTree(BiTree p, void(*Func)(ElemType elem));
	void _DestroyBSTree(BiTree p);
public:
	BSTree();
	~BSTree();
	BiTree SearchBST(KeyType key);
	Status SearchBST(KeyType key, BiTree f, BiTree &b);
	Status InsertBST(ElemType elem);
	void TraverseBSTree(void(*Func)(ElemType elem));
	void Delete(BiTree &p);
	Status DeleteBST(KeyType key);
};

void print(ElemType elem);
#endif