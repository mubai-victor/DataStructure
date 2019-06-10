#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

SqList::SqList(SqList &S)
{
	for (int i = 1; i <= S.lenght; i++) {
		r[i] = S.r[i];
	}
	lenght = S.lenght;
}
SqList::SqList()
{
	lenght = 0;
}
void SqList::InsertSort()
{
	for (int i = 2; i <= lenght; i++) {
		r[0] = r[i];
		int j = i - 1;
		for (; r[j].key > r[0].key; j--) {
			r[j + 1] = r[j];
		}
		j++;
		r[j] = r[0];
	}
}
void SqList::BInsertSort()
{
	for (int i = 2; i <= lenght; i++) {
		int low = 1, high = i, mid = 0;;
		r[0] = r[i];
		while (low <= high) {
			mid = (low + high) / 2;
			if (r[mid].key < r[0].key) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		for (int k = i - 1; k >= low; k--) {
			r[k + 1] = r[k];
		}
		r[low] = r[0];
	}
}
void SqList::P2InsertSort()
{
	RedType *ptemp = new RedType[lenght];
	int ihead = 0, itail = 0;
	ptemp[0] = r[1];
	for (int i = 2; i <= lenght; i++) {
		r[0] = r[i];
		if (r[i].key < ptemp[ihead].key) {
			ihead = (ihead + lenght - 1) % lenght;
			ptemp[ihead] = r[i];
		}
		else if (r[i].key > ptemp[itail].key) {
			itail++;
			ptemp[itail] = r[i];
		}
		else {	
			int j = itail++;
			for (; ptemp[j].key > r[i].key;j = (j + lenght - 1) % lenght) {
				ptemp[(j + 1)%lenght] = ptemp[j];
			}
			j=(j + 1) % lenght; 
			ptemp[j] = r[i];
		}
	}
	for (int i = ihead, j = 1; j <= lenght;i = (i + 1) % lenght, j++) {
		r[j] = ptemp[i];
	}
}
void SqList::Assign(RedType *p)
{
	for (int i = 0; i<N; i++) 
		r[i + 1] = p[i];
	lenght = N;
}


void SqList::Print()
{
	for (int i = 1; i <= lenght; i++) {
		cout << "(" << r[i].key << "," << r[i].otherinfo << ")";
	}
	cout << endl;
}