#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"

#define MAX 100
#define MIN 10

#define SIZE 10
enum Tag {
	USED,FREE
};
typedef struct WORD_b {
	WORD_b *llink;
	WORD_b *rlink;
	Tag tag;
	int kval;

}WORD_b, head, *Space;
typedef struct HeadNode {
	int nodesize;
	WORD_b *first;
}FreeList[SIZE+1];
class cAlloc {
private:
	FreeList a;
	Space root;
public:	
	cAlloc();
	~cAlloc();
	void Init();
	Space AllocBuddy(int n);
	Space Buddy(Space p);
	void Reclaim(Space &p);
	void Print();
	void PrintUser(Space p[]);
};
#endif