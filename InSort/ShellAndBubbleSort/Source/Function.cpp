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
}
SLinkListType::SLinkListType()
{
	length = 0;
}
void SLinkListType::Assign(RedType D[], int n)
{
	for (int i = 0; i < n; i++) {
		r[i + 1] = D[i];
	}
	length = n;
}
void SLinkListType::ShellInsert(int pos)
{
	int iPos = 0;
	for (int i = dt[pos] + 1; i <= length; i++) {
		if (r[i].key < r[i - dt[pos]].key) {
			r[0] = r[i];
			for (iPos = i - dt[pos]; iPos > 0&&r[0].key < r[iPos].key; iPos-=dt[pos]) {
				r[iPos + dt[pos]] = r[iPos];
			}
			r[iPos + dt[pos]] = r[0];
		}
	}
}
void SLinkListType::ShellSort()
{
	for (int i = 0; i < T; i++) {
		ShellInsert(i);
		cout << "No." << i << "times sort finished.Result:" << endl;
		Print();
	}
}
void SLinkListType::BubbleSort()
{
	Status sChanged = TRUE;
	RedType rSwap;
	for (int i = 1; i <= length&&sChanged == TRUE; i++) {
		sChanged = FALSE;
		for (int j = i + 1; j <= length; j++) {			
			if (r[i].key > r[j].key) {
				rSwap = r[i];
				r[i] = r[j];
				r[j] = rSwap;
				sChanged = TRUE;
			}
		}
	}
}
void SLinkListType::Print()
{
	for (int i = 1; i <= length; i++) {
		cout << "(" << r[i].key << "," << r[i].otherinfo << ")" << ends;
	}
	cout << endl;
}