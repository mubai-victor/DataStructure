#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"

#define MAX 1000
#define MIN 10
enum Tag {
	USED,FREE
};

typedef struct WORD{
	union {
		WORD*llink;
		WORD*uplink;
	};
	Tag tag;
	int size;
	WORD*rlink;
} WORD,head,foot,*Space;

inline WORD*FootLoc(WORD*p);

class cAlloc {
private:
	Space root;
	Space pav;
public:
	cAlloc();
	~cAlloc();
	void Init();
	Space AllocBoundTag(int n);
	void Reclaim(Space&p);
	void Print();
	void PrintUser(Space sign[]);
};
#endif