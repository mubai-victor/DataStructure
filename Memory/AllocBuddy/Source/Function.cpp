#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

cAlloc::cAlloc()
{
	root = NULL;
}
cAlloc::~cAlloc()
{
	delete[] root;
	root = NULL;
}
void cAlloc::Init()
{
	for (int i = 0; i <= SIZE; i++) {
		a[i].first = NULL;
		a[i].nodesize = pow(2, i);
	}
	root = a[SIZE].first = new WORD_b[int(pow(2, SIZE))];
	a[SIZE].first->kval = SIZE;
	a[SIZE].first->llink = a[SIZE].first;
	a[SIZE].first->rlink = a[SIZE].first;
	a[SIZE].first->tag = FREE;
}
Space cAlloc::AllocBuddy(int n)
{
	Space p = NULL, pFree = NULL;
	int i = 0, k = 0;
	for (i = 0; i <= SIZE && (a[i].nodesize < n + 1 || a[i].first == NULL); i++); 
	if (i > SIZE) {
		return NULL;
	}
	p = a[i].first;
	if (p->llink == p->rlink) {
		a[i].first = NULL;
	}
	else {
		a[i].first = p->llink;
		p->llink->rlink = p->rlink;
		p->rlink->llink = p->llink;		
	}
	for (k = 1; a[i - k].nodesize >= n + 1; k++) {
		pFree = p + int(pow(2, i - k));
		pFree->kval = i - k;
		pFree->llink = pFree;
		pFree->rlink = pFree;
		pFree->tag = FREE;
		a[i - k].first = pFree;
	}
	p->kval = i - k + 1;
	p->tag = USED;
	return p;
}
Space cAlloc::Buddy(Space p)
{
	if ((p - root) % (int(pow(2, p->kval + 1))) == 0) {
		return p + int(pow(2, p->kval));
	}
	else {
		return p - int(pow(2, p->kval));
	}
}
void cAlloc::Reclaim(Space &p)
{
	Space sBuddy = Buddy(p);
	while (p >= root&&p <= root + int(pow(2, SIZE)) && sBuddy->kval == p->kval&&sBuddy->tag == FREE) {
		if (sBuddy->rlink == sBuddy) {
			a[sBuddy->kval].first = NULL;
		}
		else {
			sBuddy->llink->rlink = sBuddy->rlink;
			sBuddy->rlink->llink = sBuddy->llink;
			if (a[sBuddy->kval].first == sBuddy) {
				a[sBuddy->kval].first = sBuddy->llink;
			}
		}
		if (sBuddy > p) {
			p->kval++;
		}
		else {
			sBuddy->kval++;
			p = sBuddy;
		}
		sBuddy = Buddy(p);
	}
	if (a[p->kval].first == NULL) {
		a[p->kval].first = p;
		p->llink = p;
		p->rlink = p;
	}
	else {
		p->rlink = a[p->kval].first;
		p->llink = a[p->kval].first->llink;
		p->llink->rlink = p;
		p->rlink->llink = p;
		a[p->kval].first = p;		
	}
	p->tag = FREE;
	p = NULL;
}
void cAlloc::Print()
{
	Space pTemp = NULL;
	for (int i = 0; i <= SIZE; i++) {
		pTemp = a[i].first;
		if (pTemp != NULL) {
			do {
				cout << "Size of block:" << a[i].nodesize << " Start address:" << pTemp << " State:" << ((pTemp->tag == FREE) ? "FREE" : "USED") << endl;
				pTemp = pTemp->rlink;
			} while (pTemp != a[i].first);
		}
	}
}
void cAlloc::PrintUser(Space p[])
{
	for (int i = 0; i <= SIZE; i++) {
		if (p[i] != NULL) {
			cout << "Size of blocks:" << a[p[i]->kval].nodesize << " Start address:" << p[i] << " State:" << ((p[i]->tag == FREE) ? "FREE" : "USED") << endl;
		}
	}
}