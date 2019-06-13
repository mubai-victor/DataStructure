#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;

External b;
FILE *fp[k + 1];

void InsertSort(SqList &l)
{
	for (int i = 2; i <= l.length; i++) {
		l.r[0] = l.r[i];
		int j = i - 1;
		for (; l.r[j].key > l.r[0].key; j--) {
			l.r[j + 1] = l.r[j];
		}
		j++;
		l.r[j] = l.r[0];
	}
}
void print(RedType t)
{
	printf("(%d,%d)", t.key, t.otherinfo);
}
void input(int i, RedType &a)
{
	fread(&a, sizeof(RedType), 1, fp[i]);
}
void output(int i)
{
	fwrite(&b[i], sizeof(RedType), 1, fp[k]);
}
void Adjust(LoserTree ls, int s)
{
	int iPos = (k + s) / 2;
	int iWinner = s;
	int iSwap = 0;
	while (iPos != 0) 		{
		if (b[ls[iPos]].key < b[iWinner].key) {
			iSwap = iWinner;
			iWinner = ls[iPos];
			ls[iPos] = iSwap;
		}
		iPos = iPos / 2;
	}
	ls[0] = iWinner;
}
void CreateLoserTree(LoserTree ls)
{
	b[k].key = INT_MIN;
	for (int i = 0; i < k; i++) {
		ls[i] = k;
	}
	for (int i = k - 1; i >= 0; i--) {
		Adjust(ls, i);
	}
}
void K_Merge(LoserTree ls, External b)
{
	for (int i = 0; i < k; i++) {
		input(i, b[i]);
	}
	CreateLoserTree(ls);
	while (b[ls[0]].key != INT_MAX) {
		output(ls[0]);
		input(ls[0], b[ls[0]]);
		Adjust(ls, ls[0]);
	}
	output(ls[0]);
}