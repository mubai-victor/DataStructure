#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

SLinkListType::SLinkListType(SLinkListType &L)
{
	for (int i = 1; i <= length; i++) {
		r[i] = L.r[i];
		addr[i] = L.addr[i];
	}
	length = L.length;
}
SLinkListType::SLinkListType()
{
	length = 0;
}
void SLinkListType::TableInsert(RedType D[], int n)
{
	int iFront, iBack;
	r[0].rc.key = INT_MAX;
	r[0].next = 0;
	for (int i = 0; i < n; i++) {
		r[i + 1].rc = D[i];
		iFront = 0;
		iBack = r[0].next;
		while (r[i + 1].rc.key >= r[iBack].rc.key) {
			iFront = iBack;
			iBack = r[iBack].next;
		}
		r[iFront].next = i + 1;
		r[i + 1].next = iBack;
	}
	length = n;
}
void SLinkListType::Arrange()
{
	int iUnsort = r[0].next, iPresent = 0;
	SLNode sNode;
	for (int i = 1; i < length; i++) {
		while (iPresent < i) {
			iPresent = r[iPresent].next;
		}
		iUnsort = r[iPresent].next;
		if (iPresent != i) {
			sNode = r[i];
			r[i] = r[iPresent];
			r[iPresent] = sNode;
			r[i].next = iPresent;
		}
		iPresent = iUnsort;
	}
}
void SLinkListType::Sort()
{
	int iPos = r[0].next;
	for (int i = 1; i <= length; i++) {
		addr[i] = iPos;
		iPos = r[iPos].next;
	}
}
void SLinkListType::Rearrange()
{
	int iPos = 0, iLoop = 0;
	//for (int i = 1; i < length; i++) {
	r[0] = r[1];
	iLoop = 1;
	while (addr[iLoop] != 1) {
		iPos = addr[iLoop];
		r[iLoop] = r[iPos];
		addr[iLoop] = iLoop;
		iLoop = iPos;
	}
	r[iPos] = r[0];
	addr[iPos] = iPos;
	//}
}
void SLinkListType::Print()
{
	for (int i = 1; i <= length; i++) {
		cout << "key=" << r[i].rc.key << ",information=" << r[i].rc.otherinfo << ",next=" << r[i].next << endl;
	}
	cout << endl;
}