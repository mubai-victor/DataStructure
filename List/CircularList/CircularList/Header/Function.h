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
struct LNode{
	Elemtype data;
	LNode*next;
};
typedef LNode*LinkList;

void InitList(LinkList&L);
void DestroyList(LinkList&L);
void ClearList(LinkList&L);
int ListLength(LinkList L);
Status ListEmpty(LinkList L);
Status GetElem(LinkList L, int i, Elemtype&elem);
int LocateElem(LinkList L, Elemtype elem, Status(*func)(Elemtype elem_a, Elemtype elem_b));
Status PriorElem(LinkList L, Elemtype elem_cur, Elemtype&elem_pri);
Status NextElem(LinkList L, Elemtype elem_cur, Elemtype&elem_next);
Status ListInsert(LinkList&L, int i, Elemtype elem);
Status ListDelete(LinkList&L, int i, Elemtype&elem);
void ListTraverse(LinkList&L, void(*func)(Elemtype elem));

#define LEN sizeof(LNode)
//Test function

Status equal(Elemtype a, Elemtype b);
int comp(ElemType a, ElemType b);
void print(ElemType c);
void print2(ElemType c);
void print1(ElemType &c);
Status sq(ElemType c1, ElemType c2);
void dbl(ElemType &c);




#ifdef LINERLIST_CHAIN

struct LNode{
	Elemtype data;
	LNode*next;
};
typedef LNode*LinkList;
typedef struct LNode LNode;

void InitList(LinkList&L);
void DestroyList(LinkList&L);
void ClearList(LinkList&L);
void ListTraverse(LinkList L,void(*func)(Elemtype elem));
void Union(LinkList La, LinkList Lb);
void MergeList(LinkList La, LinkList Lb, LinkList&Lc);
Status ListEmpty(LinkList L);
Status GetElem(LinkList L,int i,Elemtype &elem);
Status ListInsert(LinkList&L,int i,Elemtype elem);
Status ListDelete(LinkList&L,int i,Elemtype &elem);
Status PriorElem(LinkList L,Elemtype elem_cur,Elemtype&elem_prior);
Status NextElem(LinkList L,Elemtype elem_cur,Elemtype&elem_next);
int LocateElem(LinkList L,Elemtype elem,Status(*compare)(Elemtype a,Elemtype b));
int ListLength(LinkList L);

#endif


#endif