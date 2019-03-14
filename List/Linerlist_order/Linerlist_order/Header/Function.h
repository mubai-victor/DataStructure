#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"
#define LISTINCREMENT 5
#define LISTLENGTH 10
struct SqList{
	Elemtype*elembase;
	int length;
	int listsize;
};
Status InitList(SqList&List);

Status ListEmpty(SqList&list);
int ListLength(SqList&list);
Status GetElem(SqList&list,int i,Elemtype &elem);
int LocateElem(SqList&list,Elemtype e,Status(*compare)(Elemtype elem1,Elemtype elem2));
Status PriorElem(SqList&list,Elemtype cur_e,Elemtype&pre_e);
Status NextElem(SqList&list, Elemtype cur_e, Elemtype&next_e);
Status ListInsert(SqList&list, int i, Elemtype elem);
Status ListDelete(SqList&list,int i,Elemtype&elem);
void ListTraverse(SqList&list, void(*visit)(Elemtype&elem));
void DestroyList(SqList&list);
void ClearList(SqList&list);

//Test function

Status equal(Elemtype a, Elemtype b);
int comp(ElemType a, ElemType b);
void print(ElemType c);
void print2(ElemType c);
void print1(ElemType &c);
Status sq(ElemType c1, ElemType c2);
void dbl(ElemType &c);
void Union(SqList&a,SqList&b);
void MergeList(SqList a, SqList b,SqList&c);
#endif