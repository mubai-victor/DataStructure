#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"

#define N 16
#define m 3
#define MAX 5

typedef char Others[MAX];
typedef int KeyType;
struct Record {
	KeyType key;
	Others others;
};
typedef struct BTNode {
	int keynum;
	BTNode *parent;
	struct Node {
		KeyType key;
		BTNode *ptr;
		Record *recptr;
	}node[m + 1];
	BTNode();
}*BTree;
struct Result {
	BTNode*pt;
	int i;
	int tag;
};

class DSTree {
private:
	BTree root;
	void _DestroyDSTree(BTree &T);
	int _Search(BTree T, KeyType key);
	void _Insert(BTree &T, int i, Record *r, BTree ap);
	void _Split(BTree &q, BTree &ap);
	void _NewRoot(BTree &T, Record *r, BTree ap);
	void _TraverseDTree(BTree &T, void(*Func)(BTNode elem, int i));
public:
	DSTree();
	~DSTree();
	void InsertDSTree(Record *r, BTree q, int i);
	void TraverseDSTree(void (*Func)(BTNode elem,int i));
	Result SearchDSTree(KeyType key);
};

void print(BTNode elem, int i);
#endif