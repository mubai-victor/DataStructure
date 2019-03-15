#include "stdafx.h"
#include "Function.h"
#include "Test.h"
//Testing Function**************************************************************
// func2-3.cpp 几个常用的函数
Status equal(ElemType c1, ElemType c2)
{ // 判断是否相等的函数
	if (c1 == c2)
		return TRUE;
	else
		return FALSE;
}
int comp(ElemType a, ElemType b)
{ // 根据a<、 =或>b，分别返回-1、 0或1
	if (a == b)
		return 0;
	else
		return (a - b) / abs(a - b);
}
void print(ElemType c)
{
	printf("%d ", c);
}
void print2(ElemType c)
{
	printf("%c ", c);
}
void print1(ElemType &c)
{
	printf("%d ", c);
}
Status sq(ElemType c1, ElemType c2)
{ // 数据元素判定函数(平方关系)， LocateElem()调用的函数
	if (c1 == c2*c2)
		return TRUE;
	else
		return FALSE;
}
void dbl(ElemType &c)
{ // ListTraverse()调用的另一函数(元素值加倍)
	c *= 2;
}

#ifdef LINERLIST_CHAIN
void InitList(LinkList&L){
	L=(LinkList)malloc(sizeof(LNode));
	if(!L)
		exit(OVERFLOW);
	L->next=NULL;
}
void DestroyList(LinkList&L)
{
	LinkList p_front=L,p_rear;
	while(!p_front){
		p_rear=p_front->next;
		free(p_front);
		p_front=p_rear;
		p_rear=p_front->next;
	}
	L=NULL;
}
void ClearList(LinkList&L)
{
	LinkList p_front=L->next,p_rear;
	while(!p_front){
		p_rear=p_front->next;
		free(p_front);
		p_front=p_rear;
		p_rear=p_front->next;
	}	
	L->next=NULL;
}
void ListTraverse(LinkList L, void(*func)(Elemtype elem))
{
	LinkList p=L->next;
	while(p){
		func(p->data);
		p = p->next;
	}
}
void Union(LinkList La, LinkList Lb)
{
	Elemtype elem;
	int length = ListLength(Lb);
	for (int i = 0; i < length; i++){
		GetElem(Lb,i+1,elem);
		if (!LocateElem(La, elem, equal))
			ListInsert(La, ListLength(La)+1,elem);
	}
}
void MergeList(LinkList La, LinkList Lb, LinkList&Lc)
{
	Elemtype elem_a, elem_b;
	int pos_a=1, pos_b=1,k=0;
	int length_a = ListLength(La), length_b = ListLength(Lb);
	InitList(Lc);
	while (pos_a <= length_a&&pos_b <= length_b){
		GetElem(La, pos_a, elem_a);
		GetElem(Lb, pos_b, elem_b);	
		if (elem_a <= elem_b){
			if (ListInsert(Lc, ++k, elem_a) == ERROR)
				printf("failed to insert elem_a = %d\n", elem_a);
			else
				printf("insert elem_a=%d\n",elem_a);
			pos_a++;
		}
		else{
			if (ListInsert(Lc, ++k, elem_b) == ERROR)
				printf("failed to insert elem_b = %d\n", elem_b);
			else
				printf("insert elem_b=%d\n", elem_b);
			pos_b++;
		}
	}
	while(pos_a <= length_a){
		GetElem(La, pos_a, elem_a);
		if (ListInsert(Lc, ++k, elem_a) == ERROR)
			printf("failed to insert elem_a = %d\n", elem_a);
		else
			printf("insert elem_a=%d\n", elem_a);
		pos_a++;
	}
	while (pos_b <= length_b){
		GetElem(Lb, pos_b, elem_b);
		if (ListInsert(Lc, ++k, elem_b) == ERROR)
			printf("failed to insert elem_b = %d\n", elem_b);
		else
			printf("insert elem_b=%d\n", elem_b);
		pos_b++;
	}
}
Status ListEmpty(LinkList L)
{
	if(!L->next)
		return TRUE;
	else
		return FALSE;
}
Status GetElem(LinkList L, int i, Elemtype &elem)
{
	LinkList p=L->next;
	int count=1;
	while(p&&count<i){
		p=p->next;
		count++;
	}
	if(!p||count>i)
		return INFEASIBLE;
	elem=p->data;
	return OK;
}
Status ListInsert(LinkList&L, int i, Elemtype elem)
{
	LinkList p_front,p_rear=L;
	int count=1;
	while(p_rear&&count<i){
		p_rear = p_rear->next;
		count++;
	}
	if(!p_rear||count>i)
		return ERROR;
	p_front=(LinkList)malloc(sizeof(LNode));
	p_front->data=elem;
	p_front->next=p_rear->next;
	p_rear->next=p_front;
	return OK;
}
Status ListDelete(LinkList&L, int i, Elemtype &elem)
{
	LinkList p = L, p_temp;
	int count = 1;
	while (p->next&&count<i){
		p = p -> next;
		count++;
	}
	if (!p->next || count>i)
		return ERROR;
	elem = p->next->data;
	p_temp = p->next;
	p->next= p->next->next;
	free(p_temp);
	return OK;
}
Status PriorElem(LinkList L, Elemtype elem_cur, Elemtype&elem_prior)
{
	LinkList p_front = L->next,p_rear;
	while (p_front&&p_front->next){
		p_rear = p_front->next;
		if (p_rear->data == elem_cur){
			elem_prior = p_front->data;
			return OK;
		}
		p_front = p_rear;
	}
	return INFEASIBLE;
}
Status NextElem(LinkList L, Elemtype elem_cur, Elemtype&elem_next)
{
	LinkList p=L->next;
	while (p&&p->next){
		if (p->data == elem_cur)
		{
			elem_next = p->next->data;
			return OK;
		}
		p = p->next;
	}
	return INFEASIBLE;
}
int LocateElem(LinkList L, Elemtype elem, Status(*compare)(Elemtype a, Elemtype b))
{
	int count = 1;
	LinkList p = L->next;
	while (p){
		if (compare(elem, p->data))
			return count;
		count++;
		p = p->next;
	}
	return 0;
}
int ListLength(LinkList L)
{
	int count = 0;
	LinkList p = L;
	while (p->next){
		count++;
		p = p->next;
	}
	return count;
}

void Push(LinkStack s, SElemType selem)
{
	ListInsert(s, 1, selem);
}
void StackTraverse(LinkStack s, void(*func)(SElemType selem))
{
	LinkStack temp,cur=s->next;
	InitStack(temp);
	while (cur) {
		Push(temp, cur->data);
		cur = cur->next;
	}
	ListTraverse(temp, func);
}
Status Pop(LinkStack s, SElemType&selem)
{
	return ListDelete(s, 1, selem);
}
Status GetTop(LinkStack s, SElemType&selem)
{
	if (ListEmpty(s))
		return ERROR;
	GetElem(s, 1, selem);
	return OK;
}

#endif