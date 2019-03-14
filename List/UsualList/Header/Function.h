#ifndef _FUNCTION_
#define _FUNCTION_
#include "Test.h"
#define LISTINCREMENT 5
#define LISTLENGTH 10
typedef struct{
	float coef;
	int expn;
}Elemtype;
typedef LinkList polynomial;

typedef struct LNode{
	LNode*next;
	Elemtype data;
}*Link,*Position;
struct LinkList{
	Link head, tail;
	int length;
};
typedef Elemtype ElemType;

void MakeNode(Link&p, Elemtype elem);
void FreeNode(Link&p);
void InitList(LinkList&L);
void ClearList(LinkList&L);
void DestroyList(LinkList&L);
void InsFirst(LinkList&L, Link head, Link addnode);
Status DelFirst(LinkList&L, Link head, Link&delnode);
void Append(LinkList&L, Link s);
Position PriorPos(LinkList L, Link s);
Status Remove(LinkList&L, Link&p);
void InsBefore(LinkList&L, Link&p, Link s);
void InsAfter(LinkList&L, Link&p, Link s);
void SetCurElem(Link p, Elemtype s);
Elemtype GetCurElem(Link p);
Status ListEmpty(LinkList L);
int ListLength(LinkList L);
Position GetHead(LinkList L);
Position GetLast(LinkList L);
Position NextPos(Link P);
Status LocatePos(LinkList L, int i, Link&p);
Position LocateElem(LinkList L, Elemtype elem, Status(*compare)(Elemtype elem_a, Elemtype elem_b));
void ListTraverse(LinkList L, void(*func)(Elemtype elem));
void OrderInsert(LinkList&L, Elemtype elem, int(*compare)(Elemtype elem_a, Elemtype elem_b));
Status LocateElem(LinkList&L, Elemtype elem, Position&p, int(*compare)(Elemtype elem_a, Elemtype elem_b));
Status ListInsert_L(LinkList&L, int i, Elemtype elem);
void MergeList_L(LinkList&A, LinkList&B, LinkList&C, int(*compare)(Elemtype elem_a, Elemtype elem_b));
#define LEN sizeof(LNode)
//Polynomial function
#define DestroyPolyn DestroyList
#define PolynLength ListLength

void OrderInsertMerge(LinkList&L, Elemtype elem, int(*compare)(Elemtype elem_a, Elemtype elem_b));
int compare(Elemtype elem_a, Elemtype elem_b);
void CreatPolyn(polynomial&L, int m);
void PrintPolyn(polynomial P);
void AddPolyn(polynomial &Pa, polynomial &Pb);
void AddPolyn1(polynomial &Pa, polynomial &Pb);
void Opposite(polynomial P);
void SubtractPolyn(polynomial&Pa, polynomial&Pb);
void MultiplyPolyn(polynomial&Pa, polynomial&Pb);

#endif