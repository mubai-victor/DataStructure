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
void SqList::Assign(RedType *p)
{
	for (int i = 0; i<N; i++) 
		r[i + 1] = p[i];
	lenght = N;
}
void SqList::_Merge(RedType TR[], RedType SR[], int start, int mid, int end)
{
	int i=0, j=0, k=0;
	for (i = start, j = mid + 1, k = start; i <= mid&&j <= end;k++) {
		if (SR[i].key < SR[j].key) {
			TR[k] = SR[i];
			i++;
		}
		else {
			TR[k] = SR[j];
			j++;
		}
	}
	while (i <= mid) {
		TR[k++] = SR[i++];
	}
	while (j <= end) {
		TR[k++] = SR[j++];
	}
}
void SqList::_MSort(RedType TR[],RedType SR[], int start, int end)
{
	if (start == end) {
		SR[start] = TR[start];
	}
	else{
		int mid = (start + end) / 2;
		RedType p[MAX_SIZE];
		_MSort(TR, p, start, mid);
		_MSort(TR, p, mid + 1, end);
		_Merge(SR, p, start, mid, end);
	}
}
void SqList::MergeSort()
{
	_MSort(r, r, 1, lenght);
}
void SqList::Print()
{
	for (int i = 1; i <= lenght; i++) {
		cout << "(" << r[i].key << "," << r[i].otherinfo << ")";
	}
	cout << endl;
}