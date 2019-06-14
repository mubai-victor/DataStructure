#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;


void print(RedType t)
{
	printf("(%d,%d)", t.key, t.otherinfo);
}
void Select_MiniMax(LoserTree ls, WorkArea wa, int q)
{
	int iPos = (w + q) / 2;
	int iSwap = 0;
	while (iPos != 0) {
		if (wa[ls[iPos]].num < wa[q].num || (wa[ls[iPos]].num == wa[q].num&&wa[ls[iPos]].key < wa[q].key)) {
			iSwap = q;
			q = ls[iPos];
			ls[iPos] = iSwap;
		}
		iPos = iPos / 2;
	}
	ls[0] = q;
}
void Construct_Loser(LoserTree ls, WorkArea wa, FILE *fi)
{
	for (int i = 0; i < w; i++) {
		ls[i] = wa[i].key = wa[i].num = 0;
	}
	for (int i = w - 1; i >= 0; i--) {
		fread(&wa[i].rec, sizeof(RedType), 1, fi);
		wa[i].key = wa[i].rec.key;
		wa[i].num = 1;
		Select_MiniMax(ls, wa, i);
	}
}
void get_run(LoserTree ls, WorkArea wa, int rc, int &rmax, FILE *fi, FILE *fo)
{
	int iMiniMax = 0;
	while (rc == wa[ls[0]].num) {
		fwrite(&wa[ls[0]].rec, sizeof(RedType), 1, fo);
		iMiniMax = wa[ls[0]].key;
		fread(&wa[ls[0]].rec, sizeof(RedType), 1, fi);		
		if (feof(fi)) {
			wa[ls[0]].key = INT_MAX;
			wa[ls[0]].num = rmax + 1;
		}
		else {
			wa[ls[0]].key = wa[ls[0]].rec.key;
			if (wa[ls[0]].key < iMiniMax) {
				rmax = rc + 1;;
				wa[ls[0]].num = rmax;
			}
			else {
				wa[ls[0]].num = rc;
			}
		}
		Select_MiniMax(ls, wa, ls[0]);
	}
}
void Replace_Selection(LoserTree ls, WorkArea wa, FILE *fi, FILE *fo)
{
	int rc = 1,rmax = 1;
	RedType rEnd;
	rEnd.key = INT_MAX;	
	Construct_Loser(ls, wa, fi);
	while (rc <= rmax) {
		get_run(ls, wa, rc, rmax, fi, fo);
		rEnd.otherinfo = rc;
		fwrite(&rEnd, sizeof(RedType), 1, fo);
		rc = wa[ls[0]].num;
	}

}