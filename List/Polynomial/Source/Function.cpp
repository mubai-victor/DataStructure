#include "Function.h"
#include "Test.h"
//24 base functions
void MakeNode(Link&p, Elemtype elem)//分配一个由P指向的节点，节点的数据的值为elem"stdafx.h"
{
	p = (Link)malloc(LEN);
	if (!p)
		exit(ERROR);
	p->data = elem;
}
void FreeNode(Link&p)//release the node pointed by the pointer p;
{
	free(p);
	p = NULL;
}
void InitList(LinkList&L)//initialise the list L; 
{
	L.head = L.tail = (Link)malloc(LEN);
	L.head->next = NULL;
	L.length = 0;
}
void ClearList(LinkList&L)//clear the list L;
{
	Link cur_front,cur_back = L.head->next;
	L.head->next = NULL;
	while (cur_back != L.tail){
		cur_front=cur_back;
		cur_back=cur_back->next;
		free(cur_front);
	}
	free(L.tail);
	L.tail = L.head;
	L.length = 0;
}
void DestroyList(LinkList&L)//destroy the list L;
{
	Link cur_front, cur_back = L.head->next;
	free(L.head);
	while (cur_back){
		cur_front = cur_back;
		free(cur_front);
		cur_back=cur_back->next;
	}
	L.tail = L.head = NULL;
	L.length = 0;
}
void InsFirst(LinkList&L, Link head, Link addnode)//head points to the node of L,treat head as the head of the list and insert addnode before it;
{//or insert the addnode after head;
	addnode->next= head->next;//printf("%d  %d",head,L.head->next);
	head->next = addnode;
	if (head == L.tail)
		L.tail = addnode;
	L.length++;
}
Status DelFirst(LinkList&L, Link head, Link&delnode)//head points to the node of L,treat head as the head of the list,delete the fisrt node of the list;
{//return the value of the node with delnode,return OK,if list is empty,delnode is NULL and return ERROR;	
	if (L.head != L.tail){
		delnode = head->next;
		head->next= delnode->next;
		if (delnode == L.tail)
			L.tail = head;
		L.length--;
		return OK;
	}
	delnode = NULL;
	return FALSE;
}
void Append(LinkList&L, Link s)//append the list whose head is s to the tail of the L;
{
	int count = 1;
	L.tail->next = s;
	while (s->next){
		s = s->next;
		count++;
	}
	L.length += count;
	L.tail = s;
	L.tail->next = NULL;
}
Position PriorPos(LinkList L, Link s)//s points to the node of the list L,return pointer of  the prior position,if not exist ,return NULL;
{
	Link cur = L.head->next;
	if (cur == s){
		return NULL;
	}
	while (cur->next != s)
		cur = cur->next;
	return cur;
}
Status Remove(LinkList&L, Link&p)//delete the tail node of the list and return it with p,change the element of tail of L,if empty,p is NULL,return ERROR;
{
	if (L.tail == L.head){
		p = NULL;
		return FALSE;
	}		
	Link cur = L.head;
	while (cur->next!=L.tail){
		cur = cur->next;
	}
	p = L.tail;
	cur->next = NULL;
	L.tail = cur;
	L.length--;
	return OK;
}
void InsBefore(LinkList&L, Link&p, Link s)//p points to the node of the list,insert node pointed by s into the front of p,and p points to new node;
{
	Link cur=PriorPos(L,p);
	if (!cur)
		cur = L.head;
	s->next = p;
	cur->next = s;
	p = s;
	L.length++;
}
void InsAfter(LinkList&L, Link&p, Link s)//p points to the node of the list,insert s into the back of the node pointed by p,points to the new node;
{
	s->next = p->next;
	p->next = s;
	if (L.tail == p)
		L.tail = s;
	L.length++;
	p = s;
}
void SetCurElem(Link p, Elemtype s)//p points the node of the list,update the element of the p with s;
{
	p->data = s;
}
Elemtype GetCurElem(Link p)//p points to the node of the list,return the value of the element of the node.
{
	return p->data;
}
Status ListEmpty(LinkList L)//if the list is empty,return true,othewise,return false;
{
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}
int ListLength(LinkList L)//return the length of list;
{
	return L.length;
}
Position GetHead(LinkList L)//return the pointer of the the head of list;
{
	return L.head;
}
Position GetLast(LinkList L)//return the tail pointer of the list;
{
	return L.tail;
}
Position NextPos(Link p)//p pionts to the node of the list,return the next pointer points to next positon;
{
	return p->next;
}
Status LocatePos(LinkList L, int i, Link&p)//get the pointer of poisition i;
{
	if (i<0 || i>L.length)
		return ERROR;
	p = L.head;
	int count = 0;
	while (count < i){
		count++;
		p = p->next;
	}
	return OK;
}
Position LocateElem(LinkList L, Elemtype elem, Status(*compare)(Elemtype elem_a, Elemtype elem_b))//return the pointer of which value meet the function compare,
{//return its position,if failed,return NULL;
	Link cur = L.head->next;
	while (cur){
		if (compare(cur->data, elem))
			return cur;
		cur = cur->next;
	}
	return NULL;
}
void ListTraverse(LinkList L, void(*func)(Elemtype elem))//call function func for each element of the list by order;
{
	Link cur = L.head->next;
	while (cur){
//		printf("\nhere:\n");
		func(cur->data);
		cur=cur->next;
	}
}
void OrderInsert(LinkList&L, Elemtype elem, int(*compare)(Elemtype elem_a, Elemtype elem_b))//insert elem into L non_dencent
{
	Link cur_front=L.head,cur_temp,cur_back = L.head->next;
	if (cur_back == L.tail){
		cur_temp = (Link)malloc(LEN);
		cur_temp->data = elem;
		cur_temp->next = NULL;
		L.head->next = L.tail = cur_temp;
	}
	else{
		while (cur_back&&compare(cur_back->data, elem) < 0){
			cur_front = cur_back;
			cur_back = cur_back->next;
		}
		cur_temp = (Link)malloc(LEN);
		cur_temp->data = elem;
		cur_front->next = cur_temp;
		cur_temp->next = cur_back;
		if (cur_back == L.tail)
			L.tail = cur_temp;
	}
	L.length++;
}
Status LocateElem(LinkList&L, Elemtype elem, Position&p, int(*compare)(Elemtype elem_a, Elemtype elem_b))//get the pointer of position of which value makes the compare return 0;
{//if such element don't exist,return the pointer of position before which value make the compare return value beyond 0,and return false;
	Link cur_front;
	p = L.head->next;
	cur_front=L.head;
	while (p&&compare(p->data,elem) < 0){
//		printf("start");		
		cur_front = p;
		p = p->next;
	}
	if (!p || compare(p->data, elem) > 0){
		p = cur_front;
//		printf("stop");
//		printf("%d  %d\n", p, L.head->next);
		return FALSE;
	}
	return OK;
}

