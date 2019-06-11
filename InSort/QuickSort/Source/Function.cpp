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
int SqList::_Partition(int low, int high)
{
	int iPos = low;
	RedType key = r[low], swap;
	while (low < high) {
		while (low<high&&r[high].key >= key.key) {
			high--;
		}
		swap = r[high];
		r[high] = r[low];
		r[low] = swap;
		while (low<high&&r[low].key <= key.key) {
			low++;
		}
		swap = r[high];
		r[high] = r[low];
		r[low] = swap;
	}
	return low;
}
int SqList::_Partition_(int low, int high)
{
	int iPos = low;
	r[0] = r[low];
	while (low < high) {
		while (low < high&&r[high].key >= r[0].key) {
			high--;
		}
		r[low] = r[high];
		while (low < high&&r[low].key <= r[0].key) {
			low++;
		}
		r[high] = r[low];
	}
	r[low] = r[0];
	return low;
}
void SqList::_QSort(int low, int high)
{
	if (low < high) {
		int iPos = _Partition_(low, high);
		_QSort(low, iPos - 1);
		_QSort(iPos + 1, high);
	}
}
void SqList::QuickSort()
{
	_QSort(1, lenght);
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