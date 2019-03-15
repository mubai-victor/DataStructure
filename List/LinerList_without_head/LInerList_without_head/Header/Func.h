#ifndef FUNC_H
#define FUNC_H
#include "Test.h"
#define NAMELEN 8 // 姓名最大长度
#define CLASSLEN 4 // 班级名最大长度

struct stud // 记录的结构
{
	char name[NAMELEN + 1]; // 包括′\0′
	long num;
	char sex;
	int age;
	char Class[CLASSLEN + 1]; // 包括′\0′
	int health;
};
typedef stud ElemType;

struct LNode{
	LNode*next;
	Elemtype data;
};
typedef LNode*LinkList;
typedef struct LNode LNode;
#define DestroyList ClearList

void InitList(LinkList&L);
void ClearList(LinkList&L);
void ListTraverse(LinkList L, void(*func)(Elemtype elem));
void InsertAscend(LinkList&L, Elemtype elem, Status(*compare)(Elemtype elem_a, Elemtype elem_b));

int ListLength(LinkList L);
int LocateElem(LinkList L, Elemtype elem, Status(*compare)(Elemtype elem_a, Elemtype elem_b));


Status GetElem(LinkList L, int i, Elemtype&elem);
Status ListInsert(LinkList&L, int i, Elemtype elem);
Status ListDelete(LinkList L, int i,Elemtype&elem);
Status PriorElem(LinkList L, Elemtype elem_cur, Elemtype&elem_prior);
Status NextElem(LinkList L, Elemtype elem_cur, Elemtype&elem_next);
Status ListEmpty(LinkList L);
Status equal(Elemtype a, Elemtype b);
Status DeleteElem(LinkList&L, Elemtype&elem, Status(*equal)(Elemtype elem_a, Elemtype elem_b));

LinkList Point(LinkList L, Elemtype elem, Status(*equal)(Elemtype elem_a, Elemtype elem_b),LinkList&p);


int comp(ElemType a, ElemType b);
void print(ElemType c);
void print2(ElemType c);
void print1(ElemType &c);
Status sq(ElemType c1, ElemType c2);
void dbl(ElemType &c);

#endif
