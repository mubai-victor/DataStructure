#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"
#define MAX_SIZE 1000
#define ListClear ListDelete

typedef struct{
	int cur;
	Elemtype data;
}component, SLinkList[MAX_SIZE];

void difference(SLinkList L, int&head);
void InitSpace(SLinkList L);
int Malloc(SLinkList L);
void Free(SLinkList L, int k);
int InitList(SLinkList L);
void ClearList(SLinkList L,int n);
Status ListEmpty(SLinkList L,int n);
int ListLength(SLinkList L,int n);
Status GetElem(SLinkList L,int n, int i, Elemtype&elem);
int LocateElem(SLinkList L,int n, Elemtype elem);
Status PriorElem(SLinkList L,int n, Elemtype elem_cur,Elemtype&elem_pre);
Status NextElem(SLinkList L, int n, Elemtype elem_cur, Elemtype&elem_next);
Status ListInsert(SLinkList&L, int n, int i, Elemtype elem);
Status ListDelete(SLinkList L, int n, int i, Elemtype&elem);
void ListTraverse(SLinkList L, int n, void(*func)(Elemtype elem));


Status equal(Elemtype a, Elemtype b);
int comp(ElemType a, ElemType b);
void print(ElemType c);
void print2(ElemType c);
void print1(ElemType &c);
Status sq(ElemType c1, ElemType c2);
void dbl(ElemType &c);



#endif