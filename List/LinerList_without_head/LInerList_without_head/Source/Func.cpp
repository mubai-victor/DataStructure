#include "Func.h"




void InitList(LinkList&L)
{
	L = NULL;
}
void ClearList(LinkList&L)
{
	LinkList p=L;
	while (L){				
		L = L->next;
		free(p);
		p = L;	
	}
}
void ListTraverse(LinkList L, void(*func)(Elemtype elem))
{
	LinkList p=L;
	while (p){
		func(p->data);
		p = p->next;
	}
}
int ListLength(LinkList L)
{
	LinkList p = L;
	int length=0;
	while (p){
		p = p->next;
		length++;
	}
	return length;
}
int LocateElem(LinkList L, Elemtype elem, Status(*compare)(Elemtype elem_a, Elemtype elem_b))
{
	LinkList p=L;
	int count = 1;
	while (p){
		if (compare(p->data, elem)==OK)
			return count;
		count++;
		p = p->next;
	}
	return 0;
}
Status GetElem(LinkList L, int i, Elemtype&elem)
{
	LinkList p = L;
	int count = 1;
	while (p&&count < i){
		p = p->next;
		count++;
	}
	if (!p || count>i)
		return INFEASIBLE;
	elem = p->data;
	return OK;
}
Status ListInsert(LinkList&L, int i, Elemtype elem)
{
	LinkList p=L,p_temp=NULL;
	int count = 1;
	if (i == 1){
		p_temp = (LinkList)malloc(sizeof(LNode));
		p_temp->data = elem;
		p_temp->next = L;
		L = p_temp;
		return OK;
	}
	while (count < i-1&&p){
		count++;
		p = p->next;
	}
	if (!p || count>i)
		return ERROR;
	p_temp = (LinkList)malloc(sizeof(LNode));
	p_temp->data = elem;
	p_temp->next = p->next;
	p->next = p_temp;
	return OK;
}
Status ListDelete(LinkList L, int i,Elemtype &elem)
{
	LinkList p = L, p_temp;
	int count = 1;
	if (i == 1){
		L = L->next;
		elem = L->data;
		free(p);
		printf("ERROR\n");
		return OK;
	}
	while (p->next&&count < i - 1){
		count++;
		p=p->next;
	}
	if (!p->next || i - 1 < count){

		return ERROR;
	}
		
	p_temp = p->next;
	p->next = p_temp->next;
	elem = p_temp->data;

	free(p_temp);
	return OK;
}
//Status PriorElem(LinkList L, Elemtype elem_cur, Elemtype&elem_prior)
//{
//	LinkList p_front = L, p_back;
//	while (p_front&&p_front->next){
//		p_back=p_front->next;
//		if (p_back->data == elem_cur){
//			elem_prior = p_front->data;
//			return OK;
//		}
//		p_front = p_front->next;
//	}
//	return INFEASIBLE;
//}
//Status NextElem(LinkList L, Elemtype elem_cur, Elemtype&elem_next)
//{
//	LinkList p = L;
//	while (p&&p->next){
//		if (p->data == elem_cur){
//			elem_next = p->next->data;
//			return OK;
//		}			
//		p = p->next;
//	}
//	return INFEASIBLE;
//}
Status ListEmpty(LinkList L)
{
	if (L)
		return FALSE;
	else
		return TRUE;
}
Status DeleteElem(LinkList&L, Elemtype&elem, Status(*equal)(Elemtype elem_a, Elemtype elem_b))
{
	LinkList p_front,p_back,p_temp;
	p_back = Point(L, elem, equal,p_front);
	if (p_back){
		if (p_front){
			p_front->next= p_back->next;
			elem = p_back->data;
			free(p_back);			
		}
		else{
			p_temp = L;
			L = L->next;
			elem = p_back->data;
			free(p_temp);
		}
		return OK;
	}
	return ERROR;
}
// 查找表L中满足条件的结点。如找到，返回指向该结点的指针， p指向该结点的前驱(若该结点是
// 首元结点，则p=NULL)。如表L中无满足条件的结点，则返回NULL， p无定义。
// 函数equal()的两形参的关键字相等，返回OK；否则返回ERROR
LinkList Point(LinkList L, Elemtype elem, Status(*equal)(Elemtype elem_a, Elemtype elem_b), LinkList&p)
{
	int i, j;
	i = LocateElem(L, elem, equal);
	printf("输入的是第%d个.\n", i);
	if (i){
		if (i == 1){
			p = NULL;
			return L;
		}
		else{
			p = L;
			for (j = 2; j < i; j++){
				p = p->next;
			}
			return p->next;
		}
	}
	return NULL;
}
// 按关键字非降序将e插入表L。函数compare()返回值为形参1的关键字-形参2的关键字
void InsertAscend(LinkList&L, Elemtype elem, Status(*compare)(Elemtype elem_a, Elemtype elem_b))
{
	LinkList p = L;
	if (!L || compare(elem,L->data)<=0){
		ListInsert(L, 1, elem);
	}
	else{	
		while (p->next&&compare( p->next->data,elem) < 0)		
			p = p->next;
		ListInsert(p, 2, elem);
		}
}

//Status equal(ElemType c1, ElemType c2)
//{ // 判断是否相等的函数
//	if (c1 == c2)
//		return TRUE;
//	else
//		return FALSE;
//}
//int comp(ElemType a, ElemType b)
//{ // 根据a<、 =或>b，分别返回-1、 0或1
//	if (a == b)
//		return 0;
//	else
//		return (a - b) / abs(a - b);
//}
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
//Status sq(ElemType c1, ElemType c2)
//{ // 数据元素判定函数(平方关系)， LocateElem()调用的函数
//	if (c1 == c2*c2)
//		return TRUE;
//	else
//		return FALSE;
//}
//void dbl(ElemType &c)
//{ // ListTraverse()调用的另一函数(元素值加倍)
//	c *= 2;
//}