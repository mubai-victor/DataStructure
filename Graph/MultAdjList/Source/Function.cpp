#include "stdafx.h"
#include "Function.h"
#include "Test.h"

using namespace std;
//Function of struct ElemType*****************************************

//Function of struct ArcBox1******************************************

//Function of struct VexNode******************************************

//Function of class ArcBox******************************************

//Function of class ArcBox******************************************

//Function about Queue*************************************************
void InitQueue(LinkQueue &q)
{
	q.front = q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (q.front == NULL)
		exit(1);
	q.front->next = NULL;
}
void EnQueue(LinkQueue &q, QElemType elem)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		exit(-1);
	p->data = elem;
	p->next = q.rear->next;
	q.rear->next = p;
	q.rear = p;
}
Status DeQueue(LinkQueue &q, QElemType &elem)
{
	if (QueueEmpty(q))
		return ERROR;
	QueuePtr p = q.front->next;
	elem = p->data;
	if (q.front->next == q.rear) {
		q.rear = q.front;
		q.front->next = NULL;
	}
	else {
		q.front->next = p->next;
	}
	free(p);
	p = NULL;
	return OK;
}
Status QueueEmpty(LinkQueue &q)
{
	if (!q.front->next)
		return TRUE;
	else
		return FALSE;
}
//Function************************************************************
Status GetSubStr(char *sub, char *&str)
{
	char *pcPos = NULL;
	if ((pcPos = strchr(str, ' ')) != NULL || (pcPos = strchr(str, '\n')) != NULL) {
		*pcPos = '\0';
		strcpy_s  (sub,MAX_NAME, str);
		str = pcPos + 1;
		return OK;
	}
	return ERROR;
}
void visit(VertexType vex)
{
	cout << vex << ends;
}
Status equalvex(ElemType elem1, ElemType elem2)
{
	if (elem1.headvex == elem2.headvex) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}
//Function about List**************************************************
void InitList(LinkList&L)
{
	L = NULL;
}
void ClearList(LinkList&L)
{
	LinkList p = L;
	while (L) {
		L = L->next;
		free(p);
		p = L;
	}
}
int ListLength(LinkList L)
{
	LinkList p = L;
	int length = 0;
	while (p) {
		p = p->next;
		length++;
	}
	return length;
}
int LocateElem(LinkList L, ElemType elem, Status(*compare)(ElemType elem_a, ElemType elem_b))
{
	LinkList p = L;
	int count = 1;
	while (p) {
		if (compare(p->data, elem) == OK)
			return count;
		count++;
		p = p->next;
	}
	return 0;
}
Status GetElem(LinkList L, int i, ElemType&elem)
{
	LinkList p = L;
	int count = 1;
	while (p&&count < i) {
		p = p->next;
		count++;
	}
	if (!p || count>i)
		return INFEASIBLE;
	elem = p->data;
	return OK;
}
Status ListInsert(LinkList&L, int i, ElemType elem)
{
	LinkList p = L, p_temp = NULL;
	int count = 1;
	if (i == 1) {
		p_temp = (LinkList)malloc(sizeof(LNode));
		p_temp->data = elem;
		p_temp->next = L;
		L = p_temp;
		return OK;
	}
	while (count < i - 1 && p) {
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
Status ListDelete(LinkList &L, int i, ElemType &elem)
{
	LinkList p = L, p_temp;
	int count = 1;
	if (i == 1) {
		elem = L->data;
		L = NULL;
		free(p);
		return OK;
	}
	while (p->next&&count < i - 1) {
		count++;
		p = p->next;
	}
	if (!p->next || i - 1 < count) {

		return ERROR;
	}

	p_temp = p->next;
	p->next = p_temp->next;
	elem = p_temp->data;

	free(p_temp);
	return OK;
}
Status ListEmpty(LinkList L)
{
	if (L)
		return FALSE;
	else
		return TRUE;
}
Status DeleteElem(LinkList&L, ElemType&elem, Status(*equal)(ElemType elem_a, ElemType elem_b))
{
	LinkList p_front, p_back, p_temp;
	p_back = Point(L, elem, equal, p_front);
	if (p_back) {
		if (p_front) {
			p_front->next = p_back->next;
			elem = p_back->data;
			free(p_back);
		}
		else {
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
LinkList Point(LinkList L, ElemType elem, Status(*equal)(ElemType elem_a, ElemType elem_b), LinkList&p)
{
	int i, j;
	i = LocateElem(L, elem, equal);
	if (i) {
		if (i == 1) {
			p = NULL;
			return L;
		}
		else {
			p = L;
			for (j = 2; j < i; j++) {
				p = p->next;
			}
			return p->next;
		}
	}
	return NULL;
}