Status ListInsert_L(LinkList&L, int i, Elemtype elem)
{
	Link cur,node;
	if(LocatePos(L, i - 1, cur)==ERROR)
		return ERROR;
	MakeNode(node, elem);
	InsAfter(L, cur, node);
	return OK;
}
void MergeList_L(LinkList&A, LinkList&B, LinkList&C,int(*compare)(Elemtype elem_a,Elemtype elem_b))
{
	Link head_a, head_b, iter_a, iter_b,cur_temp;
	Elemtype elem_a, elem_b;
	InitList(C);
	head_a = GetHead(A);
	head_b = GetHead(B);
	iter_a = NextPos(head_a);	
	iter_b = NextPos(head_b);
	while (A.length&&B.length){
		elem_a = GetCurElem(iter_a);
		elem_b = GetCurElem(iter_b);
		if (compare(elem_a, elem_b) < 0){
			DelFirst(A, head_a, cur_temp);
			cur_temp->next = NULL;
			Append(C, cur_temp);
			iter_a = NextPos(head_a);
		}
		else{
			DelFirst(B, head_b, cur_temp);
			cur_temp->next = NULL;
			Append(C, cur_temp);
			iter_b = NextPos(head_b);
		}
	}
	if (A.length){
		Append(C, iter_a);
	}
	else{
		Append(C, iter_b);
	}
	A.head->next = NULL;
	DestroyList(A);
	B.head->next = NULL;
	DestroyList(B);
}

