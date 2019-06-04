#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"

#define MAX_KEY_LEN 16
#define N 16
#define LENGTH 27

struct Others {
	int ord;
};
struct KeysType {
	char ch[MAX_KEY_LEN];
	int num;
};
struct Record {
	KeysType key;
	Others others;
};
enum NodeKind { LEAF, BRANCH };
typedef struct TrieNode {
	NodeKind kind;
	union {
		struct {
			KeysType K;
			Record *infoptr;
		}lf;
		struct {
			TrieNode *ptr[LENGTH];
		}bh;
	};
}TrieNode,*TrieTree;
class TrieTrees {
private:
	TrieTree root;
	void _DestroyTrieTree(TrieTree &ptr);
	void _TraverseTrieTree(TrieTree ptr, void(*Func)(Record*rec));
public:
	TrieTrees();
	void DestroyTrieTree();
	Record*SearchTrieTree(KeysType key);
	void InsertTrieTree(Record*rec);
	void TraverseTrieTree(void(*Func)(Record*rec));	
};

int ord(char cha);
void print(Record *r);

#endif