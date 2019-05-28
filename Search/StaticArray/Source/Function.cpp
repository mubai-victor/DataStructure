#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

SStable::SStable()
{
	elem = NULL;
	length = 0;
}
void SStable::Create_Seq(ElemType table[], int n)
{
	elem = new ElemType[n+1];
	for (int i = 1; i <= n; i++) {
		elem[i] = table[i - 1];

	}
	length = n;
}
void SStable::Ascend()
{
	ElemType Min, Swap;
	int iPos = 0;
	for (int i = 1; i <= length; i++) {
		Min = elem[i];
		iPos = i;
		for (int j = i + 1; j < length; i++) {
			if (elem[j].key <= Min.key) {
				Min = elem[j];
				iPos = j;
			}
			elem[iPos] = elem[i];
			elem[i] = Min;			
		}
	}
}
void SStable::Create_Ord(ElemType table[], int n)
{
	Create_Seq(table, n);
	Ascend();
}
int SStable::Search_Seq(KeyType key)
{
	int i = length;
	elem[0].key = key;
	for (; elem[i].key != key; i--);
	return i;
}
int SStable::Search_Bin(KeyType key)
{
	int iLow = 1, iHigh = length, iMid = 0;;
	while (iLow <= iHigh) {
		iMid = (iLow + iHigh) / 2;
		if (elem[iMid].key == key) {
			return iMid;
		}
		else if (elem[iMid].key < key) {
			iLow = iMid - 1;
		}
		else {
			iHigh = iMid + 1;
		}
	}
	return 0;
}
void SStable::Traverse(void(*Func)(ElemType elem))
{
	cout << "No  name  politics  Chinese  English  math  physics  chemistry  biology  total" << endl;
	for (int i = 1; i <= length; i++) {
		Func(elem[i]);
	}
}
void SStable::Print(int i, void(*Func)(ElemType elem))
{
	print(elem[i]);
}
void print(ElemType elem)
{
	cout << elem.number << " " << elem.name << " " << elem.politics << " " << elem.Chinese << " " << elem.English << " " << elem.math << " " << elem.physics << " " << elem.chemistry << " " << elem.biology << " " << elem.total << endl;
}
