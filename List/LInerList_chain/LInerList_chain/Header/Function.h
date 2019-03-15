#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"
#define LISTINCREMENT 5
#define LISTLENGTH 10

#define LINERLIST_CHAIN

#ifdef LINERLIST_ORDER
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
void Union(SqList&a,SqList&b);
void MergeList(SqList a, SqList b,SqList&c);
#endif
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