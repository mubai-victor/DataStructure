#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;
int dt[T] = { 5,3,1 };

SLinkListType::SLinkListType(SLinkListType &L)
{
	for (int i = 1; i <= length; i++) {
		r[i] = L.r[i];
	}
	length = L.length;
	p = NULL;
}
SLinkListType::SLinkListType()
{
	length = 0;
	p = NULL;
}
SLinkListType::~SLinkListType()
{
	delete[] p;
	p = NULL;
}
void SLinkListType::Assign(RedType D[], int n)
{
	for (int i = 0; i < n; i++) {
		r[i + 1] = D[i];
	}
	length = n;
}
void SLinkListType::Print()
{
	for (int i = 1; i <= length; i++) {
		cout << "(" << r[i].key << "," << r[i].otherinfo << ")" << ends;
	}
	cout << endl;
}
int SLinkListType::SelectMinKey(int i)
{
	int iMin = i;
	for (int j = i + 1; j <= length; j++) {
		if (r[iMin].key > r[j].key) {
			iMin = j;
		}
	}
	return iMin;
}
void SLinkListType::SelectSort()
{
	int iMin = 0;
	for (int i = 1; i < length; i++) {
		iMin = SelectMinKey(i + 1);
		r[0] = r[i];
		if (r[i].key > r[iMin].key) {
			r[i] = r[iMin];
			r[iMin] = r[0];
		}
	}
}
void SLinkListType::TreeSort()
{
	int iDepth = (int)ceil(log(length) / log(2)) + 1;
	int iLengthL = (int)pow(2, iDepth) - 1, iLengthS = (int)pow(2, iDepth - 1) - 1;
	p = new RedType[iLengthL];
	for (int i = 1; i <= length; i++) {
		p[iLengthS + i - 1] = r[i];
	}
	for (int i = iLengthS + length; i < iLengthL; i++) {
		p[i].key = INT_MAX;
	}
	for (int j = iLengthL - 1; j > 0; j-=2) {
		if (p[j].key < p[j - 1].key) {
			p[j / 2 - 1] = p[j];
		}
		else {
			p[j / 2 - 1] = p[j - 1];
		}
	}
	for (int i = 1; i <= length; i++) {
		int iPos = 0;
		r[i] = p[0];
		for (int j = 1; j < iDepth; j++) {
			if (p[2 * iPos + 1].key < p[2 * iPos + 2].key) {
				iPos = 2 * iPos + 1;
			}
			else {
				iPos = 2 * iPos + 2;
			}
		}
		p[iPos].key = INT_MAX;
		for (int k = (iPos + 1) / 2 - 1; k >= 0; k = (k + 1) / 2 - 1) {
			if (p[(k + 1) * 2].key > p[(k + 1) * 2 - 1].key) {
				p[k] = p[(k + 1) * 2 - 1];
			}
			else {
				p[k] = p[(k + 1) * 2];
			}
		}
	}
}
void SLinkListType::HeapAdjust(int start, int end)
{
	int iMax = 0;
	RedType rHead = r[start];
	int iPos = start;
	while (2 * iPos <= end) {
		if ((iPos * 2 + 1 <= end)&&(r[iPos * 2].key < r[iPos * 2 + 1].key)) {
			iMax = iPos * 2 + 1;
		}
		else {
			iMax = iPos * 2;
		}
		if (rHead.key < r[iMax].key) {
			r[iPos] = r[iMax];
			iPos = iMax;
		}
		else {
			break;
		}
	}
	r[iPos] = rHead;
}
void SLinkListType::HeapSort()
{
	RedType rSwap;
	for (int i = length / 2; i > 0; i--) {
		HeapAdjust(i, length);
	}
	for (int i = length; i > 0; i--) {
		rSwap = r[i];
		r[i] = r[1];
		r[1] = rSwap;
		HeapAdjust(1, i - 1);
	}
}