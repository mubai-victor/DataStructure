#include "Function.h"
#include "Test.h"

int Malloc(SLinkList L)
{
	int i = L[0].cur;
	if (i){
		L[0].cur = L[i].cur;
	}
	return i;
}
void Free(SLinkList L, int k)
{
	int i = L[0].cur;
	L[0].cur = k;
	L[k].cur = i;
}
void InitList(SLinkList L)
{
	L[MAX_SIZE - 1].cur = 0;
	L[MAX_SIZE - 2].cur = 0;
	for (int loop = 0; loop < MAX_SIZE - 2; loop++){
		L[loop].cur = loop + 1;
	}
}
void ClearList(SLinkList L)
{
	int occupied = L[MAX_SIZE - 1].cur, unoccupied = L[0].cur,i;
	L[MAX_SIZE - 1].cur = 0;
	L[0].cur = occupied;
	for (i = 0; L[occupied].cur; i++)
		occupied = L[occupied].cur;
	L[occupied].cur = unoccupied;
}
Status ListEmpty(SLinkList L)
{
	if (L[MAX_SIZE - 1].cur)
		return FALSE;
	return TRUE;	
}
int ListLength(SLinkList L)
{
	int cur=L[MAX_SIZE-1].cur,count=0;
	while (cur){
		cur = L[cur].cur;
		count++;
	}
	return count;
}
Status GetElem(SLinkList L, int i, Elemtype&elem)
{
	int cur = L[MAX_SIZE-1].cur, count = 1;
	while (cur&&count < i){
		cur = L[cur].cur;
		count++;
	}
	if (!cur || i < count)
		return ERROR;
	elem = L[cur].data;
	return OK;
}
int LocateElem(SLinkList L, Elemtype elem)
{
	int cur = L[MAX_SIZE - 1].cur;
	while (cur){
		if (L[cur].data == elem)
			return cur;
		cur = L[cur].cur;
	}
	return 0;
}
Status PriorElem(SLinkList L, Elemtype elem_cur, Elemtype&elem_pre)
{
	int front, back = L[MAX_SIZE-1].cur;
	while (L[back].cur){
		front = back;
		back = L[back].cur;
		
		if (L[back].data == elem_cur){
			elem_pre = L[front].data;
			return OK;printf("\n%d\n",L[back].data);
		}
	}
	return ERROR;
}
Status NextElem(SLinkList L, Elemtype elem_cur, Elemtype&elem_next)
{
	int cur = L[MAX_SIZE - 1].cur;
	while (L[cur].cur){
		if (L[cur].data == elem_cur){
			cur = L[cur].cur;
			elem_next = L[cur].data;
			return OK;
		}	
		cur = L[cur].cur;
	}
	return ERROR;
}
Status ListInsert(SLinkList&L, int i, Elemtype elem)
{
	int cur = MAX_SIZE - 1, count = 1,temp;
	while (cur&&count<i){
		cur = L[cur].cur;
		count++;
	}
	if (!cur || i>count)
		return ERROR;
	temp = Malloc(L);
	L[temp].data = elem;
	L[temp].cur = L[cur].cur;
	L[cur].cur = temp;
//	printf("\ntemp=%d\n", temp);
	return OK;
}
Status ListDelete(SLinkList L, int i, Elemtype&elem)
{
	int cur = MAX_SIZE-1,count=1,cur_temp;
	while (L[cur].cur&&count<i){
		count++;
		cur = L[cur].cur;
	}
	if (!L[cur].cur || count>i)
		return ERROR;
	cur_temp = L[cur].cur;
	elem = L[cur_temp].data;
	L[cur].cur = L[cur_temp].cur;
	Free(L,cur_temp);
	return OK;
}
void ListTraverse(SLinkList L, void(*func)(Elemtype elem))
{
	int cur = L[MAX_SIZE - 1].cur;
	while (cur){
		func(L[cur].data);
		cur = L[cur].cur;
	}
}

//Testing Function**************************************************************
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

