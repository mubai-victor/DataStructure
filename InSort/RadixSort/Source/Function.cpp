#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

SLinkListType::SLinkListType(SLinkListType &L)
{
	for (int i = 1; i <= length; i++) {
		r[i] = L.r[i];
	}
	length = L.length;
	addr = NULL;
}
SLinkListType::SLinkListType()
{
	length = 0;
	addr = NULL;
}
SLinkListType::~SLinkListType()
{
	delete[] addr;
	addr = NULL;
}
void SLinkListType::Assign(RedType D[], int n)
{
	int iMax = 0;
	char cSwap[MAX_NUM_OF_KEY];
	for (int i = 0; i < n; i++) {
		if (D[iMax].key < D[i].key) {
			iMax = i;
		}
	}
	keynum = (int)ceil(log10(D[iMax].key));
	int iLength = 0;
	for (int i = 1; i <= n; i++) {
		r[i].otheritems = D[i - 1].otheritems;
		for (int j = 0; j < MAX_NUM_OF_KEY; j++) {
			r[i].r[j] = '0';
		}
		_itoa_s(D[i - 1].key, cSwap, 10);
		iLength = strlen(cSwap);
		for (int k = 0; k < iLength; k++) {
			r[i].r[k] = cSwap[iLength - k - 1];
		}
	}
	length = n;
}
void SLinkListType::PrintPos()
{
	for (int i = 1; i <=length ; i ++) {
		cout << "key=";
		for (int j = keynum - 1; j >= 0; j--) {
			cout << r[i].r[j];
		}
		cout << ",otheritems=" << r[i].otheritems << ",next=" << r[i].next << endl;
	}
}
void SLinkListType::PrintLink()
{
	for (int i = r[0].next; i != 0; i = r[i].next) {
		for (int j = keynum - 1; j >= 0; j--) {
			cout << r[i].r[j];
		} 
		cout << ends;
	}
	cout << endl;
}
void SLinkListType::Distribute(int i)
{	
	int iPos = 0;
	for (int i = 0; i < RADIX; i++) {
		head[i] = 0;
	}
	for (int j = r[0].next; j != 0; j = r[j].next) {
		iPos = ord(r[j].r[i]);
		if (head[iPos] == 0) {
			head[iPos] = j;
		}
		else {
			r[tail[iPos]].next = j;			
		}
		tail[iPos] = j;
	}
}
void SLinkListType::Collect()
{
	int iPos = 0;
	for (; iPos < RADIX&&head[iPos] == 0; iPos++);
	r[0].next = head[iPos];
	for (int j = iPos + 1; j < RADIX; j++) {
		while (j < RADIX - 1&&head[j] == 0) {
			j++;
		}
		r[tail[iPos]].next = head[j];
		iPos = j;
	}
	if (head[iPos] != 0) {
		r[tail[iPos]].next = 0;
	}

}
void SLinkListType::RadixSort()
{
	for (int i = 0; i < length; i++) {
		r[i].next = i + 1;
	}
	r[length].next = 0;
	for (int i = 0; i < keynum; i++) {
		Distribute(i);
		Collect();
		cout << "After No." << i << " times collect:" << endl;
		PrintLink();
	}
}
void SLinkListType::Sort()
{
	int iPos = r[0].next;
	addr = new int[length + 1];
	for (int i = 1; i <= length; i++) {
		addr[i] = iPos;
		iPos = r[iPos].next;
	}
}
void SLinkListType::Rearrange()
{
	int iPos = 0, iTemp = 0;
	for (int i = 1; i <= length; i++) {
		iPos = i;
		r[0] = r[i];
		while (addr[iPos] != i) {
			r[iPos] = r[addr[iPos]];
			iTemp = addr[iPos];
			addr[iPos] = iPos;
			iPos = iTemp;
		}
		r[iPos] = r[0];
		addr[iPos] = iPos;
	}
}

int ord(char c)
{
	return c - '0';
}