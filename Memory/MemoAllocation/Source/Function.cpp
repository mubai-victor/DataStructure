#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

inline WORD*FootLoc(WORD*p)
{
	return p + p->size - 1;
}

cAlloc::cAlloc()
{
	root = pav = NULL;
}
cAlloc::~cAlloc()
{
	delete[] root;
	root = pav = NULL;
}
void cAlloc::Init()
{
	root = pav = new WORD[MAX + 2];
	pav->tag = USED;
	pav = pav + 1;
	pav->llink = pav;
	pav->rlink = pav;
	pav->size = MAX;
	pav->tag = FREE;
	FootLoc(pav)->tag = FREE;
	FootLoc(pav)->uplink = pav;
	(pav->tag) = USED;
	(pav + pav->size)->tag = USED;
}
Space cAlloc::AllocBoundTag(int n)
{
	Space p = NULL;
	for (p = pav; p != NULL&&p->size < n&&p->rlink != pav; p = p->rlink);
	if (p == NULL || p->size < n) {
		return NULL;
	}
	pav = p->rlink;
	if (p->size - n <= MIN) {
		if (pav == p) {
			pav = NULL;
		}
		else {
			p->rlink->llink = p->llink;
			p->llink->rlink = p->rlink;
		}
		p->tag = USED;
		FootLoc(p)->tag = USED;
	}
	else {
		(p + p->size)->tag;
		p->size -= n;
		FootLoc(p)->tag = FREE;
		FootLoc(p)->uplink = p;
		p = FootLoc(p) + 1;
		p->size = n;
		p->tag = USED;
		FootLoc(p)->tag = USED;
	}
	return p;
}
void cAlloc::Reclaim(Space&p)
{
	Tag StaLeft = (p - 1)->tag, StaRight = (p + p->size)->tag;
	Space pSpace = NULL, pSpaceR = NULL;
	if (pav == NULL) {
		pav = p;
		p->llink = p->rlink = p;
		p->tag = FREE;
		FootLoc(p)->uplink = p;
		FootLoc(p)->tag = FREE;
	}
	else if (StaLeft == USED&&StaRight == USED) {
		p->tag = FREE;
		FootLoc(p)->tag = FREE;
		FootLoc(p)->uplink = p;
		p->rlink = pav;
		p->llink = pav->llink;
		pav->llink->rlink = p;
		pav->llink = p;
	}
	else if (StaLeft == FREE&&StaRight == USED) {
		pSpace = (p - 1)->uplink;
		pSpace->size += p->size;
		FootLoc(pSpace)->tag = FREE;
		FootLoc(pSpace)->uplink = pSpace;
	}
	else if (StaLeft == USED&&StaRight == FREE) {
		pSpace = p + p->size;
		p->tag = FREE;
		p->size += pSpace->size;
		p->llink = pSpace->llink;
		p->rlink = pSpace->rlink;
		pSpace->rlink->llink = p;
		pSpace->llink->rlink = p;
		FootLoc(pSpace)->uplink = p;
		if (pav == pSpace) {
			pav = p;
		}
	}
	else if (StaLeft == FREE&&StaRight == FREE) {
		pSpaceR = p + p->size;
		pSpace = (p - 1)->uplink;
		pSpace->size += p->size + pSpaceR->size;
		FootLoc(pSpace)->uplink = pSpace;
		pSpaceR->llink->rlink = pSpace;
		pSpaceR->rlink->llink = pSpace;
		if (pav == pSpaceR) {
			pav = pSpace;
		}
	}
	p = NULL;
}
void cAlloc::Print()
{
	Space pFoot = NULL, pHead = NULL;
	if (pav != NULL) {
		pHead = pav;
		pFoot = FootLoc(pHead);
		do {
			cout << "Start address:" << dec << pHead << " Size:" << pHead->size << "(*sizeof(WORD)) " << "Address of next bulk:" << dec << pFoot + 1 << endl;
			pHead = pHead->rlink;
			pFoot = FootLoc(pHead);
		} while (pHead != pav);
	}
}
void cAlloc::PrintUser(Space sign[])
{
	for (int i = 0; i < MAX / MIN; i++) {
		if (sign[i] != NULL) {
			cout << "Start address:" << dec << sign[i] << " Size:" << sign[i]->size << "(*sizeof(WORD)) " << "sign in the tail:" << FootLoc(sign[i])->tag << endl;
		}
	}
}