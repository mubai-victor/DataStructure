#include "Function.h"
#include "Test.h"


#ifdef LINERLIST_ORDER
Status InitList(SqList&list)
{
	list.elembase = (Elemtype*)malloc(sizeof(Elemtype)*LISTLENGTH);
	if (!list.elembase)
		return INFEASIBLE;
	list.length = 0;
	list.listsize = LISTLENGTH;
	return OK;
}

Status ListEmpty(SqList&list){
	if (!list.elembase)
		return ERROR;
	if (list.length == 0)
		return TRUE;
	else if (list.length)
		return FALSE;
}
int ListLength(SqList&list)
{
	if (!list.elembase)
		return ERROR;
	return list.length;
}
Status GetElem(SqList&list, int i, Elemtype &elem)
{
	if (!list.elembase)
		return ERROR;
	elem = *(list.elembase + i-1);
	return OK;
}
int LocateElem(SqList&list, Elemtype e, Status(*compare)(Elemtype elem1, Elemtype elem2))
{
	if (!list.elembase)
		return ERROR;
	int i = 0;
	for (; i < list.length&&compare(*(list.elembase + i-1),e)!=TRUE; i++);
	if (i >= list.length)
		return INFEASIBLE;
	else
		return i+1;
}
Status PriorElem(SqList&list, Elemtype cur_e, Elemtype&pre_e)
{
	if (!list.elembase || cur_e == *(list.elembase))
		return ERROR;
	Elemtype *p = list.elembase+1;
	while (*p != cur_e && p < list.elembase + list.length)p++;//////////////////////////////////
	if (*p == cur_e){
		pre_e=*(p-1);
		return OK;
	}
	else if (p > list.elembase + list.length)return INFEASIBLE;
}
Status NextElem(SqList&list, Elemtype cur_e, Elemtype&next_e)
{
	if (!list.elembase || cur_e == *(list.elembase + list.length - 1))
		return ERROR;
	Elemtype *p=list.elembase+1;
	for (; *p != cur_e && p < list.elembase + list.length - 1; p++);
	if (*p == cur_e){
		next_e = *++p;
		return OK;
	}
	else if (p > list.elembase + list.length - 1)
		return INFEASIBLE;
}
Status ListInsert(SqList&list, int i, Elemtype elem){
	if (!list.elembase)return ERROR;
	if (list.length >= list.listsize){
		Elemtype*newbase = (Elemtype*)realloc(list.elembase,sizeof(Elemtype)*(list.listsize + LISTINCREMENT));
		if (!newbase)
			return ERROR;
		list.elembase = newbase;
		list.listsize += LISTINCREMENT;
	}
	Elemtype*p_cur = list.elembase + i - 1;
	Elemtype*p_rear = list.elembase + list.length;
	for (; p_rear != p_cur; p_rear--){
		*p_rear = *(p_rear - 1);
	}
	*p_cur = elem;
	++list.length;
	return OK;
}
Status ListDelete(SqList&list, int i, Elemtype&elem){
	if (!list.elembase || i > list.length)
		return ERROR;
	Elemtype*cur_p = list.elembase + i - 1;
	elem = *cur_p;
	for (; cur_p < list.elembase + list.length - 1; cur_p++)
		*cur_p = *(cur_p+1);
	list.length--;
	return OK;
}
void ListTraverse(SqList&list, void(*visit)(Elemtype&elem)){
	Elemtype*p = list.elembase;
	for (; p < list.elembase + list.length; p++){
		visit(*p);
	}
}
void DestroyList(SqList&list){
	free(list.elembase);
	list.elembase = NULL;
	list.length = list.listsize = 0;
}
void ClearList(SqList&list){
	list.length = 0;
}

void Union(SqList&a, SqList&b)
{
	int a_len, b_len;
	a_len = ListLength(a);
	Elemtype elem;
	for (int i = 1; i <= a_len; i++){
		GetElem(a, i, elem);
		if (LocateElem(b, elem, equal)==INFEASIBLE)
			ListInsert(b,ListLength(b)+1,elem);
	}
}
void MergeList(SqList a, SqList b, SqList&c)
{
	int i_a = 1, i_b = 1, flag = 0;;
	int a_len = ListLength(a), b_len = ListLength(b); 
	Elemtype a_elem, b_elem;
	InitList(c);
	while (i_a <= a_len&&i_b <= b_len){
		GetElem(a, i_a, a_elem);
		GetElem(b, i_b, b_elem);
		if (a_elem <= b_elem){
			ListInsert(c, ++flag, a_elem);
			i_a++;
		}
			
		else{
			ListInsert(c, ++flag, b_elem);
			i_b++;
		}	
	}
	if (i_a <= a_len){
		for (; i_a < a_len; i_a++){
			GetElem(a, i_a, a_elem);
			ListInsert(c, ++flag, a_elem);
		}
	}
	else if (i_b <= b_len){
		for (; i_b < b_len; i_b++){
			GetElem(b, i_b, b_elem);
			ListInsert(c, ++flag, b_elem);
		}
	}
}
#endif

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
	LinkList p;
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

#endif