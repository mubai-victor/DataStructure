#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"
#define LISTINCREMENT 5
#define LISTLENGTH 10

struct DuLNode{
	Elemtype data;
	DuLNode*next,*prior;
};
typedef DuLNode*DuLinkList;

void InitList(DuLinkList&L);
void DestroyList(DuLinkList&L);
void ClearList(DuLinkList&L);
int ListLength(DuLinkList L);
Status ListEmpty(DuLinkList L);
Status GetElem(DuLinkList L, int i, Elemtype&elem);
int LocateElem(DuLinkList L, Elemtype elem, Status(*func)(Elemtype elem_a, Elemtype elem_b));
Status PriorElem(DuLinkList L, Elemtype elem_cur, Elemtype&elem_pri);
Status NextElem(DuLinkList L, Elemtype elem_cur, Elemtype&elem_next);
Status ListInsert(DuLinkList&L, int i, Elemtype elem);
Status ListDelete(DuLinkList&L, int i, Elemtype&elem);
void ListTraverse(DuLinkList&L, void(*func)(Elemtype elem));
void ListTraverseBack(DuLinkList&L, void(*func)(Elemtype elem));

#define LEN sizeof(DuLNode)
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