//Function of polynomial**************************************************************
void OrderInsertMerge(LinkList&L, Elemtype elem, int(*compare)(Elemtype elem_a, Elemtype elem_b))
{
	Position cur,cur_temp;
	if (LocateElem(L, elem, cur, compare)){
		cur->data.coef += elem.coef;
		if (!cur->data.coef){
			cur_temp = PriorPos(L, cur);
			if (!cur_temp)
				cur_temp = GetHead(L);
			DelFirst(L, cur_temp, cur);
			FreeNode(cur);
		}
	}
	else{
		//printf("insert.");
		MakeNode(cur_temp, elem);	
		InsFirst(L, cur, cur_temp);
	}
}
int compare(Elemtype elem_a, Elemtype elem_b)
{
	if (elem_a.expn == elem_b.expn)
		return 0;
	else{
		return (((elem_a.expn - elem_b.expn) > 0) ? 1 : (-1));
	}
}
void CreatPolyn(polynomial&L, int m){
	Position cur, cur_front;
	Elemtype elem_temp;
	int loop;
	InitList(L);
	printf("请输入%d个系数,指数：\n", m);
	for (loop = 0; loop < m; loop++){
		//printf("stop");
		scanf("%f,%d", &elem_temp.coef, &elem_temp.expn);
		if (!LocateElem(L,elem_temp,cur_front,compare)){
			
			MakeNode(cur, elem_temp); 
			InsFirst(L, cur_front, cur);
		}
	}
	PrintPolyn(L);
}
void PrintPolyn(polynomial P)
{
	Link q;
	q = P.head->next;
	printf(" 系数     指数\n");
	while (q){
		printf("%f    %d\n", q->data.coef, q->data.expn);
		q = q->next;
	}
}
void AddPolyn(polynomial &Pa, polynomial &Pb)
{
	ElemType elem_a, elem_b;
	Position cur_a, cur_b, cur_pria, cur_prib;
	cur_pria = Pa.head, cur_prib = Pb.head;
	cur_a = NextPos(cur_pria);
	cur_b = NextPos(cur_prib);
	while (!ListEmpty(Pa) && !ListEmpty(Pb) && cur_a){
		elem_a = GetCurElem(cur_a);
		elem_b = GetCurElem(cur_b);
		switch (compare(elem_a, elem_b)){
		case -1:
			cur_pria = cur_a;			
			cur_a = NextPos(cur_a);
//			printf("-1\n");
			break;
		case 0:
			cur_a->data.coef += cur_b->data.coef;
			if (cur_a->data.coef == 0){
				DelFirst(Pa, cur_pria, cur_a);
				FreeNode(cur_a);                                              
			}
			else
				cur_pria = cur_a;
			DelFirst(Pb, cur_prib, cur_b);
			FreeNode(cur_b);
			cur_b = NextPos(cur_prib);
			cur_a = NextPos(cur_pria);
//			printf("0\n");
			break;
		case 1:
			DelFirst(Pb, cur_prib, cur_b);
			InsFirst(Pa, cur_pria, cur_b);
			cur_b = NextPos(cur_prib);
			cur_a = cur_a->next;
//			printf("1\n");
			break;
		}
	}
	if (!ListEmpty(Pb)){
		Append(Pa, cur_b);
		FreeNode(Pb.head);
		Pb.head=Pb.tail=NULL;
		Pb.length=0;
	}
}
void AddPolyn1(polynomial &Pa, polynomial &Pb)
{
	Position cur_b=Pb.head;
	ElemType elem;
	cur_b = NextPos(cur_b);	
	while (cur_b){
		elem=GetCurElem(cur_b);
//		printf("addpolynomial.\n");
		OrderInsertMerge(Pa, elem, compare);
		cur_b = NextPos(cur_b);	
	}
	DestroyPolyn(Pb);
}
void Opposite(polynomial P)
{
	Position cur = P.head->next;
	ElemType elem;
	while (cur){
		cur->data.coef *= (-1);
		cur=NextPos(cur); 
	}
}
void SubtractPolyn(polynomial&Pa, polynomial&Pb)
{
	Opposite(Pb);
	AddPolyn(Pa, Pb);
}
void MultiplyPolyn(polynomial&Pa, polynomial&Pb)
{
	polynomial Pc;
	ElemType elem_c, elem_a, elem_b;
	Position cur_a,cur_b;
	cur_a = GetHead(Pa);
	cur_a=NextPos(cur_a);
	InitList(Pc);	
	while (cur_a){		
		elem_a = GetCurElem(cur_a);
		cur_b = GetHead(Pb);
		cur_b=NextPos(cur_b);
		while (cur_b){	
		
			elem_b = GetCurElem(cur_b);
			elem_c.coef = elem_a.coef*elem_b.coef;
			elem_c.expn = elem_a.expn + elem_b.expn;
//			printf("%fX%d",elem_a.coef,elem_a.expn);	
//			printf("*%fX%d",elem_b.coef,elem_b.expn);						
//			printf("=%fX%d\n",elem_c.coef,elem_c.expn);			
			OrderInsertMerge(Pc, elem_c, compare);
			cur_b = NextPos(cur_b);
		}
		cur_a = NextPos(cur_a);
	}		
	DestroyList(Pb);
	ClearList(Pa);
	Pa.head = Pc.head;
	Pa.tail = Pc.tail;
	Pa.length = Pc.length;
}
